#include"library.h"
void imforgiangvien(giangvien**a)// thong tin va tai khoan cua 5 giang vien la du lieu cho truoc
{
	for (int i = 0; i < 5; i++)
	{
		a[i] = new giangvien;
	}
	a[0]->hovaten = new char[16] {"Le Thi Anh Thao"};
	a[0]->ngaysinh = new char[9] { "1/3/1990"};
	a[0]->bomon = new char[19] { "Cong nghe phan mem"};
	a[0]->tentk = new char[21] {"ltathao@hcmus.edu.vn"};
	a[0]->matkhau= new char[20] {"123"};

	a[1]->hovaten = new char[21] {"Nguyen Thi Minh Phuc"};
	a[1]->ngaysinh = new char[12] { "11/2/1985"};
	a[1]->bomon = new char[19] { "He thong thong tin"};
	a[1]->tentk = new char[21] {"ntmphuc@hcmus.edu.vn"};
	a[1] ->matkhau= new char[20] {"123"};
	
	a[2]->hovaten = new char[21] {"Hoang Thanh Tu"};
	a[2]->ngaysinh = new char[12] { "6/7/1992"};
	a[2]->bomon = new char[19] { "Cong nghe phan mem"};
	a[2]->tentk = new char[21] {"httu@hcmus.edu.vn"};
	a[2]->matkhau= new char[20] {"123"};
	
	a[3]->hovaten = new char[21] {"Nguyen Van Teo"};
	a[3]->ngaysinh = new char[12] { "9/10/1980"};
	a[3]->bomon = new char[19] { "Khoa hoc may tinh"};
	a[3]->tentk = new char[21] {"1"};
	a[3]->matkhau= new char[20] {"123"};
	
	a[4]->hovaten = new char[21] {"Phan Quoc An"};
	a[4]->ngaysinh = new char[12] { "10/2/1997"};
	a[4]->bomon = new char[19] { "Mang may tinh"};
	a[4]->tentk = new char[21] {"pqan@hcmus.edu.vn"};
	a[4]->matkhau= new char[20] {"123"};
}