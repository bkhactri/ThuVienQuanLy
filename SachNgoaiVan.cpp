#include "SachNgoaiVan.h"
//Ham khoi tao va huy
SachNgoaiVan::SachNgoaiVan()
{ 
	this->ISBN  ="";
}
SachNgoaiVan::SachNgoaiVan(string _ma, string _tenS, string _tenTG, string _NXB, int _gia,  bool _tt,string _ISBN) : Sach(_ma, _tenS, _tenTG, _NXB, _gia,_tt)
{
	this->ISBN = _ISBN;
}
SachNgoaiVan::SachNgoaiVan(string _ma, string _tenS) : Sach(_ma, _tenS) {}
SachNgoaiVan::SachNgoaiVan(const SachNgoaiVan& other) : Sach(other)
{
	this->ISBN = other.ISBN;
}
SachNgoaiVan::~SachNgoaiVan() {}
//Ham get set
string SachNgoaiVan::LayISBN() { return this->ISBN; }
void SachNgoaiVan::DatISBN(string _ISBN) { this->ISBN = _ISBN; }
//Phuong thuc khac
void SachNgoaiVan::NhapThongTinSach()
{
	this->Sach::NhapThongTinSach();
	cout << "\t\tNhap ma ISBN: "; 
	getline(cin,ISBN);
	cout << endl;
}
void SachNgoaiVan::XuatThongTinSach()
{
	this->Sach::XuatThongTinSach();
	cout << setw(20) << left << ISBN << "\t";
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
int SachNgoaiVan::KiemtraLoai()
{
	return 2;
}
void SachNgoaiVan::GhiVaoFile()
{
	this->Sach::GhiVaoFile();
	fstream f;
	f.open("DanhSachCuonSach.bin", ios::app|ios::binary);
	f << this->LayISBN() << endl;
}