//Minh hoa mang cau truc NV
//Tim NV co min, max luong

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
	char name[20]; // T�n nh�n vi�n
	Date birthDay; // Ng�y sinh nh�n vi�n
	char role[20]; // Chuc vu nh�n vi�n
	float salary; // Luong nh�n vi�n
} Employee;

/* Khai b�o khu�n mau h�m */
void InitArray(Employee *&myEmployee, int length);
Employee searchSalaryMax(Employee *myEmployee, int length); 
Employee searchSalaryMin(Employee *myEmployee, int length); 
void Display(Employee myEmployee);

void InitArray(Employee *&myEmployee, int length){
	myEmployee = new Employee[length];
	for(int i=0; i<length; i++){
		cout << "Nhan vien thu " << i << endl;
		cout << "Name: ";
		cin >> myEmployee[i].name;
		cout << "Day of birth: ";
		cin >> myEmployee[i].birthDay.day;
		cout << "Month of birth: ";
		cin >> myEmployee[i].birthDay.month;
		cout << "Year of birth: ";
		cin >> myEmployee[i].birthDay.year;
		cout << "Role: ";
		cin >> myEmployee[i].role;
		cout << "Salary: ";
		cin >> myEmployee[i].salary;
	}
	return;
}

Employee searchSalaryMax(Employee *myEmployee, int length){ 
	int index = 0;
	int maxSalary = myEmployee[0].salary;
	for(int i=1; i<length; i++)
		if(myEmployee[i].salary > maxSalary){
			maxSalary = myEmployee[i].salary;
			index = i;
		}
	return myEmployee[index];
}

Employee searchSalaryMin(Employee *myEmployee, int length){ 
	int index = 0;
	int minSalary = myEmployee[0].salary;
	for(int i=1; i<length; i++)
		if(myEmployee[i].salary < minSalary){
			minSalary = myEmployee[i].salary;
			index = i;
		}
	return myEmployee[index];
}

void Display(Employee myEmployee){
	cout << "Name: " << myEmployee.name << endl;
	cout << "Birth day: " << myEmployee.birthDay.day << "/"
		<< myEmployee.birthDay.month << "/"
		<< myEmployee.birthDay.year << endl;
	cout << "Role: " << myEmployee.role << endl;
	cout << "Salary: " << myEmployee.salary << endl;
	return;
}
int main(){
	Employee *myEmployee, tmpEmployee;
	int length = 0;
	cout << "So luong nhan vien: ";
	cin >> length;
// Khoi tao danh s�ch nh�n vi�n
	InitArray(myEmployee, length);
// Nh�n vi�n c� luong cao nhat
	cout << "Nhan vien co luong cao nhat: "<< endl;
	tmpEmployee = searchSalaryMax(myEmployee, length);
	Display(tmpEmployee);
// Nh�n vi�n c� luong thap nhat
	cout << "Nhan vien co luong thap nhat: " << endl;
	tmpEmployee = searchSalaryMin(myEmployee, length);
	Display(tmpEmployee);
// Giai ph�ng v�ng nho
	delete [] myEmployee;
	return 0;
}	
