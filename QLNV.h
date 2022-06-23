#ifndef QLNV_H
#define QLNV_H
#include<string>
#include<iomanip>
// #include"QLNV.h"
#include "nhanvien.h"
#include<iostream>
using namespace std;
class QLNV
{
    int n;
    nhanvien *head;
public:
    QLNV();
    ~QLNV();
    void them(nhanvien &p);
    void show();
    void xoa(int i);
    int getn();
    nhanvien *gethead();
    void nhaptufile(fstream &input);
    void xuatfile(fstream &output);
};
QLNV::QLNV()
{
    head = NULL;
    n = 0;
}
QLNV::~QLNV()
{
    if(head) delete[] head;
}
void QLNV::them(nhanvien &p)
{
    nhanvien *node =new nhanvien(p);
    if(head == NULL)
    {
        head = node;
        n = 1;
    }
    else
    {
        nhanvien *i = head;
        if(node->getcv() <= head->getcv()) 
        {
            node->next = head;
           	head = node;
        } 
        else
        {
            while(i->next != NULL)
            {
                if(i->getcv() < node->getcv() && i->next->getcv() >= node->getcv())
                {
                    node->next = i->next;
                    i->next = node; 
                    n+=1;
                    return ;
                }
                i = i->next;
            }
            i->next = node;
            node->next = NULL;
        }
        n+=1;
    }
}
void QLNV::show()
{
    if(n==0)
	{
		cout << setfill(' ');
		cout << setw(68) << "" << "Danh sach trong!" << endl;
		return;
	}
    nhanvien *i = head;
    cout << endl;
    cout << setfill(' ');
    cout << setw(42) << "";
    cout << setfill('-');
    cout << setw(6) << left << "+" << setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
    cout << setfill(' ');
    cout << setw(42) << "";
	cout <<  "| STT " << "| " << setw(20) << left << "Ho va ten" << "| "<< setw(5) << "tuoi" << "| "<< setw(10) << "dia chi" << "| "<<  setw(13) << "SDT" << "| "<< setw(10) << "gioi tinh" << "| "<< setw(10) << "chuc vu" << "| " << setw(5) << "hsl" << "|" <<endl;
    cout << setw(42) << "";
    cout << setfill('-');
    cout << setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
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
    cout <<setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
}
int QLNV::getn()
{
	return n;
}
void QLNV::xoa(int i)
{
	if(i==1)
	{
		head = head->next;
		n--;
		return;
	}
	int dem = 1;
	nhanvien *tam = head;
	while(dem<i-1)
	{
		tam = tam->next;
		dem++;
	}
	tam->next = tam->next->next;
	n--;
}
nhanvien* QLNV::gethead()
{
	return head;
}
void QLNV::nhaptufile(fstream &input)
{
	while(!input.eof())
	{
		string ten,sdt,diachi,chucvu;
		int tuoi;
		bool gioitinh;
		float hsl;
		getline(input,ten,';');
		if(ten=="") return;
		getline(input,sdt,';');
		getline(input,diachi,';');
		input >> tuoi;
		input.ignore(1,';');
		input >> gioitinh;
		input.ignore(1,';');
		getline(input,chucvu,';');
		input >> hsl;
		input.ignore(1,'\n');
		nhanvien p;
		p.ten = ten;
		p.diachi = diachi;
		p.sdt = sdt;
		p.tuoi = tuoi;
		p.gioitinh = gioitinh;
		p.chucvu = chucvu;
		p.hesoluong = hsl;
		this->them(p);
	}
}
void QLNV::xuatfile(fstream &output)
{
	while(head)
	{
		output << head->ten << ";" << head->sdt << ";" << head->diachi << ";" << head->tuoi << ";" << head->gioitinh << ";" << head->chucvu << ";" << head->hesoluong << "\n";
		head = head->next;
	}
}
#endif
