#include<iostream>
#include<conio.h>

using namespace std;
int main(){
	
    
	
	for(int i=0;i<256;i++){
		for(int j=7;j>=0;j--){
			if(((i>>j)&1)==1){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	
		cout<<" "<<endl;
	}
	
	getch();
	return 0;
}
