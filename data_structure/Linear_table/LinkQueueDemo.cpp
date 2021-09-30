#define OK 1
#define ERROR 0
#define OVERFLOW -1
#include <iostream>
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct QNode
{
    ElemType e;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

//函数声明

void LnitQueue_L(LinkQueue &);
void DestoryQueue_L(LinkQueue &);
void EnQueue_L(LinkQueue &, ElemType);
int IsEmpty(LinkQueue);
Status DeQueue_L(LinkQueue &, ElemType &);
Status getFront_L(LinkQueue, ElemType &);
int main(int argc, char const *argv[])
{
    LinkQueue LQ;
    LnitQueue_L(LQ);
    EnQueue_L(LQ, 4);
    EnQueue_L(LQ, 3);
    EnQueue_L(LQ, 5);
    ElemType e;
    DeQueue_L(LQ, e);
    cout << e << endl;
    DestoryQueue_L(LQ);
    EnQueue_L(LQ, 6);
    system("pause");
    return 0;
}
//初始化队列
void LnitQueue_L(LinkQueue &LQ)
{
    LQ.front = LQ.rear = new QNode;
    if (!LQ.front)
        exit(OVERFLOW);
    LQ.front->next = NULL;
}
// 销毁队列
void DestoryQueue_L(LinkQueue &LQ)
{
    QueuePtr P = LQ.front;
    while (LQ.front)
    {
        P = LQ.front->next;
        delete LQ.front;
        LQ.front = P;
    }
    LQ.front = LQ.rear = NULL;
}
// 入队
void EnQueue_L(LinkQueue &LQ, ElemType e)
{
    QueuePtr NewP = new QNode;
    NewP->e = e;
    NewP->next = NULL;
    LQ.rear->next = NewP;
    LQ.rear = NewP;
}
// 判断队列是否空
int IsEmpty(LinkQueue LQ)
{
    return LQ.front == LQ.rear;
}
// 出队列
Status DeQueue_L(LinkQueue &LQ, ElemType &e)
{
    if (IsEmpty(LQ))
        return ERROR;
    e = LQ.front->next->e;
    LQ.front = LQ.front->next;
    return OK;
}
//得到队头元素
Status getFront_L(LinkQueue LQ, ElemType &e)
{
    if (IsEmpty(LQ))
        return ERROR;
    e = LQ.front->next->e;
}