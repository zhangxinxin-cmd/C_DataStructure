#define MAXSIZE 100
#define TRUE 1
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#include <iostream>
#include <stdio.h>
using namespace std;
typedef int Status;
typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;

//函数声明

Status LinkList_L(LinkList &);
int IsEmpty(LinkList);
Status DestoryList_L(LinkList &);
Status ClearList_L(LinkList &);
int GetLength_L(LinkList);
Status GetElem_L(LinkList, int, ElemType &);
int LocateElem_L(LinkList, ElemType);
Status InsertElem_L(LinkList &, ElemType, int);
Status DeleteElem_L(LinkList &, int, ElemType);
void CreateList_H(LinkList &, int);
void CreateList_T(LinkList &, int);

int main(int argc, char const *argv[])
{
    LinkList L;
    CreateList_H(L, 3);
    system("pause");
    return 0;
}

//生成一个空链表
Status LinkList_L(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return OK;
}
//判断链表是否为空
int IsEmpty(LinkList L)
{
    return L->next == NULL;
}
//销毁链表
Status DestoryList_L(LinkList &L)
{
    LNode *P;
    while (L != NULL)
    {
        P = L;
        L = L->next;
        delete P;
    }
    return OK;
}
//清空链表
Status ClearList_L(LinkList &L)
{
    LinkList p, q;
    q = L->next;
    /* while (q != NULL)
    {
        p=q->next;
        delete q;
        q=p;
    } */
    while (q)
    {
        p = q;
        q = q->next;
        delete p;
    }
    L->next = NULL;
    return OK;
}
//返回链表的长度
int GetLength_L(LinkList L)
{
    LinkList p = L->next;
    int length = 0;
    while (p != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}
//得到链表第i个节点的值
Status GetElem_L(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}
//找到指定元素所在位置
int LocateElem_L(LinkList L, ElemType e)
{
    LinkList p = L->next;
    int i = 1;
    while (p && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (p)
        return i;
    else
        return 0;
}
//在第i个节点前插入值为e的新节点(如果链表为空，则插入的节点为首元节点；如果i为链表长度+1，则插入的节点为新的尾节点)
Status InsertElem_L(LinkList &L, ElemType e, int i)
{
    LinkList p = L;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    LinkList q = new LNode; //定义一个新节点，用来储存e的值
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}
//删除第i个节点，并返回其值
Status DeleteElem_L(LinkList &L, int i, ElemType e)
{
    LinkList p = L;
    int j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p->next || j > i)
        return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}
//头插法生成链表
void CreateList_H(LinkList &L, int n)
{
    L = new LNode;
    L->next = NULL;
    char c;
    for (int i = 0; i < n; i++)
    {
        LinkList newNode = new LNode;
        printf("请输入第%d个数据", i + 1);
        cin >> newNode->data;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        newNode->next = L->next;
        L->next = newNode;
    }
}
//使用尾插法建立链表
void CreateList_T(LinkList &L, int n)
{
    L = new LNode;
    L->next = NULL;
    LinkList T = L;
    char c;
    for (int i = 0; i < n; i++)
    {
        LinkList newNode = new LNode;
        printf("请输入第%d个数据", i + 1);
        cin >> newNode->data;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        T->next = newNode;
        newNode->next = NULL;
        T = newNode;
    }
}