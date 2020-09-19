#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define OK        1
#define ERROR     0
#define OVERFLOW  -2
typedef int ElemType;
typedef struct lnode
{	ElemType  data;
	struct LNode  *next;
}LNode, *LinkList;

void createfromhead(LinkList L,int n);
	/* �ӱ�ͷ����β�������пհ�ͷ���ĵ����� */
void printlist(LinkList L);
	/* ������пհ�ͷ���ĵ�����L�ĸ���Ԫ�� */
int length(LinkList L);		/* ͳ�ƴ��пհ�ͷ���ĵ������� */
int InitList_L(LinkList* L);/*������ĳ�ʼ��*/
LNode *LocateElem(LinkList L, ElemType e);  /*����*/
int listinsert(LinkList L, int i, ElemType e); /*����*/
int listdelete(LinkList L, int i);         /*ɾ��*/

int InitList_L(LinkList* L)
{
   (*L)=(LNode*)malloc(sizeof(LNode));
   if(!L) exit(OVERFLOW);
   (*L)->next=NULL;
   return OK;
}


void createfromhead(LinkList L,int n)
{
	int i;
	LNode *p,*q;
   	q = L;
	printf("\t�밴λ�����������Ԫ��: ");
	for(i=1; i<=n; ++i)
	{
		p = (LNode *)malloc(sizeof(LNode));
		scanf("%d",&(p->data));
		p->next = q->next;
		q->next = p;
		q = p;
		}
}

void printlist(LinkList L)
{
	LNode * p;
	p = L->next;		                /* �����հ�ͷ��� */
	printf("\t�������Ԫ��Ϊ: ");
	while(p)
	{					                /* ���μ�����Ԫ�� */
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n\t");
}

int length(LinkList L)
{
	int i;
	LNode *p;
	i = 0;
	p = L;
	while(p->next != NULL)
	{						    /* �Ա�ͷ����β���μ�����Ԫ�� */
		p = p->next;		    /* ����һλ */
		i++;				    /* ������i--��¼Ԫ�ظ��� */
	}
	return i;
}

LNode *LocateElem(LinkList L, ElemType e)
{                                //�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
        LNode *p;
        p = L->next;             //��ʼ����pָ����Ԫ���
        while(p && p->data != e) //˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�������������e
            p = p->next;         //pָ����һ�����
        return p;                //���ҳɹ�����ֵΪe�Ľ���ַp������ʧ��pΪNULL
}

int listinsert(LinkList L,int i,ElemType e)
{
    LinkList p=L,s;
    int j=0;
    while(p&&(j<i-1))
    {
        p=(LinkList)p->next;
        ++j;
    }
    if(!p||j>i-1)
    {
        return ERROR;
    }
    else
    {
        s=(LinkList)malloc((sizeof(LNode)));
        s->data=e;      //��s����ڵ�����������һ��e������Ҫ�������ֵ��
        s->next=p->next;//��pָ�Ľڵ���sָ�Ľڵ���ͬ��������һ����ʱ��pҲ�Ͳ�ָ��ԭ���ĵط���
        p->next=(struct LNode *)s;
    }
    return OK;
}

int listdelete(LinkList L, int i)
{
    int j;
    LinkList p,q;
    p=L;
    j=1;
    while(p->next&&j<i)
    {
        p=(LinkList)p->next;
        j++;
    }
    if(!(p->next)||j>i||i >= length(L))    {
        return ERROR;
    }
    q = (LinkList)p->next;        //��ʱq�Ľڵ�Ϊp�Ľڵ��һ
    p->next = q->next;
    free(q);
    return OK;
}



int main()
{
	int n,len=0,b,m;
	LinkList L;
	InitList_L(&L);
	printf("\n\t�ӱ�ͷ����β�������пհ�ͷ���ĵ�����");
	printf("\n\t������Ԫ�ظ���( n ): ");
	scanf("%d",&n);
	createfromhead(L, n);
	len = length(L);
	printf("\n\t������ĳ���Ϊ: %d\n",len);
	printlist(L);
	while(1){
        printf("�������������Ĳ�����ţ�1������\t2������\t3��ɾ��\t4���˳�\n");
        scanf("%d", &b);
        switch(b)
        {
        case 1:
            printf("\t��������Ҫ���ҵ�Ԫ�أ�");
            scanf("%d", &n);
            n = LocateElem(L, n);
            printf("\t��Ԫ�صĽ���ַ�ǣ�%d�����޴�Ԫ����Ϊ0��\n", n);
            break;
        case 2:
            printf("\t��������Ҫ����Ԫ�ص�λ�ú�ֵ��");
            scanf("%d %d",&n,&b);
            if(length(L)<n) printf("\t����ֵ����\n");
            else {
            listinsert(L, n, b);
            printlist(L);
            printf("\t���\n");
            }
            break;
        case 3:
            printf("\t��ѡ����Ҫɾ����Ԫ����ţ�");
            scanf("%d", &n);
            if(length(L)<n) printf("\t����ֵ����\n");
            else {
            listdelete(L, n);
            printlist(L);
            printf("\t���\n");
            }
            break;
        case 4:
            return 0;
        }
	}
}
