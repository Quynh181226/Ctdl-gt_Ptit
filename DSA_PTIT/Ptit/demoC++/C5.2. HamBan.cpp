//Minh hoa ham permission() cua lop Person, là hàm ban cua lop Car
//kiem tra 1 nguoi có du quyen dieu khien xe hay ko
//du 18t voi xe thong thuong
//du 21t voi xe có toc do > 150km/h

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>

using namespace std;

class Car; // Khai báo nguyên mau lop

/* Ðinh nghia lop Person */
class Person{
	private:
		char name[25];
		int age; 
	public:
		void init(char[], int);		//Khoi tao thong tin ve Person
		int permission(Car);		//Xac dinh quyen dieu khien xe
};

/* Ðinh nghia lop Car */
class Car{
	private:
		int speed;					//toc do
		char mark[20];				//Nhan hieu
		float price;				//Gia xe
	public:
		void init(int, char[], float);		//Khoi tao thong tin ve xe
		friend int Person::permission(Car);	//Khai báo hàm ban cua lop
};

/* Khai báo phuong thuc bên ngoài lop */
void Person::init(char nameIn[], int ageIn){
	strcpy(name, nameIn);
	age = ageIn;
	return;
}

void Car::init(int speedIn, char markIn[], float priceIn){
	speed = speedIn;
	strcpy(mark, markIn);
	price = priceIn;
	return;
}

/* Ðinh nghia hàm ban */
int Person::permission(Car car){
	if(age < 18)
		return 0;
//Truy nhap thuoc tính private thông qua doi tuong car
	if((age < 21)&&(car.speed > 150))
		return 0;
	return 1;
}

// Hàm main, chuong trình chính
int main(){

// Khai báo các bien lop
	Car car;
	Person person;
//Khoi tao cac doi tuong 
	car.init(100, "Ford", 3000); 	
	person.init("Vinh", 20);
// Xác dinh quyen dieu khien xe	
	if(person.permission(car)) //su dung ham ban
		cout << "Co quyen dieu khien" << endl;
	else
		cout << "Khong co quyen dieu khien" << endl;
	return 0;
}



