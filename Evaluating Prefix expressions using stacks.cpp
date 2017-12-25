#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<sstream>
using namespace std;


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
		Node *headPtr;
	
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
			
		
		int peek(){
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			Node* prevNodePtr = headPtr;
			
			if (currentNodePtr == 0){
				return -1000000; // stack is empty
			}
			
			while (currentNodePtr->getNextNodePtr() != 0)
				currentNodePtr = currentNodePtr->getNextNodePtr();
			
			return currentNodePtr->getData();
			
		}

			
		
		int pop(){	
			
			Node* currentNodePtr = headPtr->getNextNodePtr();
			Node* prevNodePtr = headPtr;
			
			if (currentNodePtr == 0){
				return -1000000; // stack is empty
			}
			
			while (currentNodePtr->getNextNodePtr() != 0){
				
				prevNodePtr = currentNodePtr;
				currentNodePtr = currentNodePtr->getNextNodePtr();				

			}
			
			prevNodePtr->setNextNodePtr(0);
			return currentNodePtr->getData();
		
		}
		

		
};

int main(){

	Stack stack;

	string expression;
	
	cout << "Enter the expression to evaluate: ";
	getline(cin, expression);
	reverse(expression.begin(),expression.end());
	char* expressionArray = new char[expression.length()+1];
	strcpy(expressionArray, expression.c_str());
	
	char* cptr = strtok(expressionArray, ", ");
	
	while (cptr != 0){
		
		string token(cptr);
		
		bool isOperator = false;
		
		if ( (token.compare("*") == 0) || (token.compare("/") == 0) || (token.compare("+") == 0) || (token.compare("-") == 0) )
			isOperator = true;
		
		if (!isOperator){
			int val = stoi(token);
			stack.push(val);
		}
		
		
		if (isOperator){
			
			int leftOperand = stack.pop();
			int rightOperand = stack.pop();
			
			if (token.compare("*") == 0){
				int result = leftOperand * rightOperand;
				cout << "intermediate result: " << leftOperand << "*" << rightOperand << "=" << result << endl;
				stack.push(result);
			}			
			else if (token.compare("/") == 0){
				int result = leftOperand / rightOperand;
				cout << "intermediate result: " << leftOperand << "/" << rightOperand << "=" << result << endl;
				stack.push(result);
			}
			else if (token.compare("+") == 0){
				int result = leftOperand + rightOperand;
				cout << "intermediate result: " << leftOperand << "+" << rightOperand << "=" << result << endl;
				stack.push(result);
			}
			else if (token.compare("-") == 0){
				int result = leftOperand - rightOperand;
				cout << "intermediate result: " << leftOperand << "-" << rightOperand << "=" << result << endl;
				stack.push(result);
			}
			
		}
		
		
		cptr = strtok(NULL, ", ");
	}
	
	cout << "final result: " << stack.pop() << endl;
	
	
return 0;
}
