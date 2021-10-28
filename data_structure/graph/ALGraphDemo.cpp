/*
 * @Author: your name
 * @Date: 2021-10-28 21:28:00
 * @LastEditTime: 2021-10-28 22:31:45
 * @LastEditors: Please set LastEditors
 * @Description: 有向图
 * @FilePath: \C_data_structure\data_structure\graph\ALGraphDemo.cpp
 */
#include <iostream>
#define MVNum 100
typedef char verTexType;

typedef struct ArcNode //设置弧(边)的结点结构
{
    int adjvex;
    struct ArcNode *nextarc;

} ArcNode;

typedef struct VNode //设置顶点结构
{
    verTexType data;
    ArcNode *firstarc;
} VNode, AdjList[MVNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

//创建邻接表无向图
void CreateALG(ALGraph &);

// 返回verTexType值的数组下标
int LocateVex(ALGraph &, verTexType);
//返回出度
int GetOutGrade(ALGraph, verTexType);
//返回入度
int GetInGrade(ALGraph, verTexType);
//判断数组下标i的顶点是否连接值为verTexType的顶点
bool ContainsV(ALGraph, int, verTexType);
using namespace std;
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
void CreateALG(ALGraph &G)
{
    cout << "请输入顶点数：";
    cin >> G.vexnum;
    cout << "请输入边数：";
    cin >> G.arcnum;
    for (int i = 0; i < G.vexnum; i++)
    {
        cout << "请输入第" << (i + 1) << "个顶点:";
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for (int j = 0; j < G.arcnum; j++)
    {
        verTexType v1, v2;

        cout << "输入两顶点和两者之间的权值：";
        cin >> v1 >> v2;
        int m = LocateVex(G, v1);
        int n = LocateVex(G, v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = n;
        p1->nextarc = G.vertices[m].firstarc;
        G.vertices[m].firstarc = p1;
        ArcNode *p2 = new ArcNode;
        p2->adjvex = m;
        p2->nextarc = G.vertices[n].firstarc;
        G.vertices[n].firstarc = p2;
    }
}
int LocateVex(ALGraph &G, verTexType V)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == V)
        {
            return i;
        }
    }
    return -1;
}
int GetOutGrade(ALGraph G, verTexType v)
{
    int index = LocateVex(G, v);
    if (index < 0)
    {
        return -1;
    }
    VNode vNode = G.vertices[index];
    ArcNode *temp = vNode.firstarc;
    int out = 0;
    while (temp != NULL)
    {
        out++;
        temp = temp->nextarc;
    }
    return out;
}
int GetInGrade(ALGraph G, verTexType v)
{
    int in = 0;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (ContainsV(G, i, v))
        {
            in++;
        }
    }
    return in;
}
bool ContainsV(ALGraph G, int i, verTexType v)
{
    ArcNode *temp = G.vertices[i].firstarc;
    int index = LocateVex(G, v);
    while (temp)
    {
        if (temp->adjvex == index)
        {
            return true;
        }
        temp = temp->nextarc;
    }
    return false;
}