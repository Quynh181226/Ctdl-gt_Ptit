//Minh hoa viec dung con tro giua cac bien

#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main(void){
	int x = 12, *px, *py;
	cout << "x = " << x << endl;
	px = &x; 	// Con tro px tro toi dia chi cua x => px = 12
	cout << "px = &x, *px = " << *px << endl;
	*px = *px + 20; // px = 12 + 20 = 32 và x = 32
	cout << "*px = *px+20, x = " << x << endl;
	py = px; // Cho py tro toi cho mà px tro (dia chi cua x) py = 32
	*py += 15; // py = 32 + 15 = 47 => x = 47 
	cout << "py = px, *py +=15, x = " << x << endl;
}
