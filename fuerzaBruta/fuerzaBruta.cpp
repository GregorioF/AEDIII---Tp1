#include <iostream>
#include <fstream>
#include <time.h> 
#include <ctime>
#include <ratio>
#include <chrono>  

using namespace std;
using namespace chrono;

bool esSolucion(int* a, int * b, int n, int & cantidadSinPintar){
	int cr = -1;
	int ca = -1;
	for(int i = 0; i < n; i ++){
		if(b[i] == 0) cantidadSinPintar +=1;
		else{
			if(b[i] == 2 && (cr < a[i] ||  cr ==-1)){
				cr = a[i];
			}
			else if(b[i] == 1 && (ca == -1 || ca > a[i])){
				ca = a[i];
			}
			else return false;
		}
	}
	return true;
}

void mostrar(int* a, int* b, int n){
	cout << "[";
	for(int i = 0; i < n; i ++){

		string s;
		if(b[i]>= 1) s = b[i] == 1 ? "A":"R";
		else s = "SP";

		cout<< "("<<a[i]<<", " << s << ") ";


	}
	cout <<"]" <<endl;


}
void pintar (int * a, int * b, int & res, int x, int n){
	if(x == n){
		int cantidadSinPintar = 0;
	//	mostrar(a,b,n);
		if(esSolucion(a,b,n, cantidadSinPintar)){
			if(res == -1  || cantidadSinPintar < res){
				res = cantidadSinPintar;
			} 
		}
	}

	else {
			b[x]= 2;
			pintar(a,b,res,x+1,n);
		

			b[x]=1;
			pintar(a,b,res,x+1,n);
		

		
			b[x] = 0;
			pintar(a,b,res,x+1,n);
		

	}



}

int main(){

	fstream e ("entradas.txt", ios::in | ios::out);
	fstream s ("salidas.txt", ios::in | ios::out);

		for(int i = 0; i < 1500; i ++){	
		int n ; e >> n;

		int a [n];
		int b [n];
		for(int i = 0; i < n; i ++){
			e >> a[i];
			b[i] = -1;
		}
		int res = -1;
		

		std::chrono::high_resolution_clock::time_point t1;
		t1 = std::chrono::high_resolution_clock::now();
		
		pintar(a,b,res, 0, n);
 		
 		std::chrono::high_resolution_clock::time_point t2;
 		t2 = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> time_span;
		time_span = std::chrono::duration_cast<duration<double>>(t2 - t1);


		s << time_span.count() <<endl;

	}
	e.close();
	s.close();



	return 0;
}