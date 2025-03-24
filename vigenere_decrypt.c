#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_decrypt(char* cipher, char* key)
{
    int cipher_length = strlen(cipher);
    int key_length = strlen(key);

    char* plaintext = (char*) malloc(sizeof(char) * (cipher_length + 1));
    memset(plaintext, '\0', sizeof(char) * (cipher_length + 1));
    for(int i = 0; i < cipher_length; i++)
    {
        if(isalpha(cipher[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
            if(islower(cipher[i]))
            {
                plaintext[i] = 'a' + (cipher[i] - 'a' - shift + 26) % 26;
            }
            else
            {
                plaintext[i] = 'A' + (cipher[i] - 'A' - shift + 26) % 26;
            }
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }

    plaintext[cipher_length] = '\0';
    return plaintext;
}

int main()
{
    char cipher[MAXN];
    scanf("%s", cipher);

    char key[MAXN];
    scanf("%s", key);

    char* plaintext = vigenere_decrypt(cipher, key);
    printf("%s", plaintext);
    free(plaintext);
    return EXIT_SUCCESS;
}
