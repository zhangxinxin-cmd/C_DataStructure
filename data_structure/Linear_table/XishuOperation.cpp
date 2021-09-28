#include <iostream>
using namespace std;
typedef struct PNode
{
    float coef; //系数
    int expn;   //指数
    struct PNode *next;
} PNode, *Polynomial;

//函数声明

void CreateList_T(Polynomial &, int);
Polynomial UnionPolynomials(Polynomial, Polynomial);
void showList(Polynomial);
int main(int argc, char const *argv[])
{
    Polynomial Pa, Pb;
    CreateList_T(Pa, 4);
    CreateList_T(Pb, 3);
    // showList(L);
    Polynomial Pc = UnionPolynomials(Pa, Pb);
    showList(Pc);
    system("pause");
    return 0;
}
//尾插法创造节点
void CreateList_T(Polynomial &L, int n)
{
    L = new PNode;
    L->next = NULL;
    Polynomial T = L;
    for (int i = 0; i < n; i++)
    {
        Polynomial newNode = new PNode;
        cout << "输入第" << i + 1 << "个数据:" << endl;
        cin >> newNode->coef >> newNode->expn;
        while (T->next && T->expn < newNode->expn && T->next->expn < newNode->expn) //判断接下来两个节点是否均小于newNode->expn或者T已经来到尾节点
        {
            T = T->next;
        }

        Polynomial p = T->next;
        T->next = newNode;
        newNode->next = p;
        T = L;
        // printf("%p %p\n", T, L);
    }
}
//合并两个多项式
Polynomial UnionPolynomials(Polynomial Pa, Polynomial Pb)
{
    Polynomial Ta = Pa->next;
    Polynomial Tb = Pb->next;
    Polynomial Pc = new PNode;
    Pc->next = NULL;
    Polynomial Tc = Pc;
    while (Ta && Tb)
    {
        if (Ta->expn != Tb->expn)
        {
            if (Ta->expn < Tb->expn)
            {
                Tc->next = Ta;
                Tc = Tc->next;
                Ta = Ta->next;
            }
            else
            {
                Tc->next = Tb;
                Tc = Tc->next;
                Tb = Tb->next;
            }
        }
        else
        {
            float coefSum = Ta->coef + Tb->coef;
            if (coefSum)
            {
                Polynomial newNode = new PNode;
                newNode->coef = coefSum;
                newNode->expn = Ta->expn;
                Tc->next = newNode;
                Ta = Ta->next;
                Tb = Tb->next;
                // Tc->next->next = Ta;
                Tc = newNode;
                Tc->next = NULL;
            }
            else
            {
                Ta = Ta->next;
                Tb = Tb->next;
            }
        }
    }
    Polynomial P = Pa;
    if (Pb)
        P = Pb;
    while (P)
    {
        Tc->next = P;
        Ta = Tc->next;
        P = P->next;
    }
    return Pc;
}
//遍历链表并打印每一个节点
void showList(Polynomial L)
{
    Polynomial temp = L->next;
    while (temp)
    {
        printf("系数:%f,指数%d\n", temp->coef, temp->expn);
        temp = temp->next;
    }
}