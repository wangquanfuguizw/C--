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
	/* 从表头到表尾建立带有空白头结点的单链表 */
void printlist(LinkList L);
	/* 输出带有空白头结点的单链表L的各个元素 */
int length(LinkList L);		/* 统计带有空白头结点的单链表长度 */
int InitList_L(LinkList* L);/*单链表的初始化*/
LNode *LocateElem(LinkList L, ElemType e);  /*查找*/
int listinsert(LinkList L, int i, ElemType e); /*插入*/
int listdelete(LinkList L, int i);         /*删除*/

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
	printf("\t请按位序依次输入各元素: ");
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
	p = L->next;		                /* 跳过空白头结点 */
	printf("\t单链表的元素为: ");
	while(p)
	{					                /* 依次检索各元素 */
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
	{						    /* 自表头至表尾依次检索个元素 */
		p = p->next;		    /* 后移一位 */
		i++;				    /* 计数器i--记录元素个数 */
	}
	return i;
}

LNode *LocateElem(LinkList L, ElemType e)
{                                //在带头结点的单链表L中查找值为e的元素
        LNode *p;
        p = L->next;             //初始化，p指向首元结点
        while(p && p->data != e) //顺链域向后扫描，直到p为空或p所指结点的数据域等于e
            p = p->next;         //p指向下一个结点
        return p;                //查找成功返回值为e的结点地址p，查找失败p为NULL
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
        s->data=e;      //在s这个节点的数据域里放一个e（我们要插入的数值）
        s->next=p->next;//让p指的节点与s指的节点相同，做完这一部分时，p也就不指向原来的地方了
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
    q = (LinkList)p->next;        //此时q的节点为p的节点加一
    p->next = q->next;
    free(q);
    return OK;
}



int main()
{
	int n,len=0,b,m;
	LinkList L;
	InitList_L(&L);
	printf("\n\t从表头到表尾建立带有空白头结点的单链表");
	printf("\n\t请输入元素个数( n ): ");
	scanf("%d",&n);
	createfromhead(L, n);
	len = length(L);
	printf("\n\t单链表的长度为: %d\n",len);
	printlist(L);
	while(1){
        printf("请输入你想做的操作序号：1、查找\t2、插入\t3、删除\t4、退出\n");
        scanf("%d", &b);
        switch(b)
        {
        case 1:
            printf("\t请输入你要查找的元素：");
            scanf("%d", &n);
            n = LocateElem(L, n);
            printf("\t该元素的结点地址是：%d（若无此元素则为0）\n", n);
            break;
        case 2:
            printf("\t请输入你要插入元素的位置和值：");
            scanf("%d %d",&n,&b);
            if(length(L)<n) printf("\t输入值有误\n");
            else {
            listinsert(L, n, b);
            printlist(L);
            printf("\t完成\n");
            }
            break;
        case 3:
            printf("\t请选择你要删除的元素序号：");
            scanf("%d", &n);
            if(length(L)<n) printf("\t输入值有误\n");
            else {
            listdelete(L, n);
            printlist(L);
            printf("\t完成\n");
            }
            break;
        case 4:
            return 0;
        }
	}
}
