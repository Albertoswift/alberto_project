#include <iostream>
#include <string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
 string man;
 string vim;

 cout<<"Enter the row STRING:"<<endl;
 cin>>man;
 cout<<"Enter the column STRING"<<endl;

 cin>>vim;

 int a=man.size();
 int b= vim.size();

 int v=b;
 int m=a;
 vector<int> Nya;
 int tra[m+1][v+1];
 for (int i=0; i<=m; i++)
 {
 for (int j=0; j<=v; j++)
 {
 if(i == 0 || j == 0)
 tra[i][j] = 0;

 else if (man[i-1] == vim[j-1])
 { Nya.push_back(man[i-1]);
 tra[i][j] = tra[i-1][j-1] + 1;
 }
 else
 tra[i][j] = max(tra[i-1][j], tra[i][j-1]);
 }
 }


 cout<<"Dynamic Programming table is"<<endl;

 for(int i=0;i<=m;i++)
{
 for(int j=0;j<=v;j++)
 {
 cout<<tra[i][j]<<" ";
  }
 cout<<endl;
}
cout<<"Longest Common Subsequence is of Length "<<tra[m][v]<<endl;

return 0;
