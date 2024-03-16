//viet tcp_client ket noi toi 1 may chu 
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
//./bai1client <ip> <port>
int main(int argc,char *argv[]){
    //tao socket
    int client = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    //tao cau truc dia chi
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    int PORT;
    sscanf(argv[2],"%d",&PORT);
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    //connect
    int ret = connect(client,(struct sockaddr*)&addr,sizeof(addr));
    if(ret==-1){
        perror("Khong ket noi duoc den serve: ");
        exit(1);
    }

    //write
    char msg[]="From Bai1 with <3";
    write(client,msg,strlen(msg));

    //read
    char in[2048];
    int _ret = read(client,in,sizeof(in));
    in[_ret] = 0;
    puts(in);
    close(client);

}