#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sqr_mltpl(int , int , int );

void main()
{
    int m, n, b, k = 0, flag = 0, a = 0, flag2 = 0, i;
    printf("enter n:");
    scanf("%d", &n);
    m = n - 1;
    while (!(m & 1))
    {
        m >>= 1;
        k++;
    }
    srand(time(NULL));
    for (i = 0; i < 100;)
    {
        a = rand() % n;
        if (a)
        {
            b = sqr_mltpl(a, m, n);
            if (b == 1)
            {
                i++;
                flag = 1;
            }
            for (int j = 0; j < k; j++)
            {
                if (b == (n - 1))
                {
                    i++;
                    flag = 1;
                    break;
                }
                else
                    b = sqr_mltpl(b, 2, n);
            }
            if (!flag)
            {
                printf("%d is composite.\n", n);
                flag2 = 1;
                break;
            }
        }
    }
    if (!flag2)
        printf("%d is prime.\n", n);
}

int sqr_mltpl(int x, int e, int n)
{
    int bin[100] = {0}, i, v;
    for (i = 0; e > 0; i++)
    {
        if (e & 1)
            bin[i] = 1;
        e = e >> 1;
    }
    v = x;
    for (i = i - 2; i >= 0; i--)
    {
        v = (v * v) % n;
        if (bin[i])
            v = (v * x) % n;
    }
    return v;
}