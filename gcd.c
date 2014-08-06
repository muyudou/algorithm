//求最大公约数
#include <stdio.h>

int gcd(int x, int y)
{
    if (x < y)
    {
        return gcd(y, x);
    }
    if (y == 0)
       return x;
    int xi = x % 2;
    int yi = y % 2;
    if (xi && yi)
       return 2 * gcd(x>>1, y>>1);
    else if (xi && !yi)
       return gcd(x>>1, y);
    else if (!xi && yi)
       return gcd(x, y>>1);
    else
        return gcd(x-y, y);
}

int main()
{
    int num1, num2;
    scanf("%d %d\n", &num1, &num2);
    printf("%d\n", gcd(num1, num2));
    return 0;
}
