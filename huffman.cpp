#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MAX_FREQ = INT_MAX/2;

class HuffMan
{
public:
    HuffMan(int *arr, int num) : nodenum(num)
    {
        for (int i = 0; i < num; i++)
            nodevec.push_back(new Node('a'+i, arr[i]));
    }

    ~HuffMan()
    {
        
    }

    //huffman树的构造方法，借助队列，每次出对两个值最小的，构成一个新的子树
    //共循环n-1次，因为每次减少两个，产生一个，经过n-1次剩一个
    void HuffManTree()
    {
        make_heap(nodevec.begin(), nodevec.end(), NodeCrti());

        int i;
        Node *node;
        for (i = 0; i < nodenum-1; i++)
        {
            node = new Node;
            node->left = nodevec.front();
            pop_heap(nodevec.begin(), nodevec.end(), NodeCrti());
            nodevec.pop_back();
            node->right = nodevec.front();
            pop_heap(nodevec.begin(), nodevec.end(), NodeCrti());
            nodevec.pop_back();
            node->freq = node->left->freq + node->right->freq;
            nodevec.push_back(node);
            push_heap(nodevec.begin(), nodevec.end(), NodeCrti());
        }
    }

    void display()
    {
        display(*(nodevec.begin()));
	cout << endl;
    }

    void displaypaths()
    {
        Node *node = *(nodevec.begin());
	vector<int> arr(nodenum, -1);
	displaypaths(node, arr, 0);
    }
private:
    struct Node
    {
        Node *left;
        Node *right;
        int freq;
	char data;

        Node(char d = 0, int f = MAX_FREQ)
	    : left(NULL), right(NULL), freq(f), data(d)
        {}
    };

    //堆排序准则
    class NodeCrti
    {
    public:
        bool operator()(const Node *node1, const Node *node2)
        {
            return node1->freq > node2->freq;
        }
    };

    void display(Node *root)
    {
        if (root == NULL)
	    return;
        cout << root->freq << " ";
	display(root->left);
	display(root->right);
    }

    //显示fuffman树的编码
    void displaypaths(Node *node, vector<int> &arr, int i)
    {
         if (node == NULL)
	    return;
	 if (node->left == NULL && node->right == NULL)
	 {
	     cout << node->data << ": ";
	     for (int j = 0; j < i; j++)
	         cout << arr[j] << " ";
	     cout << endl;
	 }
	 if (node->left != NULL)
	 {
	     arr[i] = 0;
	     displaypaths(node->left, arr, i+1);
	 }
         if (node->right != NULL)
	 {
	     arr[i] = 1;
	     displaypaths(node->right, arr, i+1);
	 }
    }

    vector<Node *> nodevec;
    int nodenum;
};

int main()
{
    int arr[6] = {45, 13, 12, 16, 9, 5};
    HuffMan h(arr, 6);
    h.HuffManTree();
    h.display();
    h.displaypaths();

    return 0;
}
