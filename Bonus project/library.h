#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include<iomanip>
using namespace std;
struct giangvien {
	char* hovaten;
	char* ngaysinh;
	char* bomon;
	char* tentk;
	char* matkhau;
};
struct sinhvien {
	char* tentk;
	char* matkhau;
	char* lop;
	char* mssv;
	char* ten;
	char* ho;
	char* gioitinh;
	char* ngaysinh;
	char* cccd;
	//void inthongtin() {
	//	cout << lop << endl;
	//	cout << mssv << endl;
	//	cout<<ho<<" "<< ten << endl;
	//	cout << gioitinh << endl;
	//	cout << ngaysinh << endl;
	//	cout<<
	//}

};
struct nodesv {
	sinhvien data;
	nodesv* next;
};
struct listsv {
	nodesv* head=NULL;
	nodesv* tail=NULL;
};
struct nodelop {
	char* tenlop;
	listsv danhsachsv;
	nodelop* next;
};
struct listlop {
	nodelop* head=NULL;
	nodelop* tail=NULL;
};
struct nodenamhoc {
	int nambatdau;
	listlop danhsachlop;
	nodenamhoc* next;
};
struct listnamhoc {
	nodenamhoc* head=NULL;
	nodenamhoc* tail=NULL;
};
void nhapchuoi(char*& a);
int nhapSoNguyen(int dau, int cuoi);
void imforgiangvien(giangvien*& a);
void nhapmssv(char*& mssv);
int MENUlogin(listnamhoc& lNH,giangvien*& a);
int MENUlogingv(listnamhoc& lNH, giangvien* a);
int checklogingv(giangvien* a, char* tendn, char* mk);
int MENUhosogv(listnamhoc& lNH,giangvien*& a);
int MENUtrangcanhangv(listnamhoc& lNH,giangvien* &a);
void MENUdoimatkhau(listnamhoc& lNH,giangvien* a);
void them_sinh_vien_vao_lop(listsv& danhsachSV, sinhvien infor);
void them_lop_vao_nam_hoc(nodenamhoc*& NH, nodelop* &lop);
void tao_nam_hoc_moi(listnamhoc& lNH, int nambatdau);
void MENUtaonamhoc(giangvien* a, listnamhoc& lNH);
void MENUtaolop(giangvien* a, listnamhoc& lNH);
void MENUthemsv(giangvien* a, listnamhoc& lNH);