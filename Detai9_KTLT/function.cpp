#include "Header.h"
void TenThanhVien(int time)
{
	int x = 4;
	int y = 5;
	gotoXY(15, 2);
	TextColor(10);
	cout << "ThÃ nh viÃªn nhÃ³m 4";
	Sleep(time);
	TextColor(14);
	gotoXY(x, y);
	cout << "2001207059 - Nguyen Van Ky (Nhom truong)";
	Sleep(time);
	y = y + 2;
	gotoXY(x, y);
	y = y + 2;
	cout << "2001207208 - Do Nhat Truong  ";
	Sleep(time);
	gotoXY(x, y);
	y = y + 2;
	cout << "2001207028 - Vo Gia Dat      ";
	Sleep(time);
	gotoXY(x, y);
	y = y + 2;
	cout << "2001207182 - Nguyen Tuan Anh ";
	Sleep(time);
	gotoXY(x, y);
	cout << "2001207337 - Le The Tuan     ";
	Sleep(time);

	TextColor(7);
}
void Menu(int time)
{
	int x = 4, y = 19;
	TextColor(15);
	gotoXY(x, y);
	Sleep(time);
	printf("1.  Doc file kho sach");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("2.  Hien thi sach trong thu vien");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("3.  Them sach ");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("4.  Xoa sach  ");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("5.  Sua sach ");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("6.  Sap xep(tang, giam, tac gia)");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("7.  Tim kiem sach");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("8.  Thong ke so luong(NXB, NSX, Tac gia)");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("9.  Tac gia co nhieu sach nhat");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("10. NXB co nhieu sach nhat");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("11. Nam co nhieu sach duoc xuat ban nhat");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("12. Ghi du lieu ra file");
	y++;
	gotoXY(x, y);
	Sleep(time);
	printf("0.  Thoat chuong trinh");
	y++;
	gotoXY(x, y);
	Sleep(time);
	TextColor(4);
	printf("          ESC: XOA MAN HINH");
	TextColor(7);
	gotoXY(16, 19);
}
void Label(int time)
{
	fstream f;
	string s;
	f.open("Label.txt", ios::in);
	f.seekg(3, 0);
	TextColor(11);
	while (!f.eof())
	{
		getline(f, s);
		cout << s << endl;
		Sleep(time);
	}
	TenThanhVien(time);
	Menu(time);
	TextColor(7);
	f.close();
}
void Thoat()
{
	system("cls");
	fstream f("bye.txt", ios::in);
	string s;
	int x = 75;
	int y = 18;
	while (!f.eof())
	{
		getline(f, s);
		gotoXY(x, y++);
		cout << s << endl;;
		Sleep(200);
	}
	f.close();
}
void DocFile(Sach DS_Sach[], int& n)
{
	char file[20];
	printf("Nhap duong dan file: ");
	gets_s(file);
	fstream f(file, ios::in);
	if (f.is_open() == false)
	{
		printf("Loi!! duong dan khong dung!\n");

	}
	else
	{
		while (!f.eof())
		{
			f >> DS_Sach[n].MaSach;
			f >> DS_Sach[n].TenSach;
			f >> DS_Sach[n].TenTacGia;
			f >> DS_Sach[n].NXB;
			f >> DS_Sach[n].NamXB;
			n++;
		}
		printf("Da doc file thanh cong!\n");
	}
	f.close();

}
void GhiFile(Sach DS_Sach[], int n)
{
	if (n == 0)
	{
		printf("Danh sach rong!!\n");
	}
	else
	{
		char file[20];
		printf("Nhap duong dan file: ");
		cin.ignore();
		gets_s(file);
		fstream f(file, ios::out);
		if (f.is_open() == false)
		{
			printf("Loi!! duong dan khong dung!\n");
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				f << DS_Sach[i].MaSach << " ";
				f << DS_Sach[i].TenSach << " ";
				f << DS_Sach[i].TenTacGia << " ";
				f << DS_Sach[i].NXB << " ";
				if (i == n - 1)
					f << DS_Sach[i].NamXB;
				else
					f << DS_Sach[i].NamXB << endl;
			}
			printf("Da ghi file thanh cong!\n");
		}
		f.close();
	}
}
void Xuat_1Sach(Sach a)
{
	printf("|%5d| %40s| %30s| %20s| %9d|\n", a.MaSach, a.TenSach, a.TenTacGia, a.NXB, a.NamXB);

}
void HienThiKhoSach(Sach DS_Sach[], int n)
{
	if (n == 0)
	{
		printf("Danh sach rong\n");
	}
	else

	{
		TextColor(14);
		printf("======================================================= KHO SACH ========================================================\n");
		printf("=========================================================================================================================\n");
		printf("|%5s| %5s| %40s| %30s| %20s| %9s|\n", "STT", "Ma", "Ten sach", "Ten tac gia", "Nha XB", "Nam XB");
		printf("=========================================================================================================================\n");
		for (int i = 0; i < n; i++)
		{
			printf("|%5d| %5d| %40s| %30s| %20s| %9d|\n", i + 1, DS_Sach[i].MaSach, DS_Sach[i].TenSach, DS_Sach[i].TenTacGia, DS_Sach[i].NXB, DS_Sach[i].NamXB);
		}
		printf("=========================================================================================================================\n");
		TextColor(7);

	}
}
void Nhap1Sach(Sach& a)
{
	printf("Ma sach: ");
	scanf_s("%d", &a.MaSach);
	printf("Ten sach: ");
	// xoa bo dem ban phim tuong tu fflush
	cin.ignore();
	gets_s(a.TenSach);
	printf("Ten tac gia: ");
	gets_s(a.TenTacGia);
	printf("Nha xuat ban: ");
	gets_s(a.NXB);
	printf("Nam xuat ban: ");
	scanf_s("%d", &a.NamXB);
}
void ThemSach(Sach DS_Sach[], int& n)
{
	int soluong;
	printf("Ban muon them bao nhieu sach: ");
	scanf_s("%d", &soluong);
	for (int i = 1; i <= soluong; i++)
	{
		printf("=== Nhap thong tin sach thu %d ===\n", i);
		Nhap1Sach(DS_Sach[n]);
		n++;
		printf("Da them...\n");
	}
}
void XoaSach(Sach DS_Sach[], int& n)
{
	if (n == 0)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		int masach;
		printf("Nhap ma sach ban muon xoa: ");
		scanf_s("%d", &masach);
		for (int i = 0; i < n; i++)
		{
			if (DS_Sach[i].MaSach == masach)
			{
				for (int j = i; j < n - 1; j++)
				{
					DS_Sach[j] = DS_Sach[j + 1];
				}
				n--;
				printf("Da xoa thanh cong\n");
				return;
			}
		}
		printf("Khong tim thay %d trong danh sach\n", masach);
	}

}
void SuaSach(Sach DS_Sach[], int& n)
{
	if (n == 0)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		int masach;// 211
		printf("Nhap ma sach ban muon sua: ");
		scanf_s("%d", &masach);
		for (int i = 0; i < n; i++)
		{
			if (DS_Sach[i].MaSach == masach)
			{
				Nhap1Sach(DS_Sach[i]);
				printf("Da sua thanh cong\n");
				return;
			}
		}
		printf("%d khong co trong danh sach\n", masach);
	}
}
void Chon(int& chon, int& x, int& y, int& cur)
{

	int key;
	while (key = _getch())
	{
		if (key == key_Down)
		{
			gotoXY(x, y);
			cout << "  ";
			gotoXY(x + 42, y);
			cout << "  ";
			y++;
		}
		else if (key == key_Up)
		{
			gotoXY(x, y);
			cout << "  ";
			gotoXY(x + 42, y);
			cout << "  ";
			y--;
		}
		else if (key == key_Enter)
		{
			switch (y)
			{
			case 19:
				chon = 1;
				break;
			case 20:
				chon = 2;
				break;
			case 21:
				chon = 3;
				break;
			case 22:
				chon = 4;
				break;
			case 23:
				chon = 5;
				break;
			case 24:
				chon = 6;
				break;
			case 25:
				chon = 7;
				break;
			case 26:
				chon = 8;
				break;
			case 27:
				chon = 9;
				break;
			case 28:
				chon = 10;
				break;
			case 29:
				chon = 11;
				break;
			case 30:
				chon = 12;
				break;
			case 31:
				chon = 0;
				break;
			}
			break;
		}
		else if (key == key_ESC)
		{
			chon = 99;
			break;
		}
		if (y == 18)
			y = 31;
		else if (y == 32)
			y = 19;
		gotoXY(x, y);
		TextColor(12);
		cout << ">>";
		gotoXY(x + 42, y);
		cout << "<<";
		TextColor(7);
	}
}

void SapXepTangGiam(Sach DS_Sach[], int n, int& chon)
{
	if (n == 0)
	{
		printf("Danh sach rong\n");
		return;
	}
	// Bubble sort la tang (đạt)
	// Interchange sort la giam (tuấn)
	do {
		printf("Ban muon sap xep tang hay giam (1. tang, 2. giam, 3. theo tac gia): ");
		scanf_s("%d", &chon);
	} while (chon < 1 || chon > 3 && printf("Chon khong dung yeu cau, xin nhap lai!\n"));
	if (chon == 1)
	{
		// bubble sort
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (DS_Sach[j].MaSach > DS_Sach[j + 1].MaSach)
					swap(DS_Sach[j], DS_Sach[j + 1]);
			}
		}
		printf("Da sap xep tang dan thanh cong\n");
	}
	else if (chon == 2)
	{
		// interchange sort
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (DS_Sach[i].MaSach < DS_Sach[j].MaSach) // cặp nghịch thế
					swap(DS_Sach[i], DS_Sach[j]);

			}
		}
		printf("Da sap xep giam dan thanh cong\n");
	}
	else if (chon == 3) // sắp xếp theo tên tác giả
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (_strcmpi(DS_Sach[j].TenTacGia, DS_Sach[j + 1].TenTacGia) < 0)
					swap(DS_Sach[j], DS_Sach[j + 1]);
			}
		}
		printf("Da sap xep theo ten tac gia thanh cong\n");
	}
}
void TimKiemSach(Sach DS_Sach[], int n, int chon)
{
	// Binary search 
	// Bat buoc phai sap xep truoc khi tim kiem
	if (n == 0)
	{
		printf("Danh sach rong\n");
		return;
	}
	int left, mid, right, masach;
	left = 0;
	right = n - 1;
	printf("Nhap ma sach ban can tim: ");
	scanf_s("%d", &masach);
	// 1 la danh sach hien dang tang
	if (chon == 1)
	{
		while (left <= right)
		{
			mid = left + (right - left) / 2;

			if (masach == DS_Sach[mid].MaSach)
			{
				printf("==================================================================================================================\n");
				printf("|%5s| %40s| %30s| %20s| %9s|\n", "Ma", "Ten sach", "Ten tac gia", "Nha XB", "Nam XB");
				printf("==================================================================================================================\n");
				Xuat_1Sach(DS_Sach[mid]);
				printf("------------------------------------------------------------------------------------------------------------------\n");
				return;
			}
			if (masach > DS_Sach[mid].MaSach)
				left = mid + 1;
			else if (masach < DS_Sach[mid].MaSach)
				right = mid - 1;
		}
		printf("%d khong co trong danh sach\n", masach);
	}
	else if (chon == 2)
	{
		while (left <= right)
		{
			mid = left + (right - left) / 2;

			if (masach == DS_Sach[mid].MaSach)
			{
				printf("==================================================================================================================\n");
				printf("|%5s| %40s| %30s| %20s| %9s|\n", "Ma", "Ten sach", "Ten tac gia", "Nha XB", "Nam XB");
				printf("==================================================================================================================\n");
				Xuat_1Sach(DS_Sach[mid]);
				printf("------------------------------------------------------------------------------------------------------------------\n");
				return;
			}
			if (masach < DS_Sach[mid].MaSach)
				left = mid + 1;
			else if (masach > DS_Sach[mid].MaSach)
				right = mid - 1;
		}
		printf("%d khong co trong danh sach\n", masach);
	}
}
void sortTG(Sach DS_Sach[], int n) // ứng dụng cho thống kê
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (_strcmpi(DS_Sach[j].TenTacGia, DS_Sach[j + 1].TenTacGia) < 0)
				swap(DS_Sach[j], DS_Sach[j + 1]);
		}
	}
}
void sortNamXB(Sach DS_Sach[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (DS_Sach[j].NamXB > DS_Sach[j + 1].NamXB)
				swap(DS_Sach[j], DS_Sach[j + 1]);
		}
	}
}
void sortNXB(Sach DS_Sach[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (_strcmpi(DS_Sach[j].NXB, DS_Sach[j + 1].NXB) < 0)
				swap(DS_Sach[j], DS_Sach[j + 1]);
		}
	}
}
void SaoChepMang(Sach a[], Sach* b, int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}
void ThongKeSoLuong(ThongKe TK[], Sach DS_Sach[], int n, int& nNamXB, int& nTG, int& nNXB)
{
	if (n == 0)
	{
		printf("Danh sach rong\n");
		return;
	}
	int chon;
	Sach* temp = new Sach[n];
	SaoChepMang(DS_Sach, temp, n);
	printf("Thong ke so luong theo (1. Tac gia, 2. Nha xuat ban, 3. Nam xuat ban): ");
	scanf_s("%d", &chon);
	if (chon == 1)
	{
		if (nTG == 0) // trường hợp nếu đã thống kê rồi thì không thống kê nữa
		{
			sortTG(temp, n);
			for (int i = 1; i < n; i++)
			{
				strcpy_s(TK[nTG].TG.TenTacGia, temp[i - 1].TenTacGia); // sao chép tên tác giả vào phần tử mảng thống kê
				if (_strcmpi(temp[i].TenTacGia, temp[i - 1].TenTacGia) == 0)
				{
					TK[nTG].TG.SoLuong++;
				}
				if (_strcmpi(TK[nTG].TG.TenTacGia, temp[i].TenTacGia) != 0) // nếu phần tử hiện tại của DS_Sach khác với phần tử của mảng thống kê thì tăng phần tử mảng thống kê lên 1 
					nTG++;
			}
		}
		printf("=======================================\n");
		printf("|%5s|%20s|%10s|\n", "STT", "Tac Gia", "So luong");
		printf("=======================================\n");
		for (int i = 0; i < nTG; i++)
		{
			printf("|%5d|%20s|%10d|\n", i + 1, TK[i].TG.TenTacGia, TK[i].TG.SoLuong);
		}
		printf("=======================================\n");
	}
	else if (chon == 2)
	{
		if (nNXB == 0)
		{
			sortNXB(temp, n);
			for (int i = 1; i < n; i++)
			{
				strcpy_s(TK[nNXB].NXB.NXB, temp[i - 1].NXB);
				if (_strcmpi(temp[i].NXB, temp[i - 1].NXB) == 0)
				{
					TK[nNXB].NXB.SoLuong++;
				}
				if (_strcmpi(TK[nNXB].NXB.NXB, temp[i].NXB) != 0)
					nNXB++;
			}
		}
		printf("=================================================\n");
		printf("|%5s|%30s|%10s|\n", "STT", "Nha Xuat Ban", "So luong");
		printf("=================================================\n");
		for (int i = 0; i < nNXB; i++)
		{
			printf("|%5d|%30s|%10d|\n", i + 1, TK[i].NXB.NXB, TK[i].NXB.SoLuong);
		}
		printf("=================================================\n");

	}
	else if (chon == 3)
	{
		if (nNamXB == 0)
		{
			sortNamXB(temp, n);
			for (int i = 1; i < n; i++)
			{
				TK[nNamXB].NamXB.NamXB = temp[i - 1].NamXB;
				if (temp[i].NamXB == temp[i - 1].NamXB)
				{
					TK[nNamXB].NamXB.SoLuong++;
				}
				if (TK[nNamXB].NamXB.NamXB != temp[i].NamXB)
					nNamXB++;
			}
		}
		printf("=============================\n");
		printf("|%5s|%10s|%10s|\n", "STT", "Nam", "So luong");
		printf("=============================\n");

		for (int i = 0; i < nNamXB; i++)
		{
			printf("|%5d|%10d|%10d|\n", i + 1, TK[i].NamXB.NamXB, TK[i].NamXB.SoLuong);
		}
		printf("=============================\n");
	}
	delete[]temp;
}
int TacGia_Max_Sach(ThongKe TK[], int nTG)
{
	int vitriMax = 0;
	for (int i = 1; i < nTG; i++)
	{
		if (TK[i].TG.SoLuong > TK[vitriMax].TG.SoLuong)
			vitriMax = i;
	}
	return vitriMax;
}
int NhaXuatBan_Max_Sach(ThongKe TK[], int nNXB)
{
	int vitriMax = 0;
	for (int i = 1; i < nNXB; i++)
	{
		if (TK[i].NXB.SoLuong > TK[vitriMax].NXB.SoLuong)
			vitriMax = i;
	}
	return vitriMax;
}
int NamXB_Max_Sach(ThongKe TK[], int nNamXB)
{
	int vitriMax = 0;
	for (int i = 1; i < nNamXB; i++)
	{
		if (TK[i].NamXB.SoLuong > TK[vitriMax].NamXB.SoLuong)
			vitriMax = i;
	}
	return vitriMax;
}
#pragma region SetUpConsole
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}
void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
#pragma endregion

