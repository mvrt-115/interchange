#include "..\\Header Files\UDP_Server.h"

/*
* @author Arushi Rai
*/

#include "udp_server.h"

/*
#define PORT			5789
#define BUFFER_LENGTH   64 //enter bytes
*/

UDP_Server::UDP_Server(	char recipientAddr[128]) {
	memcpy(this->recipientAddr, recipientAddr, sizeof(recipientAddr));
	start();
}

//ic
void UDP_Server::start() {
	//set up server here
		struct sockaddr_in myaddr;      /* our address */
        struct sockaddr_in remaddr;     /* remote address */
        socklen_t addrlen = sizeof(remaddr);            /* length of addresses */
        int recvlen;                    /* # bytes received */
        unsigned char buf[BUFSIZE];     /* receive buffer */

        /* create a UDP socket */

        if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
                perror("cannot create socket\n");
                return 0;
        }

        /* bind the socket to any valid IP address and a specific port */

        memset((char *)&myaddr, 0, sizeof(myaddr));
        myaddr.sin_family = AF_INET;
        myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        myaddr.sin_port = htons(PORT);

        if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
                perror("bind failed");
                return 0;
        }

        /* now loop, receiving data and printing what we received */
        for (;;) {
                recvlen = recvfrom(fd, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
                printf("received %d bytes\n", recvlen);
                if (recvlen > 0) {
                        buf[recvlen] = 0;
                        printf("received message: \"%s\"\n", buf);
                }
        }
        /* never exits */
	}


//ic
string UDP_Server::receive() {
	string data;
	//enter UDP code to receive

	if (!validate(data))
		return ;

	timestamp(&data, true);
	buffer.push_back(data);
	return;
}

//ic
bool UDP_Server::validate() {
	bool validation = true; //change default to false after receiving data format

	return validation;
}

string UDP_Server::empty() {
	string data = buffer.front();
	buffer.pop();
	timestamp(&data, false);

	return data;
}

void UDP_Server::timestamp(string* data, bool add) {
	string time;

	if (add)
		time = "; ARB: "; //stands for added to retrieve buffer
	else
		time = "; ERB: "; //stands for emptied from retrieve buffer

	//time += get time here
	time += ";"
	*data += time;
}

/*
sendto(s, buf, strlen(buf), 0, (struct sockaddr *)&remaddr, addrlen)
*/