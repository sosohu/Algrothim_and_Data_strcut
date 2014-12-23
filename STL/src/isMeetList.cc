#include "link_list.h"

// 判断两个链表是否相交，只需要判断两个链表最后一个节点是否为同一个即可
bool isMeetList(ListNode *pHead1, ListNode *pHead2){
	if(!pHead1 || !pHead2)	return false;
	ListNode *pos1 = pHead1, *pos2 = pHead2;
	while(pos1->next){
		pos1 = pos1->next;
	}
	while(pos2->next){
		pos2 = pos2->next;
	}
	return pos1 == pos2;
}
