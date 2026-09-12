#include <iostream>
#include <conio.h>
#include <winsock2.h>
#include <string>
#include "titleScreen.cpp"
using namespace std;
#pragma comment(lib, "ws2_32.lib")
#define BUFFER_SIZE 4096
int main()
{
    title();
    WSADATA wsaData;
    SOCKET listenSocket = INVALID_SOCKET;
    SOCKET clientSocket = INVALID_SOCKET;
    sockaddr_in serverAddr, clientAddr; //struct to save all server configurations
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
    int l = sizeof(clientAddr);
    while(1){
        clientSocket = accept(listenSocket, (sockaddr*)&clientAddr, &l);
        if (clientSocket == INVALID_SOCKET) {
            cerr << "Accept failed: " << WSAGetLastError() <<endl;
            continue;
        }
        char buffer[BUFFER_SIZE] = {0};
        int bytes = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
        if(bytes > 0){
            cout << "\n--- Received Request ---\n" << buffer <<endl;
            string htmlContent = 
                "<!DOCTYPE html>"
                "<html><head><title>Winsock HTTP Server</title></head>"
                "<body><h1>Hello from C++ Winsock Server!</h1>"
                "<p>This page was served by a raw C++ socket server.</p></body></html>";
            string httpResponse = 
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: " + to_string(htmlContent.length()) + "\r\n"
                "Connection: close\r\n\r\n" + htmlContent;
            /*
                HTTP/1.1: Protocol version being used.
                200: Numeric status code indicating success.
                OK: Human-readable explanation of the status code.

                Metadata headers : 
                following the file is a text or HTML file, it's length is fla, and inform the browser that conncetion will be closed after sending this data,
                The first \r\n terminates the last header line
                The second \r\n creates a completely empty line

                < Content or Body (Payload) >
                The actual content being returned (HTML page, JSON, image file, plain text, etc).
            */

            send(clientSocket, httpResponse.c_str(), (int)(httpResponse.length()), 0);
        }
        closesocket(clientSocket);
    }
    closesocket(listenSocket);
    WSACleanup();
    getch();
    return EXIT_SUCCESS;
}