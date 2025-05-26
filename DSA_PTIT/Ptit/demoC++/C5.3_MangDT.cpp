//Minh hoa mang doi tuong
//Nhap mang cac xe, tim xe c� gia dat nhat 

#include<stdio.h>
#include<conio.h>
#include<cstring>
#include<iostream>

using namespace std;

/* �inh nghia lop */
class Car{
	private:
		int speed;
		char mark[20];
		float price;
	public:
		void setSpeed(int); // G�n toc do cho xe
		int getSpeed(); 	// �oc toc do xe
		void setMark(char*); // G�n nh�n cho xe
		string getMark(); 	// �oc nh�n xe
		void setPrice(float); // G�n gi� cho xe
		float getPrice(); 		// �oc gi� xe
		Car(int speedIn=0, char* markIn="", float priceIn=0);// Khoi tao th�ng tin xe
		void show(); 			// Gioi thieu xe
};

/* Khai b�o phuong thuc b�n ngo�i lop */
Car::Car(int speedIn, char *markIn, float priceIn){
	speed = speedIn;
	strcpy(mark, markIn);
	price = priceIn;
}

void Car::setSpeed(int speedIn){ // G�n toc do cho xe
	speed = speedIn;
}

int Car::getSpeed(){			//doc toc do xe
	return speed;	
}

void Car::setMark(char* markIn){	// G�n nh�n cho xe
	strcpy(mark, markIn);
}

string Car::getMark(){			// �oc nh�n xe
	return mark;
}

void Car::setPrice(float priceIn){// G�n gi� cho xe
	price = priceIn;
}

float Car::getPrice(){ // �oc gi� xe
	return price;
}

void Car::show(){ // Phuong thuc gioi thieu xe
	cout << "This is a " << mark << " having a speed of "
		<< speed << "km/h and its price is $" << price << endl;
	return;
}

// H�m main, chuong tr�nh ch�nh
int main(){
	int length;				//chieu dai mang
	float maxPrice = 0;		//Gia cao nhat
	int index = 0;			//Chi so cua xe dat nhat
	Car *cars;				//Khai bao mang doi tuong
	cout << "So luong xe: ";	//Nhap sl xe, tuc chieu dai mang
	cin >> length;
//Cap phat bo nho dong cho mang
	cars = new Car[length];
//Khoi tao cac doi tuong trong mang
	for(int i=0;i<length; i++){
		int speed;			//Bien tam (toc do)
		char mark[20];		//Bien tam nhan hieu
		float price; 		//Bien tam gi� xe
		cout << "Xe thu " << i+1 << ": " <<endl;
		cout << "Toc do (km/h): ";
		cin >> speed; cars[i].setSpeed(speed); // Nhap toc do
		cout << "Nhan hieu : ";
		cin >> mark; cars[i].setMark(mark); // Nhap nh�n xe
		cout << "Gia ($): ";
		cin >> price; cars[i].setPrice(price); // Nhap gi� xe
		if(maxPrice < price){
			maxPrice = price;
			index = i;
		}
	}
// T�m xe gia cao nhat
	for(int i=0; i<length; i++)
		if(i == index){
			cars[i].show(); // Gioi thieu xe co gia cao nhat
			break;
		}
// Giai phong bo nho cua mang
	delete [] cars;
	cout << "The object has been destroyed!" << endl;
	return 0;
}

