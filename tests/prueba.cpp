#include <iostream>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */


using namespace std;

int main ()
{
  time_t timer;
  

  time(&timer);  /* get current time; same as: timer = time(NULL)  */

  //seconds = difftime(timer,mktime(&y2k));
	cout << timer<< endl;

  return 0;
}