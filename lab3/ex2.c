#include <stdio.h>

int odd_ones(unsigned int x){

    int count;
    for (int i = 0; i < 32; i++)
    {
        count= count+ (x&1);
        x=x>>1;
    }

    if (count&1){
        printf("Impar");
        return 1;
    }
    else{
        printf("Par");
        return 0;

    }


}

int main(void) {
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  return 0;
}