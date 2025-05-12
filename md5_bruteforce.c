#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#define MAXN 1000

unsigned char* str_to_md5(unsigned char* str)
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    int length = strlen(str);
    MD5((const unsigned char*) str, length, digest);
    unsigned char* result = (unsigned char*) malloc(32);
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        sprintf(&result[i*2], "%02x", digest[i]);
    }
    return result;
}

int main()
{
    char hash[MAXN];
    scanf("%s", hash);
    for(char letter1 = 'A'; letter1 <= 'Z'; letter1++)
    {
        for(char letter2 = 'A'; letter2 <= 'Z'; letter2++)
        {
            for(char letter3 = 'A'; letter3 <= 'Z'; letter3++)
            {
                for(char letter4 = 'A'; letter4 <= 'Z'; letter4++)
                {
                    unsigned char current[] = {letter1, letter2, letter3, letter4, '\0'};
                    unsigned char* current_hash = str_to_md5(current);
                    printf("%s ", current_hash);
                    if(strcmp(hash, current_hash) == 0)
                    {
                        printf("\n%s -> %s\n", current, current_hash);
                        return EXIT_SUCCESS;   
                    }                 
                }
            }
        }    
    }
    
    
    printf("\n");
    return EXIT_SUCCESS;
}
