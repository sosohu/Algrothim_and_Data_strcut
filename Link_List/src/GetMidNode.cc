#include "link_list.h"

// 慢指针以每步一个节点的速度前进，快指针以每步两个节点的速度前进
ListNode* getMidNode(ListNode *pHead){
	if(!pHead || !pHead->next)	return pHead;
	ListNode *slow = pHead, *fast = pHead->next;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next;
		fast = fast->next;
	}
	return slow;
}
