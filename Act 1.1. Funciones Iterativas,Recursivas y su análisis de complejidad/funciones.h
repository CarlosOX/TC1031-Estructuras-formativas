#include <iostream>
#include <stdlib.h>


using namespace std;

class Funciones{
	public:
		int sumaIterativa(int);
		int sumaRecursiva(int);
		int sumaDirecta(int);
		
};


int Funciones::sumaIterativa(int n){
	int acum=0;
	
	for(int i=0;i<=n;i++){
		acum=acum+i;
		
	}
	return acum;
}

int Funciones::sumaRecursiva(int n){
	if(n<=0){
		return 0;
		
	}else {
		return n+sumaRecursiva(n-1);
	}
}


int Funciones::sumaDirecta(int n){
	int suma;
	suma=n*(n+1)/2;
	return suma;	
}





