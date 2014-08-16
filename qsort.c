#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//单边快速排序
int randint(int a, int b)
{
    return a+rand()%(b-a+1);
}

void qsort(int *arr, int l, int u)
{
    if (l >= u)
        return;

    swap(&arr[l], &arr[randint(l,u)]);
    int pivot = arr[l];

    int m = l, i;
    for (i = l+1; i <= u; i++)
    {
        if (arr[i] < pivot)
            swap(&arr[++m], &arr[i]);
    }
    swap(&arr[l], &arr[m]);
    qsort(arr, l, m-1);
    qsort(arr, m+1, u);
}

void qsort2(int *arr, int l, int u)
{
    if (l >= u)
        return;
    swap(&arr[l], &arr[randint(l, u)]);
    
    int i = l+1;
    int j = u;

    for(;;)
    {
        while (i <= u && arr[i] < arr[l])
            i++;
        while (j >= l && arr[l] < arr[j])
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    } 
    //这里要注意与谁交换，i指向的是比它大的数，j是指比它小的数
    //如果选择第一个元素为枢纽元，第一个元素最后应该是比枢纽元小的元素
    //所以要与最后的j指向的元素交换
    swap(&arr[l], &arr[j]); 
    qsort2(arr, l, j-1);
    qsort2(arr, j+1, u);
}

int main()
{
    int arr[8] = {55, 41, 59, 26, 53, 58, 97, 93};

    qsort2(arr, 0, 7);

    int i;
    for (i = 0; i < 8; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
