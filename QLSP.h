#ifndef QLSP_H
#define QLSP_H
#include<bits/stdc++.h>
#include"sanpham.h"
using namespace std;
class QLSP
{
    int n;
    sanpham *head;
public:
    QLSP();
    ~QLSP();
    void show();
    void them(sanpham &p);
    void xoa(int i);
    void thongke();
    int getn();
    sanpham* gethead();
    void nhaptufile(fstream &input);
    void xuatfile(fstream &);
};
QLSP::QLSP()
{
	n = 0;
	head = NULL;
}
QLSP::~QLSP()
{
	if(head) delete[] head;
}
void QLSP::show()
{
	if(n==0)
	{
		cout << setfill(' ');
		cout << setw(68) << "" << "Danh sach trong!" << endl;
		return;
	}
	sanpham *i = head;
	cout << endl;
	cout << setfill(' ');
	cout << setw(50) << "";
	cout << setfill('-');
	cout << setw(6) << left << "+" << setw(12) << "+"<< setw(22) << "+" << setw(10) << "+" << setw(10) << "+" << setw(11) << "+" << "+" << endl;
	cout << setfill(' ');
	cout << setw(50) << "";
	cout << "| STT " << "| " << setw(10) << "Loai" << setw(22) << "| Ten san pham" << setw(10) << "| Don vi" << setw(10) << "| Gia" << setw(11) << "| so luong" << "|" << endl;
	cout << setw(50) << "";
	cout << setfill('-');
	cout << setw(6) << left << "+" << setw(12) << "+"<< setw(22) << "+" << setw(10) << "+" << setw(10) << "+" << setw(11) << "+" << "+" << endl;	
	int dem = 1;
	while(i)
	{
		cout << setfill(' ');
    	cout << setw(50) << "" << "| " <<setw(4) << left << dem++ ;
        i->infor();
        cout << endl;
        i = i->next;
	}
	cout << setw(50) << "";
	cout << setfill('-');
	cout << setw(6) << left << "+" << setw(12) << "+"<< setw(22) << "+" << setw(10) << "+" << setw(10) << "+" << setw(11) << "+" << "+" << endl;	
}
void QLSP::them(sanpham &p)
{
	sanpham *node =new sanpham(p);
    if(head == NULL)
    {
        head = node;
        n = 1;
    }
    else
    {
        sanpham *i = head;
        if(node->getloai() <= head->getloai()) 
        {
            node->next = head;
           	head = node;
        } 
        else
        {
            while(i->next != NULL)
            {
                if(i->getloai() < node->getloai() && i->next->getloai() >= node->getloai())
                {
                    node->next = i->next;
                    i->next = node; 
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
void QLSP::xoa(int i)
{
	if(i==1)
	{
		head = head->next;
		n--;
		return;
	}
	int dem = 1;
	sanpham *tam = head;
	while(dem<i-1)
	{
		tam = tam->next;
		dem++;
	}
	tam->next = tam->next->next;
	n--;
}
int QLSP::getn()
{
	return n;
}
sanpham* QLSP::gethead()
{
	return head;
}
void QLSP::nhaptufile(fstream &input)
{
	int dem = 1;
	while(!input.eof())
	{
		string loai,ten,donvi;
		int soluong;
		float gia;
		getline(input,loai,';');
		if(loai =="") return;
		getline(input,ten,';');
		getline(input,donvi,';');
		input >> soluong;
		input.ignore(1,';');
		input >> gia;
		input.ignore(1,'\n');
		sanpham p;
		p.ten = ten;
		p.loai = loai;
		p.donvi = donvi;
		p.soluong = soluong;
		p.gia = gia;
		this->them(p);
	}
}
void QLSP::xuatfile(fstream &output)
{
	while(head)
	{
		output << head->loai << ";" << head->ten << ";" << head->donvi << ";" << head->soluong << ";" << head->gia << "\n";
		head = head->next;
	}
}
#endif
