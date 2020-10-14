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
//create a socket
int network_socket;
network_socket=socket(AF_INET,SOCK_STREAM,0);
if(network_socket>-1)
printf("\nClient Socket created successfully.");
//create a address for the socket
struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
//Specify port to which we connect to
server_address.sin_port=htons(9000);
//Specify the actual address that is IP address
//This will be the real server address that we will be connecting to
server_address.sin_addr.s_addr=INADDR_ANY;


int connection_status=connect(network_socket,(struct sockaddr*) &server_address,sizeof(server_address));
//If connection_status is 0 then connection successful else if -1 then some error.
if(connection_status==-1)
{
printf("\nThere was an error making a connection to the remote socket\n\n");
return 0;
}
else if(connection_status>=0)
printf("\nConnection Successfull");
//TO recieve data froms server
char server_response[256];

for(int i=0;i<20;i++)
server_response[i]='\0';

recv(network_socket,&server_response,sizeof(server_response),0);

//print out the server's response

printf("\nMessage Received\nThe server sent the data: %s\n",server_response);

//closing the socket
close(network_socket);

return 0;

}
