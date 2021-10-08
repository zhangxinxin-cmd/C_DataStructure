/*
 * @Author: your name
 * @Date: 2021-09-27 21:34:07
 * @LastEditTime: 2021-10-08 14:23:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C_data_structure\data_structure\Linear_table\jiecheng.c
 */
#define MAXNUM 10
#include <stdio.h>
#include <stdlib.h>
int fun1(int);
int fun2(int);
void print_num(int);
void hannuota(int, char, char, char);
int main(int argc, char const *argv[])
{
    // printf("%d\n", fun1(4));
    // printf("==============\n");
    // printf("%d\n", fun2(5));
    // hannuota(10, 'A', 'B', 'C');
    print_num(1);
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
// 从num打印到MAXNUM再打印到num
void print_num(int num)
{
    if (num == MAXNUM)
    {
        printf("%d\n", num);
        return;
    }
    printf("%d\n", num);
    print_num(num + 1);
    printf("%d\n", num);
}