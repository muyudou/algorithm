//生成不重复的10^7个数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//如果用栈分配数组，会溢出，因为栈的默认大小空间是2M,而这么大的数组大约是4M.//所以要在堆上分配
#define N 10000000 
#define MAXN N

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main()
{
    struct timeval tpstart;
    int m, n, i;
    FILE *fp = fopen("data.txt", "w");
    char num[100] = {};
    int *nums = malloc(sizeof(int)*N);
    int linen = 25;

    //首先生成这些顺序的数
    for (i = 0; i < N; i++)
        nums[i] = i+1;
    //之后打乱
    for (i = 0; i < N; i++)
    {
        linen--;
        gettimeofday(&tpstart, NULL);
        srand(tpstart.tv_usec); //使用微秒撒种子
        n = MAXN * (rand()/(RAND_MAX+1.0)); //生成[0-MAXN]之间的数
        //printf("%d ", n);
        swap(&nums[i], &nums[n]);  //生成一个随机数，然后交换，打乱数据
        fprintf(fp, "%d ", nums[i]);
        if (linen == 0)
        {
            fputc('\n', fp);
            linen = 25;   //每行20个数
        }
    }
    free(nums);
    return 0;
}
