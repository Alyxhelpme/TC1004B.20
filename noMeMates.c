#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handleTerm(int signal){
    printf("Received signal: %d\n",signal);
}

int main(){
    signal(2,handleTerm);
    while(1){
        printf("Working...\n");
        sleep(1);
    }
}