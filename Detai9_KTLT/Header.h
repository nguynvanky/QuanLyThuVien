#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
#define MAX 1000
#define key_Up		72
#define key_Down	80
#define key_Enter	13
struct Sach {
	int MaSach;
	char TenSach[50];
	char TenTacGia[30];
	char NXB[20];
	int NamXB;
};
struct TacGia {
	char TenTacGia[50];
	int SoLuong = 1;
};
struct NhaXB {
	char NXB[20];
	int SoLuong = 1;
};
struct NamXuatBan {
	int NamXB;
	int SoLuong = 1;
};
struct ThongKe {
	TacGia TG;
	NhaXB NXB;
	NamXuatBan NamXB;
};
void Xuat_1Sach(Sach a);
void Label(int time);
void ThucThi();
void DocFile(Sach DS_Sach[], int& n);
void HienThiKhoSach(Sach DS_Sach[], int n);
void Nhap1Sach(Sach& a);
void ThemSach(Sach DS_Sach[], int& n);
void GhiFile(Sach DS_Sach[], int n);
void XoaSach(Sach DS_Sach[], int& n);
void SuaSach(Sach DS_Sach[], int& n);
void Thoat();
void Chon(int& chon, int& x, int& y, int &cur);
void TenThanhVien(int time);
void SapXepTangGiam(Sach DS_Sach[], int n, int& chon);
void TimKiemSach(Sach DS_Sach[], int n, int chon);
void ThongKeSoLuong(ThongKe TK[], Sach DS_Sach[], int n, int& nNamXB, int& nTG, int& nNXB);
void sortTG(Sach DS_Sach[], int n);
void sortNamXB(Sach DS_Sach[], int n);
void sortNXB(Sach DS_Sach[], int n);
void SaoChepMang(Sach a[], Sach* b, int n);
int TacGia_Max_Sach(ThongKe TK[], int nTG);
int NhaXuatBan_Max_Sach(ThongKe TK[], int nNXB);
int NamXB_Max_Sach(ThongKe TK[], int nNamXB);
void Menu(int time);
void gotoXY(int column, int line);
int whereX();
int whereY();
void TextColor(int color);