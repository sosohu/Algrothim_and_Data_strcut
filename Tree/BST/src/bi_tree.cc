#include "binary_tree.h"
#include <iostream>
#include <stack>

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
