Protocol::Protocol(int port) {
	name = " ";
	targetPort = port;
}

std::string Protocol::getName() {
	return name;
}
