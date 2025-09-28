// letra A


unsigned char switch_byte(unsigned char x){
// AB -> BA

unsigned char A = (x& 0xF0);
A=A>>4;

unsigned char B = (x& 0xF);
B=B<<4;

unsigned char res = A+B;

return res;

}

unsigned char rotate_left(unsigned char x, int n) {
    return (x << n) | (x >> (8 - n));
}

int main(void) {
    unsigned char v1 = 0xAB;
    unsigned char v2 = 0xF0;
    unsigned char v3 = 0x12;

    printf("0x%X -> 0x%X\n", v1, switch_byte(v1));
    printf("0x%X -> 0x%X\n", v2, switch_byte(v2));
    printf("0x%X -> 0x%X\n", v3, switch_byte(v3));

    unsigned char v = 0x61; // 0110 0001

    printf("0x61 rotate left 1 bit: 0x%X\n", rotate_left(v, 1)); // 0xC2
    printf("0x61 rotate left 2 bits: 0x%X\n", rotate_left(v, 2)); // 0x85
    printf("0x61 rotate left 7 bits: 0x%X\n", rotate_left(v, 7)); // 0xB0


    return 0;
}