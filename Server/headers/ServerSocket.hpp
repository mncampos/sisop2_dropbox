#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

#include "../../Common/Socket.hpp"

class ServerSocket : public Socket {
    public:
    ServerSocket(int port);
    bool bind();
    bool listen(int backlog = 5);
    bool accept();
    int getClientSocketFd();


    private:
    int clientSocketFd;
    int port;

};

#endif