//Minh hoa ham permission() cua lop Person, l� h�m ban cua lop Car
//kiem tra 1 nguoi c� du quyen dieu khien xe hay ko
//du 18t voi xe thong thuong
//du 21t voi xe c� toc do > 150km/h

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>

using namespace std;

class Car; // Khai b�o nguy�n mau lop

/* �inh nghia lop Person */
class Person{
	private:
		char name[25];
		int age; 
	public:
		void init(char[], int);		//Khoi tao thong tin ve Person
		int permission(Car);		//Xac dinh quyen dieu khien xe
};

/* �inh nghia lop Car */
class Car{
	private:
		int speed;					//toc do
		char mark[20];				//Nhan hieu
		float price;				//Gia xe
	public:
		void init(int, char[], float);		//Khoi tao thong tin ve xe
		friend int Person::permission(Car);	//Khai b�o h�m ban cua lop
};

/* Khai b�o phuong thuc b�n ngo�i lop */
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

/* �inh nghia h�m ban */
int Person::permission(Car car){
	if(age < 18)
		return 0;
//Truy nhap thuoc t�nh private th�ng qua doi tuong car
	if((age < 21)&&(car.speed > 150))
		return 0;
	return 1;
}

// H�m main, chuong tr�nh ch�nh
int main(){

// Khai b�o c�c bien lop
	Car car;
	Person person;
//Khoi tao cac doi tuong 
	car.init(100, "Ford", 3000); 	
	person.init("Vinh", 20);
// X�c dinh quyen dieu khien xe	
	if(person.permission(car)) //su dung ham ban
		cout << "Co quyen dieu khien" << endl;
	else
		cout << "Khong co quyen dieu khien" << endl;
	return 0;
}



