#include <stdio.h>

char S2[] = {65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0};

int main (void) {
  //char *pc = S2;
  char *pc;
  pc= S2;

  // while (*pc)
  while (*pc !=0 ){ 

    // printf ("%c", *pc++);
    char temp = *pc;
    printf("%c", temp);
    pc++;

    }

  printf("\n");

  return 0; // como eu faço return em assembly
}

//Perguntas acumuladas:
//Para imprimir char(como inteiro) usariamos hhd [Correto]
//Como usar o .data 
//Como dar return em assembly