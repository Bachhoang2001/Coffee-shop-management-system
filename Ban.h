#ifndef BAN_H
#define BAN_H
#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include"sanpham.h"
#include "QLSP.h"
using namespace std;
struct goimon
{
    sanpham mon;
    int soluong;
    int tong;
};
#include "Hoadon.h"
#include "QLHD.h"
class ban
{
protected:
	int maban; 
    bool trangthai;
    goimon danhsach[20];
    int somon;
    khach *p = NULL;
public:
    ban(int maban = 0);
    ban(const ban& a);
    ~ban(){};
    void tinhtien(QLHD &);
    void themmon();
    bool gettrangthai();
    void setmaban(int i);
    void doitrangthai();
    void themmon(QLSP &);
    void setkhach(khach *);
    void show();
};
ban::ban(int maban):maban(maban)
{
	trangthai = true;
	somon = 0;
	p = NULL;
}
ban::ban(const ban& a):maban(a.maban),trangthai(a.trangthai),somon(a.somon),p(a.p)
{
}
bool ban::gettrangthai()
{
	return trangthai;
}
void ban::setmaban(int i)
{
	this->maban = i;
}
void ban::doitrangthai()
{
	trangthai = !trangthai;
}
void ban::themmon(QLSP &dssp)
{
	cout << setfill(' ');
	cout << endl << setw(68) << "" << "Chon mon: ";
	char nhapstt[20];
	fflush(stdin);
	cout << endl << setw(68) << " " << "STT: "; cin >> nhapstt;	
	if(atoi(nhapstt)==0 || atoi(nhapstt)>dssp.getn()) 
	{
		cout << endl << setw(68) << "" << "Khong co san pham nay!" << endl;
		return;
	}
	int stt = atoi(nhapstt);
	sanpham *i = dssp.gethead();
	while(stt>1)
	{
		stt--;
		i = i->next;
	}
	int soluong;
	cout << endl << setw(68) << "" << "so luong: "; cin >> soluong;
	i->giamsoluong(soluong);
	danhsach[somon].mon = (*i);
	danhsach[somon].soluong = soluong;
	danhsach[somon].tong = danhsach[somon].mon.getgia() * danhsach[somon].soluong;
	somon++;
}
void ban::tinhtien(QLHD &dshd)
{
	if(trangthai==true)
	{
		cout << setfill(' ') << setw(68) << "" << "Ban nay khong co khach!" << endl;
		return;
	}
	doitrangthai(); 
	long tongtien = 0 ;
	for(int i=0;i<somon;i++)
	{
		tongtien+=danhsach[i].tong;
	}
	if(p) 
	{
		p->congdtl((int)tongtien/50000);
		if(p->getdtl()>=50) 
		{
			cout << setfill(' ') << setw(68) << "" << "Diem tich luy hien tai " << p->getdtl() << endl;
			cout << setfill(' ') << setw(68) << "" << "Dung diem 50 tich luy?(c/k) : ";
			char dungdtl;
			fflush(stdin);
			cin >> dungdtl;
			if(dungdtl == 'c') 
			{
				tongtien-=50000;
				p->congdtl(-50);	
			}	
		}
	}
	Hoadon a(maban);
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	a.time.y = 1900 + ltm->tm_year;
	a.time.m = 1 + ltm->tm_mon;
	a.time.d = ltm->tm_mday;
	a.time.h = 1 + ltm->tm_hour;
	a.time.mi = 1 + ltm->tm_min;
	a.time.s = 1 + ltm->tm_sec;
	a.tongtien = tongtien;
	a.somon = somon;
	if(p) 
	{
		a.tenkhach = p->getname();
	}
	for(int i=0;i<somon;i++)
	{
		a.danhsach[i] = danhsach[i];
	}
	dshd.them(a);
	p = NULL;
	cout << setfill(' ') << right;
	cout << endl;
	cout << setw(55) << char(218) << setfill(char(196)) << setw(70) << char(191) << endl;
	cout << setfill(' ');
	cout << setw(55) << char(179) << setw(38) << "HOA DON" << setw(32) << char(179) << endl;
	cout << setw(55) << char(179) << setw(70) << char(179) << endl;
	cout << setw(55) << char(179) << setw(5) << "" << setw(2) << a.time.d << "/" << setw(2) << a.time.m << "/" << a.time.y << setw(3) << "" << setw(2) << a.time.h << ":" << setw(2) << a.time.mi << ":" << setw(2) << a.time.s << setw(6) << "Ten:" << left << setw(20) << a.tenkhach  << right << setw(6) << "ban: " << setw(2) << maban << setw(10) << char(179) << endl;
	cout << right ;
	cout << setw(55) << char(179) << setw(70) << char(179) << endl;
	cout << setw(55) << char(179) << "   " << left << setw(4) << "STT" << "  " << setw(22) << "Ten mon an" << "  " << setw(10) << "Don gia" << "  " << setw(10) << "So luong" << "      " <<setw(8) << "Tong"<< char(179) << endl;
	for(int i=0;i<somon;i++)
	{
		cout << setfill(' ');
		cout << setw(55) <<	right << char(179) << left << "   " << setw(4) << i+1 << "  " << setw(22) << danhsach[i].mon.getname() << "  " << setw(10) << danhsach[i].mon.getgia() << "  " << setw(10) << danhsach[i].soluong << "  " << setw(12)  << right << danhsach[i].tong << left << char(179) << endl; 
	}
	cout << setw(54) << "" << char(179) <<"   " << setfill(char(196)) << setw(63) << "" << "   " << char(179) << endl;
	cout << setfill(' ') << setw(54) << "" << char(179) << "    " << "Tong tien:" << setw(43) <<"" <<setw(12) <<right<<tongtien <<left<< char(179) << endl;
	cout << setw(55) << right << char(192) << setfill(char(196)) << setw(70) << char(217);
	somon = 0;
}
void ban::setkhach(khach *p)
{
	this->p = p;
}
void ban::show()
{
	if(somon == 0) return;
	cout << endl << setfill(' ') << setw(68) << "" << "Mon da chon:" << endl;
	for(int i=0;i<somon;i++)
	{
		cout << setfill(' ') << setw(68) << "" << danhsach[i].mon.getname()  << "    " << danhsach[i].soluong << endl;
	}
}
#endif
