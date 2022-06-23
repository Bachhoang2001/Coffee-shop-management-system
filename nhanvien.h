#ifndef NHANVIEN_H
#define NHANVIEN_H
#include<string>
#include<iomanip>
#include<iostream>
#include "nguoi.h"
using namespace std;
class nhanvien : public nguoi
{
    string chucvu,manv;
    float hesoluong;
public:
	friend class QLNV;
    nhanvien* next = NULL;
    nhanvien(string ten = "", string sdt="", string diachi = "",int tuoi = 0, bool gioitinh = true,string chucvu ="",float hesoluong = 0);
    nhanvien(const nhanvien &p);
	~nhanvien(){};
    void nhap();
    virtual void infor() const;
    ///lay gia tri
    string getname();
    string getcv();
    float gethsl();
    int gettuoi();
    /// tim
    bool timten(string);
    bool timsdt(string);
    bool timdiachi(string);
    bool timchucvu(string);
    /// thay doi 
    void doituoi(int tuoi);
    void doidiachi(string diachi);
    void doihesoluong(float hsl);
    void doisdt(string sdt);
    void doichucvu(string chucvu);
};
nhanvien::nhanvien(string ten, string sdt,string diachi, int tuoi, bool gioitinh, string chucvu, float hesoluong)
: nguoi(ten,sdt,diachi,tuoi,gioitinh),chucvu(chucvu),hesoluong(hesoluong)
{}
nhanvien::nhanvien(const nhanvien& p)
:nguoi(p.ten,p.sdt,p.diachi,p.tuoi,p.gioitinh), chucvu(p.chucvu), hesoluong(p.hesoluong)	
{}
void nhanvien::nhap()
{
	cout << setfill(' ');
	cout << endl;
	cout << setw(65) << "";
	cout << "Nhap thong tin nhan vien: " << endl;
	fflush(stdin);
	cout << setw(65) << "" <<"Ten nhan vien: " ;  getline(cin,ten);
	cout << setw(65) << "" <<"So dien thoai: " ; cin >> sdt;
	fflush(stdin);
	cout << setw(65) << "" <<"Dia chi: " ; getline(cin,diachi);
	fflush(stdin);
	cout << setw(65) << "" <<"Tuoi: " ; cin >> tuoi;
	cout << setw(65) << "" << "Gioi tinh(nam: 1 | nu: 0): " ; cin >> gioitinh;
	fflush(stdin);
	cout << setw(65) << "" <<"Chuc vu: " ; getline(cin,chucvu);
	fflush(stdin);
	cout << setw(65) << "" <<"He so luong: " ; cin >> hesoluong;
}
void nhanvien::infor() const
{
    nguoi::infor();
    cout << setw(10) << chucvu<< "| " << setw(5) << hesoluong << "|";
}
string nhanvien::getname()
{
    return this->ten;
}
string nhanvien::getcv()
{
	return this->chucvu;
}
float nhanvien::gethsl()
{
	return hesoluong;
}
int nhanvien::gettuoi()
{
	return tuoi;
}
bool nhanvien::timten(string s)
{
	int ans = (int)ten.find(s);
	if(ans!=-1) return true;
	return false;
}
bool nhanvien::timsdt(string s)
{
	int ans = (int)sdt.find(s);
	if(ans!=-1) return true;
	return false;
}
bool nhanvien::timdiachi(string s)
{
	int ans = (int)diachi.find(s);
	if(ans!=-1) return true;
	return false;
}
bool nhanvien::timchucvu(string s)
{
	int ans = (int)chucvu.find(s);
	if(ans!=-1) return true;
	return false;
}
void nhanvien::doituoi(int tuoi)
{
	this->tuoi = tuoi;
}
void nhanvien::doidiachi(string diachi)
{
	this->diachi = diachi;
}
void nhanvien::doihesoluong(float hsl)
{
	this->hesoluong = hsl;
}
void nhanvien::doisdt(string sdt)
{
	this->sdt = sdt;
}
void nhanvien::doichucvu(string chucvu)
{
	this->chucvu = chucvu;
}

#endif
