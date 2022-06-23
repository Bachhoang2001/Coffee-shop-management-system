#ifndef Hoadon_h
#define Hoadon_h
#include<bits/stdc++.h>
#include "Ban.h"
#include "sanpham.h"
using namespace std;
struct thoigian
{
	int d,m,y;
	int h,mi,s;	
};
class Hoadon
{
	thoigian time;
	long long tongtien;
	int maban; 
    goimon danhsach[20];
    int somon;
    string tenkhach;
public:
	friend class QLHD;
	friend class ban;
	Hoadon *next = NULL;
	Hoadon(int maban);
	Hoadon(const Hoadon &);
	void infor();
	void show();
};
Hoadon::Hoadon(int maban): maban(maban)
{
	tenkhach = "Chua duoc luu";
	tongtien = 0;
	next = NULL;
}
Hoadon::Hoadon(const Hoadon &a) : time(a.time),tongtien(a.tongtien),somon(a.somon),maban(a.maban),tenkhach(a.tenkhach)
{
	for(int i=0;i<somon;i++)
	{
		danhsach[i].mon = a.danhsach[i].mon;
		danhsach[i].soluong = a.danhsach[i].soluong;
		danhsach[i].tong = a.danhsach[i].tong;
	}
}
void Hoadon::show()
{
	cout << char(179) << " " << setw(2) << time.d << "/" << setw(2) << time.m << "/" << setw(4) << time.y << " ";
	cout << char(179) << " " << setw(2) << time.h << ":" << setw(2) << time.mi << ":" << setw(2) << time.s << " ";
	cout << char(179) << setw(20) << tenkhach ;
	cout << char(179) <<right << setw(12) << tongtien ;
}
void Hoadon::infor()
{
	cout << endl;
	cout << setw(55) << char(218) << setfill(char(196)) << setw(70) << char(191) << endl;
	cout << setfill(' ');
	cout << setw(55) << char(179) << setw(38) << "HOA DON" << setw(32) << char(179) << endl;
	cout << setw(55) << char(179) << setw(70) << char(179) << endl;
	cout << setw(55) << char(179) << setw(5) << "" << setw(2) << time.d << "/" << setw(2) << time.m << "/" << time.y << setw(3) << "" << setw(2) << time.h << ":" << setw(2) << time.mi << ":" << setw(2) << time.s << setw(6) << "Ten:" << left << setw(20) << tenkhach << right << setw(6) << "ban : " << setw(2) << maban << setw(10) << char(179) << endl;
	cout << right ;
	cout << setw(55) << char(179) << setw(70) << char(179) << endl;
	cout << setw(55) << char(179) << "   " << left << setw(4) << "STT" << "  " << setw(22) << "Ten mon an" << "  " << setw(10) << "Don gia" << "  " << setw(10) << "So luong" << "      " <<setw(8) << "Tong"<< char(179) << endl;
	for(int i=0;i<somon;i++)
	{
		cout << setfill(' ');
		cout << setw(55) <<	right << char(179) << left << "   " << setw(4) << i+1 << "  " << setw(22) << danhsach[i].mon.getname() << "  " << setw(10) << danhsach[i].mon.getgia() << "  " << setw(10) << danhsach[i].soluong << "  " << setw(12)  <<danhsach[i].tong << char(179) << endl; 
	}
	cout << setw(54) << "" << char(179) <<"   " << setfill(char(196)) << setw(63) << "" << "   " << char(179) << endl;
	cout << setfill(' ') << setw(54) << "" << char(179) << "    " << "Tong tien:" << setw(43) <<"" <<setw(12) <<tongtien << char(179) << endl;
	cout << setw(55) << right << char(192) << setfill(char(196)) << setw(70) << char(217);
}
#endif
