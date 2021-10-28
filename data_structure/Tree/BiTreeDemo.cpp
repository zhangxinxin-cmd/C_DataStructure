/*
 * @Author: your name
 * @Date: 2021-10-09 00:31:42
 * @LastEditTime: 2021-10-26 23:32:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C_data_structure\data_structure\Tree\BiTreeDemo.cpp
 */
#include <iostream>
#include <string.h>
using namespace std;
typedef char TElemType;
typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

void CreateBiTree(BiTree &);
void PreOrder(BiTree);
int main(int argc, char const *argv[])
{
    BiTree bt;
    CreateBiTree(bt);
    PreOrder(bt);
    system("pause");
    return 0;
}
void CreateBiTree(BiTree &bt)
{
    cout << "Input:";
    char data;
    cin >> data;
    bt = NULL;
    if (data != '#')
    {
        bt = new BiNode;
        bt->data = data;
        CreateBiTree(bt->lchild);
        CreateBiTree(bt->rchild);
    }
}
void PreOrder(BiTree bt)
{
    if (bt != NULL)
    {
        cout << bt->data << endl;
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}