// Example program
#include <iostream>
#include <string>
using namespace std;
int quote(int Dividend, int Divisor)
{  int a=0;
   while(Divisor<=Dividend)
   { Dividend=Dividend-Divisor;
     a++;
   }
   return a;
}


int main()
{ 
    int tra=quote(33,6);
    cout<<"The quotient is "<<tra<<endl;
    return 0;
  
}
