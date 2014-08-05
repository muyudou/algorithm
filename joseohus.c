/*约瑟夫环问题：n个数字形成一个圆圈，从数字0开始，每次从圆圈
  中删除第m个数字，当一个数字删除后，从被删除数字的下一个继续删除第
  m个数字。求圆圈中最后一个数字
 */
#include <stdio.h>

//这个是最简单的实现，模拟这个过程，用了一个数组记录该数字是否被删除，
//初始为0，被删除后对应的数组值为-1,循环直到剩下一个数，再扫描一遍输出，
//时间复杂度：这个时间复杂度有些高阿...O(n*n)了...
int simplejosephus(int n, int m)
{
    int cnt = n, k=0, i;
    int *arr = malloc(sizeof(int)*n);
    memset(arr, 0, n);

    while (cnt > 1)
    {
        for (i = 0; i < n; i++)
        {
            if (arr[i] == -1)
                continue;
            k++;
            if (k%m == 0)
            {
                 arr[i] = -1;
                 cnt--;
                 k = 0;
            }
        }
    }

    for (i = 0; i < n; i++)
        if (arr[i] != -1)
        {
            cnt = i;
            break;
        }
    free(arr);
   return cnt;
}

/*将该问题用数学的方法表示出来，最后是一个递推式，假设知道n-1个数字最后
  剩下的数x，则n个数最后剩下的数是(x+m)%n; 1个数是是0，式子如下：
  f[1] = 0; f[i] = (f[i-1]+m) % i (i > 1),编程完爆其他方法阿，时间复杂度也是  O（n），算法真好....
 */
int josephus(int n, int m)
{
    int f = 0, i;
    for (i = 2; i <= n; i++)
        f = (f+m)%i;
    return f;
}

int main()
{
    int n, m, i, k, cnt;
    scanf("%d%d\n", &n, &m);
    printf("%d\n", simplejosephus(n, m));
    printf("%d\n", josephus(n, m));

    return 0;
} 
