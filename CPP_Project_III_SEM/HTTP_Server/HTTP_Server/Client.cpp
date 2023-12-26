#include<iostream>
#include<string>
#include<cstring>
#include<ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void main(){
    string ip_address = "10.1.187.69" // My IP address is added
    int port_number = 54000; // Some random number given

    // Initialize the WinSock

    WSAData data;
    WORD ver = MAKEWORD(2, 2);
    int wsResult = WSAStartup(ver, &data);

    if(wsResult != 0){
        cerr << "Can't start Winsock, Error #" << wsResult << endl;
        return;
    }

    // Create a Socket

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == INVALID_SOCKET) cerr << "Can't create socket, Error #" << WSAGetLastError() << endl; return;

    // Fill in a hint structure

    sockadder_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address.c_str(), &hint.sin_addr);

    // Connect to server

    int connResult = cinnect(sock, (sockaddr*)&hint, sizeof(hint));
    if(connResult == SOCKET_ERROR){
        cerr << "Can't connect to the server, Error #" << WSAGetLastError() << endl; return;
        closesocket(sock);
        WSACleanup();
        return;
    }

    // Do-while loop to send and recieve data

    char buffer[4096];
    string UserInput;

    do{
        // Promt te user any text messages

        cout << "> ";
        getline(cin, UserInput);

        // Send the text message

        int send_result = send(sock, UserInput.c_str(), UserInput.size()+1, 0);
        if(send_result != SOCKET_ERROR){

            // Wait for the response

            ZeroMemory(buffer, 4096);
            int bytesRecieved = recv(sock, bufer, 4096, 0);
            if(bytesRecieved > 0){

                // Echo response to the Console

                cout << "SERVER> " << string(buffer, 0, bytesRecieved) << endl;
            }
        }
    } while(UserInput.size()>0);

    // Shutting down the connection

    closesocket(sock);
    WSACleanup();
}