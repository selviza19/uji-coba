#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include<windows.h>

using namespace std;

typedef int typeinfo;
typedef struct vaksin *typeptr;
struct screening{
	char nama[50];
	int umur;
	long int NIK;
	int dosis;
	float suhu;
	int sistol;
	int diastol;
	int jenisvaksin;
	int status;
};
struct vaksin{
	screening info;
	typeptr next;
};

void buatlistbaru();
void inputdata();
void simpandata(screening BARU);
void cetakdata();
void cekdata();
void hapusdata(typeinfo IH);
void caridata();


typeptr awal;
typeptr akhir;

int main()
{
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"	Nama  : Selvi\n";Sleep(200);
	cout<<"	NIM   : 123200026\n";Sleep(200);
	cout<<"	Kelas : IF-A\n";Sleep(200);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		
	int pil;
	string ulang;
	typeptr cari;

	buatlistbaru();
	do{
		cout<<"-----------------------------------------------------"<<endl;Sleep(200);
		cout<<"                  PROGRAM VAKSIN                     "<<endl;Sleep(200);
		cout<<"-----------------------------------------------------"<<endl;Sleep(200);
		cout << "Data Vaksinasi Jawa Tengah" << endl;
		cout << "1. Input Data" << endl;
		cout << "2. Lihat Peserta Vaksinasi" << endl;
		cout << "3. Cek Status Vaksinasi" << endl;
		cout << "4. Hapus Data Vaksinasi" << endl;
		cout << "5. Keluar" << endl;
		cout << "Menu yang dipilih = "; cin>>pil;
		if(pil==1){
			system("cls");
			cout << "--------INPUT DATA PESERTA VAKSINASI--------" << endl;
			inputdata();
		}
		else if(pil==2){
			cetakdata();
		}
		else if(pil==3){
			cekdata();
		}
		else if(pil==4){
			cout << "---------HAPUS DATA PESERTA VAKSIN----------" << endl;
			caridata();
		}
		else if(pil==5){
			break;
		}
		cout << "Kembali ke menu? "; cin>>ulang;
	}while(ulang=="Y" || ulang=="y");

	return 0;
}

void buatlistbaru(){	
	typeptr baru;
	baru=(vaksin *) malloc(sizeof(vaksin));
	baru=NULL;                                     //mendeklarasikan bahwa data nya kosong
	awal=baru;
	akhir=baru;
}

void inputdata(){
	vaksin tmp;
	
	cout << "Screening Tahap 1" << endl;
	cout << "  Nama\t\t: "; cin.ignore();cin.getline(tmp.info.nama, sizeof(tmp.info.nama));
	cout << "  Umur\t\t: "; cin>>tmp.info.umur;
	cout << "  NIK\t\t: "; cin>>tmp.info.NIK;
	cout << "  Dosis Vaksin Ke-"; cin>>tmp.info.dosis;if(tmp.info.dosis==2){tmp.info.status=1;}
	if(tmp.info.umur>12){
		cout << "Screening Tahap 2" << endl;
		cout << "  Suhu Badan\t: "; cin>>tmp.info.suhu;
		cout << "  Tekanan Darah\t: " <<endl; 
		cout << "   Sistol\t: ";cin>>tmp.info.sistol;
		cout << "   Diastol\t: ";cin>>tmp.info.diastol;
		if(tmp.info.suhu<37.5 && (tmp.info.sistol>=100 && tmp.info.sistol<=120) && (tmp.info.diastol>=60 && tmp.info.diastol<=90)){
			cout << "Screening Tahap 3" << endl;
			cout << "  Daftar Vaksin yang Tersedia" << endl;
			cout << "   1. Sinovac\n   2. Astrazeneca\n   3. Moderna" <<endl;
			cout << "  Vaksin yang dipilih No."; cin>>tmp.info.jenisvaksin;
			cout << "  Penginputan Data Selesai" << endl;	
		}
	}
	if(tmp.info.umur<12||tmp.info.suhu>37.5 || tmp.info.sistol<100 || tmp.info.sistol>120 || tmp.info.diastol<60 || tmp.info.diastol>90){
		cout << "Mohon maaf anda belum bisa melakukan vaksinasi" << endl;	
	}
	
	simpandata(tmp.info);
}

void simpandata(screening BARU){
	typeptr NB;
	NB=(vaksin *)malloc(sizeof(vaksin));
	NB->info=BARU;
	if(awal==NULL){
		awal=NB;
		akhir=awal;
	}
	else{
		akhir->next=NB;
		akhir=NB;
	}
	akhir->next=NULL;
}

void cetakdata(){
	typeptr bantu;
	bantu=awal;
	int no=1;

	if (awal==NULL){
		cout << "Data Kosong" << endl;
	}
	else{
		while(bantu!=NULL){
			cout << no <<". " << bantu->info.nama << " (" << bantu->info.umur << ")" << endl;
			no++;
			bantu=bantu->next;
		}
	}
}

void cekdata(){
	typeptr bantu;
	long int cariNIK;
	int statussementara;
	string setujuvaksin, yakinvaksin;
	bantu=awal;

	if(awal==NULL){
		cout << "Data Kosong" << endl;
	}
	else{
		cout << "Silahkan masukkan NIK yang ingin anda cek"<<endl;
		cout << "NIK : "; cin>>	cariNIK;
		while(bantu!=NULL){
			if(bantu->info.NIK==cariNIK){
				if(bantu->info.status==0){
					cout << "Nama\t\t: " << bantu->info.nama << endl;
					cout << "Umur\t\t: " << bantu->info.umur << endl;
					cout << "NIK\t\t: " << bantu->info.NIK << endl;
					cout << "Suhu\t\t: " << bantu->info.suhu << endl;
					cout << "Tekanan Darah\t: " << bantu->info.sistol <<"/" << bantu->info.diastol << endl;
					cout << "Vaksin yang diambil\t: ";if(bantu->info.jenisvaksin==1){cout << "Sinovac";}else if(bantu->info.jenisvaksin==2){cout << "Astrazeneca";}else if(bantu->info.jenisvaksin==3){cout << "Moderna";}
					cout << endl;
					cout << "Status Vaksinasi\t: Belum melakukan vaksinasi" << endl;
					cout << "Lakukan vaksinasi? ";cin>>setujuvaksin;
					if(setujuvaksin=="y"||setujuvaksin=="Y"){
						cout << "Yakin? "; cin>>yakinvaksin;
						if(yakinvaksin=="y" || yakinvaksin=="Y"){
							statussementara=1;
							bantu->info.status=statussementara;
						}
					}
					break;
				}
				else if(bantu->info.status==1){
					cout << "Nama\t\t: " << bantu->info.nama << endl;
					cout << "Umur\t\t: " << bantu->info.umur << endl;
					cout << "NIK\t\t: " << bantu->info.NIK << endl;
					cout << "Suhu\t\t: " << bantu->info.suhu << endl;
					cout << "Tekanan Darah\t: " << bantu->info.sistol <<"/" << bantu->info.diastol << endl;
					cout << "Vaksin yang diambil\t: ";if(bantu->info.jenisvaksin==1){cout << "Sinovac";}else if(bantu->info.jenisvaksin==2){cout << "Astrazeneca";}else if(bantu->info.jenisvaksin==3){cout << "Moderna";}
					cout << endl;
					cout << "Status Vaksinasi\t: Sudah melakukan vaksinasi pertama" << endl;
					cout << "Lakukan vaksinasi? ";cin>>setujuvaksin;
					if(setujuvaksin=="y"||setujuvaksin=="Y"){
						cout << "Yakin? "; cin>>yakinvaksin;
						if(yakinvaksin=="y" || yakinvaksin=="Y"){
							statussementara=2;
							bantu->info.status=statussementara;
						}
					}
					break;
				}
				else if(bantu->info.status==2){
					cout << "Nama\t\t: " << bantu->info.nama << endl;
					cout << "Umur\t\t: " << bantu->info.umur << endl;
					cout << "NIK\t\t: " << bantu->info.NIK << endl;
					cout << "Suhu\t\t: " << bantu->info.suhu << endl;
					cout << "Tekanan Darah\t: " << bantu->info.sistol <<"/" << bantu->info.diastol << endl;
					cout << "Vaksin yang diambil\t: ";if(bantu->info.jenisvaksin==1){cout << "Sinovac";}else if(bantu->info.jenisvaksin==2){cout << "Astrazeneca";}else if(bantu->info.jenisvaksin==3){cout << "Moderna";}
					cout << endl;
					cout << "Status Vaksinasi\t: Proses vaksinasi anda sudah selesai" << endl;
					break;
				}
			}
		}
	}
	
}

void hapusdata(typeinfo IH){
	typeptr bantu, hapus;
	
	if (awal==NULL){	
		cout << "Data Masih Kosong" << endl;
	}
	else{	
		if (awal->info.NIK==IH){                     	//menghapus data yang ada diawal	
			hapus=awal;
			awal=hapus->next;
			free(hapus);
		}
		else{	
			bantu=awal;	                               // proses mencari data yang akan dihapus
			while ((bantu->next->info.NIK!=IH) && (bantu->next!=NULL)){
				bantu=bantu->next;
			}
			hapus=bantu->next;
			if (hapus==NULL){	
				cout << "Data tidak ditemukan" << endl; 
			}
			else{	
				if (hapus==akhir){                     	//menghapus data paling akhir
					akhir=bantu;
					akhir->next=NULL;
				}
				else{  			                    	//menghapus data yang ada di tengah
					bantu->next=hapus->next;
				}
				free(hapus);
			}
		}
	}
}

void caridata(){
	typeptr cari;
	long int hapusNIK;
	string yakinhapus;
	bool cek;
	cari=awal;

	cout << "Masukkan NIK yang akan dihapus : "; cin>>hapusNIK;
	if (awal==NULL){
		cout << "Data Kosong" << endl;
	}
	else{
		while(cari!=NULL){
			
			if(hapusNIK==cari->info.NIK){
				cout << cari->info.nama<< endl;
				cek=1;
			}
			cari=cari->next;
		}
		if(cek==1){
			cout << "Yakin hapus data? "; cin>>yakinhapus;
			if(yakinhapus=="y"||yakinhapus=="Y"){
				hapusdata(hapusNIK);
			}
		}
	}
}
