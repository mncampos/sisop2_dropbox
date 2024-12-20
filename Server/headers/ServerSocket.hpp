#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

#include "../../Common/Socket.hpp"
#include <fstream>
#include <unordered_map>
#include <algorithm>

class ServerSocket : public Socket {
    public:
    ServerSocket(int port);
    bool bind();
    bool listen(int backlog = 5);
    int accept();

    void addClientSocket(std::string username, int socket);
    void sendSignal(std::string username, int signalCode, int excludedSocket); // See packet.hpp for codes
    void removeClientSocket(int socket);


    private:
    int port;
    std::unordered_map<std::string, std::vector<int>> clientSockets;

};

#endif