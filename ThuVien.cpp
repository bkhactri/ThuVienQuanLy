#include "ThuVien.h"
#include"HamHoTro.h"
//Ham khoi tao va huy
ThuVien::ThuVien(){}
ThuVien::ThuVien(const ThuVien& other)
{
	for (int i = 0; i < other.dsDocGia.size(); i++)
	{
		dsDocGia[i] = other.dsDocGia[i];
	}
	for (int i = 0; i < other.dsSach.size(); i++)
	{
		dsSach[i] = other.dsSach[i];
	}
}
ThuVien::~ThuVien() {}
//Phuong thuc quan ly chung
void ThuVien::QuanLySach()
{
	bool Break = false;
	while (Break != true)
	{
		char choice[50];
		int dem;
		int vt[100];
		system("cls");
		cout << "\t\t========== QUAN LY SACH ==========\n" << endl;
		cout << "\t\t1.Them sach vao thu vien\n" << endl;
		cout << "\t\t2.Cap nhat thong tin sach\n" << endl;
		cout << "\t\t3.Tim kiem sach trong bo du lieu\n" << endl;
		cout << "\t\t4.Xoa thong tin sach trong bo du lieu\n" << endl;
		cout << "\t\t5.Xem thong tin cua toan bo sach\n" << endl;
		cout << "\t\t6.Quay lai\n" << endl;
		cout << "\t\tNhap lua chon cua ban: "; gets_s(choice, 50);
		int temp = KiemTra(choice);
		switch (temp)
		{
		case 1:
			system("cls");
			this->ThemSach();
			break;

		case 2:
			system("cls");
			this->SuaSach();
			break;
		case 3:
			system("cls");
			DO:
			dem = this->TimKiemNhieuSach(vt);
			if (dem == 0) {
				cout << "\t\tKhong ton tai du lieu sach" << endl;
				cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
				if (atoi(choice) == 1) goto DO;
			}
			else 
			{
				cout << "\t\tKet qua tim kiem:\n" << endl;
				cout << "SACH TIENG VIET: \n" << endl;
				cout << left << setw(10) << "Ma sach" << "\t" << left << setw(25) << "Ten sach" << "\t" << left << setw(25) << "Tac gia" << "\t" << left << setw(25) << "Nha xuat ban" << "\t" << left << setw(8) << "Gia" << "\t" << left << setw(9) << "Tinh Trang" << "\t" << endl;
				for (int i = 0; i < dem; i++)
				{
					if (dsSach[vt[i]]->KiemtraLoai() == 1)
					{
						cout << "===========================================================================================================================================" << endl;
						dsSach[vt[i]]->XuatThongTinSach();
						cout << endl;
					}
				}
				cout << endl;
				cout << "SACH NGOAI VAN: \n" << endl;
				cout << left << setw(10) << "Ma sach" << "\t" << left << setw(25) << "Ten sach" << "\t" << left << setw(25) << "Tac gia" << "\t" << left << setw(25) << "Nha xuat ban" << "\t" << left << setw(8) << "Gia" << "\t" << left << setw(20) << "ISBN" << "\t" << left << setw(9) << "Tinh Trang" << "\t" << endl;
				for (int i = 0; i < dem; i++)
				{
					if (dsSach[vt[i]]->KiemtraLoai() == 2)
					{
						cout << "===================================================================================================================================================================" << endl;
						dsSach[vt[i]]->XuatThongTinSach();
						cout << endl;
					}
				}
			}
			system("pause");
			break;
		case 4:
			system("cls");
			this->XoaSach();
			system("pause");
			break;
		case 5:
			system("cls");
			this->XemToanBoSach();
			system("pause");
			break;
		case 6:
			Break = true;
			break;
		default:
			cout << "\t\tLua chon khong hop le" << endl;
			system("pause");
			break;
		}
	}
}
void ThuVien::QuanLyDocGia()
{
	int vt;
	bool Break = false;
	while (Break != true)
	{
		char choice[50];
		system("cls");
		cout << "\t\t=============== QUAN LY DOC GIA ===============\n" << endl;
		cout << "\t\t1.Dang ky them thong tin doc gia\n" << endl;
		cout << "\t\t2.Cap nhat thong tin doc gia\n" << endl;
		cout << "\t\t3.Tim kiem thong tin doc gia trong bo du lieu\n" << endl;
		cout << "\t\t4.Xoa thong tin doc gia trong bo du lieu\n" << endl;
		cout << "\t\t5.Xem thong tin cua toan bo doc gia\n" << endl;
		cout << "\t\t6.Danh sach doc gia qua han tra sach\n" << endl;
		cout << "\t\t7.Quay lai\n" << endl;
		cout << "\t\tNhap lua chon cua ban: "; gets_s(choice, 50);
		int temp = KiemTra(choice);
		switch (temp)
		{
		case 1:
			system("cls");
			this->ThemDocGia();
			system("pause");
			break;

		case 2:
			system("cls");
			this->SuaThongTinDocGia();
			break;
		case 3:
			DO:
			system("cls");
			cout << "\n\n";
			cout << "\t\tNhap ma doc gia in tren phieu muon sach de tim kiem thong tin: ";
			vt = this->TimKiemDocGia();
			if (vt == -1) {
				cout << "\t\tKhong ton tai doc gia" << endl;
				cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
				if (atoi(choice) == 1) goto DO;
			}
			else {
				cout << "\t\tKet qua tim kiem:\n " << endl;
				cout << left << setw(6) << "Ma doc gia" << "\t" << left << setw(20) << "Ten doc gia" << "\t" << left << setw(7) << "Gioi tinh" << "\t" << left << setw(7) << "So sach muon" << endl;
				dsDocGia[vt]->XuatThongTinDocGia();
				cout << endl;
			}
			system("pause");
			break;
		case 4:
			system("cls");
			this->XoaThongTinDocGia();
			system("pause");
			break;
		case 5:
			system("cls");
			this->XemToanBoDocGia();
			system("pause");
			break;
		case 6:
			system("cls");
			this->DanhSachDongPhat();
			system("pause");
			break;
		case 7:
			Break = true;
			break;
		default:
			cout << "\t\tLua chon khong hop le" << endl;
			system("pause");
			break;
		}
	}
}
void ThuVien::QuanLyPhieuMuonSach()
{
	char choice[50];
	DO:
	system("cls");
	cout << "\n\n";
	cout << "\t\tNhap ma doc gia in tren phieu muon sach de tim kiem thong tin: ";
	int vt = this->TimKiemDocGia();
	if (vt == -1) {
		cout << "\t\tKhong ton tai doc gia" << endl;
		cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
		if (atoi(choice) == 1) goto DO;
	}
	else {
		bool Break = false;
		while (Break != true)
		{
			Ngay ngaytra;
			Sach* input = new Sach;
			int vt1;
			string Temp;
			system("cls");
			cout << "\t\t===== QUAN LY PHIEU MUON SACH =====\n" << endl;
			cout << "\t\t1.Doc gia muon them sach\n" << endl;
			cout << "\t\t2.Doc gia tra sach\n" << endl;
			cout << "\t\t3.Quay lai\n" << endl;
			cout << "\t\tNhap lua chon cua ban: "; gets_s(choice, 50);
			cout << endl;
			int temp = KiemTra(choice);
			switch (temp)
			{
			case 1:
				system("cls");
				if (DieuKienMuonSach(vt) == 0)
				{
					cout << "\t\tSo luong sach doc gia nay chua tra lon hon hoac bang 5 .Khong the muon them" << endl;
				}
				else
				{
				DO1:
					cout << "\n\n";
					vt1 = this->TimKiemSach();
					if (vt1 == -1)
					{
						cout << "\t\tKhong ton tai sach" << endl;
						cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
						if (atoi(choice) == 1) goto DO1;
					}
					else {
						if (dsSach[vt1]->LayTinhTrang() == true)
						{
							cout << "\t\tSach nay da duoc muon vui long chon sach khac" << endl;
							cout << "\t\tAn 1 de tim kiem sach khac hoac an phim bat ky de thoat: "; gets_s(choice, 50);
							if (atoi(choice) == 1) goto DO1;
						}
						else {
							input = dsSach[vt1];
							dsSach[vt1]->DatTinhTrang(true);
							dsDocGia[vt]->TaoPhieuMuonSach(input);
							cout << "\t\tDa cap nhat thanh cong sach muon" << endl;
						}
					}
				}
				system("pause");
				break;

			case 2:
				system("cls");
				if (dsDocGia[vt]->LaySoLuongSach() == 0)
				{
					cout << "\t\tDoc gia nay chua muon sach" << endl;
				}
				else {
				DO2:
					system("cls");
					gotoxy(0, 22);
					cout << "\t\tKet qua tim kiem sach cua doc gia: \n" << endl;
					cout << left << setw(6) << "Ma doc gia" << "\t" << left << setw(20) << "Ten doc gia" << "\t" << left << setw(7) << "Gioi tinh" << "\t" << left << setw(7) << "So sach muon" << endl;
					cout << "=============================================================================================" << endl;
					dsDocGia[vt]->XuatThongTinDocGia();
					gotoxy(6, 0);
					cout << "\n\n";
					cout << "\t\tNhap ma sach doc gia tra: ";
					getline(cin, Temp);
					vt1 = dsDocGia[vt]->TimSachCuaDocGia(Temp);
					if (vt1 == -1) {
						cout << "\t\tDoc gia khong muon sach nay" << endl;
						cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
						if (atoi(choice) == 1) goto DO2;
					}
					else {
						if (dsDocGia[vt]->LayTinhTrangSach(vt1) != 0)
						{
							cout << "\t\tDoc gia da tra sach nay roi" << endl;
							cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
							if (atoi(choice) == 1) goto DO2;
						}
						else 
						{
							CapNhatNgayTra(ngaytra);
							dsDocGia[vt]->DatNgayTra(ngaytra, vt1);
							cout << "\t\tCap nhat ngay tra thanh cong" << endl;
						}
					}
				}
				system("pause");
				break;
			case 3:
				Break = true;
				break;
			default:
				cout << "\t\tLua chon khong hop le" << endl;
				system("pause");
				break;
			}
		}
	}
}
//Phuong thuc quan ly sach
void ThuVien::GhiFileSach()
{
	if (dsSach.size() == 0)
	{
		return;
	}
	else {
		fstream f;
		f.open("DanhSachCuonSach.bin", ios::out | ios::trunc|ios::binary);
		f << dsSach.size() << endl;
		for (int i = 0; i < dsSach.size(); i++)
		{
			dsSach[i]->GhiVaoFile();
		}
		f.close();
	}
}
void ThuVien::DocFileSach()
{
	fstream f;
	int size;
	f.open("DanhSachCuonSach.bin", ios::binary||ios::in);
	if (f.fail()) { return; }
	f >> size;
	for (int i = 0; i < size; i++)
	{
		bool tt;
		int loai,_gia;
		Sach* input;
		string _ma, _tenS, _tenTG, _NXB, _ISBN;
		f >> loai;
		f.ignore();
		getline(f, _ma);
		getline(f, _tenS);
		getline(f, _tenTG);
		getline(f, _NXB);
		f >> _gia;
		f >> tt;
		if (loai == 1)
		{
			input = new SachTiengViet(_ma, _tenS, _tenTG, _NXB, _gia, tt);
		}
		if (loai == 2)
		{
			f.ignore();
			getline(f, _ISBN);
			input = new SachNgoaiVan(_ma, _tenS, _tenTG, _NXB, _gia, tt, _ISBN);
		}
		dsSach.push_back(input);
	}
	f.close();
}
void ThuVien::ThemSach()
{
	string str;
	bool Break = false;
	while (Break != true)
	{
		char choice[50];
		system("cls");
		cout << "\t\t=====THEM THONG TIN SACH=====\n" << endl;
		cout << "\t\t1.Them sach tieng viet\n" << endl;
		cout << "\t\t2.Them sach ngoai van\n" << endl;
		cout << "\t\t3.Quay lai\n" << endl;
		cout << "\t\tNhap lua chon cua ban: "; gets_s(choice, 50);
		cout << endl;
		Sach* input;
		int temp = KiemTra(choice);
		switch (temp)
		{
		case 1:
			cout << "\t\tThem sach tieng viet\n" << endl;
			input = new SachTiengViet;
			input->NhapThongTinSach();
			if(KiemTraMaSachTrung(input->LayMaSach()) == 1)
			{
				do
				{
					cout << "\t\tOops !! Ma sach nay bi trung ban hay nhap lai ma sach khac: "; getline(cin, str);
				} while (KiemTraMaSachTrung(str) == 1);
				input->DatMaSach(str);
			}
			dsSach.push_back(input);
			cout << "\t\tThem thanh cong" << endl;
			system("pause");
			break;
		case 2:
			cout << "\t\tThem sach ngoai van\n" << endl;
			input = new SachNgoaiVan;
			input->NhapThongTinSach();
			if (KiemTraMaSachTrung(input->LayMaSach()) == 1)
			{
				do
				{
					cout << "\t\tOops !! Ma sach nay bi trung ban hay nhap lai ma sach khac: "; getline(cin, str);
				}while (KiemTraMaSachTrung(str) == 1);
				input->DatMaSach(str);
			}
			dsSach.push_back(input);
			cout << "\t\tThem thanh cong" << endl;
			system("pause");
			break;
		case 3:
			Break = true;
			break;
		default:
			cout << "\t\tLua chon khong hop le" << endl;
			system("pause");
			break;
		}
	}
}
int ThuVien::TimKiemSach()
{
	string strTemp;
	int gia;
	bool Break = false;
	while (Break != true)
	{
		char choice[50];
		system("cls");
		cout << "\n\n";
		cout << "\t\tBan hay lua chon tim kiem theo sach theo thong tin ban co sau do chuong trinh se xu ly tac vu ban yeu cau\n" << endl;
		cout << "\t\t1.Tim sach theo ma\n" << endl;
		cout << "\t\t2.Tim sach theo ten sach\n" << endl;
		cout << "\t\t3.Tim sach theo ten tac gia\n" << endl;
		cout << "\t\t4.Tim sach theo nha xuat ban\n" << endl;
		cout << "\t\t5.Tim sach theo gia\n" << endl;
		cout << "\t\tNhap lua chon cua ban: "; gets_s(choice, 50);
		int temp = KiemTra(choice);
		switch (temp)
		{
		case 1:
			cout << "\t\tNhap ma sach: ";
			getline(cin, strTemp);
			Uppercase(strTemp);
			for (int i = 0; i < dsSach.size(); i++)
			{
				if (dsSach[i]->LayMaSach() == strTemp)
				{
					return i;
				}
			}
			return -1;
			break;
		case 2:
			cout << "\t\tNhap vao ten sach : ";
			getline(cin, strTemp);
			Uppercase(strTemp);
			for (int i = 0; i < dsSach.size(); i++)
			{
				if (dsSach[i]->LayTenSach() == strTemp)
				{
					return i;
				}
			}
			return -1;
			break;
		case 3:
			cout << "\t\tNhap vao ten tac gia : ";
			getline(cin, strTemp);
			Uppercase(strTemp);
			for (int i = 0; i < dsSach.size(); i++)
			{
				if (dsSach[i]->LayTacGia() == strTemp)
				{
					return i;
				}
			}
			return -1;
			break;
		case 4:
			cout << "\t\tNhap vao nha xuat ban : ";
			getline(cin, strTemp);
			Uppercase(strTemp);
			for (int i = 0; i < dsSach.size(); i++)
			{
				if (dsSach[i]->LayNhaXB() == strTemp)
				{
					return i;
				}
			}
			return -1;
			break;
		case 5:
			cout << "\t\tNhap vao gia sach : ";
			cin >> gia;
			for (int i = 0; i < dsSach.size(); i++)
			{
				if (dsSach[i]->LayGia() == gia)
				{
					return i;
				}
			}
			return -1;
			break;
		default:
			cout << "\t\tLua chon khong hop le" << endl;
			system("pause");
			break;
		}
	}
}
int ThuVien::TimKiemNhieuSach(int vt[100])
{
	string strTemp;
	int dem = 0;
	bool Break = false;
	while (Break != true)
	{
		char choice[50];
		system("cls");
		cout << "\n\n";
		cout << "\t\tBan hay lua chon tim kiem theo sach theo thong tin ban co sau do chuong trinh se xu ly tac vu ban yeu cau\n" << endl;
		cout << "\t\t1.Tim sach theo ma\n" << endl;
		cout << "\t\t2.Tim sach theo ten sach\n" << endl;
		cout << "\t\t3.Tim sach theo ten tac gia\n" << endl;
		cout << "\t\t4.Tim sach theo nha xuat ban\n" << endl;
		cout << "\t\tNhap lua chon cua ban: "; gets_s(choice, 50);
		int temp = KiemTra(choice);
		switch (temp)
		{
		case 1:
			cout << "\t\tNhap ma sach: ";
			getline(cin, strTemp);
			Uppercase(strTemp);
			for (int i = 0; i < dsSach.size(); i++)
			{
				if (dsSach[i]->LayMaSach().find(strTemp) != size_t(-1) || dsSach[i]->LayMaSach() == strTemp)
				{
					vt[dem++] = i;
				}
			}
			return dem;
			break;
		case 2:
			cout << "\t\tNhap vao ten sach : ";
			getline(cin, strTemp);
			Uppercase(strTemp);
			for (int i = 0; i < dsSach.size(); i++)
			{
				if (dsSach[i]->LayTenSach().find(strTemp) != size_t(-1) || dsSach[i]->LayTenSach() == strTemp)
				{
					vt[dem++] = i;
				}
			}
			return dem;
			break;
		case 3:
			cout << "\t\tNhap vao ten tac gia : ";
			getline(cin, strTemp);
			Uppercase(strTemp);
			for (int i = 0; i < dsSach.size(); i++)
			{
				if (dsSach[i]->LayTacGia().find(strTemp) != size_t(-1) || dsSach[i]->LayTacGia() == strTemp)
				{
					vt[dem++] = i;
				}
			}
			return dem;
			break;
		case 4:
			cout << "\t\tNhap vao nha xuat ban : ";
			getline(cin, strTemp);
			Uppercase(strTemp);
			for (int i = 0; i < dsSach.size(); i++)
			{
				if (dsSach[i]->LayNhaXB().find(strTemp) != size_t(-1) || dsSach[i]->LayNhaXB() == strTemp)
				{
					vt[dem++] = i;
				}
			}
			return dem;
			break;
		default:
			cout << "\t\tLua chon khong hop le" << endl;
			system("pause");
			break;
		}
	}
}
void ThuVien::SuaSach()
{
	char choice[50];
	DO:
	int vt = this->TimKiemSach();
	if (vt == -1) {
		cout << "\t\tKhong ton tai du lieu sach" << endl;
		cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
		if (atoi(choice) == 1) goto DO;
	}
	else if (dsSach[vt]->LayTinhTrang() == true)
	{
		cout << "\t\tSach nay dang duoc muon vui long khong chinh sua khi doc gia chua tra sach" << endl;
		cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
		if (atoi(choice) == 1) goto DO;
	}
	else {
		string Temp;
		int _Gia;
		bool Break = false;
		while (Break != true)
		{
			system("cls");
			cout << "\t\t===== CAP NHAT THONG TIN SACH =====\n" << endl;
			cout << "\t\t1.Cap nhat ma sach\n" << endl;
			cout << "\t\t2.Cap nhat ten sach\n" << endl;
			cout << "\t\t3.Sua ten tac gia\n" << endl;
			cout << "\t\t4.Cap nhat nha xuat ban\n" << endl;
			cout << "\t\t5.Cap nhat gia ban\n" << endl;
			cout << "\t\t6.Cap nhat ma ISBN\n" << endl;
			cout << "\t\t7.Quay lai\n" << endl;
			cout << "\t\tNhap lua chon cua ban: "; gets_s(choice, 50);
			cout << endl;
			int temp = KiemTra(choice);
			switch (temp)
			{
			case 1:
				cout << "\t\tCap nhat ma sach moi ( Day la ma sach cu: " << dsSach[vt]->LayMaSach() << " )\n" << endl;
				cout << "\t\tNhap ma sach moi: "; getline(cin, Temp);
				Uppercase(Temp);
				dsSach[vt]->DatMaSach(Temp);
				cout << "\t\tCap nhat thanh cong" << endl;
				system("pause");
				break;
			case 2:
				cout << "\t\tCap nhat ten sach moi ( Day la ten sach cu: " << dsSach[vt]->LayTenSach() << " )\n" << endl;
				cout << "\t\tNhap ten sach moi: "; getline(cin, Temp);
				Uppercase(Temp);
				dsSach[vt]->DatTenSach(Temp);
				cout << "\t\tCap nhat thanh cong" << endl;
				system("pause");
				break;
			case 3:
				cout << "\t\tCap nhat ten tac gia moi ( Day la ten tac gia cu: " << dsSach[vt]->LayTacGia() << " )\n" << endl;
				cout << "\t\tNhap ten tac gia moi: "; getline(cin, Temp);
				Uppercase(Temp);
				dsSach[vt]->DatTacGia(Temp);
				cout << "\t\tCap nhat thanh cong" << endl;
				system("pause");
				break;
			case 4:
				cout << "\t\tCap nhat nha xuat ban moi ( Day la nha xuat ban cu: " << dsSach[vt]->LayNhaXB() << " )\n" << endl;
				cout << "\t\tNhap nha xuat ban moi: "; getline(cin, Temp);
				Uppercase(Temp);
				dsSach[vt]->DatNhaXB(Temp);
				cout << "\t\tCap nhat thanh cong" << endl;
				system("pause");
				break;
			case 5:
				cout << "\t\tCap nhat gia sach moi ( Day la gia sach cu: " << dsSach[vt]->LayGia() << " )\n" << endl;
				cout << "\t\tNhap gia sach moi: "; cin >> _Gia;
				dsSach[vt]->DatGia(_Gia);
				cout << "\t\tCap nhat thanh cong" << endl;
				system("pause");
				break;
			case 6:
				if (dsSach[vt]->KiemtraLoai() == 1)
				{
					cout << "\t\tDay la sach tieng viet khong the cap nhat ISBN" << endl;
				}
				else if (dsSach[vt]->KiemtraLoai() == 2)
				{
					cout << "\t\tCap nhat ma ISBN moi ( Day la ma ISBN cu: " << ((SachNgoaiVan*)dsSach[vt])->LayISBN() << " )\n" << endl;
					cout << "\t\tNhap ma ISBN moi: "; getline(cin, Temp);
					Uppercase(Temp);
					((SachNgoaiVan*)dsSach[vt])->DatISBN(Temp);
					cout << "\t\tCap nhat thanh cong" << endl;
				}
				system("pause");
				break; 
			case 7:
				Break = true;
				break;
			default:
				cout << "\t\tLua chon khong hop le" << endl;
				system("pause");
				break;
			}
		}
	}
}
void ThuVien::XoaSach()
{
	char choice[50];
DO:
	int vt = this->TimKiemSach();
	if (vt == -1) {
		cout << "\t\tKhong ton tai du lieu sach" << endl;
		cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
		if (atoi(choice) == 1) goto DO;
	}
	else
	{	
		dsSach.erase(dsSach.begin() + vt);
		cout << "\t\tDa xoa" << endl;
	}
}
void ThuVien::XemToanBoSach()
{
	cout << "SACH TIENG VIET: \n" << endl;
	cout << left << setw(10) << "Ma sach" << "\t" << left << setw(25) << "Ten sach" << "\t" << left << setw(25) << "Tac gia" << "\t" << left << setw(25) << "Nha xuat ban" << "\t" << left << setw(8) << "Gia" << "\t" << left << setw(9) << "Tinh Trang" << "\t" << endl;
	for (int i = 0; i < dsSach.size(); i++)
	{
		if (dsSach[i]->KiemtraLoai() == 1)
		{
			cout << "===========================================================================================================================================" << endl;
			dsSach[i]->XuatThongTinSach();
			cout << endl;
		}
	}
	cout << endl;
	cout << "SACH NGOAI VAN: \n" << endl;
	cout << left << setw(10) << "Ma sach" << "\t" << left << setw(25) << "Ten sach" << "\t" << left << setw(25) << "Tac gia" << "\t" << left << setw(25) << "Nha xuat ban" << "\t" << left << setw(8) << "Gia" << "\t" << left << setw(20) << "ISBN" << "\t" << left << setw(9) << "Tinh Trang" << "\t" << endl;
	for (int i = 0; i < dsSach.size(); i++)
	{
		if (dsSach[i]->KiemtraLoai() == 2)
		{
			cout << "===================================================================================================================================================================" << endl;
			dsSach[i]->XuatThongTinSach();
			cout << endl;
		}
	}
}
//Phuong thuc quan ly doc gia
void ThuVien::GhiFileDocGia()
{
	if (dsDocGia.size() == 0)
	{
		return;
	}
	else
	{
		fstream f;
		f.open("DanhSachDocGia.bin", ios::out | ios::trunc|ios::binary);
		f << dsDocGia.size() << endl;
		for (int i = 0; i < dsDocGia.size(); i++)
		{
			dsDocGia[i]->GhiVaoFile();
		}
		f.close();
	}
}
void ThuVien::DocFileDocGia()
{
	fstream f;
	int size1,size2;
	f.open("DanhSachDocGia.bin", ios::in||ios::binary);
	if (f.fail()) { return; }
	f >> size1;
	for (int i = 0; i < size1; i++)
	{
		DocGia* docgia;
		vector<PhieuMuonSach*>SoLuong;
		string ma, ten, gioitinh;
		f.ignore();
		getline(f, ma);
		getline(f, ten);
		getline(f, gioitinh);
		f >> size2;
		for (int j = 0; j < size2; j++)
		{
			int loai;
			string _maS, _tenS;
			Sach* sach = new Sach;
			Ngay muon, tra;
			f >> loai;
			f.ignore();
			getline(f, _maS);
			getline(f, _tenS);
			f >> muon.ngay >> muon.thang >> muon.nam;
			f >> tra.ngay >> tra.thang >> tra.nam;
			if (loai == 1)
			{
				sach = new SachTiengViet(_maS, _tenS);
			}
			if (loai == 2)
			{
				sach = new SachNgoaiVan(_maS, _tenS);
			}
			PhieuMuonSach* input = new PhieuMuonSach(sach, muon, tra);
			SoLuong.push_back(input);
		}
		docgia = new DocGia(ma, ten, gioitinh, SoLuong);
		dsDocGia.push_back(docgia);
	}
}
void ThuVien::ThemDocGia()
{
	cout << "\t\tThem doc gia\n" << endl;
	string str;
	DocGia* input=new DocGia;
	input->NhapThongTinDocGia();
	if (KiemTraMaDocGiaTrung(input->LayMaDocGia()) == 1)
	{
		do
		{
			cout << "\t\tOops !! Ma doc gia nay bi trung ban hay nhap lai ma sach khac: "; getline(cin, str);
		} while (KiemTraMaDocGiaTrung(str) == 1);
		input->DatMaDocGia(str);
	}
	dsDocGia.push_back(input);
	cout << "\n\t\tThem thanh cong" << endl;
}
int ThuVien::TimKiemDocGia()
{
	string ma;
	getline(cin, ma);
	Uppercase(ma);
	for (int i = 0; i < dsDocGia.size(); i++)
	{
		if (dsDocGia[i]->LayMaDocGia() == ma)
		{
			return i;
		}
	}
	return -1;
}
void ThuVien::SuaThongTinDocGia()
{
	char choice[50];
DO:
	system("cls");
	cout << "\n\n";
	cout << "\t\tNhap ma doc gia in tren phieu muon sach de sua thong tin: ";
	int vt = this->TimKiemDocGia();
	if (vt == -1) 
	{
		cout << "\t\tKhong ton tai doc gia" << endl;
		cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
		if (atoi(choice) == 1) {
			system("cls");
			goto DO;
		}
	}
	else {
		string Temp;
		bool Break = false;
		while (Break != true)
		{
			system("cls");
			cout << "\t\t====== CAP NHAT THONG TIN DOC GIA ======\n" << endl;
			cout << "\t\t1.Cap nhat ma doc gia\n" << endl;
			cout << "\t\t2.Cap nhat ten doc gia\n" << endl;
			cout << "\t\t3.Cap nhat gioi tinh\n" << endl;
			cout << "\t\t4.Quay lai\n" << endl;
			cout << "\t\tNhap lua chon cua ban: "; gets_s(choice, 50);
			cout << endl;
			int temp = KiemTra(choice);
			switch (temp)
			{
			case 1:
				cout << "\t\tCap nhat ma doc gia moi ( Day la ma doc gia cu: " << dsDocGia[vt]->LayMaDocGia() << " )\n" << endl;
				cout << "\t\tNhap vao ma doc gia moi: "; getline(cin, Temp);
				Uppercase(Temp);
				dsDocGia[vt]->DatMaDocGia(Temp);
				cout << "\t\tCap nhat thanh cong" << endl;
				system("pause");
				break;
			case 2:
				cout << "\t\tCap nhat ten doc gia (Day la ten cu: " << dsDocGia[vt]->LayTen() << " )\n" << endl;
				cout << "\t\tNhap vao ten moi cho doc gia: "; getline(cin, Temp);
				Uppercase(Temp);
				dsDocGia[vt]->DatTen(Temp);
				cout << "\t\tCap nhat thanh cong" << endl;
				system("pause");
				break;
			case 3:
				cout << "\t\tCap nhat gioi tinh moi (Day la gioi tinh cu: " << dsDocGia[vt]->LayGioiTinh() << " )\n" << endl;
				cout << "\t\tNhap vao gioi tinh doc gia: "; getline(cin, Temp);
				Uppercase(Temp);
				dsDocGia[vt]->DatGioiTinh(Temp);
				cout << "\t\tCap nhat thanh cong" << endl;
				system("pause");
				break;
			case 4:
				Break = true;
				break;
			default:
				cout << "\t\tLua chon khong hop le" << endl;
				system("pause");
				break;
			}
		}
	}
}
void ThuVien::XoaThongTinDocGia()
{

	char choice[50];
DO:
	cout << "\n\n";
	cout << "\t\tNhap ma doc gia in tren phieu muon sach de xoa thong tin: ";
	int vt = this->TimKiemDocGia();
	if (vt == -1)
	{
		cout << "\t\tKhong ton tai doc gia" << endl;
		cout << "\t\tAn 1 de tim kiem lai hoac an phim bat ky de thoat: "; gets_s(choice, 50);
		if (atoi(choice) == 1) { 
			system("cls"); 
			goto DO; 
		}
	}
	else {
		dsDocGia.erase(dsDocGia.begin() + vt);
		cout << "\t\tDa xoa" << endl;
	}
}
void ThuVien::XemToanBoDocGia()
{
	
	for (int i = 0; i < dsDocGia.size(); i++)
	{
		cout << left << setw(10) << "Ma doc gia" << "\t" << left << setw(20) << "Ten doc gia" << "\t" << left << setw(7) << "Gioi tinh" << "\t" << left << setw(7) << "So sach muon" << endl;
		cout << "===================================================================================================" << endl;
		dsDocGia[i]->XuatThongTinDocGia();
		cout << endl << endl;
	}
}
void ThuVien::DanhSachDongPhat()
{
	bool flag = false;
	cout << "\n\nDanh sach cac doc gia tra sach tre han va so tien phat" << endl << endl;
	for (int i = 0; i < dsDocGia.size(); i++)
	{
		int temp = dsDocGia[i]->TongTienPhat();
		if (temp != 0)
		{
			cout << left << setw(6) << "Ma doc gia" << "\t" << left << setw(20) << "Ten doc gia" << "\t" << left << setw(7) << "Tong Tien Phat" << endl;
			cout << "===================================================================================================" << endl;
			cout << setw(6) << left << dsDocGia[i]->LayMaDocGia() << "\t\t";
			cout << setw(20) << left << dsDocGia[i]->LayTen() << "\t";
			cout << setw(7) << left << temp << endl << endl;
			cout << "Chi tiet cac sach nop tre han: " << endl;
			cout << "\t" << left << setw(3) << "Loai sach" << "\t" << left << setw(8) << "Ma sach" << "\t" << left << setw(1) << "Ngay Muon" << "\t" << left << setw(1) << "Ngay tra" << "\t" << left << setw(4) << "So ngay tre" << "\t" << left << setw(4) << "Tien phat" << endl;
			dsDocGia[i]->XuatThongTinSachTreHan();
			flag = true;
			cout << endl << endl;
		}
	}
	if (flag == false)
	{
		system("cls");
		cout << "\n\n\t\tHIEN TAI KHONG DOC GIA NAO NOP TRE HAN" << endl;
	}
}

//Kiem tra so bo
int ThuVien::KiemTraMaSachTrung(string ma)
{
	for (int i = 0; i < dsSach.size(); i++)
	{
		if (dsSach[i]->LayMaSach() == ma)
		{
			return 1;
		}
	}
	return 0;
}
int ThuVien::KiemTraMaDocGiaTrung(string ma)
{
	for (int i = 0; i < dsDocGia.size(); i++)
	{
		if (dsDocGia[i]->LayMaDocGia() == ma)
		{
			return 1;
		}
	}
	return 0;
}
int ThuVien::DieuKienMuonSach(int vt)
{
	int dem = 0;
	for (int i = 0; i < dsDocGia[vt]->LaySoLuongSach(); i++)
	{
		if (dsDocGia[vt]->LayTinhTrangSach(i) == 0)
		{
			dem++;
		}
	}
	if (dem >= 5)
	{
		return 0;
	}
	else return 1;
	
}


