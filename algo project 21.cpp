#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<vector>
using namespace std;

void bubble(vector<int> &koo)
{
	int n=koo.size();
	for(int i=0;i<n-1;i++)
	{
		bool didswap=false;
		for(int j=0;j<n-i-1;j++)
		{
			if(koo[j]>koo[j+1])
			{
				int a=koo[j];
				koo[j]=koo[j+1];
				koo[j+1]=a;
				didswap=true;
			}
		}
	if(didswap==false)
	 return;
	}

}
	
void Insertion(vector<int> &koo)
{
	int n=koo.size();
	for(int i=1;i<n;i++)
	{
		int v=koo[i];
		int j=i-1;
		while(j>=0)
		{
			if(koo[j]<v)
			break;
			else
			koo[j+1]=koo[j];
			
			j=j-1;
		}
	   koo[j+1]=v;
	}
 return;
}

void print(vector<int> koo)
{
	int n=koo.size();
	for(int i=0;i<n;i++)
	{
		cout<<koo[i]<<" ";
	}
return;
}

int main()
{
	int n;
	int m;
	cout<<"enter the number of elements in the array"<<endl;
	cin>>n;
	cout<<"enter value for m"<<endl;
	cin>>m;
	
	
	int b=0;
	
	while(b<1000)
	{
	 vector<int>tra;
	 for(int i=0;i<n;i++)
	{
		int a=1+rand()%m;
		tra.push_back(a);
	}
	 
	 Insertion(tra);
	 
	
	 
	 b++;
   }
	
	
return 0;	
}

