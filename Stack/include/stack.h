#ifndef __STACK__H__
#define __STACK__H__

#include <vector>
#include <iostream>
#include <stdexcept>

using std::vector;

template<typename T>
class Stack{
public:
	Stack();
	~Stack();

	void push(const T& value);
	void pop();
	T	top() const;

	inline bool empty() const;

private:
	vector<T> data;
};

template<typename T>
Stack<T>::Stack(){}

template<typename T>
Stack<T>::~Stack(){}


template<typename T>
void Stack<T>::push(const T& value){
	data.push_back(value);
}

template<typename T>
void Stack<T>::pop(){
	try{
		if(empty())	throw std::runtime_error("error: try to pop an empty stack");
		data.pop_back();
	}catch(const std::runtime_error &err){
		std::cout<<err.what()<<std::endl;
		terminate();
	}
}

template<typename T>
T	Stack<T>::top() const{
	try{
		if(empty())	throw std::runtime_error("error: try to top an empty stack");
		return data.back();
	}catch(const std::runtime_error &err){
		std::cout<<err.what()<<std::endl;
		terminate();
	}
}

template<typename T>
bool Stack<T>::empty() const{
	return data.empty();
}

#endif
