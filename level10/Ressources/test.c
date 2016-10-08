#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
	{
		return (0);
	}
	struct sockaddr_in server_addr;
	memset((void *)&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(6969);
	if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
	{
		return (0);
	}
	if (listen(sockfd, 255) == -1)
	{
		return (0);
	}
	int cfd;
	struct sockaddr csock;
	socklen_t mdr = sizeof(csock);
	while ((cfd = accept(sockfd, &csock, &mdr)) != -1)
	{
		char c;
		while (read(cfd, &c, 1) > 0)
			write(1, &c, 1);
	}
}
