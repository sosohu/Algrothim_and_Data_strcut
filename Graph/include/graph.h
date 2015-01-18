#ifndef GRAPH_H_
#define GRAPH_H_
#include <climits>
#include <vector>

using std::vector;

//图的定义

enum Graph_Kind{
	UG,   // 无向图
	DG    // 有向图
};

class Graph{
	public:
		Graph(Graph_Kind gk, int v, int a): kind(gk), vexnum(v), arcnum(a){}

		~Graph(){}

		Graph_Kind type(){ return kind; }

		int vexsize(){ return vexnum; }

		virtual int arcsize(){}

		virtual vector<int> getNeighbour(int i){}
		
	protected:
		Graph_Kind kind;
		int vexnum;
		int arcnum;
};

// 两点之间没有边则边值为INT_MAX
class Graph_Map : public Graph{
public:

	Graph_Map(Graph_Kind k = UG, int n = 0, int m = -1) : Graph(k, n, m), map(vector<vector<int> > (n, vector<int>(n, 0))){}

	Graph_Map(vector<vector<int> > map, Graph_Kind k = UG, int m = -1) : Graph(k, map.size(), m), map(map){}

	~Graph_Map(){}

	vector<int> getNeighbour(int i);

	int arcsize();

private:
	vector<vector<int> >  map;

};

struct Node{
	int index;
	int weight;
	Node(int index = 0, int weight = 0) : index(index), weight(weight){}
};

struct Edge{
	int s;
	int e; 
	int w; // 权值
	Edge(int s = 0, int e = 0, int w = 0) : s(s), e(e), w(w){}
};

class Graph_List : public Graph{
public:
	Graph_List(Graph_Kind k = UG, int n = 0, int m = -1) : Graph(k, n, m), list(vector<vector<Node> > (n, vector<Node>())){}
	
	Graph_List(vector<vector<Node> > list, Graph_Kind k = UG, int m = -1) : Graph(k, list.size(), m), list(list){}

	~Graph_List(){}

	vector<int> getNeighbour(int i);

	int arcsize();
private:
	vector<vector<Node> > list;
};

// 图的一些操作

void dfs(Graph *g);

void bfs(Graph *g);

int MinSpanTree_Prim(vector<vector<int> > &data); // data是邻接矩阵

int MinSpanTree_Kruskal(vector<vector<Node> > &data); // data是邻接表

vector<int> jointPointSearch(vector<vector<Node> > &data); // data是邻接表

vector<int> topoSort(vector<vector<Node> > &data);  // data是邻接表

vector<Edge> criticalPath(vector<vector<Node> > &data);  // data是邻接表

vector<Edge> dijMinPath(vector<vector<Node> > &data); // data是邻接表

#endif
