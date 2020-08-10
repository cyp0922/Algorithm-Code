#include<stdio.h>
#include<iostream>

using namespace std;

void quick(int* array, int start, int end){
	
	if(start >= end){
		return;
	}
	
	int key,left,right,temp;
	
	key = start;
	left = start+1;
	right = end;
	

	while(left <= right){
		
		while(array[left] < array[key]){
			left ++; 
		}
		
		while(right > start && array[right] > array[key]){
			right--;
		}
		
		if(left > right){
			temp = array[right];
			array[right] = array[key];
			array[key] = temp;
		}
		
		else{
			temp = array[right];
			array[right] = array[left];
			array[left] = temp;
		}
		
	}
	
	quick(array,start,right-1);
	quick(array,right+1,end);
	
}


int main(){
	
	int input,num;
	
	cin >> num;
	
	int array[num];
	
	for(int i =0; i<num; i++){
		cin >> input;
		array[i] = input; 
	}
	
	quick(array,0,num-1);

	
	for(int i =0; i<num; i++){
		printf("%d\n", array[i]);
	}
	
}
