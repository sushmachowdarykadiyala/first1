#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define PORT 8001

using namespace std;


int main()
{
	//create a socket
	
	int sockfd= socket(AF_INET, SOCK_STREAM,0);
	if(sockfd==-1)
	{
		perror("socket not created");
		exit(0);
	}
	
	//cout<<"hi1"<<sockfd<<endl;
	struct sockaddr_in s;
	
	s.sin_family= AF_INET;
	s.sin_port= htons(PORT);
	s.sin_addr.s_addr= INADDR_ANY;
	
	
	//binding the socket
	if(bind(sockfd, (struct sockaddr *)&s ,sizeof(struct sockaddr_in) ) == -1)
	{
		perror("bind error");
		exit(0);
	}
	
	//cout<<"hi2"<<endl;
	
	
	if(listen(sockfd, 10) ==-1)
	{
		perror("error on listen function call");
		exit(0);
	}
	
	//cout<<"hi3"<<endl;
	
	int addrlen= sizeof(struct sockaddr_in) ;
	
	
	int socket= accept(sockfd, (struct sockaddr *)&s, (socklen_t *)&addrlen);
	
	if(socket==-1)
	{
		perror("error on accept function call");
		exit(0);
	}
	
	
	cout<<"socket connection established"<<endl;
	
	
	char buff[50]= "I am server.......";
	send(socket, buff, 50, 0);
	cout<<"msg sent to client:\t"<<buff<<endl;
	
	
	
	char msg[50];
	
	recv(socket, msg, 50,0);
	
	cout<<"msg received from client:\t"<<msg<<endl;
	
	
	
	
	return 0;
	
	
}
