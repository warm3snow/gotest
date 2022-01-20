package httpstest

import (
	"fmt"
	"io/ioutil"
	"testing"

	"github.com/stretchr/testify/assert"

	cmtls "chainmaker.org/chainmaker/common/v2/crypto/tls"
	cmx509 "chainmaker.org/chainmaker/common/v2/crypto/x509"
)

var (
	caCert      = "./testdata/ca.crt"
	adminTlsKey = "./testdata/admin1.tls.key"
	adminTlsCrt = "./testdata/admin1.tls.crt"
)

func TestChainmaker_rpcserver_https_getversion_test(t *testing.T) {
	// 信任的根证书
	certPool := cmx509.NewCertPool()
	cacert, err := ioutil.ReadFile(caCert)
	assert.NoError(t, err)
	certPool.AppendCertsFromPEM(cacert)

	//tr := &http.Transport{
	//	TLSClientConfig: &cmtls.Config{RootCAs: certPool},
	//}

	cert, err := cmtls.LoadX509KeyPair(adminTlsCrt, adminTlsKey)

	config := &cmtls.Config{
		//GMSupport:    &cmtls.GMSupport{},
		RootCAs:      certPool,
		Certificates: []cmtls.Certificate{cert},
	}

	conn, err := cmtls.Dial("tcp", "localhost:12301", config)
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	req := []byte("GET /v1/getversion HTTP/1.1\r\n" +
		"Host: localhost\r\n" +
		"Connection: close\r\n\r\n")
	_, _ = conn.Write(req)
	buff := make([]byte, 1024)
	for {
		n, _ := conn.Read(buff)
		if n <= 0 {
			break
		} else {
			fmt.Printf("%s", buff[0:n])
		}
	}
}
