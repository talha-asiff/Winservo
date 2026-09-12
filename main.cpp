#include <iostream>
#include <conio.h>
#include <winsock2.h>
#include <string>
#include "titleScreen.cpp"
using namespace std;
#pragma comment(lib, "ws2_32.lib")
int main()
{
    WSADATA wsaData;
    SOCKET listenSocket = INVALID_SOCKET;
    SOCKET clientSocket = INVALID_SOCKET;
    try{
        if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
		    throw runtime_error("Error : " + to_string(WSAGetLastError()));
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    title();
    getch();
}