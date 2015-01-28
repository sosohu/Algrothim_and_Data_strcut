#include "sstring.h"
#include <iostream>
#include <vector>

using namespace std;
using Hu::strStr;
using Hu::string;

int main(){
	char *hay = "BBCABCDABABCDABCDABDE";
	char *needle = "ABCDABD";
	cout<<strStr(hay, needle)<<endl;
	Hu::string str1("haha");
	Hu::string str2(str1);
	str1 = str1 + str2;
	str1.swap(str2);
	cout<<str1.toChar()<<endl;
	cout<<str2.toChar()<<endl;
	cout<<str2.compare("haha")<<endl;
	cout<<Hu::LongestPalindrome("aabbbaaa", 8)<<endl;
}
