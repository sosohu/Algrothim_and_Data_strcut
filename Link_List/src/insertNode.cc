#include "link_list.h"

// 题目要求在指定节点pPos前插入，我们可以先插入到后面，然后交换他们的值即可
void insertNode(ListNode *pPos, ListNode *pInsert){
	if(!pPos || !pInsert)	return;
	pInsert->next = pPos->next;
	pPos->next = pInsert;
	int tmp = pPos->val;
	pPos->val = pInsert->val;
	pInsert->val = tmp;
}
