#include<iostream>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
int main(){
	int client;
	int server;
	int portNum=1500;
	bool isExit=false;
	int bufSize=1024;
	char buffer[bufSize];
	struct sockaddr_in server_addr;
	socklen_t size;
	//init socket
	client=socket(AF_INET,SOCK_STREAM,0);//se crea el socket 
	if(client<0){//Verificamos si el se realizo la conexion  
		cout<<"Error establishing connection."<<endl;
		exit(1);
	}
	cout<<"Server Socket connection create..."<<endl;//Si si se creo se imprime texto 
	if(bind(client,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
		cout<<"Error binding socket..."<<endl;
		exit(1);
	}
	size=sizeof(server_addr);
	cout<<"looking for clients..."<<endl;
	listen(client,1);
	server=accept(client,(struct sockaddr*)&server_addr,&size);
	if(server<0){
		cout<<"Error on accepting... "<<endl;
		exit(1);
	}
	while(server>0){
		strcpy(buffer,"Server conneted...\n");
		send(server,buffer,bufSize,0);
		cout<<"Connected with client..."<<endl;
		cout<<"Enter # to end the connection"<<endl;
		cout<<"Client: ";
		do{
			recv(server,buffer,bufSize,0);
			cout<<"buffer"<<" ";
			if(*buffer=='#'){//accediendo al valor que almacena que almacena la direccion
				*buffer='*';
				isExit=true;
			}
		}while(*buffer!='*');
		cout<<"Client: ";
		do{
			recv(server,buffer,bufSize,0);
			cout<<buffer<<" ";
			if(*buffer=='#'){
				*buffer=='*';
				isExit=true;
			}while(*buffer!='*');
			
		}
	}while(*buffer!='*');
	cout<<"Client: ";
	do{
		recv(server,buffer,bufSize,0);
		cout<<buffer<<" ";
		if(*buffer=='#'){
			*buffer=='*';
			isExit=true;
		}while ()
	}
	cout<<"Connection terminated..."<<endl;
	cout<<"Goodbye ..."<<endl;
	isExit
		
	
	return 0;
}
