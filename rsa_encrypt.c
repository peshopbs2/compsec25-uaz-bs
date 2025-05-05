#include <stdio.h>
#include <stdlib.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#define KEYFILE "public.pem"
#define BUFFER_SIZE 4096

RSA* load_public_key(const char* filename)
{
    FILE* fp = fopen(filename, "rb");
    //TODO: check if file is not available
    RSA* rsa = PEM_read_RSAPublicKey(fp, NULL, NULL, NULL);
    //TODO: check if reading is not ok
    fclose(fp);
    return rsa;
}

int encrypt_message(RSA* rsa, const unsigned char *plaintext, unsigned char *cipher)
{
    int length = strlen(plaintext) + 1;
    int result = RSA_public_encrypt(length, plaintext, cipher, rsa, 
        RSA_PKCS1_OAEP_PADDING);
    return result;
}

int main()
{
    unsigned char plaintext[BUFFER_SIZE];
    scanf("%s", plaintext);
    unsigned char cipher[BUFFER_SIZE];
    RSA* rsa = load_public_key(KEYFILE);
    int encrypted_len = encrypt_message(rsa, plaintext, cipher);
    //TODO: check if encrypted_len is -1
    for(int i = 0; i < encrypted_len; i++)
    {
        printf("%02x", cipher[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
