#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include<arpa/inet.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
//create a server socket
int server_socket;
server_socket=socket(AF_INET,SOCK_STREAM,0);
if(server_socket>=-1)
printf("\nSocket created Successfully.");
//create a address for the socket
struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
//Specify port to which we look for connection to
server_address.sin_port=htons(9000);
//Specify the actual address that is IP address
server_address.sin_addr.s_addr=INADDR_ANY;

//bind the socket to specified IP and Port
int b=bind(server_socket,(struct sockaddr*) &server_address,sizeof(server_address));
if(b>0)
printf("\nBind Successfull");

//To listen for connections we use listen function
int k=listen(server_socket,5);
if(k!=-1)
printf("\nListen Successfull");

int client_socket;
client_socket=accept(server_socket,NULL,NULL);
if(client_socket!=-1)
printf("\nConnection Successfull");

//send the message
char server_message[256];
for(int i=0;i<20;i++)
server_message[i]='\0';

printf("\nEnter a message: ");
scanf("%[^\n]%*c",server_message);

send(client_socket,server_message,sizeof(server_message),0);

//close the socket
close(server_socket);

return 0;
}
