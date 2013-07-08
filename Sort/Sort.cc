#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;

void swap(int *a, int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

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

int partition(int *a, int l, int r){
	int pivot = a[l];

	while (l < r){
		while (l < r && a[r] >= pivot)
			r--;
		if (l < r){
			a[l++] = a[r];
		}

		while (l < r && a[l] <= pivot)
			l++;
		if (l < r){
			a[r--] = a[l];
		}
	}
	a[l] = pivot;
	return l;
}
void quickSort(int *a, int l, int r){
	int q;
	if (l < r){
		q = partition(a,l,r);
		quickSort(a,l,q-1);
		quickSort(a,q+1,r);
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

void heapAdjust(int *a, int i, int m){
	int nchild;
	for (; 2*i+1 < m; i = nchild){
		nchild = 2*i+1;
		if ((nchild+1) < m && a[nchild] < a[nchild+1])
			nchild++;
		if (a[nchild] > a[i]){
			swap(a, i, nchild);
		} else
			break;
	}
}

void heapSort(int *a, int m){
	for (int i = m/2-1; i >= 0; i--){
		heapAdjust(a,i,m);
	}
	for (int i = m-1; i > 0; i--){
		swap(a,0,i);
		heapAdjust(a,0,i);
	}
}

void merge(int *a, int *temp, int l, int mid, int r){

	if (l > mid || mid > r)
		return;
	int i = l;
	int l0 = l;
	int l1 = mid+1;
	while (l0 <= mid && l1 <= r){
		if (a[l0] < a[l1])
			temp[i++] = a[l0++];
		else
			temp[i++] = a[l1++];
	}

	while (l0 <= mid)
		temp[i++] = a[l0++];
	while (l1 <= r)
		temp[i++] = a[l1++];

	for (i = l; i <= r; i++)
		a[i] = temp[i];
}
void _mergeSort(int *a, int *temp, int l, int r){
	if (l < r){
		int mid = (l+r)/2;
		_mergeSort(a,temp,l,mid);
		_mergeSort(a,temp,mid+1,r);
		merge(a,temp,l,mid,r);
	}
}

void mergeSort(int *a, int len){
	int *p = new int[len];
	_mergeSort(a, p, 0, len-1);
	delete[] p;
}

void mergeSort2(int *a, int len){
	assert(a != NULL);
	int* p = new int[len];
	int s = 2;
	int i;
	while (s <= len){
		for (i=0; i+s<=len ; i+=s){
			merge(a,p,i,i+s/2-1,i+s-1);
		}
		merge(a,p,i,i+s/2-1,len-1);
		s *= 2;
	}
	merge(a,p,0,s/2-1,len-1);
	delete[] p; 
}

void countSort(int *a, int len, int max){
	int *temp = new int[max+1];
	memset(temp, 0, sizeof(int)*(max+1));
	for (int i=0; i < len; i++){
		temp[a[i]]++;
	}

	int k = 0;
	for (int i=0; i <= max; i++){
		while (temp[i] > 0){
			a[k++] = i;
			temp[i]--;
		}
	}

	delete[] temp;
}
int main(){
	int arr[15] = {2,1,3,4,5,89,0,8,7,6,34,5,5,3,14};
	//bubbleSort(arr, 10);
	//insertSort(arr, 10);
	//selectSort(arr, 10);
	//shellSort(arr, 10);
	//quickSort(arr, 0, 9);
	//heapSort(arr, 10);
	//mergeSort(arr, 10);
	//mergeSort2(arr, 10);
	countSort(arr, 15, 89);
	for (int i = 0; i < 15; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
