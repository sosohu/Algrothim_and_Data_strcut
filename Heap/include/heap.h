#ifndef HEAP_H_
#define HEAP_H_

#include <vector>

using std::vector;

class Com{
public:
	bool operator()(const int &a, const int &b){
		return a < b;
	}
};

void make_heap(vector<int> &data, int len);

void push_heap(vector<int> &data, int len);

void pop_heap(vector<int> &data, int len);

void sort_heap(vector<int> &data, int len);

#endif
