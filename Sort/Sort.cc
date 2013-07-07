#include <iostream>
#include <assert.h>
using namespace std;

void bubbleSort(int *a, int m){
	assert(a != NULL);
	bool flag = true;
	int temp = 0;

	for (int i = 0; i < m && flag; i++){
		flag = false;
		for (int j = m-2; j >= i; j--){
			if (*(a+j) > *(a+j+1)){
				temp = *(a+j);
				*(a+j) = *(a+j+1);
				*(a+j+1) = temp;
				flag = true;
			}
		}
	}
}

void insertSort(int *a, int m){
	assert(a != NULL);
	int temp;
	int i = 0; 
	int j = 0;

	for (i = 1; i < m; i++){
		temp = a[i];
		for (j = i; j > 0 && temp < a[j-1]; j--){
			a[j] = a[j-1];
		}
		a[j] = temp;
	}

}

void shellSort(int *a, int m){
	assert(a != NULL);

	int d = m;
	int temp;
	int i = 0;
	int j = 0;

	while (d > 1){
		d = d/2;
		for (i = d; i < m; i++){
			temp = a[i];
			for (j = i; j >= d && temp < a[j-d]; j-=d){
				a[j] = a[j-d];
			}
			a[j] = temp;
		}
	}

}

void selectSort(int *a, int m){
	assert(a != NULL);
	int temp = 0;
	int min = 0;

	for (int i = 0; i < m; i++){
		min = i;;
		for (int j = i+1; j < m; j++){
			if (a[min] > a[j])
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

int main(){
	int arr[10] = {2,1,3,4,5,9,0,8,7,6};
	//bubbleSort(arr, 10);
	//insertSort(arr, 10);
	//selectSort(arr, 10);
	shellSort(arr, 10);
	for (int i = 0; i < 10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
