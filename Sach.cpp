#include "Sach.h"
//Ham khoi tao va sao chep
Sach::Sach()
{
	this->MaSach = "";
	this->TenSach = "";
	this->TacGia = "";
	this->NhaXuatBan = "";
	this->Gia = 0;
	this->TinhTrang = false;
}
Sach::Sach(string _ma, string _tenS, string _tenTG, string _NXB, int _gia,bool _tt)
{
	this->MaSach = _ma;
	this->TenSach = _tenS;
	this->TacGia = _tenTG;
	this->NhaXuatBan = _NXB;
	this->Gia = _gia;
	this->TinhTrang = _tt;
}
Sach::Sach(string _ma, string _tenS)
{
	this->MaSach = _ma;
	this->TenSach = _tenS;
}
Sach::Sach(const Sach& other)
{
	this->MaSach = other.MaSach;
	this->TenSach = other.TenSach;
	this->TacGia = other.TacGia;
	this->NhaXuatBan = other.NhaXuatBan;
	this->Gia = other.Gia;
	this->TinhTrang = other.TinhTrang;
}
Sach::~Sach(){}
//Ham get set
int Sach::LayGia() { return this->Gia; }
void Sach::DatGia(int value) { this->Gia = value; }
string Sach::LayMaSach() { return this->MaSach; }
void Sach::DatMaSach(string value) { this->MaSach = value; }
string Sach::LayTenSach() { return this->TenSach; }
void Sach::DatTenSach(string _ten) { this->TenSach = _ten; }
string Sach::LayTacGia() { return this->TacGia; }
void Sach::DatTacGia(string _ten) { this->TacGia = _ten; }
string Sach::LayNhaXB() { return this->NhaXuatBan; }
void Sach::DatNhaXB(string _ten) { this->NhaXuatBan = _ten; }
bool Sach::LayTinhTrang() { return this->TinhTrang; }
void Sach::DatTinhTrang(bool _tinhtrang) { this->TinhTrang = _tinhtrang; }
//Phuong thuc khac
void Sach::NhapThongTinSach()
{
	char temp[10];
	cout << "\t\tNhap ma sach: "; getline(cin, MaSach);
	cout << "\t\tNhap ten sach: "; getline(cin, TenSach);
	cout << "\t\tNhap ten tac gia: "; getline(cin, TacGia);
	cout << "\t\tNhap nha xuat ban: ";getline(cin, NhaXuatBan);
	cout << "\t\tNhap gia ban sach: "; gets_s(temp, 10);
	do {
		cout << "\t\tDay khong phai gia tien dung ban hay nhap lai: "; gets_s(temp, 10);
	} while (KiemTra(temp) == -1);
	Gia = atoi(temp);
	TinhTrang = false;
}
void Sach::XuatThongTinSach()
{
	cout << setw(6) << left << MaSach << "\t";
	cout << setw(25) << left << TenSach << "\t";
	cout << setw(20) << left << TacGia << "\t";
	cout << setw(15) << left << NhaXuatBan << "\t";
	cout << setw(8) << left << Gia << "\t";
}
void Sach::GhiVaoFile()
{
	fstream f;
	f.open("DanhSachCuonSach.txt", ios::app);
	f << this->KiemtraLoai() << endl;
	f << MaSach << endl;
	f << TenSach << endl;
	f << TacGia << endl;
	f << NhaXuatBan << endl;
	f << Gia << endl;
	f << TinhTrang << endl;
}
//Ham ho tro
int KiemTra(char a[50])
{
	int temp = 0;
	bool flag = false;
	for (int i = 0; i < strlen(a); i++)
	{
		if (int(a[i]) < 48 || int(a[i]) > 57)
		{
			temp = -1;
			flag = false;
		}
		else
		{
			flag = true;
		}
	}
	if (flag == true)
	{
		temp = atoi(a);
	}
	return temp;
}