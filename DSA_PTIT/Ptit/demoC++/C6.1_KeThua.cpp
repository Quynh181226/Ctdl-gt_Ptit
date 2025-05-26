//Minh hoa t�nh k� thua

#include<stdio.h>
#include<conio.h>
#include<cstring>
#include<iostream>

using namespace std;

/* �inh nghia lop Car*/
class Car{
	private:
		int speed;
		char mark[20];
		float price;
	public:
		int getSpeed(); 	// �oc toc do xe
		string getMark(); 	// �oc nh�n xe
		float getPrice(); 		// �oc gi� xe
		Car(int speedIn=0, char markIn[]="", float priceIn=0);// Khoi tao th�ng tin xe
		void show(); 			// Gioi thieu xe
};

/* Khai b�o phuong thuc b�n ngo�i lop */
Car::Car(int speedIn, char markIn[], float priceIn){
	speed = speedIn;
	strcpy(mark, markIn);
	price = priceIn;
}

int Car::getSpeed(){			//doc toc do xe
	return speed;	
}

string Car::getMark(){			// �oc nh�n xe
	return mark;
}

float Car::getPrice(){ // �oc gi� xe
	return price;
}

void Car::show(){ // Phuong thuc gioi thieu xe
	cout << "This is a " << mark << " having a speed of "
		<< speed << "km/h and its price is $" << price << endl;
	return;
}

/* �inh nghia lop Bus ke thua lop Car */
class Bus: public Car{
	int label; // so hieu tuyen xe
	public:
		// khoi tao du tham so
		Bus(int sIn=0, char mIn[]="", float pIn=0, int lIn=0);
		void show(); // �inh nghia chong phuong thuc
};

// khoi tao du tham so
Bus::Bus(int sIn, char mIn[], float pIn, int lIn):Car(sIn, mIn, pIn){ 
	label = lIn;
}

// �inh nghia nap chong phuong thuc
void Bus::show(){ 		// Gioi thieu xe bus 
	cout << "This is a bus of type " << getMark() << ", on the line "
		<< label << ", having a speed of " << getSpeed()
		<< "km/h and its price is $" << getPrice() << endl;
	return;
}


// H�m main, chuong tr�nh ch�nh
int main(){
	Car myCar(100, "Ford", 3000); //Bien doi tuong lop Car 
	Bus myBus(80, "Mercedes", 5000, 27);// Bien doi tuong lop Bus
	cout << "Gioi thieu xe o to lan 1:" << endl;
	myCar.show();		//Goi phuong thuc show() cua lop Car, dl doi tuong myCar
	cout << "Gioi thieu xe o to lan 2:" << endl;
	myCar = myBus;		
	myCar.show();		//Goi phuong thuc show() cua lop Car, dl doi tuong myBus
	cout << "Gioi thieu xe bus:" << endl;
	myBus.show();		//Goi phuong thuc show() cua lop Bus, dl doi tuong myBus
	return 0;
}

	
