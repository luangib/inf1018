int odd_ones(unsigned int x){

    int count;
for (int i = 0; i < 31; i++)
{
count= count+ (x&1);
x=x>>1;
}

if (count&1){
printf("Impar");

}
else{
printf("Par");

}

}