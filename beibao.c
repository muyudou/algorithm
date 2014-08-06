/* 0-1背包问题：
   c[i][m]表示从前i个物体选择若干件放入最多承重m的背包的最大价值
   对这i个物体的每一个k<=i，或者放进去c[i-1][m-w[k]]+v[k]，或者不放c[i-1][m]
   c[i][m] = max(c[i-1][m-k[i]], c[i-1][k]),转化为i-1个物体的子问题
   i = 0 || m = 0 : c[i][m] = 0;
 */

void beibao(int *v, int *w, int n, int W)
{
    int **c = (int **)malloc(sizeof(int*)*n);

    int i, j;
    for (i = 0; i <= n; i++)
    {
        c[i] = (int *)malloc(sizeof(int)*(W+1));
        memset(c[i], 0, W+1);
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= W; j++)
        {
            int wei = j-w[i-1];
            if (wei < 0)
                c[i][j] = 0;
            else if (c[i-1][j] > c[i-1][wei] + v[i-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i-1][wei] + v[i-1];
        }
    }

    for (i = 0; i <= n; i++)
    {
        if (i != 0)
            printf("%d %d\t", w[i-1], v[i-1]);
        for (j = 0; j <= W; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    for (i = 0; i <= n; i++)
    {
        free(c[i]);
    }
}

int main()
{
    int v[5] = {4, 10, 16, 5, 10};
    int w[5] = {10, 5, 8, 5, 10};

    beibao(v, w, 5, 10);
    return 0;
}
