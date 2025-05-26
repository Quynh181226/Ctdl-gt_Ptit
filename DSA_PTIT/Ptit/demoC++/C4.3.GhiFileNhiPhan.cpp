//minh hoa ghi file nhi phan, dl kieu struct nhap tu ban phim
//ten file + so luong ban ghi nhap tu ban phim

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
	int recordNumber;
	cout << "So luong ban ghi: "; 
	cin >> recordNumber;
/* Mo file */
	// Khai báo và mo file
	fstream fileOut(fileName, ios::out|ios::binary);
	if(!fileOut){ // Không mo duoc file
	cout << "Khong the tao duoc tep tin " << fileName << endl; 
	exit(1);
	}
/* Ghi dl vao file */
	Employee myEmployee;
	for(int i=0; i<recordNumber; i++){
	cout << "Ban ghi thu " << i+1 << endl;
	cout << "Name: ";
	cin >> myEmployee.name; 
	cout << "Day of birth: ";
	cin >> myEmployee.birthDay.day;
	cout << "Month of birth: ";
	cin >> myEmployee.birthDay.month;
	cout << "Year of birth: ";
	cin >> myEmployee.birthDay.year;
	cout << "Role: ";
	cin >> myEmployee.role; 
	cout << "Salary: ";
	cin >> myEmployee.salary; 
// Ghi dl vao file
	fileOut.write(reinterpret_cast<char *>(&myEmployee), sizeof(Employee));
	}
/* Ðóng file */
	fileOut.close(); 
}
