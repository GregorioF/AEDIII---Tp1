#include <iostream>


using namespace std;

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

struct AzulAct{
	int value;
	bool valido;
	AzulAct(){valido = false;}
	AzulAct(int v){ value = v; valido = true;}
	AzulAct( AzulAct * otro){
		value = otro->value;
		valido= otro->valido;
	}

};

struct Entry{
	bool rojo;
	bool azul;
	bool sinPintar;
	int value;
	Entry(){

	}
	Entry( int n ){
		sinPintar=true;
		rojo = false;
		azul = false;
		value= n;
	}
};

void reiniciarPosicion(Entry & b_i){
	b_i.rojo=false;
	b_i.azul = false;
	b_i.sinPintar= false;
}

int contarSinPintar(Entry b[], int n){
	int res =0 ;
	for(int i =0 ; i < n; i ++){
		if(b[i].sinPintar==true) res ++;
	}
	return res;
}

void mayorSubSecuencia(int x, int n, Entry b [], RojoAct ra, AzulAct aa, int & res, int sinPintarAct){
	if(res != 0 ){
		if(x == n){
			if(res==-1 || sinPintarAct < res){
				res = sinPintarAct;
			}
		}

		// probar si puede ser Rojo
		reiniciarPosicion(b[x]);
		if(ra.valido == false || ra.value < b[x].value){
			b[x].rojo=true;
			mayorSubSecuencia(x+1, n, b, RojoAct( b[x].value), AzulAct(&aa), res, sinPintarAct );
		}
		reiniciarPosicion(b[x]);
		//probar si puede ser Azul
		if(aa.valido == false || aa.value > b[x].value){
			b[x].azul = true;
			mayorSubSecuencia(x+1, n, b, RojoAct(&ra), AzulAct( b[x].value ), res, sinPintarAct  );
		} 
		reiniciarPosicion(b[x]);
		//probar si sin pintar es mejor
		if(res == -1 || res > (sinPintarAct +1) ){
			b[x].sinPintar=true;
			sinPintarAct++;
			mayorSubSecuencia(x+1, n, b, RojoAct(&ra), AzulAct(&aa), res,sinPintarAct );
		}
		else return;
	
	}
}

int main(){

	int n; cin >> n;
	Entry b [n]; 
	int aux;
	for(int i =0 ; i < n; i ++){
		cin >> aux ;
		b[i]=Entry(aux);
	}

	Entry mejorSolucion [n];
	int res = -1;

	RojoAct ra= RojoAct();
	AzulAct aa = AzulAct();

	mayorSubSecuencia(0, n, b, ra, aa, res, 0);
	/*
	cout << "Rojo: [";
	for(int i = 0; i < n; i ++){
		if(mejorSolucion[i].rojo == true)cout << mejorSolucion[i].value <<", ";
	}
	cout << "]" <<endl;

	cout << "Azul: [";
	for(int i = 0; i < n; i ++){
		if(mejorSolucion[i].azul == true)cout << mejorSolucion[i].value <<", ";
	}
	cout << "]" <<endl;*/

	cout << res <<endl;



	return 0 ;
}