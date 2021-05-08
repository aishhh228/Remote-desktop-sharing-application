#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "info.h"
#define MAX_CLIENTS 100
#define BUFFER_SZ 2048
int chat_client();
int file_client();
int portNum;

int getValueOfPort(void)
{
	int port = 0;

	printf("Please enter port number : ");
	scanf("%d", &port);
	return port;
}
int getChoice()
{
	int choice = -1;

	do {
		printf("Please enter choice : \n 1.Chatroom \n 2.File Transfer \n 3.Screen Sharing\n 4.Exit \n");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:	//printf("chatroom\n");
				chat_client();
				break;
			case 2:	//printf("file transfer\n");
				file_client();
				break;
			case 3://printf("screen sharing\n");
				screen();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 4);

}

int main()
{
	getChoice();

	return 0;

}
