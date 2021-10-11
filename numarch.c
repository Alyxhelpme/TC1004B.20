#include <unistd.h>
#include <stdio.h>

int main(){
    int fd[2],pid;
    pipe(fd);
    pid= fork();
    if(pid==0){   //[0] es entrada estandar y [1] es salida estandar 
        close(0);
        dup(fd[0]);
        close(fd[1]);
        execlp("wc","wc","-l",NULL);
    }else{
        close(1);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls","ls",NULL); //Proceso padre que deja de ser el proceso padre y se convierte en ls
    }
}