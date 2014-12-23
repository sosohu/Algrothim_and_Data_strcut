#include "link_list.h"
// 找到两个链表第一个相交点，首先遍历两个链表，得到两个链表的长度，比如说l1, l2
// 然后先移动较长的那个链表（比如l1>l2），移动l1-l2步，这样双方剩余的节点数就相等了
// 接着以前往后走，第一次相遇的点就是答案
ListNode *getFirstMeet(ListNode *pHead1, ListNode *pHead2){
	if(!pHead1 || !pHead2)	return NULL;
	ListNode *pos1 = pHead1, *pos2 = pHead2;
	int l1 = 0, l2 = 0;
	while(pos1->next){
		l1++;
		pos1 = pos1->next;
	}
	while(pos2->next){
		l2++;
		pos2 = pos2->next;
	}
	if(pos1 != pos2)	return NULL;
	pos1 = l1 > l2? pHead1 : pHead2;
	pos2 = l1 > l2? pHead2 : pHead1;
	int count = l1 > l2? l1 - l2 : l2 -l1;
	while(count-- > 0){
		pos1 = pos1->next;
	}
	while(pos1 && pos2){
		if(pos1 == pos2)	return pos1;
		pos1 = pos1->next;
		pos2 = pos2->next;
	}
}
