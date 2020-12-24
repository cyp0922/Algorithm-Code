#include<iostream>
#include<string>
using namespace std;

int main(){
	
	int num,input;
	scanf("%d",&num);
	
	for(int x=0; x<num; x++){
		scanf("%d",&input);

		int div = 10;
		
		while(div < input){
			
			if(input % div>=5*div/10){
				input = input - input % div + div;
				div = div*10;
			}
			else{
				input = input - input % div;
				div = div*10;
			}
		}
		
	
		cout << input <<endl;
	}
	
}

