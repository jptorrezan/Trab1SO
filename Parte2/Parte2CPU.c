#include<stdio.h>
#include<stdlib.h>
#define NUMEROMAXIMO 1000000000

int contagemNumeros(long long numeroAlvo, int digito){
  int contador = 0;
  while(numeroAlvo > 0){
    if((numeroAlvo%10) == digito)
      contador++;
    numeroAlvo /= 10;
  }
  return contador;
}

int main(){
  int digito=1;
  int contador2 = 0;
  printf("\n\tEsse programa compara quantas vezes um digito aparece na contagem\nde 0 até 1 Bilhao.\n" );
  printf("\t\tQual o digito a ser comparado?\n\t\t->" );
  int a = scanf("%d", &digito);
  long long i = 0;
  long long contador = 0;
  printf("Progresso:\n");
  for(i=0; i < NUMEROMAXIMO + 1; i++){
    contador += contagemNumeros(i, digito);
    
   
  }
  printf("O digito (%d) aparece [%lld] vezes\n", digito, contador);
}
