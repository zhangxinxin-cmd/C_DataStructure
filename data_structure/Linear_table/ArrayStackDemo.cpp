/*
 * @Author: your name
 * @Date: 2021-09-29 09:01:10
 * @LastEditTime: 2021-10-02 20:03:22
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C_data_structure\data_structure\Linear_table\ArrayStackDemo.cpp
 */
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#include <iostream>
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType *elem;
    int top;
    int StackSize;
} SqStack;

//函数声明

void LnitStack_Sq(SqStack &);
void DestoryStack_Sq(SqStack &);
int IsEmpty_Sq(SqStack);
int IsFull_Sq(SqStack);
void StackLength_Sq(SqStack, int &);
Status GetTop_Sq(SqStack, ElemType &);
void ClearStack_Sq(SqStack &);
Status Push_Sq(SqStack &, ElemType);
Status Pop_Sq(SqStack &, ElemType &);
int main(int argc, char const *argv[])
{
    SqStack AS;
    LnitStack_Sq(AS);
    Push_Sq(AS, 12);
    ElemType data = 0;
    Pop_Sq(AS, data);
    cout << data;
    system("pause");
    return 0;
}
//返回一个空栈
void LnitStack_Sq(SqStack &AS)
{
    AS.elem = new ElemType(MAXSIZE);
    if (!AS.elem)
        return exit(OVERFLOW);
    AS.top = -1;
    AS.StackSize = MAXSIZE;
}
//销毁栈
void DestoryStack_Sq(SqStack &AS)
{
    delete AS.elem;
    AS.elem = NULL;
}
//判断栈是否为空
int IsEmpty_Sq(SqStack AS)
{
    return AS.top == -1;
}
//判断栈是否满
int IsFull_Sq(SqStack AS)
{
    return (AS.top + 1) == AS.StackSize;
}
//获取栈的长度
void StackLength_Sq(SqStack AS, int &l)
{
    l = AS.top + 1;
}
//取栈顶元素
Status GetTop_Sq(SqStack AS, ElemType &e)
{
    if (!(AS.top + 1))
        return ERROR;
    e = AS.elem[AS.top];
    return OK;
}
//清空栈
void ClearStack_Sq(SqStack &AS)
{
    AS.top = -1;
}
//压栈
Status Push_Sq(SqStack &AS, ElemType e)
{
    if (IsFull_Sq(AS))
        return ERROR;
    AS.elem[++AS.top] = e;
    return OK;
}
//出栈
Status Pop_Sq(SqStack &AS, ElemType &e)
{
    if (IsEmpty_Sq(AS))
        return ERROR;
    e = AS.elem[AS.top--];
    return OK;
}