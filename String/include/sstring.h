#ifndef STRING_H
#define STRING_H

#include <algorithm>
#include <iostream>

namespace Hu{

// 基本C库函数
int atoi(const char *str);

int strlen(const char *str);

char *strcpy(char *dest, const char *src); 

char *strncpy(char *dest, const char *src, int n); 

int strstr(const char *haystack, const char *needle);

char *strcat(char *strDest, const char *strScr);

int strcmp(const char *str1,const char *str2);

void *memcpy(void *dest, const void *src, size_t count);

// 仿照C++, string的实现
class string{
public:
	string(const char* str){
		cap = strlen(str) == 0? 1 : 2*strlen(str);
		data = (char*)malloc(cap*sizeof(char));
		strcpy(data, str);
		size = strlen(data);
	}

	string(const char* str, int len){
		cap = len == 0? 1 : 2*len;
		data = (char*)malloc(cap*sizeof(char));
		strncpy(data, str, len);
		size = strlen(data);
	}

	string(){
		cap = 1;
		data = (char*)malloc(cap*sizeof(char));
		data[0] = '\0';
		size = 0;
	}
	
	string(const string &rth){
		size = rth.length();
		cap = rth.capcity();
		data = (char*)malloc(cap*sizeof(char));
		strcpy(data, rth.toChar());
	}

	string& operator=(const string &rth){
		if(*this == rth)	return *this;
		size = rth.length();
		cap = rth.capcity();
		data = (char*)realloc(data, cap*sizeof(char));
		strcpy(data, rth.toChar());
		return *this;
	}

	bool operator==(const string &rth){
		return data == rth.toChar();
	}

	int compare(const string &rth){
		return strcmp(data, rth.toChar());
	}

	int compare(const char* str){
		return strcmp(data, str);
	}

	~string(){
		free(data);
	}

	string& operator+(const string &rth){
		char* last = data + size;
		size = size + rth.length();
		if(!cap)	cap = 1;
		while(cap < size)	cap = 2*cap;
		data = (char*)realloc(data, cap*sizeof(char));
		strcpy(last, rth.toChar());
		return *this;
	}

	string subString(int pos, int len){
		if(pos < 0 || pos >= size)	return "";
		if(!len || pos+len > size)	return "";
		return string(&data[pos], len);
	}

	void swap(string& rth){
		std::swap(data, rth.getChar());
	}

	int length() const{	return size; }

	int capcity() const{ return cap; }

	const char*	toChar() const{	return data;}

	char*& getChar(){	return data;}
private:
	char* data;
	int size;
	int cap;
};

// string 问题
	int LongestPalindrome(const char *s, int n);
}


#endif
