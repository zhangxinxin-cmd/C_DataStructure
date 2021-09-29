#include <iostream>
#include <string>
using namespace std;
typedef struct Book
{
    char id[20];
    char name[20];
    int price;
} Book;
typedef struct LNode
{
    Book book;
    struct LNode *next;
} LNode, *LinkList;

//函数声明

void LinkList_L(LinkList &);
int IsEmpty(LinkList &);
void CreateList_L(LinkList &, int);
void showList_L(LinkList);
void LocateBook_L(LinkList, char[], LinkList &);
void fun(char[]);
int main(int argc, char const *argv[])
{
    LinkList L;
    // LinkList_L(L);
    CreateList_L(L, 3);
    // showList_L(L);
    LinkList RL;
    LocateBook_L(L, "123", RL);
    showList_L(RL);
    system("pause");
    return 0;
}
void LinkList_L(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
}
int IsEmpty(LinkList L)
{
    return L->next == NULL;
}
void CreateList_L(LinkList &L, int n)
{
    L = new LNode;
    LinkList p = L;
    for (int i = 0; i < n; i++)
    {
        LinkList newNode = new LNode;
        cout << "请输入第" << i + 1 << "个:" << endl;
        cout << "请输入id：";
        cin >> newNode->book.id;
        cout << "请输入书名:";
        cin >> newNode->book.name;
        cout << "请输入价格:";
        cin >> newNode->book.price;
        p->next = newNode;
        newNode->next = NULL;
        p = newNode;
    }
}

void showList_L(LinkList L)
{
    LinkList T = L->next;
    while (T)
    {

        cout << T->book.id << "," << T->book.price << "元" << endl;
        T = T->next;
    }
}
//根据输入的id创建可能书目的链表并填入RL中
void LocateBook_L(LinkList L, char id[], LinkList &RL)
{
    LinkList P = L->next;
    string ID = id;
    int length = ID.length(); //得到id字符串长度
    string LID = P->book.id;
    if (LID.length() < length)
        length = LID.length();           //得到ID和LID字符串长度最小值
    string IDstr = ID.substr(0, length); //按最小值截取ID
    RL = new LNode;
    RL->next = NULL;
    LinkList q = RL;
    while (P)
    {
        LID = P->book.id;
        string LIDstr = LID.substr(0, length); //按最小值截取LID
        if (IDstr == LIDstr)
        {
            q->next = P;
            q = P;
        }
        P = P->next;
    }
    q->next = NULL;
}