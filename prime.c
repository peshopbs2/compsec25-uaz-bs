#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int x)
{
    bool is_prime = true;
    for(int i = 2; i <= x/2; i++)
    {
        if(x % i == 0)
        {
            is_prime = false;
        }
    }
    return is_prime;
}

int main()
{
    int x;
    scanf("%d", &x);

    if(is_prime(x))
    {
        printf("The number is prime");
    }
    else
    {
        printf("The number is NOT prime");
    }

    return EXIT_SUCCESS;
}