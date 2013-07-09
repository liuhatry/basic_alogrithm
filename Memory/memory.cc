#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;

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

int main(){
	char *s = "Golden Global View";
	char d[20];
	//Memcpy(d,s,(strlen(s)+1));
	Memccpy(d,s,int('d'),(strlen(s)+1));
	cout<<d<<endl;
	return 0;
}

