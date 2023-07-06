#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <math.h>
#include<iomanip>
#include<string>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
struct giangvien {
	char* hovaten;
	char* ngaysinh;
	char* bomon;
	char* tentk;
	char* matkhau;
};
struct diem1mon
{
	float quatrinh=-1;
	float cuoiki;
	float giuaki;
	char* ghichu;
};
struct nodediemtongket
{
	char* monhoc ;
	float diemtongket;
	nodediemtongket* next = NULL;
};
struct listdiemtongket
{
	nodediemtongket* head = NULL;
	nodediemtongket* tail = NULL;
};
struct sinhvien {
	char* tentk;
	char* matkhau=new char[20]{"123"};
	char* stt;
	char* lop;
	char* mssv;
	char* ten;
	char* ho;
	char* gioitinh;
	char* ngaysinh;
	char* cccd;
	diem1mon diem;
	listdiemtongket ldtk;
};
struct nodesv {
	sinhvien data;
	nodesv* next=NULL;
};
struct listsv {
	nodesv* head=NULL;
	nodesv* tail=NULL;
};
struct nodelop {
	char* tenlop;
	listsv danhsachsv;
	nodelop* next=NULL;
};
struct listlop {
	nodelop* head=NULL;
	nodelop* tail=NULL;
};
struct monhoc {
	char* id;
	char* tenmonhoc;
	char* tenlop;
	char* tengv;
	int sosvtoida=50;
	int sotinchi;
	int ngayhoc;
	int buoihoc;
	listsv danhsachsv;
	void inNgay()
	{
		if (ngayhoc == 1) cout << "Thu hai" << endl;
		else if (ngayhoc == 2) cout << "Thu ba" << endl;
		else if (ngayhoc == 3) cout << "Thu tu" << endl;
		else if (ngayhoc == 4) cout << "Thu nam" << endl;
		else if (ngayhoc == 5)  cout << "Thu sau" << endl;
		else cout << "Thu bay" << endl;
	};
	void inBuoi()
	{
		if (buoihoc == 1) cout << "S1 (7h30)" << endl;
		else if (buoihoc == 2) cout << "S2 (9h30)" << endl;
		else if (buoihoc == 3) cout << "S3 (13h30)" << endl;
		else cout << "S4 (15h30)" << endl;
	}
};
struct nodemonhoc {
	monhoc data;
	nodemonhoc* next=NULL;
};
struct listmonhoc {
	nodemonhoc* head = NULL;
	nodemonhoc* tail = NULL;
};
struct nodehocki {
	int tenhk;
	char* ngaybatdau;
	char* ngayketthuc;
	listmonhoc danhsachmon;
	nodehocki* next=NULL;
};
struct nodenamhoc {
	int nambatdau;
	listlop danhsachlop;
	nodenamhoc* next;
	nodehocki* headhk;
	nodehocki* tailhk;
};
struct listnamhoc {
	giangvien** imfor=NULL;
	nodenamhoc* head=NULL;
	nodenamhoc* tail=NULL;
	nodehocki* hockihientai=new nodehocki;
	int namhientai;
};
float nhapdiem();
void nhapchuoi(char*& a);
int nhapSoNguyen(int dau, int cuoi);
void imforgiangvien(giangvien**a);
void nhapmssv(char*& mssv);
int MENUlogin(listnamhoc& lNH);
int MENUlogingv(listnamhoc& lNH);
void MENUloginsv(listnamhoc lNH);
void MENUtrangcanhansv(listnamhoc& lNH, nodesv*& tem);
void MENUhososv(listnamhoc& lNH, nodesv*& tem);
void MENUdoimatkhausv(listnamhoc& lNH, nodesv*& tem);
int checklogingv(giangvien** a, char* tendn, char* mk);
int MENUhosogv(listnamhoc& lNH,giangvien*& a);
int MENUtrangcanhangv(listnamhoc& lNH,giangvien* &a);
void MENUdoimatkhau(listnamhoc& lNH,giangvien* &a);
void them_sinh_vien_vao_lop(listsv& danhsachSV, sinhvien infor);
void them_lop_vao_nam_hoc(nodenamhoc*& NH, nodelop* &lop);
void tao_nam_hoc_moi(listnamhoc& lNH, int nambatdau);
void MENUtaonamhoc(giangvien* a, listnamhoc& lNH);
void MENUtaolop(giangvien* a, listnamhoc& lNH);
void MENUthemsv(giangvien* a, listnamhoc& lNH);
void MENUthemsvCSV(giangvien* a, listnamhoc& lNH);
void doichuoi(char*& a, char b[]);
void MENUtaohocki(giangvien* a, listnamhoc& lNH);
void MENUthemmonhoc(giangvien* a, nodehocki* nHK, listnamhoc& lNH);
void MENUhockihientai(giangvien* a, listnamhoc& lNH);
void MENUxemdanhsachcacmon(giangvien* a, nodehocki* nHK, listnamhoc& lNH);
void MENUcapnhatthongtinmonhoc(giangvien* a, nodehocki* nHK, listnamhoc& lNH);
void MENUthemsvvaokhoahoc(giangvien* a, nodehocki* nHK, listnamhoc& lNH);
void MENUxoaSinhVien(giangvien* a, nodehocki* nHK, listnamhoc& lNH);
void MENUxoakhoahoc(giangvien* a, nodehocki* nHK, listnamhoc& lNH);
void MENUxemdanhsachcacmonhocmasvhoc(listnamhoc& lNH, nodesv*& tem);
void MENUxemdanhsachlophoc(giangvien* a, listnamhoc& lNH);
void Xemdanhsachcacmon(giangvien* a, listnamhoc& lNH);
void XuatdanhsachSVrafile(giangvien* a, listnamhoc& lNH);
void XuatDanhSachChoGiaoVienNhapBangDiem(giangvien* a, listnamhoc& lNH);
void taifilediemlen(giangvien* a, listnamhoc& lNH);
void Xembangdiemcuamonhoc(giangvien* a, listnamhoc& lNH);
void Xembangdiemcualop(giangvien* a, listnamhoc& lNH);
void SVxemdiem(nodesv*& tem, listnamhoc& lNH);