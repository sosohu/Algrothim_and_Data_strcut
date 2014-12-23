#ifndef __AVL__H__
#define __AVL__H__

#include "bst.h"

typedef TreeNode ATreeNode;

class ATree : public  BsTree
{
	public:
		ATree(ATreeNode *root = NULL):BsTree(root){}
		
		void virtual insert(int key);

		void virtual remove(int key);

	protected:
		ATreeNode* left_left_rotate(ATreeNode *rt);

		ATreeNode* left_right_rotate(ATreeNode *rt);

		ATreeNode* right_left_rotate(ATreeNode *rt);

		ATreeNode* right_right_rotate(ATreeNode *rt);

		ATreeNode* insert_aux(ATreeNode* rt, int key);

		ATreeNode* remove_aux(ATreeNode *rt, int key);

};

#endif
