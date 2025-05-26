//Minh hoa doc dl tu file ra man hinh
//Ten File nhap tu ban phim

#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>

using namespace std;

const int length = 25; // Do dai toi da ten file

int main(){
	char fileName[length], output;
	cout << "Ten tep tin: ";
	cin >> setw(length) >> fileName; // Nhap ten file
/* Mo file */
	ifstream fileIn(fileName, ios::in); // Khai b�o v� mo file
	if(!fileIn){ // Kh�ng mo duoc file
		cout << "Khong the mo duoc tep tin " << fileName << endl;
	exit(1);
	}
/* �oc file in ra m�n h�nh */
	while(fileIn >> output){// Doc ki tu tu file
		cout << output << ' '; // Ghi ra m�n h�nh
	}
	cout << endl; // Xuong d�ng tr�n m�n h�nh
/* ��ng file */
	fileIn.close(); 
}

