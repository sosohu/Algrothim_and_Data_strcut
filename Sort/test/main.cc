#include "sort.h"
#include <iostream>

using namespace std;

int main(){
	int A[] = {3,2,3,2,6,1,44,11,33,22,2,3,12131,23};
	int n = sizeof(A) / sizeof(int);
	//insert_sort(A, n);
	//bubble_sort(A, n);
	//select_sort(A, n);
	//merge_sort(A, n);
	//quick_sort(A, n);
	//heap_sort(A, n);
	//count_sort(A, n, 100);
	bucket_sort(A, n);
	for(auto i = 0; i < n; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
