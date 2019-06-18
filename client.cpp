#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define PORT 8001

using namespace std;


int main()
{
	//creating a socket
	int sockfd= socket(AF_INET, SOCK_STREAM,0);
	
	if(sockfd== -1)
	{
		perror("error in socket creation");
		exit(0);
	}
	
	
	
	struct sockaddr_in s;
	s.sin_family= AF_INET;
	s.sin_port= htons(PORT);
	s.sin_addr.s_addr= INADDR_ANY;
	
	//cout<<"hi1"<<endl;
	
	//connect a socket
	if(connect(sockfd,(sockaddr *) &s, sizeof(struct sockaddr_in))==-1 )
	{
		perror("error on connect function call");
		exit(0);
	}
	cout<<"socket connection established"<<endl;
	
	
	
	char buff[50]= "i am client.......";
	send(sockfd, buff, 50, 0);
	cout<<"msg sent to server:\t"<<buff<<endl;
	
	
	
	char msg[50];
	
	recv(sockfd, msg, 50,0);
	
	cout<<"msg received from server:\t"<< msg<<endl;
	
	
	
	return 0;
}
