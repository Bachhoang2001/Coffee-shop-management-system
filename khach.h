#ifndef KHACHHANG_H
#define KHACHHANG_H
#include<iostream>
#include<string>
#include<iomanip>
#include "nguoi.h"
using namespace std;
class khach : public nguoi
{
    int diemtichluy;
public:
	friend class QLKH;
    khach *next = NULL;
    khach(string ten = "", string sdt="",string diachi="", int tuoi = 0, bool gioitinh = true,int diemtichluy = 0);
    khach(const khach &n);
    ~khach(){};
    void nhap();
    ///tim
    void infor() const;
    bool timten(string);
    bool timsdt(string);
    bool timdiachi(string);
    ///lay gia tri
    string getname();
    int getdtl();
    int gettuoi();
    string getsdt();
    /// thay doi
    void thaydoidiemtichluy();
    void doituoi(int tuoi);
    void doidiachi(string diachi);
    void doisdt(string sdt);
    void congdtl(int i); 
};
khach::khach(string ten, string sdt, string diachi, int tuoi, bool gioitinh, int diemtichuy)
    : nguoi(ten,sdt,diachi,tuoi,gioitinh), diemtichluy(diemtichluy)
    {}
khach::khach(const khach &n)
    : nguoi(n.ten,n.sdt,n.diachi,n.tuoi,n.gioitinh) , diemtichluy(n.diemtichluy)
    {}
void khach::nhap()
{
	cout << setfill(' ');
	cout << endl;
    cout << setw(65) << "" << "Nhap thong tin khach hang: " << endl;
    fflush(stdin);
	cout << setw(65) << "" << "Ten khach hang: " ;  getline(cin,ten);
	fflush(stdin);
	cout << setw(65) << "" << "So dien thoai: " ; cin >> sdt;
	fflush(stdin);
	cout << setw(65) << "" << "Dia chi: " ; getline(cin,diachi);
	fflush(stdin);
	cout << setw(65) << "" << "Tuoi: " ; cin >> tuoi;
	fflush(stdin);
	cout << setw(65) << "" << "Gioi tinh (nam: 1 | nu: 0): " ; cin >> gioitinh;
	fflush(stdin);
	cout << setw(65) << "" <<"Diem tich luy: "; cin >> diemtichluy;
}
void khach::infor() const
{
    nguoi::infor();
    cout << setw(5) << diemtichluy << "|" ;
}
void khach::thaydoidiemtichluy()
{
    int chon,diem;
    cout << setfill(' ');
    cout << endl << setw(68) << "" << "DIEM HIEN CO: " << diemtichluy << endl;
    cout << endl << setw(68) << "" <<"[1] Cong diem tich luy" ;
    cout << endl << setw(68) << "" <<"[2] Tru diem tich luy" ;
    cout << endl << setw(68) << "" <<"[3] Xoa het diem tich luy" ;
    cout << endl << setw(68) << "" <<"Nhap lua chon : " ; cin >> chon;
    switch(chon)
    {
        case 1:
        {
            cout << endl << setw(68) << "" <<"Nhap so diem muon cong vao : " ; cin >> diem ;
            cout << endl << setw(68) << "" <<"Da cong " << diem << " diem vao khach hang "<< ten << "!";
            diemtichluy+=diem;
            cout << endl << setw(68) << "" <<"So diem hien tai: " << diemtichluy << endl;
            break;
        }
        case 2:
        {
            cout << endl << setw(68) << "" <<"Nhap so diem muon tru di : " ; cin >> diem ;
            cout << endl << setw(68) << "" <<"Da tru " << diem << " diem cua khach hang "<< ten << "!";
            diemtichluy-=diem;
            if(diemtichluy < 0) diemtichluy = 0;
            cout << endl << setw(68) << "" <<"So diem hien tai: " << diemtichluy << endl;
            break;
        }
        case 3:
        {
            cout << endl << setw(68) << "" <<"Da tru het diem tich luy!" << endl;
            diemtichluy = 0;
            break;
        }
    }
}
void khach::doituoi(int tuoi)
{
	this->tuoi = tuoi;
}
void khach::doidiachi(string diachi)
{
	this->diachi = diachi;
}
void khach::doisdt(string sdt)
{
	this->sdt = sdt;
}
string khach::getname()
{
	return this->ten;
}
bool khach::timten(string s)
{
	int ans = (int)ten.find(s);
	if(ans!=-1) return true;
	return false;
}
bool khach::timsdt(string s)
{
	int ans = (int)sdt.find(s);
	if(ans!=-1) return true;
	return false;
}
bool khach::timdiachi(string s)
{
	int ans = (int)diachi.find(s);
	if(ans!=-1) return true;
	return false;
}
int khach::getdtl()
{
	return diemtichluy;
}
int khach::gettuoi()
{
	return tuoi;
}
string khach::getsdt()
{
	return this->sdt;
}
void khach::congdtl(int i)
{
	diemtichluy+=i;
}
#endif
