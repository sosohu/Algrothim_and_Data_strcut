#include "bst.h"
#include "avl.h"
#include <iostream>
#include <vector>

const int DATASIZE = 10;

using namespace std;

void testBs(){
	BsTree bs;
	bs.insert(5);
	bs.insert(3);
	bs.insert(4);
	bs.insert(6);
	bs.insert(1);
	cout<<"PreOrderTraversal"<<endl;
	bs.PreOrderTraversal();
	cout<<"InOrderTraversal"<<endl;
	bs.InOrderTraversal();
	bs.remove(5);
	cout<<"PreOrderTraversal"<<endl;
	bs.PreOrderTraversal();
	cout<<"InOrderTraversal"<<endl;
	bs.InOrderTraversal();
	cout<<bs.find(3)->val<<endl;
}

int main(){
	ATree bs;
	for(int i = 0; i < DATASIZE; i++){
		cout<<"PreOrderTraversal"<<endl;
		bs.PreOrderTraversal();
		bs.insert(i);
	}
	cout<<"PreOrderTraversal"<<endl;
	bs.PreOrderTraversal();
	cout<<"InOrderTraversal"<<endl;
	bs.InOrderTraversal();
	bs.remove(7);
	cout<<"PreOrderTraversal"<<endl;
	bs.PreOrderTraversal();
	cout<<"InOrderTraversal"<<endl;
	bs.InOrderTraversal();
	//cout<<bs.find(3)->val<<endl;
}
