//Minh hoa dao nguoc xau
//su dung thu vien stack

#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include  <stack>

using namespace std;

int main(){
	system("cls");
	stack<char> myStack;
	char strIn[250];
	cout << "Nhap chuoi: ";
	cin >> strIn; 
	for(int i=0; i<strlen(strIn); i++) 
		myStack.push(strIn[i]);		//Day tung ki tu vao ngan xep
	while(!myStack.empty()) // Lay tung ki tu ra khi ngan xep khac rong
	{
		cout << myStack.top();
		myStack.pop();
		}
	return 0;
}

