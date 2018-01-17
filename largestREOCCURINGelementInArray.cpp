// Example program
#include <iostream>
#include <string>
#include<vector>
using namespace std;
int freq(vector<int> &koo)
{ int n=koo.size();
  int k=n;
  for(int i=0;i<n;i++)
  
  koo[koo[i]%k]+=k;
  
  int max=koo[0];
  int largest=0;
  
  for(int i=1;i<n;i++)
  {  if(koo[i]>max)
     {max=koo[i];
      largest=i;
     }
  }
  return largest;
}

int main()
{
  int n;
  cout<<"Enter the mnumber of elements in the array"<<endl;
  cin>>n;
  vector<int> arr;
  cout<<"Enter Elements"<<endl;
  for(int i=0;i<n;i++)
  { int a;
   cin>>a;
   arr.push_back(a);
  }
  
  int saa=freq(arr);
  cout<<saa<<endl;
  return 0;
}
