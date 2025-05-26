//Minh hoa dung ngan xep dao nguoc xau ki tu

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

typedef struct {
	int top;		//vi tri node dinh
	char *nodes;		//danh sach phan tu
} Stack;
 
/* Khai b�o nguy�n mau h�m */ 
void init(Stack *stack);
void push(Stack *stack, char node); 
int pop(Stack *stack); 
void release(Stack *stack);

void init(Stack *stack){ 
	stack = new Stack; 		//cap phat vung nho cho con tro
	stack->top = -1;		//khoi tao ngan xep rong
}

void push(Stack *stack, char node){
	//cout << "Stack is empty!" << endl;
	Stack *tmpNodes = new Stack[stack->top + 2];	// cap phat vung nho moi
	stack->top ++; 								// Tang chi so node dinh
	for(int i=0; i<stack->top; i++) 			// Sao ch�p sang v�ng nho moi
		tmpNodes[i] = stack->nodes[i];
	tmpNodes[stack->top] = node; 				// Th�m node moi v�o dinh
	delete [] stack->nodes; 					// Giai ph�ng v�ng nho cu
	stack->nodes = tmpNodes; 					// Tro v�o v�ng nho moi
	return;
}

int pop(Stack *stack){
	if(stack->top < 0){ 						// Kiem tra ngan xep rong
		cout << "Stack is empty!" << endl;
	return 0;
	}
	int result = stack->nodes[stack->top];		// Luu giu gi� tri dinh
	int *tmpNodes = new int[stack->top];		// Cap ph�t v�ng nho moi
	for(int i=0; i<stack->top; i++) 			// Sao ch�p sang v�ng nho moi
		tmpNodes[i] = stack->nodes[i];
			stack->top --; 						// Giam chi so cua node dinh
	delete [] stack->nodes; 					// Giai ph�ng v�ng nho cu
	stack->nodes = tmpNodes; 					// Tro vao vung nho moi
	return result; 								// Tra ve gia tri node dinh
}

void release(Stack *stack){ 
	delete [] stack->nodes; 	//Giai phong vung danh sach
	delete stack;				//Giai phong con tro
	return;
}

int main(){
	Stack *stack;
	init(stack); 				// Khoi tao ngan xep
	char *strIn;
//Nhap chuoi ki tu tu b�n ph�m 
	cout << "Nhap chuoi: ";
	cin >> strIn;
	for(int i=0; i<strlen(strIn); i++) 		// �at v�o ngan xep
		push(stack, strIn[i]);
	while(stack->top > -1)					//lay ra tu ngan xep
		cout << pop(stack);
	release(stack);				
	return 0;
}
