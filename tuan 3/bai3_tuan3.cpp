#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include<conio.h>
#include<stdio.h>
using namespace std;

typedef struct nhanvien{
	char nhanvienID[4], hoten[20];
	int songaycong, luong;
};
nhanvien nv;

vector <nhanvien> dsNV;
char tenfile[12]="input3.txt";
char file_output[12]="output3.txt";
//--------------------------------------------
//khai bao tat ca cac ham trong chuong trinh.
void showMenu();
void chon();

void inNV(nhanvien nv);
void inDSNV();
nhanvien NhapNVtuBP();
void docfile(char* tenfile);// doc file
void ghifile(char* file_output);// ghi file
void SapXep();
bool themNV(nhanvien nv);
bool xoaNV(char* nvID);
void editNV(nhanvien nvEdit);
bool search_nvID(char *nvMA);

//--------------------------------------------
//ham int main
int main()
{
	docfile(tenfile);
	cout << "\t\tThong tin nhan vien ban dau" << endl;
	inDSNV();
	///bat dau xu ly
	showMenu();
	chon();
	ghifile(tenfile);
	system("pause");
}
//--------------------------------------------
//doc file
void docfile(char* tenfile)
{
	fstream file;
	file.open(tenfile,ios::in);
	if (file.fail())
		cout<<"khong mo duoc file !!"<<endl;
	else
		{
			while(!file.eof())
			{	
				nhanvien nv;
				file.getline(nv.nhanvienID,4);
				file.getline(nv.hoten,21);
				file>>nv.songaycong;
				file.ignore();
				dsNV.push_back(nv);
			}
			file.close();			
		}
}
//--------------------------------------------
// ham hien thi meunu
void showMenu()
{	
	cout << "1. Nhap thong tin nhan vien tu ban phim" << endl;
	cout << "2. Sap Xep danh sach tang dan theo so ngay cong." << endl;
	cout << "3. Them 1 nhan vien. " << endl;
	cout << "4. Xoa 1 nhan vien. " << endl;
	cout << "5. Sua thong tin 1 nhan vien. " << endl;
	cout << "6. Tim kiem nhan vien theo ma so nhan vien. " << endl;
	cout << "7. Thoat. " << endl << endl;
}
//--------------------------------------------
// ham lua chon
void chon()
{
	nhanvien nv3, nvEdit;
	char nvID[4], nvMA[4];
	int select;
	do{
		cout << "\tLua chon cua ban la: ";
		cin >> select;
		switch (select)
		{
			case 1:
				// nhap nhan vien tu ban phim
				int n;
				do{
					cout << "nhap so luong nhan vien: ";
					cin >> n;	
				} while( n < 0 || n > 10);
				dsNV.resize(n);
				for ( int i = 0; i < n; i++){	
					dsNV[i] = NhapNVtuBP();
				}
				showMenu();
				do{
					cout << "\tLua chon cua ban la: ";
					cin >> select;	
				switch (select)
				{
					case 2:
						//sap xep danh sach nhan vien theo so ngay cong
						cout << "\t\tDanh sach sau khi da Sap Xep: " << endl;
						SapXep();
						inDSNV();
							break;
					case 3:
						//nhap thong tin nhan vien de them vao
						cout << "\t\tThong tin nhan vien can them" << endl;
						nv3 = NhapNVtuBP();
						themNV(nv3);
						cout << "\t\tDanh sach nhan vien sau khi da them 1 nhan vien." << endl;
						inDSNV();
							break;
					case 4:
						//in ds nhan vien sau khi xoa
						xoaNV(nvID);
						cout << "\t\tDanh sach nhan vien sau khi da xoa 1 nhan vien." << endl;
						inDSNV();
							break;
					case 5:
						//in ds nhan vien sau khi da edit
						cout << "\t\tNhap thong tin nhan vien can edit." << endl;
						nvEdit=NhapNVtuBP();
						editNV(nvEdit);
						cout << "\t\t Danh sach nhan vien sau khi edit:\n";
						inDSNV();
							break;
					case 6:
						//tim thong tin nhanvien bang manv
						search_nvID(nvMA);
							break;
					case 7:
						exit(1);
						break;
					default:
						cout << "Sai cu phap" << endl;	
					}
				}while(select!=7);
			case 7:
					exit(1);
					break;
			default:
				cout << "Du lieu khong ton tai. Nhap lai di nao ...!" << endl;
				break;
		}
	
	} while( select != 1 && select != 7 );
}

//--------------------------------------------
// them nhan vien vao danh sach
bool themNV(nhanvien nv){
	int size=dsNV.size();
	for(int i=0;i<size;i++)
		if(strcmp(nv.nhanvienID,dsNV[i].nhanvienID)==0)
			return false;
	dsNV.push_back(nv);
	return true;
}
//--------------------------------------------
//in ra thong tin cua 1 nhan vien i
void inNV(nhanvien nv){
//	cout << "\t\tthong tin nhan vien." << endl;
	cout <<"maNV: "<< nv.nhanvienID << endl;
	cout <<"tenNV: "<<nv.hoten  << endl;
	cout <<"songaycong: "<<nv. songaycong << endl;
	cout <<"luongNV: "<< nv.songaycong*300000 << endl;
	cout << "---------------------"<< endl;
}
//--------------------------------------------
// in ra danh sach thong tin nhan vien tu ham inNV
void inDSNV(){
	int size=dsNV.size();
	for(int i=0;i<size;i++)
		inNV(dsNV[i]);
}
//--------------------------------------------
// nhap thong tin nhan vien tu ban phim
nhanvien NhapNVtuBP(){
	nhanvien nv;
//	cout << "\t\tnhap thong tin nhan vien can them." << endl;
	cout<<"Nhap ma nv: ";fflush(stdin);
	gets(nv.nhanvienID);
	cout<<"Nhap ten nv: ";fflush(stdin);
	gets(nv.hoten);
	cout<<"Nhap songaycong: ";
	cin>>nv.songaycong;
	cout<<"Nhap luong nv: " << nv.songaycong*300000 << endl;
	cout << "----------------------"<< endl<<endl;
	return nv;
}
//--------------------------------------------

void SapXep(){
	int size=dsNV.size();
	for( int i = 0; i < size-1; i++){
		for( int j = i+1; j < size; j++){
			if(dsNV[i].songaycong > dsNV[j].songaycong)
			swap( dsNV[i], dsNV[j]);
		}
	}
}

//--------------------------------------------
//xoa di thong tin 1 nhan vien
bool xoaNV(char* nvID){
	
	cout << "nhap ma nhan vien can xoa:";
	cin >> nvID;
		int size=dsNV.size();
		int vtxoa=-1;
		for(int i=0;i<size;i++)
		if(strcmp(nvID,dsNV[i].nhanvienID)==0){
			vtxoa=i;
			break;
		}
		if(vtxoa!=-1){
			dsNV.erase(dsNV.begin()+vtxoa);
			return true;
		}
		return false;
}
//--------------------------------------------
// chinh sua thong tin nhan vien
void editNV(nhanvien nvEdit){
		int size=dsNV.size();
		int vtedit=-1;
		for(int i=0;i<size;i++)
		if(strcmp(nvEdit.nhanvienID,dsNV[i].nhanvienID)==0){
			vtedit=i;
			break;
		}
	if(vtedit!=-1){	
		strcpy(dsNV[vtedit].nhanvienID,nvEdit.nhanvienID);
			strcpy(dsNV[vtedit].hoten,nvEdit.hoten);
			dsNV[vtedit].songaycong=nvEdit.songaycong;
			dsNV[vtedit].luong=nvEdit.luong;
	}
}
//--------------------------------------------
// ham tim kiem nhan vien theo ma nhan vien
bool search_nvID(char* nvMA){
	cout << "nhap ma nhan vien can tim kiem:";
	cin >> nvMA;
		int size=dsNV.size();
		int vt_search=-1;
		for(int i=0;i<size;i++)
		if(strcmp(nvMA,dsNV[i].nhanvienID)==0){
			vt_search=i;
			cout << "\t\tThong tin nhan vien can tim la:" << endl;
			inNV(dsNV[i]);
			break;
			return true;
		}
		return false;		
}
//--------------------------------------------
//ham ghi file
void ghifile(char* tenfile)
{
	fstream file;
	file.open(file_output,ios::out);
	if (file.fail())
		cout<<"khong mo duoc file !!"<<endl;
	else
		{
			int n = dsNV.size();
			for(int i = 0; i < n-1; i++)
			{
				file<<dsNV[i].nhanvienID << endl;
				file<<dsNV[i].hoten << endl;
				file<<dsNV[i].songaycong << endl;
				file<<dsNV[i].songaycong*300000 << endl;				
			}
			file<<dsNV[n-1].nhanvienID << endl;
			file<<dsNV[n-1].hoten << endl;
			file<<dsNV[n-1].songaycong << endl;
			file<<dsNV[n-1].songaycong*300000 << endl;	
		}
}
