#ifndef __B_TREE__H__
#define __B_TREE__H__
#include <list>
#include <iostream>

using std::list;

struct BTreeNode{
	int nums;
	BTreeNode *parent;
	list<int> keys;
	list<BTreeNode*> childs;
	BTreeNode(int nums = 0, BTreeNode *parent = NULL):nums(nums), parent(parent){ }
	~BTreeNode(){
	}
};

class BTree{
	public:
		BTree(int m = 3) : root(new BTreeNode()), m(m), up((m+1)/2) {}

		~BTree(){}

		// judge wheather the tree is empty
		bool empty();

		// find the key and return the node which contains the key
		BTreeNode* find(int key);

		// insert the key when the key is not in the tree 
		void insert(int key);

		// remove the key when the key is in the tree
		void remove(int key);

		// print preorder
		void print();

	protected:
		// inter find detail func
		BTreeNode* _find(int key, BTreeNode *root);

		// root has m keys , you should split it into two nodes
		void adjust(BTreeNode *root);

		void adjustLess(BTreeNode *node);

		// pre print
		void _prePrint(BTreeNode *root);

		// wheather is a leaf
		bool isLeaf(BTreeNode *node){	return node->nums == 0; }	

		void _removeExternal(int key, BTreeNode *node);

		BTreeNode* _getMax(BTreeNode *node);

	private:
		// tree root node
		BTreeNode *root;
		// declare it is the m B-tree , m > 2
		const int m;
	
		const int up;
};

#endif
