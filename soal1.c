#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nama[30];
    char kategori[30];
    int tahun;
    int nilai;
}artefak;

void swap(artefak *a, artefak *b){
    artefak temp = *a;
    *a = *b;
    *b = temp;
}

void best(artefak *data, int N){
    for(int j = 0; j<N-1;j++){
        for(int i=0; i<N-j-1;i++){
            if (strcmp(data[i].kategori, data[i+1].kategori)>0) {
                swap(&data[i],&data[i+1]);
            }
            else if(data[i].kategori == data[i+1].kategori){
                if(data[i].tahun > data[i+1].tahun){
                    swap(&data[i],&data[i+1]);
            }
                else if(data[i].tahun == data[i+1].tahun){
                    if(data[i].nilai < data[i+1].nilai){
                        swap(&data[i],&data[i+1]);
            }
                    else if(data[i].nilai == data[i+1].nilai){
                        if(strcmp(data[i].nama, data[i+1].nama) > 0){
                            swap(&data[i],&data[i+1]);
            }
            }
            }
            }
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    artefak kategori[N];

    for(int i=0; i<N; i++){
        scanf("%s %s %d %d", &kategori[i].nama, &kategori[i].kategori, &kategori[i].tahun, &kategori[i].nilai);
    }

    best(kategori, N);

    for(int i=0; i<N; i++){
        printf("%s %s %d %d\n", kategori[i].nama, kategori[i].kategori, kategori[i].tahun, kategori[i].nilai);
    }
    return 0;
}
