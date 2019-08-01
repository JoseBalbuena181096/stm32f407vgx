#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include<windows.h>
#include<winsock2.h>
#include<ws2tcpip.h>
#include<iphlpapi.h>
#include<iostream>
#pragma comment(lib,"Ws2_32.lib")


using namespace std;
int main(){
	
	WSADATA wsaData;
	SOCKET server;


int iResult;

// Initialize Winsock
iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
if (iResult != 0) {
    printf("WSAStartup failed: %d\n", iResult);
    return 1;
return 0;
}
}
