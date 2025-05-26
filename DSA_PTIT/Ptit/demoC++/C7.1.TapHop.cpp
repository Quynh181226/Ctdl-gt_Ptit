//Minh hoa 1 so thao tac tren 1 tap hop cac phan tu có kieu char
//su dung thu vien Set

#include <stdio.h>
#include <conio.h>
#include <set>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	system("cls");
	set <char> mySet;
	int function;
	do{
		cout << "CAC CHUC NANG:" << endl;
		cout << "1: Them mot phan tu vao tap hop" << endl;
		cout << "2: Loai bo mot phan tu khoi tap hop" << endl;
		cout << "3: Xem tat ca cac phan tu cua tap hop" << endl;
		cout << "5: Thoat!" << endl;
		cout << "=====================================" << endl; 
		cout << "Chon chuc nang: " << endl;
		cin >> function;
		switch(function){
			case 1: // Thêm vào
				char phantu;
				cout << "Ki tu them vao: ";
				cin >> phantu;
				mySet.insert(phantu);
				break;
			case 2: // Loai ra
				//char phantu;
				cout << "Loai bo ki tu: " << endl;
				cin >> phantu;
				mySet.erase(phantu);
				break;
			case 3: // Duyet
				cout<<"Cac phan tu cua tap hop la:"<<endl;
				set<char>::iterator i;
				for(i=mySet.begin(); i != mySet.end(); i++)
					cout << *i << " ";
				cout << endl;
				system("pause");
				break;
		}
	}while(function != 5);
	return 0;
}
