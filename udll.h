#include<stdio.h>
#include<stdlib.h>
union Data {
	int integer;
	int *intptr;
	float floating;
	float *floatptr;
	char character;
	char *charptr;
};
typedef struct LLnode LLnode;
struct LLnode {
	struct LLnode *next;
	struct LLnode *prev;
	union Data Value;
	int type;
};
LLnode *create (LLnode *next, LLnode *prev, union Data Value, int type){
	LLnode *s = malloc(sizeof(LLnode));
	s->next =next; s->prev=prev; s->Value=Value; s->type=type;
	return s;
}
union Data Len;
struct LLnode* head;
struct LLnode* tail;
void update(LLnode* s, LLnode *next, LLnode *prev, union Data Value,int type){
	s->next=next;
	s->prev=prev;
	s->Value=Value;
	s->type=type;
}
int length(){
	LLnode temp = *head;
	
	return temp.Value.integer;
}
union Data get(int index){
	LLnode *iterator = head;
	for (int i = 0; i < index; i ++){
		iterator = (*iterator).next;
	}
	return (*iterator).Value;
}
void insert(int index, union Data data){
	LLnode *iterator = head;
	LLnode *prevnode = NULL;
	LLnode tempit = *iterator;
	if (index < length()/2){
		for (int i = 0; i < index; i++){
			prevnode = iterator;
