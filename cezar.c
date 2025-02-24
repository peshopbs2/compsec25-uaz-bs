#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
char* cezar_cipher(char* str, int key)
{
    int length = strlen(str);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        cipher[i] = (str[i] - 'a' + key) % 26 + 'a';
    }
    cipher[length] = '\0';
    return cipher;
}

int main()
{
    char str[MAXN];
    scanf("%s", str);
    int key;
    scanf("%d", &key);
    char* cipher = cezar_cipher(str, key);
    printf("%s", cipher);
    return EXIT_SUCCESS;
}