#include "udll.c"
#include "udll.h"
int main(){
	union Data hello;
	hello.charptr = "hello";
	LLnode Last = {NULL,NULL, hello, 3};
	tail = &Last;
	LLnode middle2 = {&Last, NULL, hello,3};
	LLnode middle1 = {&middle2, NULL, hello,3};
	union Data Count;
	Count= 4;
	LLnode first = {&middle1, NULL,Count,0};
	head = &first;
	printf("%d", length());
	insert(1,get(1));
	remove(1);
}
