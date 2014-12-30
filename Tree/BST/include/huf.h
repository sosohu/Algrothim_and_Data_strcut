#ifndef __HUF__H__
#define __HUF__H__
#include <map>

#include "binary_tree.h"

using std::multimap;
using std::make_pair;

class HufTree : public BiTree
{
	public:
		HufTree(int data[], int n) : BiTree(NULL){
			if(n == 0)	return;
			multimap<int, TreeNode*> heap;
			for(int i = 0; i < n; i++)
				heap.insert(make_pair(data[i],new TreeNode(data[i])));
			TreeNode *left = NULL, *right = NULL;
			while(heap.size() > 1){
				left = heap.begin()->second;
				heap.erase(heap.begin());
				right = heap.begin()->second;
				heap.erase(heap.begin());
				TreeNode *node = new TreeNode(left->val + right->val);
				node->left = left;
				node->right = right;
				heap.insert(make_pair(node->val, node));
			}
			root = heap.begin()->second;
		}

		int getWPL(){
			int w = 0;
			_getWPL(root, w, 0);
			return w;
		}

	private:

		void _getWPL(TreeNode *node, int &w, int hight){
			if(!node)	return;
			if(!node->left && !node->right){
				w = w + hight * node->val;
			}
			if(node->left)
				_getWPL(node->left, w, hight + 1);
			if(node->right)
				_getWPL(node->right, w, hight + 1);
		}
};

#endif
