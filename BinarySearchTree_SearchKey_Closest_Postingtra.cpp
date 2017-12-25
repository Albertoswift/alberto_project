#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class BTNode{
	
	private:
		int nodeid;
		int data;
		int levelNum;
		BTNode* leftChildPtr;
		BTNode* rightChildPtr;
	
	public:
	
		BTNode(){}
		
		void setNodeId(int id){
			nodeid = id;
		}
	
		int getNodeId(){
			return nodeid;
		}
	
		void setData(int d){
			data = d;
		}
	
		int getData(){
			return data;
		}
	
		void setLevelNum(int level){
			levelNum = level;
		}
		
		int getLevelNum(){
			return levelNum;
		}
		
		void setLeftChildPtr(BTNode* ptr){
			leftChildPtr = ptr;
		}
	
		void setRightChildPtr(BTNode* ptr){
			rightChildPtr = ptr;
		}
	
		BTNode* getLeftChildPtr(){
			return leftChildPtr;
		}
	
		BTNode* getRightChildPtr(){
			return rightChildPtr;
		}
	
		int getLeftChildID(){
			if (leftChildPtr == 0)
				return -1;
			
			return leftChildPtr->getNodeId();
		}
		
		int getRightChildID(){
			if (rightChildPtr == 0)
				return -1;
			
			return rightChildPtr->getNodeId();
		}
};



class BinarySearchTree{
	
	private:
		int numNodes;
		BTNode* arrayOfBTNodes;
		int rootNodeID;
		
		
	public:
	
		BinarySearchTree(int n){
			numNodes = n;
			arrayOfBTNodes = new BTNode[numNodes];
			
			for (int index = 0; index < numNodes; index++){
				
				arrayOfBTNodes[index].setNodeId(index);
				arrayOfBTNodes[index].setLeftChildPtr(0);
				arrayOfBTNodes[index].setRightChildPtr(0);
				arrayOfBTNodes[index].setLevelNum(-1);
				
			}
		}
	
	
		void setLeftLink(int upstreamNodeID, int downstreamNodeID){
			arrayOfBTNodes[upstreamNodeID].setLeftChildPtr(&arrayOfBTNodes[downstreamNodeID]);
		}
		
		void setRightLink(int upstreamNodeID, int downstreamNodeID){
			arrayOfBTNodes[upstreamNodeID].setRightChildPtr(&arrayOfBTNodes[downstreamNodeID]);
		}	
	
	
		void selectionSort(int *array, int arraySize){
	
			for (int iterationNum = 0; iterationNum < arraySize-1; iterationNum++){
			
				int minIndex = iterationNum;
		
				for (int j = iterationNum+1; j < arraySize; j++){
			
					if (array[j] < array[minIndex])
						minIndex = j;
			
				}
		
				// swap array[minIndex] with array[iterationNum]
				int temp = array[minIndex];
				array[minIndex] = array[iterationNum];
				array[iterationNum] = temp;
		
			}
	
		}
	
		void constructBSTree(int* array){
			
			int leftIndex = 0;
			int rightIndex = numNodes-1;
			int middleIndex = (leftIndex + rightIndex)/2;
			
			rootNodeID = middleIndex;
			arrayOfBTNodes[middleIndex].setData(array[middleIndex]);
			
			ChainNodes(array, middleIndex, leftIndex, rightIndex);
			
		}
	
	
		void ChainNodes(int* array, int middleIndex, int leftIndex, int rightIndex){
			
			
			if (leftIndex < middleIndex){
				int rootIDLeftSubtree = (leftIndex + middleIndex-1)/2;
				setLeftLink(middleIndex, rootIDLeftSubtree);
				arrayOfBTNodes[rootIDLeftSubtree].setData(array[rootIDLeftSubtree]);
				ChainNodes(array, rootIDLeftSubtree, leftIndex, middleIndex-1);
			}
			
			
			if (rightIndex > middleIndex){
				int rootIDRightSubtree = (rightIndex + middleIndex + 1)/2;
				setRightLink(middleIndex, rootIDRightSubtree);
				arrayOfBTNodes[rootIDRightSubtree].setData(array[rootIDRightSubtree]);
				ChainNodes(array, rootIDRightSubtree, middleIndex+1, rightIndex);
			}
			
			
		}
	
	
		void printLeafNodes(){
			
			for (int id = 0; id < numNodes; id++){
				
				if (arrayOfBTNodes[id].getLeftChildPtr() == 0 && arrayOfBTNodes[id].getRightChildPtr() == 0)
					cout << arrayOfBTNodes[id].getData() << " ";
			}
			
			cout << endl;
		}
	
	
		void InOrderTraversal(int nodeid){
			
			if (nodeid == -1)
				return; 
			
			
			
			InOrderTraversal(arrayOfBTNodes[nodeid].getLeftChildID());
			cout << arrayOfBTNodes[nodeid].getData() << " ";
			InOrderTraversal(arrayOfBTNodes[nodeid].getRightChildID());
			
		}

		
		void PrintInOrderTraversal(){
			
			InOrderTraversal(rootNodeID);
			cout << endl;
			
		}
		
		
		int getKeyIndex(int searchKey){
			
			int searchNodeID = rootNodeID;
			
			while (searchNodeID != -1){
				
				if (searchKey == arrayOfBTNodes[searchNodeID].getData())
					return searchNodeID;
				else if (searchKey < arrayOfBTNodes[searchNodeID].getData())
					searchNodeID = arrayOfBTNodes[searchNodeID].getLeftChildID();
				else
					searchNodeID = arrayOfBTNodes[searchNodeID].getRightChildID();
	
			}
			
			return -1;

		}
		
		
		int getClosestKey(int testKey){
			
	
			int searchNodeID = rootNodeID;
			int getdifference;
			int closestkey;
			while (searchNodeID != -1){
				
				if (testKey == arrayOfBTNodes[searchNodeID].getData())
					return arrayOfBTNodes[searchNodeID].getData();
				     
				else if (testKey < arrayOfBTNodes[searchNodeID].getData())
					  {    
					        int c=arrayOfBTNodes[searchNodeID].getData();
						getdifference= abs(c-testKey);
					    
					searchNodeID = arrayOfBTNodes[searchNodeID].getLeftChildID();				           
						int d =arrayOfBTNodes[searchNodeID].getData();
						 int diff=abs(d-testKey);
						   if(diff<getdifference)
						   {
						   	  closestkey= d;
						   }
			}
				else
					 {    
					    int c=arrayOfBTNodes[searchNodeID].getData();
						getdifference= abs(c-testKey);
					    
						searchNodeID = arrayOfBTNodes[searchNodeID].getRightChildID();				           
						int f =arrayOfBTNodes[searchNodeID].getData();
						 int diff=abs(f-testKey);
						   if(diff<getdifference);
						   {
						   	  closestkey= f;
						   }
			
	
			}
		}
			return closestkey;

			// implement this function, starting to compare/search
			// from the rootNodeID
			

		}
	
};


	void selectionSort(int *array, int arraySize){
	
		for (int iterationNum = 0; iterationNum < arraySize-1; iterationNum++){
			
			int minIndex = iterationNum;
		
			for (int j = iterationNum+1; j < arraySize; j++){
			
				if (array[j] < array[minIndex])
					minIndex = j;
		
			}
		
			// swap array[minIndex] with array[iterationNum]
			int temp = array[minIndex];
			array[minIndex] = array[iterationNum];
			array[iterationNum] = temp;
		
		}
	
	}
	

int main(){
	
	int numElements;
	cout << "Enter the number of elements: ";
	cin >> numElements;
	
	int *array = new int[numElements];
			
	int maxValue;
	cout << "Enter the maximum value for an element: ";
	cin >> maxValue;
			
	srand(time(NULL));
			
	cout << "array generated: ";
			
	for (int index = 0; index < numElements; index++){
		array[index] = rand() % maxValue;
		cout << array[index] << " ";
	}			
			
	cout << endl;
			
	selectionSort(array, numElements);		
			
	BinarySearchTree bsTree(numElements);	
	bsTree.constructBSTree(array);
	
	int testKey;
	cout << "Enter a test key: ";
	cin >> testKey;
	
	int closestKey = bsTree.getClosestKey(testKey);
	cout << "Closest Key to " << testKey << " is: " << closestKey << endl;
	
	
	return 0;
}
