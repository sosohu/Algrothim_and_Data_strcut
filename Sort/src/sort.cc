#include "sort.h"
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using std::vector;

void insert_sort(int A[], int n){
	if(n <= 1) return;
	int cur;
	for(int i = n - 2; i >= 0; i--){
		cur = A[i];
		int j = i + 1;
		for(; j < n && cur > A[j]; j++)
			A[j-1] = A[j];
		A[j-1] = cur;
	}
}

void swap(int& a, int& b){
	if(a == b) return; //avoid a, b is the same one
	a = a^b;
	b = a^b;
	a = a^b;
}

void bubble_sort(int A[], int n){
	if(n <= 1)	return;
	for(int i = n - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(A[j] > A[j+1])
				swap(A[j], A[j+1]);
		}
	}
}

void select_sort(int A[], int n){
	if(n <= 1)	return;
	for(int i = 0; i < n; i++){
		int minPos = i;
		for(int j = i + 1; j < n; j++){
			if(A[minPos] > A[j]){
				minPos = j;
			}
		}
		swap(A[i], A[minPos]);
	}
}

int min(int a, int b){
	return a < b? a : b;
}

void merge_aux(int A[], int begin, int end){
	if(begin >= end)	return;
	int mid = (begin + end)/2;
	merge_aux(A, begin, mid);
	merge_aux(A, mid+1, end);
	int result[end - begin + 1];
	int i = begin, j = mid+1, k = 0;
	while(i <= mid || j <= end){
		int first = i > mid? INT_MAX : A[i];
		int second = j > end? INT_MAX : A[j];
		if(first < second)	i++;
		else	j++;
		result[k++] = min(first, second);
	}
	for(int i = 0; i < k; i++)
		A[begin + i] = result[i];
}

#ifndef OPT
void merge_sort(int A[], int n){
	merge_aux(A, 0, n-1);
}
#else

void merge_iteration(vector<int> &mix, vector<int> &cur){
	vector<int> sum;
	int i = 0, j = 0;
	while(i < mix.size() || j < cur.size()){
		int left = i == mix.size()? INT_MAX : mix[i];
		int right = j == cur.size()? INT_MAX : cur[j];
		if(left < right) i++;
		else	j++;
		sum.push_back(min(left, right));
	}
	cur.clear();
	mix = sum;
}

//迭代写法
void merge_sort(int A[], int n){
	if(n <= 1)	return;
	vector<vector<int> > bucket(64, vector<int>());
	for(int i = 0; i < n; i++){
		int index = 0;
		vector<int> mix(1, A[i]);
		while(!bucket[index].empty()){
			merge_iteration(mix, bucket[index]);
			index++;
		}
		bucket[index] = mix;
	}
	vector<int> mix;
	for(int i = 0; i < 64; i++){
		if(!bucket[i].empty()){
			merge_iteration(mix, bucket[i]);
		}
	}
	for(int i = 0; i < mix.size(); i++)
		A[i] = mix[i];
}
#endif

int partition(int A[], int begin, int end){
	int index = rand()%(end - begin + 1) + begin;
	int last = begin;
	swap(A[index], A[end]);
	for(int i = begin; i < end; i++){
		if(A[i] < A[end]){
			swap(A[last], A[i]);
			last++;
		}
	}
	swap(A[end], A[last]);
	return last;
}

void quick_aux(int A[], int begin, int end){
	if(begin < end){
		int part = partition(A, begin, end);
		quick_aux(A, begin, part - 1);
		quick_aux(A, part + 1, end);
	}
}

void quick_sort(int A[], int n){
	quick_aux(A, 0, n-1);
}

int max(int a, int b){
	return a > b? a : b;
}

void adjust_heap(int A[], int n, int root){
	while(1){
		int left = root*2 + 1 > n - 1? INT_MIN : A[root*2 + 1];
		int right = root*2 + 2 > n - 1? INT_MIN : A[root*2 + 2];
		if(A[root] < max(left, right)){
			if(left < right){
				swap(A[root], A[root*2+2]);
				root = root*2 + 2;
			}else{
				swap(A[root], A[root*2+1]);
				root = root*2 + 1;
			}
		}else
			break;
	}
}

//build max heap
void make_heap(int A[], int n){
	for(int i = n/2 - 1; i >= 0; i--){
		adjust_heap(A, n, i);
	}
}

void pop_heap(int A[], int n){
	if( n <= 1)	return;
	swap(A[0], A[n-1]);
	adjust_heap(A, n-1, 0);
}

void heap_sort(int A[], int n){
	make_heap(A, n);
	for(int i = n; i > 0; i--)
		pop_heap(A, i);
}

//assume ele in A is [0, up), up is not a very large num
void count_sort(int A[], int n, int up){
	int count[up];
	memset(count, 0, sizeof(count));
	for(int i = 0; i < n; i++)
		count[A[i]]++;
	int pos = 0;
	for(int i = 0; i < up; i++){
		for(int j = 0; j < count[i]; j++){
			A[pos++] = i;
		}
	}
}

struct bucket_node{
	int val;
	bucket_node* next;
};

int march_bucket(int val, int pos){
	return (val / ((int)pow(10,pos))) % 10;
}

void bucket_aux(bucket_node start[], bucket_node end[], int n, int pos){
	bucket_node new_start[10], new_end[10];
	for(int i = 0; i < 10; i++){
		new_start[i].next = 0;
		new_end[i].next = &new_start[i];
	}
	for(int i = 0; i < n; i++){
		bucket_node *head = &start[i], *cur;
		while(head->next){
			cur = head->next;
			head->next = cur->next;
			int id = march_bucket(cur->val, pos);
			(new_end[id].next)->next = cur;
			cur->next = 0;
			new_end[id].next = cur;
		}
	}
	for(int i = 0; i < 10; i++){
		start[i] = new_start[i];
		end[i] = new_end[i];
	}
}

void bucket_pre(int A[], bucket_node node[], int n, int w){
	bucket_node start[10], end[10];
	start[0].next = &node[0];
	end[0].next = &node[n-1];
	for(int i = 1; i < 10; i++){
		start[i].next = 0;
		end[i].next = &start[i];
	}
	for(int i = 0; i < w; i++)
		bucket_aux(start, end, 10, i);
	int pos = 0;
	for(int i = 0; i < 10; i++){
		bucket_node* cur = &start[i];
		while(cur->next){
			cur = cur->next;
			A[pos++] = cur->val;
		}
	}
}

void bucket_sort(int A[], int n, int w){
	if(n <= 1)	return;
	bucket_node node[n];
	bucket_node* pre = &node[0]; ;
	pre->val = A[0];
	for(int i = 1; i < n; i++){
		node[i].val = A[i];
		pre->next = &node[i];
		pre= pre->next;
	}
	pre->next = 0;
	bucket_pre(A, node, n, w);
}





