/* 
 2021.9.26
 顺序表实现和操作
 */
#define MAXSIZE 100
#define TRUE 1
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#include <iostream>
using namespace std;
typedef int Status;
typedef char ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} SqList;

//函数声明

Status lnitList_Sq(SqList &);
void DestoryList(SqList &);
int GetLength(SqList &);
int IsEmpety(SqList &);
Status GetElem(SqList, int, ElemType &);
int LocateElem(SqList, ElemType);
Status ListInsert(SqList &, int i, ElemType);
Status ListDelete(SqList &, int i, ElemType &);
void MergeList_Sq(SqList, SqList, SqList &);

int main(int argc, char const *argv[])
{
    SqList list;
    lnitList_Sq(list);
    ListInsert(list, GetLength(list) + 1, 2);
    ElemType e = 0;
    GetElem(list, 1, e);
    printf("e=%d\n", e);
    system("pause");
    return 0;
}
//创建一个空的线性表
Status lnitList_Sq(SqList &L)
{
    L.elem = new ElemType(MAXSIZE);
    if (L.elem == NULL)
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}
//销毁线性表
void DestoryList(SqList &L)
{
    if (L.elem)
        delete (L.elem);
}
//得到线性表的长度
int GetLength(SqList &L)
{
    return L.length;
}
//判断线性表是否为空
int IsEmpty(SqList &L)
{
    if (L.length == 0)
        return 0;
    return 1;
}
//查找到第i个元素
Status GetElem(SqList L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}
//查找与指定值e相同的元素的位置
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
            return i + 1; //查找成功，返回位置
    }
    return 0; //查找失败，返回0
}
//在第i个位置插入元素
Status ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1 || L.length == MAXSIZE)
        return ERROR;

    for (int j = L.length; j > i - 1; j--)
    {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}
//删除第i个位置的元素，并将删除的值返回至ezhong
Status ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return ERROR;

    for (int j = i; j < L.length; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    L.elem[L.length - 1] = e;
    L.length--;
    return OK;
}
//合并两个有序链表成一个有序链表
void MergeList_Sq(SqList LA, SqList LB, SqList &LC)
{
    LC.length = LA.length + LB.length;
    LC.elem = new ElemType(LC.length);
    int PA = 0;
    int PB = 0;
    int PC = 0;
    while (PA < LA.length && PB < LA.length)
    {
        if (LA.elem[PA] < LB.elem[PB])
            LC.elem[PC++] = LA.elem[PA++];
        else
            LC.elem[PC++] = LB.elem[PB++];
    }
    while (PA < LA.length)
        LC.elem[PC++] = LA.elem[PA++];
    while (PB < LB.length)
    {
        LC.elem[PC++] = LB.elem[PB++];
    }
}