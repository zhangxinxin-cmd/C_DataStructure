#define MAXLEN 255
#define OK 1
#define ERROR -1
#include <iostream>
using namespace std;
typedef int Status;
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;
void StrAssign(SString &, char[]);
int NumCompare(int, int);
int StrCompare(SString, SString);
int Strlength(SString &);
Status Concat(SString &, SString &);
Status subString(SString, SString &, int, int);
Status Index(SString, SString, int &);
int main(int argc, char const *argv[])
{
    SString T1;
    SString T2;
    char chs1[] = "abcdefg";
    StrAssign(T1, chs1);
    char chs2[] = "de";
    StrAssign(T2, chs2);
    int index = 100;
    Index(T1, T2, index);
    cout << index << endl;
    system("pause");
    return 0;
}
// 通过赋值来初始化字符串
void StrAssign(SString &T, char chars[])
{
    int i = 0;
    while (chars[i] != '\0')
    {
        if ((i + 1) == MAXLEN)
        {
            cout << "被赋值字符串长度过长";
            break;
        }
        T.ch[i] = chars[i];
        i++;
    }
    T.ch[i] = '\0';
    T.length = i;
}
// 返回字符串长度
int Strlength(SString &T)
{
    return T.length;
}
int NumCompare(int num1, int num2)
{
    return num1 - num2;
}
// 从第一个字符的ASCII开始比较T1和T2,若大于,则返回1,等于返回0,小于返回-1,若共同长度内都相等,则字符串长度更长的大
int StrCompare(SString T1, SString T2)
{
    int length1 = Strlength(T1);
    int length2 = Strlength(T2);
    int length = length2;
    if (length1 < length)
        length = length1;
    for (int i = 0; i < length; i++)
    {
        int result = NumCompare(T1.ch[i], T2.ch[i]);
        if (result < 0)
            return -1;
        if (result > 0)
            return 1;
    }
    if (length1 > length2)
        return 1;
    else if (length1 == length2)
        return 0;
    else
        return -1;

    return 1;
}
// 连接T1和T2成新的T1
Status Concat(SString &T1, SString &T2)
{
    if ((T1.length + T2.length) > MAXLEN)
        return ERROR;
    for (int i = 0; i < T2.length; i++)
    {
        T1.ch[T1.length - 1 + i] = T2.ch[i];
    }
    T1.length = T1.length + T2.length;
    return OK;
}
//从下标为pos的位置截取长度为len的字符串到subT中去
Status subString(SString T, SString &subT, int pos, int len)
{
    if (pos < 0 || pos >= T.length || len < 0 || (pos + len) > T.length)
    {
        return ERROR;
    }
    int i;
    for (i = pos; i < pos + len; i++)
    {
        subT.ch[subT.length++] = T.ch[i];
    }
    subT.ch[subT.length] = '\0';
    return OK;
}
//判断T1中是否含有T2,若含有,则将初始下标填入pos中
Status Index(SString T1, SString T2, int &pos)
{
    for (int i = 0; i < T1.length - T2.length + 1; i++)
    {
        SString subT;
        StrAssign(subT, "");
        subString(T1, subT, i, T2.length);
        if (!StrCompare(subT, T2))
        {
            pos = i;
            return OK;
        }
    }
    return ERROR;
}