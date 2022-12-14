package gmcredentials

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"testing"

	"github.com/stretchr/testify/assert"

	"github.com/warm3snow/gmsm/gmtls"
	"github.com/warm3snow/gmsm/x509"

	cmtls "chainmaker.org/chainmaker/common/v2/crypto/tls"
	//gmtls "chainmaker.org/chainmaker/common/v2/crypto/tls"
	//"chainmaker.org/chainmaker/common/v2/crypto/x509"
)

var (
	caCert = "../tassl_demo_certs/CA.crt"

	ssCert = "../tassl_demo_certs/SS.crt"
	ssKey  = "../tassl_demo_certs/SS.key"
	seCert = "../tassl_demo_certs/SE.crt"
	seKey  = "../tassl_demo_certs/SE.key"

	csCert = "../tassl_demo_certs/CS.crt"
	csKey  = "../tassl_demo_certs/CS.key"
	ceCert = "../tassl_demo_certs/CE.crt"
	ceKey  = "../tassl_demo_certs/CE.key"
)

func TestGmServer(t *testing.T) {
	// 切换GMSSL/TSL
	sigCert, err := gmtls.LoadX509KeyPair(ssCert, ssKey)
	assert.NoError(t, err)
	encCert, err := gmtls.LoadX509KeyPair(seCert, seKey)
	assert.NoError(t, err)

	// 信任的根证书
	certPool := x509.NewCertPool()
	cacert, err := ioutil.ReadFile(caCert)
	assert.NoError(t, err)
	certPool.AppendCertsFromPEM(cacert)

	config := &gmtls.Config{
		GMSupport:    &gmtls.GMSupport{},
		Certificates: []gmtls.Certificate{sigCert, encCert},
		//RootCAs:      certPool,
		ClientCAs:  certPool,
		ClientAuth: gmtls.RequireAndVerifyClientCert,
	}

	ln, err := gmtls.Listen("tcp", ":44330", config)
	if err != nil {
		log.Println(err)
		return
	}
	defer ln.Close()

	http.HandleFunc("/", func(writer http.ResponseWriter, request *http.Request) {
		fmt.Fprintf(writer, "hello\n")
	})
	fmt.Println(">> HTTP Over [GMSSL/TLS] running...")
	err = http.Serve(ln, nil)
	if err != nil {
		panic(err)
	}
}

// gmGCMClientRun GCM模式测试
func TestGmClient(t *testing.T) {

	// 信任的根证书
	certPool := x509.NewCertPool()
	cacert, err := ioutil.ReadFile(caCert)
	assert.NoError(t, err)
	certPool.AppendCertsFromPEM(cacert)

	cs, err := gmtls.LoadX509KeyPair(csCert, csKey)
	assert.NoError(t, err)
	ce, err := gmtls.LoadX509KeyPair(ceCert, ceKey)
	assert.NoError(t, err)

	config := &gmtls.Config{
		GMSupport:    &gmtls.GMSupport{},
		RootCAs:      certPool,
		Certificates: []gmtls.Certificate{cs, ce},
		CipherSuites: []uint16{gmtls.GMTLS_ECC_SM4_CBC_SM3},
		//CipherSuites: []uint16{gmtls.GMTLS_SM2_WITH_SM4_SM3},
		//CipherSuites: []uint16{gmtls.GMTLS_ECDHE_SM2_WITH_SM4_SM3},
		ServerName:         "server sign (SM2)",
		InsecureSkipVerify: false,
	}

	conn, err := gmtls.Dial("tcp", "localhost:44330", config)
	assert.NoError(t, err)
	defer conn.Close()

	//this commented code is used to test tassl server
	//for i := 0; i < 10; i++ {
	//	req := []byte(fmt.Sprintf("hello chainmaker%d\n", i))
	//	_, _ = conn.Write(req)
	//
	//	time.Sleep(time.Second * 3)
	//}

	req := []byte("GET / HTTP/1.1\r\n" +
		"Host: localhost\r\n" +
		"Connection: close\r\n\r\n")
	conn.Write(req)

	//buff := make([]byte, 1024)
	//for {
	//	n, _ := conn.Read(buff)
	//	if n <= 0 {
	//		break
	//	} else {
	//		fmt.Printf("%s", buff[0:n])
	//	}
	//}

	fmt.Println(">> SM2_SM4_GCM_SM3 suite [PASS]")
}

func TestLoadX509KeyPair(t *testing.T) {
	cs, err := cmtls.LoadX509KeyPair(csCert, csKey)
	assert.NoError(t, err)
	assert.NotNil(t, cs)

	csx, err := gmtls.LoadX509KeyPair(csCert, csKey)
	assert.NoError(t, err)
	assert.NotNil(t, csx)
}
