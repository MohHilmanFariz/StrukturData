#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

using namespace std;

#define info(P) P->info
#define next(P) P->next
#define child(P) P->child
#define first(L) ((L).first)

typedef struct Kota *adrKota;
typedef struct NamaAnggota *adrAngg;

struct Kota{
    string info;
    adrKota next;
    adrAngg child;
};

struct NamaAnggota{
    string info;
    adrAngg next;
};

struct listKota{
    adrKota first;
};

void createListKota(listKota &l);
adrKota newKota(string x);
//fungsi a & d
void addKota(listKota &l, adrKota p);
void addAnggota(listKota &l, string x, string y);
//fungsi b
adrKota findKota(listKota l, string x);
void findAnggota(listKota, string y);
//fungsi c
void show(listKota l);
//fungsi e
void delKota(listKota &l, string x );
//fungsi f
int countKota(listKota l);
int countAnggota(listKota l);
int hitung(listKota l, adrKota p);
//fungsi g
void maxAnggota(listKota l);
//fungsi h
void minAnggota(listKota l);
//menu
int selectMenu();


#endif // TUBES_H_INCLUDED
