#include "bst.h"
#include <iostream>

TreeNode* BsTree::_find(TreeNode* rt, int key, TreeNode* &p){
	if(!rt)	return NULL;
	if(rt->val == key)	return rt;
	p = rt;
	if(key < rt->val)	return _find(rt->left, key, p);
	else	return _find(rt->right, key, p);
}

TreeNode* BsTree::find(int key){
	return _find(root, key);
}

void BsTree::insert(int key){
	if(!root){
		root = new TreeNode(key);
		return;
	}
	TreeNode *ret = NULL, *p = NULL;
	ret = _find(root, key, p);
	if(!ret){
		if(key < p->val){
			p->left = new TreeNode(key);
		}else{
			p->right = new TreeNode(key);
		}
	}
}

void BsTree::remove(int key){
	TreeNode *p = NULL;
	TreeNode *ret = _find(root, key, p);
	if(ret){
		if(isLeaf(ret)){
			if(ret == root){
				delete ret;
				root = NULL;
			}else{
				if(ret == p->left){
					p->left = NULL;
				}else{
					p->right = NULL;
				}
			}
		}else{
			TreeNode *pnext = NULL;
			if(ret->left){
				pnext = _findPre(ret);
			}else{
				pnext = _findPost(ret);
			}	
			int tmp = pnext->val;
			remove(pnext->val);
			ret->val = tmp;
		}
	}
}
