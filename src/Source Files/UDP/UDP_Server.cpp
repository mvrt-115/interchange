#include "..\\Header Files\UDP_Server.h"

/*
* @author Arushi Rai
*/

UDP_Server::UDP_Server(string address, int port) {
    buffer = new Buffer("UDP Receive Buffer", BUFFER_SIZE);
    PORT = port;
    char* temp = (char*)address.c_str();
    memcpy(recipientAddr, temp, sizeof(recipientAddr));
    start();
}

void UDP_Server::start() {
    struct sockaddr_in myaddr; // our address 

    cout << "Test" << endl;
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("cannot create socket\n");
        return;
    }

    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myaddr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
        perror("bind failed");
        return;
    }
}

void UDP_Server::receive() {
    unsigned char buf[BUFFER_SIZE]; //temp receive buffer 
    int recvlen; //# bytes received

    recvlen = recvfrom(server_socket, buf, BUFFER_SIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
    if (recvlen > 0) {
        buf[recvlen] = 0;
        string data = reinterpret_cast<const char*>(buf);
        if (!validate(data))
    	return;

        Datum temp(data, "target", "UDP Protocol");
        timestamp(&temp, true);
        buffer.push(temp);
    }

    return;
}

//ic
bool UDP_Server::validate() {
    bool validation = true; //change default to false after receiving data format

    return validation;
}

string UDP_Server::empty() {
    Datum data = buffer.pop();
    timestamp(&data, false);

    return data;
}

//ic
void UDP_Server::timestamp(string* data, bool add) {
    /*string time;

    if (add)
	time = "; ARB: "; //stands for added to retrieve buffer
    else
	time = "; ERB: "; //stands for emptied from retrieve buffer

    //time += get time here
    time += ";"
    *data += time; */
}
