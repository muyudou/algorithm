/*用c语言实现位图排序，位图的表示用字符或数字都行，如果是int, 则一个整数可以
  表示32位整数，给定一个n，要找出这个n在这个整数数组中的哪一个字节的哪一位，
  所以要确定两个，一个是字节位置（数组下标）和位位置
  字节位置：n/32 (采用位运算就是n >> 5,右移5位)
  位位置：n % 32（采用位运算就是跟0x1F进行相与操作, n&0x1F(对32取余最后小于
  32所以保留最后的32位为原值，即得到)）
 */
#include <stdio.h>

#define MAX 10000000
#define SHIFT 5
#define MASK 0x1F
#define DIGITS 32

//将n对应的逻辑位置置为1
void set(int *arr, int n)
{
    //printf("%d ", n);
    //n>>SHIFT,计算数组下标, n&MASK相当于对32取余即求位位置
    //然后将左移后的结果与当前元素元素进行或操作，相当于置1
    arr[n>>SHIFT] |= (1 << (n&MASK));
}

//将n对应的位置清0
void clear(int *arr, int n)
{
    arr[n>>SHIFT] &= ~(1 << (n&MASK));
}

int test(int *arr, int n)
{
    return arr[n>>SHIFT] & (1 << (n&MASK));
}

//位排序
void bsort(FILE *fp)
{
    int i, n, data;
    n = 1+MAX/DIGITS;
    int *arr = malloc(sizeof(int)*n);
    memset(arr, 0, n);
    FILE *outfp = fopen("datasort1.txt", "w");

    while (fscanf(fp, "%d", &data) != EOF)
        set(arr, data);
    int count = 0;
    for (i = 0; i < MAX; i++)
    {
        if (test(arr, i))
        {
            count++;
            fprintf(outfp, "%d ", i);
            if (count%32 == 0x0)
                fprintf(outfp, "\n");
        }
    }
    fclose(outfp);
    free(arr);
}

int main()
{
    FILE *f = fopen("data.txt", "r");
    bsort(f);
    fclose(f);

    return 0;
}
