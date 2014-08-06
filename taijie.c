//跳台阶问题：总共n级，一次可以跳1级或2级
//求总共多少种跳法，并分析复杂度

#include <stdio.h>

//f(n) = f(n-1)+f(n-2); f(0) = 0; f(1) = 1; f(2) = 2;
//如果让f(0) = 1,就是fibs
int taijie(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int a = 1;
    int b = 2;
    int i, c;

    for (i = 3; i <= n; i++)
    {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    scanf("%d\n", &n);

    printf("%d\n", taijie(n));
    return 0;
}
