#ifndef SP_H
#define SP_H
#include<bits/stdc++.h>
using namespace std;
class sanpham
{
    string loai,ten,donvi;
    float gia;
    int soluong;
public:
	friend class QLSP;
	sanpham *next = NULL;
    sanpham(string loai ="",string ten ="",string donvi="",int soluong=0,float gia=0);
    sanpham(const sanpham &a);
    ~sanpham(){};
    void nhap();
    void infor();
    //lay gia tri
    string getloai();
    int getsl();
    float getgia();
    string getname();
    //tim 
    bool timten(string s);
    bool timloai(string s);
    //thay doi
    void doiloai(string loai);
    void doigia(float gia);
    void doiten(string ten);
    void doisoluong(int soluong);
    void giamsoluong(int i);
};
sanpham::sanpham(string loai,string ten,string donvi,int soluong,float gia): loai(loai),ten(ten),donvi(donvi),soluong(soluong),gia(gia)
{}
sanpham::sanpham(const sanpham &a):loai(a.loai),ten(a.ten),donvi(a.donvi),soluong(a.soluong),gia(a.gia)
{}
void sanpham::nhap()
{
	cout << endl;
	cout << setfill(' ');
	cout << setw(65) << "";
	cout << setfill(' ');
	cout << "Nhap thong tin san pham: " << endl;
	fflush(stdin);
	cout << setw(65) << "" << "Loai san pham: " ; getline(cin,loai);
	fflush(stdin);
	cout << setw(65) << "" << "Ten san pham: " ; getline(cin,ten);
	fflush(stdin);
	cout << setw(65) << "" << "Don vi: " ; getline(cin,donvi);
	fflush(stdin);
	cout << setw(65) << "" << "Gia: " ; cin >> gia;
	cout << setw(65) << "" << "So luong: " ; cin >> soluong;
}
void sanpham::infor()
{
	cout << setfill(' ');
	cout << "| " << setw(10) << loai << "| " << setw(20) << ten << "| " << setw(8) << donvi << "| " << setw(8) << gia << "| " << setw(9) << soluong << "|";
}
string sanpham::getloai()
{
	return loai;
}
int sanpham::getsl()
{
	return soluong;
}
float sanpham::getgia()
{
	return gia;
}
bool sanpham::timten(string s)
{
	int ans = (int)ten.find(s);
	if(ans!=-1) return true;
	return false;
}
bool sanpham::timloai(string s)
{
	int ans = (int)loai.find(s);
	if(ans!=-1) return true;
	return false;
}
void sanpham::doiloai(string loai)
{
	this->loai = loai;
}
void sanpham::doiten(string ten)
{
	this->ten = ten;
}
void sanpham::doisoluong(int soluong)
{
	this->soluong = soluong;
}
void sanpham::doigia(float gia)
{
	this->gia = gia;
}
string sanpham::getname()
{
	return ten;
}
void sanpham::giamsoluong(int i)
{
	soluong -= i;
}
#endif
