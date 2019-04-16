/*
Nama Program : Exercise 1
Nama         : Hana Meilina Fauziyyah
NPM          : 140810180012
Tanggal buat : 15 April 2019
Deskripsi    : Represent below data in singly linked list
********************************************/
#include <iostream>
#include <windows.h>
using namespace std;

struct ElemtList{
	char info;
	ElemtList* next;
};

typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First);
void createElemt(pointer& pBaru);
void insertFirst(List& First, pointer pBaru);
void traversal(List First);
void deleteFirst(List& First, pointer& pHapus);
void insertLast(List& First, pointer pBaru);
void linearSearch(List First,int key, int& found, pointer& pCari);
void deleteLast(List& First, pointer& pHapus);

main(){
    pointer p;
    List m;
    int pilih;

    createList(m);
    while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Insert First "<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Delete First"<<endl;
        cout<<"4. Delete Last"<<endl;
        cout<<"5. Traversal"<<endl;
        cout<<"6. Exit"<<endl;
        cout << "Masukan Pilihan : "; cin >> pilih;
        switch(pilih){
        case 1:
            createElemt(p);
            insertFirst(m, p);
        break;

        case 2:
            createElemt(p);
            insertLast(m,p);
        break;

        case 3:
            deleteFirst(m,p);
        break;

        case 4:
            deleteLast(m,p);
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

void createList(List& First){
    First = NULL;
}

void createElemt(pointer& pBaru){
    pBaru=new ElemtList;
	cout<<"Masukkan satu huruf : ";
	cin>>pBaru->info;
	pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
    if(First==NULL)
		First=pBaru;
		else{
			pBaru->next=First;
			First=pBaru;
		}
}

void traversal(List First){
    pointer pBantu;
	pBantu=First;
	while(pBantu != NULL){
		cout<<pBantu->info<<endl;
		pBantu=pBantu->next;
	}
}

void deleteFirst(List& First, pointer& pHapus){
    if (First==NULL){
        pHapus=NULL;
        cout << "List kosong tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void insertLast(List& First, pointer pBaru){

    pointer last;
    if(First==NULL){
        First=pBaru;
    }
    else{
        last=First;
        while(last->next!=NULL){
            last=last->next;
    }
    last->next=pBaru;
    }
}

void deleteLast(List& First, pointer& pHapus){
    pointer last,precLast;
    if (First==NULL){
        pHapus=NULL;
        cout << "List Kosong tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        last=First;
        precLast=NULL;
        while(last->next !=NULL){
            precLast=last;
            last=last->next;
        }
        pHapus=last;
        precLast->next=NULL;
    }
}

void linearSearch(List First,int key, int& found, pointer& pCari){
    found=0;
    pCari=First;
    while (found==0 && pCari!=NULL) {
        if (pCari->info==key)
            found=1;
        else
        pCari=pCari->next;
        }
}
