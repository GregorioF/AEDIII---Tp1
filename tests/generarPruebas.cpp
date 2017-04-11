#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
	system("touch entradas.txt");
  fstream f ("entradas.txt", ios::in | ios::out);
  int n;

  srand (time(NULL));

  /* generate secret number between 1 and 10: */
 
 for(int i = 0 ; i < 500 ; i++){
      n = 10;
      f << n;
      f << "\n";
      for(int k = 0; k < n; k ++){
        int aux = rand() % 100 ;
        f << aux;
        f << " ";
      }
      f << "\n";
  }

 for(int i = 0 ; i < 500 ; i++){
      n = 15;
      f << n;
      f << "\n";
      for(int k = 0; k < n; k ++){
        int aux = rand() % 100 ;
        f << aux;
        f << " ";
      }
      f << "\n";
  }

  for(int i = 0 ; i < 500 ; i++){
      n = 25;
      f << n;
      f << "\n";
      for(int k = 0; k < n; k ++){
        int aux = rand() % 100 ;
        f << aux;
        f << " ";
      }
      f << "\n";
  }



  f.close();

  puts ("Congratulations!");
  return 0;
}