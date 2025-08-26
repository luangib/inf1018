#include <stdio.h>

int is_little(){

unsigned short input = 1;  
// 0000 0000 0000 0001  


unsigned char *byte = &input;

// 0001

//Eu preciso saber quem que eu pego nessa primeira conversão pois não sei se ele pega primeiro o da direita ou o da esquerda

if((*byte)==1){
    printf("Ele é little_endian");
    return 1;

}

else{
    printf("Ele é big_endian");
    return 0;
}


}

int main(){
printf("%d", is_little());

    return 0;
}