#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

#include <ws2tcpip.h>
#define MAXBUFLEN 512
#define PORT 4950

char RecvBuff[MAXBUFLEN];

int main(int argc, char *argv[]){

  WSADATA wsaData;
  SOCKET conn_socket,comm_socket;
  SOCKET comunicacion;
  struct sockaddr_in server;
  struct sockaddr_in client;
  struct hostent *hp;
  int resp,stsize;
  
  //Inicializamos la DLL de sockets
  resp=WSAStartup(MAKEWORD(1,0),&wsaData);
  if(resp){
    printf("Error al inicializar socket\n");
    getchar();return resp;
  }
  
  //Obtenemos la IP que usará nuestro servidor... 
  // en este caso localhost indica nuestra propia máquina...
  hp=(struct hostent *)gethostbyname("localhost");

  if(!hp){
    printf("No se ha encontrado servidor...\n");
    getchar();WSACleanup();return WSAGetLastError();
  }

  // Creamos el socket...
  conn_socket=socket(AF_INET,SOCK_DGRAM, 0);
  if(conn_socket==INVALID_SOCKET) {
    printf("Error al crear socket\n");
    getchar();WSACleanup();return WSAGetLastError();
  }
  
  memset(&server, 0, sizeof(server)) ;
  memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
  server.sin_family = hp->h_addrtype;
  server.sin_port = htons(PORT);

  // Asociamos ip y puerto al socket
  resp=bind(conn_socket, (struct sockaddr *)&server, sizeof(server));
  if(resp==SOCKET_ERROR){
    printf("Error al asociar puerto e ip al socket\n");
    closesocket(conn_socket);WSACleanup();
    getchar();return WSAGetLastError();
  }

  // Se reciben los datos
  stsize = sizeof(struct sockaddr);
  resp=recvfrom(conn_socket, RecvBuff, MAXBUFLEN, 0, (struct sockaddr *)&client, &stsize);
  if(resp==SOCKET_ERROR){ 
    printf("Error al recivir datos...\n");
    closesocket(conn_socket);WSACleanup();
    getchar();return WSAGetLastError();
  }
  
  // Se visualiza lo recibido 
  RecvBuff[resp] = '\0';
  printf("Paquete proveniente de: %s\n",inet_ntoa(client.sin_addr));
  printf("Longitud del paquete en bytes: %d\n",resp);
  printf("El paquete contiene:\n\n%s\n",RecvBuff);
  
  getchar();
  // Cerramos el socket de comunicacion
  closesocket(conn_socket);
  
  // Cerramos liberia winsock
  WSACleanup();
  return (EXIT_SUCCESS);
}
