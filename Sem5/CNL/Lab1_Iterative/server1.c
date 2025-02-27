#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORTNO 10201
int main(){
    int sockfd,newsockfd,portno,clilen,n=1;
    struct sockaddr_in seraddr,cliaddr;
    int i,value;
    // create an unnamed socket for the server
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    //Name the socket
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr("172.16.57.167");
    seraddr.sin_port = htons(PORTNO);
    bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
    //Create a connection queue and wait for clients
    listen(sockfd,5);
    while (1) {
        char buf[1000];
        printf("server waiting");
        //Accept a connection
        clilen = sizeof(clilen);
        newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
        //Read and write to client on client_sockfd (Logic for problem mentioned here)
        n = read(newsockfd,buf,sizeof(buf));
        printf(" \nMessage from Client %s \n",buf);
        for(int i=0; i< strlen(buf); i++){
            buf[i]=buf[i]-4;
        }
        printf(" \nMessage from Client decrypted %s \n",buf);
        n = write(newsockfd,buf,sizeof(buf));
    }
}
