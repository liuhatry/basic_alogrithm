#include <iostream>
#include <assert.h>
using namespace std;

int  binaryFind(int *a, int val, int l, int r){
	assert(a != NULL);
	int mid;
	while (l <= r){
		mid = (l+r)/2;
		if (a[mid] == val){
			while (a[mid] == val)  //Find the first one.
				mid--;
			return mid+1;
		}
		else if (a[mid] > val)
			r = mid-1;
		else
			l = mid+1;
	}
	return -1;
}
int main(){
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	cout<<binaryFind(arr,5,0,9)<<endl;
	cout<<binaryFind(arr,10,0,9)<<endl;
}
