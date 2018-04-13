#include <iostream>
#include <fstream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <cstring> // for string tokenizer and c-style string processing
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
  
  
  int countList(){
   
   Node* currentNodePtr = headPtr->getNextNodePtr();
   int countElements = 0;
   
   while (currentNodePtr != 0){
    currentNodePtr = currentNodePtr->getNextNodePtr();
    countElements++;
   }   
   
   return countElements;
   
  }
  
  
  
  
};

class Graph{
 
 private:
  int numNodes;
  List* adjacencyList;
  int* pushOrder;
  int* popOrder;
  int lastPushNumber = 0;  
  int lastPopNumber = 0;
  
  
  
 public:
 
  Graph(int n){
   numNodes = n;
   adjacencyList = new List[numNodes];
   pushOrder = new int[numNodes];
   popOrder = new int[numNodes];
  }
  
  
  void addEdge(int u, int v){
   adjacencyList[u].insert(v);
   adjacencyList[v].insert(u);
  }
 
  
  List getNeighborList(int id){
   return adjacencyList[id];
  }
 
 
  int getDegree(int id){
   return adjacencyList[id].countList();
  }
 
  
  int getPushOrder(int id){
   return pushOrder[id];
  }
  
  int getPopOrder(int id){
   return popOrder[id];
  }
 
  void resetLastPopNumber(){
   lastPopNumber = 0;
  }
 
  void resetLastPushNumber(){
   lastPushNumber = 0;
  } 
 
  void RunDFSRecur(int visitedNodeID, bool* visitedNodes){
   
   visitedNodes[visitedNodeID] = true;
   pushOrder[visitedNodeID] = ++lastPushNumber;
   
   
   int neighborListSize = adjacencyList[visitedNodeID].countList();
   
   for (int index = 0; index < neighborListSize; index++){
    
    int neighbID = adjacencyList[visitedNodeID].read(index);
    
    if (!visitedNodes[neighbID]){
     RunDFSRecur(neighbID, visitedNodes);
    }
    
    
   }
   
   popOrder[visitedNodeID] = ++lastPopNumber;
   
  }
  
   
  
  bool RunDFSRecursive(int rootNodeID){
   
   bool* visitedNodes = new bool[numNodes];
   for (int id = 0; id < numNodes; id++){
    visitedNodes[id] = false;
    pushOrder[id] = -1;
    popOrder[id] = -1;
   }
   
   RunDFSRecur(rootNodeID, visitedNodes);
   resetLastPushNumber();
   resetLastPopNumber();
    
  }
 
 
 
 
};

int main(){
 string graphEdgesFilename;
 cout << "Enter the file name for the edges of the graph: ";
 cin >> graphEdgesFilename;
 
 int numNodes;
 cout << "Enter number of nodes: ";
 cin >> numNodes;
 
 
 Graph graph(numNodes);
 
 ifstream graphEdgeFileReader(graphEdgesFilename);
 
 if (!graphEdgeFileReader){
  cout << "File cannot be opened!! ";
  return 0;
 }
 int numCharsPerLine = 25;
 
 char *line = new char[numCharsPerLine]; 
 // '25' is the maximum number of characters per line
 
 graphEdgeFileReader.getline(line, numCharsPerLine, '\n'); 
 // '\n' is the delimiting character to stop reading the line
  
 while (graphEdgeFileReader){
   
  char* cptr = strtok(line, " ");
  
  string uNodeToken(cptr);
  int uNodeID = stoi(uNodeToken);
  
  cptr = strtok(NULL, " ");
  
  string vNodeToken(cptr);
  int vNodeID = stoi(vNodeToken);
  
  graph.addEdge(uNodeID, vNodeID);
  
  
  graphEdgeFileReader.getline(line, numCharsPerLine, '\n'); 
  
 }
 
 
 cout << endl;
 
 graph.RunDFSRecursive(0);
 
 
 for(int i=0;i<numNodes;i++)
 {
  cout<<"Push and Pop Order of "<<i<<":"<<graph.getPushOrder(i)<<" "<<graph.getPopOrder(i)<<endl;
 }
 
 // Add code to print the push and pop order of the vertices
      cout<<"Directed Graph Is "<<endl;
 
  bool visitedNodes[numNodes];
 for(int i=0;i<numNodes;i++)
    {
     
  List adjacencyList =graph.getNeighborList(i);
  int neighborListSize = adjacencyList.countList();
     
     visitedNodes[i] = true;
  for(int a=0;a<neighborListSize;a++)
     {
      int n=adjacencyList.read(a);
   if (!visitedNodes[n])
   {
     if(graph.getPopOrder(i)>graph.getPopOrder(n))
         cout<<i<<"->"<<n<<endl;
        else
        cout<<n<<"->"<<i<<endl;
  }
     
 }
 
}
   

 // Add code to assign and print the directions to the edges such that the resulting directed graph is a DAG
 
  
  
 
 
return 0;
}
