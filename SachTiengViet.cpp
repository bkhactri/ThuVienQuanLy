#include "SachTiengViet.h"
//Ham khoi tao va huy
SachTiengViet::SachTiengViet() {}
SachTiengViet::SachTiengViet(string _ma, string _tenS, string _tenTG, string _NXB, int _gia,bool _tt) : Sach(_ma, _tenS, _tenTG, _NXB, _gia,_tt) {}
SachTiengViet::SachTiengViet(string _ma, string _tenS) : Sach(_ma, _tenS){}
SachTiengViet::SachTiengViet(const Sach& other) : Sach(other){}
SachTiengViet::~SachTiengViet() {}
//Phuong thuc khac
void SachTiengViet::NhapThongTinSach()
{
	this->Sach::NhapThongTinSach();
	cout << endl;
}
void SachTiengViet::XuatThongTinSach()
{
	this->Sach::XuatThongTinSach();
	cout << setw(7) << left;
	if (this->LayTinhTrang() == false)
	{
		cout << "CHUA MUON" << "\t";
	}
	else if (this->LayTinhTrang() == true)
	{
		cout << "DUOC MUON" << "\t";
	}
	cout << endl;
}
int SachTiengViet::KiemtraLoai()
{
	return 1;
}
void SachTiengViet::GhiVaoFile()
{
	this->Sach::GhiVaoFile();
}
