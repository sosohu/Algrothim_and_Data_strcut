#include "link_list.h"

// 快慢指针, 慢指针每步一个节点，快指针每步两个节点，如果有环肯定会相遇
bool isCircleList(ListNode *pHead){
	if(!pHead || !pHead->next) return false;
	ListNode *slow = pHead, *fast = pHead;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)	return true;
	}
	return false;
}
