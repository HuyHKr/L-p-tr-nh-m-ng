#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc,char*argv[]){
    int client = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(client==-1){
        perror("Socket() error: ");
        exit(1);
    }
    //tao cau truc dia chi
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    int port;
    sscanf(argv[1],"%d",&port);
    printf("Port: %d\n",port);
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //connect to server
    int ret = connect(client,(struct sockaddr*)&addr,sizeof(addr));
    if(ret==-1){
        perror("Connect Failed: ");
        exit(1);
    }
    printf("Connect successful!\n");

    //nhap va gui du lieu
    char mssv[2048],hoten[2048],ngaysinh[2048];
    double cpa;
    printf("\nMSSV: "); scanf("%s",mssv);
    int c = getchar();
    printf("\nHo va ten: "); 
    fgets(hoten,sizeof(hoten),stdin);hoten[strlen(hoten)-1]=0;
    printf("\nNgay sinh: "); fgets(ngaysinh,sizeof(ngaysinh),stdin);ngaysinh[strlen(ngaysinh)-1]=0;
    printf("\nCPA: ");scanf("%lf",&cpa);
    printf("\nBan da nhap: %s, %s(strlen = %d), %s, %.2f",mssv, hoten,strlen(hoten),ngaysinh,cpa);

    //gui du lieu
    int leng_mssv = strlen(mssv),leng_hoten = strlen(hoten),leng_ngaysinh = strlen(ngaysinh);
    write(client,&leng_mssv,sizeof(int));
    write(client,mssv,leng_mssv);

    write(client,&leng_hoten,sizeof(int));
    write(client,hoten,leng_hoten);

    write(client,&leng_ngaysinh,sizeof(int));
    write(client,ngaysinh,leng_ngaysinh);

    write(client,&cpa,sizeof(double));
    close(client);


}