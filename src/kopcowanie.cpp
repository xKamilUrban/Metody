#include "kopcowanie.hpp"
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <chrono>
using namespace std;

void swap(int A[],int B[]){
	int k=*A;
	A=B;
	B=A;
}

double logarytm(
   double x
);

void stworz(int A[], int n){
	//wyznaczamy najnizszy poziom drzewa
	int k=ceil(log2(n+1));	//liczba poziomow
	int start=0;			//wspolrzedna pierwszego elementu najnizszego poziomu
	if(k>1){
		for(int i=0;i<k-1;i++){
			start+=pow(2,i);
		}
	}
	int end=n-1;				//wspolrzedna ostatniego elementu najnizszego poziomu
	int dz_1=start;
	int dz_2=start+1;
	int rodzic;
	while(k>1){
		start=dz_1;
		while(dz_1<n){
			rodzic=dz_1-pow(2,k-2);
			if(A[dz_2]>A[dz_1] and dz_2<n){
				if(A[dz_2]>A[rodzic]){
					swap(A[dz_2],A[rodzic]);
				}
			}
			else{
				if(A[dz_1]>A[rodzic]){
					swap(A[dz_1],A[rodzic]);
				}
			}
			dz_1++;
			dz_2++;
		}
		//petla sie konczy przchodzimy do wyzszego poziomu
		dz_1=start-pow(2,k-2);;
		dz_2=dz_1+1;
		k--;
	}
}

void napraw_kopiec(int A[], int n){
	//naprawa kopca metoda top-down
	int rodzic=0;
	int dz_1=1;
	int dz_2=2;
	int ile=1; //ilosc rodzicow na danym poziomie (maksymalna)
	int k=1; //ktory poziom rodzicow rozwazamy
	//na kazdym i-tym poziomie jest 2^(i-1) rodzicow (poza ostatnim poziomem)
	while(dz_1<n){
		for(int i=0;i<=ile;i++){
			if(A[dz_2]>A[dz_1] and dz_2<n){
				if(A[dz_2]>A[rodzic]){
					swap(A[dz_2],A[rodzic]);
				}
			}
			else{
				if(A[dz_1]>A[rodzic] and dz_1<n){
					swap(A[dz_1],A[rodzic]);
				}
			}
			rodzic++;
			dz_1+=2;
			dz_2+=2;
		}
		ile+=pow(2,k-1);
		k++;
	}

}

void sortowanie(int A[],int n){
	stworz(A,n);
	napraw_kopiec(A,n);
	for(int i=0;i<n-1;i++){
		swap(A[0],A[n-1-i]);
		napraw_kopiec(A,n-i-1);
	}
}

//tablica domyslnie jest w porzadku malejacym
//funkcja do odwracania

void odwroc(int A[],int n){
	for(int i=0; i<n/2;i++){
		swap(A[i],A[n-i-1]);
	}
}

