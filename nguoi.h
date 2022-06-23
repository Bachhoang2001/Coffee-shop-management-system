#ifndef NGUOI_H
#define NGUOI_H
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class nguoi
{
protected: 
	string ten,sdt,diachi;
	int tuoi;
	bool gioitinh;
public:
	nguoi();
	nguoi(string ten = "", string sdt="",string diachi="", int tuoi = 0, bool gioitinh = true);
	nguoi(const nguoi &n);
	virtual ~nguoi(){}; 
	virtual void infor() const;
}; 
nguoi::nguoi()
{
	ten = "";
	sdt = "";
	diachi = "";
	tuoi = 0;
	gioitinh = true;
}
nguoi::nguoi(string ten,string sdt,string diachi,int tuoi,bool gioitinh):ten(ten), sdt(sdt),diachi(diachi),tuoi(tuoi), gioitinh(gioitinh)
	{}
nguoi::nguoi(const nguoi &n)
:ten(n.ten), sdt(n.sdt),diachi(n.diachi),tuoi(n.tuoi), gioitinh(n.gioitinh)
{}
void nguoi::infor() const
{
	cout << "| " << setw(20) << left << ten << "| "<< setw(5) << tuoi << "| "<< setw(10) << diachi << "| "<<  setw(13) << sdt << "| "<< setw(10) << (gioitinh?"Nam":"Nu") << "| " ;
}
#endif
