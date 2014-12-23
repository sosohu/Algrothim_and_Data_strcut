#include "link_list.h"

// 调用以前的RGetKthNode函数返回倒数第k+1节点，然后执行删除
void deleteRKthNode(ListNode *pHead, int k){
	if(!pHead || !k)	return;
	ListNode *pre = RGetKthNode(pHead, k+1);
	ListNode *tmp;
	if(!pre){
		tmp = pHead;
		pHead = pHead->next;
	}else{
		tmp = pre->next;
		pre->next = pre->next->next;
	}
	delete tmp;
}
