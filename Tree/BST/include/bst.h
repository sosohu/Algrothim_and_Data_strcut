#ifndef __BST__H__
#define __BST__H__

#include "binary_tree.h"
#include <cstdlib>

class BsTree : public BiTree{
	public:
		BsTree(TreeNode* root = NULL):BiTree(root){}

		TreeNode* find(int key);

		void virtual insert(int key);

		void virtual remove(int key);
	protected:

		TreeNode* _find(TreeNode* rt, int key, TreeNode* &p);

		TreeNode* _find(TreeNode* rt, int key){
			TreeNode* tmp = new TreeNode(0);
			return _find(rt, key, tmp);
		}

};

#endif
