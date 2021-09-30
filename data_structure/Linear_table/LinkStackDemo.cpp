#define ok 1
#define ERROR 0
#define OVERFLOW -1
#include <iostream>
typedef int ElemType;
typedef int Status;
typedef struct StackNode
{
    ElemType elem;
    struct StackNode *next;

} StackNode, *LinkStack;
void LnitStack_L(LinkStack &);
void DestoryStack_L(LinkStack &);
int IsEmpty_L(LinkStack);
void StackLength_L(LinkStack, int &);
Status GetTop_L(LinkStack &, ElemType &);
void ClearStack_L(LinkStack &);
Status Push_L(LinkStack &, ElemType);
Status Pop_L(LinkStack &, ElemType &);
int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
void LnitStack_L(LinkStack &LS)
{
    LS = new StackNode;
    LS->next = NULL;
}
void DestoryStack_L(LinkStack &LS)
{
    LinkStack TS = LS;
    while (LS)
    {
        LS = LS->next;
        delete TS;
        TS = LS;
    }
}
int IsEmpty_L(LinkStack LS)
{
    return LS->next == NULL;
}
void StackLength_L(LinkStack LS, int &length)
{
    length = 0;
    LinkStack PS = LS->next;
    while (PS)
    {
        length++;
        PS = PS->next;
    }
}
Status GetStack_L(LinkStack &LS, ElemType &e)
{
    e = LS->next->elem;
}
void ClearStack_L(LinkStack &LS)
{
    LinkStack TS = LS->next;
    LinkStack PS = TS;
    while (TS)
    {
        TS = TS->next;
        delete PS;
        PS = TS;
    }
}
Status Push_L(LinkStack &LS, ElemType e)
{
    LinkStack newNode = new StackNode;
    newNode->elem = e;
    newNode->next = LS->next;
    LS->next = newNode;
}
Status Pop_L(LinkStack &LS, ElemType &e)
{
    LinkStack Node = LS->next;
    e = Node->elem;
    LS->next = Node->next;
    delete Node;
}