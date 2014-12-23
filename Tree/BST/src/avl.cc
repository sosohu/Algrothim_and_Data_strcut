#include "avl.h"
#include <cassert>
#include <iostream>

// left's left > right
ATreeNode* ATree::left_left_rotate(ATreeNode *rt){
	assert(rt && rt->left);
	return right_rotate(rt);
}

ATreeNode* ATree::left_right_rotate(ATreeNode *rt){
	assert(rt && rt->left && rt->left->right);
	rt->left = left_rotate(rt->left);
	return right_rotate(rt);
}

ATreeNode* ATree::right_left_rotate(ATreeNode *rt){
	assert(rt && rt->right && rt->right->left);
	rt->right = right_rotate(rt->right);
	return left_rotate(rt);
}

ATreeNode* ATree::right_right_rotate(ATreeNode *rt){
	assert(root->right);
	return left_rotate(rt);
}


void ATree::insert(int key){
	if(!root){
		root = new ATreeNode(key);
		return;
	}
	insert_aux(root, key);
}

ATreeNode* ATree::insert_aux(ATreeNode* rt, int key){
	std::cout<<"insert "<<key<<std::endl;
	if(rt == NULL){
		return (new ATreeNode(key));
	}
	if(rt->val == key)	return rt;
	bool is_root = (rt == root);
	if(rt->val > key){
		rt->left = insert_aux(rt->left, key);
		if(getHeight(rt->left) - getHeight(rt->right) > 1){
			if(getHeight(rt->left->left) > getHeight(rt->left->right)){
			//LL
				rt = left_left_rotate(rt);
			}else{
			//LR
				rt = left_right_rotate(rt);
			}
		}
	}else{
		rt->right = insert_aux(rt->right, key);
		if(getHeight(rt->right) - getHeight(rt->left) > 1){
			if(getHeight(rt->right->right) > getHeight(rt->right->left)){
			//RR
				rt = right_right_rotate(rt);
			}else{
			//RL
				rt = right_left_rotate(rt);
			}
		}
	}
	rt->height = getHeight(rt->left) > getHeight(rt->right)? 
					getHeight(rt->left) + 1 : getHeight(rt->right) + 1;
	std::cout<<rt->val<<" "<<rt->height<<std::endl;
	if(is_root)	root = rt;
	return rt;
}

void ATree::remove(int key){
	if(!root)	return;
	remove_aux(root, key);
}

ATreeNode* ATree::remove_aux(ATreeNode *rt, int key){
	if(!rt)	return NULL;
	bool is_root = (rt == root);
	if(rt->val == key){
		if(!rt->left || !rt->right){
			delete rt;
			return rt->left? rt->left : rt->right;
		}else{
			rt->val = _findPost(rt)->val;
			rt->right = remove_aux(rt->right, rt->val);
			if(getHeight(rt->left) - getHeight(rt->right) > 1){
				if(getHeight(rt->left->left) > getHeight(rt->left->right)){
				//LL
					rt = left_left_rotate(rt);
				}else{
				//LR
				rt = left_right_rotate(rt);
				}
			}
			rt->height = genHeight(rt);
			if(is_root)	root = rt;
			return rt;
		}
	}
	if(rt->val > key){
		rt->left = remove_aux(rt->left, key);
		if(getHeight(rt->right) - getHeight(rt->left) > 1){
			if(getHeight(rt->right->right) > getHeight(rt->right->left)){
			//RR
				rt = right_right_rotate(rt);
			}else{
			//RL
				rt = right_left_rotate(rt);
			}
		}
	}else{
		rt->right = remove_aux(rt->right, key);
		if(getHeight(rt->left) - getHeight(rt->right) > 1){
			if(getHeight(rt->left->left) > getHeight(rt->left->right)){
			//LL
				rt = left_left_rotate(rt);
			}else{
			//LR
				rt = left_right_rotate(rt);
			}
		}
	}
	rt->height = genHeight(rt);
	if(is_root)	root = rt;
	return rt;
}
