/*
Nama Program : Exercise 2
Nama         : Hana Meilina Fauziyyah
NPM          : 140810180012
Tanggal buat : 15 April 2019
Deskripsi    : Represent below data in doubly linked list
********************************************/
#include <iostream>
#include <windows.h>
using namespace std;

struct Elemtlist{
    char info;
    Elemtlist* next;
    Elemtlist* prev;
};

typedef Elemtlist* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirstDoubly(List& First, pointer pBaru);
void InsertLastDoubly(List& First, pointer pBaru);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast(List& First, pointer& pHapus);
void traversal(List First);

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
            createElmt(p);
            insertFirstDoubly(m, p);
        break;

        case 2:
            createElmt(p);
            InsertLastDoubly(m,p);
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
	First=NULL;
}
void createElmt(pointer& pBaru){
	pBaru=new Elemtlist;
	cout<<"Masukkan satu huruf : ";
	cin>>pBaru->info;
	pBaru->next=NULL;
	pBaru->prev=NULL;
	cout<<endl;
}

void insertFirstDoubly(List& First, pointer pBaru){
	if (First==NULL)
		First=pBaru;
	else {
		pBaru->next=First;
		First->prev = pBaru;
		First=pBaru;
	}
}

void InsertLastDoubly(List& First, pointer pBaru){
	pointer last;
	if (First==NULL){
		First=pBaru;
	}
	else {
		last=First;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
		pBaru->prev=last;
	}
}

void deleteFirst(List& First, pointer& pHapus){
	if (First==NULL){
		pHapus=NULL;
		cout << "List kosong, tidak ada yang dihapus"<<endl;
	}
	else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}
	else{
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
		First->prev=NULL;
	}
}

void deleteLast(List& First, pointer& pHapus){
	pointer last;
	cout << "Delete last"<<endl;
	if (First==NULL){
		pHapus=NULL;
		cout << "List Kosong, tidak ada yang dihapus"<<endl;
	}
	else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}
	else{
		last=First;
		while(last->next != NULL){
			last = last->next;
		}
		pHapus = last;
		last->prev->next=NULL;
		pHapus->prev=NULL;
	}
}

void traversal(List First){
	pointer pBantu;
	int i=1;
	if(First==NULL){
		cout<<"List Kosong"<<endl;
	}else{
		pBantu=First;
		do{
			cout<<pBantu->info<<endl;
			pBantu=pBantu->next;
		}while(pBantu!=NULL);
	}
	cout<<endl;
}
