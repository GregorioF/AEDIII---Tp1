#include <iostream>

using namespace std;

struct Entry{
	Entry(){ val = 0; esc = 0;}
	int val;
	int esc;
};

void actualizar(Entry b[], int x, int n){
		for(int i = x; i <n; i ++)
			if(b[i].val > b[x].val && b[i].esc >= b[x].esc) 
				b[x].esc = b[i].esc + 1;
		
}

void CompletarB(int a[], Entry b [], int n){
	b[n-1].val = a[n-1];
	b[n-1].esc = 0;
	
	for(int i = n-2 ; i >= 0; i-- ){
		b[i].val = a[i];
		actualizar(b,i,n);
	}
}

void mostrar(int a[], int n){
		cout << "[";
		for(int i =0 ; i < n-1; i++) cout << a[i] << ", ";
		cout << a[n-1] <<"]"<< endl;
}

void mayorSubSecuencia(int a [], int n){
	Entry b [n];
	CompletarB(a,b,n);
	for(int i = 0; i<n; i ++) cout << "("<<b[i].val<< "," << b[i].esc<< "), " ;
	int posEscMax = 0;
	int escMax = 0;
	int escAct = 0;
	for(int i = 0; i < n;  i ++ ){
			if(b[i].esc >= escMax){
				escMax = b[i].esc;
				posEscMax= i;
			}
	}
	int res [escMax+1];
	res[0] = b[posEscMax].val; 
	int resAct= 0;
	escAct = escMax - 1;
	
	
	for(int i = posEscMax+1; i < n; i ++){
		if(b[i].esc == escAct && b[i].val > res[resAct]){
			res [resAct + 1 ] = b[i].val;
			resAct ++ ;
			escAct -=1;
		}
	}
	mostrar(res, escMax+1);		
}


int main(){
	int n ; cin >> n;
	int a [n]; 
	for(int i = 0; i < n; i++) cin >> a[i];
	mayorSubSecuencia(a,n);
	
	
	return 0 ;
}
