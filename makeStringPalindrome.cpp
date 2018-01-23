// Example program
#include <iostream>
#include <string>
using namespace std;
bool palin(string:: iterator low, string:: iterator high)
{ while(low<high)
 {if(*low !=*high)
   return false;
   high--;
   low++;
}
 return true;
}

int possibpalin(string vim)
{ int low=0;
  int high=vim.size()-1;
  while(low<high)
  {  if(vim[low]==vim[high])
     { low++;
      high--;
     }
     else
     { if(palin(vim.begin()+low+1,vim.begin()+high))
        return low;
        if(palin(vim.begin()+low,vim.begin()+high-1))
        return high;
        return -1;
     }
  }
  return -2;
}


int main()
{
  string tra="abeaba";
  if(possibpalin(tra)==-1)
   cout<<"not possible palindrome"<<endl;
   else if(possibpalin(tra)==-2)
   cout<<"already a palindrome"<<endl;
   else
   cout<<"Becomes a palindrome after removing element at index "<<possibpalin(tra)<<endl;
   
   return 0;
}
