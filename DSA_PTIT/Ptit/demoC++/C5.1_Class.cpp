//Minh hoa su dung lop Car voi cac thuoc tinh cuc bo
//các phuong thuc public de dinh nghia cac doi tuong cu the

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>

using namespace std;

/* Dinh nghia lop */
class Car{
	private:
		int speed; 			// Toc do
		char mark[20]; 		// Nhãn hieu
		float price; 		// Giá xe
	public:
		void setSpeed(int); // Gán toc do cho xe
		int getSpeed(); 	// Ðoc toc do xe
		void setMark(char*); // Gán nhãn cho xe
		char* getMark(); 	// Ðoc nhãn xe
		void setPrice(float); // Gán giá cho xe
		float getPrice(); 		// Ðoc giá xe
		void init(int, char[], float);// Khoi tao thông tin xe
		void show(); 			// Gioi thieu xe
};

/* Khai báo phuong thuc bên ngoài lop */
void Car::setSpeed(int speedIn){ // Gán toc do cho xe
	speed = speedIn;
}

int Car::getSpeed(){			//doc toc do xe
	return speed;	
}

void Car::setMark(char* markIn){	// Gán nhãn cho xe
	strcpy(mark, markIn);
}

char* Car::getMark(){			// Ðoc nhãn xe
	return mark;
}

void Car::setPrice(float priceIn){// Gán giá cho xe
	price = priceIn;
}

float Car::getPrice(){ // Ðoc giá xe
	return price;
}

void Car::init(int speedIn, char markIn[], float priceIn){
	speed = speedIn;
	strcpy(mark, markIn);
	price = priceIn;	
	return;
}

void Car::show(){ // Phuong thuc gioi thieu xe
	cout << "This is a " << mark << " having a speed of "
		<< speed << "km/h and its price is $" << price << endl;
	return;
}

// Hàm main, chuong trình chính
int main(){
	Car myCar; // Khai báo bien lop
// Khoi tao lan 1
	cout << "Xe thu nhat: " << endl;
	myCar.init(100, "Ford", 3000);
	cout << "Toc do (km/h): " << myCar.getSpeed() << endl;
	cout << "Nhan hieu : " << myCar.getMark() << endl;
	cout << "Gia ($): " << myCar.getPrice() << endl;
// Thay doi thuoc tính xe
	cout << "Xe thu hai: " << endl;
	myCar.setSpeed(150);
	myCar.setMark("Mercedes");
	myCar.setPrice(5000);
	myCar.show();
	return 0;
}
