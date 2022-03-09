package tbass_test

import (
	"crypto/ecdsa"
	"crypto/rsa"
	gox509 "crypto/x509"
	"crypto/x509/pkix"
	"encoding/asn1"
	"encoding/hex"
	"encoding/pem"
	"fmt"
	"log"
	"testing"

	"chainmaker.org/chainmaker/common/v2/crypto/asym"

	tjx509 "github.com/tjfoc/gmsm/x509"

	cmecdsa "chainmaker.org/chainmaker/common/v2/crypto/asym/ecdsa"
	cmrsa "chainmaker.org/chainmaker/common/v2/crypto/asym/rsa"
	cmsm2 "chainmaker.org/chainmaker/common/v2/crypto/asym/sm2"
	"github.com/btcsuite/btcd/btcec"

	bccrypto "chainmaker.org/chainmaker/common/v2/crypto"

	"github.com/stretchr/testify/assert"

	"chainmaker.org/chainmaker/common/v2/crypto/x509"
	tjsm2 "github.com/tjfoc/gmsm/sm2"
)

func TestClientSign(t *testing.T) {
	plain := "0a0b636861696e5f646377766f10011a403532656638633639623163653464623162336464396665663466363564323864663666343262336263623265346262616139613136646330333236323537626220defccb9006320b434841494e5f51554552593a0e4745545f434841494e5f494e464f"

	sig := "304402201cb65d2110a15e2ab28c8643a740e198f797975dcbaf49a48f1482045b931c2b02203396a46c50e04e66c9fd199520bbb736c65d8639d52e94cfce076e507b356188"

	clientCrt := `-----BEGIN CERTIFICATE-----
MIICrjCCAlSgAwIBAgIDBxqMMAoGCCqGSM49BAMCMIGeMQswCQYDVQQGEwJDTjEQ
MA4GA1UECBMHQmVpamluZzEQMA4GA1UEBxMHQmVpamluZzEpMCcGA1UEChMgb3Jn
Njl2a2tmdS5jaGFpbm1ha2VyLWo1ZnF3NGhjazcxEjAQBgNVBAsTCXJvb3QtY2Vy
dDEsMCoGA1UEAxMjY2Eub3JnNjl2a2tmdS5jaGFpbm1ha2VyLWo1ZnF3NGhjazcw
HhcNMjIwMjIxMDI0OTUwWhcNMjcwMjIxMDI0OTUwWjCBojELMAkGA1UEBhMCQ04x
EDAOBgNVBAgTB0JlaWppbmcxEDAOBgNVBAcTB0JlaWppbmcxKTAnBgNVBAoTIG9y
ZzY5dmtrZnUuY2hhaW5tYWtlci1qNWZxdzRoY2s3MQ8wDQYDVQQLEwZjbGllbnQx
MzAxBgNVBAMTKnRlc3Quc2lnbi5vcmc2OXZra2Z1LmNoYWlubWFrZXItajVmcXc0
aGNrNzBZMBMGByqGSM49AgEGCCqGSM49AwEHA0IABNxhs2l1H7VLcVKSy9M/9TtX
tosa4L4lUU+0enZsgBgeQkrHPikfDQsDtWhhaV2QAW9vrNmR9sGYs2z9uiSn/pOj
ezB5MA4GA1UdDwEB/wQEAwIBpjAPBgNVHSUECDAGBgRVHSUAMCkGA1UdDgQiBCCG
b0MH6Pt+nHJWATg5J/qAQbiHaSsZ+tcsMCSieelUwzArBgNVHSMEJDAigCBpKlkh
bhjitvmVmIaXg0S/oUOk4SGCrPf0SX4If/P7bTAKBggqhkjOPQQDAgNIADBFAiBI
UsqEw63vAEz27C0DnJouI5MytvLmGGCp9mxNb70xogIhAP0UCLTyIH1jQObTlpvZ
C3cv+gl+wZSWYU0OOpsaD0qS
-----END CERTIFICATE-----`

	clientKey := `-----BEGIN PRIVATE KEY-----
MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQg69kMkjNa5t+Cq1Sy
esY+U37QeU805Fr0EW5N+oZFwyqhRANCAATcYbNpdR+1S3FSksvTP/U7V7aLGuC+
JVFPtHp2bIAYHkJKxz4pHw0LA7VoYWldkAFvb6zZkfbBmLNs/bokp/6T
-----END PRIVATE KEY-----`
	//	clientKey := `-----BEGIN PRIVATE KEY-----
	//MIGTAgEAMBMGByqGSM49AgEGCCqBHM9VAYItBHkwdwIBAQQg7ZpeoikwYhv1IL0d
	//IBnSvAQ/Rxnrf8naZB8qwgeOqdigCgYIKoEcz1UBgi2hRANCAAQA06EHIXfBLncL
	//xrLT48O5r/8IGLxWsozzRO0xSLie1iDOB/r74EiJGUWtBwtEvO/ctDs/Rp6ZPjXd
	//xehwSxM/
	//-----END PRIVATE KEY-----`

	block, _ := pem.Decode([]byte(clientCrt))

	cert, err := x509.ParseCertificate(block.Bytes)
	assert.NoError(t, err)
	pub := cert.PublicKey

	plainBytes, err := hex.DecodeString(plain)
	assert.NoError(t, err)
	log.Printf("plainBytes len = %d\n", len(plainBytes))

	sigBytes, err := hex.DecodeString(sig)
	assert.NoError(t, err)
	log.Printf("sigBytes len = %d\n", len(sig))

	hashAlgo, err := x509.GetHashFromSignatureAlgorithm(cert.SignatureAlgorithm)
	ok, err := pub.VerifyWithOpts(plainBytes, sigBytes, &bccrypto.SignOpts{
		Hash: hashAlgo,
	})
	assert.NoError(t, err)
	assert.True(t, ok)

	//sign, verify
	println("=================")
	block, _ = pem.Decode([]byte(clientKey))
	//key, err := asym.PrivateKeyFromDER(block.Bytes)
	//assert.NoError(t, err)

	//sig1, err := key.SignWithOpts(plainBytes, &bccrypto.SignOpts{
	//	Hash: hashAlgo,
	//})
	//ok, err = pub.VerifyWithOpts(plainBytes, sig1, &bccrypto.SignOpts{
	//	Hash: hashAlgo,
	//})
	//assert.NoError(t, err)
	//assert.True(t, ok)
}

type pkcs8 struct {
	Version    int
	Algo       pkix.AlgorithmIdentifier
	PrivateKey []byte
}

var oidSM2 = asn1.ObjectIdentifier{1, 2, 840, 10045, 2, 1}

func PrivateKeyFromDER(der []byte) (bccrypto.PrivateKey, error) {
	if key, err := x509.ParsePKCS1PrivateKey(der); err == nil {
		return &cmrsa.PrivateKey{K: key}, nil
	}

	if key, err := x509.ParseECPrivateKey(der); err == nil {
		if key.Curve == tjsm2.P256Sm2() {
			k := &tjsm2.PrivateKey{
				PublicKey: tjsm2.PublicKey{
					Curve: tjsm2.P256Sm2(),
					X:     key.X,
					Y:     key.Y,
				},
				D: key.D,
			}
			return &cmsm2.PrivateKey{K: k}, nil
		} else {
			return &cmecdsa.PrivateKey{K: key}, nil
		}
	}

	if key, err := gox509.ParsePKCS8PrivateKey(der); err == nil {
		switch k := key.(type) {
		case *ecdsa.PrivateKey:
			return &cmecdsa.PrivateKey{K: k}, nil
		case *tjsm2.PrivateKey:
			return &cmsm2.PrivateKey{K: k}, nil
		case *rsa.PrivateKey:
			return &cmrsa.PrivateKey{K: k}, nil
		case bccrypto.PrivateKey:
			return k, nil
		default:
			return nil, fmt.Errorf("fail to parse private key, unrecognized key type [%T]", key)
		}
	}
	if key, err := tjx509.ParsePKCS8UnecryptedPrivateKey(der); err == nil {
		return &cmsm2.PrivateKey{K: key}, nil
	}

	Secp256k1Key, _ := btcec.PrivKeyFromBytes(btcec.S256(), der)
	key := Secp256k1Key.ToECDSA()
	return &cmecdsa.PrivateKey{K: key}, nil
}
func TestPKCS8(t *testing.T) {
	clientKey1 := `-----BEGIN PRIVATE KEY-----
MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQg69kMkjNa5t+Cq1Sy
esY+U37QeU805Fr0EW5N+oZFwyqhRANCAATcYbNpdR+1S3FSksvTP/U7V7aLGuC+
JVFPtHp2bIAYHkJKxz4pHw0LA7VoYWldkAFvb6zZkfbBmLNs/bokp/6T
-----END PRIVATE KEY-----`
	clientKey2 := `-----BEGIN PRIVATE KEY-----
MIGTAgEAMBMGByqGSM49AgEGCCqBHM9VAYItBHkwdwIBAQQg7ZpeoikwYhv1IL0d
IBnSvAQ/Rxnrf8naZB8qwgeOqdigCgYIKoEcz1UBgi2hRANCAAQA06EHIXfBLncL
xrLT48O5r/8IGLxWsozzRO0xSLie1iDOB/r74EiJGUWtBwtEvO/ctDs/Rp6ZPjXd
xehwSxM/
-----END PRIVATE KEY-----`
	block1, _ := pem.Decode([]byte(clientKey1))
	//key, err := asym.PrivateKeyFromDER(block.Bytes)
	//assert.NoError(t, err)
	key1, err := asym.PrivateKeyFromDER(block1.Bytes)
	assert.NoError(t, err)
	assert.NotNil(t, key1)
	fmt.Println("key1 type = ", key1.Type())

	block2, _ := pem.Decode([]byte(clientKey2))
	//key, err := asym.PrivateKeyFromDER(block.Bytes)
	//assert.NoError(t, err)
	key2, err := asym.PrivateKeyFromDER(block2.Bytes)
	assert.NoError(t, err)
	assert.NotNil(t, key2)
	fmt.Println("key2 type = ", key2.Type())

}
