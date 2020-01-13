#include "DocGia.h"
#include"HamHoTro.h"
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
int DocGia::LayTinhTrangSach(int vt) { return SoLuong[vt]->NgayTra.ngay; }
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
	f.open("DanhSachDocGia.bin", ios::app | ios::binary);
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
	Uppercase(MaDocGia);
	cout << "\t\tNhap ten doc gia: "; getline(cin, Ten);
	Uppercase(Ten);
	cout << "\t\tNhap gioi tinh: "; getline(cin, GioiTinh);
	Uppercase(GioiTinh);
}
void DocGia::XuatThongTinDocGia()
{
	cout << setw(10) << left << MaDocGia << "\t";
	cout << setw(20) << left << Ten << "\t";
	cout << setw(7) << left << GioiTinh << "\t\t";
	cout << setw(7) << left << SoLuong.size() << "\t";
	cout << endl << endl;
	cout << "Cac cuon sach doc gia nay dang muon: " << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	cout << "\t" << left << setw(3) << "Loai sach" << "\t" << left << setw(8) << "Ma sach" << "\t" << left << setw(25) << "Ten sach" << "\t" << left << setw(1) << "Ngay Muon" << "\t" << left << setw(1) << "Ngay tra" << endl;
	for (int i = 0; i < SoLuong.size(); i++)
	{
		cout << "\t" << setw(3) << left << SoLuong[i]->CuonSach->KiemtraLoai() << "\t";
		cout << "\t" << setw(8) << left << SoLuong[i]->CuonSach->LayMaSach();
		cout << "\t" << setw(25) << left << SoLuong[i]->CuonSach->LayTenSach();
		cout << "\t" << setw(1) << left << SoLuong[i]->NgayMuon.ngay << "/" << SoLuong[i]->NgayMuon.thang << "/" << SoLuong[i]->NgayMuon.nam;
		cout << "\t" << setw(1) << left << SoLuong[i]->NgayTra.ngay << "/" << SoLuong[i]->NgayTra.thang << "/" << SoLuong[i]->NgayTra.nam << endl;
	}
	cout << "--------------------------------------------------------------------------------------------------" << endl;
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
	cout << "--------------------------------------------------------------------------------------------------" << endl;
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
	cout << "--------------------------------------------------------------------------------------------------" << endl;
}

