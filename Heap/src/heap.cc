#include "heap.h"
#include <iostream>
#include <algorithm>

using std::swap;


//默认最大堆
void make_heap(vector<int> &heap, int len){
	Com comp;
	if(len <= 1)	return;
	int mid = len / 2 - 1;
	while(mid >= 0){
		int cur = mid--;
		while(cur < len){
			int index = 2*cur + 1;
			if(index < len){
				if(index + 1 < len){
					if(comp(heap[index], heap[index+1])){
						index = index + 1;
					}
				}
				if(comp(heap[cur], heap[index])){
					swap(heap[cur], heap[index]);
				}else{
					break;
				}
			}
			cur = index;
		}
	}
}


void push_heap(vector<int> &data, int len){
	Com comp;
	if(len <= 1)	return;
	int cur = len - 1;
	while(cur > 0){
		int parent = (cur - 1) / 2;
		if(comp(data[parent], data[cur])){
			swap(data[parent], data[cur]);
			cur = parent;
		}else{
			return;
		}
	}
}

void pop_heap(vector<int> &data, int len){
	Com comp;
	if(len <= 1)	return;
	swap(data[0], data[len - 1]);
	int cur = 0;
	while(cur < len / 2){
		int index = 2*cur + 1;
		if(index < len){
			if(index + 1 < len){
				if(comp(data[index], data[index+1])){
					index = index + 1;
				}
			}
			if(index == len - 1)	return;
			swap(data[cur], data[index]);
		}
		cur = index;
	}
}

void sort_heap(vector<int> &data, int len){
	for(auto i = len - 1; i > 0; i--){
		pop_heap(data, i);
	}
}
