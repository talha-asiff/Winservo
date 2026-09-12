#include <iostream>
#include <conio.h>
#include <winsock2.h>
#include <string>
#include "titleScreen.cpp"
using namespace std;
#pragma comment(lib, "ws2_32.lib")
int main()
{
    title();
    WSADATA wsaData;
    SOCKET listenSocket = INVALID_SOCKET;
    SOCKET clientSocket = INVALID_SOCKET;
    sockaddr_in serverAddr; //struct to save all server configurations
    try{
        if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
		    throw runtime_error("Error : " + to_string(WSAGetLastError()));
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    // IPPROTO_TCP = 6 : TCP protocol |||| If we put 0 here system automatically choose dafault protocol for that port
    if (listenSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed: " << WSAGetLastError() <<endl;
        WSACleanup();
        return INVALID_SOCKET;
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Listen on all network interfaces
    serverAddr.sin_port = htons(5555);
    if ( bind(listenSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR ) {
        /*
        Binding server config. with listenSocket
        sockaddr typecast to make it generic
        */
        cerr << "Bind failed: " << WSAGetLastError() <<endl;
        closesocket(listenSocket);
        WSACleanup();
        return INVALID_SOCKET;
    }
    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
        //SOMAXCONN here bcz idk how many clients r gonna send requests all at once
        cerr << "Listen failed: " << WSAGetLastError() <<endl;
        closesocket(listenSocket);
        WSACleanup();
        return INVALID_SOCKET;
    }
    cout << "server running..."<<endl;
    getch();
}