#include "..\\Header Files\UDP_Client.h"

/*
* @author Arushi Rai
*/

UDP_Client::UDP_Client(string address, int port) {
	buffer = new Buffer("UDP Send Buffer", BUFFER_SIZE);
	PORT = port;
	char* temp = (char*)address.c_str();
	memcpy(recipientAddr, temp, sizeof(recipientAddr));
	setup();
}

//ic
void UDP_Client::setup() {
	//binds socket and sets udp server address    
	if ((udp_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("cannot create socket");
    }

    struct sockaddr_in myaddr;
    
    bindSocket();
    struct hostent *hp;     /* host information */
    char *host = "localhost";
    hp = gethostbyname(host);
    //initializes the servaddr struct
    memset((char*)&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	memcpy((void *)&servaddr.sin_addr, hp->h_addr_list[0], hp->h_length);
}

void UDP_Client::addToSendBuffer(string message) {
	if (!validate(message)) //if the data fails the validation, then don't send 
		return;
	Datum temp = Datum(message, "std::string target", "UDP Protocol");
	timestamp(&temp, true);
	buffer.push(temp); 
}
    
void UDP_Client::send() {
	Datum data;
	data = empty();
	char* message = (char*) data.getSendable().c_str();
	if (sendto(udp_socket, message, strlen(message), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("sendto failed");
	return;
}

void UDP_Client::bindSocket (int s, struct sockaddr_in* myaddr) {
   memset((char *)&myaddr, 0, sizeof(myaddr));
    
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY); //IP address
    myaddr.sin_port = htons(8934); //socket
    if((bind(udp_socket, (struct sockaddr*)&myaddr, sizeof(myaddr))) < 0)
        perror("cannot bind");  
}
//ic
bool UDP_Client::validate(string data) {
	bool validation = true; //change default to false after receiving data format

	return validation;
}

//ic
Datum UDP_Client::empty() {
	Datum data = buffer.pop();
	timestamp(&data, false);

	return data;
}

void UDP_Client::timestamp(Datum* data, bool add) {
	/*string time;

	if (add)
		time = "; ASB: "; //stands for added to send buffer
	else
		time = "; ESB: "; //stands for emptied from send buffer

	//time += get time here
	time += ";"
	*data += time; */
}


