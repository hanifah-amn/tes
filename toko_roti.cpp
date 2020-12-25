#include <iostream>
#include <windows.h>
using namespace std;

typedef struct dataRoti typeinfo;
struct dataRoti{
	int kode;	// kode roti
	string nama;	// nama roti
	int masa[10];	// sisa masa kadaluarsa roti, dalam hari
	};
typedef struct typenode *typeptr;
struct typenode{
	typeinfo info;
	typeptr next;
	};
typeptr awal, akhir;

void bukaToko(), sisipRoti(string namaRoti, int kodeRoti);
void pegawai(), pembeli();

int main(){
	bukaToko();	//settingan awal, roti masih kosong
	
	bool ulang=false;
	do{
		//system("cls");
		int pilihan;
		cout<<"--- MENU UTAMA ---\n";
		cout<<"1. Pegawai\n";
		cout<<"2. Pembeli\n";
		cout<<"Pilih: "; cin>>pilihan;
		
		system("cls");
		switch(pilihan){
			case 1 : pegawai(); break;
			case 2 : pembeli(); break;
			default: cout<<"Pilihan tidak tersedia. Pilih lagi\n";
		}

		char pilih;
		cout<<"Kembali ke MENU UTAMA? (y/t) "; cin>>pilih;
		if((pilih=='y')||(pilih=='Y')) ulang=true;
		else if((pilih=='t')||(pilih=='T')) ulang=false;
		
	} while(ulang);
}

void bukaToko(){
	// membuat linked list berisi queue
	// info LL: nama roti, info queue masih kosong
	
	// buat linked list kosong
	typeptr list;
	list=(typenode *) malloc(sizeof(typenode));
	list=NULL;
	awal=list;
	akhir=list;
	
	//sisip linked list
	sisipRoti("Roti Cokelat",1);
	sisipRoti("Roti Susu",2);
	sisipRoti("Roti Keju",3);
}

void sisipRoti(string namaRoti, int kodeRoti){
	// sisip belakang
	typeptr NB;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->info.kode=kodeRoti;
	NB->info.nama=namaRoti;
	if(awal==NULL){
		awal=NB;
		akhir=NB;
	}
	else{
		akhir->next=NB;
	}
	akhir=NB;
	akhir->next=NULL;
}

void pegawai(){
	//tampil stok roti
	typeptr bantu;
	bantu=awal;
	while(bantu!=NULL){
		cout<<bantu->info.kode <<". ";
		cout<<bantu->info.nama <<endl;
		for(int i=0; i<10; i++)
			cout<<bantu->info.masa[i] <<endl;
		bantu=bantu->next;
	}
	
	//tampil input nyetok roti & box
	int pilihan;
	cout<<"1. Tambah stok roti\n";
	cout<<"2. Tambah stok box\n";
	cout<<"0. Keluar\n";
	cout<<"Pilih : "; cin>>pilihan;
}

void pembeli(){}
