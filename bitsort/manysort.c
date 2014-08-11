//给10^7个数据排序，这些数据不重复，且每个都小于10^7
#include <iostream>
#include <bitset>
#include <fstream>
using namespace std;

const int MAXN = 10000000;
//1 使用位图，使用可以表示10^7个位的字符串，每个表示一个数，先使用bit_set
void sort1(ifstream &infile)
{
    ofstream out("datasort.txt");
    bitset<MAXN> bits;

    int data, i, count = 0;
    while (infile >> data)
        bits.set(data);
    for (i = 0; i < bits.size(); i++)
    {
        if (bits.test(i))
        {
            count++;
            out << i << ' ';
            if (count % 25 == 0)
                out << '\n';
        }
    }
    cout << count << endl;
}

int main()
{
    ifstream infile;
    infile.open("data.txt");
    if (!infile)
        cout << "打开文件错误" << endl;
    sort1(infile);
    infile.close();

    return 0;
}
