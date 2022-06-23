#ifndef QLKH_H
#define QLKH_H
#include "khach.h"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class QLKH
{
    int n;
    khach *head;
public:
    QLKH();
    ~QLKH();
    void them(khach &);
    void show();
    void xoa(int i); 
    int getn();
    khach* gethead();
    void nhaptufile(fstream &);
    void xuatfile(fstream &);
};
QLKH::QLKH()
{
    n = 0;
    head = NULL;
}
QLKH::~QLKH()
{
    if(head) delete[] head;
}
void QLKH::them(khach &p)
{
    khach *node = new khach(p);
    if(head == NULL)
    {
        head = node;
        n=1;
    }
    else
    {
        khach *i = head;
        if(node->getname() < head->getname()) 
        {
            node->next = head;
            head = node;
            n++;
            return;
        } 
        else
        {
            while(i->next != NULL)
            {
                if(i->getname() < node->getname() && i->next->getname() > node->getname())
                {
                    node->next = i->next;
                    i->next = node; 
                    return ;
                }
                i = i->next;
            }
            i->next = node;
            node->next = NULL;
            n+=1;
        }
    }
}
void QLKH::show()
{
	if(n==0)
	{
		cout << setfill(' ');
		cout << setw(68) << "" << "Danh sach trong!" << endl;
		return;
	}
    khach *i = head;
    cout << endl;
    cout << setfill(' ');
    cout << setw(42) << "";
    cout << setfill('-');
    cout << setw(6) << left << "+" << setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
    cout << setfill(' ');
    cout << setw(42) << "";
	cout <<  "| STT " << "| " << setw(20) << left << "Ho va ten" << "| "<< setw(5) << "tuoi" << "| "<< setw(10) << "dia chi" << "| "<<  setw(13) << "SDT" << "| "<< setw(10) << "gioi tinh" << "| "<< setw(5) << "dtl" << "|" <<endl;
    cout << setw(42) << "";
    cout << setfill('-');
    cout << setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
	int dem = 1;
	while(i)
    {
    	cout << setfill(' ');
    	cout << setw(42) << "" << "| " <<setw(4) << left << dem++ ;
        i->infor();
        cout << endl;
        i = i->next;
    }
    cout << setw(42) << ""; 
    cout << setfill('-');
    cout <<setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
}
void QLKH::xoa(int i)
{
	if(i==1)
	{
		head = head->next;
		n--;
		return;
	}
	int dem = 1;
	khach *tam = head;
	while(dem<i-1)
	{
		tam = tam->next;
		dem++;
	}
	tam->next = tam->next->next;
	n--;
}
int QLKH::getn()
{
	return n;
}
khach* QLKH::gethead()
{
	return head;
}
void QLKH::nhaptufile(fstream &input)
{
	while(!input.eof())
	{
		string ten,sdt,diachi;
		int tuoi;
		bool gioitinh;
		float dtl;
		getline(input,ten,';');
		if(ten=="") return;
		getline(input,sdt,';');
		getline(input,diachi,';');
		input >> tuoi;
		input.ignore(1,';');
		input >> gioitinh;
		input.ignore(1,';');
		input >> dtl;
		input.ignore(1,'\n');
		khach p;
		p.ten = ten;
		p.diachi = diachi;
		p.sdt = sdt;
		p.tuoi = tuoi;
		p.gioitinh = gioitinh;
		p.diemtichluy = dtl;
		this->them(p);
	}
}
void QLKH::xuatfile(fstream &output)
{
	while(head)
	{
		output << head->ten << ";" << head->sdt << ";" << head->diachi << ";" << head->tuoi << ";" << head->gioitinh << ";" << head->diemtichluy << "\n";
		head = head->next;
	}
}
#endif
