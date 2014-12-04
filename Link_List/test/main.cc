#include "link_list.h"
#include <iostream>
#include <vector>
#include <tr1/memory>

const int DATA_SIZE = 13;

using namespace std;
using std::tr1::shared_ptr;

int main(){
	vector<ListNode* > data(DATA_SIZE, NULL);
	data[0] = new ListNode(0);
	for(int i = 1; i < DATA_SIZE; i++){
		data[i] = new ListNode(i);
		data[i-1]->next = data[i];
	}
	data[DATA_SIZE-1]->next = data[5];
	cout<<isCircleList(data[0])<<endl;
	cout<<GetFirstCircleNode(data[0])->val<<endl;
	data[DATA_SIZE-1]->next = NULL;
	ListNode* nl = new ListNode();
	nl->next = data[5];
	cout<<isMeetList(data[0], nl)<<endl;
	cout<<getFirstMeet(data[0], nl)->val<<endl;
	cout<<"Before"<<endl;
	ListNode *ret;
	ret = ReverseList(data[0]);
	ReversePrint(ret);
	ret = ListSort(ret);
	cout<<"After"<<endl;
	ret = ReverseList(ret);
	deleteNode(ret, RGetKthNode(ret, 11));
	insertNode(data[11], RGetKthNode(ret, 12));
	ReversePrint(ret);
	cout<<"RGetKthNode: "<<RGetKthNode(ret, 3)->val<<endl;
	cout<<"getMidNode: "<<getMidNode(ret)->val<<endl;
	for(int i = 0; i < DATA_SIZE; i++)
		delete data[i];
}
