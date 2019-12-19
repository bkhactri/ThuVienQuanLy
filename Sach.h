#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
class Sach
{
private:
	string MaSach;
	string TenSach;
	string TacGia;
	string NhaXuatBan;
	int Gia;
	bool TinhTrang;//false : chua duoc muon | true : dang duoc muon
public:
	Sach();
	Sach(string _ma, string _tenS, string _tenTG, string _NXB, int _gia,bool _tt);
	Sach(string _ma, string _tenS);
	Sach(const Sach&);
	~Sach();
public:
	string LayMaSach();
	void DatMaSach(string);
	string LayTenSach();
	void DatTenSach(string);
	string LayTacGia();
	void DatTacGia(string);
	string LayNhaXB();
	void DatNhaXB(string);
	int LayGia();
	void DatGia(int);
	bool LayTinhTrang();
	void DatTinhTrang(bool);
public:
	virtual void NhapThongTinSach();//Nhap thong tin sach 5 thuoc tinh - thuoc tinh tinh trang se tu duoc cap nhat la false
	virtual void XuatThongTinSach();//Xuat thong tin sach theo 6 thuoc tinh
	virtual int KiemtraLoai() { return 0; }; //Kiem tra xem cac ke thua la loai sach nao
	virtual void GhiVaoFile();//Ghi vao file sach
};
//Ham ho tro
int KiemTra(char a[50]);//Kiem tra xuat nhap
/*
	yeu cau nhap 1 2 3 4.
	Nhap e			
	Nhap 1ee	-> bao loi quuay tro lai nhap tiep
	Nhap eee
*/


