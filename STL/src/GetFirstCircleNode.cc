#include "link_list.h"

// 假设已知链表有环, 找到环的入点
ListNode *GetFirstCircleNode(ListNode* pHead){
	if(!pHead || !pHead->next)	return pHead;
	ListNode *slow = pHead, *fast = pHead;
	// fast指针先进入环内
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			break;
	}
	if(!fast || !fast->next)	return NULL; // 不存在环
	// slow指针再次从头开始, fast指针减速
	slow = pHead;
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow; // 相遇点就是环的入口
}

// 这里面还有两种方法,一个是fast指针进入环后，把环断开，这样就变成了两个环相交的问题
// 另一个是使用hash table记录走过的环
