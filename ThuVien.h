#pragma once
#include"Sach.h"
#include"SachNgoaiVan.h"
#include"SachTiengViet.h"
#include"DocGia.h"
#include<fstream>
#include<Windows.h>
class ThuVien
{
private:
	vector<DocGia*>dsDocGia;
	vector<Sach*>dsSach;
public:
	ThuVien();
	ThuVien(const ThuVien&);
	 ~ThuVien();
public:
	//Quan ly chung
	void QuanLySach();//Giao dien quan ly sach
	void QuanLyDocGia();//Giao dien quan ly doc gia
	void QuanLyPhieuMuonSach();//Giao dien quan ly phieu muon sach cua tung doc gia
	//Quan ly sach
	void GhiFileSach();//Ghi file cho  cac du lieu sach nhap vao trong luc su dung
	void DocFileSach();//Doc file lay du lieu len
	void ThemSach(); //Them vao 1 cuon sach moi cho thu vien
	int TimKiemSach(); //Tim kiem sach trong thu vien (hinh thuc tim kiem bang 5 thuoc tinh ten,ma,ten tac gia,nha xuat ban,gia)
	void SuaSach(); //Sua thong tin 1 cuon sach
	void XoaSach(); //Xoa 1 cuon sach khoi bo du lieu
	void XemToanBoSach(); //Xem toan bo thong tin cua sach trong thu vien
	//Quan ly doc gia
	void GhiFileDocGia(); //Ghi file cho cac du lieu nhap vao trong luc su dung
	void DocFileDocGia(); //Doc file lay du lieu tu database
	void ThemDocGia(); //Them thong tin 1 doc gia vao thu vien
	void SuaThongTinDocGia(); //Sua thong tin cua 1 doc gia
	void XoaThongTinDocGia(); //Xoa hoan toan thong tin cua 1 doc gia khoi thu vien
	int TimKiemDocGia(); //Tim kiem 1 doc gia
	void XemToanBoDocGia(); //Xem toan bo thong tin cac doc gia
	void DanhSachDongPhat(); //Xem danh sach cac doc gia phai dong phat
};
//Ham ho tro
void gotoxy(int x, int y);//Ham gotoxy de  tro xuat o cac vi tri mong muon



