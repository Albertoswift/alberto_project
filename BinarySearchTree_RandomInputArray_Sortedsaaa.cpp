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
	
	
		void constructBSTree(int *array){
			
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
	
	int FindLCA(int vim,int tra)
	{
		
		while(rootNodeID!=-1)
		{
		
			int c=arrayOfBTNodes[rootNodeID].getData();
		
			if(c>=arrayOfBTNodes[vim].getData() && c<=arrayOfBTNodes[tra].getData())
			{
			return c;
			}
		
		
			else if(c<arrayOfBTNodes[vim].getData() && c<arrayOfBTNodes[tra].getData())
			{
			rootNodeID=arrayOfBTNodes[rootNodeID].getRightChildID();
			}
		
			else
			{
			rootNodeID=arrayOfBTNodes[rootNodeID].getLeftChildID();
			}
		
			
		}
	
	
	
	
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
	
	cout << "Inorder traversal: ";
	bsTree.PrintInOrderTraversal();
	
	cout << "Leaf nodes: ";
	bsTree.printLeafNodes();
	
	cout<<"Enter the two node ids to find least common ancestor"<<endl;
	int a,b;
	cin>>a>>b;
	
	int leftSearchNode=a;
	int  rightSearchNode=b;
	
	if(array[a]>array[b])
	{
		int leftSearchNode=b;
		int  rightSearchNode=a;
	}
	
	
	int d=bsTree.FindLCA(leftSearchNode,rightSearchNode);
	
	cout<<"Least Common ancestor of "<<array[leftSearchNode]<<" and "<<array[rightSearchNode]<<" is "<<d<<endl;
	
	
	
	
	
	return 0;
}
