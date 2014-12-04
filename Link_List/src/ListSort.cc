#include "link_list.h"
#include <vector>

using std::vector;

//仿照SGI STL里面的List容器的sort函数，实现迭代版的归并排序
ListNode *ListSort(ListNode *pHead){
	if(!pHead || !pHead->next)	return pHead;
	vector<ListNode*> counter(64, NULL);
	ListNode *carry;
	ListNode *pos = pHead;
	int fill = 0;
	while(pos){
		carry = new ListNode(pos->val);
		pos = pos->next;
		int i = 0;
		for(i = 0; i < fill && counter[i]; i++){
			carry = MergeSortedList(carry, counter[i]);
			counter[i] = NULL;
		}
		counter[i] = carry;
		if(i == fill) fill++;
	}
	for(int i = 1; i < fill; i++){
		counter[i] = MergeSortedList(counter[i-1], counter[i]);
	}
	return counter[fill-1];
}

// 递归的方式实现归并排序
/*
ListNode *ListSort(ListNode *pHead){
	if(!pHead || !pHead->next)	return pHead;
	ListNode *mid = getMidNode(pHead);
	ListNode *right = pHead, *left = mid->next;
	mid->next = NULL;
	right = ListSort(right);
	left = ListSort(left);
	pHead = MergeSortedList(right, left);
	return pHead;
}
*/
