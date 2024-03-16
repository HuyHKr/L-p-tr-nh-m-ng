#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
//./ <port> <filelog>
int main(int argc,char* argv[]){
    int listener = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(listener == -1){
        perror("socket() failed: ");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    int port;
    sscanf(argv[1],"%d",&port);
    printf("Port: %d\n",port);
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //client addr
    struct sockaddr_in client_addr;
    int addr_length = sizeof(client_addr);
    if(bind(listener,(struct sockaddr*)&addr,sizeof(addr))){
        perror("Bind() failed: ");
        exit(1);
    }
    if(listen(listener,10)){
        perror("Listen() failed: ");
        exit(1);
    }

    int client = accept(listener,(struct sockaddr*)&client_addr,&addr_length);
    
    //doc du lieu
    char mssv[2048],hoten[2048],ngaysinh[2048];
    double cpa;

    //doc mssv
    int leng_mssv; read(client,&leng_mssv,sizeof(int));
    read(client,mssv,leng_mssv);
    mssv[leng_mssv]=0;
   
    //doc hoten
    int leng_hoten; read(client,&leng_hoten,sizeof(int));
    read(client,hoten,leng_hoten);
    hoten[leng_hoten]=0;

    //doc ngay sinh
    int leng_ngaysinh;  read(client,&leng_ngaysinh,sizeof(int));
    read(client,ngaysinh,leng_ngaysinh);
    ngaysinh[leng_ngaysinh]=0;

    //doc cpa
    read(client,&cpa,sizeof(double));
    printf("I'm recv: %s, %s, %s, %.2f\n",mssv,hoten,ngaysinh,cpa);

    
    char *caddr = inet_ntoa(client_addr.sin_addr);
    FILE *f = fopen(argv[2],"a");
    time_t now = time(NULL);
    struct tm *mytime = localtime(&now);
    //ip nam-thang-ngay gio:phut:giay mssv hoten ngaysinh cpa
    fprintf(f,"%s %d-%d-%d %d:%d:%d %s %s %s %.2f\n",caddr,mytime->tm_year+1900,mytime->tm_mon,mytime->tm_mday,mytime->tm_hour,mytime->tm_min,mytime->tm_sec,mssv,hoten,ngaysinh,cpa);
    printf("%s %d-%d-%d %d:%d:%d %s %s %s %.2f\n",caddr,mytime->tm_year+1900,mytime->tm_mon,mytime->tm_mday,mytime->tm_hour,mytime->tm_min,mytime->tm_sec,mssv,hoten,ngaysinh,cpa);

    close(client);
    close(listener);
}