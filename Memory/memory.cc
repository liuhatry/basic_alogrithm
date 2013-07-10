#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;

//保证src 与 dest不重叠，若重叠，行为未定义，看具体实现
void* Memcpy(void* dest, const void* src, size_t n){
	assert(dest != NULL && src != NULL);
	char* address = (char*)dest;
	const char* s = (char*)src;
	while (n--)
		*address++ = *s++;
	return dest;
}

void* Memccpy(void *dest, void *src, unsigned char c, unsigned int count){
	assert((dest != NULL) && (src != NULL));
	while (count--){
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		if (*(char*)src == (char)c)
			break;
		src = (char*)src + 1;
	}
	return(count ? dest : NULL);
}

void* Memchr(const char *s, int c_in, size_t n){
	assert(s != NULL && n > 0);
	char* pret = NULL; 
	char* ptmp = (char*)s;
	while (n){
		if (*ptmp == c_in){
			pret = ptmp;
			break;
		}
		ptmp++;
		n--;
	}
	return pret;
}

int Memcmp(const void *s, const void *t, size_t num){
	assert(s != NULL && t != NULL);
	int ret = 0;
	const char* p0 = (char*)s;
	const char* p1 = (char*)t;
	while (num--){
		if (*p0 > *p1){
			ret = 1;
			break;
		}
		else if(*p0 < *p1){
			ret = -1;
			break;
		}
		p0++;
		p1++;
	}
	return ret;
}

//dest与src重叠仍能正确赋值
void* Memmove(void* dest, void* src, size_t n){
	assert(dest != NULL && src != NULL);
	char* pd = (char*)dest;
	char* ps = (char*)src;

	if (pd > ps && pd-ps < n){ //从后往前
		while (n--){
			*(pd+n) = *(ps+n);
		}
	} else {//从前往后
		while (n--)
			*pd++ = *ps++;
	}
	return dest;
}

int main(){
	char *s = "Golden Global View";
	char d[20];
	char s1[] = "1234567890";
	//Memcpy(d,s,(strlen(s)+1));
	//Memccpy(d,s,int('d'),(strlen(s)+1));
	//cout<<d<<endl;
	//cout<<(char*)Memchr(s,'d',10)<<endl;
	//Memcpy(s1+1,s1,5);
	Memmove(s1,s1+1,5);
	cout<<s1<<endl;
	return 0;
}

