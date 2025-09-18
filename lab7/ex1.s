/*
Dicionário
Reg  Var
rbx pc
eax  temp

*/

#include <stdio.h>

.data #Varivaveis Globais(Declaradas fora das Funções) e Strings constantes
#char S2[] = {65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0};
S2: .byte 65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0

Sf:        .string "%c"   
MUDA_LINHA:.string "\n"

#Explicação: eu coloco .byte se for char, .int se for int e se for .string é para string

.text  # Segmento de codigo (texto para a CPU)

#todo endereço de função é o nome da função sem parenteses ou seja int main (void) é main:

.globl main # pode ser antes ou depois do main: diz que a função é global(todas são)
#int main (void) {
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/


#char =*pc; <== não existem variaveis em linguagem de maquina

#pc= S2;
movq $S2, %rbx  #b= byte w= 2bytes l= 4bytes q= 8bytes

WHILE:

#while (*pc !=0 ){ 
cmpb $0, (%rbx)
jz FORA_WHILE

#char temp = *pc;
movsbl (%rbx), %eax
    

#printf("%c", temp);

/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/
    
#pc++;
incq %rbx

# }
jmp WHILE
FORA_WHILE:


#printf("\n");
  /*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $MUDA_LINHA, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/

#  return 0;

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret      
/***************************************************************/
#}