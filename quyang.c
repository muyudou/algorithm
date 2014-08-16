//从0-n个元素中随机选择m个数，并且是没有重复的有序的选择
#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

//解法1:依次考虑0,1,...,n-1的整数，通过随机测试队每个整数进行选择，
//选择的标准是从n个整数中选择m个整数，则每个被选中的数字的概率是m/n
//从r个剩余的整数中选择s个整数，概率是r/s
void getknuth(int m, int n)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        //从n-i个元素中选择m元素的概率
        if ((rand()%(n-i)) < m)
        {
            cout << i << " ";
            m--;
        }
    }
    cout << endl;
}

//解法2：用set实现
void gensets(int m, int n)
{
    set<int> s;
    while (s.size() <= m)
        s.insert(rand()%n);
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << endl;
}

//解法3:把包含0到n-1的有序数组顺序打乱，然后将前m个元素排序输出
void genshuf(int m, int n)
{
    int i, j;
    int *arr = new int[n];
    for (i = 0; i < n; i++)
        arr[i] = i;
    for (i = 0; i < m; i++)
    {
       //从n-i个元素中随机选择一个元素, 每次都是从未选择的元素中选择元素
       //所以保证了元素的不重复性
       j = rand() % (n-i);
       swap(arr[i], arr[j]);
    }
    sort(arr, arr+m);
    for (i = 0; i < m; i++)
        cout << arr[i] << " ";
    cout << endl;
    delete [] arr;
}

int main()
{
    int n, m;
    cin >> n >> m;
    getknuth(m, n);
    gensets(m, n);
    genshuf(m, n);

    return 0;
}
