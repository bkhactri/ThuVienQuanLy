#pragma once
#include"Sach.h"
struct Ngay //Ngay thang nam
{
	int ngay, thang, nam;
	Ngay() {
		ngay = thang = nam = 0;
	}
};
//Prototype
//Ham ho tro
//Kiem tra xuat nhap (Xu lay cac loi nhap gay dung chuong trinh
int KiemTra(char a[50]);

//Ham gotoxy de  tro xuat o cac vi tri mong muon
void gotoxy(int x, int y);

//Ham in hoa toan bo chuoi
void Uppercase(string& index);

//Dem so ngay (ham dung de tinh khoang cach 2 ngay -> tinh tien tre han)
int SoNgay(Ngay);

//Kiem tra tinh hop le cua ngay
int KiemTraNgay(Ngay ngay);

//Cap nhat ngay thang nam theo he thong
void CapNhatNgayMuon(Ngay&);

//Cap nhat ngay thang nam bang cach nhap(vi cai nay em muon thay test duoc cai tinh tien)
void CapNhatNgayTra(Ngay&);
