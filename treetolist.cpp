#include <iostream>
#include <stack>
using namespace std;

struct BTreeNode
{
    int data;
    BTreeNode *left;
    BTreeNode *right;
    bool flag;
    BTreeNode(int val) : data(val), left(NULL), right(NULL), flag(true) {}
};

typedef BTreeNode* pNode;

pNode tree2list(pNode &root)
{
    if (root == NULL)
        return NULL;
    pNode node = root, pre = NULL;
    stack<pNode> stk;

    //循环处理每个结点，对于每个节点，首先将左孩子进栈，之后判断栈是否为空，
    //如果不为空，出栈一个元素，然后判断pre是否为null，不为空则将pre和node
    //改为双向链表，之后更新pre
    stk.push(node);
    while (!stk.empty())
    {
        while (node->flag && node->left != NULL)
        {
            stk.push(node->left);
            node = node->left;
        }
        
        if (!stk.empty())
        {
            node = stk.top();
            stk.pop();
            if (pre != NULL)
            {
                pre->right = node;
                node->left = pre;
                node->flag = false;
            }
            pre = node;
            if (node->right != NULL)
            {
                stk.push(node->right);
                node = node->right;
            }
        }
    }
    return root;
}

void display(pNode root)
{
    pNode p;
    while (root != NULL)
    {
        p = root;
        root = root->left;
    }
    root = p;
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

void createTree(pNode &root)
{
    int val;
    if (root == NULL)
    {
        cin >> val;
        if (val != -1)
        {
            root = new BTreeNode(val);
            createTree(root->left);
            createTree(root->right);
        }
    }
}

void displayTree(pNode root)
{
    if (root == NULL)
        return;
    displayTree(root->left);
    cout << root->data << " ";
    displayTree(root->right);
}
int main()
{
    pNode root = NULL;
    createTree(root);
    displayTree(root);
    cout << endl;
    tree2list(root);
    display(root);

    return 0;
}
