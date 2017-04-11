#include <iostream>

using namespace std;
struct Entry{
	int value;
	int escR;
	int escA;
	int mejorArregloAzul;
	Entry(){value = 0;
		escR = 0;
		escA = 0;
		rojo = false;
		sinPintar= false;
		azul = false;
		mejorArregloAzul=0;
	}
	Entry(int v){
		value = v;
		escR = 0;
		escA=0;
		mejorArregloAzul=0;
		rojo = false;
		sinPintar= false;
		azul = false;
	}
	bool azul;
	bool rojo;
	bool sinPintar;
};

struct RojoAct{
	int value;
	bool valido;
	RojoAct(){valido = false;}
	RojoAct(int v){ value = v; valido = true;}
	RojoAct( RojoAct * otro){
		value = otro->value;
		valido= otro->valido;
	}

};

void actualizarRojo(Entry b[], int x, int n){
		for(int i = x; i <n; i ++)
			if(b[i].value > b[x].value && b[i].escR >= b[x].escR) 
				b[x].escR = b[i].escR + 1;
		
}

void CompletarEscRoja(Entry b [], int n){
	b[n-1].escR = 0;
	
	for(int i = n-2 ; i >= 0; i-- ){
		actualizarRojo(b,i,n);
	}
}

void actualizarAzul(Entry b[], int x, int n ){
	b[x].escA = 0;
	for(int i = 0; i < x; i++){
		if(b[i].value > b[x].value && b[i].escA >= b[x].escA && b[i].rojo == false)
			b[x].escA = b[i].escA + 1 ;
	}
}

void CompletarEscAzul(Entry a[], int n){
	a[0].escA = 0;
	for(int i  = 0; i <n; i ++){
		if(a[i].rojo != true)actualizarAzul(a,i,n);
		else a[i].escA = 0;
	}
}

int mayorEscAzul (Entry b [], int n , int escAct){
	int res = 0;
	for( int i = 0 ; i < n ; i ++){
		if(b[i].escA > res && b[i].escR == escAct && b[i].rojo != true) res = b[i].escA;
	}
	return res;
}


int cantNumerosSinPintar(Entry * b,  int n, int escMax)
{
	int escAct = escMax ;
	int res = 0;
	int ultimoRojo = -1;
	for(int k  = 0 ; k < n ; k ++ ){

		int mejorCandidato = -1;
		int mejorEscAzul = 0;
		
		for(int i = k; i < n ; i ++ ){
			if ( b[i].escR == escAct && b[i].value > ultimoRojo ){
				
				b[i].rojo = true;
				CompletarEscAzul(b, n);
				b[i].mejorArregloAzul = mayorEscAzul(b,n, escAct);
				
				if( b[i].mejorArregloAzul >= mejorEscAzul ){
					 mejorEscAzul = b[i].mejorArregloAzul;
					 mejorCandidato = i;
				}
				b[i].rojo = false;
			}
		}

		b[mejorCandidato].rojo = true;

		ultimoRojo = b[mejorCandidato].value;
		
		k = mejorCandidato+1;
		escAct --;
		if(escAct == -1){
			res = b[mejorCandidato].mejorArregloAzul;
			break;
		}

	}

	return n - res - escMax;	

}
int main(){

	int n; cin >> n;
	Entry a[n];
	for(int i = 0; i <n; i ++){
		cin >> a[i].value;
	}
	int res;


	CompletarEscRoja(a,n); 
	/*for(int i = 0; i <n; i ++) cout << "(" <<a[i].value<<", " <<a[i].esc << "), " ;
	cout << "\n";*/
	int escMax = a[0].escR;
	int escAMax = a[n-1].escA;
	for(int i = 0; i < n; i ++){
		if(a[i].escR > escMax ) escMax = a[i].escR;
	}

	RojoAct ra = RojoAct();
	res = cantNumerosSinPintar(a, n ,  escMax);

	CompletarEscAzul(a,n);
	for(int i = n-1; i >=0; i --){
		if(a[i].escA > escAMax  ) escAMax = a[i].escA;
	}

	int escAzulAct = escAMax;
	
	for(int i = n-1; i >= 0 ; i --){
		if(a[i].escA == escAzulAct && a[i].rojo != true){
		 	a[i].azul = true;
		 	escAzulAct --;
		}
	}
	for(int i =0 ; i< n ; i ++){
		cout<< "(" << a[i].escA <<", " <<a[i].value << "), ";
	}
	cout << "\n";

	cout << "[";
	for(int i = 0 ; i < n; i ++){
		string s ;
		if(a[i].rojo == true) s = "R";
		else if(a[i].azul == true) s= "A";
		else s= "SP";
		cout << "("<<a[i].value<<", " << s << "), ";
	}
	cout << "\n" <<endl;

	cout << res << endl;

	return 0 ;
}