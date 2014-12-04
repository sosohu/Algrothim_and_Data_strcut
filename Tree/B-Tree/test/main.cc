#include "b_tree.h"
#include <iostream>
#include <vector>

const int DATA_SIZE = 10;

using namespace std;

int main(){
	BTree b(3);
	for(int i = 0; i < DATA_SIZE; i++){
		b.insert(i + 1);
		cout<<"insert "<<i+1<<endl;
		b.print();
	}
	for(int i = 0; i < DATA_SIZE - 1; i++){
		cout<<"remove "<<i+1<<endl;
		b.remove(i + 1);
		b.print();
	}
}
