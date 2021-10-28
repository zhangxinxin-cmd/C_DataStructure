/*
 * @Author: zhangxinxin
 * @Date: 2021-10-08 22:44:08
 * @LastEditTime: 2021-10-09 00:30:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C_data_structure\data_structure\Tree\SqBiTreeDemo.cpp
 */
#define MAXSTSIZE 100
#include <iostream>
typedef int TElemType;
typedef TElemType SqBiTree[MAXSTSIZE]; //给TElemType类型得大小为MAXSTSIZE得数组起别名为SqBiTree
using namespace std;
int main(int argc, char const *argv[])
{
    SqBiTree bt;
    cout << sizeof(bt);
    system("pause");
    return 0;
}
