#include "link_list.h"
#include <iostream>
#include <stack>

using std::stack;

// 递归的打印
/*
void ReversePrint(ListNode *pHead){
	if(!pHead)	return;
	ReversePrint(pHead->next);
	std::cout<<pHead->val<<std::endl;
}*/

// 使用栈迭代的打印
void ReversePrint(ListNode *pHead){
	if(!pHead)	return;
	stack<ListNode*>	data;
	ListNode *pos = pHead;
	while(pos){
		data.push(pos);
		pos = pos->next;
	}
	ListNode *cur;
	while(!data.empty()){
		cur = data.top();
		std::cout<<cur->val<<std::endl;
		data.pop();
	}
}
