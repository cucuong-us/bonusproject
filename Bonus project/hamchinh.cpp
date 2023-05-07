#include"library.h"
void nhapchuoi(char*& a)// cap  phat dong de nhap chuoi
{
	char b[100];
	cin.getline(b, 100);
	a = new char[strlen(b) + 1];
	strcpy(a, b);
}
int nhapSoNguyen(int dau, int cuoi) //nhap vao bat buoc la mot so nguyen, khong phai thi nhap lai
{

	char a[20];
	int n = 0;
	if (dau == cuoi) {
		do
		{
			n = 0;
			cout << "Nhap so " << dau << " :";
			cin.getline(a, 20);
			for (int i = 0; i < strlen(a); i++)
			{
				if (a[i] < 48 || a[i]>57) n++;
			}
			if (atoi(a) < dau || atoi(a) > cuoi) n++;
		} while (n != 0);
		return atoi(a);
	}
	else {
		do
		{
			n = 0;
			cout << "chon 1 so nguyen tu " << dau << " den " << cuoi << ":";
			cin.getline(a, 20);
			for (int i = 0; i < strlen(a); i++)
			{
				if (a[i] < 48 || a[i]>57) n++;
			}
			if (atoi(a) < dau || atoi(a) > cuoi) n++;
		} while (n != 0);
		return atoi(a);
	}
}
void nhapmssv(char*& mssv)
{
	char a[20];
	int n;
	do
	{
		n = 0;
		cout << " phai gom 8 chu so:";
		cin.getline(a, 20);
		if (strlen(a) != 8) n++;
		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] < 48 || a[i]>57) n++;
		}
	} while (n != 0);
	mssv = new char[9];
	strcpy(mssv, a);
}
int checklogingv(giangvien* a, char* tendn, char* mk)
{
	for (int i = 0; i < 5; i++)
	{
		if ((strcmp(tendn, (a + i)->tentk) == 0) && (strcmp(mk, (a + i)->matkhau) == 0)) {
			return i;
		}
	}
	return -1;
}

void them_sinh_vien_vao_lop(listsv& danhsachSV, sinhvien infor)
{
	nodesv* tem = new nodesv{ infor,NULL };
	if (danhsachSV.head == NULL) {
		danhsachSV.head = tem;
		danhsachSV.tail = tem;
	}
	else {
		danhsachSV.tail->next = tem;
		danhsachSV.tail = tem;
	}
}
void them_lop_vao_nam_hoc(nodenamhoc*& NH, nodelop*& lop)
{
	
}
void tao_nam_hoc_moi(listnamhoc& lNH, int nambatdau)
{
	listlop lLop;
	lLop.head = NULL;
	lLop.tail = NULL;
	nodenamhoc* tem = new nodenamhoc{ nambatdau,lLop,NULL };
	if (lNH.head == NULL)
	{
		lNH.head = tem;
		lNH.tail = tem;
	}
	else
	{
		lNH.tail->next = tem;
		lNH.tail = tem;
	}
}