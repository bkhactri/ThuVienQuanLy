#include"Sach.h"
#include"HamHoTro.h"
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
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void Uppercase(string& index)
{
	for (int i = 0; i < index.size(); i++)
	{
		index[i] = toupper(index[i]);
	}
}
int SoNgay(Ngay ngay)
{
	if (ngay.thang < 3) {
		ngay.nam--;
		ngay.thang += 12;
	}
	return 365 * ngay.nam + ngay.nam / 4 - ngay.nam / 100 + ngay.nam / 400 + (153 * ngay.thang - 457) / 5 + ngay.ngay - 306;
}
void CapNhatNgayMuon(Ngay& ngay)
{
	time_t baygio = time(0);
	tm* hientai = localtime(&baygio);
	ngay.ngay = hientai->tm_mday;
	ngay.thang = 1 + hientai->tm_mon;
	ngay.nam = 1900 + hientai->tm_year;
}
void CapNhatNgayTra(Ngay& ngay)
{
	char tempNgay[10], tempThang[10], tempNam[10];
	cout << "\t\tNhap ngay tra" << endl;
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
		if ((ngay.nam % 100 != 0 && ngay.nam % 4 == 0) || (ngay.nam % 100 == 0 && ngay.nam % 400 == 0))
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