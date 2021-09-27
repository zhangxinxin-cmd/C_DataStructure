/* 
2021.9.27
双向链表
 */
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
typedef struct DuLNode
{
    ElemType data;
    DuLNode *prior, *next;

} DuLNode, *DuLinkList;
int IsEmpty(DuLinkList);
void CreateList_DUL(DuLinkList &, int);
Status LisstInsert_DUL(DuLinkList &, ElemType, int);
int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
void CreateList_L(DuLinkList &DL, int n)
{
    DL = new DuLNode;
    DL->prior = DL;
    DL->next = DL;
    DuLinkList temp = DL;
    char c;
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个数据：", i + 1);
        DuLinkList newNode = new DuLNode;
        cin >> newNode->data;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        temp->next = newNode;
        newNode->prior = temp;
        newNode->next = NULL;
        temp = newNode;
    }
}
int IsEmpty(DuLinkList DL)
{
    return DL->next == NULL;
}
//在第i个位置插入值为e的节点
Status LisstInsert_DUL(DuLinkList &DL, ElemType e, int i)
{
    DuLinkList temp = DL->next;
    int j = 1;
    while (temp != NULL && j < i)
    {
        temp = temp->next;
        j++;
    }
    if (!temp || j > i)
        return ERROR;
    DuLinkList newNode = new DuLNode;
    newNode->data = e;
    newNode->prior = temp->prior;
    temp->prior->next = newNode;
    newNode->next = temp;
    temp->prior = newNode;
    return OK;
}