#include <iostream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <chrono>
#include "kopcowanie.hpp"
using namespace std;


int main() {
	int n;
	cout<<"Podaj dlugosc tablicy:";
	cin>>n;
	cout<<"Podaj przedzial w ktorym zawarte beda elementy tablicy"<<endl;
	int g;
	int d;
	cout<<"Dolny kres przedzialu:";
	cin>>d;
	cout<<"Gorny kres przedzialu:";
	cin>>g;
	cout<<"Porzadek rosnacy-0, malejacy-1"<<endl;
	int l;
	cin>>l;
	srand( time( NULL ) );

	int* A = new int[n];
	int s=g-d+1;
	for(int i=0;i<n;i++){
		A[i]=rand() % s + d;
	}

	if(l==0){
		odwroc(A,n);
	}
	cout<<"Losowo wygenerowana tablica"<<endl;
	cout<<"[";
	for(int i=0;i<n-1;i++){
		cout<<A[i]<<",";
	}
	cout<<A[n-1]<<"]"<<endl;

	cout<<"Posortowana tablica:"<<endl;

    // Rozpoczęcie pomiaru czasu dzialania algorytmu sortowania przez kopcowanie
    auto start = chrono::high_resolution_clock::now();

	sortowanie(A,n);


    // Zakończenie pomiaru czasu
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;


	cout<<"[";
	for(int i=0;i<n-1;i++){
		cout<<A[i]<<",";
	}
	cout<<A[n-1]<<"]"<<endl;
	cout << "Czas wykonania algorytmu sortowania przez kopcowanie: " << duration.count() << " sekund" << endl;
	return 0;
}
