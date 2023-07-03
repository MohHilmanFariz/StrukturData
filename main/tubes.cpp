#include "tubes.h"

void createListKota(listKota &l){
    first(l) = NULL;
}

adrKota newKota(string x){
    adrKota p = new Kota;
    info(p) = x;
    next(p) = NULL;
    child(p) = NULL;
    return p;
}

void addKota(listKota &l, adrKota p){
    if(first(l) == NULL){
        first(l) = p;
    } else{
        next(p) = first(l);
        first(l) = p;
    }
}

adrKota findKota(listKota l, string x){
    if(first(l) == NULL){
        return NULL;
    }else {
        adrKota p = first(l);
        while(p != NULL){
            if(info(p) == x){
                return p;
            }
            p = next(p);
        }
        return p;
    }
}

void findAnggota(listKota l, string y){
    adrKota p = first(l);
    adrKota a;
    adrAngg q;
    bool ketemu = false;

    while(p != NULL && ketemu == false){
        q = child(p);
        while(q != NULL){
            if(info(q) == y){
                ketemu = true;
                a = p;
            }
            q = next(q);
        }
        p = next(p);
    }
    cout<<endl;
    if(ketemu){
        cout<<y<< " Anggota dari Kota: "<<info(a)<< endl;
    }else{
        cout<<"Anggota tidak ditemukan"<<endl;
    }
}

void addAnggota(listKota &l, string x, string y){
    adrKota p = findKota(l, x);
    adrAngg q = new NamaAnggota;
    info(q) = y;
    next(q) = NULL;
    if(child(p) == NULL){
        child(p) =  q;
    }else{
        next(q) = child(p);
        child(p) = q;
    }
}

void show(listKota l){
    adrKota p = first(l);
    while(p != NULL){
        adrAngg q = child(p);
        cout << "Kota Lahir: " << info(p)<< " - Nama Anggota: ";
        while(q != NULL){
            cout << "|" << info(q) << "|";
            q = next(q);
        }
        p = next(p);
        cout << endl;
    }
}

int countKota(listKota l){
    adrKota p = first(l);
    int i = 0;
    while(p != NULL){
        i++;
        p = next(p);
    }
    return i;
}

int countAnggota(listKota l){
    adrKota p = first(l);
    int i = 0;
    while(p != NULL){
        adrAngg q = child(p);
        while(q != NULL){
            i++;
            q = next(q);
        }
        p = next(p);
    }
    return i;
}

int hitung(listKota l, adrKota p){
    p = first(l);
    while(p != NULL){
        int i = 0;
        adrAngg q = child(p);
        cout << "Jumlah anggota yang terdapat pada kota " << info(p) << " adalah: ";
        while(q != NULL){
            i++;
            q = next(q);
        }
        cout<<i<<endl;
        p = next(p);
    }
}

void maxAnggota(listKota l){
    adrKota p = first(l);
    adrKota a;
    int maks = 0;
    while(p != NULL){
        adrAngg q = child(p);
        int hitung = 0;
        while (q != NULL){
            hitung ++;
            q = next(q);
        }
        if(hitung >= maks){
            maks = hitung;
            a = p;
        }
        p = next(p);
    }

    cout << "Anggota paling terbanyak terdapat pada Kota " << info(a) << " dengan jumlah anggota : " << maks << endl;
}

void minAnggota(listKota l){
    adrKota p = first(l);
    adrKota a;
    int mins = 1;
    while(p != NULL){
        adrAngg q = child(p);
        int hitung = 0;
        while (q != NULL){
            hitung ++;
            q = next(q);
        }
        if(hitung <= mins){
            mins = hitung;
            a = p;
        }
        p = next(p);
    }
    cout << "Anggota paling sedikit terdapat pada Kota " << info(a) << " dengan jumlah anggota : " << mins << endl;
}

void delKota(listKota &l, string x ){
    adrKota p = first(l);
    if(first(l) == NULL){
        cout << "Data Kosong" << endl;
    }else if(info(p) == x){
        first(l) = next(p);
        next(p) = NULL;
        child(p) = NULL;
    }else{
        while(info(next(p)) != x){
            p = next(p);
        }
        adrKota q = next(p);
        next(p) = next(next(p));
        next(q) = NULL;
        child(q) = NULL;
    }
}

int selectMenu(){
    cout<<"======MENU======="<<endl;
    cout<<"01. Menambah kota lahir"<<endl;
    cout<<"02. Menambah anggota"<<endl;
    cout<<"03. Mencari nama anggota"<<endl;
    cout<<"04. Menampilkan jumlah kota lahir"<<endl;
    cout<<"05. Menampilkan jumlah anggota"<<endl;;
    cout<<"06. Menampilkan jumlah anggota yang dimiliki kota lahir"<<endl;
    cout<<"07. Menampilkan jumlah anggota paling banyak"<<endl;
    cout<<"08. Menampilkan jumlah anggota paling sedikit"<<endl;
    cout<<"09. Menghapus kota lahir beserta nama anggotanya"<<endl;
    cout<<"10. Menampilkan data"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Masukkan menu: ";

    int input = 0;
    cin>>input;
    cout<<"================="<<endl;
    return input;
}
