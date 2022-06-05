#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *, int *);
int jacobi(int, int);
int sqr_mltpl(int, int, int);

void main()
{
    int a = 0, n, x, y, flag = 0, i;
    printf("enter n: ");
    scanf("%d", &n);
    srand(time(NULL));
    for (i = 0; i < 100; )
    {
        a = rand() % n;
        if (a)
        {
            i++;
            x = jacobi(a, n);
            if (!x)
            {
                printf("%d is composite.\n", n);
                flag = 1;
                break;
            }
            else
            {
                y = sqr_mltpl(a, (n - 1) >> 1, n);
                if (!((x == y) || ((x + n) == y)))
                {
                    printf("%d is composite.\n", n);
                    flag = 1;
                    break;
                }
            }
        }
    }
    if (!flag)
        printf("%d is prime.\n", n);
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int jacobi(int a, int n)
{
    int result = 1;
    if (a > n)
        a %= n;
    while (a)
    {
        while (!(a & 1))
        {
            if ((n & 7) == 3 || (n & 7) == 5)
                result = -result;
            a >>= 1;
        }
        swap(&a, &n);
        if ((a & 3) == 3 && (n & 3) == 3)
            result = -result;
        a %= n;
    }
    if (n == 1)
        return result;
    else
        return 0;
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