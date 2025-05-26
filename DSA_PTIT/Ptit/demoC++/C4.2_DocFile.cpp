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
	ifstream fileIn(fileName, ios::in); // Khai báo và mo file
	if(!fileIn){ // Không mo duoc file
		cout << "Khong the mo duoc tep tin " << fileName << endl;
	exit(1);
	}
/* Ðoc file in ra màn hình */
	while(fileIn >> output){// Doc ki tu tu file
		cout << output << ' '; // Ghi ra màn hình
	}
	cout << endl; // Xuong dòng trên màn hình
/* Ðóng file */
	fileIn.close(); 
}

