 #include<iostream>
 #include<stack>
 
 using namespace std;
 
int main(){
	
	int num;
	string input;
	stack<char>array;

	scanf("%d",&num);
	int ok[num];
	
	for(int i=0; i<num; i++){
		cin >> input;
		
					
		while(!array.empty()){
			array.pop();
 		}
 		
		for(int j=0; j<input.length(); j++){
			if(input[j] == '('){
				array.push(1);  
				
			}
			else {
				if(array.empty()){
					array.push(1); 
					break;
				}
				array.pop();
			}
		}
		if(array.empty()){
			ok[i] = 1;
		}
		else{
			ok[i] = 0;
			
		}
	}
	
	for(int i=0; i<num; i++){
		if(ok[i]){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
} 
	
	

