#include "link_list.h"
// Smart Mark
// delete Node, with O(1), 平均时间复杂度
void deleteNode(ListNode *pHead, ListNode *pDelete){
	if(!pHead || !pDelete)	return;
	if(pDelete->next){
		// 不是最后一个节点，只需要复制下一个节点的值过来然后删除下一个节点, O(1)
		ListNode *tmp = pDelete->next;
		pDelete->val = pDelete->next->val;
		pDelete->next = pDelete->next->next;
		delete tmp;	 // 很容易忘记
	}else{
		// 是最后一个节点，只能从前遍历到倒数第二个节点，O(n)
		if(pHead == pDelete){ // 只有一个节点是个特殊情况
			delete pHead;
			pHead = NULL;
		}
		ListNode *pos = pHead;
		while(pos->next != pDelete){
			pos = pos->next;
		}
		pos->next = NULL;
		delete pDelete;   // 这一句很容易忘记
	}
}
