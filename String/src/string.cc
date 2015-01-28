#include "sstring.h"
#include <climits>
#include <cassert>
#include <cstring>

using std::cout;
using std::endl;
using std::min;

namespace Hu{

int atoi(const char *str){
	int sum = 0;  // 存负值.
	bool isMinus = false;
	const char* p = str;
	if(!p)	return 0;
	while(*p == ' ' && *p != '\0') p++; //空格
	if(*p == '\0')	return 0;
	if(*p == '-'){
		isMinus = true;
		p++;
	}else{
		if(*p == '+') p++;
	}
	while(*p != '\0'){
		int cur = *p++ - '0';
		if(!(cur >= 0 && cur <= 9))	break;  //非法字符
		if(isMinus && sum == INT_MIN/10 && cur > INT_MAX%10 + 1){
			return INT_MIN;
		}
		if(isMinus && sum < INT_MIN/10){
			return INT_MIN;
		}
		if(!isMinus && sum == -INT_MAX/10 && cur > INT_MAX%10){
			return INT_MAX;
		}
		if(!isMinus && sum < -INT_MAX/10){
			return INT_MAX;
		}
		sum = sum*10 - cur;
	}
	if(!isMinus)	return -sum;
	return sum;
}

int strlen(const char *str){
	int len = 0;
	while(*str++ != '\0'){
		len++;
	}
	return len;
}

// libc没有考虑地址重叠情况=.=
char *strcpy(char *dest,const char *src){
	int lens = strlen(src);
	int lend = strlen(dest);
	if(src + lens > dest){ // 从后往前拷贝
		for(int i = lens - 1; i >= 0; i--){
			dest[i] = src[i];
		}
	}else{ //从前往后拷贝
		for(int i = 0; i < lens; i++){
			dest[i] = src[i];
		}
	}
}

char *strncpy(char *dest,const char *src, int n){
	int lens = strlen(src);
	int lend = strlen(dest);
	if(src + lens > dest && src + n > dest){ // 从后往前拷贝
		for(int i = min(lens, n) - 1; i >= 0; i--){
			dest[i] = src[i];
		}
	}else{ //从前往后拷贝
		for(int i = 0; i < lens && i < n; i++){
			dest[i] = src[i];
		}
	}
}

// KMP
int strStr(const char *haystack, const char *needle){
	int ln = strlen(needle);
	if(ln == 0)	return 0;
	int com[ln], next[ln];
	com[0] = 0;
	int k;
	for(int i = 1; i < ln; i++){
		k = com[i-1];
		while(1){
			if(needle[k] == needle[i]){
				com[i] = k + 1;
				break;
			}else{
				if(k == 0){
					com[i] = 0;
					break;
				}
				k = com[k - 1];
			}
		}
	}
	for(int i = 0; i < ln - 1; i++)
		next[i+1] = com[i];
	next[0] = -1;
	int lh = strlen(haystack);
	int i = 0, j = 0;
	while(i + ln - j < lh + 1){
		if(j == ln)	return i - ln;
		if(haystack[i] == needle[j]){
			i++;
			j++;
		}else{
			if(next[j] == -1){
				i++;
			}else{
				j = next[j];
			}
		}
	}
	return -1;
}

//勉强可以
char *strcat(char *strDest, const char *strScr){
	if(!strScr)	return strDest;
	char* p = strDest;
	while(*p){
		p++;
	}
	while(*strScr){
		*p++ = *strScr++;
	}
	*p = '\0';
	return strDest;
}

// 勉强可以
int strcmp(const char *str1,const char *str2){
	assert(str1);
	assert(str2);
	while(*str1 && *str2){
		if(*str1 != *str2)	return (*str1) - (*str2);
		str1++;
		str2++;
	}
	if(!(*str1) && !(*str2))	return 0;
	return (*str1) - (*str2);
}

//libc使用了page copy, unsigned long copy做到快速拷贝
void *memcpy(void *dest, const void *src, size_t count){
	if(!src || !dest)	return NULL;
	unsigned char *d = (unsigned char*)dest, *s = (unsigned char*)src;
	while(count-- > 0){
		*d++ = *s++;
	}
	return dest;
}

// string 问题
	
int LongestPalindrome(const char *s, int n){
	if(!s || n == 0)	return 0;
	char* str = (char*)malloc((n+n+2)*sizeof(char));
	str[0] = '#';
	int count = 0;
	for(int i = 0; i < n; i++){
		str[++count] = s[i];
		str[++count] = '#';
	}
	str[count+1] = '\0';
	int id = 0, mx = 1;
	int p[2*n+1];
	memset(p, 0, sizeof(p));
	p[0] = 1;
	for(int i = 1; i < 2*n + 1; i++){
		int j = 2*id - i;
		p[i] = mx > i? min(p[j], mx - i) : 1;
		while(i + p[i] < 2*n + 1 && i - p[i] >= 0){
			if(str[i + p[i]] != str[i - p[i]]) break;
			p[i]++;
		}
		if(i + p[i] > mx){
			mx = i+ p[i];
			id = i;
		}
	}
	int max = INT_MIN;
	for(int i = 0; i < 2*n + 1; i++){
		if(max < p[i])	max = p[i];
	}
	free(str);
	return max - 1;
}


}
