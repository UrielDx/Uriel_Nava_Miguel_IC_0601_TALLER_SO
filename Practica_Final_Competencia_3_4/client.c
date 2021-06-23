#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080
#define MAX 100
   
int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[MAX];
    char A[MAX] = {0}, B[MAX] = {0};
    
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n-->  Socket creation error!! \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\n--> Invalid address/ Address not supported!! \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n--> Connection Failed!!! \n");
        return -1;
    }
    printf("\t---------------------------------\n");
    printf("\tIngrese el primer numero: ");
    scanf("%s", A);
    send(sock, A, strlen(A), MAX);
    printf("\t--> Primer numero enviado al servidor\n");
    printf("\tIngrese el segundo numero: ");
    scanf("%s", B);
    send(sock, B, strlen(B), MAX);
    printf("\t--> Segundo numero enviado al servidor\n");
    printf("\t--> Recibiendo resultado del servidor...\n");
    valread = read( sock , buffer, 100);
    printf("\tEl resultado de la suma es --> %s\n", buffer);
    printf("\t---------------------------------\n");
    
    return 0;
}
