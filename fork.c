#include <stdio.h>
#include <stdlib.h>

/* exec reemplaza instrucciones en memoria del proceso que lo ejecuta */

int main(){

	pid_t pid;

	pid = fork();

	if(pid == -1){
		printf("Hubo un error ejecutando el fork....\n");
	} 
	else if( pid == 0 ){
		printf("Estás en el proceso hijo... \n");
		printf("El id del hijo es: %d, y mi proceso padre es: %d\n\n", getpid(), getppid());
	}else{
		wait(&pid);
		printf("Estás en el proceso padre... \n");
		printf("El id del padre es: %d\n", getpid());
	}

	return 0;
}