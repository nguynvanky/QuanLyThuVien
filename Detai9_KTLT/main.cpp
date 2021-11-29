#include "Header.h"
int main()
{
#pragma region setup
	SetConsoleTitle(L"Quản Lý Thư Viện");
	// ẩn con trỏ
	ShowCur(0);
	DisableResizeWindow();
	// để in ra được kí tự trong txt
	SetConsoleOutputCP(65001);
	//system("mode con: cols=209 lines=50");
	system("cls");
#pragma endregion
	int chon, x, y, vitriMax, n = 0, sapxep = 0;
	Sach* DS_Sach = new Sach[MAX];
	ThongKe* TK = new ThongKe[MAX];
	int nNamXB = 0, nTG = 0, nNXB = 0;
	x = 0;
	y = 35;
	int x_chon = 2;
	int y_chon = 19;
	bool sort = false, ghiFile = false;
	Label(5);
	do {
		//chon = -1;
		Chon(chon, x_chon, y_chon, y);
		gotoXY(x, y);
		switch (chon)
		{
		case 0:
			if (ghiFile == true)
				Thoat();
			else
				printf("Ban chua ghi du lieu ra file!!!\n");
			break;
		case 1:
			n = 0;
			DocFile(DS_Sach, n);
			break;
		case 2:
			HienThiKhoSach(DS_Sach, n);
			break;
		case 3:
			ThemSach(DS_Sach, n);
			break;
		case 4:
			XoaSach(DS_Sach, n);
			break;
		case 5:
			SuaSach(DS_Sach, n);
			break;
		case 6:
			SapXepTangGiam(DS_Sach, n, sapxep);
			if (sapxep != 3)
				sort = true;
			else
				sort = false;
			break;
		case 7:
			if (sort == true)
				TimKiemSach(DS_Sach, n, sapxep);
			else
				printf("Ban phai sap xep theo ma sach truoc khi tim kiem\n");
			break;
		case 8:
			ThongKeSoLuong(TK, DS_Sach, n, nNamXB, nTG, nNXB);
			break;
		case 9:
			if (nTG == 0)
			{
				printf("Xin hay thong ke truoc!\n");
				break;
			}
			vitriMax = TacGia_Max_Sach(TK, nTG);
			printf("Tac gia %s co so luong nhieu nhat va so luong la %d\n", TK[vitriMax].TG.TenTacGia, TK[vitriMax].TG.SoLuong);
			break;
		case 10:
			if (nNXB == 0)
			{
				printf("Xin hay thong ke truoc!\n");
				break;
			}
			vitriMax = NhaXuatBan_Max_Sach(TK, nNXB);
			printf("Nha xuat ban %s co so luong nhieu nhat va so luong la %d\n", TK[vitriMax].NXB.NXB, TK[vitriMax].NXB.SoLuong);
			break;
		case 11:
			if (nNamXB == 0)
			{
				printf("Xin hay thong ke truoc!\n");
				break;
			}
			vitriMax = NamXB_Max_Sach(TK, nNamXB);
			printf("Nam xuat ban %d co so luong nhieu nhat va so luong la %d\n", TK[vitriMax].NamXB.NamXB, TK[vitriMax].NamXB.SoLuong);
			break;
		case 12:
			GhiFile(DS_Sach, n);
			ghiFile = true;
			if (n != 0)
			{
				printf("Da ghi du lieu ra file, ban co the thoat\n");
			}
			break;
		case 99:
			system("cls");
			y = 35;
			Label(0);
			break;
		}
		if (chon != 99)
			y = whereY();
	} while (chon != 0 || ghiFile == false);
	delete[]DS_Sach;
	delete[]TK;
	return 0;
}