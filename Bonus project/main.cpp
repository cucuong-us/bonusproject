#include"library.h"
int main()
{
	listnamhoc lNH;
	giangvien* cosan = new giangvien[6];
	imforgiangvien(cosan);
	MENUlogin(lNH,cosan);
}