//(str[i] - 'a' + key) % 26 + 'a'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000

char* cezar_decipher(char* cipher, int key)
{
    int length = strlen(cipher);
    char* str = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            str[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            str[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(cipher[i] >= '0' && cipher[i] <= '9')
        {
            str[i] = (cipher[i] - '0' - key + 10) % 10 + '9';
        }
        else
        {
            str[i] = cipher[i];
        }
    }
    str[length] = '\0';

    return str;
}

int read_cipher(char* filename, char* cipher)
{
    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }

    if(fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file.\n");
        return EXIT_FAILURE;
    }

    fclose(fp);

    return EXIT_SUCCESS;
}


int main()
{
    char filename[MAXN];
    printf("Enter filename: \n");
    scanf("%s", filename);
    char cipher[MAXN];
    if(read_cipher(filename, cipher) == EXIT_SUCCESS)
    {
        int key;
        printf("Enter key:\n");
        scanf("%d", &key);
    
        char* text = cezar_decipher(cipher, key);

        printf("%s", text);
        free(text);

        return EXIT_SUCCESS;    
    }
    else
    {
        return EXIT_FAILURE;
    }
}
