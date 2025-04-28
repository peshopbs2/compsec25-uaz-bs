#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/des.h>
#define KEY_SIZE 8
#define DATA_SIZE 1000

unsigned char hex_to_byte(const char* hex)
{
    //TODO: change the function so it's faster
    unsigned int byte;
    sscanf(hex, "%2x", &byte);
    return (unsigned char) byte;
}

int main()
{
    unsigned char key[KEY_SIZE] = "banichka";
    char hex_input[DATA_SIZE * 2];
    scanf("%s", hex_input);

    int hex_len = strlen(hex_input);
    if(hex_len % 2 != 0)
    {
        printf("Invalid hex input!\n");
        return EXIT_FAILURE;
    }

    int cipher_len = hex_len / 2;
    unsigned char cipher[cipher_len];
    for(int i = 0; i < cipher_len; i++)
    {
        cipher[i] = hex_to_byte(&hex_input[i * 2]);
    }

    unsigned char decrypted[cipher_len];
    DES_key_schedule key_schedule;
    DES_set_key( (DES_cblock*) key, &key_schedule);

    for(int i = 0; i < cipher_len; i += 8)
    {
        DES_ecb_encrypt((DES_cblock*) (cipher + i),
            (DES_cblock*) (decrypted + i), &key_schedule, DES_DECRYPT);
    }

    unsigned char pad_value = decrypted[cipher_len - 1];
    if(pad_value > 8)
    {
        pad_value = 0;   
    }

    int original_len = cipher_len - pad_value;
    fwrite(decrypted, 1, original_len, stdout);
    printf("\n");
    return EXIT_SUCCESS;
}
