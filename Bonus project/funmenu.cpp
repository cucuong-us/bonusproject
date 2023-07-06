#include"library.h"
int MENUlogin(listnamhoc& lNH)
{ 
	system("cls");
	int choose;
	cout << "									Thoat (0)" << endl;
	cout << "			Sinh vien(1)    Giang vien(2)              " << endl << endl;
	choose=nhapSoNguyen(0, 2);
	if (choose == 0) exit(0);
	else if (choose == 1) MENUloginsv(lNH);
	else if (choose == 2) MENUlogingv(lNH);
	return 0;
}
int MENUlogingv(listnamhoc& lNH)
{
	if (lNH.imfor == NULL) {
		lNH.imfor = new giangvien * [5];
		imforgiangvien(lNH.imfor);

	}
	system("cls");
	int choose = 0;
	char* tendn, * mk;
	int vitri;
	cout << "			Ten dang nhap:";
	nhapchuoi(tendn);
	cout << "			Mat khau (mac dinh la 123):";
	nhapchuoi(mk);
	while (checklogingv(lNH.imfor, tendn, mk) == -1)
	{
		system("cls");
		cout << "										Tro ve(0)" << endl << endl;
		cout << "Ten dang nhap hoac mat khau khong dung!!!.Dang nhap lai(1). " << endl;
		choose = nhapSoNguyen(0, 1);
		if (choose == 0) MENUlogin(lNH);
		else {
			system("cls");
			cout << "			Ten dang nhap:";
			nhapchuoi(tendn);
			cout << "			Mat khau (mac dinh la 123):";
			nhapchuoi(mk);
		}
	} 
	vitri = checklogingv(lNH.imfor, tendn, mk);
	MENUtrangcanhangv(lNH,lNH.imfor[vitri]);
	return 0;
}
void MENUloginsv(listnamhoc lNH)
{
	int choose,n=0;
	nodesv* tem = new nodesv{ NULL };
	nodenamhoc *p = lNH.head;
	nodelop* p1 = NULL;
	nodesv* p2 = NULL;
	char* tendn, * mk;
	do
	{
		choose = -1;
		system("cls");
		cout << "			Ten dang nhap(mssv cua ban):";
		nhapchuoi(tendn);
		cout << "			Mat khau (mac dinh la 123):";
		nhapchuoi(mk);
		while (p != NULL)
		{
			p1 = p->danhsachlop.head;
			while (p1!= NULL)
			{
				p2 = p1->danhsachsv.head;
				while (p2 != NULL)
				{
					if (strcmp(p2->data.mssv, tendn) == 0 && strcmp(mk, p2->data.matkhau) == 0) {
						tem = p2; n++;
					}
					p2= p2->next;
				}
				p1 = p1->next;
			}
			p = p->next;
		}
		if (n==0)
		{
			system("cls");
			cout << "										Tro ve(0)" << endl << endl;
			cout << "Ten dang nhap hoac mat khau khong dung!!! Hoac ban can cho cho den khi giang vien them ban vao lop hoc." << endl;
			cout << "\t\t\tDang nhap lai(1)" << endl;
			choose = nhapSoNguyen(0, 1);
		}
	} while (choose == 1);
	if (choose == 0) MENUlogin(lNH);
	else MENUtrangcanhansv(lNH, tem);
}
void MENUtrangcanhansv(listnamhoc& lNH, nodesv* &tem)
{
	int choose;
	system("cls");
	cout << "Dang xuat(0)		" << endl << endl;
	cout << "\t\t\tXin chao " << tem->data.ho<<" "<<tem->data.ten << endl;
	cout << "\nXem ho so cua ban(1)				Doi mat khau(2)" << endl;
	cout << "Xem cac mon ma ban dang hoc(3)" << endl;
	cout << "Xem diem cua ban(4)" << endl;
	choose = nhapSoNguyen(0, 4);
	if (choose == 0) MENUlogin(lNH);
	else if (choose == 1) MENUhososv(lNH, tem);
	else if (choose == 2) MENUdoimatkhausv(lNH, tem);
	else if (choose == 3) MENUxemdanhsachcacmonhocmasvhoc(lNH, tem);
	else if (choose == 4) SVxemdiem(tem,lNH);
}
void MENUhososv(listnamhoc& lNH, nodesv* &tem)
{
	int choose;
	system("cls");
	cout << "Dang xuat(0)					Tro ve(1)" << endl << endl;
	cout << "+Thong tin cua ban:" << endl;
	cout << "+Ma so sinh vien:"<<tem->data.mssv << endl;
	cout << "+Ho va ten:" << tem->data.ho<<" "<<tem->data.ten << endl;
	cout << "+Lop:" << tem->data.lop << endl;
	cout << "+Ngay sinh:" << tem->data.ngaysinh << endl;
	cout << "+Gioi tinh:" << tem->data.gioitinh << endl;
	cout << "+ID xa hoi:" << tem->data.cccd << endl;
	choose = nhapSoNguyen(0, 1);
	if (choose == 1) MENUtrangcanhansv(lNH, tem);
	else MENUlogin(lNH);
}
void MENUdoimatkhausv(listnamhoc& lNH, nodesv* &tem)
{
	int choose;
	system("cls");
	char* mknow = new char;
	cout << "Nhap mat khau hien tai:";
	nhapchuoi(mknow);
	while (strcmp(mknow, tem->data.matkhau) != 0)
	{
		system("cls");
		cout << "							Tro ve(0)" << endl;
		cout << "Mat khau khong dung!!! Nhap lai (1)" << endl;
		choose = nhapSoNguyen(0, 1);
		if (choose == 0)
		{
			MENUtrangcanhansv(lNH, tem); return;
		}
		cout << "Nhap mat khau hien tai:";
		nhapchuoi(mknow);
	}
	cout << lNH.head->danhsachlop.head->danhsachsv.head->data.mssv << endl;
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
		choose = nhapSoNguyen(0, 1);
		if (choose == 0) {
			delete mknow, tem1, tem2;
			MENUtrangcanhansv(lNH, tem);
		}
		else {
			system("cls");
			cout << "Nhap mat khau muon thay doi:";
			nhapchuoi(tem1);
			cout << "Xac nhan lai mat khau:";
			nhapchuoi(tem2);
		}
	}
	strcpy(tem->data.matkhau, tem1);
	cout << lNH.head->danhsachlop.head->danhsachsv.head->data.mssv << endl;
	cout << "							Tro ve (0)";
	cout << "\nDoi mat khau thanh cong!!!";
	choose = nhapSoNguyen(0, 0);
	if (choose == 0) MENUtrangcanhansv(lNH, tem);
}
int MENUtrangcanhangv(listnamhoc& lNH,giangvien*& a)
{
	int choose;
	system("cls");
	
	cout << "Dang xuat(0)		"<<endl<<endl;
	cout << "\t\t\tXin chao " << (a )->hovaten << endl;
	cout << "\nXem ho so cua ban(1)				Doi mat khau(2)"<<endl;
	cout << "Tao ra nam hoc moi(3)				Them lop vao nam hoc(4)"<<endl;
	cout << "Them hoc sinh vao lop (thu cong) (5)		Them hoc sinh vao lop (tu file CSV) (6)" << endl;
	cout << "Tao ra hoc ki moi(7)				Thao tac voi hoc ki hien tai (8)"<<endl;
	cout << "Xem danh sach cac lop (9)			Xem bang diem cua lop(10)"<< endl;
	cout << "" << endl;
	choose = nhapSoNguyen(0,10);
	if (choose == 0) MENUlogin(lNH);
	else if (choose == 1) {
		MENUhosogv(lNH, a);
	}
	else if (choose == 2) MENUdoimatkhau(lNH, a);
	else if (choose == 3) MENUtaonamhoc(a, lNH);
	else if (choose == 4) MENUtaolop(a, lNH);
	else if (choose == 5) MENUthemsv(a, lNH);
	else if (choose == 6) MENUthemsvCSV(a, lNH);
	else if (choose == 7) MENUtaohocki(a, lNH);
	else if (choose == 8) MENUhockihientai(a,lNH);
	else if (choose == 9) MENUxemdanhsachlophoc(a, lNH);
	else if (choose == 10) Xembangdiemcualop(a, lNH);
	return 0;
}
int MENUhosogv(listnamhoc& lNH,giangvien* &a)
{
	int choose;
	system("cls");
	cout << "Dang xuat(0)					Tro ve(1)" << endl << endl;
	cout << "Thong tin cua ban:" << endl;
	cout << "+Ho va ten:" << (a )->hovaten<<endl;
	cout << "+Ngay sinh:" << (a )->ngaysinh << endl;
	cout << "+Thuoc bo mon:" << (a)->bomon << endl;
	choose = nhapSoNguyen(0,1);
	if (choose == 1) MENUtrangcanhangv(lNH,a);
	else MENUlogin(lNH);
	return 0;
}
void MENUdoimatkhau(listnamhoc& lNH,giangvien* &a)
{
	int choose;
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
		if (choose == 0)
		{
			MENUtrangcanhangv(lNH, a); return;
		}
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
			if (p->nambatdau == nam) {
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
				system("cls");
			}
		} while (choose ==1);
		if(choose ==0) MENUtrangcanhangv(lNH, a);
		else
		{
			do
			{
				nodesv* tem = new nodesv;
				tem->data.lop = new char[strlen(p1->tenlop)+1];
				int n;
				system("cls");
				strcpy(tem->data.lop, p1->tenlop);
				cout << "Nhap thong tin sinh vien muon them vao lop " << p1->tenlop << endl;
				cout << "So thu tu:";
				nhapchuoi(tem->data.stt);
				cout << "MSSV,";
				nhapmssv(tem->data.mssv);
				cout << "Ten:";
				nhapchuoi(tem->data.ten);
				cout << "Ho:";
				nhapchuoi(tem->data.ho);
				cout << "Gioi tinh:";
				nhapchuoi(tem->data.gioitinh);
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
void MENUthemsvCSV(giangvien* a, listnamhoc& lNH)
{
	char* tenfile;
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
			n = 0, choose = -1;
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
				cout << "Lop " << timlop << " khong ton tai trong nam hoc " << p->nambatdau << "-" << p->nambatdau + 1 << " !!!!" << endl;
				cout << "							Tro ve(0)" << endl;
				cout << "Nhap lai(1)			" << endl;
				choose = nhapSoNguyen(0, 1);
				system("cls");
			}
		} while (choose == 1);
		if (choose == 0) MENUtrangcanhangv(lNH, a);
		else 
		{
			do
			{
				choose = -1;
				cout << "Nhap ten file chua du lieu:";
				nhapchuoi(tenfile);
				FILE* fp = NULL;
				fp = fopen(tenfile, "r");
				if (fp==NULL)
				{
					cout << "File khong ton tai!!!" << endl;
					cout << "Tro ve (0)			Nhaplai(1)" << endl;
					choose = nhapSoNguyen(0, 1);
					if (choose == 0) {
						MENUtrangcanhangv(lNH, a);
						return;
					}
				}
				else
				{
					
					while (!feof(fp))
					{	
						nodesv* tem = new nodesv;

						tem->next = NULL;
						char line[100];
						fgets(line,100,fp);
						char delim [2] {","};
						char* token=new char[30];
						token = strtok(line, delim);
						doichuoi(tem->data.stt, token); 
						token = strtok(NULL, delim);
						doichuoi(tem->data.mssv, token);
						token = strtok(NULL, delim);
						doichuoi(tem->data.ho, token);
						token = strtok(NULL, delim);
						doichuoi(tem->data.ten, token);
						token = strtok(NULL, delim);
						doichuoi(tem->data.gioitinh, token);
						token = strtok(NULL, delim);
						doichuoi(tem->data.ngaysinh, token);
						token = strtok(NULL, delim);
						doichuoi(tem->data.cccd, token);
						tem->data.lop = new char;
						strcpy(tem->data.lop, p1->tenlop);
						if (p1->danhsachsv.head == NULL) {
							p1->danhsachsv.head = tem;
							p1->danhsachsv.tail = tem;
						}
						else {
							p1->danhsachsv.tail->next = tem;
							p1->danhsachsv.tail = tem;
						}
					}
					fclose(fp);
					cout << "Them hoc sinh vao lop " << p1->tenlop << " thanh cong!!!" << endl;
					cout << "Tro ve (0)				Tiep tuc them(1)" << endl;
					choose = nhapSoNguyen(0, 1);
				}				
			} while (choose==1);
			if (choose == 0) MENUtrangcanhangv(lNH, a);
		}
	}
}
void MENUtaohocki(giangvien* a, listnamhoc& lNH)
{
	nodenamhoc* p = lNH.head;
	nodehocki* p1 = new nodehocki;
	int nam, n, choose;
	do 
	{
		choose = -1;
		system("cls");
		cout << "Nam hoc muon tao hoc ki,";
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
		nodehocki* now = new nodehocki; 
		do
		{
			n = 0;
			cout << "Ngay bat dau (dd/mm/yyyy):";
			nhapchuoi(now->ngaybatdau);
			if (now->ngaybatdau[0] > '9' || now->ngaybatdau[0] < '0') n++;
			if (now->ngaybatdau[1] > '9' || now->ngaybatdau[1] < '0') n++;
			if (now->ngaybatdau[2] != '/') n++;
			if (now->ngaybatdau[3] > '9' || now->ngaybatdau[3] < '0') n++;
			if (now->ngaybatdau[4] > '9' || now->ngaybatdau[4] < '0') n++;
			if (now->ngaybatdau[5] != '/') n++;
			if (now->ngaybatdau[6] > '9' || now->ngaybatdau[6] < '0') n++;
			if (now->ngaybatdau[7] > '9' || now->ngaybatdau[7] < '0') n++;
			if (now->ngaybatdau[8] > '9' || now->ngaybatdau[8] < '0') n++;
			if (now->ngaybatdau[9] > '9' || now->ngaybatdau[9] < '0') n++;
		} while (n != 0);
		do
		{
			n = 0;
			cout << "Ngay ket thuc (dd/mm/yyyy):";
			nhapchuoi(now->ngayketthuc);
			if (now->ngayketthuc[0] > '9' || now->ngayketthuc[0] < '0') n++;
			if (now->ngayketthuc[1] > '9' || now->ngayketthuc[1] < '0') n++;
			if (now->ngayketthuc[2] != '/') n++;
			if (now->ngayketthuc[3] > '9' || now->ngayketthuc[3] < '0') n++;
			if (now->ngayketthuc[4] > '9' || now->ngayketthuc[4] < '0') n++;
			if (now->ngayketthuc[5] != '/') n++;
			if (now->ngayketthuc[6] > '9' || now->ngayketthuc[6] < '0') n++;
			if (now->ngayketthuc[7] > '9' || now->ngayketthuc[7] < '0') n++;
			if (now->ngayketthuc[8] > '9' || now->ngayketthuc[8] < '0') n++;
			if (now->ngayketthuc[9] > '9' || now->ngayketthuc[9] < '0') n++;
		} while (n != 0);
		cout << "Hoc ki muon them la hoc ki may.";
		n = nhapSoNguyen(1, 3);
		p1 = p->headhk;
		for (int i = 0; i < n-1; i++)
		{
			p1 = p1->next;
		}
		p1->ngaybatdau = new char[11];
		p1->ngayketthuc = new char[11];
		strcpy(p1->ngaybatdau, now->ngaybatdau);
		strcpy(p1->ngayketthuc, now->ngayketthuc);
		p1->tenhk = n;
		lNH.hockihientai = p1;
		lNH.namhientai = nam;
		cout << "Tao hoc ki " << p1->tenhk << " cho nam hoc thanh cong !!!!" << endl;
		cout << "Tiep tuc(0)" << endl;
		choose=nhapSoNguyen(0, 0);
	}
	if(choose==0)MENUhockihientai(a,lNH);
}
void MENUhockihientai(giangvien* a, listnamhoc& lNH)
{
	int choose;
	system("cls");
	cout << "										Tro ve(0)" << endl;
	cout << "Them mon hoc(1)" << endl;
	cout << "Xem danh sach cac mon hoc (thong tin cu the) (2)" << endl;
	cout << "Cap nhat thong tin mon hoc(3)" << endl;
	cout << "Them sinh vien vao mon hoc(4)" << endl;
	cout << "Xoa sinh vien ra khoi mon hoc(5)" << endl;
	cout << "Xoa mon hoc(6)" << endl;
	cout << "Xem danh sach mon hoc (7)" << endl;
	cout << "Xuat danh sach sinh vien dang hoc mon hoc ra file (8)" << endl;
	cout << "Xuat danh sach ra file de giang vien nhap diem(9)" << endl;
	cout << "Tai bang diem ma giang vien da nhap len he thong (10)" << endl;
	cout << "Xem bang diem cua mon hoc (11)" << endl;
	choose = nhapSoNguyen(0, 11);
	if (choose == 1) MENUthemmonhoc(a, lNH.hockihientai, lNH);
	else if (choose == 2) MENUxemdanhsachcacmon(a, lNH.hockihientai, lNH);
	else if (choose == 0) MENUtrangcanhangv(lNH, a);
	else if (choose == 3) MENUcapnhatthongtinmonhoc(a, lNH.hockihientai, lNH);
	else if (choose == 4) MENUthemsvvaokhoahoc(a, lNH.hockihientai, lNH);
	else if (choose == 5) MENUxoaSinhVien(a, lNH.hockihientai, lNH);
	else if (choose == 6) MENUxoakhoahoc(a, lNH.hockihientai, lNH);
	else if (choose == 7) Xemdanhsachcacmon(a, lNH);
	else if (choose == 8) XuatdanhsachSVrafile(a, lNH);
	else if (choose == 9) XuatDanhSachChoGiaoVienNhapBangDiem(a, lNH);
	else if (choose == 10) taifilediemlen(a, lNH);
	else if (choose == 11) Xembangdiemcuamonhoc(a, lNH);
}
void MENUthemmonhoc(giangvien* a, nodehocki* nHK,listnamhoc &lNH)
{
	int choose;
	do
	{
		choose = -1;
		nodemonhoc* tem = new nodemonhoc;
		tem->next = NULL;
		system("cls");
		cout << "ID mon hoc:";
		nhapchuoi(tem->data.id);
		cout << "Ten mon hoc:";
		nhapchuoi(tem->data.tenmonhoc);
		cout << "Ten lop:";
		nhapchuoi(tem->data.tenlop);
		cout << "Ten giao vien:";
		nhapchuoi(tem->data.tengv);
		cout << "So tinh chi,";
		tem->data.sotinchi = nhapSoNguyen(1, 4);
		cout << "Ngay hoc:" << endl;
		cout << "Thu 2(1)   Thu 3(2)     Thu 4(3)      Thu 5(4)      Thu 6(5)      Thu 7(6)" << endl;
		tem->data.ngayhoc = nhapSoNguyen(1, 6);
		cout << "Buoi hoc:" << endl;
		cout << "S1 (7:30) (1)           S2 (9:30) (2)          S3 (13:30) (3)         S4 (15:30) (4)" << endl;
		tem->data.buoihoc = nhapSoNguyen(1, 4);
		if (lNH.hockihientai->danhsachmon.head == NULL)
		{
			lNH.hockihientai->danhsachmon.head = tem;
			lNH.hockihientai->danhsachmon.tail = tem;
		}
		else
		{
			lNH.hockihientai->danhsachmon.tail->next = tem;
			lNH.hockihientai->danhsachmon.tail = tem;
		}
		system("cls");
		cout << "Mon " << lNH.hockihientai->danhsachmon.tail->data.tenlop << " da duoc them vao hoc ki " << lNH.hockihientai->tenhk << " thanh cong!!!!" << endl;
		cout << "Ban vui long tai danh sach cac sinh vien da dang ki khoa hoc tu file CSV." << endl;
		char* tenfile ;
		do
		{
			choose = -1;
			cout << "Nhap ten file chua du lieu:";
			nhapchuoi(tenfile);
			FILE* fp = NULL;
			fp = fopen(tenfile, "r");
			if (fp == NULL)
			{
				system("cls");
				cout << "File khong ton tai!!!" << endl;
				cout << "Tro ve (0)			Nhaplai(1)" << endl;
				choose = nhapSoNguyen(0, 1);
				if (choose == 0) {
					MENUtrangcanhangv(lNH, a);
					return;
				}
			}
			else
			{

				while (!feof(fp))
				{
					nodesv* tem1 = new nodesv;

					tem1->next = NULL;
					char line[100];
					fgets(line, 100, fp);
					char delim[2]{ "," };
					char* token = new char[30];
					token = strtok(line, delim);
					doichuoi(tem1->data.stt, token);
					token = strtok(NULL, delim);
					doichuoi(tem1->data.mssv, token);
					token = strtok(NULL, delim);
					doichuoi(tem1->data.ho, token);
					token = strtok(NULL, delim);
					doichuoi(tem1->data.ten, token);
					token = strtok(NULL, delim);
					doichuoi(tem1->data.gioitinh, token);
					token = strtok(NULL, delim);
					doichuoi(tem1->data.ngaysinh, token);
					token = strtok(NULL, delim);
					doichuoi(tem1->data.cccd, token);
					if (tem->data.danhsachsv.head == NULL) {
						tem->data.danhsachsv.head = tem1;
						tem->data.danhsachsv.tail = tem1;
					}
					else {
						tem->data.danhsachsv.tail->next = tem1;
						tem->data.danhsachsv.tail = tem1;
					}
				}
				fclose(fp);
			}
		} while (choose == 1);
		cout << "Mon hoc da duoc them thanh cong!!!" << endl;
		cout << "Tro ve (0)              Tiep tuc them lop moi (1)" << endl;
		choose = nhapSoNguyen(0, 1);
	} while (choose==1);
	if (choose == 0) MENUhockihientai (a,lNH);
}
void MENUxemdanhsachcacmon(giangvien* a, nodehocki* nHK, listnamhoc& lNH)
{
	int choose=0;
	system("cls");
	if (nHK->danhsachmon.head == NULL)
	{
		cout << "Chua co mon hoc nao duoc them vao!!!!" << endl;
		cout << "Tro ve (0)"<< endl;
		choose = nhapSoNguyen(0, 0);
	}
	else
	{
		nodemonhoc* p = nHK->danhsachmon.head;
		while (p != NULL)
		{
			cout << "** Lop " << p->data.tenlop << "." << endl;
			cout << "+ID:" << p->data.id << endl;
			cout << "+Ten mon hoc:" <<p->data.tenmonhoc<< endl;
			cout << "+Ten giao vien:" << p->data.tengv << endl;
			cout << "+So tin chi:" << p->data.sotinchi << endl;
			cout << "+So sinh vien toi da:" << p->data.sosvtoida << endl;
			cout << "+Ngay hoc trong tuan:"; p->data.inNgay();
			cout << "+Buoi hoc:"; p->data.inBuoi();
			cout << "\n";
			p = p->next;
		}
		cout << "Tro ve (0)" << endl;
		choose = nhapSoNguyen(0, 0);
	}
	if(choose==0)  MENUhockihientai(a,lNH);
}
void MENUcapnhatthongtinmonhoc(giangvien* a, nodehocki* nHK, listnamhoc& lNH)
{
	int choose;
	system("cls");
	if (nHK->danhsachmon.head == NULL) {
		cout << "Hoc ki chua co mon nao ca!!!!";
		cout << "Tro ve (0)" << endl;
		choose = nhapSoNguyen(0, 0);
		if (choose == 0)  MENUhockihientai(a, lNH);
	}
	else
	{
		cout << "CHON LOP BAN MUON CAP NHAT" << endl;
		nodemonhoc* p = nHK->danhsachmon.head;
		int i = 0, choose;
		while (p != NULL)
		{
			cout << "+" << p->data.tenlop << ".(" << ++i << ")" << endl;
			p = p->next;
		}
		i = nhapSoNguyen(1, i);
		p = nHK->danhsachmon.head;
		for (int j = 1; j < i; j++)
		{
			p = p->next;
		}
		cout << "ID mon hoc:";
		nhapchuoi(p->data.id);
		cout << "Ten mon hoc:";
		nhapchuoi(p->data.tenmonhoc);
		cout << "Ten lop:";
		nhapchuoi(p->data.tenlop);
		cout << "Ten giao vien:";
		nhapchuoi(p->data.tengv);
		cout << "So tinh chi,";
		p->data.sotinchi = nhapSoNguyen(1, 4);
		cout << "So sinh vien toi da:";
		p->data.sosvtoida = nhapSoNguyen(10, 100);
		cout << "Ngay hoc:" << endl;
		cout << "Thu 2(1)   Thu 3(2)     Thu 4(3)      Thu 5(4)      Thu 6(5)      Thu 7(6)" << endl;
		p->data.ngayhoc = nhapSoNguyen(1, 6);
		cout << "Buoi hoc:" << endl;
		cout << "S1 (7:30) (1)           S2 (9:30) (2)          S3 (13:30) (3)         S4 (15:30) (4)" << endl;
		p->data.buoihoc = nhapSoNguyen(1, 4);
		system("cls");
		cout << "							Tro ve(0)" << endl;
		cout << "\nTHONG TIN DA DUOC CAP NHAT THANH CONG!!!!" << endl;
		choose = nhapSoNguyen(0, 0);
		if (choose == 0)  MENUhockihientai(a,  lNH);
	}
}
void MENUthemsvvaokhoahoc(giangvien* a, nodehocki* nHK, listnamhoc& lNH)
{
	int n;
	nodesv* tem = new nodesv;
	tem->next = NULL;
	cout << "CHON LOP BAN MUON CAP NHAT" << endl;
	nodemonhoc* p = nHK->danhsachmon.head;
	int i = 0, choose;
	while (p != NULL)
	{
		cout << "+" << p->data.tenlop << ".(" << ++i << ")" << endl;
		p = p->next;
	}
	choose = nhapSoNguyen(1, i);
	p = nHK->danhsachmon.head;
	for (int j = 1; j < i; j++)
	{
		p = p->next;
	}
	cout << "NHAP THONG TIN SINH VIEN CAN THEM VAO" << endl;
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
	p->data.danhsachsv.tail->next = tem;
	p->data.danhsachsv.tail = tem;
	cout << "\nThem thanh cong!!" << endl;
	cout << "Tro ve (0)" << endl;
	choose = nhapSoNguyen(0, 0);
	if (choose == 0) MENUhockihientai(a,  lNH);
}
void MENUxoaSinhVien(giangvien* a, nodehocki* nHK, listnamhoc& lNH)
{
	int n = 0;
	nodemonhoc* p = new nodemonhoc;
	int i = 0, choose;
	while (p != NULL)
	{
		cout << "+" << p->data.tenlop << ".(" << ++i << ")" << endl;
		p = p->next;
	}
	choose = nhapSoNguyen(1, i);
	p =nHK->danhsachmon.head;
	for (int j = 1; j < i; j++)
	{
		p = p->next;
	}
	char* mssv;
	cout << "Nhap mssv muon xoa ra khoi lop:" << endl;
	nhapchuoi(mssv);
	nodesv* p1 = new nodesv;
	p1 = p->data.danhsachsv.head;
	if (strcmp(p->data.danhsachsv.head->data.mssv, mssv) == 0) {
		p->data.danhsachsv.head = p->data.danhsachsv.head->next;
		n++;
	}
	else if (strcmp(p->data.danhsachsv.tail->data.mssv, mssv) == 0) {
		while (p1->next != NULL)
		{
			if (p1->next->next == NULL) {
				p1->next = NULL;
				p->data.danhsachsv.tail = p1;
				n++;
			}
		}
	}
	else
	{
		while (p1 != NULL)
		{
			if (strcmp(p1->next->data.mssv, mssv) == 0) {
				p1->next = p1->next->next;
				n++;
			};
			p1 = p1->next;
		}
	}
	if (n != 0)cout << "Khong ton tai ma so sinh vien da nhap" << endl;
	else cout << "XOA XONG!!!"<<endl;
	cout << "Tro ve(0)" << endl;
	choose=nhapSoNguyen(0, 0);
	if (choose == 0)MENUhockihientai(a, lNH);
}
void MENUxoakhoahoc(giangvien* a, nodehocki* nHK, listnamhoc& lNH)
{
	int choose;
	system("cls");
	cout << "Chon khoa hoc muon xoa" << endl;
	nodemonhoc* p = new nodemonhoc;
	p = nHK->danhsachmon.head;
	int i = 0;
	while (p != NULL)
	{
		cout << p->data.tenmonhoc << " (" << ++i << ")" << endl;;
		p = p->next;
	}
	choose = nhapSoNguyen(1, i);
	p = nHK->danhsachmon.head;
	if (choose == 1) nHK->danhsachmon.head=nHK->danhsachmon.head->next;
	else
	{
		for (int j = 1; j <choose-1; j++)
		{
			p = p->next;
		}
		p->next = p->next->next;
	}
	cout << "Xoa khoa hoc thanh cong !!" << endl;
	cout << "Tro ve (0)" << endl;
	choose = nhapSoNguyen(0, 0);
	if (choose == 0) MENUhockihientai(a, lNH);
}
void MENUxemdanhsachcacmonhocmasvhoc( listnamhoc &lNH, nodesv*& tem)
{
	int n = 0, choose;
	nodemonhoc* p = lNH.hockihientai->danhsachmon.head;
	cout << lNH.hockihientai->danhsachmon.head->data.danhsachsv.head->data.mssv<<" va "<<lNH.head->danhsachlop.head->danhsachsv.head->data.mssv;
	nodesv* p1 = new nodesv;
	cout << "Danh sach cac mon hoc cua ban la."<<endl;
	while (p != NULL)
	{
		p1 = p->data.danhsachsv.head;
		while (p1 != NULL)
		{
			if (strcmp(p1->data.mssv, tem->data.mssv) == 0) cout << "+Mon " << p->data.tenmonhoc << " lop " << p->data.tenlop << endl;
			p1 = p1->next;
		}
		p = p->next;
	}
	cout << "Tro ve(0)" << endl;
	choose = nhapSoNguyen(0, 0);
	if (choose == 0) MENUtrangcanhansv(lNH, tem);
}
void MENUxemdanhsachlophoc(giangvien* a, listnamhoc& lNH)
{
	int choose;
	nodenamhoc* p = new nodenamhoc;
	nodelop* p1 = new nodelop;
	int i;
	do
	{
		system("cls");
		i = 0;
		p = lNH.head;
		while (p != NULL)
		{
			if (p->nambatdau == lNH.namhientai)
			{
				p1 = p->danhsachlop.head;
				while (p1 != NULL)
				{
					cout << "+ " << p1->tenlop << " (" << ++i << ")" << endl;
					p1 = p1->next;
				}
				break;
			}
			p = p->next;
		}
		cout << "Neu muon xem danh sach 1 lop cu the hay chon so tuong ung" << endl;
		cout << "Tro ve (0)" << endl;
		choose = nhapSoNguyen(0, i);
		if (choose == 0) MENUtrangcanhangv(lNH, a);
		else
		{
			p1 = p->danhsachlop.head;
			for (int j = 1; j < choose; j++)
			{
				p1 = p1->next;
			}
			if (p1->danhsachsv.head == NULL) {
				cout << "Danh sach sinh vien rong!!!! " << endl;
				cout << "Tro ve (0)" << endl;
				choose = nhapSoNguyen(0, 0);
				if (choose == 0) MENUtrangcanhangv(lNH, a);
			}
			else {
				nodesv* p2 = p1->danhsachsv.head;
				while (p2 != NULL)
				{
					cout << setw(4) << left << p2->data.stt << setw(13) << left << p2->data.ho << setw(7) << left << p2->data.ten << setw(7) << left << p2->data.gioitinh << setw(12) << left << p2->data.ngaysinh << setw(15) << left << p2->data.cccd << endl;
					p2 = p2->next;
				}
			}
		}
		cout << "Tro ve (0)			Xem danh sach lop khac(1)" << endl;
		choose = nhapSoNguyen(0, 1);
		if (choose == 0) MENUtrangcanhangv(lNH, a);
	} while (choose == 1);
}
void Xemdanhsachcacmon(giangvien* a, listnamhoc& lNH)
{
	int choose;
	if (lNH.hockihientai->danhsachmon.head == NULL) {
		cout << "Hoc ki nay chua co muon hoc nao !!!" << endl;
		cout << "Tro ve (0)" << endl;
		choose = nhapSoNguyen(0, 0);
		if (choose == 0)  MENUhockihientai(a,lNH);
	}
	else
	{
		nodemonhoc* p = lNH.hockihientai->danhsachmon.head;
		do
		{
			int i = 0;
			while (p != NULL)
			{
				cout << "+ " << p->data.tenlop << " (" << ++i << ")" << endl;
				p = p->next;
			}
			cout << "Neu muon xem danh sach 1 mon cu the hay chon so tuong ung" << endl;
			cout << "Tro ve (0)" << endl;
			choose = nhapSoNguyen(0, i);
			if (choose == 0)  MENUhockihientai(a, lNH);
			else
			{
				p = lNH.hockihientai->danhsachmon.head;
				for (int j = 1; j < choose; j++)
				{
					p = p->next;
				}
				if (p->data.danhsachsv.head == NULL) {
					cout << "Danh sach sinh vien rong!!!! " << endl;
					cout << "Tro ve (0)" << endl;
					choose = nhapSoNguyen(0, 0);
					if (choose == 0) MENUtrangcanhangv(lNH, a);
				}
				else {
					nodesv* p2 = p->data.danhsachsv.head;
					while (p2 != NULL)
					{
						cout << setw(4) << left << p2->data.stt <<setw(10)<<left<<p2->data.mssv<< setw(15) << left << p2->data.ho << setw(7) << left << p2->data.ten << setw(7) << left << p2->data.gioitinh << setw(12) << left << p2->data.ngaysinh << setw(15) << left << p2->data.cccd << endl;
						p2 = p2->next;
					}
				}
			}
			cout << "Tro ve (0)			Xem danh sach lop khac(1)" << endl;
			choose = nhapSoNguyen(0, 1);
		} while (choose==1);
		if (choose == 0)  MENUhockihientai(a,  lNH);
	}
}
void XuatdanhsachSVrafile(giangvien* a, listnamhoc& lNH)
{
	int choose;
	if (lNH.hockihientai->danhsachmon.head == NULL) {
		cout << "Hoc ki nay chua co muon hoc nao !!!" << endl;
		cout << "Tro ve (0)" << endl;
		choose = nhapSoNguyen(0, 0);
		if (choose == 0)  MENUhockihientai(a,  lNH);
	}
	else
	{
		nodemonhoc* p = new nodemonhoc;
		p = lNH.hockihientai->danhsachmon.head;
		int i = 0;
		while (p != NULL)
		{
			cout << "+ " << p->data.tenlop << " (" << ++i << ")" << endl;
			p = p->next;
		}
		cout << "chon mon hoc can xuat danh sach lop" << endl;
		choose = nhapSoNguyen(1, i);
		p = lNH.hockihientai->danhsachmon.head;
		for (int j = 1; j < choose; j++)
		{
			p = p->next;
		}
		if (p->data.danhsachsv.head == NULL) {
			cout << "Danh sach sinh vien rong!!!! " << endl;
			cout << "Tro ve (0)" << endl;
			choose = nhapSoNguyen(0, 0);
			if (choose == 0)  MENUhockihientai(a,lNH);
		}
		else {
			cout << "Nhap ten file can xuat" << endl;
			string file;
			getline(cin, file);
			ofstream file1;
			file1.open(file);
			nodesv* p2 = p->data.danhsachsv.head;
			while (p2 != NULL)
			{
				file1 << p2->data.stt << " " << p2->data.mssv << " " << p2->data.ho << " " << p2->data.ten << " " << p2->data.gioitinh << " " << p2->data.ngaysinh << " " << p2->data.cccd << "\n";
				p2 = p2->next;
			}
			file1.close();
		}
	}
	cout << "Xuat thanh cong !!!!!" << endl;
	cout << "Tro ve (0)" << endl;
	choose = nhapSoNguyen(0, 0);
	if (choose == 0) MENUhockihientai(a, lNH);
}
void XuatDanhSachChoGiaoVienNhapBangDiem(giangvien* a, listnamhoc& lNH)
{
	int choose;
	if (lNH.hockihientai->danhsachmon.head == NULL) {
		cout << "Hoc ki nay chua co muon hoc nao !!!" << endl;
		cout << "Tro ve (0)" << endl;
		choose = nhapSoNguyen(0, 0);
		if (choose == 0)  MENUhockihientai(a, lNH);
	}
	else
	{
		nodemonhoc* p = new nodemonhoc;
		p = lNH.hockihientai->danhsachmon.head;
		int i = 0;
		while (p != NULL)
		{
			cout << "+ " << p->data.tenlop << " (" << ++i << ")" << endl;
			p = p->next;
		}
		cout << "chon mon hoc can xuat danh sach lop de nhap ban diem" << endl;
		choose = nhapSoNguyen(1, i);
		p = lNH.hockihientai->danhsachmon.head;
		for (int j = 1; j < choose; j++)
		{
			p = p->next;
		}
		if (p->data.danhsachsv.head == NULL) {
			cout << "Danh sach sinh vien rong!!!! " << endl;
			cout << "Tro ve (0)" << endl;
			choose = nhapSoNguyen(0, 0);
			if (choose == 0)  MENUhockihientai(a, lNH);
		}
		else {
			string a(p->data.tenlop);
			a = "Danh sach nhap diem " + a + ".txt";
			ofstream file1;
			file1.open(a);
			file1 << "STT Ma_so_sinh_vien Ho Ten Diem_qua_trinh Diem_giua_ki Diem_cuoi_ki Ghi_chu" << endl;
			nodesv* p2 = p->data.danhsachsv.head;
			while (p2 != NULL)
			{
				file1 << p2->data.stt << " " << p2->data.mssv << " " << p2->data.ho << " " << p2->data.ten << endl;
				p2 = p2->next;
			}
			file1.close();
		}
	}
	cout << "Xuat thanh cong !!!!!" << endl;
	cout << "Tro ve (0)" << endl;
	choose = nhapSoNguyen(0, 0);
	if (choose == 0)  MENUhockihientai(a,lNH);
}
void taifilediemlen(giangvien* a, listnamhoc& lNH)
{
	int choose;
	if (lNH.hockihientai->danhsachmon.head == NULL) {
		cout << "Hoc ki nay chua co muon hoc nao !!!" << endl;
		cout << "Tro ve (0)" << endl;
		choose = nhapSoNguyen(0, 0);
		if (choose == 0) MENUhockihientai(a, lNH);
	}
	else
	{
		nodemonhoc* p = new nodemonhoc;
		p = lNH.hockihientai->danhsachmon.head;
		int i = 0;
		while (p != NULL)
		{
			cout << "+ " << p->data.tenlop << " (" << ++i << ")" << endl;
			p = p->next;
		}
		cout << "chon mon hoc can nhap bang diem" << endl;
		choose = nhapSoNguyen(1, i);
		p = lNH.hockihientai->danhsachmon.head;
		for (int j = 1; j < choose; j++)
		{
			p = p->next;
		}
		if (p->data.danhsachsv.head == NULL) {
			cout << "Danh sach sinh vien rong!!!! " << endl;
			cout << "Tro ve (0)" << endl;
			choose = nhapSoNguyen(0, 0);
			if (choose == 0)  MENUhockihientai(a, lNH);
		}
		else
		{
			do
			{
				char* file;
				cout << "Nhap ten file diem:";
				nhapchuoi(file);
				FILE* fp = NULL;
				fp = fopen(file, "r");
				if (fp == NULL)
				{
					cout << "File khong ton tai!!!" << endl;
					cout << "Tro ve (0)			Nhaplai(1)" << endl;
					choose = nhapSoNguyen(0, 1);
					if (choose == 0) {
						MENUhockihientai(a, lNH);
						return;
					}
				}
				else
				{
					nodesv* tem = p->data.danhsachsv.head;
					while (tem != NULL)
					{
						char line[100];
						fgets(line, 100, fp);
						char delim[2]{ "," };
						char* token = new char[30];
						token = strtok(line, delim);
						token = strtok(NULL, delim);
						token = strtok(NULL, delim);
						token = strtok(NULL, delim);
						token = strtok(NULL, delim);
						tem->data.diem.quatrinh = atof(token);
						token = strtok(NULL, delim);
						tem->data.diem.giuaki = atof(token);
						token = strtok(NULL, delim);
						tem->data.diem.cuoiki = atof(token);
						token = strtok(NULL, delim);
						tem->data.diem.ghichu = new char[strlen(token) + 1];
						strcpy(tem->data.diem.ghichu, token);
						tem = tem->next;
					}
					fclose(fp);
					nodenamhoc* namhoc = lNH.head;
					while (1)
					{
						if (namhoc->nambatdau == lNH.namhientai) break;
						namhoc=namhoc->next;
					}
					nodesv* p2 = new nodesv;
					nodelop* p3 = new nodelop;
					nodesv* p4 = new nodesv;
					p2 = p->data.danhsachsv.head;
					while (p2 != NULL)
					{
						p3 = namhoc->danhsachlop.head;
						while (p3 != NULL)
						{
							p4 = p3->danhsachsv.head;
							while (p4 != NULL)
							{
								if (strcmp(p2->data.mssv, p4->data.mssv) == 0)
								{
									nodediemtongket* p5 = new nodediemtongket;
									p5->next = NULL;
									p5->diemtongket = 1.0 * (p2->data.diem.cuoiki + p2->data.diem.giuaki + p2->data.diem.quatrinh)/3;
									p5->monhoc = new char[strlen(p->data.tenmonhoc)+1];
									strcpy(p5->monhoc, p->data.tenmonhoc);
									if (p4->data.ldtk.head == NULL)
									{
										p4->data.ldtk.head = p5;
										p4->data.ldtk.tail = p5;
									}
									else
									{
										p4->data.ldtk.tail->next = p5;
										p4->data.ldtk.tail = p5;
									}
									break;
								}
								p4 = p4->next;
							}
							p3 = p3->next;
						}
						p2 = p2->next;
					}
				cout << "Them diem vao lop " << p->data.tenlop << " thanh cong!!!" << endl;
				cout << "Tro ve (0)" << endl;
				choose = nhapSoNguyen(0, 0);
				if (choose == 0) MENUhockihientai(a, lNH);
			}
		
			} while (choose==1);
		}
	}
}
void Xembangdiemcuamonhoc(giangvien* a, listnamhoc& lNH)
{
	int choose;
	if (lNH.hockihientai->danhsachmon.head == NULL) {
		cout << "Hoc ki nay chua co muon hoc nao !!!" << endl;
		cout << "Tro ve (0)" << endl;
		choose = nhapSoNguyen(0, 0);
		if (choose == 0)  MENUhockihientai(a, lNH);
	}
	else
	{
		nodemonhoc* p = new nodemonhoc;
		p = lNH.hockihientai->danhsachmon.head;
		int i = 0;
		while (p != NULL)
		{
			cout << "+ " << p->data.tenlop << " (" << ++i << ")" << endl;
			p = p->next;
		}
		cout << "chon mon hoc can xuat danh sach lop de nhap ban diem" << endl;
		choose = nhapSoNguyen(1, i);
		p = lNH.hockihientai->danhsachmon.head;
		for (int j = 1; j < choose; j++)
		{
			p = p->next;
		}
		if (p->data.danhsachsv.head == NULL) {
			cout << "Danh sach sinh vien rong!!!! " << endl;
			cout << "Tro ve (0)" << endl;
			choose = nhapSoNguyen(0, 0);
			if (choose == 0)  MENUhockihientai(a, lNH);
		}
		else
		{
			nodesv* p1 = p->data.danhsachsv.head;
			if (p1->data.diem.quatrinh == -1) {
				cout << "Diem chua duoc nhap vao.Vui long kiem tra lai!!!!" << endl;
				cout << "Tro ve(0)" << endl;
				choose = nhapSoNguyen(0, 0);
				if (choose == 0) MENUhockihientai(a, lNH);
			}
			else
			{
				do
				{
					system("cls");
					while (p1 != NULL)
					{
						cout << setw(3) << left << p1->data.stt << setw(10) << left << p1->data.mssv << setw(20) << left << p1->data.ho << setw(8) << left << p1->data.ten << setw(15) << left << p1->data.diem.quatrinh << setw(13) << left << p1->data.diem.giuaki << setw(13) << left << p1->data.diem.cuoiki << p1->data.diem.ghichu << endl;
						p1 = p1->next;
					}
					cout << "Tro ve(0)" << endl;
					cout << "Neu muon cap nhat diem so cua sinh vien hay chon so thu tu tuong ung" << endl;
					choose = nhapSoNguyen(0, atoi(p->data.danhsachsv.tail->data.stt));
					if(choose!=0)
					{
						p1 = p->data.danhsachsv.head;
						for (int i = 1; i < choose; i++)
						{
							p1 = p1->next;
						}
						system("cls");
						cout << "NHAP DIEM CAN CHINH SUA" << endl;
						cout << "Diem qua trinh,";
						p1->data.diem.quatrinh = nhapdiem();
						cout << "Diem giua ki,";
						p1->data.diem.giuaki = nhapdiem();
						cout << "Diem cuoi ki,";
						p1->data.diem.cuoiki = nhapdiem();
						cout << "ghi chu:";
						nhapchuoi(p1->data.diem.ghichu);
					}
				} while (choose != 0);
			}
		}
		if (choose == 0) MENUhockihientai(a, lNH);
	}
}
void Xembangdiemcualop(giangvien* a, listnamhoc& lNH)
{
	int choose;
	nodenamhoc* p = new nodenamhoc;
	nodelop* p1 = new nodelop;
	int i;

	system("cls");
	i = 0;
	p = lNH.head;
	while (p != NULL)
	{
		if (p->nambatdau == lNH.namhientai)
		{
			p1 = p->danhsachlop.head;
			while (p1 != NULL)
			{
				cout << "+ " << p1->tenlop << " (" << ++i << ")" << endl;
				p1 = p1->next;
			}
			break;
		}
		p = p->next;
	}
	cout << "Hay chon so tuong ung de xem diem" << endl;
	choose = nhapSoNguyen(1, i);
	p1 = p->danhsachlop.head;
	for (int j = 1; j < choose; j++)
	{
		p1 = p1->next;
	}
	if (p1->danhsachsv.head == NULL) {
		cout << "Danh sach sinh vien rong!!!! " << endl;
		cout << "Tro ve (0)" << endl;
		choose = nhapSoNguyen(0, 0);
		if (choose == 0) MENUtrangcanhangv(lNH, a);
	}
	else {
		if (p1->danhsachsv.head->data.ldtk.head == NULL)
		{
			cout << "Diem chua duoc giang vien nhap vao" << endl;
			cout << "Tro ve (0)" << endl;
			choose = nhapSoNguyen(0, 0);
			if (choose == 0) MENUtrangcanhangv(lNH, a);
		}
		else {
			nodesv* p2 = p1->danhsachsv.head;
			nodediemtongket* tem = new nodediemtongket;
			nodemonhoc* tem1 = new nodemonhoc;
			float tonghk, tongall;
			int somonhk, somonall;
			while (p2 != NULL)
			{
				cout << p2->data.stt << "." << p2->data.mssv << " " <<p2->data.ho<<" "<< p2->data.ten << endl;
				tem = p2->data.ldtk.head;
				cout << "- Diem hoc ki." << endl;
				tonghk = 0; somonhk = 0;
				tongall = 0; somonall = 0;
				while (tem != NULL)
				{
					tongall += tem->diemtongket;
					somonall++;
					tem1 = lNH.hockihientai->danhsachmon.head;
					while (tem1 != NULL)
					{
						if (strcmp(tem1->data.tenmonhoc,tem->monhoc)==0)
						{
							cout << "   + " << tem->monhoc << ":" << tem->diemtongket << endl;
							tonghk += tem->diemtongket;
							somonhk++;
						}
						tem1 = tem1->next;
					}
					tem = tem->next;
				}
				cout << "- Diem trung binh hoc ki nay la:" << 1.0 * tonghk / somonhk << endl;
				cout << "- Diem trung binh tich luy la:" << 1.0 * tongall / somonall << endl;
				p2 = p2->next;
			}
		}
		cout << "Tro ve (0)	" << endl;
		choose = nhapSoNguyen(0, 0);
		if (choose == 0) MENUtrangcanhangv(lNH, a);
	}
}
void SVxemdiem(nodesv*& tem, listnamhoc& lNH)
{
	int choose;
	nodediemtongket* p = tem->data.ldtk.head;
	float tonghk, tongall;
	int somonhk, somonall;
	tonghk = 0; somonhk = 0;
	tongall = 0; somonall = 0;
	cout << "-=-=-=-=-BANG DIEM CUA BAN-=-=-=-=-" << endl;
	cout << "-Diem tung mon" << endl;
	while (p!= NULL)
	{
		cout << "   + " << p->monhoc << ":" << p->diemtongket << endl;
		tongall += p->diemtongket;
		somonall++;
		nodemonhoc* tem1 = lNH.hockihientai->danhsachmon.head;
		while (tem1 != NULL)
		{
			if (strcmp(tem1->data.tenmonhoc, p->monhoc)==0)
			{
				tonghk += p->diemtongket;
				somonhk++;
			}
			tem1 = tem1->next;
		}
		p = p->next;
	}
	cout << "- Diem trung binh hoc ki nay la:" << 1.0 * tonghk / somonhk << endl;
	cout << "- Diem trung binh tich luy la:" << 1.0 * tongall / somonall << endl;
	cout << "Tro ve (0)"<<endl;
	choose = nhapSoNguyen(0, 0);
	if (choose == 0) MENUtrangcanhansv(lNH, tem);
}