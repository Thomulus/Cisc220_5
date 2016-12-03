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
			iterator = tempit.next;
			tempit = *iterator;
		}
	}
	else 	{
		iterator = tail;
		tempit = *iterator;
		for (int i =0; i < length()-index; i++){
			iterator = tempit.prev;
			tempit = *iterator;
			prevnode = tempit.prev;
		}
	}
	if (index == 0) {
		LLnode *Middle = create(head,NULL,data,3);
		union Data temp = tempit.Value;;
		update(head, tempit.next, Middle, data,3);
		update(Middle, head, NULL, temp,3);
		head = Middle;
	}
	else{
	LLnode tempprev = *prevnode;
	LLnode *Middle = create(iterator,prevnode,data,3);
	update(iterator, tempit.next, Middle, tempit.Value,3);
	update(prevnode, Middle, tempprev.prev, tempprev.Value,3);
	}
	tempit = *head;
	union Data Count;
	Count.integer = length() +1;
	update(head, tempit.next, tempit.prev, Count,0);
	return;
}
void removeNode(int index){
	LLnode *iterator =head;
	LLnode *prevnode = NULL;
	LLnode *nextnode = NULL;
	LLnode derefhead = *head;
	LLnode tempit = *iterator;
	if (index ==0){
		head = derefhead.next;
	}
	if (index == length() -1){
		
	}
	if (index < length()/2){
		for(int i=0; i <index; i++){
			iterator = tempit.next;
			tempit = *iterator;
		}
	}
	else{
		LLnode dereftail = *tail;
		iterator = tail;
		for (int i=0; i < length()-index; i++){
			tail = dereftail.prev;
			dereftail = *tail;
		}
	}
	prevnode = (*iterator).prev;
	nextnode = (*iterator).next;
	update(nextnode, (*nextnode).next, prevnode, (*nextnode).Value,(*nextnode).type);
	update(prevnode, nextnode, (*prevnode).prev, (*prevnode).Value,(*prevnode).type);
	union Data Count;
	Count.integer = length() -1;
	tempit = *head;
	update(head,tempit.next, tempit.prev, Count,0);
	
}
void printAll(){
	for(LLnode *i = head; i!=NULL; i=i->next){
		printf("derp");
	}
}
int main(){
	/*union Data hello;
	union Data goodbye;
	hello.charptr = "hello";
	goodbye.charptr = "goodbye";
	LLnode Test = {NULL,NULL, hello,3};
	LLnode First = {&Test,NULL, hello,3};
	LLnode Second = {&First, NULL, goodbye,3};
	update(&First, &Test, &Second, hello,3);
	union Data middle;
	middle.charptr = "middle";
	LLnode Third = {&Second, NULL, 4 , 0};
	head = &Third;
	printAll();
	printf("\n");
	insert(1,hello);
	update(&Second, &First, &Third, goodbye,3);
	update(&Test, NULL, &First, hello, 3);
	printAll();
	printf("\n");
	removeNode(1);
	printAll();
	printf("\n");
	printf("%d", length());*/
}
