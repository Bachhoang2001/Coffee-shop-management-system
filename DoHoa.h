#ifndef dohoa
#define dohoa
#include <iostream>
#include <conio.h>
#include<string>
#include <Windows.h>
#define KEY_NONE	-1
using namespace std;

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
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
int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoXY(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */ 

// Hàm tự viết
void ToMau(int x, int y, string a, int color) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
{
	gotoXY(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}
void Box(int x,int y,int w,int h,int t_color,int b_color)
{
	textcolor(b_color);
	for(int ix = x+1 ;ix<x+w;ix++)
	{
		for(int iy=y+1;iy<y+h;iy++)
		{
			gotoXY(ix,iy);
			cout << " ";
		}
	}
	textcolor(1);
	SetColor(t_color);
	for(int i=x;i<=x+w;i++)
	{
		gotoXY(i,y);
		cout << char(196);
		gotoXY(i,y+h);
		cout << char(196);
	}
	for(int i=y;i<=y+h;i++)
	{
		gotoXY(x,i);
		cout << char(179);
		gotoXY(x+w,i);
		cout << char(179);
	}
	gotoXY(x,y);     cout << char(218);
	gotoXY(x+w,y);   cout << char(191);
	gotoXY(x,y+h);   cout << char(192);
	gotoXY(x+w,y+h); cout << char(217); 
}
#endif
