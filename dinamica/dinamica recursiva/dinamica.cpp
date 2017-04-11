#include <iostream>

using namespace std;


int b [1000][1000][1000];

int min(int a, int b, int c){
	int res = a;
	res = res < b ? res : b;
	res = res < c ? res : c;
	return res;
}

int pintar(int a [],  int x, int n , int  ca, int cr){
	b[50][50][50] +=1;
	if(b[x][cr][ca] != -1) return b[x][cr][ca];
	else if(x == n){
		int res = a[x] > cr || a[x] < ca ? 0:1;
		b[x][cr][ca] = res;
		return res; 
	}
	else{
		int res1, res2,res3;
		
		if( ca ==  0 || a[x] < a[ca]){
			res1 = pintar(a,x+1,n,x,cr);
		}else{
			res1 = pintar(a,x+1, n, ca ,cr) +1;
		}

		if( cr ==  0 || a[x] > a[cr]){
			res2 = pintar(a,x+1,n, ca, x);
		}else{
			res2 = pintar(a,x+1,n, ca, cr) +1;
		}

		res3 = pintar(a,x+1,n,ca,cr)+1;

		int res = min(res1,res2,res3);

		b [x][ca][cr] = res;
		return res;
	}
}

int main(){
	int n ; cin >> n;
	int a [n+1];
	a[0] = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i]; 
	}
	for(int i = 0; i <= n; i ++) for(int k = 0; k <= n; k ++) for(int j = 0; j <= n; j++) b[i][k][j] = -1;

	int res = pintar(a,  1 , n, 0, 0 );

	cout << "res: " << res <<endl;
	cout << "llamadas a recursion: " << b[50][50][50]+1 << endl;

	return 0;
}