#include "sstring.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
using Hu::strstr;
using Hu::string;

void testString(){
	Hu::string str1("haha");
	Hu::string str2(str1);
	str1 = str1 + str2;
	str1.swap(str2);
	cout<<str1.toChar()<<endl;
	cout<<str2.toChar()<<endl;
	cout<<str2.compare("haha")<<endl;
}

void testlib(){
	char *hay = "BBCABCDABABCDABCDABDE";
	char *needle = "ABCDABD";
	cout<<"strlen: "<<Hu::strlen(hay)<<endl;
	cout<<"strstr: "<<Hu::strstr(hay, needle)<<endl;
	char s1[] = "BBCABCDABABCDABCDABDE";
	char s2[] = "ABCDABD";
	cout<<"strcmp: "<<Hu::strcmp(s1, s2)<<endl;
	char *h1 = (char*)malloc(100*sizeof(char));
	char *h2 = (char*)malloc(100*sizeof(char));
	cout<<"strcpy: "<<Hu::strcpy(h1, s1)<<endl;
	cout<<"strcpy: "<<Hu::strcpy(h2, s2)<<endl;
	cout<<"strcat: "<<Hu::strcat(h1, "AAAAA222")<<endl;
	cout<<"strcat: "<<Hu::strcat(h2, "BBBBB")<<endl;
	cout<<"memcpy: "<<(char*)(Hu::memcpy(h1, h2, Hu::strlen(h2)))<<endl;
	free(h1);
	free(h2);
}

void testAlg(){
	cout<<Hu::LongestPalindrome("aabbbaaa", 8)<<endl;
}

int main(){
	testlib();
}
