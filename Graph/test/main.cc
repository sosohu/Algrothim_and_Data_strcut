#include "graph.h"
#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>

using namespace std;

void search(){
	vector<vector<int> > map(5, vector<int>(5, INT_MAX));
	map[0][1] = 2;
	map[0][2] = 2;
	map[0][3] = 2;
	map[2][4] = 2;
	Graph_Map* gm = new Graph_Map(map, DG);
	bfs(gm);
	dfs(gm);
}

void jointPoint(){
	freopen("input", "r", stdin);
	int n, m, s, e, w;
	cin>>n>>m;
	vector<vector<Node> > data(n, vector<Node>());
	while(m--){
		cin>>s>>e>>w;
		s--;
		e--;
		data[s].push_back(Node(e, w));
		data[e].push_back(Node(s, w));
	}

	vector<int> ret = jointPointSearch(data);

	for(auto i = 0; i < ret.size(); i++){
		cout<<ret[i]<<endl;
	}

	fclose(stdin);
}

void TopoSort(){
	freopen("input", "r", stdin);
	int n, m, s, e, w;
	cin>>n>>m;
	vector<vector<Node> > data(n, vector<Node>());
	while(m--){
		cin>>s>>e>>w;
		s--;
		e--;
		data[s].push_back(Node(e, w));
	}

	vector<int> ret = topoSort(data);

	for(auto i = 0; i < ret.size(); i++){
		cout<<ret[i]<<endl;
	}

	fclose(stdin);
}

void AllTopoSort(){
	freopen("input", "r", stdin);
	int n, m, s, e, w;
	cin>>n>>m;
	vector<vector<Node> > data(n, vector<Node>());
	while(m--){
		cin>>s>>e>>w;
		s--;
		e--;
		data[s].push_back(Node(e, w));
	}

	vector<vector<int> > ret = allTopoSort(data);

	for(auto i = 0; i < ret.size(); i++){
		for(auto j = 0; j < ret[i].size(); j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}

	fclose(stdin);
}

void CriticalPath(){
	freopen("input", "r", stdin);
	int n, m, s, e, w;
	int S, T;
	cin>>n>>m>>S>>T;
	S--;
	T--;
	vector<vector<Node> > data(n, vector<Node>());
	while(m--){
		cin>>s>>e>>w;
		s--;
		e--;
		data[s].push_back(Node(e, w));
	}

	vector<Edge> ret = criticalPath(data, S, T);

	for(auto i = 0; i < ret.size(); i++){
		cout<<ret[i].s<<" "<<ret[i].e<<" "<<ret[i].w<<endl;
	}

	fclose(stdin);
}

void GetStrongConnectComponent(){
	freopen("input", "r", stdin);
	int n, m, s, e, w;
	cin>>n>>m;
	vector<vector<Node> > data(n, vector<Node>());
	while(m--){
		cin>>s>>e>>w;
		s--;
		e--;
		data[s].push_back(Node(e, w));
	}

	vector<vector<int> > ret = getStrongConnectComponent(data);

	for(auto i = 0; i < ret.size(); i++){
		for(auto j = 0; j < ret[i].size(); j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}

	fclose(stdin);
}

int main(){
	//search();
	//jointPoint();
	//TopoSort();
	//AllTopoSort();
	//CriticalPath();
	GetStrongConnectComponent();
}
