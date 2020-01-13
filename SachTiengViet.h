#pragma once
#include"Sach.h"
#include"HamHoTro.h"
class SachTiengViet :public Sach
{
public:
	SachTiengViet();
	SachTiengViet(string _ma, string _tenS, string _tenTG, string _NXB, int _gia, bool _tt);
	SachTiengViet(string _ma, string _tenS);
	SachTiengViet(const Sach&);
	~SachTiengViet();
public:
	void NhapThongTinSach();
	void XuatThongTinSach();
	int KiemtraLoai();
	void GhiVaoFile();
};

