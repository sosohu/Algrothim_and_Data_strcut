#ifndef __LINK__LIST__H__
#define __LINK__LIST__H__
#include <iostream>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int val = 0) : val(val), next(NULL){}
};

ListNode *GetFirstCircleNode(ListNode* pHead);

int GetListLength(ListNode *head);

ListNode* getMidNode(ListNode *pHead);

ListNode *ListSort(ListNode *pHead);

ListNode* MergeSortedList(ListNode *pHead1, ListNode *pHead2);

ListNode * RGetKthNode(ListNode * pHead, unsigned int k);

ListNode *ReverseList(ListNode *pHead);

void ReversePrint(ListNode *pHead);

void deleteNode(ListNode *pHead, ListNode *pDelete);

void deleteRKthNode(ListNode *pHead, int k);

ListNode *getFirstMeet(ListNode *pHead1, ListNode *pHead2);

void insertNode(ListNode *pPos, ListNode *pInsert);

bool isCircleList(ListNode *pHead);

bool isMeetList(ListNode *pHead1, ListNode *pHead2);


#endif
