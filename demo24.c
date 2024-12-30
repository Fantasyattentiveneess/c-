#include <stdio.h>


void modify( int *pbuf,int plen){
    printf("modify:\n");
    for(int index = 0 ; index < plen; index ++){
        pbuf[index] = index*2;
        printf("%d",pbuf[index]);

    }
    printf("\n");
    }
int main(){
    int array[100];
    int array_len = sizeof(array_len)/sizeof(int);
      printf ("before modify:\n");
    for (int index = 0;index < 100;index ++ ){
        array[index] = index;
      printf("%d",array[index])
    }
    printf("\n");
    modify(array,array_len);
    printf("after modify:\n");
    for(int index = 0 ;index < array_len; index ++){
        printf("%d",array [index]);

     }

    

    return 0;
}
