#pragma once
#include"Sach.h"

struct Ngay //Ngay thang nam
{
	int ngay, thang, nam;
	Ngay() {
		ngay = thang = nam = 0;
	}
};
int SoNgay(Ngay ngay);


struct PhieuMuonSach //Phieu muon tra sach - 1 doc gia/1 phieu - quan ly cac sach muon, thoi gian muon, thoi gian tra
{
	Sach* CuonSach;
	Ngay NgayMuon;
	Ngay NgayTra;

	PhieuMuonSach() {
		CuonSach = new Sach;
	};
	PhieuMuonSach(Sach*input, Ngay muon, Ngay tra)
	{
		CuonSach = input;
		NgayMuon = muon;
		NgayTra = tra;
	}
};

class DocGia //Doc gia trong thu vien
{
private:
	string MaDocGia;
	string Ten;
	string GioiTinh;
	vector<PhieuMuonSach*>SoLuong;//Doc gia co the tuy y muon so luong sach
public:
	DocGia();
	DocGia(string _ma,string _ten,string _gt, vector<PhieuMuonSach*>_SoLuong);
	DocGia(const DocGia&);
	~DocGia();
public://Cac get/set ho so cho viec sua doi thong tin doc gia
	int LaySoLuongSach();
	void DatNgayTra(Ngay,int);//Dat ngay tra sach - vi tri int() la cuon sach doc gia tra
	string LayMaDocGia();
	void DatMaDocGia(string);
	string LayTen();
	void DatTen(string);
	string LayGioiTinh();
	void DatGioiTinh(string);
public:
	void GhiVaoFile();//Ghi vao file
	void NhapThongTinDocGia();//Nhap 3 thong tin ma, ten, gioi tinh
	void TaoPhieuMuonSach(Sach*);//Cho doc gia muon them sach
	void XuatThongTinDocGia();//Xuat toan bo thong tin doc gia ( da dieu chinh man hinh xuat)
	int TimSachCuaDocGia(string); //Tim kiem bang ma cuon sach trong so sach doc gia muon (muc dich de tra sach)
	int TinhTienPhat(int); //Tinh tien phat ma doc gia tra tre 
	int TongTienPhat(); //Tong so tien phat ma doc gia phai tra ( vd muon 10 cuon tra tre 7 cuon thi tinh tien 7 cuon)
	void XuatThongTinSachTreHan();
};
//Ham ho tro

//Dem so ngay (ham dung de tinh khoang cach 2 ngay -> tinh tien tre han)
int SoNgay(Ngay);

//Cap nhat ngay thang nam theo he thong
int KiemTraNgay(Ngay ngay);

//Cap nhat ngay thang nam bang cach nhap(vi cai nay em muon thay test duoc cai tinh tien)
void CapNhatNgayMuon(Ngay&);

//Kiem tra tinh hop le cua ngay
void CapNhatNgayTra(Ngay&);


