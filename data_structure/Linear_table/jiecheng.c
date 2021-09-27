#include <stdio.h>
#include <stdlib.h>
int fun1(int);
int fun2(int);
void hannuota(int, char, char, char);
int main(int argc, char const *argv[])
{
    // printf("%d\n", fun1(4));
    // printf("==============\n");
    // printf("%d\n", fun2(5));
    hannuota(10, 'A', 'B', 'C');
    system("pause");
    return 0;
}
//求n的阶乘
int fun1(int num)
{
    if (num == 1)
        return 1;
    int result = fun1(num - 1);
    return result * num;
}
//求1+2+3...+n的和
int fun2(int num)
{
    if (num == 1)
        return 1;
    int result = fun2(num - 1);
    return result + num;
}
void hannuota(int n, char from, char buffer, char to)
{
    if (n == 1)
    {
        printf("move %d from %c to %c\n", n, from, to);
        return;
    }
    hannuota(n - 1, from, to, buffer);
    hannuota(1, from, buffer, to);
    hannuota(n - 1, buffer, from, to);
}