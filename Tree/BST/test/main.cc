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

void AVLTest(){
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

void otherTest(){
	ATree bs;
	for(int i = 0; i < DATASIZE; i++){
		bs.insert(i);
	}
	cout<<"PreOrderTraversal"<<endl;
	bs.PreOrderTraversal();
	cout<<"InOrderTraversal"<<endl;
	bs.InOrderTraversal();
	cout<<"find common Ancestor"<<endl;
	cout<<NearestCommAncestor(&bs, bs.find(5), bs.find(9))->val<<endl;
	cout<<"max path"<<endl;
	cout<<MaxPath(bs.find(3))<<endl;
	cout<<"get path"<<endl;
	vector<TreeNode*> ret;
	GetPath(bs.find(7), bs.find(6), ret);
	int c;
	CountPath(bs.find(3), bs.find(7), bs.find(6), c);
	cout<<c<<endl;
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]->val<<endl;
}

int main(){
	otherTest();
}
