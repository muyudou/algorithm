#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//生成300个1-1000的整数
int main()
{
    struct timeval tpstart;
    int n = 100;
    int i = 0;
    for (i = 0; i < 300; i++)
    {
        gettimeofday(&tpstart, NULL);
        srand(tpstart.tv_usec); //使用微秒撒种子
        n = 1+(int)(1000.0*(rand()/(RAND_MAX+1.0)));
        printf("%d ", n);
    }
    return 0;
}
