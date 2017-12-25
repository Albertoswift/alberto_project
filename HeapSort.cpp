#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void rearrangeHeapArray(int *array, int arraySize, int index){
	// max heap construction
	
	int leftChildIndex = 2*index + 1;
	int rightChildIndex = 2*index + 2;
	
	if (leftChildIndex >= arraySize)
		return;
	
	
	if (rightChildIndex >= arraySize){
		
		if (array[index] > array[leftChildIndex]){
			int temp = array[index];
			array[index] = array[leftChildIndex];
			array[leftChildIndex] = temp;
		}
			
		return;
	}
	
	
	if (array[index] <= array[leftChildIndex] && array[index] <=  array[rightChildIndex])
		return;
	
	int maxIndex = leftChildIndex;
	if (array[leftChildIndex] > array[rightChildIndex])
		maxIndex = rightChildIndex;
	
	int temp = array[maxIndex];
	array[maxIndex] = array[index];
	array[index] = temp;
	
	rearrangeHeapArray(array, arraySize, maxIndex);
		
}


int main(){
	
	int arraySize;
	
	cout << "Enter array size: ";
	cin >> arraySize;
	
	int array[arraySize];


	

	int a;
	for (int i = 0; i < arraySize; i++){
		//cout << "Enter element at index " << i << " : ";
		//cin >> array[i];
		cout<<"Enter Array Elements"<<endl;
		cin>>a;
		array[i] = a;
		cout << array[i] << " ";
	}
	
	cout << endl;
	
	
	//max. heap construction
	
	for (int index = (arraySize/2)-1; index  >= 0; index--){
		
		rearrangeHeapArray(array, arraySize, index);
			
	}
	
	
	cout << "After Heap construction..." << endl;
	for (int index = 0; index < arraySize; index++)
		cout  << array[index] << " ";
	
	cout << endl;
	
	// Heap sort
	
	for (int iterationIndex = 0; iterationIndex < arraySize; iterationIndex++){
		
		int temp = array[0];
		array[0] = array[arraySize-1-iterationIndex];
		array[arraySize-1-iterationIndex] = temp;
		
		rearrangeHeapArray(array, arraySize-1-iterationIndex, 0);
		
		cout << "Iteration " << iterationIndex << " : ";
		for (int index = 0; index < arraySize; index++)
			cout << array[index] << " ";
		
		cout << endl;
		
	}
	
	cout << "After heap sort...";
	for (int index = 0; index < arraySize; index++)
		cout << array[index] << " ";
	
	cout << endl;
	
return 0;
}
