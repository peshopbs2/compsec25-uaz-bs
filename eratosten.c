#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool* eratosten(int x)
{
    bool* seive = (bool*) malloc(sizeof(bool) * (x + 1));
    memset(seive, false, sizeof(bool) * (x + 1));
    for(int i = 2; i <= x; i++)
    {
        if(!seive[i])
        {
            for(int j = i + i; j <= x; j += i)
            {
                seive[j] = true;
            }
        }
    }
    return seive;
}

void print_numbers(bool* seive, int x)
{
    for(int i = 2; i <= x; i++)
    {
        if(!seive[i])
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int x;
    scanf("%d", &x);
    bool* seive = eratosten(x);
    print_numbers(seive, x);

    return EXIT_SUCCESS;
}