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
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
} CLNode, *CircleLinkList;
void CreateList_T(CircleLinkList &, int);
int IsEmpty(CircleLinkList);
CircleLinkList ConnectTwoCL(CircleLinkList, CircleLinkList);
void showCL(CircleLinkList);
int main(int argc, char const *argv[])
{
    CircleLinkList CT1, CT2; //定义尾节点
    CreateList_T(CT1, 4);
    CreateList_T(CT2, 3);
    showCL(CT1);
    showCL(CT2);
    CircleLinkList newCT = ConnectTwoCL(CT1, CT2);
    showCL(newCT);
    system("pause");
    return 0;
}
//创建节点数位n的循环链表，并返回尾指针
void CreateList_T(CircleLinkList &CT, int n)
{
    CircleLinkList CL = new CLNode;
    CL->next = NULL;
    CT = CL;
    char c;
    for (int i = 0; i < n; i++)
    {
        CircleLinkList newNode = new CLNode;
        cout << "请输入第" << i + 1 << "个数据："
             << endl;
        cin >> newNode->data;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        CT->next = newNode;
        CT = newNode;
        newNode->next = CL;
    }
}
int IsEmpty(CircleLinkList CT)
{
    return CT->next == NULL;
}
CircleLinkList ConnectTwoCL(CircleLinkList Ta, CircleLinkList Tb)
{
    if (IsEmpty(Ta))
        return Tb;
    if (IsEmpty(Tb))
        return Ta;
    CircleLinkList p = Ta->next;
    Ta->next = Tb->next->next;
    delete Tb->next;
    Tb->next = p;
    return Tb;
}

void showCL(CircleLinkList CT)
{
    if (IsEmpty(CT))
        return;
    CircleLinkList temp = CT->next->next;
    while (temp != CT->next)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n==================\n");
}