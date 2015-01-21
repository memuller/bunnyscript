#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rnd(int max){
    static int seeded = 0;
    if(seeded == 0){
        srand(time(NULL));
        seeded = 1;
    }
    return rand() % max ;
}

void main(){
    int i;
    for(i = 0; i < 100; i++){
        printf("%i", rnd(2));
    }
}