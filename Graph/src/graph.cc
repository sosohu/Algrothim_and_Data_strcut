#include "graph.h"
#include <iostream>
#include <queue>
#include <algorithm>

using std::cout;
using std::endl;
using std::queue;
using std::min;
using std::pair;
using std::make_pair;

int Graph_Map::arcsize(){
	if(arcnum != -1)	return arcnum;
	arcnum = 0;
	for(int i = 0; i < vexnum; i++){
		for(int j = 0; j <vexnum; j++){
			if(map[i][j] != INT_MAX)	arcnum++;
		}
	}
	if(kind == UG)	arcnum = arcnum / 2;
	return arcnum;
}

int Graph_List::arcsize(){
	if(arcnum != -1)	return arcnum;
	arcnum = 0;
	for(int i = 0; i < vexnum; i++){
		for(int j = 0; j <list[i].size(); j++){
			arcnum++;
		}
	}
	if(kind == UG)	arcnum = arcnum / 2;
	return arcnum;
}

vector<int> Graph_Map::getNeighbour(int i){
	vector<int> ret;
	for(int j = 0; j < vexnum; j++){
		if(map[i][j] != INT_MAX)
			ret.push_back(j);
	}
	return ret;
}

vector<int> Graph_List::getNeighbour(int i){
	vector<int> ret;
	for(int j = 0; j < list[i].size(); j++){
		ret.push_back(list[i][j].index);
	}
	return ret;
}

void dfs_aux(int i, Graph *g, vector<bool> &visited){
	visited[i] = true;
	cout<<i<<endl;
	vector<int> next = g->getNeighbour(i);
	for(int i = 0; i < next.size(); i++){
		if(!visited[next[i]])
			dfs_aux(next[i], g, visited);
	}
}

// 对于dfs和bfs,若是采用邻接矩阵存储则时间复杂度为O(V^2), 用邻接表存储时间复杂度为O(V+E)
void dfs(Graph *g){
	cout<<"dfs:"<<endl;
	int vexsize = g->vexsize();
	vector<bool> visited(vexsize, false);
	for(int i = 0; i < vexsize; i++){
		if(!visited[i]){
			dfs_aux(i, g, visited);
		}
	}
}

void bfs_aux(int i, Graph *g, vector<bool> &visited){
	queue<int> q;
	q.push(i);
	int cur;
	vector<int> next;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		visited[cur] = true;
		cout<<cur<<endl;
		next = g->getNeighbour(cur);
		for(int j = 0; j < next.size(); j++){
			if(!visited[next[j]])
				q.push(next[j]);
		}
	}
}

void bfs(Graph *g){
	cout<<"bfs:"<<endl;
	int vexsize = g->vexsize();
	vector<bool> visited(vexsize, false);
	for(int i = 0; i < vexsize; i++){
		if(!visited[i]){
			bfs_aux(i, g, visited);
		}
	}
}

// Prim  -----------------------------------------------------
// Time Complex O(VlgV)
int MinSpanTree_Prim(vector<vector<int> > &data){
	int n = data.size();
	if(n <= 0)  return 0;
    vector<int> closeEdge(n, 0);
    // 初始化closeEdge函数
    for(int i = 1; i < n; i++){
        closeEdge[i] = data[0][i];
    }
    int sum = 0, count = 1, min = 0, index = 0;
    while(count++ < n){
        min = INT_MAX;
        for(int i = 0; i < n; i++){
            if(closeEdge[i] != 0 && min > closeEdge[i]){
                index = i;
                min = closeEdge[i];
            }
        }
        sum = sum + min;
	        closeEdge[index] = 0; // 不用再被找
        for(int i = 0; i < n; i++){
            if(closeEdge[i] != 0 && data[index][i] < closeEdge[i])
                closeEdge[i] = data[index][i];
        }
    }
    return sum;
}
// Prim  -----------------------------------------------------

//kruskal ----------------------------------------------------
// Time Complex O(ElgE)
struct Edge{
	int s;
	int e; 
	int w; // 权值
	Edge(int s, int e, int w) : s(s), e(e), w(w){}
};

bool EdgeCmp(const Edge& a, const Edge& b){
    return a.w < b.w;
}

int root(int x, vector<Edge> &edges, vector<int> &father){
    if(x != father[x])
        father[x] = root(father[x], edges, father);   // 这点非常重要,能够减少很多时间
    return father[x];
}


bool join(int x, int y, vector<Edge> &edges, vector<int> &father){
    int rx = root(x, edges, father);
    int ry = root(y, edges, father);
    if(rx == ry)    return false;
    else{
        father[rx] = ry;
        return true;
    }
}


int MinSpanTree_Kruskal(vector<vector<Node> > &data){ // data是了邻接表
	vector<Edge> edges;
	for(int i = 0; i < data.size(); i++){
		for(int j = 0; j < data[i].size(); i++){
			edges.push_back(Edge(i, data[i][j].index, data[i][j].weight));
		}
	}
	sort(edges.begin(), edges.end(), EdgeCmp);
	vector<int> father(data.size(), 0);  // 表明父节点
	for(int i = 0; i < data.size(); i++){
        father[i] = i;
    }
	int vecnum = data.size(), arcnum = edges.size();
	int count = 0;
    int sum = 0;
    for(int i = 0; i < arcnum && count < vecnum - 1; i++){
        if(join(edges[i].s, edges[i].e, edges, father)){
            sum = sum + edges[i].w;
            count++;
        }
    }
    return sum;
}
//kruskal ----------------------------------------------------


//joint search -----------------------------------------------
// Time Complex O(V + E)
void jointDfs(vector<vector<Node> > &data, vector<int> &visited, vector<int> &low,
			 vector<int> &ret, int v, int &count, bool isRoot = false){
	visited[v] = count++;
	Node cur;
	int sons = 0;
	int l = visited[v];
	for(int i = 0; i < data[v].size(); i++){
		cur = data[v][i];
		if(visited[cur.index] == INT_MAX){
			sons++;
			jointDfs(data, visited, low, ret, cur.index, count);
			if(visited[v] <= low[cur.index])	ret.push_back(v);
			l = min(low[cur.index], l);
		}else{
			l = min(visited[cur.index], l);
		}
	}
	low[v] = l;
	if(isRoot && sons > 1){
		ret.push_back(v);
	}
}

vector<int> jointPointSearch(vector<vector<Node> > &data){
	int vecnum = data.size();
	vector<int> visited(vecnum, INT_MAX);  // visited array
	vector<int> low(vecnum, INT_MAX);     // low array
	vector<int> ret;
	int count = 0;

	for(int i = 0; i < vecnum; i++){
		if(visited[i] != INT_MAX){
			jointDfs(data, visited, low, ret, i, count, true);
		}
	}
}
//joint search -----------------------------------------------


//topo sort    -----------------------------------------------
//使用dfs方式进行topo排序
//Time Complex O(N + E)
void topoDfs(vector<vector<Node> > &data, vector<int> &inDegree,
			 vector<int> &ret, int v){
	ret.push_back(v);
	for(int i = 0; i < data[v].size(); i++){
		inDegree[data[v][i].index]--;
		if(inDegree[data[v][i].index] == 0){
			topoDfs(data, inDegree, ret, data[v][i].index);
		}
	}
}

vector<int> topoSort(vector<vector<Node> > &data){
	int vecnum = data.size();
	vector<int> inDegree(vecnum, 0);
	vector<int> ret(vecnum, 0);

	//compute in degree
	for(int i = 0; i < vecnum; i++){
		for(int j = 0; j < data[i].size(); i++){
			inDegree[data[i][j].index]++;
		}
	}
	//dfs
	int count = 0;
	for(int i = 0; i < vecnum; i++){
		if(inDegree[i] == 0){
			topoDfs(data, inDegree, ret, i);
		}
	}
	return ret;
}
//topo sort    -----------------------------------------------
