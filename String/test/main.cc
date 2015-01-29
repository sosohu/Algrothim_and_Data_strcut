#include "sstring.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;
using Hu::strstr;
using Hu::string;
 
void bar(const Hu::string& x){
	cout<<x.toChar()<<endl;
}

void foo(Hu::string& x){
	cout<<x.toChar()<<endl;
}
 
Hu::string baz()
{
  Hu::string ret("world");
  return ret;
}

void testString(){
 
  Hu::string s0;
  Hu::string s1("hello");
  Hu::string s2(s0);
  Hu::string s3 = s1;
  s2 = s1;
 
  foo(s1);
  bar(s1);
  bar("temporary");
  Hu::string s4 = baz();
 
  std::vector<Hu::string> svec;
  svec.push_back(s0);
  svec.push_back(s1);
  svec.push_back(baz());
  svec.push_back("good job");
  for(auto ele : svec)
		cout<<ele.toChar()<<endl;
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
	//testlib();
	testString();
}
