//Minh hoa su dung lop Car voi cac thuoc tinh cuc bo
//c�c phuong thuc public de dinh nghia cac doi tuong cu the

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>

using namespace std;

/* Dinh nghia lop */
class Car{
	private:
		int speed; 			// Toc do
		char mark[20]; 		// Nh�n hieu
		float price; 		// Gi� xe
	public:
		void setSpeed(int); // G�n toc do cho xe
		int getSpeed(); 	// �oc toc do xe
		void setMark(char*); // G�n nh�n cho xe
		char* getMark(); 	// �oc nh�n xe
		void setPrice(float); // G�n gi� cho xe
		float getPrice(); 		// �oc gi� xe
		void init(int, char[], float);// Khoi tao th�ng tin xe
		void show(); 			// Gioi thieu xe
};

/* Khai b�o phuong thuc b�n ngo�i lop */
void Car::setSpeed(int speedIn){ // G�n toc do cho xe
	speed = speedIn;
}

int Car::getSpeed(){			//doc toc do xe
	return speed;	
}

void Car::setMark(char* markIn){	// G�n nh�n cho xe
	strcpy(mark, markIn);
}

char* Car::getMark(){			// �oc nh�n xe
	return mark;
}

void Car::setPrice(float priceIn){// G�n gi� cho xe
	price = priceIn;
}

float Car::getPrice(){ // �oc gi� xe
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

// H�m main, chuong tr�nh ch�nh
int main(){
	Car myCar; // Khai b�o bien lop
// Khoi tao lan 1
	cout << "Xe thu nhat: " << endl;
	myCar.init(100, "Ford", 3000);
	cout << "Toc do (km/h): " << myCar.getSpeed() << endl;
	cout << "Nhan hieu : " << myCar.getMark() << endl;
	cout << "Gia ($): " << myCar.getPrice() << endl;
// Thay doi thuoc t�nh xe
	cout << "Xe thu hai: " << endl;
	myCar.setSpeed(150);
	myCar.setMark("Mercedes");
	myCar.setPrice(5000);
	myCar.show();
	return 0;
}
