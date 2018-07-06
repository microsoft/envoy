REM Create a test certificate with a 15-day expiration for SSL tests.
SETLOCAL
set PATH=C:/OpenSSL-Win32/bin;%PATH%
set TEST_CERT_DIR=%TEST_TMPDIR%

mkdir "%TEST_CERT_DIR%"

set OPENSSL_CONF=%TEST_CERT_DIR%/openssl.cnf
(
echo [ req ]
echo default_bits            = 2048
echo distinguished_name      = req_distinguished_name

echo [ req_distinguished_name ]
echo countryName                     = Country Name ^(2 letter code^)
echo countryName_default             = AU
echo countryName_min                 = 2
echo countryName_max                 = 2

echo stateOrProvinceName             = State or Province Name ^(full name^)
echo stateOrProvinceName_default     = Some-State

echo localityName                    = Locality Name ^(eg, city^)

echo 0.organizationName              = Organization Name ^(eg, company^)
echo 0.organizationName_default      = Internet Widgits Pty Ltd

echo organizationalUnitName          = Organizational Unit Name ^(eg, section^)

echo commonName                      = Common Name ^(e.g. server FQDN or YOUR name^)
echo commonName_max                  = 64

echo emailAddress                    = Email Address
echo emailAddress_max                = 64
)>"%OPENSSL_CONF%"

openssl genrsa -out "%TEST_CERT_DIR%/unittestkey.pem" 1024

set country=US
set state=California
set locality=San Francisco
set organization=Lyft
set organizationalunit=Test
set commonname=Unit Test CA
set email=unittest@lyft.com

openssl req -new -key "%TEST_CERT_DIR%/unittestkey.pem" -out "%TEST_CERT_DIR%/unittestcert.csr" ^
 -sha256 -subj "/C=%country%/ST=%state%/L=%locality%/O=%organization%/OU=%organizationalunit%/CN=%commonname%/emailAddress=%email%"

openssl x509 -req -days 15 -in "%TEST_CERT_DIR%/unittestcert.csr" -sha256 ^
 -signkey "%TEST_CERT_DIR%/unittestkey.pem" -out "%TEST_CERT_DIR%/unittestcert.pem"
