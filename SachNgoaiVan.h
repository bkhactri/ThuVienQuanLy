#pragma once
#include"Sach.h"
class SachNgoaiVan:public Sach
{
private:
	string ISBN;
public:
	string LayISBN();
	void DatISBN(string);
public:
	SachNgoaiVan();
	SachNgoaiVan(string _ma, string _tenS, string _tenTG, string _NXB, int _gia, bool _tt, string _ISBN);
	SachNgoaiVan(string _ma, string _tenS);
	SachNgoaiVan(const SachNgoaiVan&);
	~SachNgoaiVan();
public:
	void NhapThongTinSach();
	void XuatThongTinSach();
	int KiemtraLoai();
	void GhiVaoFile();
};

