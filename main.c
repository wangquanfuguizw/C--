/*#include<stdio.h>
#include<stdlib.h>

typedef int TreeNodeType;
typedef struct
{
    TreeNodeType data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode;
void InitBiTree(BitNode** Node);  //初始化
void PreOrderTraverse(BitNode *root);//先序遍历
void InOrderTraverse(BitNode *root);//中序遍历
void PostOrderTraverse(BitNode *root);//后序遍历
*/


#include <stdio.h>
#include <stdlib.h>

typedef int TreeNodeType;
typedef struct node{ //树的结点
    TreeNodeType data;
    struct node* left;
    struct node* right;
} Node;

typedef struct { //树根
    Node* root;
} Tree;
void InitBiTree(Tree* tree, int value);//创建树
void PreOrderTraverse(Node *node);//先序遍历
void InOrderTraverse(Node *node);//中序遍历
void PostOrderTraverse(Node *node);//后序遍历

void InitBiTree(Tree* tree, int value)
{
    Node* node=(Node*)malloc(sizeof(Node));//创建一个节点
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    if (tree->root == NULL)//判断树是不是空树
    {
        tree->root = node;
    }
    else {//不是空树
        Node* temp = tree->root;//从树根开始
        while (temp != NULL)
        {


            if (value < temp->data)//小于就进左儿子
            {
                if (temp->left == NULL)
                {
                    temp->left = node;
                    return;
                }
                else {
                    temp = temp->left;
                }
            }
            else {

                if (temp->right == NULL)
                {
                    temp->right = node;
                    return;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
    return;
}

void PreOrderTraverse(Node *node)
{
    if (node != NULL)
    {
        printf("%d ",node->data);
        PreOrderTraverse(node->left);
        PreOrderTraverse(node->right);
    }
}

void InOrderTraverse(Node* node)
{
    if (node != NULL)
    {
        InOrderTraverse(node->left);
        printf("%d ",node->data);
        InOrderTraverse(node->right);
    }
}

void PostOrderTraverse(Node *node)
{
    if (node != NULL)
    {
        PostOrderTraverse(node->left);
        PostOrderTraverse(node->right);
        printf("%d ",node->data);
    }
}

int main()
{
    Tree tree;
    tree.root = NULL;//创建一个空树
    int n;
    printf("请输入创建树的个数：");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)//输入n个数并创建这个树
    {
        int temp;
        printf("请输入第%d个数：", i+1);
        scanf("%d",&temp);
        InitBiTree(&tree, temp);
        printf("\n");
    }
    printf("\n先序遍历：\t");
    PreOrderTraverse(tree.root);
    printf("\n");
    printf("\n中序遍历：\t");
    InOrderTraverse(tree.root);
    printf("\n");
    printf("\n后序遍历：\t");
    PostOrderTraverse(tree.root);
    printf("\n");
    return 0;
}
