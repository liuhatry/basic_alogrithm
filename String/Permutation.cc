#include <iostream>
#include <assert.h>
using namespace std;

void swap(char *p0, char *p1){
	char temp = *p0;
	*p0 = *p1;
	*p1 = temp;
}

bool isSwap(char *pBegin, char *pEnd){
	for (char *p = pBegin; p < pEnd; p++){
		if (*p == *pEnd)
			return false;
	}
	return true;
}
void permutation(char *pStr, char *pBegin){
	assert(pStr && pBegin);
	if (*pBegin == '\0')
		cout<<pStr<<endl;
	else {
		for (char *pCh = pBegin; *pCh != '\0'; pCh++){
			if (isSwap(pBegin,pCh)){
				swap(pCh,pBegin);
				permutation(pStr,pBegin+1);
				swap(pCh,pBegin);
			}
		}
	}
}
int main(){
	char arr[4] = {'a','a','c','\0'};
	permutation(arr,arr);
}
