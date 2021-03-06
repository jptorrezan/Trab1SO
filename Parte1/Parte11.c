#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

/*
* Parte 1 do trabalho 1, system calls
* Trabalho consiste na analise de 9 system calls de 3 grupos distintos (gerenciamento de memoria, processos, E/S e arquivos)
* a ferramenta utilizada para analise dessas system calls foi o strace
* João Pedro Doimo Torrezan 9806933
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  Função que lida com as system calls de arquivos.
*   As system calls aqui utilizadas são:
*   1- int open(const char *pathname, int flags, mode_t mode);
*     open = a qual abre (ou cria, caso haja a flag O_CREAT) algum arquivo no caminho especificado,
*         caso haja a flag de criação o argumento mode deve ser especificado, caso contrário, será ignorado.
*         No nosso caso o arquivo já existirá.
*         Entretanto, como o caminho do arquivo é relativo, ou seja está no mesmo diretório do programa,
*         a system call utilizada é a openat, que fuciona da mesma maneira que open.
*
*
*   2- ssize_t read(int fd, void *buf, size_t count);
*     read = lê a quantidade de bytes indicada em count, salvando no buffer buf, no arquivo indicado por fd
*
*   3- int close(int fd);
*     close = fecha o arquivo indicado por fd.
*/
int gerenciamentoArquivos(){
  int arqv, readReturn;
  char *conteudoArqv = (char*)calloc(30, sizeof(char));
  arqv = open("HelloWorld.txt", O_RDONLY);
  if(arqv < 0 ){
    return -1;
  }
  readReturn = read(arqv, conteudoArqv, 11);
  conteudoArqv[readReturn] = '\0';

  if(close(arqv) < 0){

    free(conteudoArqv);
    return -1;
  }

  free(conteudoArqv);
  return 0;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Função responsável por tratar as System calls de gerenciamento de processos
*   1- pid_t getpid(void);
      Função que retorna o PID do processo que a executa.
*   2- pid_t fork(void);
      Função que cria um processo filho identico ao pai, ela retorna o pid do processo criado
        e retorna 0 no processo filho.
*   3- pid_t waitpid(pid_t pid, int *wstatus, int options);
      Função que faz com que o processo pai aguarde algum sinal do processo filho para que continue a execução;
*/
void gerenciamentoProcessos(){
  int pidChild;
  int wstatus;
  int pidSelf;

  pidSelf = getpid();

  if(pidChild = fork()){  //processo pai

    waitpid(pidChild, &wstatus, 0);
  

  }
  else{ //processo filho
    for(int i = 0; i < 5000; i++);

    exit(EXIT_SUCCESS);
  }

}
/*Função responsável por tratar as System calls de gerenciamento de memória
*    1- void *sbrk(intptr_t increment);
       sbrk = Incrementa o espaço de armazenamento do programa no valor de increment
          Como tive dificuldade em encontrar mais system calls de gerenciamento de memória
          utilizei essa syscall de 2 formas:
            1- Caso o parametro increment for passado como 0, a função retorna o valor atual do process break
            2- Caso o parametro increment for diferente de 0, o valor passado é adicionado ao final do process break
*    2- int brk(void *addr);
        brk = seta o procress break para a posição de memória apontada por addr
          retorna 0 no sucesso e (void*)-1 caso haja erro.
*
*
*/
int gerenciamentoMemoria(){
    intptr_t oldEnd;
  	intptr_t newEnd, addValue = 100;

  	oldEnd = (intptr_t) sbrk(0);

  	newEnd = (intptr_t) sbrk(addValue);
    newEnd = (intptr_t) sbrk(0);

    if(brk( (void *) (newEnd + addValue) ) != 0){

      return -1;
    }
    else{
      newEnd = (intptr_t) sbrk(0);

      return 0;
    }
}

int main(){

    gerenciamentoMemoria();
    gerenciamentoArquivos();
    gerenciamentoProcessos();

}
