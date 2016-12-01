#include<stdio.h>
union Data {
	int integer;
	int *integerptr;
	float floating;
	float *floatptr;
	char character;
	char *charptr;
	struct Data address;
};
typedef struct{
	union Data Value;
	union Data prevptr;
	union Data nextptr;
} LLnode;
LLnode* create (union Data data, union Data preptr, union Data nxtptr){
	LLnode s = {data,preptr,nxtptr};
	return &s;
}
int main(){
	union Data hello;
	union Data nullptr;
	union Data previousptr;
	union Data nextpointer;
	hello.integer = 1;
	nullptr.address =  NULL;
	LLnode *First = create(hello, nullptr, nullptr);
	hello.floating = 10.2;
	previousptr.address = &First;
	LLnode *Second = create(hello, previousptr, nullptr);
	printf("", Second->prevptr);
}

