/*#include<stdio.h>
#include<stdlib.h>

typedef int TreeNodeType;
typedef struct
{
    TreeNodeType data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode;
void InitBiTree(BitNode** Node);  //��ʼ��
void PreOrderTraverse(BitNode *root);//�������
void InOrderTraverse(BitNode *root);//�������
void PostOrderTraverse(BitNode *root);//�������
*/


#include <stdio.h>
#include <stdlib.h>

typedef int TreeNodeType;
typedef struct node{ //���Ľ��
    TreeNodeType data;
    struct node* left;
    struct node* right;
} Node;

typedef struct { //����
    Node* root;
} Tree;
void InitBiTree(Tree* tree, int value);//������
void PreOrderTraverse(Node *node);//�������
void InOrderTraverse(Node *node);//�������
void PostOrderTraverse(Node *node);//�������

void InitBiTree(Tree* tree, int value)
{
    Node* node=(Node*)malloc(sizeof(Node));//����һ���ڵ�
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    if (tree->root == NULL)//�ж����ǲ��ǿ���
    {
        tree->root = node;
    }
    else {//���ǿ���
        Node* temp = tree->root;//��������ʼ
        while (temp != NULL)
        {


            if (value < temp->data)//С�ھͽ������
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
    tree.root = NULL;//����һ������
    int n;
    printf("�����봴�����ĸ�����");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)//����n���������������
    {
        int temp;
        printf("�������%d������", i+1);
        scanf("%d",&temp);
        InitBiTree(&tree, temp);
        printf("\n");
    }
    printf("\n���������\t");
    PreOrderTraverse(tree.root);
    printf("\n");
    printf("\n���������\t");
    InOrderTraverse(tree.root);
    printf("\n");
    printf("\n���������\t");
    PostOrderTraverse(tree.root);
    printf("\n");
    return 0;
}
