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
			
		
		void deleteElement(int deleteData){
			
			// Modify the deleteElement member function to delete all occurrences of 'deleteData'
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			Node* prevNodePtr = headPtr;
			Node* nextNodePtr = headPtr;
			
			while (currentNodePtr != 0){
			
				if (currentNodePtr->getData() == deleteData){
					nextNodePtr = currentNodePtr->getNextNodePtr();
					prevNodePtr->setNextNodePtr(nextNodePtr);
					currentNodePtr=nextNodePtr;
					
					
				}
				else{
				
					prevNodePtr = currentNodePtr;
					currentNodePtr = currentNodePtr->getNextNodePtr();				
					
				}
				
			}
			
		
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

int main(){

	int listSize;
	
	cout << "Enter the number of elements you want to insert: ";
	cin >> listSize;
	
	List integerList; // Create an empty list
	
	for (int i = 0; i < listSize; i++){
		
		int value;
		cout << "Enter element # " << i << " : ";
		cin >> value;
		
		integerList.insertAtIndex(i, value);
	}
	
	cout << "Contents of the List: (before delete) ";
	integerList.IterativePrint();

	
	// to delete all occurrences of a particular data
	
	int deleteData;
	cout << "Enter the data to delete: ";
	cin >> deleteData;
	integerList.deleteElement(deleteData); // modify the deleteElement member function to delete 
											// all occurrences of 'deleteData'
	
	cout << "Contents of the List (after delete): ";
	integerList.IterativePrint();
	
return 0;
}
