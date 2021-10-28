/*
 * @Author: your name
 * @Date: 2021-10-25 16:53:26
 * @LastEditTime: 2021-10-28 21:43:13
 * @LastEditors: Please set LastEditors
 * @Description: 采用邻接矩阵创建无向图
 * @FilePath: \C_data_structure\data_structure\graph\GraphDemo.cpp
 */
#include <iostream>
#define MVNum 100
#define MaxInt 4672
typedef char VerType;
typedef int ArcTyped;
typedef struct
{
    VerType vexs[MVNum];
    ArcTyped arcs[MVNum][MVNum];
    int vexnum, arcnum; //vexnum顶点数，arcnum边数
} AMGraph;
using namespace std;
void CreateUDN(AMGraph &, int, int);
int LocateVex(AMGraph, int);
void traver(AMGraph);
int main(int argc, char const *argv[])
{
    AMGraph G;
    CreateUDN(G, 4, 3);
    traver(G);
    system("pause");
    return 0;
}
void CreateUDN(AMGraph &G, int v, int a)
{
    if ((v * (v - 1)) / 2 < a)
    {
        cout << "输入的顶点数和边数不正确" << endl;
        return;
    }
    G.vexnum = v;
    G.arcnum = a;
    if (v > MVNum)
    {
        return;
    }
    //输入顶点信息
    for (int i = 0; i < G.vexnum; i++)
    {
        cout << "请输入第" << i + 1 << "个顶点值";
        cin >> G.vexs[i];
        cout << '\n';
    }
    //初始化邻接矩阵
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j] = MaxInt;
        }
    }
    //构造邻接矩阵
    for (int i = 0; i < G.arcnum; i++)
    {
        int v1, v2; //顶点的下标
        ArcTyped w; //边的权重
        cin >> v1 >> v2 >> w;
        int m = LocateVex(G, v1);
        int n = LocateVex(G, v2);
        if (m < 0 || n < 0)
        {
        }
        G.arcs[m][n] = w;
        G.arcs[n][m] = w;
    }
}
//返回v的下标
int LocateVex(AMGraph G, VerType V)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vexs[i] == V)
        {
            return i;
        }
    }
    return -1;
}
void traver(AMGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        cout << G.vexs[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < G.vexnum; i++)
    {
        cout << G.vexs[i] << " ";
        for (int j = 0; j < G.vexnum; j++)
        {
            cout << G.arcs[i][j] << " ";
        }
        cout << "\n";
    }
}