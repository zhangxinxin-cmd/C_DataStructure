/* 
2021.9.27
单链表实现和操作
 */
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
void Union(LinkList &, LinkList &);
void MergeList_L(LinkList, LinkList, LinkList &);
void ShowList_L(LinkList);

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
//两线性表的合并
void Union(LinkList &La, LinkList &Lb)
{
    int la_len = GetLength_L(La);
    int Lb_len = GetLength_L(Lb);
    ElemType e;
    for (int i = 0; i < Lb_len; i++)
    {
        GetElem_L(Lb, i + 1, e);           //将第i+1位置的值填入e中
        if (!LocateElem_L(La, e))          //判断La链表中是否存在e,没有就返回0，有返回所在位置>=1
            InsertElem_L(La, e, ++Lb_len); //将e插入La链表长度+1的位置出，也就是成为新的尾节点
    }
}
//循环实现合并两有序链表生成一个有序链表
void MergeList_L(LinkList LA, LinkList LB, LinkList &LC)
{
    LinkList PA = LA->next;
    LinkList PB = LB->next;
    LC = LA;
    LinkList PC = LC;
    while (PA && PB)
    {
        if (PA->data < PB->data)
        {
            PC->next = PA;
            PC = PA;
            PA = PA->next;
        }
        else
        {
            PC->next = PB;
            PC = PB;
            PB = PB->next;
        }
        LinkList P = PB;
        ;
        if (PA)
        {
            P = PA;
        }
        while (P)
        {
            PC->next = P;
            PC = P;
            P = P->next;
        }
    }
}
//遍历链表并打印输出每一个节点的值
void ShowList_L(LinkList L)
{
}