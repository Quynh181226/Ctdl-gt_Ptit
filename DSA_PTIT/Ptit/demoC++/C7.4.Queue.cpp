//Minh hoa 
//su dung thu vien queue

#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(){
	system("cls");
	queue<int> myQueue;
	int function;
	do{
		cout << "CAC CHUC NANG:" << endl;
		cout << "1: Them mot tien trinh vao hang doi" << endl;
		cout << "2: Dua mot tien trinh trinh vao thuc hien" << endl;
		cout << "3: Xem tat ca cac tien trinh trong hang doi" << endl;
		cout << "5: Thoat!" << endl;
		cout << "========================================" << endl;
		cout << "Chon chuc nang: ";
		cin >> function;
		switch(function){
			case 1: // Thêm vào hàng doi
				{
				int maso;
				cout << "Ma so tien trinh vao hang doi: ";
				cin >> maso;
				myQueue.push(maso);
				break;
			}
			case 2: // lay ra khoi hang doi
				{
					if (myQueue.empty())
						{
							cout << "Hang doi rong! Ko co tien trinh nao duoc thuc hien! " << endl;
							break;
						}
					else
					{
						cout << "Tien trinh duoc thuc hien: " << myQueue.front() << endl;
						myQueue.pop();
						break;	
					}
			}
			case 3: // Duyet hàng doi
				while (!myQueue.empty()) 
    			{ 
        			cout << '\t' << myQueue.front(); 
        			myQueue.pop(); 
    			} 
    			cout << '\n';
				break;
			}
	}while(function != 5);
	return 0;
}
