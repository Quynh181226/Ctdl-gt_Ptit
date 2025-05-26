//Minh hoa Ghi File
//Ghi cac ki tu nhap tu ban phim cho den khi nhap ki tu e
//moi ki tu phan cach ' '

#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>

using namespace std;

const int length = 25; // Do dai toi da ten file

int main(){
	char fileName[length], input;
	cout << "Ten tep tin: ";
	cin >> setw(length) >> fileName; //Nhap ten file
/* Mo file */
	ofstream fileOut(fileName, ios::out);// Khai báo và mo file
	if(!fileOut){ // Không mo duoc file 
	cout << "Khong the tao duoc tep tin " << fileName << endl; 
	exit(1);
	}
/* Ghi du lieu vao file */
	do{
	cin >> input;	//doc ki tu tu ban phim
	fileOut << input << ' ';	//ghi ki tu vao file
	}while((input != 'e')&&(fileOut));
	fileOut << endl; // xuong dong cuoi file
/* Ðóng file */
	fileOut.close();	//Dong file
	return 0;
}
