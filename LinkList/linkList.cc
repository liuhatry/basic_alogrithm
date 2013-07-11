#include <iostream>
#include <assert.h>
using namespace std;

typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode,*LinkList;


LinkList linkReverse(LinkList head){

	if (NULL == head || NULL == head->next)
		return head;

	LinkList p1, p2, p3;
	p1 = head;
	p2 = head->next;
	while (p2){
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head->next = NULL;
	head = p1;

	return head;
}
int main(){
	return 0;
}
