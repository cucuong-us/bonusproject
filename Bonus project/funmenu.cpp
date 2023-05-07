#include"library.h"
int MENUlogin(listnamhoc& lNH, giangvien*& a)
{ 
	system("cls");
	int choose;
	cout << "									Thoat (0)" << endl;
	cout << "			Sinh vien(1)    Giang vien(2)              " << endl << endl;
	choose=nhapSoNguyen(0, 2);
	if (choose == 0) exit(0);
	else if (choose == 2) MENUlogingv(lNH,a);
	return 0;
}
int MENUlogingv(listnamhoc& lNH, giangvien* a)
{
	system("cls");
	int choose = 0;
	char* tendn, * mk;
	int vitri;
	cout << "			Ten dang nhap:";
	nhapchuoi(tendn);
	cout << "			Mat khau (mac dinh la 123):";
	nhapchuoi(mk);
	while (checklogingv(a, tendn, mk) == -1)
	{
		system("cls");
		cout << "										Tro ve(0)" << endl << endl;
		cout << "Ten dang nhap hoac mat khau khong dung!!!.Dang nhap lai(1). " << endl;
		choose = nhapSoNguyen(0, 1);
		if (choose == 0) MENUlogin(lNH,a);
		else {
			system("cls");
			cout << "			Ten dang nhap:";
			nhapchuoi(tendn);
			cout << "			Mat khau (mac dinh la 123):";
			nhapchuoi(mk);
		}
	} 
	vitri = checklogingv(a, tendn, mk);
	a = (a + vitri);
	MENUtrangcanhangv(lNH,a);
	return 0;
}
int MENUtrangcanhangv(listnamhoc& lNH,giangvien*& a)
{
	int choose;
	system("cls");
	
	cout << "Dang xuat(0)		"<<endl<<endl;
	cout << "\t\t\tXin chao " << (a )->hovaten << endl;
	cout << "\nXem ho so cua ban(1)"<<endl;
	cout << "Doi mat khau(2)" << endl;
	cout << "Tao ra nam hoc moi(3)"<<endl;
	cout << "Them lop vao nam hoc(4)" << endl;
	cout << "Them hoc sinh vao lop (thu cong) (5)" << endl;
	cout << "Them hoc sinh vao lop (tu file CSV) (6)" << endl;
	choose = nhapSoNguyen(0,6);
	if (choose == 0) MENUlogin(lNH, a);
	else if (choose == 1) {
		MENUhosogv(lNH, a);
	}
	else if (choose == 2) MENUdoimatkhau(lNH, a);
	else if (choose == 3) MENUtaonamhoc(a, lNH);
	else if (choose == 4) MENUtaolop(a, lNH);
	else if (choose == 5) MENUthemsv(a, lNH);
	return 0;
}
int MENUhosogv(listnamhoc& lNH,giangvien* &a)
{
	int choose;
	system("cls");
	cout << "Dang xuat(0)					Tro ve(1)" << endl << endl;
	cout << "Thong tin cua ban:" << endl;
	cout << "+Ho va tem:" << (a )->hovaten<<endl;
	cout << "+Ngay sinh:" << (a )->ngaysinh << endl;
	cout << "+Thuoc bo mon:" << (a)->bomon << endl;
	choose = nhapSoNguyen(0,1);
	if (choose == 1) MENUtrangcanhangv(lNH,a);
	else MENUlogin(lNH,a);
	return 0;
}
void MENUdoimatkhau(listnamhoc& lNH,giangvien* a)
{
	int choose,dau,cuoi;
	system("cls");
	char* mknow=new char;
	cout << "Nhap mat khau hien tai:";
	nhapchuoi(mknow);
	while (strcmp(mknow, (a)->matkhau) != 0)
	{ 
		system("cls");
		cout << "							Tro ve(0)" << endl;
		cout << "Mat khau khong dung!!! Nhap lai (1)" << endl;
		choose = nhapSoNguyen(0,1);
		cout << "Nhap mat khau hien tai:";
		nhapchuoi(mknow);
	}
	char* tem1;
	char* tem2;
	cout << "Nhap mat khau muon thay doi:";
	nhapchuoi(tem1);
	cout << "Xac nhan lai mat khau:";
	nhapchuoi(tem2);
	while (strcmp(tem1, tem2) != 0)
	{
		system("cls");
		cout << "									Tro ve(0)" << endl;
		cout << "2 lan nhap khong trung khop nhau!! Nhap lai(1)" << endl;
		choose = nhapSoNguyen(0,1);
		if (choose == 0) {
			delete mknow, tem1, tem2;
			MENUtrangcanhangv(lNH,a);
		}
		else {
			system("cls");
			cout << "Nhap mat khau muon thay doi:";
			nhapchuoi(tem1);
			cout << "Xac nhan lai mat khau:";
			nhapchuoi(tem2);
		}
	}
	strcpy((a )->matkhau, tem1);
	delete mknow, tem1, tem2;
	cout << "							Tro ve (0)";
	cout << "\nDoi mat khau thanh cong!!!";
	choose = nhapSoNguyen(0,0);
	if (choose == 0) MENUtrangcanhangv(lNH,a);
}
void MENUtaonamhoc(giangvien* a, listnamhoc& lNH)
{
	int nam;
	system("cls");
	cout << "Nhap nam nam hoc bat dau.";
	nam = nhapSoNguyen(2000, 2100);
	tao_nam_hoc_moi(lNH, nam);
	system("cls");
	cout << "							Tro ve(0)" << endl;
	cout << "Nam hoc " << lNH.tail->nambatdau << "-" << lNH.tail->nambatdau + 1 << " da duoc tao !!" << endl;
	int choose;
	choose = nhapSoNguyen(0, 0);
	if (choose == 0) MENUtrangcanhangv(lNH, a);
}
void MENUtaolop(giangvien* a, listnamhoc& lNH)
{
	int nam, n, choose;
	do {
		choose = -1;
		system("cls");
		cout << "Nam hoc muon tao lop,";
		nam = nhapSoNguyen(2000, 2100);
		n = 0;
		nodenamhoc* p = lNH.head;
		while (p != NULL)
		{
			if (lNH.head->nambatdau == nam) {
				n++; break;
			}
			p = p->next;
		}
		if (n == 0) {
			cout << "Nam hoc da nhap khong ton tai!!!";
			cout << "							Tro ve(0)" << endl;
			cout << "					Nhap lai(1)			" << endl;
			choose = nhapSoNguyen(0, 1);
		}
	} while  (choose == 1);
	if (choose == 0) MENUtrangcanhangv(lNH, a);
	else
	{
		nodenamhoc* p = new nodenamhoc;
		do
		{
			system("cls");
			nodelop* tem = new nodelop;
			tem->next = NULL;
			cout << "Ten lop hoc muon them:";
			nhapchuoi(tem->tenlop);
			p = lNH.head;
			while (p != NULL)
			{
				if (p->nambatdau == nam) {
					if (p->danhsachlop.head == NULL)
					{
						p->danhsachlop.head = tem;
						p->danhsachlop.tail = tem;
					}
					else {
						p->danhsachlop.tail->next = tem;
						p->danhsachlop.tail = tem;
					}
				}
				p = p->next;
			}
			cout << "Lop " << tem->tenlop << " da duoc them vao thanh cong!!!" << endl;
			cout << "Tro ve (0)				Tiep tuc them(1)" << endl;
			choose=nhapSoNguyen(0, 1);
		} while (choose == 1);
		if(choose==0 ) MENUtrangcanhangv(lNH, a);
	}
}
void MENUthemsv(giangvien* a, listnamhoc& lNH)
{
	nodenamhoc* p = new nodenamhoc;
	int nam, n, choose;
	do {
		choose = -1;
		system("cls");
		cout << "Nam hoc muon them sinh vien,";
		nam = nhapSoNguyen(2000, 2100);
		n = 0;
		p = lNH.head;
		while (p != NULL)
		{
			if (lNH.head->nambatdau == nam) {
				n++; break;
			}
			p = p->next;
		}
		if (n == 0) {
			cout << "Nam hoc da nhap khong ton tai!!!";
			cout << "							Tro ve(0)" << endl;
			cout << "					Nhap lai(1)			" << endl;
			choose = nhapSoNguyen(0, 1);
		}
	} while (choose == 1);
	if (choose == 0) MENUtrangcanhangv(lNH, a);
	else
	{
		nodelop* p1 = new nodelop;
		char* timlop = new char;
		do {
			n = 0,choose=-1;
			system("cls");
			cout << "Nhap ten lop muon them sinh vien:";
			//cout << timlop;
			nhapchuoi(timlop);
			p1 = p->danhsachlop.head;
			while (p1 != NULL)
			{
				if (strcmp(timlop, p1->tenlop) == 0) {
					n++; break;
				}
				p1 = p1->next;
			}
			if (n == 0)
			{
				cout << "Lop " << timlop << " khong ton tai trong nam hoc " << p->nambatdau << "-" << p->nambatdau + 1<<" !!!!"<<endl;
				cout << "							Tro ve(0)" << endl;
				cout << "Nhap lai(1)			" << endl;
				choose=nhapSoNguyen(0, 1);
			}
		} while (choose ==1);
		if(choose ==0) MENUtrangcanhangv(lNH, a);
		else
		{
			do
			{
				nodesv* tem = new nodesv;
				tem->data.lop = new char;
				int n;
				strcpy(tem->data.lop, p1->tenlop);
				cout << "Nhap thong tin sinh vien muon them vao lop " << p1->tenlop << endl;
				cout << "MSSV,";
				nhapmssv(tem->data.mssv);
				cout << "Ten:";
				nhapchuoi(tem->data.ten);
				cout << "Ho:";
				nhapchuoi(tem->data.ho);
				cout << "Gioi tinh:";
				nhapchuoi(tem->data.ngaysinh);
				do
				{
					n = 0;
					cout << "ngay sinh (dd/mm/yyyy):";
					nhapchuoi(tem->data.ngaysinh);
					if (tem->data.ngaysinh[0] > '9' || tem->data.ngaysinh[0] < '0') n++;
					if (tem->data.ngaysinh[1] > '9' || tem->data.ngaysinh[1] < '0') n++;
					if (tem->data.ngaysinh[2] != '/') n++;
					if (tem->data.ngaysinh[3] > '9' || tem->data.ngaysinh[3] < '0') n++;
					if (tem->data.ngaysinh[4] > '9' || tem->data.ngaysinh[4] < '0') n++;
					if (tem->data.ngaysinh[5] != '/') n++;
					if (tem->data.ngaysinh[6] > '9' || tem->data.ngaysinh[6] < '0') n++;
					if (tem->data.ngaysinh[7] > '9' || tem->data.ngaysinh[7] < '0') n++;
					if (tem->data.ngaysinh[8] > '9' || tem->data.ngaysinh[8] < '0') n++;
					if (tem->data.ngaysinh[9] > '9' || tem->data.ngaysinh[9] < '0') n++;
				} while (n != 0);
				cout << "ID xa hoi:";
				nhapchuoi(tem->data.cccd);
				if (p1->danhsachsv.head == NULL) {
					p1->danhsachsv.head = tem;
					p1->danhsachsv.tail = tem;
				}
				else {
					p1->danhsachsv.tail->next = tem;
					p1->danhsachsv.tail = tem;
				}
				cout << "Them sinh vien vao lop thanh cong !!!!" << endl;
				cout << "Tro ve (0)				Tiep tuc them(1)" << endl;
				choose = nhapSoNguyen(0, 1);
			} while (choose == 1);
			if (choose == 0)MENUtrangcanhangv(lNH, a);
		}
	}
}
	