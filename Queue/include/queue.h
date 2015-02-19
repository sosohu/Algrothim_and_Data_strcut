#ifndef __QUEUE__H__
#define __QUEUE__H__

#include <list>
#include <iostream>
#include <stdexcept>

using std::list;

template<typename T>
class Queue{
public:
	Queue(){}
	~Queue(){}
	
	T front() const;
	T back() const;
	void push(const T& value);
	void pop();
	bool empty() const;
private:
	list<T> data;
};

template<typename T>
T	Queue<T>::front() const{
	try{
		if(empty())	throw std::runtime_error("error: try to front an empty queue");
		return data.front();
	}catch(const std::runtime_error &err){
		std::cout<<err.what()<<std::endl;
		terminate();
	}
}

template<typename T>
T	Queue<T>::back() const{
	try{
		if(empty())	throw std::runtime_error("error: try to front an empty queue");
		return data.back();
	}catch(const std::runtime_error &err){
		std::cout<<err.what()<<std::endl;
		terminate();
	}
}

template<typename T>
void Queue<T>::push(const T& value){
	data.push_back(value);
}

template<typename T>
void Queue<T>::pop(){
	try{
		if(empty())	throw std::runtime_error("error: try to pop an empty queue");
		data.pop_front();
	}catch(const std::runtime_error &err){
		std::cout<<err.what()<<std::endl;
		terminate();
	}
}

template<typename T>
bool Queue<T>::empty() const{
	return data.empty();
}

#endif
