#include"ThuVien.h"
#include"HamHoTro.h"
#pragma comment(lib, "user32")
int main()
{
	system("color F1");
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	cout << "Dang cap nhat du lieu....";
	ThuVien TVDHQG;
	TVDHQG.DocFileSach();
	TVDHQG.DocFileDocGia();
	bool Break = false;
	while (Break != true)
	{
		char choice[50];
		system("cls");
		cout << "\t\t==================== CHUONG TRINH QUAN LY THU VIEN ====================\n" << endl;
		cout << "\t\t1.Quan ly sach\n" << endl;
		cout << "\t\t2.Quan ly doc gia\n" << endl;
		cout << "\t\t3.Quan ly phieu muon sach\n" << endl;
		cout << "\t\t4.Thoat chuong trinh\n" << endl;
		cout << "\t\tNhap lua chon cua ban: "; gets_s(choice, 50);
		int temp = KiemTra(choice);
		switch (temp)
		{
		case 1:
			system("cls");
			TVDHQG.QuanLySach();
			break;
		
		case 2:
			system("cls");
			TVDHQG.QuanLyDocGia();
			break;
		case 3:
			system("cls");
			TVDHQG.QuanLyPhieuMuonSach();
			break;
		case 4:
			TVDHQG.GhiFileSach();
			TVDHQG.GhiFileDocGia();
			Break = true;
			break;
		default:
			cout << "\t\tLua chon khong hop le" << endl;
			system("pause");
			break;
		}
	}
	cout << "\n\t\tDu lieu da duoc cap nhat " << endl;
	return 0;
}
