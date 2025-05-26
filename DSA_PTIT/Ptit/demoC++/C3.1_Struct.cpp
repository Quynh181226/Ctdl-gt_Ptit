//Minh hoa su dung cau truc don, ko dung tu khoa typedef

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>

using namespace std;

struct Employee{
	char name[20]; // Tên nhân viên
	int age; // Tuoi nhân viên
	char role[20]; // Chuc vu nhân viên
	float salary; // Luong nhân viên
};

/* Khai báo khuôn mau hàm */
void Display(struct Employee myEmployee);

void Display(struct Employee myEmployee){
	cout << "Name: " << myEmployee.name << endl;
	cout << "Age: " << myEmployee.age << endl;
	cout << "Role: " << myEmployee.role << endl;
	cout << "Salary: " << myEmployee.salary << endl;
return;
}

int main(){
// Hien thi gia tri mac dinh
	struct Employee myEmployee = {"Nguyen Van A", 27, "Nhan vien", 300};
	cout << "Thong tin mac dinh:" << endl;
	Display(myEmployee);
//Thay doi gia tri cho cac thuoc tinh
	cout << "Name: ";
	cin >> myEmployee.name;
	cout << "Age: ";
	cin >> myEmployee.age;
	cout << "Role: ";
	cin >> myEmployee.role;
	cout << "Salary: ";
	cin >> myEmployee.salary;
	cout << "Thong tin sau khi thay doi:" << endl;
	Display(myEmployee);
	return 0;
}

