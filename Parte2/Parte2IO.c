#include<stdio.h>
#include<stdlib.h>

#define NUMEROMAXIMO 100000000
/*
  Para a parte do trabalho referente a um programa IOBound utilizaremos
  uma lista de palavras salva em um arquivo txt, copiando todo o conteudo de um
  arquivo em outro.

int main()
{


    FILE *novo, *velho;
    novo=fopen("newList.txt","w");
    velho=fopen("List.txt" ,"r");
    if (novo==NULL || velho==NULL){
        printf("Erro de abertura\n");
        system("pause");
        exit(1);
    }
    char letra;
    char *palavra = (char*)calloc(50, sizeof(char));
    int i = 0, j = 0;
    while(j < 20){
      while( (letra = fgetc(velho)) != EOF )
      {
          if(letra == '\n'){
            //palavra[i] = '\0';
            fprintf(novo, "%s\n", palavra);
            //printf("Escrito\n" );
            i = 0;
            fprintf(novo, "\n" );
          }
          else{
            palavra[i]=letra;
            i++;
          }
      }
      j++;
    }
    fclose(velho);
    fclose(novo);
    return 0;
}


int main()
{
    FILE *novo, *velho, *indice;
    velho=fopen("List.txt", "r");

    indice = fopen("indice.txt", "w");
    if (novo==NULL || velho==NULL){
        printf("Erro de abertura\n");
        system("pause");
        exit(1);
    }

    char letra;
    int contador[6];
    contador[0] = 0;
    contador[1] = 0;
    contador[2] = 0;
    contador[3] = 0;
    contador[4] = 0;
    contador[5] = 0;
    while( (letra = fgetc(velho)) != EOF ) {
      novo=fopen("newList.txt", "a");
      if(letra =='a' || letra == 'A'){
        contador[0] ++;
      }
      else if(letra =='e' || letra == 'E'){
        contador[1] ++;
      }
      else if(letra =='i' || letra == 'I'){
        contador[2] ++;
      }
      else if(letra =='o' || letra == 'O'){
        contador[3] ++;
      }
      else if(letra =='u' || letra == 'U'){
        contador[4] ++;
      }
      else
        contador[5] ++;
      fprintf(novo, "%c", letra);
      fclose(novo);
    }
    fprintf(indice, "Numero de letras 'a'    = %d\n", contador[0]);
    fprintf(indice, "Numero de letras 'e'    = %d\n", contador[1]);
    fprintf(indice, "Numero de letras 'i'    = %d\n", contador[2]);
    fprintf(indice, "Numero de letras 'o'    = %d\n", contador[3]);
    fprintf(indice, "Numero de letras 'u'    = %d\n", contador[4]);
    fprintf(indice, "Numero de outras letras = %d\n", contador[5]);
    fclose(velho);
    fclose(novo);
    fclose(indice);
    return 0;
}
*/
int main(){
  int contador = 0;
  FILE *numerosOriginal;
  numerosOriginal = fopen("numeros.txt", "w");
  for(int i=0;i < NUMEROMAXIMO; i++ ){
    float a = rand();
    fprintf(numerosOriginal, "%f ", a);
    if(i%1000000 == 0) printf("%dkk\n", contador++);

  }
  fclose(numerosOriginal);

}
