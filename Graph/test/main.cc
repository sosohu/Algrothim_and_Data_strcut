#include "graph.h"
#include <vector>
#include <climits>

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

int main(){
	search();
}
