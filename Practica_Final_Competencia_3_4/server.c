#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
#define MAX 100

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char A[MAX] = {0}, B[MAX] = {0};
    int An[MAX], Bn[MAX], res[MAX] = {0};
    int o, p, q;
    int tamA, tamB, len;
    char buffer[MAX] = {0};
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("--> socket fallido!!");
        exit(EXIT_FAILURE);
    }
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("--> bind failed!!");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("\t--> Esperando cliente\n");
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("\t---------------------------------\n");
    valread = read( new_socket , A, MAX);
    printf("\tPrimer numero recibido del cliente --> %s\n", A);
    valread = read( new_socket , B, MAX);
    printf("\tSegundo numero recibido del cliente --> %s\n", B);
    printf("\t---> Realizando suma...\n");
    printf("\t---> Enviando resultado a cliente...\n");
    printf("\t--------------------------------\n");
    
    tamA=strlen(A);
    tamB=strlen(B);

	if(tamA>=tamB){
		len=tamA+1;
	}else{
		len=tamB+1;
	}
    for(o=0; o<tamA; o++){
        An[o]=A[o]-48;
    }
    for(p=0; p<tamB; p++){
        Bn[p]=B[p]-48;
    }
    p=tamB-1, q=len-1;
    for(o=tamA-1; o>=0 && p>=0; o--){
        res[q]= An[o]+Bn[p];
        p--;
        q--;
    }
    for(o; o>=0; o--){
        res[q]=An[o];
        q--;
    }
    for(p; p>=0; p--){
        res[q]=Bn[p]; 
        p--;
	}
    for(q=len-1; q>0; q--){
        if(res[q]>9){
         	res[q]=res[q]%10;
            res[q-1] = res[q-1]+1;
        }
    }
    for(q=0; q<len; q++){
        buffer[q]=res[q]+48;
    }
    send(new_socket, buffer, strlen(buffer), MAX);
    return 0;
}
