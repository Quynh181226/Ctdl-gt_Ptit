//minh hoa doc file nhi phan co ten nhap tu ban phim, dl kieu struct 

#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>

using namespace std;

const int length = 25; // Do dai toi da ten file

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char name[20];
	Date birthDay;
	char role[20];
	float salary;
} Employee;

int main(){
	char fileName[length]; 
	cout << "Ten tep tin: ";
	cin >> setw(length) >> fileName; 
/* Mo file */
// Khai báo và mo file
	fstream fileIn(fileName, ios::in|ios::binary);
	if(!fileIn){ // Không mo duoc file 
		cout << "Khong the mo duoc tep tin " << fileName << endl; 
	exit(1);
	}
/* Doc file in ra màn hình */
	Employee myEmployee;
	while(fileIn.read(reinterpret_cast<char *>(&myEmployee),sizeof(Employee))){	// doc ki tu tu file 
	cout << myEmployee.name << " " << myEmployee.birthDay.day << "/" 
		<< myEmployee.birthDay.month << "/" << myEmployee.birthDay.year << "       "
			<< myEmployee.role << " " << myEmployee.salary << endl; // Ghi kí tu ra màn hình
	}
/* Ðóng file */
	fileIn.close(); 
}
