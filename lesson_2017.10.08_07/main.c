#include <stdio.h>
#include <stdbool.h>
int calc(int limit);

void main()
{
    int limit   [4] = { 100, 120, 30 , 10};
    int expected[4] = {   5,  16,  6,   5};
    int result = 0;

    for (int i=0; i < sizeof(limit) / sizeof(int); i++)
    {
        result = calc(limit[i]);
        if ( result == expected[i] )
            printf("Passed: limit = %d, result = %d, expected = %d\n", limit[i], result, expected[i]);
        else
            printf("Failed!: limit = %d, result = %d, expected = %d\n", limit[i], result, expected[i]);
    }
}

int calc(int limit)
{
    int summ = 0;
    int i = 0;

    while (true)
    {
        i++;
        if ((summ > limit) && ((summ + i - limit) > i)) break;
        summ = summ + i;
    }

    return(summ - limit);
}