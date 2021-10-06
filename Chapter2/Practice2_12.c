#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len){
        size_t i;
        for(i = 0;i < len;i++){
                printf(" %.2x",start[i]);
        }
        printf("\n");
}

void show_int(int x){
        show_bytes((byte_pointer) &x,sizeof(int));
}

void FunctionA(byte_pointer x,size_t len){
        size_t i;
        printf("ResultA:");
        for(i = 1;i<len;i++){
                x[i] &= 0x00;
        }
}
void FunctionB(byte_pointer x,size_t len){
        size_t i;
        printf("ResultB:");
        for(i = 1;i < len;i++){
                x[i] = ~x[i];
        }
}

void FunctionC(byte_pointer x,size_t len){
        printf("ResultC:");
        x[0] |= 0xFF;
}

int main(){
        int x = 0x87654321;
        int y = x,z = x;
        show_int(x);
        FunctionA((byte_pointer) &x,sizeof(x));
        show_int(x);
        FunctionB((byte_pointer) &y,sizeof(y));
        show_int(y);
        FunctionC((byte_pointer) &z,sizeof(z));
        show_int(z);

}
