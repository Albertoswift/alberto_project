// Example program
#include <iostream>
#include <string>
#include<stack>
using namespace std;
void subin(int x)
{
    stack<int> koo;
    while(x>0)
    { int vim=x%2;
      koo.push(vim);
       x/=2;
    }
     
     while(!koo.empty())
     { int a=koo.top();
        cout<<a;
        koo.pop();
     }
return;
}

int main()
{
    subin(8);
    return 0;
}
