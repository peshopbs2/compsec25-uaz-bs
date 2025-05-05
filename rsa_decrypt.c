#include <stdio.h>
#include <stdlib.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#define MAXN 4096
#define KEYFILE "private.pem"

RSA* load_private_key(const char* filename)
{
    FILE *keyFile = fopen(filename, "rb");
    RSA *rsa = PEM_read_RSAPrivateKey(keyFile, NULL, NULL, NULL);
    fclose(keyFile);
    return rsa;
}

int hex_to_bin(const char *hex, unsigned char* binary)
{
    int len = 0;
    for(int i = 0; hex[i] != '\0' && hex[i+1] != '\0'; i += 2)
    {
        sscanf(&hex[i], "%2hhx", &binary[len]);
        len++;
    }
    return len;
}

int decrypt_rsa(RSA* rsa, const unsigned char* encrypt, int encryptLen, 
    unsigned char* decrypt)
{
    return RSA_private_decrypt(encryptLen, encrypt, decrypt, rsa,
        RSA_PKCS1_OAEP_PADDING);
}

int main()
{
    RSA* rsa = load_private_key(KEYFILE);
    char hex[MAXN];
    scanf("%s", hex);
    unsigned char encrypt[MAXN];
    int encryptLen = hex_to_bin(hex, encrypt);
    printf("Encrypted len: %d\n", encryptLen);

    unsigned char decrypt[MAXN];
    int decryptLen = decrypt_rsa(rsa, encrypt, encryptLen, decrypt);
    printf("Decrypted len: %d\n", decryptLen);

    printf("%.*s\n", decryptLen, decrypt);
    return EXIT_SUCCESS;
}
