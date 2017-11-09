#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv)	{
	int master_socket = socket(
							   PF_INET, /* IPv4*/
							   SOCK_STREAM, /* TCP */
							   IPPROTO_TCP);

	struct sockaddr_in sock_addr;
	sock_addr.sin_family = PF_INET;
	sock_addr.sin_port = htons(12345);
	sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(master_socket, (struct sockaddr*)&sock_addr,
		 sizeof(sock_addr));

	listen(master_socket, SOMAXCONN);
		int slave_socket = accept(master_socket, 0, 0);

	while(1)	{
		int recv_buffer[256] = {[0] = 0};
	   	recv(slave_socket, recv_buffer, 256, MSG_NOSIGNAL);
		printf("Vladimir: %s\n", recv_buffer);
		
		char *send_buffer;
		printf("Nikita: ");
		gets(send_buffer);
		send(slave_socket, send_buffer, strlen(send_buffer),
			 MSG_NOSIGNAL);
	}
	
	return 0;
}
