// Example program
#include <iostream>
#include <string>
#include<vector>
using namespace std;
bool isPrime(int n);

vector<int> koo(int x)
{ vector<int> tra;
   int a=2;
   int v=0;
   
   while(v<x)
   { if(isPrime(a))
     {tra.push_back(a);
       v++;
     }
     a++;
}
return tra;
}

bool isPrime(int n)
{ 
    if(n==2||n==3||n==5||n==7)
    return true;
    
    else
  {  if((n%2!=0)&&(n%3!=0)&&(n%5!=0)&&(n%7!=0))
       return true;
       
       else return false;
       
  }
  
  
    
}

int main()
{
  vector<int> man=koo(3);
  for(int i=0;i<man.size();i++)
    cout<<man[i]<<" ";
    
    return 0;
}
