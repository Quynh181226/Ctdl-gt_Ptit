//Minh hoa viec khoi tao va hien thi noi dung con tro cau truc

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>

using namespace std;

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char name[20]; // Tên nhân viên
	Date birthDay; // Ngày sinh nhân viên
	char role[20]; // Chuc vu nhân viên
	float salary; // Luong nhân viên
} Employee;

/* Khai báo khuôn mau hàm */
void InitStruct(Employee *&myEmployee);
void Display(Employee *myEmployee);

void InitStruct(Employee *&myEmployee){
	myEmployee = new Employee;
	cout << "Name: ";
	cin >> myEmployee->name;
	cout << "Day of birth: ";
	cin >> myEmployee->birthDay.day;
	cout << "Month of birth: ";
	cin >> myEmployee->birthDay.month;
	cout << "Year of birth: ";
	cin >> myEmployee->birthDay.year;
	cout << "Role: ";
	cin >> myEmployee->role;
	cout << "Salary: ";
	cin >> myEmployee->salary;
}

void Display(Employee *myEmployee){
	cout << "Name: " << myEmployee->name << endl;
	cout << "Birth day: " << myEmployee->birthDay.day << "/"
			<< myEmployee->birthDay.month << "/"
			<< myEmployee->birthDay.year << endl;
	cout << "Role: " << myEmployee->role << endl;
	cout << "Salary: " << myEmployee->salary << endl;
	return;
}

int main(){
	Employee *myEmployee;
	InitStruct(myEmployee);
	Display(myEmployee);
	return 0;
}

