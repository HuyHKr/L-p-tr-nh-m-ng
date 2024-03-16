//server <cong> <file from server> <file from client>
//file dai toi da 2048 byte :
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char*argv[]){
    int listener = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    int port;
    sscanf(argv[1],"%d",&port);
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(bind(listener,(struct sockaddr*)&addr,sizeof(addr))){
        perror("Bind() error: ");
        exit(1);
    }

    if(listen(listener,5)){
        perror("Listen() error: ");
        exit(1);
    }

    int client = accept(listener,NULL,NULL);
    puts("accept");
    //docfile chua cau xin chao
    FILE *fromFile = fopen(argv[2],"rb");
    char buffer[2048];
    int ret = fread(buffer,1,sizeof(buffer),fromFile);
    buffer[ret]  = 0;

    //gui den client
    write(client,&buffer,ret);

    //nhan tu client
    int _ret = read(client,buffer,sizeof(buffer));
    FILE *tofile = fopen(argv[3],"wb");
    fwrite(buffer,1,_ret,tofile);
    fclose(tofile);
    fclose(fromFile);
    close(client);
    close(listener);
    
}