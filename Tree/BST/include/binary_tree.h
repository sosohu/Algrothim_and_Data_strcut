#ifndef __BINARY_TREE__H__
#define __BINARY_TREE__H__
#include <cstdlib>

struct TreeNode{
	int val;
	int height;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val):val(val),height(1),left(NULL),right(NULL){}
};

class BiTree{
protected:
	TreeNode *root;
public:
	BiTree(TreeNode* rt = NULL):root(rt){}

	void PreOrderTraversal(){	return PreOrderTraversal(root);}

	void InOrderTraversal(){	return	InOrderTraversal(root);}

	void PostOrderTraversal(){	return PostOrderTraversal(root);}

	bool isBalanced(TreeNode* r);

	bool isLeaf(TreeNode* node){
		if(node->left || node->right)	return false;
		return true;
	}

	protected:

	void PreOrderTraversal(TreeNode* r);

	void InOrderTraversal(TreeNode* r);

	void PostOrderTraversal(TreeNode* r);

	TreeNode* left_rotate(TreeNode *root);

	TreeNode* right_rotate(TreeNode *root);

	TreeNode* _findPre(TreeNode *rt);

	TreeNode* _findPost(TreeNode *rt);

};

int getHeight(TreeNode *rt);

int genHeight(TreeNode *rt);

#endif
