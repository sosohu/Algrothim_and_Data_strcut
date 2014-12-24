#include "binary_tree.h"
#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::stack;

// 递归
/*
void BiTree::PreOrderTraversal(TreeNode* root){
	if(!root)	return;
	cout<<root->val<<endl;
	if(root->left)
		PreOrderTraversal(root->left);
	if(root->right)
		PreOrderTraversal(root->right);
}

void BiTree::InOrderTraversal(TreeNode* root){
	if(!root)	return;
	if(root->left)
		InOrderTraversal(root->left);
	cout<<root->val<<endl;
	if(root->right)
		InOrderTraversal(root->right);
}

void BiTree::PostOrderTraversal(TreeNode* root){
	if(!root)	return;
	if(root->left)
		PostOrderTraversal(root->left);
	if(root->right)
		PostOrderTraversal(root->right);
	cout<<root->val<<endl;
}
*/

//	迭代
void BiTree::PreOrderTraversal(TreeNode* root){
	if(!root)	return;
	stack<TreeNode*> s;
	TreeNode *cur;
	s.push(root);
	while(!s.empty()){
		cur = s.top();
		s.pop();
		cout<<cur->val<<endl;
		if(cur->right)
			s.push(cur->right);
		if(cur->left)
			s.push(cur->left);
	}
}

void BiTree::InOrderTraversal(TreeNode* root){
	if(!root)	return;
	stack<TreeNode*> s;
	TreeNode *pos = root;
	s.push(pos);
	while(pos->left){
		pos = pos->left;
		s.push(pos);
	}
	while(!s.empty()){
		pos = s.top();
		s.pop();
		cout<<pos->val<<endl;
		if(pos->right){
			pos = pos->right;
			s.push(pos);
			while(pos->left){
				pos = pos->left;
				s.push(pos);
			}
		}
	}
}

void BiTree::PostOrderTraversal(TreeNode* root){
	if(!root)	return;
	stack<TreeNode*> s;
	TreeNode *pos = root, *last = root;
	s.push(root);
	while(!s.empty()){
		pos = s.top();
		if(pos->left == last || pos->right == last || (!pos->left && !pos->right)){
		//孩子已经打印完毕或者根本就没有孩子
			cout<<pos->val<<endl;
			last = pos;
			s.pop();
		}else{
			if(pos->right){
				s.push(pos->right);
			}
			if(pos->left){
				s.push(pos->right);
			}
		}
	}
}

TreeNode* BiTree::left_rotate(TreeNode *root){
	if(!root || !root->right){
		cout<<"root is NULL or root->right is NULL"<<endl;
		return root;
	}
	TreeNode *newroot = root->right;
	root->right = newroot->left;
	newroot->left = root;
	newroot->left->height = genHeight(newroot->left);
	newroot->height = genHeight(newroot);
	return newroot;
}

TreeNode* BiTree::right_rotate(TreeNode *root){
	if(!root || !root->left){
		cout<<"root is NULL or root->left is NULL"<<endl;
		return root;
	}
	TreeNode *newroot = root->left;
	root->left = newroot->right;
	newroot->right = root;
	newroot->right->height = genHeight(newroot->right);
	newroot->height = genHeight(newroot);
	return newroot;
}

bool BiTree::isBalanced(TreeNode* root){
	if(!root)	return true;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	if(abs(left - right) > 1) return false;
	if(!isBalanced(root->left) || !isBalanced(root->right))	return false;
	return true;
}

TreeNode* BiTree::_findPre(TreeNode* root){
	if(!root || !root->left){
		cout<<"root or root->left is NULL"<<endl;
		return NULL;
	}
	TreeNode *pos = root->left;
	while(pos->right){
		pos = pos->right;
	}
	return pos;
}

TreeNode* BiTree::_findPost(TreeNode* root){
	if(!root || !root->right){
		cout<<"root or root->right is NULL"<<endl;
		return NULL;
	}
	TreeNode *pos = root->right;
	while(pos->left){
		pos = pos->left;
	}
	return pos;
}

int getHeight(TreeNode *rt){
	return rt? rt->height : 0;
}

int genHeight(TreeNode *rt){
	if(!rt)	return 0;
	return getHeight(rt->left) > getHeight(rt->right)? 
			getHeight(rt->left) + 1 : getHeight(rt->right) + 1;
}

void _GetPath(TreeNode *root, TreeNode* node, std::vector<TreeNode*> &path, std::vector<TreeNode*> &tmp){
	if(!root || !node || !path.empty())	return;
	tmp.push_back(root);
	if(root == node){
		path.swap(tmp);
		return;
	}
	if(root->left)
		_GetPath(root->left, node, path, tmp);
	if(root->right)
		_GetPath(root->right, node, path, tmp);
	tmp.pop_back();
}

void GetPath(BiTree *bt, TreeNode* node, std::vector<TreeNode*> &path){
	std::vector<TreeNode*> tmp;
	_GetPath(bt->root, node, path, tmp);
}

void GetPath(TreeNode *root, TreeNode* node, std::vector<TreeNode*> &path){
	std::vector<TreeNode*> tmp;
	_GetPath(root, node, path, tmp);
}

void CountPath(TreeNode *root, TreeNode* node, int &result, int &tmp){
	if(!root || !node || result)	return;
	tmp++;
	if(root == node){
		result = tmp;
		return;
	}
	if(root->left)
		CountPath(root->left, node, result, tmp);
	if(root->right)
		CountPath(root->right, node, result, tmp);
	tmp--;
}

void CountPath(TreeNode *root, TreeNode* node, int &result){
	int tmp = -1;
	result = 0;
	CountPath(root, node, result, tmp);
}

int _CountPath(TreeNode *root, TreeNode* node1, TreeNode* node2, int& result){
	if(!root || !node1 || !node2 )	return -1;
	if(result)	return result;
	if(root == node1){
		CountPath(node1, node2, result);
		return result;
	}
	if(root == node2){
		CountPath(node2, node1, result);
		return result;
	}
	int left = _CountPath(root->left, node1, node2, result);
	int right = _CountPath(root->right, node1, node2, result);
	if(left != -1 && right != -1){
		result = left + right;
		return result;
	}
	return left == -1? right : left;
}

void CountPath(TreeNode *root, TreeNode* node1, TreeNode* node2, int &reslut){
	reslut = 0;
	_CountPath(root, node1, node2, reslut);
}

int _MaxPath(TreeNode *root, int &in){
	if(!root)	return 0;
	int l = 0, r = 0, left = 0 , right = 0;
	left = _MaxPath(root->left, l);
	right = _MaxPath(root->right, r);
	int ret = l + r + 1;
	ret = ret < left ? left : ret;
	ret = ret < right ? right : ret;
	in = l < r ? r + 1 : l + 1;
	return ret;
}

int MaxPath(TreeNode *root){
	int in = 0;
	return _MaxPath(root, in);
}

TreeNode * _NearestCommAncestor(TreeNode *root, TreeNode *node1, TreeNode *node2){
	if(!root || !node1 || !node2)	return NULL;
	if(node1 == root || node2 == root)
		return root;
	if(!root->left)
		return _NearestCommAncestor(root->right, node1, node2);
	if(!root->right)
		return _NearestCommAncestor(root->left, node1, node2);
	TreeNode *left, *right;
	left = _NearestCommAncestor(root->left, node1, node2);
	right = _NearestCommAncestor(root->right, node1, node2);
	if(left && right)	return root;
	return left? left : right;
}

TreeNode * NearestCommAncestor(BiTree* bt, TreeNode* node1, TreeNode* node2){
	return _NearestCommAncestor(bt->root, node1, node2);
}

