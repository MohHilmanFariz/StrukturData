#include <iostream>
#include "tubes.h"

using namespace std;

int main(){
    int pilihan = 0;
    int i, n;
    int inputan;
    listKota L;
    string x, y;
    adrKota p;


    cout<<"======================================="<<endl;
    cout<<"=======TUGAS BESAR STRUKTUR DATA======="<<endl;
    cout<<"Kelompok I/O"<<endl;
    cout<<"Nama Anggota:"<<endl;
    cout<<"1. Moh Hilman Fariz (1301213393)"<<endl;
    cout<<"2. Renata Alfianto Rasyid (1301213304)"<<endl;
    cout<<"======================================="<<endl<<endl;


    createListKota(L);
    pilihan = selectMenu();
    while(pilihan!=0){
        switch(pilihan){
        case 1:
            n = 1;
            i = 0;
            inputan = 0;
            cout<<"Jumlah kota lahir yang akan ditambahkan: ";
            cin>>inputan;
            while(i<inputan){
                cout<<n<<": ";
                cin>>x;
                addKota(L, newKota(x));
                i++;
                n++;
            }
            cout<<endl;
            break;

        case 2:
            inputan = 0;
            i= 0;
            cout<<"Jumlah anggota yang akan ditambahkan: ";
            cin>>inputan;
            while(i<inputan){
                cout<<"Kota lahir? ";
                cin>>x;
                cout<<"Nama anggota: ";
                cin>>y;
                addAnggota(L, x, y);
                i++;
                cout<<endl;
            }
            break;

        case 3:
            inputan = 0;
            i= 0;
            cout<<"Jumlah yang ingin dicari: ";
            cin>>inputan;
            while(i<inputan){
                cout<<"Masukkan Nama anggota yang ingin dicari: ";
                cin>>y;
                findAnggota(L, y);
                i++;
                cout<<endl;
            }
            break;

        case 4:
            cout<<"Jumlah kota lahir: "<<countKota(L)<<endl<<endl;
            break;

        case 5:
            cout<<"Jumlah anggota: "<<countAnggota(L)<<endl<<endl;
            break;

        case 6:
            hitung(L, p);
            cout<<endl;
            break;

        case 7:
            maxAnggota(L);
            cout<<endl;
            break;

        case 8:
            minAnggota(L);
            cout<<endl;
            break;

        case 9:
            i = 0;
            inputan = 0;
            cout<<"Jumlah yang ingin dihapus: ";
            cin>>inputan;
            while(i<inputan){
                cout<<"Apa kota lahir yang ingin dihapus? ";
                cin>>x;
                delKota(L, x);
                i++;
                cout<<endl;
            }
            break;

        case 10:
            show(L);
            cout<<endl;
            break;

        default:
            cout<<"Anda belum beruntung, silahkan coba lagi"<<endl<<endl;
        }

        pilihan = selectMenu();
    }
    cout<<"ANDA TELAH KELUAR DARI PROGRAM"<<endl;
    return 0;
}
