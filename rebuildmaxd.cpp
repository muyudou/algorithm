//给定一个二叉查找树的前序和后序序列，构造出二叉树
//找到一个二叉树中节点的最远距离
#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    char chValue;
    int maxleft;   //到叶子节点的最大距离
    int maxright;
    Node(char ch) : left(NULL), right(NULL), 
        chValue(ch), maxleft(0), maxright(0) {}
};

//非递归算法
void rebuild(char *preorder, char *pinorder, Node **root)
{
    stack<Node *> stk;
    Node *node;
    Node *rt;
    Node *pre;
    Node *prert;
    bool flag = false;
    int cnt = 0;
    while (*preorder != '\0')
    {
        //将根节点的左子树进栈
        while (*pinorder != *preorder)
        {
            node = new Node(*pinorder);
            stk.push(node);
            pinorder++;
        }
        //为相等的节点分配一个结点，当前子树的根节点
        node = new Node(*pinorder);
        rt = node;  //当前子树的根指向该节点
        preorder++;
        pinorder++;

        if (++cnt == 1) //如果是第一个根，说明是树的根节点，赋值
        {
            *root = rt;
            prert = rt;  //指向上一个根节点
        }
        else
        {
            prert->right = rt; 
            prert = rt;
        }
       
        //当栈不空的时候将左孩子节点都出栈，并放置好
        pre = rt;
        while (!stk.empty())
        {
            cnt++;
            node = stk.top();
            stk.pop();
            preorder++;
            pre->left = node;
            pre = node;
        }
    }
}

void display(Node *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->chValue << " ";
    display(root->right);
}

//求二叉树中节点的最远距离，将每个节点看成一个二叉树的根，和下面的节点构成这棵子树
//遍历所有这些子树，然后找出这些子树中的最远距离，是maxleft, maxright和(maxleft+maxright)
//的最大值
int findmaxlen(Node *&root, int &max)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL)
        root->maxleft = findmaxlen(root->left, max) + 1;
    if (root->right != NULL)
        root->maxright = findmaxlen(root->right, max) + 1;
    if (max < root->maxleft + root->maxright)
        max = root->maxleft + root->maxright;
    return root->maxleft > root->maxright ? root->maxleft : root->maxright;
}

int main()
{
    char preorder[10] = "abdcef";
    char inorder[10] = "dbaecf";
    Node *root;
    rebuild(preorder, inorder, &root);
    display(root);
    cout << endl;
    int max = 0;
    cout << findmaxlen(root, max) << endl;
    cout << max << endl;
    return 0;
}
