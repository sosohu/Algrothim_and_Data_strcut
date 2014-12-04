#include "link_list.h"

// 通常解法
ListNode* MergeSortedList(ListNode *pHead1, ListNode *pHead2){
	if(!pHead1)	return pHead2;
	if(!pHead2)	return pHead1;
	ListNode *pos1 = pHead1, *pos2 = pHead2;
	ListNode *ret = pHead1->val < pHead2->val? (pos1 = pos1->next, pHead1) 
					: (pos2 = pos2->next, pHead2);
	ListNode *pos = ret;
	while(pos1 && pos2){
		if(pos1->val < pos2->val){
			pos->next = pos1;
			pos1 = pos1->next;
		}else{
			pos->next = pos2;
			pos2 = pos2->next;
		}
		pos = pos->next;
	}
	if(pos1){
		pos->next = pos1;
	}
	if(pos2){
		pos->next = pos2;
	}
	return ret;
}

// 递归解法,  非常的简洁
/*
ListNode* MergeSortedList(ListNode *pHead1, ListNode *pHead2){
	if(!pHead1)	return pHead2;
	if(!pHead2)	return pHead1;
	ListNode *ret, *pos1 = pHead1, *pos2 = pHead2;
	ret = pHead1->val < pHead2->val?  (pos1 = pos1->next, pHead1) : (pos2 = pos2->next, pHead2);
	ret->next = MergeSortedList(pos1, pos2);
	return ret; 
}
*/
