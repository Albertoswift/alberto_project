#include <iostream>
using namespace std;

// implementing the dynamic List ADT using Linked List

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

class List{

	private:
		Node *headPtr;
	
	public:
		List(){
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
		
		
		void insert(int data){
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			Node* prevNodePtr = headPtr;
			
			while (currentNodePtr != 0){
				prevNodePtr = currentNodePtr;
				currentNodePtr = currentNodePtr->getNextNodePtr();
			}
			
			Node* newNodePtr = new Node();
			newNodePtr->setData(data);
			newNodePtr->setNextNodePtr(0);
			prevNodePtr->setNextNodePtr(newNodePtr);						
			
		}
		
		void insertAtIndex(int insertIndex, int data){
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			Node* prevNodePtr = headPtr;
			
			int index = 0;
			
			while (currentNodePtr != 0){
				
				if (index == insertIndex)
					break;
				
				prevNodePtr = currentNodePtr;
				currentNodePtr = currentNodePtr->getNextNodePtr();
				index++;
			}
			
			Node* newNodePtr = new Node();
			newNodePtr->setData(data);
			newNodePtr->setNextNodePtr(currentNodePtr);
			prevNodePtr->setNextNodePtr(newNodePtr);	
			
		}
		
		
		int read(int readIndex){
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			Node* prevNodePtr = headPtr;
			int index = 0;
			
			while (currentNodePtr != 0){
			
				if (index == readIndex)
					return currentNodePtr->getData();
				
				prevNodePtr = currentNodePtr;
				currentNodePtr = currentNodePtr->getNextNodePtr();
				
				index++;
				
			}
			
			return -1; // an invalid value indicating 
						// index is out of range
			
		}
		
		void modifyElement(int modifyIndex, int data){
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			Node* prevNodePtr = headPtr;
			int index = 0;
			
			while (currentNodePtr != 0){
			
				if (index == modifyIndex){
					currentNodePtr->setData(data);
					return;
				}
				
				prevNodePtr = currentNodePtr;
				currentNodePtr = currentNodePtr->getNextNodePtr();
				
				index++;
			}
			
			
		}
			
		
		void deleteElementAtIndex(int deleteIndex){	
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			Node* prevNodePtr = headPtr;
			Node* nextNodePtr = headPtr;
			int index = 0;
			
			while (currentNodePtr != 0){
			
				if (index == deleteIndex){
					nextNodePtr = currentNodePtr->getNextNodePtr();
					break;				
				}
				
				prevNodePtr = currentNodePtr;
				currentNodePtr = currentNodePtr->getNextNodePtr();				
				
				index++;
			}
			
			prevNodePtr->setNextNodePtr(nextNodePtr);
		
		}
		
		
		void deleteElement(int deleteData){
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			Node* prevNodePtr = headPtr;
			Node* nextNodePtr = headPtr;
			
			while (currentNodePtr != 0){
			
				if (currentNodePtr->getData() == deleteData){
					nextNodePtr = currentNodePtr->getNextNodePtr();
					break;				
				}
				
				prevNodePtr = currentNodePtr;
				currentNodePtr = currentNodePtr->getNextNodePtr();				
				
			}
			
			prevNodePtr->setNextNodePtr(nextNodePtr);
		
		}
		
		
		void IterativePrint(){
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			
			while (currentNodePtr != 0){
				cout << currentNodePtr->getData() << " ";
				currentNodePtr = currentNodePtr->getNextNodePtr();
			}
				
			cout << endl;
			
		}
		
		
		
		void constructSequence(int upperBound){
			
			Node* firstNodePtr = headPtr->getNextNodePtr();
			Node* secondNodePtr = firstNodePtr->getNextNodePtr();
		    
			while(secondNodePtr->getData()<upperBound)
			{
				int x =secondNodePtr->getData()+firstNodePtr->getData();
				if(x>upperBound)
				{
					break;
				}
				this->insert(x);
				firstNodePtr=secondNodePtr;
				secondNodePtr=secondNodePtr->getNextNodePtr();
				
			}
			// complete the code to construct a singly linked list that has the elements of the 
			// Fibonacci sequence less than or equal to the upperBound
			
			
			
						
			
		}
		
		
		
};

int main(){

	List FibonacciList;
	
	FibonacciList.insert(0);
	FibonacciList.insert(1);
	
	int upperBoundFibonacciValue;
	cout << "Enter the upper bound for the sequence: ";
	cin >> upperBoundFibonacciValue;
	
	FibonacciList.constructSequence(upperBoundFibonacciValue);
	
	
	
	FibonacciList.IterativePrint();
	
return 0;
}
