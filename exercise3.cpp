/*
Nama Program : Exercise 3
Nama         : Hana Meilina Fauziyyah
NPM          : 140810180012
Tanggal buat : 15 April 2019
Deskripsi    : Represent below data in circular doubly linked list
********************************************/
#include <iostream>
#include <windows.h>
using namespace std;

struct elemlist{
    char info;
    elemlist* next;
    elemlist* prev;
};

typedef elemlist* pointer;
typedef pointer List;

void createlist (List& first);
void createElmt(List& first, pointer& pBaru);
void insertLastCircular(List& first, pointer pBaru);
void deleteLastCircular(List& first, pointer& pHapus);
void insertFirstCircular (List& first, pointer pBaru);
void deleteFirstCircular (List& first, pointer& pHapus);
void traversal (List first);

main (){
    pointer p;
    List m;
    int pilih,n;

    createlist(m);
    while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Insert First "<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Delete First"<<endl;
        cout<<"4. Delete Last"<<endl;
        cout<<"5. Traversal"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Masukan Pilihan : ";
        cin >> pilih;
        switch(pilih){
        case 1:
            createElmt(m,p);
            insertFirstCircular(m,p);
        break;

        case 2:
            createElmt(m,p);
            insertLastCircular(m,p);
        break;

        case 3:
            deleteFirstCircular(m,p);
        break;

        case 4:
            deleteLastCircular(m,p);
        break;

        case 5:
            traversal(m);
        break;

        case 6:
            return 0;
            break;
        }
        system("pause");
    }

}

void createlist (List& first){
    first = NULL;
}

void createElmt(List& first, pointer& pBaru){
    pBaru = new elemlist;
    cout<<"Input element : ";
    cin>>pBaru->info;
    pBaru->next=pBaru;
    pBaru->prev=pBaru;
}

void insertLastCircular(List& first, pointer pBaru){
    pointer last;
    if (first==NULL){
        first=pBaru;
        last=first;
    }
    else{
        last=first;
        while(last->next!=first){
            last=last->next;
        }
        last->next=pBaru;
        pBaru->prev=last;
        pBaru->next=first;
        first->prev=pBaru;
    }
}

void deleteLastCircular(List& first, pointer& pHapus){
    pointer last;
    if (first==NULL){
        cout<<"List kosong tidak ada yang bisa dihapus"<<endl;
    }
    else if (first->next==first){
        pHapus=first;
        pHapus->next=NULL;
        pHapus->prev=NULL;
        first=NULL;
    }
    else{
        last=first;
        while(last->next!=first){
            last=last->next;
        }
        pHapus = last;
        first->prev = last->prev;
        last->prev->next = first;
        pHapus->next = NULL;
        pHapus->prev = NULL;
    }
}

void insertFirstCircular(List& first, pointer pBaru){
    pointer last;
    if (first == NULL){
        first = pBaru;
    }
    else{
        last = first;
        while(last->next != first){
            last = last->next;
        }
        pBaru->next = first;
        pBaru->prev = last;
        first->prev = pBaru;
        last->next = pBaru;
        first = pBaru;
    }
}

void deleteFirstCircular (List& first, pointer& pHapus){
    pointer last;
    if (first == NULL){
        cout<<"List kosong tidak ada yang bisa dihapus"<<endl;
    }
    else if (first->next == first){
        pHapus = first;
        pHapus->next = NULL;
        pHapus->prev = NULL;
        first = NULL;
    }

    else{
        last = first;
        while(last->next != first){
            last = last->next;
        }
        pHapus = first;
        first = pHapus->next;
        last->next = first;
        first->prev = last;
        pHapus->next = NULL;
        pHapus->prev = NULL;
    }
}

void traversal (List first){
    pointer pBantu, last;
    if (first == NULL){
        cout<<"List kosong"<<endl;
    }
    else{
        int i = 1;
        pBantu = first;
        while(pBantu->next != first){
            cout<<" <--> "<<pBantu->info;
            pBantu=pBantu->next;
        }
        cout<<" <--> ";
    }
}
