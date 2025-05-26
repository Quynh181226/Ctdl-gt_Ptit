//Minh hoa d�ng mang d�ng 2 chi�u tinh tong 2 ma tran

#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

/* Khai b�o nguy�n m�u h�m */
int** InitArray(int row, int colum);
void AddArray(int **A, int **B, int row, int colum);
void DisplayArray(int **A, int row, int colum);
void DeleteArray(int **A, int row);

int** InitArray(int row, int colum){
	int **A = new int*[row];
	for(int i=0; i<row; i++){
		A[i] = new int[colum];
		for(int j=0; j<colum; j++){
			cout << "Phan tu [" << i << "," << j << "] = ";
			cin >> A[i][j];
		}
	}
	return A;
}
void AddArray(int **A, int **B, int row, int colum){
	for(int i=0; i<row; i++)
		for(int j=0; j<colum; j++)
			A[i][j]+=B[i][j];
	return;
}
void DisplayArray(int **A, int row, int colum){
	for(int i=0; i<row; i++){
		for(int j=0; j<colum; j++)
			cout << A[i][j] << " ";
		cout << endl; // Xu�ng d�ng
	}
return;
}
void DeleteArray(int **A, int row){
	for(int i=0; i<row; i++)
		delete [] A[i];
	delete [] A;
	return;
}

int main(){
	//clrscr();
	int **A =NULL, **B=NULL, row, colum;
	cout << "So dong: ";
	cin >> row;
	cout << "So cot: ";
	cin >> colum;
/* Khoi tao c�c ma tr�n */
	cout << "Khoi tao ma tran A:" << endl;
	A = InitArray(row, colum);
	cout << "Khoi tao ma tran B:" << endl;
	B = InitArray(row, colum);
// hien thi ma tran A, B
	cout << "Ma tran A:" << endl;
	DisplayArray(A, row, colum);
	cout << "Ma tran B:" << endl;
	DisplayArray(B, row, colum);
// Cong 2 ma tr�n
	AddArray(A, B, row, colum);
// hi�n thi ma tran kq
	cout << "A + B = " << endl;
	DisplayArray(A, row, colum);
// Giai phong bo nho
	DeleteArray(A, row);
	DeleteArray(B, row);
	return 0;
}

