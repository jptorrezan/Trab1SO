#include<stdio.h>
#include<stdlib.h>
#define NUMEROMAXIMO 10000000000

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
  int digito;
  int contador2 = 1;
  printf("\n\tEsse programa compara quantas vezes um digito aparece na contagem\nde 0 até 10 Bilhoes.\n" );
  printf("\t\tQual o digito a ser comparado?\n\t\t->" );
  scanf("%d", &digito);
  long long i = 0;
  long long contador = 0;
  for(i=0; i < NUMEROMAXIMO + 1; i++){
    contador += contagemNumeros(i, digito);
    if(i % 10000000 == 0)printf("%d0kk\n", contador2++);
  }
  printf("O digito (%d) aparece [%lld] vezes\n", digito, contador);
}
