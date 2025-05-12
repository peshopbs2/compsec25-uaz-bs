#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#define MAXN 1000

int main()
{
    char str[MAXN];
    scanf("%s", str);

    unsigned char digest[SHA256_DIGEST_LENGTH];

    int length = strlen(str);
    SHA256((const unsigned char*) str, length, digest);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
