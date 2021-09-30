/* 
2021.9.30
用数组实现队列 
 */
#define MAXSIZE 5
#define OK 1
#define ERROR -1
#include <iostream>
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType *elem;
    int front;
    int rear;
} SqQueue;
void LnitQueue_Sq(SqQueue &);
void DestoryStack_Sq(SqQueue &);
int IsEmpty(SqQueue &);
int IsFull_Sq(SqQueue);
void QueueLength_Sq(SqQueue, int &);
Status GetFront_Sq(SqQueue, ElemType &);
void ClearQueue_Sq(SqQueue &);
Status EnQueue_Sq(SqQueue &, ElemType);
Status GetQueue_Sq(SqQueue &, ElemType &);
int main(int argc, char const *argv[])
{
    SqQueue queue;
    LnitQueue_Sq(queue);
    cout << EnQueue_Sq(queue, 1) << endl;
    cout << EnQueue_Sq(queue, 2) << endl;
    cout << EnQueue_Sq(queue, 3) << endl;
    cout << EnQueue_Sq(queue, 4) << endl;
    cout << EnQueue_Sq(queue, 5) << endl;
    ElemType e = 0;
    GetQueue_Sq(queue, e);
    cout << e << "=============" << endl;
    GetQueue_Sq(queue, e);
    cout << e << endl;
    system("pause");
    return 0;
}
//创建空队列
void LnitQueue_Sq(SqQueue &SQ)
{
    SQ.elem = new ElemType[MAXSIZE];
    SQ.front = SQ.rear = 0;
}
//销毁队列
void DestoryStack_Sq(SqQueue &SQ)
{
    if (SQ.elem)
        delete SQ.elem;
    SQ.elem = NULL;
    SQ.front = SQ.rear = 0;
}
//判断队列是否为空
int IsEmpty(SqQueue &SQ)
{
    return SQ.front == SQ.rear;
}
//判断队列是否为满
int IsFull_Sq(SqQueue SQ)
{
    return (SQ.rear + 1) % MAXSIZE == SQ.front; //少用一个元素空间来判断是否满
}
//得到队列元素数量
void QueueLength_Sq(SqQueue SQ, int length)
{
    /* if (SQ.rear >= SQ.front)
        length = SQ.rear = SQ.front;
    else
    {
        length = SQ.rear + MAXSIZE - SQ.front;
    } */
    length = (SQ.rear - SQ.front + MAXSIZE) & MAXSIZE;
}
//得到队头的元素
Status GetFront_Sq(SqQueue SQ, ElemType &e)
{
    if (IsEmpty(SQ))
        return ERROR;
    e = SQ.elem[SQ.front];
    return OK;
}
//入队
Status EnQueue_Sq(SqQueue &SQ, ElemType e)
{
    if (IsFull_Sq(SQ))
        return ERROR;
    SQ.rear = SQ.rear % MAXSIZE;
    SQ.elem[SQ.rear++] = e;
    return OK;
}
Status GetQueue_Sq(SqQueue &SQ, ElemType &e)
{
    if (IsEmpty(SQ))
        return ERROR;
    SQ.front = SQ.front % MAXSIZE;
    e = SQ.elem[SQ.front++];
    return OK;
}