#include<stdio.h>
#include<stdlib.h>

#define NUMEROMAXIMO 10000000
/*
  Para a parte do trabalho referente a um programa IOBound utilizaremos
  um programa que gera numeros aleatórios e os salva em um arquivo de destino


*/
int main(){
  int contador = 0;
  FILE *numerosOriginal;
  numerosOriginal = fopen("numeros.txt", "w");
  for(int i=0;i < NUMEROMAXIMO; i++ ){
    float a = rand();
    fprintf(numerosOriginal, "%f\n", a);


  }
  fclose(numerosOriginal);

}
