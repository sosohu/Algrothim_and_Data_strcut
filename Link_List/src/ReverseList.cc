#include "link_list.h"

// new one head node, insert one by one
/*
ListNode *ReverseList(ListNode *pHead){
	if(!pHead || !pHead->next)	return pHead;
	ListNode * newhead = new ListNode();
	ListNode *pos = pHead, *tmp;
	newhead->next = pHead;
	while(pos->next){
		tmp = pos->next;
		pos->next = tmp->next;
		tmp->next = newhead->next;
		newhead->next = tmp;
	}
	return newhead->next;
}*/

/*
// 就地倒转 + 迭代
ListNode *ReverseList(ListNode *pHead){
	if(!pHead || !pHead->next)	return pHead;
	ListNode *pre = pHead, *cur = pHead->next, *next = NULL;
	pHead->next = NULL;
	while(cur){
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
*/

// Smart Mark
// 就地倒转 + 递归 // 非常具有技巧性
ListNode *ReverseList(ListNode *pHead){
	if(!pHead || !pHead->next)	return pHead;
	ListNode *left = ReverseList(pHead->next); // 返回left为left段倒转后的首节点
	pHead->next->next = pHead; // pHead->next 一开始是left段的首节点，倒转后就是末节点
	pHead->next = NULL;
	return left;
}
