//求一个整数的二进制中1的个数
#include <stdio.h>

//思路1：直接位运算，首先判断最后一位是否为1，是则+1，
//然后右移一位，但是这个算法只在数为正数时成立，如果为
//负数，则右移是算数右移，最高位是补1，会陷入死循环
int cnt1(int val)
{
    int cnt = 0;
    while (val)
    {
        if (val & 1 == 1)
            cnt++;
        val >>= 1;
    }
    return cnt;
}

//为了避免解法1的问题，可以将这个数以此与2的次幂相与，计算1的个数
int cnt1_1(int val)
{
    int flag = 1;
    int cnt = 0;
    while (flag < val)
    {
        if (val & flag == 1)
           cnt++;
        flag <<= 1; //flag左移1，依次变成2的倍数增长
    }
    return cnt;
}

//以上两种方法循环的次数都几乎等于整数的位数，如何提高时间复杂度，
//从而让计算与数中1的个数成正比？
//根据一个规律: n & (n-1)会使n的最右边的1变为0，即一次消掉一个1
//所以如果已该为循环，数中有多少1，就会循环多少次
int cnt1_2(int val)
{
    int cnt = 0;
    while (val)
    {
        val &= (val-1);
        cnt++;
    }
    return cnt;
}

int main()
{
    int val;
    scanf("%d\n", &val);
    printf("解法1：%d二进制中1的个数是:%d\n", val, cnt1(val));
    printf("解法2：%d二进制中1的个数是:%d\n", val, cnt1(val));
    printf("解法3：%d二进制中1的个数是:%d\n", val, cnt1(val));

    return 0;
}
