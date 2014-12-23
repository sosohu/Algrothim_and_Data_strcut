#include "link_list.h"

ListNode * RGetKthNode(ListNode *pHead, unsigned int k){
	if(k < 1)	return NULL;
	ListNode *pre = pHead;
	ListNode *last = pHead;
	while(k-- > 0 && last){
		last = last->next;
	}
	if(!last) return NULL;
	while(last){
		last = last->next;
		pre = pre->next;
	}
	return pre;	
}
