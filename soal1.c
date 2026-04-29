/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3 (Structures and Dynamic Arrays)
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Yudhi Tsabit Izhharul Mulki (13224052)
 *   Nama File           : Arsip Artefak Terkategori.c
 *   Deskripsi           : Sebuah sistem yang dapat sorting suatu strukur yang berisi nama kategori tahun beserta nilai yang disusun dengan beberapa kondisi
 */

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
            else if(strcmp(data[i].kategori, data[i+1].kategori) == 0 ){
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
        scanf("%s %s %d %d", kategori[i].nama, kategori[i].kategori, &kategori[i].tahun, &kategori[i].nilai);
    }

    best(kategori, N);

    for(int i=0; i<N; i++){
        printf("%s %s %d %d\n", kategori[i].nama, kategori[i].kategori, kategori[i].tahun, kategori[i].nilai);
    }
    return 0;
}
