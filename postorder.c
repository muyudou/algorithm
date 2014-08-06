//判断一个数组是否是一棵二叉查找树的后序遍历顺序
#include <stdio.h>

typedef struct Node *pNode;
typedef pNode Tree;
struct Node
{
    int data;
    pNode left;
    pNode right;
};

//从后续遍历构造二叉树，似乎还有问题
void post2bintree(pNode *root, int *arr, int i)
{
    if (i < 0)
        return;
    (*root) = (pNode)malloc(sizeof(struct Node));
    (*root)->data = arr[i];
    (*root)->left = NULL;
    (*root)->right = NULL;
    if (i > 0)
    {
        if (arr[i] < arr[i-1])
            post2bintree(&(*root)->right, arr, i-1);
        else if (arr[i-1] < arr[i])
            post2bintree(&(*root)->left, arr, i-1);
    }
}

void display(pNode root)
{
    if (root == NULL)
        return;
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

//不用构造二叉树，从这个序列中直接判断，递归判断，从最后一个元素开始找，
//最后一个元素是根，向前遍历，直到找到一个比它小的元素，以这个元素为分割
//分别判断左右两边是否符合二叉查找树，判断方式是找到那个分割元素后，遍历从
//开始元素到该元素，如果有大于根元素的元素，则错误
int isBinTree(int *arr, int b, int e)
{
    if (b == e)
        return 1;
    int i = e-1;
    while (arr[e] < arr[i] && i >= b)
        --i;
    int k;
    for (k = b; k < i; k++)
        if (arr[k] > arr[e])
            return 0;
    int r = isBinTree(arr, i+1, e-1);
    int l = isBinTree(arr, b, i);
    return r && l;
}

int main()
{
    int arr[4] = {7, 4, 6, 5};
    Tree root;
    //post2bintree(&root, arr, 6);
    printf("%d\n", isBinTree(arr, 0, 6));
    //display(root);

    return;
}
