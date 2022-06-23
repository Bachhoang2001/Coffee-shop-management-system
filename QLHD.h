#ifndef qlhd
#define qlhd
#include<bits/stdc++.h>
#include"Hoadon.h"
using namespace std;
class QLHD
{
	Hoadon *head;
	int n;
public:
	QLHD();
	~QLHD();
	void them(Hoadon &);
	void show();
	void xoa(int i);
	int getn();
	Hoadon* gethead();
	void xoahet();
    void nhaptufile(fstream &);
    void xuatfile(fstream &);
};
QLHD::QLHD()
{
	n = 0;
	head = NULL;
}
QLHD::~QLHD()
{
	if(head) delete[] head;
}
void QLHD::them(Hoadon &a)
{
	Hoadon *node = new Hoadon(a);
	node->next = head;
	head = node;
	n++;
}
void QLHD::show()
{
	int le = 40;
	if(n==0) 
	{
		cout << setfill(' ');
		cout << setw(68) << "" << "Danh sach trong!" << endl;
		return;
	}
	Hoadon *i = head;
	cout << endl;
	cout << setfill(' ') << setw(le) << "";
	cout << setfill(char(196));
	cout << char(218) << setw(5) << "" << char(194) << setw(12) << ""  << char(194) << setw(10) << "" << char(194) << setw(20) << "" << char(194) << setw(12) << "" << char(191) << endl;
	cout << setfill(' ') << setw(le) << "";
	cout << char(179) << setfill(' ') << setw(5) << " STT " << char(179) << setw(12) << "Ngay"  << char(179) << setw(10) << "Gio" << char(179) << setw(20) << "Ten khach hang" << char(179) << setw(12) << "Tong tien" << char(179) << endl;
	cout << setfill(' ') << setw(le) << "";
	cout << setfill(char(196));
	cout << char(195) << setw(5) << "" << char(197) << setw(12) << ""  << char(197) << setw(10) << "" << char(197) << setw(20) << "" << char(197) << setw(12) << "" << char(180) << endl;
	cout << setfill(' ');
	int dem=1;
	while(i)
	{
		cout << setfill(' ');
		cout << setw(le) << "" << char(179) << setw(5) << dem++;
		i->show();
		cout << char(179);
		cout << endl;
		i = i->next;
	}
	cout << setfill(' ');
	cout << setw(le) << "";
	cout << setfill(char(196));
	cout << char(192) << setw(5) << "" << char(193) << setw(12) << ""  << char(193) << setw(10) << "" << char(193) << setw(20) << "" << char(193) << setw(12) << "" << char(217) << endl;
}
void QLHD::xoa(int i)
{
	if(i==1)
	{
		head = head->next;
		n--;
		return;
	}
	int dem = 1;
	Hoadon *tam = head;
	while(dem<i-1)
	{
		tam = tam->next;
		dem++;
	}
	tam->next = tam->next->next;
	n--;
}
Hoadon* QLHD::gethead()
{
	return head;
}
int QLHD::getn()
{
	return this->n;
}
void QLHD::xoahet()
{
	head->next = NULL;
	head = NULL;
	n=0;
}
void QLHD::nhaptufile(fstream &a)
{
	while(!a.eof())
	{
		Hoadon p(0);
		a >> p.time.d ;
		a.ignore(1,'/');
		a >> p.time.m ;
		a.ignore(1,'/');
		a >> p.time.y ;
		a.ignore(1,';');
		a >> p.time.h ;
		a.ignore(1,':');
		a >> p.time.mi ;
		a.ignore(1,':');
		a >> p.time.s;
		a.ignore(1,';');
		a >> p.maban;
		a.ignore(1,';');
		a >> p.somon;
		a.ignore(1,';');
		getline(a,p.tenkhach,';');
		if(p.tenkhach=="") return;
		for(int i=0;i<p.somon-1;i++)
		{
			string ten;
			int sl;
			int gia;
			getline(a,ten,';');
			p.danhsach[i].mon.doiten(ten);
			a >> sl;
			a.ignore(1,';');
			a >> gia;
			p.danhsach[i].soluong = sl;
			p.danhsach[i].mon.doigia(gia);
			p.danhsach[i].tong = sl*gia;
			p.tongtien+=p.danhsach[i].tong;
		}
		string ten;
		int sl;
		int gia;
		if(p.somon>1) a.ignore(1,';');
		getline(a,ten,';');
		p.danhsach[p.somon-1].mon.doiten(ten);
		a >> sl;
		a.ignore(1,';');
		a >> gia;
		p.danhsach[p.somon-1].soluong = sl;
		p.danhsach[p.somon-1].mon.doigia(gia);
		p.danhsach[p.somon-1].tong = sl*gia;
		p.tongtien+=p.danhsach[p.somon-1].tong;
		a.ignore(1,'\n');
		this->them(p);
	}
}
void QLHD::xuatfile(fstream &a)
{
	while(head)
	{
		a << head->time.d << "/" << head->time.m << "/" << head->time.y << ";" << head->time.h << ":" << head->time.mi << ":" << head->time.s << ";" << head->maban << ";" << head->somon << ";" <<head->tenkhach << ";";
		for(int i = 0;i<head->somon-1;i++)
		{
			a << head->danhsach[i].mon.getname() << ";" << head->danhsach[i].soluong << ";" << head->danhsach[i].mon.getgia() << ";";
		}
		a << head->danhsach[head->somon-1].mon.getname() << ";" << head->danhsach[head->somon-1].soluong << ";" << head->danhsach[head->somon-1].mon.getgia();
		a << endl;
		head = head->next;
	}
}
#endif
