#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#define MAXN 1000

int main()
{
    char str[MAXN];
    scanf("%s", str);

    unsigned char digest[MD5_DIGEST_LENGTH];

    int length = strlen(str);
    MD5((const unsigned char*) str, length, digest);
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
