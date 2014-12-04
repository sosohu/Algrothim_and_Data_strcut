#include "b_tree.h"

bool BTree::empty(){
	return root->nums == 0;
}

BTreeNode* BTree::_find(int key, BTreeNode *node){
	if(!node->nums)	return node;
	list<int>::iterator iter_k = node->keys.begin();
	list<BTreeNode*>::iterator iter_c = node->childs.begin();
	while(iter_k != node->keys.end() && key >= *iter_k){
		if(key == *iter_k)	return node;
		iter_k++;
		iter_c++;
	}
	BTreeNode *ret = _find(key, *iter_c);
	return ret;
}

BTreeNode* BTree::find(int key){
	BTreeNode* ret = _find(key, root);
	return ret;
}

// 调整函数
void BTree::adjust(BTreeNode *node){
	BTreeNode *parent = node->parent;
	if(!parent){// node节点是根节点
		int mid = (node->nums)/2;
		list<int>::iterator iter_k = node->keys.begin();
		list<BTreeNode*>::iterator iter_c = node->childs.begin();
		BTreeNode *left = new BTreeNode(), *right = new BTreeNode(); // 拆分后的两个新节点
		for(int i = 0; i < mid; iter_k++, iter_c++, i++){//拆分, 前一半弄成坐便节点
			left->nums++;
			left->keys.push_back(*iter_k);
			left->childs.push_back(*iter_c);
			(*iter_c)->parent = left;
		}
		left->childs.push_back(*iter_c);
		(*iter_c)->parent = left;
		iter_c++;
		BTreeNode *newroot = new BTreeNode();//由于node是根节点，需要重新生成新跟节点
		newroot->keys.push_back(*iter_k);
		newroot->childs.push_back(left);
		newroot->childs.push_back(right);
		newroot->nums = 1;
		left->parent = newroot;
		right->parent = newroot;
		iter_k++;
		for(; iter_k != node->keys.end(); iter_k++, iter_c++){//后一半弄成右边节点
			right->nums++;
			right->keys.push_back(*iter_k);
			right->childs.push_back(*iter_c);
			(*iter_c)->parent = right;
		}
		right->childs.push_back(*iter_c);
		(*iter_c)->parent = right;


		//delete node;
		root = newroot;
		return;
	}else{// node　并非是根节点
		int mid = (node->nums)/2;
		list<int>::iterator iter_k = node->keys.begin();
		list<BTreeNode*>::iterator iter_c = node->childs.begin();
		BTreeNode *left = new BTreeNode(), *right = new BTreeNode();
		for(int i = 0; i < mid; iter_k++, iter_c++, i++){// 拆分
			left->nums++;
			left->keys.push_back(*iter_k);
			left->childs.push_back(*iter_c);
			(*iter_c)->parent = left;
		}
		left->childs.push_back(*iter_c);
		(*iter_c)->parent = left;
		iter_c++;
		list<int>::iterator iter_pk = parent->keys.begin();
		list<BTreeNode*>::iterator iter_pc = parent->childs.begin();
		while(iter_pk != parent->keys.end() && *iter_k > *iter_pk){
			iter_pk++;
			iter_pc++;
		}
		parent->keys.insert(iter_pk, *iter_k);
		*iter_pc = right;
		parent->childs.insert(iter_pc, left);
		parent->nums++;
		left->parent = parent;
		right->parent = parent;
		iter_k++;
		for(; iter_k != node->keys.end(); iter_k++, iter_c++){
			right->nums++;
			right->keys.push_back(*iter_k);
			right->childs.push_back(*iter_c);
			(*iter_c)->parent = right;
		}
		right->childs.push_back(*iter_c);
		(*iter_c)->parent = right;

		if(parent->nums == m)// 继续向上调整
			return adjust(parent);
	}
}

//插入函数
void BTree::insert(int key){
	if(root->nums == 0){ // 树现在为空
		root->keys.push_back(key);
		root->childs.push_back(new BTreeNode(0, root));
		root->childs.push_back(new BTreeNode(0, root));
		root->nums++;
		return;
	}
	BTreeNode *node = find(key);
	if(node->nums == 0){ // key 确实不存在树中
		BTreeNode *parent = node->parent; // parent节点是要插入的节点
		list<int>::iterator iter = parent->keys.begin();
		list<BTreeNode*>::iterator iter_c = parent->childs.begin();
		while(iter != parent->keys.end() && key > *iter){ // 寻找插入位置
			iter++;
			iter_c++;
		}
		parent->keys.insert(iter, key); // 插入进去
		iter_c++;
		parent->childs.insert(iter_c, new BTreeNode(0, parent));
		parent->nums++;
		if(parent->nums == m){ // 插入之后key值爆满，需要调整
			adjust(parent);
		}
	}
}

void BTree::_prePrint(BTreeNode *node){
	if(node->nums == 0)	return;
	std::cout<<"nums : "<<node->nums<<std::endl;
	std::cout<<"keys size: "<<node->keys.size()<<std::endl;
	std::cout<<"childs size: "<<node->childs.size()<<std::endl;
	list<int>::iterator iter = node->keys.begin();
	while(iter != node->keys.end()){
		std::cout<<*iter<<" ";		
		iter++;
	}
	std::cout<<std::endl;
	list<BTreeNode*>::iterator iter_c = node->childs.begin();
	while(iter_c != node->childs.end()){
		_prePrint(*iter_c);
		iter_c++;
	}
}

void BTree::print(){
	std::cout<<"----------PRINT Tree---------"<<std::endl;
	_prePrint(root);
	std::cout<<"-----------------------------"<<std::endl;
}

BTreeNode* BTree::_getBrother(BTreeNode* node, BTreeNode* &parent, list<int>::iterator &iter_k, list<BTreeNode*>::iterator &iter_c){
	int key = node->keys.back();
	parent = node->parent;
	iter_k = parent->keys.begin();
	iter_c = parent->childs.begin();
	while(iter_k != parent->keys.end() && *iter_k < key){
		iter_k++;
		iter_c++;
	}
	if(iter_k != parent->keys.end() || parent == root){
		list<BTreeNode*>::iterator iter = iter_c;
		iter++;
		return *iter;
	}else{
		while(1){
			node = parent;
			parent = node->parent;
			key = node->keys.back();
			iter_k = parent->keys.begin();
			iter_c = parent->childs.begin();
			while(iter_k != parent->keys.end() && *iter_k < key){
				iter_k++;
				iter_c++;
			}
			if(iter_k != parent->keys.end() || parent == root){
				list<BTreeNode*>::iterator iter = iter_c;
				iter++;
				return *iter;
			}
		}
	}
}

void BTree::adjustLess(BTreeNode *node){
	BTreeNode *parent = node->parent;
	if(!parent)	return;
	list<int>::iterator iter_k;
	list<BTreeNode*>::iterator iter_c;
	int key = node->keys.front();
	BTreeNode *left = NULL;
	_getBrother(node, parent, iter_k, iter_c);
	if(iter_k == parent->keys.end()){
		left->keys.push_back(parent->keys.back());
		left->childs.push_back(node->childs.front());
		node->childs.front()->parent = left;
		left->nums++;
		list<int>::iterator iter_sk = node->keys.begin();
		list<BTreeNode*>::iterator iter_sc = node->childs.begin();
		iter_sc++;
		while(iter_sk != node->keys.end()){
			left->keys.push_back(*iter_sk);
			left->childs.push_back(*iter_sc);
			(*iter_sc)->parent = left;
			iter_sk++;
			iter_sc++;
			left->nums++;
		}
		parent->keys.pop_back();
		parent->childs.pop_back();
		parent->nums--;
		if(parent->nums == 0){
			root = left;
			root->parent = NULL;
			return;
		}
		if(parent->nums < up - 1)
			adjustLess(parent);
		return;
	}
	iter_c++;
	BTreeNode *right = *iter_c;
	node->keys.push_back(*iter_k);
	node->childs.push_back(right->childs.front());
	node->nums++;
	right->childs.front()->parent = node;
	*iter_k = right->keys.front();
	right->keys.pop_front();
	right->childs.pop_front();
	right->nums--;
	if(right->nums < up - 1)
		adjustLess(right);
}

void BTree::_removeExternal(int key, BTreeNode *node){
	if(node == root && root->nums == 1){
		node->keys.clear();
		node->childs.clear();
		node->nums = 0;
		return;
	}
	list<int>::iterator iter_k = node->keys.begin();
	list<BTreeNode*>::iterator iter_c = node->childs.begin();
	while(*iter_k != key && iter_k != node->keys.end()){
		iter_k++;
		iter_c++;
	}
	node->keys.erase(iter_k);	//　默认情况2a 
	node->childs.erase(iter_c);
	node->nums--;
	if(node->nums < up){// 转至情况2b,2c
		adjustLess(node);
	}
}

BTreeNode* BTree::_getMax(BTreeNode *node){
	if(node->childs.front()->nums == 0)	return node;
	return _getMax(node->childs.back());
}

void BTree::remove(int key){
	BTreeNode *node = find(key);
	if(!isLeaf(node)){
		list<int>::iterator iter_k = node->keys.begin();
		list<BTreeNode*>::iterator iter_c = node->childs.begin();
		while(*iter_k != key && iter_k != node->keys.end()){
			iter_k++;
			iter_c++;
		}
		if(isLeaf(*iter_c)){
			_removeExternal(key, node); // 情况2
		}else{
			BTreeNode* max;
			if(iter_k == node->keys.begin()){ // 与后继交换
				iter_c++;
				max = _getMax(*iter_c);
				*iter_k = max->keys.front();
				_removeExternal(max->keys.front(), max); // 转为情况2
			}
			else{ // 与前驱交换
				max = _getMax(*iter_c);
				*iter_k = max->keys.back();
				_removeExternal(max->keys.back(), max);
			}
		}
	}
}
