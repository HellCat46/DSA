#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void enqueue(struct Node**, struct Node**);
void dequeue(struct Node**, struct Node**);
void display(struct Node*);

int main(){
	struct Node* f = NULL, *r = NULL;
	int in;

	while(1){
		printf("\n1)To Insert \n2)To Delete \n3)Display \n4)Exit");
		printf("\nEnter Choice:");
		scanf("%d", &in);

		switch(in){
			case 1: enqueue(&f, &r);
				break;
			case 2: dequeue(&f, &r);
				break;
			case 3: display(f);
				break;
			case 4: exit(1);

			default: printf("Invalid Choice");
		}
	}

	return 0;
}


void enqueue(struct Node** f, struct Node** r){
	struct Node *p;
	p = (struct Node*) malloc(sizeof(struct Node));

	printf("Enter Data:");
	scanf("%d", &p->data);
	p->next = NULL;

	if(*r == NULL){
		*r = *f = p;
	}else {
		(*r)->next = p;
		*r = p;
	}
}

void dequeue(struct Node** f, struct Node** r){
	struct Node *p = *f;

	if(*f == NULL){
		printf("Underflow\n");
		return;
	}

	if(p->next == NULL){
		*f = *r = NULL;
	}else {
		*f = p->next;
	}

	printf("Removed Data: %d", p->data);
	free(p);
}
void display(struct Node* f){
	struct Node* p = f;

	if(p == NULL){
		printf("Queue is Empty\n");
		return;
	}

	while(p != NULL){
		printf("%d\n", p->data);
		p = p->next;
	}
}
