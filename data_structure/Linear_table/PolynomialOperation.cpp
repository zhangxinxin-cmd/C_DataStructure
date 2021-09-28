/* 
2021.9.28
求多项式Pn(x)=P0+P1X+P2X^2+P3X^3+...+Pnx^n结果
 */
#include <iostream>
#include <math.h>
using namespace std;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;

//函数声明
void CreateList_T(LinkList &, int);
int calculate(LinkList, int);

int main(int argc, char const *argv[])
{
    LinkList Li;
    int n = 4;
    int x = 3;
    CreateList_T(Li, n);
    printf("%d", calculate(Li, x));
    system("pause");
    return 0;
}
//尾插法创造节点
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
// 根据两个头节点计算一元多项式Pn(x)=P0+P1X+P2X^2+P3X^3+...+Pnx^n;
int calculate(LinkList Li, int x)
{
    int i = 0;
    LinkList Pi = Li->next;
    int result = 0;
    while (Pi)
    {
        result += (Pi->data) * pow(x, i);
        Pi = Pi->next;
        i++;
    }
    return result;
}