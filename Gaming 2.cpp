#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>
using namespace std;

// implementing the dynamic List ADT using Linked List
// operations to be implemented: read, Modify, delete, isEmpty, insert, countElements

int main(){


	
	srand(time(NULL));
	
	int Value;
	int win=0;
   	int loss=0;
  bool tagn=false; 
cout<<"Enter 20 numbers from 1 to 100 "<<endl;

  int b;
  do{
  	int a=rand() % 100;
	for (int i = 0; i < 20; i++){
		cin>>Value;
		
	cout<<"your number is "<<Value<<endl;
	if(a==Value)
	{
		win++;
		tagn=true;
		cout<<"Congratulations, you have won"<<endl;
		break;
	}
	else {
			cout<<" Hard luck, Try again"<<endl;
            loss++;
		  }
	}
cout<<"Correct number is "<<a<<endl;
cout<<"Enter 1 to play again"<<endl;
cout<<"Enter 2 to quit"<<endl;	

cin>>b;

} while(b==1);
cout<<"You won "<<win<<endl;
cout<<"You Lost "<<loss<<endl;
 
  	
return 0;
}
