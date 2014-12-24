#ifndef __BINARY_TREE__H__
#define __BINARY_TREE__H__
#include <cstdlib>
#include <vector>

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

	friend void GetPath(BiTree* bt, TreeNode* node, std::vector<TreeNode*> &path);

	friend TreeNode * NearestCommAncestor(BiTree* bt, TreeNode* node1, TreeNode* node2);

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

//　根节点到指定节点的路径
void GetPath(TreeNode *root, TreeNode* node, std::vector<TreeNode*> &path);

//　根节点到指定节点的距离
void CountPath(TreeNode *root, TreeNode* node, int &reslut);

// distance of node1 and node2
void CountPath(TreeNode *root, TreeNode* node1, TreeNode* node2, int &reslut);

#endif
