//Minh hoa 1 so thao tac tren lop chuoi
//su dung thu vien chuoi

#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>


using namespace std;

int main(){
	system("cls");
	string myStr;
	int function;
	do{
	cout << "CAC CHUC NANG:" << endl;	
	cout << "1: Cong them mot chuoi" << endl;	
	cout << "2: Chen them mot chuoi" << endl;
	cout << "3: Xoa di mot chuoi" << endl;
	cout << "4: Tim mot chuoi con" << endl;
	cout << "5: Xem noi dung chuoi" << endl;
	cout << "6: Xem chieu dai chuoi" << endl;	
	cout << "9: Thoat!" << endl;
	cout << "=====================================" << endl; 
	cout << "Chon chuc nang: ";
	cin >> function;
	switch(function){
		case 1: // Thêm vào cuoi
			{
			string subStr;
			cout << "Chuoi them vao: ";
			cin >> subStr;
			myStr += subStr;
			break;}
		case 2:  // Chèn vào chuoi
			{
			string subStr;
			int position;
			cout << "Chuoi them vao: ";
			cin >> subStr;
			cout << "Vi tri chen:";
			cin >> position;
			myStr.insert(position, subStr);
			break;}
		case 3: // Xoá di mot chuoi con
			{
			int position, count;
			cout << "Vi tri bat dau xoa:";
			cin >> position;	
			cout << "Do dai xoa:";
			cin >> count;
			myStr.erase(position, count);
			break;}
		case 4: // Tìm chuoi con
			{
			string subStr;
			int position;
			cout << "Chuoi con can tim:";
			cin >> subStr;
			cout << "Vi tri bat dau tim:";
			cin >> position;
			if(myStr.find(subStr, position))	
				cout << "Co xuat hien!" << endl;	
			else
				cout << "Khong xuat hien!" << endl;	
			break;}
		case 5: // Duyet
			cout << "Noi dung chuoi:" << endl;	
			cout << myStr << endl;
			break;
		case 6: // Duyet
			cout << "Chieu dai chuoi:" << myStr.length() << endl;
			break;
		}
	}while(function != 9);
return 0;
}

