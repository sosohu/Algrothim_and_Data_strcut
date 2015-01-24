#include "heap.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> data{1,2,3,4,5,6,7,8,9};
	make_heap(data, data.size());
	data.push_back(12);
	push_heap(data, data.size());
	pop_heap(data, data.size());
	sort_heap(data, data.size());
	for(auto ele : data)
		cout<<ele<<endl;
}
