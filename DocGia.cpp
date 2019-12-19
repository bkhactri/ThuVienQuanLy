#define _CRT_SECURE_NO_WARNINGS
#include "DocGia.h"

//Ham khoi tao va huy
DocGia::DocGia()
{
	this->Ten = "";
	this->GioiTinh = "";
}
DocGia::DocGia(string _ma, string _ten, string _gt, vector<PhieuMuonSach*>_SoLuong)
{
	this->MaDocGia = _ma;
	this->Ten = _ten;
	this->GioiTinh = _gt;
	SoLuong = _SoLuong;
}
DocGia::DocGia(const DocGia& other)
{
	this->MaDocGia = other.MaDocGia;
	this->Ten = other.Ten;
	this->GioiTinh = other.GioiTinh;
	for (int i = 0; i < other.SoLuong.size(); i++)
	{
		this->SoLuong[i] = other.SoLuong[i];
	}
}
DocGia::~DocGia() {}
//Ham get set
int DocGia::LaySoLuongSach() { return SoLuong.size(); }
void DocGia::DatNgayTra(Ngay _ngaytra, int thutu)
{
	SoLuong[thutu]->NgayTra.ngay = _ngaytra.ngay;
	SoLuong[thutu]->NgayTra.thang = _ngaytra.thang;
	SoLuong[thutu]->NgayTra.nam = _ngaytra.nam;
	SoLuong[thutu]->CuonSach->DatTinhTrang(false);
}
string DocGia::LayMaDocGia() { return MaDocGia; }
void DocGia::DatMaDocGia(string _ma) { this->MaDocGia = _ma; }
string DocGia::LayTen() { return this->Ten; }
void DocGia::DatTen(string _ten) { this->Ten = _ten; }
string DocGia::LayGioiTinh() { return this->GioiTinh; }
void DocGia::DatGioiTinh(string _gt) { this->GioiTinh = _gt; }
//Phuong thuc khac
void DocGia::GhiVaoFile()
{
	fstream f;
	f.open("DanhSachDocGia.txt", ios::app);
	f << MaDocGia << endl;
	f << Ten << endl;
	f << GioiTinh << endl;
	f << SoLuong.size() << endl;
	for (int i = 0; i < SoLuong.size(); i++)
	{
		f << SoLuong[i]->CuonSach->KiemtraLoai() << endl;
		f << SoLuong[i]->CuonSach->LayMaSach() << endl;
		f << SoLuong[i]->CuonSach->LayTenSach() << endl;
		f << SoLuong[i]->NgayMuon.ngay << " " << SoLuong[i]->NgayMuon.thang << " " << SoLuong[i]->NgayMuon.nam << endl;
		f << SoLuong[i]->NgayTra.ngay << " " << SoLuong[i]->NgayTra.thang << " " << SoLuong[i]->NgayTra.nam << endl;
	}
	f.close();
}
void DocGia::NhapThongTinDocGia()
{
	cout << "\t\tNhap ma doc gia: "; getline(cin, MaDocGia);
	cout << "\t\tNhap ten doc gia: "; getline(cin, Ten);
	cout << "\t\tNhap gioi tinh: "; getline(cin, GioiTinh);
}
void DocGia::XuatThongTinDocGia()
{
	cout << setw(9) << left << MaDocGia << "\t";
	cout << setw(20) << left << Ten << "\t";
	cout << setw(7) << left << GioiTinh << "\t\t";
	cout << setw(7) << left << SoLuong.size() << "\t";
	cout << endl << endl;
	cout << "Cac cuon sach doc gia nay dang muon: " << endl;
	cout << "\t" << left << setw(3) << "Loai sach" << "\t" << left << setw(8) << "Ma sach" << "\t" << left << setw(20) << "Ten sach" << "\t" << left << setw(1) << "Ngay Muon" << "\t" << left << setw(1) << "Ngay tra" << endl;
	for (int i = 0; i < SoLuong.size(); i++)
	{
		cout << "\t" << setw(3) << left << SoLuong[i]->CuonSach->KiemtraLoai() << "\t";
		cout << "\t" << setw(8) << left << SoLuong[i]->CuonSach->LayMaSach();
		cout << "\t" << setw(20) << left << SoLuong[i]->CuonSach->LayTenSach();
		cout << "\t" << setw(1) << left << SoLuong[i]->NgayMuon.ngay << "/" << SoLuong[i]->NgayMuon.thang << "/" << SoLuong[i]->NgayMuon.nam;
		cout << "\t" << setw(1) << left << SoLuong[i]->NgayTra.ngay << "/" << SoLuong[i]->NgayTra.thang << "/" << SoLuong[i]->NgayTra.nam << endl;
	}
}
void DocGia::TaoPhieuMuonSach(Sach* sach)
{
	PhieuMuonSach* input = new PhieuMuonSach;
	input->CuonSach = sach;
	cout << "\t\tNgay muon se duoc cap nhat theo ngay he thong !" << endl;
	CapNhatNgayMuon(input->NgayMuon);
	SoLuong.push_back(input);
}
int DocGia::TimSachCuaDocGia(string _ma)
{
	for (int i = 0; i < SoLuong.size(); i++)
	{
		if (SoLuong[i]->CuonSach->LayMaSach() == _ma)
		{
			return i;
			break;
		}
	}
	return -1;
}
int DocGia::TinhTienPhat(int vt)
{
	if (SoLuong[vt]->NgayTra.ngay == 0)
	{
		return 0;
	}
	else 
	{
		int KC2Ngay = abs(SoNgay(SoLuong[vt]->NgayMuon) - SoNgay(SoLuong[vt]->NgayTra));
		if (KC2Ngay <= 7) return 0;
		else
		{
			if (SoLuong[vt]->CuonSach->KiemtraLoai() == 1)
			{
				return 10000 * (KC2Ngay - 7);
			}
			if (SoLuong[vt]->CuonSach->KiemtraLoai() == 2)
			{
				return 20000 * (KC2Ngay - 7);
			}
		}
	}
}
int DocGia::TongTienPhat()
{
	int tong = 0;
	for (int i = 0; i < SoLuong.size(); i++)
	{
		tong += this->TinhTienPhat(i);
	}
	return tong;
}
void DocGia::XuatThongTinSachTreHan()
{
	for (int i = 0; i < SoLuong.size(); i++)
	{
		int temp = this->TinhTienPhat(i);
		if (temp != 0)
		{
			cout << "\t" << setw(3) << left << SoLuong[i]->CuonSach->KiemtraLoai() << "\t\t";
			cout << setw(8) << left << SoLuong[i]->CuonSach->LayMaSach() << "\t";
			cout << setw(1) << left << SoLuong[i]->NgayMuon.ngay << "/" << SoLuong[i]->NgayMuon.thang << "/" << SoLuong[i]->NgayMuon.nam << "\t";
			cout << SoLuong[i]->NgayTra.ngay << "/" << SoLuong[i]->NgayTra.thang << "/" << setw(4) << left << SoLuong[i]->NgayTra.nam << "\t";
			if (SoLuong[i]->NgayTra.ngay != 0 && abs(SoNgay(SoLuong[i]->NgayMuon) - SoNgay(SoLuong[i]->NgayTra)) - 7 > 0)
			{
				cout << setw(10) << left << abs(SoNgay(SoLuong[i]->NgayMuon) - SoNgay(SoLuong[i]->NgayTra)) - 7 << "\t";
			}
			else {
				cout << setw(10) << left << "0" << "\t";
			}
			cout << setw(6) << left << temp << endl;
		}
	}
}
//Ham ho tro
//Dem so ngay (ham dung de tinh khoang cach 2 ngay -> tinh tien tre han)
int SoNgay(Ngay ngay)
{
	if (ngay.thang < 3) {
		ngay.nam--;
		ngay.thang += 12;
	}
	return 365 * ngay.nam + ngay.nam / 4 - ngay.nam / 100 + ngay.nam / 400 + (153 * ngay.thang - 457) / 5 + ngay.ngay - 306;
}
//Cap nhat ngay thang nam theo he thong
void CapNhatNgayMuon(Ngay &ngay)
{
	time_t baygio = time(0);
	tm* hientai = localtime(&baygio);
	ngay.ngay = hientai->tm_mday;
	ngay.thang = 1 + hientai->tm_mon;
	ngay.nam = 1900 + hientai->tm_year;
}
//Cap nhat ngay thang nam bang cach nhap(vi cai nay em muon thay test duoc cai tinh tien)
//Em da xu ly nhap chu cai dung chuong trinh
void CapNhatNgayTra(Ngay& ngay)
{
	char tempNgay[10], tempThang[10], tempNam[10];
	cout << "\t\tNhap ngay tra(ban hay nhap dung neu nhap sai met lam do)" << endl;
	Do:
	cout << "\t\tNhap ngay: "; gets_s(tempNgay, 10);
	cout << "\t\tNhap thang: "; gets_s(tempThang, 10);
	cout << "\t\tNhap nam: "; gets_s(tempNam, 10);
	if (atoi(tempNgay) == 0 || atoi(tempThang) == 0 || atoi(tempNam) == 0)
	{
		do {
			cout << "\t\tBan nhap co gi do sai roi,hay nhap lai" << endl;
			cout << "\t\tNhap ngay: "; gets_s(tempNgay, 10);
			cout << "\t\tNhap thang: "; gets_s(tempThang, 10);
			cout << "\t\tNhap nam: "; gets_s(tempNam, 10);
		} while (atoi(tempNgay) == 0 || atoi(tempThang) == 0 || atoi(tempNam) == 0);
	}
	ngay.ngay = atoi(tempNgay);
	ngay.thang = atoi(tempThang);
	ngay.nam = atoi(tempNam);
	if (KiemTraNgay(ngay) == 0)
	{
		cout << "\t\tNgay nay khong hop le,hay nhap lai" << endl;
		goto Do;
	}
	else {
		return;
	}
}
//Kiem tra tinh hop le cua ngay
int KiemTraNgay(Ngay ngay)
{
	switch (ngay.thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if (ngay.ngay <= 31 && ngay.ngay > 0)
		{
			return 1;
		}
		else return 0;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if (ngay.ngay <= 30 && ngay.ngay > 0)
		{
			return 1;
		}
		else return 0;
		break;
	}
	default:
		if ((ngay.nam % 100 != 0 && ngay.nam % 4 == 0)||(ngay.nam % 100 == 0 && ngay.nam % 400 == 0))
		{
			if (ngay.ngay == 29) return 1;
			else return 0;
		}
		else
		{
			if (ngay.ngay == 28) return 1;
			else return 0;
		}
		break;
	}
}
