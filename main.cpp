#include<bits/stdc++.h>
#include<conio.h>
#include "QLKH.h"
#include "khach.h"
#include "nguoi.h"
#include "nhanvien.h"
#include "QLNV.h"
#include "QLSP.h"
#include "Ban.h"
#include "DoHoa.h"
#include "Hoadon.h"
#include "QLHD.h"
using namespace std;
void Start(); // in khung gioi thieu
void ChonQuyen(); // Chon quyen truy cap
void Menu_NV();
void Menu_AD();
void Menu_QLKH();
void Menu_BH();
void Menu_QLSP();
void Menu_QLNV();
void quanlikhachhang();
void banhang();
void quanlisanpham();
void quanlinhanvien();
void vemenu(int le,int trai,int phai,string strai,string sphai); //ve menu
void vethoat(int le); // ve phim thoat
string inputPassword(size_t length_max); //nhap password
void bang(ban a[]);//ve bang quan li ban
void doimatkhau();
string password;
QLKH danh_sach_khach_hang; 
QLNV dsnv;
QLSP dssp;
QLHD dshd;
ban a[30];
int main()
{
	fstream input;
	input.open("khach.txt",ios::in);
	danh_sach_khach_hang.nhaptufile(input);
	input.close();
	input.open("nhanvien.txt",ios::in);
	dsnv.nhaptufile(input);
	input.close();
	input.open("sanpham.txt",ios::in);
	dssp.nhaptufile(input);
	input.close();
	input.open("Hoadon.txt",ios::in);
	dshd.nhaptufile(input);
	input.close();
	for(int i=0;i<30;i++)
	{
		a[i].setmaban(i);
	}
	int chon;
	ifstream pass("pass.txt");
	getline(pass,password);
	ChonQuyen();
	fstream output;
	output.open("nhanvien.txt",ios::trunc | ios::out);
	dsnv.xuatfile(output);
	output.close();
	output.open("khach.txt",ios::trunc | ios::out);
	danh_sach_khach_hang.xuatfile(output);
	output.close();
	output.open("sanpham.txt",ios::trunc | ios::out);
	dssp.xuatfile(output);
	output.close();
	output.open("Hoadon.txt",ios::trunc | ios::out);
	dshd.xuatfile(output);
	output.close();
	output.open("pass.txt",ios::trunc | ios::out);
	output << password;
	system("cls");
	Start();
	cout << setfill(' ');
	cout << endl << endl << setw(68) << "" << "Chuong trinh ket thuc!";
	return 0;
}
void Start()
{
	system("cls");
	cout << "\n\n";
    cout << setfill('_') << right;
    cout << "\t\t\t\t" << setw(72) <<"TRUONG DAI HOC BACH KHOA - DAI HOC DA NANG" << setw(30) << "" ;
    cout << "\n\t\t\t\t*" << setfill(' ') <<setw(65) << "== KHOA CONG NGHE THONG TIN =="  << setw(36) << "*" << endl;
    cout << "\t\t\t\t*" << setw(101) << "*";
    cout << "\n\t\t\t\t*" << setw(64) << "PBL2:  DO AN CO SO LAP TRINH" << setw(37) << "*"  << endl;
    cout << "\t\t\t\t*" <<  setw(68)<< "CHU DE: HE THONG QUAN LI QUAN CAFE" << setw(33) << "*" << endl;
    cout << "\t\t\t\t*" << setw(101) << "*" << endl;
    cout << "\t\t\t\t*" << setw(45) << "GV HUONG DAN:" << setw(50) << left << "    Ths TRAN HO THUY TIEN" << right << setw(6) << "*" <<endl;
    cout << "\t\t\t\t*" <<setw(45) << "SINH VIEN THUC HIEN:" << setw(56) << "*" << endl;
    cout << "\t\t\t\t*" << setw(50) << left << "" << setw(50) << "LE PHUC KHUONG"  << "*" << endl;
    cout << "\t\t\t\t*" << setw(50) << left << "" << setw(50) << "HOANG NGUYEN BACH"  << "*" << endl;
    cout << "\t\t\t\t*" << setw(50) << left << "" << setw(50) << "PHAM HUYNH VAN PHAT" << "*" << endl;
    cout << "\t\t\t\t*" << setfill('_') <<right << setw(101) << "*" << endl;
}
void ChonQuyen()
{
	while(true)
	{
		Start();
		cout << setfill(' ') << setw(68) << left << "" << "==============WELCOME==============" << endl << endl;
		vemenu(51,1,2,"NHAN VIEN","ADMIN");
		cout << endl;
		vethoat(51);
		cout << endl << setw(68) << "" <<  "===================================" << endl;
		cout << setfill(' ') << setw(68) << "" << "Chon quyen truy cap: ";
		char chon_quyen_truy_cap;
		fflush(stdin);
		cin >> chon_quyen_truy_cap;
		switch(chon_quyen_truy_cap)
		{
			case '1': //nhan vien
			{
				Menu_NV();
				break;
			}
			case '2': //Admin
			{
				Menu_AD();
				break;
			}
			case '0':
			{
				return;
			}
			default:
			{
				cout << endl << setfill(' ') << setw(68) << "" << "Khong co lenh nay! Moi nhap lai!";
				getch();
			}
		}
	}
}
void Menu_NV()
{	
	while(true)
	{
		Start();
		cout << setfill(' ') << setw(61) << left << "" << "==============MENU NHAN VIEN==============" << endl << endl;
		vemenu(51,1,2,"QUAN LI KHACH HANG","BAN HANG");
		cout << endl;
		vethoat(51);
		cout << endl << setw(61) << "" <<  "==========================================" << endl;
		cout << setw(68) << "" << "Nhap lenh: ";
		char chon_NV;
		fflush(stdin);
		cin >> chon_NV;
		switch(chon_NV)
		{
			case '1'://quan li khach hang
			{
				quanlikhachhang();
				break;
			}
			case '2'://ban hang
			{
				banhang();
				break;
			}
			case '0':
			{
				return;
			}
			default:
			{
				cout << endl << setfill(' ') << setw(68) << "" << "Khong co lenh nay! Moi nhap lai!";
				getch();
			}
		}
	}
}
void Menu_AD()
{   //nhap mat khau
	system("cls");
	Box(68,16,30,7,14,14);
	ToMau(77,17,"NHAP MAT KHAU",14);
	int solannhap = 3;
	string nhappass;
	do
	{
		ToMau(72,18,"                          ",14);
		textcolor(14);
		gotoXY(72,24);
		cout << "Tab: An/hien ki tu";
		gotoXY(72,25);
		cout << "Esc: Thoat";
		gotoXY(76,19);
		cout << "Con " << solannhap << " lan nhap!";
		gotoXY(72,18);
		textcolor(7);
		string strRet ;
	    char ch = 0;
	    bool bShow = false;
	    int length_max = 30;
	    do
	    {
	        ch = getch();
	        if((strRet.size() < length_max) && (::isalpha(ch) || ::isalnum(ch))) 
	        {
	            std::cout << (bShow ? ch : '*');
	            strRet.push_back(ch);
	        }
	        else
	        {
	            if(9 == ch) 
	            {
	                bShow = !bShow;
	 
	                std::cout << std::string(strRet.size(), '\b');
	           
	                if(bShow)
	                    std::cout << strRet;
	                else
	                    std::cout << std::string(strRet.size(), '*');
	               
	            }
	            if('\b' == ch && !strRet.empty())
	            {
	                std::cout << "\b \b";
	                strRet.resize(strRet.size() - 1);
	            }
	            if(ch == 27)
	            {
	            	return;
				}
	        }
		}
		while ('\r' != ch);
		if(strRet == password)
		{
			break;
		}
		else
		{
			solannhap--;
			ToMau(75,21,"Sai mat khau!",14);
			getch();
			ToMau(75,21,"             ",14);
			if(solannhap==0) return;	
		}
		textcolor(7);
	}
	while(true);
	//thuc thi
	while(true)
	{
		Start();
		cout << setfill(' ') << setw(61) << left << "" << "================MENU ADMIN================" << endl << endl;
		vemenu(51,1,2,"QUAN LI NHAN VIEN","QUAN LI KHACH HANG");
		cout << endl;
		vemenu(51,3,4,"QUAN LI SAN PHAM","BAN HANG");
		cout << endl;
		vemenu(51,5,0,"DOI MAT KHAU","THOAT");
		cout << endl << setw(61) << "" <<  "==========================================" << endl;
		cout << setw(68) << "" << "Nhap lenh: ";
		char chon_AD;
		fflush(stdin);
		cin >> chon_AD;
		switch(chon_AD)
		{
			case '1'://quan li nhan vien
			{
				quanlinhanvien();
				break;
			}
			case '2': // quan li khach hang
			{
				quanlikhachhang();
				break;
			}
			case '3': // quan li san pham
			{
				quanlisanpham();
				break;
			}
			case '4':// ban hang
			{
				banhang();
				break;
			}	
			case '5':
			{
				doimatkhau();
				break;
			}
			case '0': //thoat
			{
				return;
			}
			default:
			{
				cout << endl << setfill(' ') << setw(68) << "" << "Khong co lenh nay! Moi nhap lai!";
				getch();
			}
		}
	}
}
void vemenu(int le,int trai,int phai,string strai,string sphai)
{
	int cach = 10;
	cout << setfill(' ');
    cout << setw(le) << "";
    cout << char(218);
    for(int i=0;i<6;i++) cout << char(196) ;
	cout << char(194);
	for(int i=0;i<19;i++) cout << char(196) ;
	cout << char(191);
	cout <<setw(cach) << "";
	cout << char(218);
	for(int i=0;i<19;i++) cout << char(196) ;
	cout << char(194);
	for(int i=0;i<6;i++) cout << char(196);
	cout << char(191);
	cout << endl;
	
	cout <<	setw(le) << "";
	cout << char(179) << setw(5) << "CHON " << trai << char(179) << setw(19) << left << strai << char(179);
	cout << setw(cach) << "" << char(179) << setw(19) << right << sphai << char(179) << "CHON " << phai << char(179) << endl;
	
	cout << setw(le) << "";
	cout << char(192) ;
	for(int i=0;i<6;i++) cout << char(196) ;
	cout << char(193);
	for(int i=0;i<19;i++) cout << char(196) ;
	cout << char(217);
	cout << setw(cach) << "" << char(192) ;
	for(int i=0;i<19;i++) cout << char(196);
	cout << char(193);
	for(int i=0;i<6;i++) cout << char(196);
	cout << char(217);
	cout << endl ;
}
void vethoat(int le)
{
	cout << setw(le+38) << "" ;
	cout << char(218);
	for(int i=0;i<19;i++) cout << char(196) ;
	cout << char(194);
	for(int i=0;i<6;i++) cout << char(196);
	cout << char(191);
	cout << endl;
	cout << setw(le+38) << "" ;
	cout << char(179) << setw(19) << right << "THOAT" << char(179) << "CHON 0" << char(179) << endl;
	cout << setw(le+38) << "";
	cout << char(192);
	for(int i=0;i<19;i++) cout << char(196);
	cout << char(193);
	for(int i=0;i<6;i++) cout << char(196);
	cout << char(217);
	cout << endl;
}
string inputPassword(size_t length_max)
{
    string strRet;
    char ch = 0;
    bool bShow = false;
    do
    {
        ch = getch();
        if((strRet.size() < length_max) && (::isalpha(ch) || ::isalnum(ch))) 
        {
            std::cout << (bShow ? ch : '*');
            strRet.push_back(ch);
        }
        else
        {
            if(0x1B == ch) 
            {
                bShow = !bShow;
 
                std::cout << std::string(strRet.size(), '\b');
           
                if(bShow)
                    std::cout << strRet;
                else
                    std::cout << std::string(strRet.size(), '*');
               
            }
            if('\b' == ch && !strRet.empty())
            {
                std::cout << "\b \b";
                strRet.resize(strRet.size() - 1);
            }
        }
 
    }while ('\r' != ch);
    cout << endl;
    return strRet;
}
void quanlikhachhang()
{
	while(true)
	{
	b:	Menu_QLKH();
		fflush(stdin);
		char c1;
		cin >> c1;
		switch(c1)
		{
			case '1'://show
			{
				Start();
				danh_sach_khach_hang.show();
				break;
			}
			case '2'://them
			{
				Start();
				khach p;
				p.nhap();
				danh_sach_khach_hang.them(p);
				break;
			}
			case '3'://xoa
			{
				Start();
				int a;
				if(danh_sach_khach_hang.getn()==0)
				{
					cout <<setfill(' ');
					cout << endl << setw(68) << "" << "Khong co khach hang nao de xoa!" ;
					break;
				}
				danh_sach_khach_hang.show();
				cout <<setfill(' ');
				cout << endl << endl;
				cout << setw(68) << "" << "Nhap STT khach hang muon xoa: " ;
				cin >> a;
				danh_sach_khach_hang.xoa(a);
				cout <<setfill(' ');
				cout << endl << setw(68) << "" <<"Da xoa khach hang STT " << a << " khoi danh sach!";
				break;
			}
			case '4'://tim
			{
			c:	Start();
				cout <<setfill(' ');
				cout << endl << setw(68) << "" << "Tim kiem theo:";
				cout << endl << setw(68) << "" << "[1] Ten";
				cout << endl << setw(68) << "" << "[2] SDT";
				cout << endl << setw(68) << "" << "[3] Dia chi";
				cout << endl << setw(68) << "" << "[0] Thoat";
				cout << endl << setw(68) << "" << "Nhap lua chon: ";
				fflush(stdin);
				char c14;
				cin >> c14;
				switch(c14)
				{
					case '1':
					{
						cout << endl << setw(68) << "" << "Nhap ten can tim: ";
						string tim;
						fflush(stdin);
						getline(cin,tim);
						khach *i = danh_sach_khach_hang.gethead();
    					cout << endl;
    					cout << setfill(' ');
    					cout << setw(50) << "";
    					cout << setfill('-');
   						cout << setw(6) << left << "+" << setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
    					cout << setfill(' ');
    					cout << setw(50) << "";
						cout <<  "| STT " << "| " << setw(20) << left << "Ho va ten" << "| "<< setw(5) << "tuoi" << "| "<< setw(10) << "dia chi" << "| "<<  setw(13) << "SDT" << "| "<< setw(10) << "gioi tinh" << "| "<< setw(5) << "dtl" << "|" <<endl;
    					cout << setw(50) << "";
    					cout << setfill('-');
    					cout << setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						int dem = 1;
						cout << setfill(' ');
						while(i)
						{
							if(i->timten(tim))
							{
								cout << setw(50) << "" << "| " <<setw(4) << left << dem++ ;
        						i->infor();
       							cout << endl;
							}
							i = i->next;
						}
						cout << setw(50) << ""; 
    					cout << setfill('-');
   			 			cout <<setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						break;
						}
						case '2':
						{
							cout << endl << setw(68) << "" << "Nhap SDT can tim: ";
							string sdttim;
							fflush(stdin);
							cin >> sdttim;
							khach *i = danh_sach_khach_hang.gethead();
    						cout << endl;
    						cout << setfill(' ');
    						cout << setw(50) << "";
    						cout << setfill('-');
   							cout << setw(6) << left << "+" << setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
    						cout << setfill(' ');
    						cout << setw(50) << "";
							cout <<  "| STT " << "| " << setw(20) << left << "Ho va ten" << "| "<< setw(5) << "tuoi" << "| "<< setw(10) << "dia chi" << "| "<<  setw(13) << "SDT" << "| "<< setw(10) << "gioi tinh" << "| "<< setw(5) << "dtl" << "|" <<endl;
    						cout << setw(50) << "";
    						cout << setfill('-');
    						cout << setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
							int dem = 1;
							cout << setfill(' ');
							while(i)
							{
								if(i->timsdt(sdttim))
								{
									cout << setw(50) << "" << "| " <<setw(4) << left << dem++ ;
        							i->infor();
       								cout << endl;
								}
								i = i->next;
							}
							cout << setw(50) << ""; 
    						cout << setfill('-');
   			 				cout <<setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
							break;
						}
						case '3':
						{
							cout << endl << setw(68) << "" << "Nhap dia chi can tim: ";
							string diachitim;
							fflush(stdin);
							cin >> diachitim;
							khach *i = danh_sach_khach_hang.gethead();
    						cout << endl;
    						cout << setfill(' ');
    						cout << setw(50) << "";
    						cout << setfill('-');
   							cout << setw(6) << left << "+" << setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
    						cout << setfill(' ');
    						cout << setw(50) << "";
							cout <<  "| STT " << "| " << setw(20) << left << "Ho va ten" << "| "<< setw(5) << "tuoi" << "| "<< setw(10) << "dia chi" << "| "<<  setw(13) << "SDT" << "| "<< setw(10) << "gioi tinh" << "| "<< setw(5) << "dtl" << "|" <<endl;
    						cout << setw(50) << "";
    						cout << setfill('-');
    						cout << setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
							int dem = 1;
							cout << setfill(' ');
							while(i)
							{
								if(i->timdiachi(diachitim))
								{
									cout << setw(50) << "" << "| " <<setw(4) << left << dem++ ;
        							i->infor();
       								cout << endl;
								}
									i = i->next;
							}
							cout << setw(50) << ""; 
    						cout << setfill('-');
   			 				cout <<setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
							break;
						}
						case '0':
						{
							goto b;
						}
						default:
						{
							cout << setfill(' ');
							cout << setw(68) << "" << "Khong ton tai lenh nay, moi nhap lai!" << endl;
							getch();
							goto c;
						}
				}
				break;
			}
			case '5'://thay doi thong tin
			{
			d:	Start();
				if(danh_sach_khach_hang.getn()==0)
				{
					cout <<setfill(' ');
					cout << endl << setw(68) << "" << "Danh sach trong!" ;
				}
				danh_sach_khach_hang.show();
				cout <<setfill(' ');
				cout << endl ;
				cout << setw(60) << "" << "Nhap STT khach hang muon thay doi thong tin: " ;
				int a;
				cin >> a;
				khach *i = danh_sach_khach_hang.gethead();
				while(--a)
				{
					i = i->next;
				}
				////
				cout << setw(60) << "" << "[1] Thay doi tuoi" << endl;
				cout << setw(60) << "" << "[2] Thay doi dia chi" << endl;
				cout << setw(60) << "" << "[3] Thay doi diem tich luy" << endl;
				cout << setw(60) << "" << "[4] Thay doi so dien thoai" << endl;
				cout << setw(60) << "" << "[0] Thoat" << endl;
				cout << setw(60) << "" << "Nhap lua chon: ";
				fflush(stdin);
				char c15;
				cin >> c15;
				switch(c15)
				{
					case '1':
					{
						int tuoimoi;
						cout << setfill(' ');
    					cout << endl << setw(68) << "" << "Nhap so tuoi moi: " ; cin >> tuoimoi;
    					i->doituoi(tuoimoi);
   		 				cout << endl << setw(68) << "" << "Da thay doi tuoi!" << endl;
						break;
					}
					case '2':
					{
						string diachimoi;
						cout << setfill(' ');
    					cout << endl << setw(68) << "" << "Nhap dia chi moi: " ; 
						fflush(stdin);
						getline(cin,diachimoi);
						i->doidiachi(diachimoi);
    					cout << endl << setw(68) << "" << "Da thay doi dia chi!" << endl;
    					break;
					}
					case '3':
					{
						i->thaydoidiemtichluy();
						break;
					}
					case '4':
					{
						string sdtmoi;
						cout << setfill(' ');
   					 	cout << endl << setw(68) << "" << "Nhap so dien thoai moi: " ; 
						fflush(stdin);
						cin >> sdtmoi;
						i->doisdt(sdtmoi);
    					cout << endl << setw(68) << "" << "Da thay doi so dien thoai!" << endl;
						break;
					}
					case '0':
					{
						goto b;
					}
					default:
					{
						cout << setfill(' ');
						cout << setw(68) << "" << "Khong ton tai lenh nay, moi nhap lai!" << endl;
						getch();
						goto d;
					}
				}
				break;
			}
			case '6'://thong ke
			{
				Start();
				int tongtuoi = 0,tongdtl = 0, maxdtl = 0;
				khach *i = danh_sach_khach_hang.gethead();
				cout << setfill(' ');
				cout << endl << setw(68) << "" <<"Tong so khach hang: " << danh_sach_khach_hang.getn();
				while(i)
				{
					if(i->getdtl()>maxdtl) maxdtl = i->getdtl();
					tongtuoi+=i->gettuoi();
					tongdtl+=i->getdtl();
					i = i->next;
				}
				float tuoitb = tongtuoi/(float)danh_sach_khach_hang.getn();
				cout << endl << setw(68) << "" << "Tong diem tich luy: " << tongdtl;
				cout << endl << setw(68) << "" << "Do tuoi trung binh: " << tuoitb;
				cout << endl << setw(68) << "" << "Diem tich luy lon nhat: " << maxdtl;
				break;
			}
			case '0':
			{
				return;
			}
			default:
			{
				cout << setfill(' ');
				cout << setw(68) << "" << "Lenh nhap sai!";
			}
		}
		cout << setfill(' ');
		cout << endl;
		cout << setw(68)<< "" <<"Nhan phim bat ki de tiep tuc!";
		getch();
	}
}
void Menu_QLKH()
{
	system("cls");
	Start();
	cout << setfill(' ') << setw(59) << left << "" << "==============QUAN LI KHACH HANG==============" << endl << endl;
	vemenu(51,1,2,"IN DANH SACH","THEM KHACH HANG");
	cout << endl;
	vemenu(51,3,4,"XOA KHACH HANG","TIM KIEM KHACH HANG");
	cout << endl;
	vemenu(51,5,6,"THAY DOI THONG TIN","THONG KE");
	cout << endl;
	vethoat(51);
	cout << endl << setw(59) << "" <<  "==============================================" << endl;
	cout << setw(68) << "";
	cout << "Nhap lenh: ";
}
void banhang()
{
	while(true)
	{
	b2:	Menu_BH();
		char chon;
		fflush(stdin);
		cin >> chon;
		switch(chon)
		{
			case '1': //dat ban
			{
				cout << endl << endl;
				cout << setfill(' ');
				bool full = true;
				for(int i=0;i<30;i++)
				{
					if(a[i].gettrangthai() == true) 
					{
						full = false;
						break;
					}
				}
				if(full == true) 
				{
					cout << setfill(' ') << setw(68) << " " << "Khong con ban trong!";
					break;
				}
							
		chon:	bang(a);
				cout << endl << endl << setfill(' ') ;
				cout << setw(68) << "" << "Chon ban: ";
				char nhapchonban[20];
				fflush(stdin);
				cin >> nhapchonban;
				if(atoi(nhapchonban)==0 && (nhapchonban[0]!='0' || strlen(nhapchonban)!=1)) break; 
				int chonban = atoi(nhapchonban);
				if(a[chonban].gettrangthai() == false)
				{
					cout <<  setfill(' ') << setw(68) << " " << "Ban nay da co khach!";
					getch();
					goto chon;
				}
				a[chonban].doitrangthai();
				char ck = 'c';
				do
				{
					system("cls");
					Start();
					dssp.show();
					a[chonban].show();
					a[chonban].themmon(dssp);
					cout << setw(68) << "" << "Tiep tuc nhap mon?(c/k) :";
					fflush(stdin);
					cin >> ck;
				}
				while(ck!='k');
				break;							
			}
			case '2': //them mon
			{
				bool full = true;
				for(int i=0;i<30;i++)
				{
					if(a[i].gettrangthai() == false) 
					{
						full = false;
						break;
					}
				}
				if(full == true) 
				{
					cout << setfill(' ') << setw(68) << " " << "Khong con ban nao duoc dat!";
					break;
				}
			them:	bang(a);
				cout << endl << endl <<setw(68) << "" << "Chon ban muon them mon: ";
				char nhapchonban[20];
				fflush(stdin);
				cin >> nhapchonban;
				if(atoi(nhapchonban)==0 && (nhapchonban!="0" || strlen(nhapchonban)!=1)) break; 
				int banchon = atoi(nhapchonban);
				if(a[banchon].gettrangthai() == true)
				{
					cout <<  setfill(' ') << setw(68) << " " << "Ban nay chua co khach!";
					getch();
					goto them;
				}
				char ck = 'c';
				do
				{
					system("cls");
					Start();
					dssp.show();
					a[banchon].show();
					a[banchon].themmon(dssp);
					cout << setw(68) << "" << "Tiep tuc nhap mon?(c/k) :";
					fflush(stdin);
					cin >> ck;
				}
				while(ck!='k');
				break;
			}
			case '3': //tinhtien
			{
				bool full = true;
				for(int i=0;i<30;i++)
				{
					if(a[i].gettrangthai() == false) 
					{
						full = false;
						break;
					}
				}
				if(full == true) 
				{
					cout << setfill(' ') << setw(68) << " " << "Khong con ban nao duoc dat!";
					break;
				}
	chonlai:	bang(a);
				cout << endl << endl << setw(68) << "" << "Chon ban muon tinh tien: ";
				char nhapchonban[20];
				fflush(stdin);
				cin >> nhapchonban;
				if(atoi(nhapchonban)==0 && (nhapchonban!="0" || strlen(nhapchonban)!=1)) break; 
				int banchon = atoi(nhapchonban);
				if(a[banchon].gettrangthai() == true) 
				{
					cout << setfill(' ') << setw(68) << "" << "Ban nay chua co khach!";
					getch();
					goto chonlai;
				}
				
				int cumoi;
	hoi:		cout << endl << setfill(' ') << setw(68) << "" << "Luu thong tin khach hang?(c/k) : " ;
				char hoi;
				fflush(stdin);
				cin >> hoi;
				if(hoi=='c') 
				{
		nhapten:	system("cls");
					Start();
					cout << endl << setfill(' ') << setw(68) << "" << " (?) Khach hang moi?(moi : 1|cu : 0|thoat: so bat ki) : "; cin >> cumoi;
					khach khach1;
					string ten;
					if(cumoi == 1)
					{
						khach1.nhap();
						danh_sach_khach_hang.them(khach1);
						ten = khach1.getname();	
					}
					else if(cumoi==0)
					{ 
						cout << setfill(' ') << setw(68)  << "" << "Ten khach hang: " ;
						fflush(stdin);
						getline(cin,ten);	
					}
					else 
					{
						goto tinhtien;
					}
					khach *i = danh_sach_khach_hang.gethead();
					while(i!=NULL)
					{
						if(i->getname()!=ten) i = i->next;
						else break;
					}
					if(i==NULL)
					{
						cout << setw(68) << "" << "Khong co trong danh sach! Moi nhap lai!";
						getch();
						goto nhapten;
					}
					if(i->next!=NULL)
					{
						if(i->next->getname()==ten)
						{
							cout << setw(68) << "" << "SDT: ";
							string laysdt;
							fflush(stdin);
							cin >> laysdt;
							while(i->getsdt()!=laysdt)
							{
								i = i->next;
							} 
						}
					}
					a[banchon].setkhach(i);
					cout << endl << setw(68) << "" << "Nhan phim bat ki de tiep tuc!" << endl;
					getch();
				}
		tinhtien:system("cls");
				Start();
				a[banchon].tinhtien(dshd);
				break;
			}
			case '4':
			{
			hd:	system("cls");
				cout << endl << endl << endl << endl;
				dshd.show();
				char chon;
				cout << setfill(' ') << setw(60) << "" << setfill('-') << setw(30) << "" << endl;
				cout << setfill(' ') << setw(65) << "" << "[1] Hoa don chi tiet" << endl;
				cout << setfill(' ') << setw(65) << "" << "[2] Xoa hoa don " << endl;
				cout << setfill(' ') << setw(65) << "" << "[3] Xoa tat ca hoa don " << endl;
				cout << setfill(' ') << setw(65) << "" << "[0] Thoat " << endl;
				cout << setfill(' ') << setw(60) << "" << setfill('-') << setw(30) << "" << endl;
				cout << setfill(' ') << setw(65) << "" << "Nhap lenh: ";
				fflush(stdin);
				cin >> chon;
				switch(chon)
				{
					case '1':
					{
						int chon2;
						cout << setfill(' ') << setw(65) << "" << "Nhap STT hoa don : ";
						cin >> chon2;
						Hoadon *i = dshd.gethead();
						while(chon2>1 && i)
						{
							i = i->next;
						}
						if(i==NULL || chon2 == 0) 
						{
							cout << setfill(' ') << setw(65) << "" << "Lenh nhap sai!" << endl;
							cout << setw(65) << "" << "Nhan phim bat ki de tiep tuc.";
							getch();
							goto hd;
						}  
						else
						{
							system("cls");
							i->infor();
							cout << endl;
							cout << setfill(' ') << setw(65) << "" << "Nhan phim bat ki de tiep tuc.";
							getch();
							goto hd;
						}
					}
					case '2':
					{
						int chon2;
						cout << setfill(' ') << setw(65) << "" << "Nhap STT hoa don can xoa : ";
						cin >> chon2;
						if(chon2 == 0 || chon2 > dshd.getn()) 
						{
							cout << setfill(' ') << setw(65) << "" << "Lenh nhap sai!" << endl;
							cout << setfill(' ') << setw(65) << "" << "Nhan phim bat ki de tiep tuc.";
							getch();
							goto hd;
						} 
						else
						{
							dshd.xoa(chon2);
							cout << setfill(' ') << setw(65) << "" << "Da xoa hoa don." << endl;
							cout << setfill(' ') << setw(65) << "" << "Nhan phim bat ki de tiep tuc.";
							getch();
							goto hd;
						}
					}
					case '3':
					{
						cout << setfill(' ') << setw(65) << "" << "Ban co thuc su muon xoa tat ca hoa don?(c/k) : ";
						char a;
						fflush(stdin);
						cin >> a;
						if(a=='c')
						{
							dshd.xoahet();
							cout << setfill(' ') << setw(65) << "" << "Da xoa tat ca hoa don." << endl;
							cout << setfill(' ') << setw(65) << "" << "Nhan phim bat ki de tiep tuc.";
							getch();
							goto hd;
						}
						else
						{
							cout << endl << setfill(' ') << setw(65) << "" << "Nhan phim bat ki de tiep tuc.";
						}
					}
					case '0':
					{
						break;
					}
					default:
					{
						cout << setfill(' ') << setw(65) << "" << "Lenh nhap sai!" << endl;
						cout << setfill(' ') << setw(65) << "" << "Nhan phim bat ki de tiep tuc.";
						getch();
					}
				}
				break;
			}
			case '0':
			{
				return;
			}
			default:
			{
				cout << setfill(' ');
				cout << setw(68) << "" << "Lenh nhap sai!";
			}
		}
		cout << setfill(' ');
		cout << endl << setw(68) << "" << "Nhan phim bat ki de tiep tuc!" << endl;
		getch();
	}
}
void Menu_BH()
{
	system("cls");
	Start();
	cout << setfill(' ');
	cout << setfill(' ') << setw(68) << left << "" << "==========BAN HANG==========" << endl << endl;
	vemenu(51,1,2,"DAT BAN","THEM MON");
	cout << endl;
	vemenu(51,3,4,"TINH TIEN","LICH SU BAN HANG");
	cout << endl;
	vethoat(51);
	cout << endl << setw(68) << "" <<  "============================" << endl;	
	cout << setw(68) << "" << "Nhap lenh: ";
}
void bang(ban a[])
{
	system("cls");
	Start();
	cout << endl << endl << endl << setfill(' ') << setw(44)<< "";
	cout << char(218);
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<7;j++) cout << char(196);
		cout << char(194);
	}
	for(int j=0;j<7;j++) cout << char(196);
	cout << char(191);
	////////////////////
	cout << endl << setfill(' ') << setw(44)<< "";			
	for(int i=0;i<10;i++)
	{
		cout << char(179) << "   " << i << "   ";
	}
	cout << char(179);
	////////////////////
	cout << endl << setfill(' ') << setw(40)<< "";	
	cout << char(218) << char(196) << char(196) << char(196);
	cout << char(197);
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<7;j++) cout << char(196);
		cout << char(197);
	}
	for(int j=0;j<7;j++) cout << char(196);
	cout << char(180);
	///////////////////
	for(int j=0;j<3;j++)
	{
		cout << endl << setfill(' ') << setw(40)<< "" << char(179) << (j==1?" 0 ":"   ");
		for(int i=1;i<=10;i++)
		{
			cout << char(179) << (a[i-1].gettrangthai()==false&&j==1?"   X   ":"       ");
		}
		cout << char(179);
	}
	////////////////////////
	cout << endl << setfill(' ') << setw(40)<< ""<< char(195) << char(196) << char(196) << char(196);
	cout << char(197);
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<7;j++) cout << char(196);
		cout << char(197);
	}
	for(int j=0;j<7;j++) cout << char(196);
	cout << char(180);
	///////////////////////////
	for(int j=0;j<3;j++)
	{
		cout << endl << setfill(' ') << setw(40)<< "" << char(179) << (j==1?" 1 ":"   ");
		for(int i=1;i<=10;i++)
		{
			cout << char(179) << (a[i-1+10].gettrangthai()==false&&j==1?"   X   ":"       ");
		}
		cout << char(179);
	}
	////////////////////// 
	cout << endl << setfill(' ') << setw(40)<< "" << char(195) << char(196) << char(196) << char(196);
	cout << char(197);
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<7;j++) cout << char(196);
		cout << char(197);
	}
	for(int j=0;j<7;j++) cout << char(196);
	cout << char(180);
	////////////////////////
	for(int j=0;j<3;j++)
	{
		cout << endl << setfill(' ') << setw(40)<< "" << char(179) << (j==1?" 2 ":"   ");
		for(int i=1;i<=10;i++)
		{
			cout << char(179) << (a[i-1+20].gettrangthai()==false&&j==1?"   X   ":"       ");
		}
		cout << char(179);
	}
	///////////////////
	cout << endl << setfill(' ') << setw(40)<< "" << char(192) << char(196) << char(196) << char(196);
	cout << char(193);
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<7;j++) cout << char(196);
		cout << char(193);
	}
	for(int j=0;j<7;j++) cout << char(196);
	cout << char(217);
	cout << endl << setw(40) << "" << "X : ban co khach" << endl;
	cout << endl << setw(40) << "" << "thoat: Nhap chu bat ki!";
}
void quanlisanpham()
{
	while(true)
	{
b1:		Menu_QLSP();
		fflush(stdin);
		char c3;
		cin >> c3;
		switch(c3)
		{
			case '1':// in ds
				{
					Start();
					dssp.show();
					break;	
				}
			case '2':// them
			{
				Start();
				sanpham p;
				p.nhap();
				dssp.them(p);
				break;
			}	
			case '3' : // xoa 
			{
				Start();
				int a;
				if(dssp.getn()==0)
				{
					cout <<setfill(' ');
					cout << endl << setw(68) << "" << "Khong co san pham nao de xoa!" ;
					break;
				}
				dssp.show();
				cout <<setfill(' ');
				cout << endl << endl;
				cout << setw(68) << "" << "Nhap STT san pham muon xoa: " ;
				cin >> a;
				dssp.xoa(a);
				cout <<setfill(' ');
				cout << endl << setw(68) << "" <<"Da xoa san pham STT " << a << " khoi danh sach!" << endl;
				break;
			}
			case '4' : // tim kiem
			{
			c1:	Start();
				cout <<setfill(' ');
				cout << endl << setw(68) << "" << "Tim kiem theo:";
				cout << endl << setw(68) << "" << "[1] Ten SP";
				cout << endl << setw(68) << "" << "[2] Loai SP";
				cout << endl << setw(68) << "" << "[0] Thoat";
				cout << endl << setw(68) << "" << "Nhap lua chon: ";
				fflush(stdin);
				char c34;
				cin >> c34;
				switch(c34)
				{
					case '1':
					{
						cout << endl << setw(68) << "" << "Nhap ten san pham can tim: ";
						string tim;
						fflush(stdin);
						getline(cin,tim);
						sanpham *i = dssp.gethead();
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
						cout << setfill(' ');
						while(i)
						{
							if(i->timten(tim))
							{
								cout << setw(50) << "" << "| " <<setw(4) << left << dem++ ;
        						i->infor();
       							cout << endl;
							}
							i = i->next;
						}
						cout << setw(50) << "";
						cout << setfill('-');
						cout << setw(6) << left << "+" << setw(12) << "+"<< setw(22) << "+" << setw(10) << "+" << setw(10) << "+" << setw(11) << "+" << "+" << endl;
						break;
					}
					case '2':
					{
						cout << endl << setw(68) << "" << "Nhap loai san pham can tim: ";
						string tim;
						fflush(stdin);
						getline(cin,tim);
						sanpham *i = dssp.gethead();
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
						cout << setfill(' ');
						while(i)
						{
							if(i->timloai(tim))
							{
								cout << setw(50) << "" << "| " <<setw(4) << left << dem++ ;
        						i->infor();
       							cout << endl;
							}
							i = i->next;
						}
						cout << setw(50) << "";
						cout << setfill('-');
						cout << setw(6) << left << "+" << setw(12) << "+"<< setw(22) << "+" << setw(10) << "+" << setw(10) << "+" << setw(11) << "+" << "+" << endl;
						break;
					}
					case '0':
					{
						goto b1;
					}
					default:
					{
						cout << setfill(' ');
						cout << setw(68) << "" << "Khong ton tai lenh nay, moi nhap lai!" << endl;
						getch();
						goto c1;
					}
				}
				break;
			}
			case '5'://thay doi thong tin
			{
			d1:	Start();
				if(dssp.getn()==0)
				{
					cout <<setfill(' ');
					cout << endl << setw(68) << "" << "Danh sach trong!" ;
					break;
				}
				dssp.show();
				cout <<setfill(' ');
				cout << endl ;
				cout << setw(68) << "" << "Nhap STT san pham muon thay doi thong tin: " ;
				int a;
				cin >> a;
				sanpham *i = dssp.gethead();
				while(--a)
				{
					i = i->next;
				}
				////
				cout << setw(68) << "" << "[1] Thay doi ten SP" << endl;
				cout << setw(68) << "" << "[2] Thay doi loai SP" << endl;
				cout << setw(68) << "" << "[3] Thay doi gia SP" << endl;
				cout << setw(68) << "" << "[4] Thay doi so luong SP" << endl;
				cout << setw(68) << "" << "[0] Thoat" << endl;
				cout << setw(68) << "" << "Nhap lua chon: ";
				fflush(stdin);
				char c35;
				cin >> c35;
				switch(c35)
				{
					case '1':
					{
						string tenmoi;
						cout << setfill(' ');
						cout << endl << setw(68) << "" << "Nhap ten SP moi: " ;
						fflush(stdin);
						getline(cin,tenmoi);
						i->doiten(tenmoi);
						cout << endl << setw(68) << "" << "Da thay doi ten cua SP!" << endl;
						break;
					}
					case '2':
					{
						string loaimoi;
						cout << setfill(' ');
						cout << endl << setw(68) << "" << "Nhap loai moi: " ; 
						fflush(stdin);
						getline(cin,loaimoi);
						i->doiloai(loaimoi);
						cout << endl << setw(68) << "" << "Da thay doi loai cua SP!" << endl;
						break;
					}
					case '3':
					{
						float giamoi;
						cout << setfill(' ');
						fflush(stdin);
						cout << endl << setw(68) << "" << "Nhap gia moi: " ; cin >> giamoi;
						i->doigia(giamoi);
						cout << endl << setw(68) << "" << "Da thay doi gia cua SP!" << endl;
						break;
					}
					case '4':
					{
						int slmoi;
						cout << setfill(' ');
						fflush(stdin);
						cout << endl << setw(68) << "" << "Nhap so luong SP moi: " ; cin >> slmoi;
						i->doisoluong(slmoi);
						cout << endl << setw(68) << "" << "Da thay doi so luong cua SP!" << endl;
						break;
					}
					case '0':
					{
						goto b1;
					}
					default:
					{
						cout << setfill(' ');
						cout << setw(68) << "" << "Khong ton tai lenh nay, moi nhap lai" << endl;
						getch();
						goto d1;
						break;
					}
				}
				break;
			}
			case '6':
			{
				Start();
				cout << setfill(' ');
				cout << endl << setw(68) << "" <<"Tong so san pham: " << dssp.getn();
				float tonggt = 0;
				int tongsl = 0;
				sanpham *i = dssp.gethead();
				while(i)
				{
					tonggt+=i->getsl()*i->getgia();
					tongsl+=i->getsl();
					i = i->next;
				}
				cout << endl << setw(68) << "" << "Tong so luong san pham con lai: " << tongsl;
				cout << endl << setw(68) << "" << "Tong gia tri sang pham con lai: " << tonggt;
				break;
			}
			case '0':
			{
				return;
			}
			default:
			{
				cout << setfill(' ');
				cout << setw(68) << "" << "Lenh nhap sai!";
			}
		}
		cout << setfill(' ');
		cout << endl << endl << setw(68) << "" << "Nhan phim bat ki de tiep tuc!";
		getch();
	}	
}
void Menu_QLSP()
{
	system("cls");
	Start();
	cout << setfill(' ') << setw(59) << left << "" << "===============QUAN LI SAN PHAM===============" << endl << endl;
	vemenu(51,1,2,"IN DANH SACH","THEM SAN PHAM");
	cout << endl;
	vemenu(51,3,4,"XOA SAN PHAM","TIM KIEM SAN PHAM");
	cout << endl;
	vemenu(51,5,6,"THAY DOI THONG TIN","THONG KE");
	cout << endl;
	vethoat(51);
	cout << endl << setw(59) << "" <<  "==============================================" << endl;
	cout << setw(68) << "";
	cout << "Nhap lenh: ";
}
void quanlinhanvien()
{
	while(true)
	{
	b3:	Menu_QLNV();
		char c2;
		fflush(stdin);
		cin >> c2;
		switch(c2)
		{
			case '1'://show
			{
				Start();
				dsnv.show();
				break;
			}
			case '2'://them
			{
				Start();
				nhanvien p;
				p.nhap();
				dsnv.them(p);
				break;
			}
			case '3'://xoa
			{
				Start();
				int a;
				if(dsnv.getn()==0)
				{
					cout <<setfill(' ');
					cout << endl << setw(68) << "" << "Khong co nhan vien nao de xoa!" ;
					break;
				}
				dsnv.show();
				cout <<setfill(' ');
				cout << endl << endl;
				cout << setw(68) << "" << "Nhap STT nhan vien muon xoa: " ;
				cin >> a;
				dsnv.xoa(a);
				cout <<setfill(' ');
				cout << endl << setw(68) << "" <<"Da xoa nhan vien STT " << a << " khoi danh sach!" << endl;
				break;
			}
			case '4'://tim kiem
			{
				c3:	Start();
				cout <<setfill(' ');
				cout << endl << setw(68) << "" << "Tim kiem theo:";
				cout << endl << setw(68) << "" << "[1] Ten";
				cout << endl << setw(68) << "" << "[2] SDT";
				cout << endl << setw(68) << "" << "[3] Dia chi";
				cout << endl << setw(68) << "" << "[4] Chuc vu";
				cout << endl << setw(68) << "" << "[0] Thoat";
				cout << endl << setw(68) << "" << "Nhap lua chon: ";
				fflush(stdin);
				char c24;
				cin >> c24;
				switch(c24)
				{
					case '1':
					{
						cout << endl << setw(68) << "" << "Nhap ten can tim: ";
						string tim;
						fflush(stdin);
						getline(cin,tim);
						nhanvien *i = dsnv.gethead();
						cout << endl;
						cout << setfill(' ');
						cout << setw(50) << "";
						cout << setfill('-');
						cout << setw(6) << left << "+" << setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						cout << setfill(' ');
						cout << setw(50) << "";
						cout <<  "| STT " << "| " << setw(20) << left << "Ho va ten" << "| "<< setw(5) << "tuoi" << "| "<< setw(10) << "dia chi" << "| "<<  setw(13) << "SDT" << "| "<< setw(10) << "gioi tinh" << "| "<< setw(10) << "chuc vu" << "| " << setw(5) << "hsl" << "|" <<endl;
						cout << setw(50) << "";
						cout << setfill('-');
						cout << setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						int dem = 1;
						cout << setfill(' ');
						while(i)
						{
							if(i->timten(tim))
							{
								cout << setw(50) << "" << "| " <<setw(4) << left << dem++ ;
								i->infor();
								cout << endl;
							}
							i = i->next;
						}
						cout << setw(50) << ""; 
						cout << setfill('-');
						cout <<setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						break;
					}
					case '2':
					{
						cout << endl << setw(68) << "" << "Nhap SDT can tim: ";
						string sdttim;
						fflush(stdin);
						getline(cin,sdttim);
						nhanvien *i = dsnv.gethead();
						cout << endl;
						cout << setfill(' ');
						cout << setw(50) << "";
						cout << setfill('-');
						cout << setw(6) << left << "+" << setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						cout << setfill(' ');
						cout << setw(50) << "";
						cout <<  "| STT " << "| " << setw(20) << left << "Ho va ten" << "| "<< setw(5) << "tuoi" << "| "<< setw(10) << "dia chi" << "| "<<  setw(13) << "SDT" << "| "<< setw(10) << "gioi tinh" << "| "<< setw(10) << "chuc vu" << "| " << setw(5) << "hsl" << "|" <<endl;
						cout << setw(50) << "";
						cout << setfill('-');
						cout << setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						int dem = 1;
						cout << setfill(' ');
						while(i)
						{
							if(i->timsdt(sdttim))
							{
								cout << setw(50) << "" << "| " <<setw(4) << left << dem++ ;
								i->infor();
								cout << endl;
							}
							i = i->next;
						}
						cout << setw(50) << ""; 
						cout << setfill('-');
						cout <<setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						break;
					}
					case '3':
					{
						cout << endl << setw(68) << "" << "Nhap dia chi can tim: ";
						string diachitim;
						fflush(stdin);
						getline(cin,diachitim);
						nhanvien *i = dsnv.gethead();
						cout << endl;
						cout << setfill(' ');
						cout << setw(50) << "";
						cout << setfill('-');
						cout << setw(6) << left << "+" << setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						cout << setfill(' ');
						cout << setw(50) << "";
						cout <<  "| STT " << "| " << setw(20) << left << "Ho va ten" << "| "<< setw(5) << "tuoi" << "| "<< setw(10) << "dia chi" << "| "<<  setw(13) << "SDT" << "| "<< setw(10) << "gioi tinh" << "| "<< setw(10) << "chuc vu" << "| " << setw(5) << "hsl" << "|" <<endl;
						cout << setw(50) << "";
						cout << setfill('-');
						cout << setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						int dem = 1;
						cout << setfill(' ');
						while(i)
						{
							if(i->timdiachi(diachitim))
							{
								cout << setw(50) << "" << "| " <<setw(4) << left << dem++ ;
								i->infor();
								cout << endl;
							}
							i = i->next;
						}
						cout << setw(50) << ""; 
						cout << setfill('-');
						cout <<setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						break;
					}
					case '4':
					{
						cout << endl << setw(68) << "" << "Nhap chuc vu can tim: ";
						string chucvutim;
						fflush(stdin);
						getline(cin,chucvutim);
						nhanvien *i = dsnv.gethead();
						cout << endl;
						cout << setfill(' ');
						cout << setw(50) << "";
						cout << setfill('-');
						cout << setw(6) << left << "+" << setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						cout << setfill(' ');
						cout << setw(50) << "";
						cout <<  "| STT " << "| " << setw(20) << left << "Ho va ten" << "| "<< setw(5) << "tuoi" << "| "<< setw(10) << "dia chi" << "| "<<  setw(13) << "SDT" << "| "<< setw(10) << "gioi tinh" << "| "<< setw(10) << "chuc vu" << "| " << setw(5) << "hsl" << "|" <<endl;
						cout << setw(50) << "";
						cout << setfill('-');
						cout << setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						int dem = 1;
						cout << setfill(' ');
						while(i)
						{
							if(i->timchucvu(chucvutim))
							{
								cout << setw(50) << "" << "| " <<setw(4) << left << dem++ ;
								i->infor();
								cout << endl;
							}
							i = i->next;
						}
						cout << setw(50) << ""; 
						cout << setfill('-');
						cout <<setw(6) << left << "+" <<setw(22) << "+" << setw(7) << "+" << setw(12) << "+" << setw(15) << "+" << setw(12) << "+" << setw(12) << "+" << setw(7) << "+" << "+" << endl;
						break;
					}
				case '0':
					{
						goto b3;
					}
				default:
					{
						cout << setfill(' ');
						cout << setw(68) << "" << "Khong ton tai lenh nay, moi nhap lai!" << endl;
						getch();
						goto c3;
					}
				}
				break;
			}
			case '5'://thay doi thong tin
			{
			d3:	Start();
				if(dsnv.getn()==0)
				{
					cout <<setfill(' ');
					cout << endl << setw(68) << "" << "Danh sach trong!" ;
					break;
				}
				dsnv.show();
				cout <<setfill(' ');
				cout << endl ;
				cout << setw(68) << "" << "Nhap STT nhan vien muon thay doi thong tin: " ;
				int a;
				cin >> a;
				nhanvien *i = dsnv.gethead();
				while(--a)
				{
					i = i->next;
				}
				////
				cout << setw(68) << "" << "[1] Thay doi tuoi" << endl;
				cout << setw(68) << "" << "[2] Thay doi dia chi" << endl;
				cout << setw(68) << "" << "[3] Thay doi he so luong" << endl;
				cout << setw(68) << "" << "[4] Thay doi so dien thoai" << endl;
				cout << setw(68) << "" << "[5] Thay doi chuc vu" << endl;
				cout << setw(68) << "" << "[0] Thoat" << endl;
				cout << setw(68) << "" << "Nhap lua chon: ";
				fflush(stdin);
				char c25;
				cin >> c25;
				switch(c25)
				{
					case '1':
					{
						int tuoimoi;
						cout << setfill(' ');
						cout << endl << setw(68) << "" << "Nhap so tuoi moi: " ; cin >> tuoimoi;
						i->doituoi(tuoimoi);
						cout << endl << setw(68) << "" << "Da thay doi tuoi!" << endl;
						break;
					}
					case '2':
					{
						string diachimoi;
						cout << setfill(' ');
						cout << endl << setw(68) << "" << "Nhap dia chi moi: " ; 
						fflush(stdin);
						getline(cin,diachimoi);
						i->doidiachi(diachimoi);
						cout << endl << setw(68) << "" << "Da thay doi dia chi!" << endl;
						break;
					}
					case '3':
					{
						float hslmoi;
						cout << setfill(' ');
					    cout << endl << setw(68) << "" << "Nhap he so luong moi: " ; cin >> hslmoi;
					    i->doihesoluong(hslmoi);
					    cout << endl << setw(68) << "" << "Da thay doi he so luong!" << endl;
						break;
					}
					case '4':
					{
						string sdtmoi;
						cout << setfill(' ');
					    cout << endl << setw(68) << "" << "Nhap so dien thoai moi: " ; 
					    fflush(stdin);
						cin >> sdtmoi;
						i->doisdt(sdtmoi);
					    cout << endl << setw(68) << "" << "Da thay doi so dien thoai!" << endl;
						break;
					}
					case '5':
					{
						string chucvumoi;
						cout << setfill(' ');
					    cout << endl << setw(68) << "" << "Nhap chuc vu moi: " ; 
					    fflush(stdin);
					    getline(cin,chucvumoi);
					    i->doichucvu(chucvumoi);
					    cout << endl << setw(68) << "" << "Da thay doi chuc vu!" << endl;
						break;
					}
					case '0':
					{
						goto b3;
					}
					default:
					{
						cout << setfill(' ');
						cout << setw(68) << "" << "Khong ton tai lenh nay, moi nhap lai!" << endl;
						getch();
						goto d3;
					}
				}
				break;
			}	
			case '6'://thong ke
			{
				int tongtuoi = 0;
				float tonghsl = 0;
				nhanvien *i = dsnv.gethead();
				cout << setfill(' ');
				cout << endl << setw(68) << "" <<"Tong so nhan vien: " << dsnv.getn();
				while(i)
				{
					tonghsl+=i->gethsl();
					tongtuoi+=i->gettuoi();
					i = i->next;
				}
				float tuoitb = tongtuoi/(float)dsnv.getn();
				float hsltb = tonghsl/dsnv.getn();
				cout << setprecision(3) << fixed;
				cout << endl << setw(68) << "" << "Do tuoi trung binh: " << tuoitb;
				cout << endl << setw(68) << "" << "he so luong trung binh: " << hsltb;
				break;
			}
			case '0':
			{
				return;
			}
			default:
			{
				cout << setfill(' ');
				cout << setw(68) << "" << "Lenh nhap sai!";
			}
		}
		cout << setfill(' ');
		cout << endl;
		cout << setw(68)<< "" <<"Nhan phim bat ki de tiep tuc!";
		getch();
	}
}
void Menu_QLNV()
{
	system("cls");
	Start();
	cout << setfill(' ') << setw(59) << left << "" << "===============QUAN LI NHAN VIEN===============" << endl << endl;
	vemenu(51,1,2,"IN DANH SACH","THEM NHAN VIEN");
	cout << endl;
	vemenu(51,3,4,"XOA NHAN VIEN","TIM KIEM NHAN VIEN");
	cout << endl;
	vemenu(51,5,6,"THAY DOI THONG TIN","THONG KE");
	cout << endl;
	vethoat(51);
	cout << endl << setw(59) << "" <<  "===============================================" << endl;
	cout << setw(68) << "";
	cout << "Nhap lenh: ";
}
void doimatkhau()
{
	system("cls");
	Box(68,16,30,7,14,14);
	ToMau(77,17,"NHAP MAT KHAU",14);
	int solannhap = 3;
	string newpass1,newpass2;
	int length_max = 30;
	do
	{
		ToMau(72,18,"                          ",14);
		textcolor(14);
		gotoXY(76,19);
		cout << "Con " << solannhap << " lan nhap!";
		gotoXY(72,24);
		cout << "Tab: An/hien ki tu";
		gotoXY(72,25);
		cout << "Esc: Thoat";
		gotoXY(72,18);
		textcolor(7);
		string strRet;
	    char ch = 0;
	    bool bShow = false;
	    do
	    {
	        ch = getch();
	        if((strRet.size() < length_max) && (::isalpha(ch) || ::isalnum(ch))) 
	        {
	            std::cout << (bShow ? ch : '*');
	            strRet.push_back(ch);
	        }
	        else
	        {
	            if(9 == ch) 
	            {
	                bShow = !bShow;
	                std::cout << std::string(strRet.size(), '\b');
	                if(bShow)
	                    std::cout << strRet;
	                else
	                    std::cout << std::string(strRet.size(), '*');
	               
	            }
	            if('\b' == ch && !strRet.empty())
	            {
	                std::cout << "\b \b";
	                strRet.resize(strRet.size() - 1);
	            }
	            if(ch == 27)
	            {
	            	return ;
				}
	        }
	    }
		while ('\r' != ch);
		if(strRet == password)
		{
			break;
		}
		else
		{
			solannhap--;
			ToMau(75,21,"Sai mat khau!",14);
			getch();
			ToMau(75,21,"             ",14);
			if(solannhap==0) return ;	
		}
		textcolor(7);
	}
	while(true);	
	do
	{
		system("cls");
		Box(68,16,30,7,14,14);
		ToMau(70,17,"NHAP MAT KHAU MOI",14);
		ToMau(70,19,"NHAP LAI MAT KHAU MOI",14);
		textcolor(14);
		gotoXY(72,24);
		cout << "Tab: An/hien ki tu";
		gotoXY(72,25);
		cout << "Esc: Thoat";
		gotoXY(70,18);
		string newpass1;
	    char ch1 = 0;
	    bool bShow = false;
	    do
	    {
	        ch1 = getch();
	        if((newpass1.size() < length_max) && (::isalpha(ch1) || ::isalnum(ch1))) 
	        {
	            std::cout << (bShow ? ch1 : '*');
	            newpass1.push_back(ch1);
	        }
	        else
	        {
	            if(9 == ch1) 
	            {
	                bShow = !bShow;
	                std::cout << std::string(newpass1.size(), '\b');
	                if(bShow)
	                    std::cout << newpass1;
	                else
	                    std::cout << std::string(newpass1.size(), '*');
	               
	            }
	            if('\b' == ch1 && !newpass1.empty())
	            {
	                std::cout << "\b \b";
	                newpass1.resize(newpass1.size() - 1);
	            }
	            if(ch1 == 27)
	            {
	            	return ;
				}
	        }
	    }
		while ('\r' != ch1);
	    
	    gotoXY(70,20);
	    string newpass2;
	    char ch2 = 0;
	    bShow = false;
	    do
	    {
	        ch2 = getch();
	        if((newpass2.size() < length_max) && (::isalpha(ch2) || ::isalnum(ch2))) 
	        {
	            std::cout << (bShow ? ch2 : '*');
	            newpass2.push_back(ch2);
	        }
	        else
	        {
	            if(9 == ch2) 
	            {
	                bShow = !bShow;
	                std::cout << std::string(newpass2.size(), '\b');
	                if(bShow)
	                    std::cout << newpass2;
	                else
	                    std::cout << std::string(newpass2.size(), '*');
	               
	            }
	            if('\b' == ch2 && !newpass2.empty())
	            {
	                std::cout << "\b \b";
	                newpass2.resize(newpass2.size() - 1);
	            }
	            if(ch2 == 27)
	            {
	            	return ;
				}
	        }
	    }while ('\r' != ch2);
		if(newpass1!=newpass2)
		{
			gotoXY(70,21);
			cout << "Mat khau khong khop!";
			getch();
		}
		else
		{
			gotoXY(70,21);
			cout << "Doi mat khau thanh cong!";
			password = newpass1;
			getch();
			textcolor(7);
			return ;
		}
	}
	while(true);
}
