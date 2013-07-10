#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

/**
 * Return the number of des in src.
 */
int count(const char *src, const char *des){
	assert(src && des);
	int count_ = 0;

	while (*src != '\0'){
		const char *s0 = src;
		const char *s1 = des;
		while (*s0 == *s1 && *s0 != '\0' && *s1 != '\0'){
			s0++;
			s1++;
		}
		if (*s1 == '\0')
			count_++;
		src++;
	}
	return count_;
}

int Strcmp(const char *l, const char*r){
	assert(l != NULL && r !=NULL);
    while (*l == *r && *l != '\0' && *r != '\0'){
		l++;
		r++;
	}

	if (*l == *r)
		return 0;
	else if (*l < *r)
		return -1;
	else 
		return 1; 
}

char* Strcpy(char *des, const char *src){
	assert(des != NULL && src != NULL);
	char* strD = des;
	while ((*strD++ = *src++) != '\0');
	return des;
}

char* Strcat(char* dest, const char* src){
	assert(dest != NULL && src != NULL);
	char* strD = dest;

	while (*dest){
		dest++;
	}
	while (*dest++ = *src++);
	return strD;
}

char* Itoa(int value, char* s, int radix = 10){
	int sign = 0;
	if ((sign = value) < 0)
		value = -value;
	int i = 0;
	do {
		s[i++] = value%radix + '0';
	} while ((value /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';

	int k = i-1;
	int j = 0;
	char temp;
	while (j < k){
		temp = s[j];
		s[j] = s[k];
		s[k] = temp;
		j++;
		k--;
	}
	s[i] = '\0';
	return s;
}

int main(){
	char s[100] = "aaaaasdfsdfsdaaasd";
	char d[] = "aa";
	//cout<<count(s,d)<<endl;
	//cout<<Strcmp(s,d)<<endl;
	//cout<<Strcpy(s,d)<<endl;
	//cout<<Strcat(s,d)<<endl;
	int a = -12345;
	//sprintf(s,"%d",a);
	//cout<<s<<endl;
	cout<<Itoa(a,s)<<endl;

}
