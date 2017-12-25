#include<iostream>
#include<stdlib.h> //srand, rand
#include<time.h> //clock_t, clock, CLOCKS_PER_SEC
using namespace std;

// implementing a doubly linked list


class Node{
	
	private:
		int data;
		Node* nextNodePtr;
		
		
	public:
		Node(){}
		
		void setData(int d){
			data = d;
		}
		
		int getData(){
			return data;
		}
		
		void setNextNodePtr(Node* nodePtr){
				nextNodePtr = nodePtr;
		}	
		
		Node* getNextNodePtr(){
			return nextNodePtr;
		}
		
	
		
};

class Stack{

	private:
		Node* headPtr;
	
	
	public:
		Stack(){
			headPtr = new Node();
		
			headPtr->setNextNodePtr(0);
			
		}
	
		Node* getHeadPtr(){
			return headPtr;
		}
		
	
		
		
		bool isEmpty(){
			
			if (headPtr->getNextNodePtr() == 0)
				return true;
			
			return false;
		}
		
		
		void push(int data){
			
			Node* newNodePtr = new Node();
			newNodePtr->setData(data);
			newNodePtr->setNextNodePtr(0);
			
			Node* lastNodePtr = headPtr->getNextNodePtr();
			
			if (lastNodePtr == 0){
				
				headPtr->setNextNodePtr(newNodePtr);
				newNodePtr->setNextNodePtr(0);
				
			}
			else{
				
				headPtr->setNextNodePtr(newNodePtr);
				newNodePtr->setNextNodePtr(lastNodePtr);
				
			}
			
			
			
		}		

		
		int pop(){	
			
			Node* lastNodePtr =headPtr->getNextNodePtr();
			Node* prevNodePtr = 0;
			
			int poppedData = -100000; //empty stack
			
			if (lastNodePtr != 0){
				prevNodePtr = lastNodePtr->getNextNodePtr();
				poppedData = lastNodePtr->getData();				
			}
			else
				return poppedData;
			
			if (prevNodePtr != 0){
				
				headPtr->setNextNodePtr(prevNodePtr);
			}
			else{
				headPtr->setNextNodePtr(0);
				
			}

			return poppedData;			
			
		}
		
		
		int peek(){
			
			Node* lastNodePtr = headPtr->getNextNodePtr();
			
			if (lastNodePtr != 0)
				return lastNodePtr->getData();				
			else	
				return -100000; //  empty stack
				
		}
		
		
		void IterativePrint(){
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			
			while (currentNodePtr != 0){
				cout << currentNodePtr->getData() << " ";
				currentNodePtr = currentNodePtr->getNextNodePtr();
			}
				
			cout << endl;		
			
		}
		
		
	
		
	
		
		
};

int main()
{

	int arraySize;
	
	cout << "Enter the number of elements you want to analyze: ";
	cin >> arraySize;
	
	Stack stack; // Create an empty stack
	
	srand(time(NULL));
	
	int maxValue;
	
	cout << "Enter the maximum value for an element: ";
	cin >> maxValue;

	int array[arraySize];
	
	for (int i = 0; i < arraySize; i++){
		
		int value = rand() % maxValue;
		cout << value << " ";
		array[i] = value;
	}
	
	cout << endl;
		stack.push(array[0]);

	for(int a = 1; a < arraySize; a++)
	{
		
		while(stack.peek()<array[a]&&!stack.isEmpty())
		{
			int b=stack.pop();
			cout<<b<<"  "<<array[a]<<endl;
		}
	stack.push(array[a]);
	}
	while(!stack.isEmpty())
	{
		int value=stack.pop();
		cout<<value<<"   "<<"-1"<<endl;
	}

	// Implement a theta(n) algorithm using Stack to find the next greater element of each 
	// element in the array and print them
	
	
return 0;
}


