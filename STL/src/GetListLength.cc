#include "link_list.h"
#include <iostream>

int GetListLength(ListNode *head){
	int count = 0;
	ListNode *pos = head;
	while(pos){
		count++;
		pos = pos->next;
	}
	return count;
}
