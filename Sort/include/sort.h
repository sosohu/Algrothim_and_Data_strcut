#ifndef __SORT__H__
#define __SORT__H__

//stable sort
void insert_sort(int A[], int n); // O(n^2)
void bubble_sort(int A[], int n); // O(n^2)
void merge_sort(int A[], int n); // O(nlgn)

//unstable sort
void heap_sort(int A[], int n); // O(nlgn)
void quick_sort(int A[], int n); // O(nlgn)
void select_sort(int A[], int n); // O(n^2)

//O(n) sort
void count_sort(int A[], int n, int up);
void bucket_sort(int A[], int n, int w = 10);

//aux function
void swap(int& a, int& b);
int min(int a, int b);
int max(int a, int b);

#endif
