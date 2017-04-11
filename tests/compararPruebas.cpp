#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
  fstream s1( "salidas1.txt", ios::in);
  fstream s2( "salidas2.txt", ios::in);
  int casos = 0;
  int numS1;
  int numS2;
  for(int i = 0; i < 150; i ++){
    s1 >> numS1;
    s2 >> numS2;
    bool b = numS1 == numS2 ;
    if( b == false){
      cout << "Fallo en el caso: " << i << endl;
      cout << "Res 1 fue : " << numS1 << endl;
      cout << "Res 2 fue : " << numS2 << endl;
      cout << "\n"; 
    }
  }

  cout << "Terminop, si no ves ningun otro texto felicidades ambos devolvieron lo mismo :)"<<endl;
  s1.close();
  s2.close();

  return 0;
}