	
	#include "Nhanvien.h"
	#include "Vattu.h"



// vat tu error

struct vattu_error{
	char* error_st[4];
	int error_color[4];
	bool check = true;
};
vattu_error Check_VT_new(Vattu &vt,char MaVT[], char TVT[], char Donvi[], char sluong[])
{
		vattu_error p;
		
		
		// xu li ma vat tu
		if(Find_VT(DataVattu,MaVT)) {
			p.error_st[0] = "Vat tu da ton tai\0";
			p.check = false;
			p.error_color[0] = 4;
		}
		else if(strlen(MaVT)==0) {
			p.error_st[0] = "Khong duoc rong  \0";
			p.check = false;
			p.error_color[0] = 4;
		}
			else
			p.error_st[0] = "Co the su dung   \0",p.error_color[0] = COLOR(0,255,0);
		// xu li ten vat tu
		
			int len_TVT = strlen(TVT);
			if(TVT[len_TVT-1] == ' ') TVT[--len_TVT] = NULL;
			if(len_TVT == 0) {
				p.error_st[1] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[1] = 4;
			}
			else p.error_st[1] = "Co the su dung \0",p.error_color[1] = COLOR(0,255,0);
			
		
		// xu li Don vi
		
			int len_DV = strlen(Donvi);
			if(Donvi[len_DV-1] == ' ') Donvi[len_DV--] = NULL;
			if(len_DV == 0){
				p.error_st[2] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[2] = 4;
			}
			else p.error_st[2] = "Co the su dung \0",p.error_color[2] = COLOR(0,255,0);
		
		//xu li so luong
		
			int len_slt = strlen(sluong);
			if(len_slt == 0){
				p.error_st[3] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[3] = 4;
			}
			else p.error_st[3] = "Co the su dung \0",p.error_color[3] = COLOR(0,255,0);
				if(p.check == true){
			strcpy(vt.MAVT, MaVT);
			
			strcpy(vt.TENVT, TVT);
			
			strcpy(vt.DVT , Donvi);
			strcpy(vt.soluongton,sluong);
		}
		return p;
}
vattu_error Check_VT_seclect(Vattu &vt,char MaVT[], char TVT[], char Donvi[], char sluong[],int check_vt)
{
		vattu_error p;
		// xu li ma vat tu
		if(Find_VT(DataVattu,MaVT) != check_vt && Find_VT(DataVattu,MaVT)>0) {
			p.error_st[0] = "Vat tu da ton tai\0";
			p.check = false;
			p.error_color[0] = 4;
		}
		else if(strlen(MaVT)==0) {
			p.error_st[0] = "Khong duoc rong  \0";
			p.check = false;
			p.error_color[0] = 4;
		}
			else
			p.error_st[0] = "Co the su dung   \0",p.error_color[0] = COLOR(0,255,0);
		// xu li ten vat tu
		
			int len_TVT = strlen(TVT);
			if(TVT[len_TVT-1] == ' ') TVT[len_TVT--] = NULL;
			if(len_TVT == 0) {
				p.error_st[1] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[1] = 4;
			}
			else p.error_st[1] = "Co the su dung \0",p.error_color[1] = COLOR(0,255,0);
			
		
		// xu li Don vi
		
			int len_DV = strlen(Donvi);
			if(Donvi[len_DV-1] == ' ') Donvi[len_DV--] = NULL;
			if(len_DV == 0){
				p.error_st[2] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[2] = 4;
			}
			else p.error_st[2] = "Co the su dung \0",p.error_color[2] = COLOR(0,255,0);
		
		//xu li so luong
		
			int len_slt = strlen(sluong);
			if(len_slt == 0){
				p.error_st[3] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[3] = 4;
			}
			else p.error_st[3] = "Co the su dung \0",p.error_color[3] = COLOR(0,255,0);
				if(p.check == true){
			strcpy(vt.MAVT, MaVT);
			
			strcpy(vt.TENVT, TVT);
			
			strcpy(vt.DVT , Donvi);
			strcpy(vt.soluongton,sluong);
		}
		return p;
}



// nhan vien error
struct nhanvien_error{
	char* error_st[4];
	int error_color[4];
	bool check = true;
};
nhanvien_error Check_NV_new(Nhanvien &nv,char MaNV[], char Ho[], char Ten[], char Phai[])
{
		nhanvien_error p;
		
		
		// xu li ma vat tu
		if(Find_NV(DataNhanvien._nhanvien,MaNV)) {
			p.error_st[0] = "Da ton tai\0";
			p.check = false;
			p.error_color[0] = 4;
		}
		else if(strlen(MaNV)==0) {
			p.error_st[0] = "Khong duoc rong  \0";
			p.check = false;
			p.error_color[0] = 4;
		}
			else
			p.error_st[0] = "Co the su dung   \0",p.error_color[0] = COLOR(0,255,0);
		// xu li ten vat tu
		
			int len_Ho = strlen(Ho);
			if(len_Ho == 0) {
				p.error_st[1] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[1] = 4;
			}
			else p.error_st[1] = "Co the su dung \0",p.error_color[1] = COLOR(0,255,0);
			
		
		// xu li Don vi
		
			int len_ten = strlen(Ten);
			if(len_ten == 0){
				p.error_st[2] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[2] = 4;
			}
			else p.error_st[2] = "Co the su dung \0",p.error_color[2] = COLOR(0,255,0);
		
		//xu li so luong
		
			int len_phai = strlen(Phai);
			if(len_phai == 0){
				p.error_st[3] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[3] = 4;
			}
			else p.error_st[3] = "Co the su dung \0",p.error_color[3] = COLOR(0,255,0);
			if(p.check == true){
			strcpy(nv.MANV, MaNV);
			strcpy(nv.HO, Ho);
			strcpy(nv.TEN , Ten);
			strcpy(nv.PHAI,Phai);
			}
		return p;
}
nhanvien_error Check_NV_seclect(Nhanvien &nv,char MaNV[], char Ho[], char Ten[], char Phai[],char buf[])
{
		nhanvien_error p;
		// xu li ma vat tu
		cout<<"MaNV:::"<<MaNV<<"buf:::"<<buf<<endl;
		if(strcmp(MaNV,buf)==0) cout<<"dung"<<endl;
		if(Find_NV(DataNhanvien._nhanvien,MaNV)==true &&  strcmp(buf , MaNV)!=0) {
			p.error_st[0] = "Vat tu da ton tai\0";
			p.check = false;
			p.error_color[0] = 4;
		}
		else if(strlen(MaNV)==0) {
			p.error_st[0] = "Khong duoc rong  \0";
			p.check = false;
			p.error_color[0] = 4;
		}
			else
			p.error_st[0] = "Co the su dung   \0",p.error_color[0] = COLOR(0,255,0);
		// xu li ten vat tu
		
			int len_Ho = strlen(Ho);
			if(len_Ho == 0) {
				p.error_st[1] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[1] = 4;
			}
			else p.error_st[1] = "Co the su dung \0",p.error_color[1] = COLOR(0,255,0);
			
		
		// xu li Don vi
		
			int len_Ten = strlen(Ten);
			if(len_Ten == 0){
				p.error_st[2] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[2] = 4;
			}
			else p.error_st[2] = "Co the su dung \0",p.error_color[2] = COLOR(0,255,0);
		
		//xu li so luong
		
			int len_Phai = strlen(Phai);
			if(len_Phai == 0){
				p.error_st[3] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[3] = 4;
			}
			else p.error_st[3] = "Co the su dung \0",p.error_color[3] = COLOR(0,255,0);
				if(p.check == true){
			strcpy(nv.MANV, MaNV);	
			strcpy(nv.HO, Ho);
			strcpy(nv.TEN, Ten);
			strcpy(nv.PHAI,Phai);
		}
		return p;
}
// error hoa don
bool Find_HD(Tree &root,char soHD[]){
	if(root == NULL) return false;
	cout<<"1:::"<<root->nv.MANV<<endl;
	for(NodeHD* p = root->nv.nv_HOADON.hdHead;p!=NULL;p = p->_next){
		if(strcmp(p->soHD,soHD)==0) return true;
	}
	return (Find_HD(root->left,soHD) | Find_HD(root->right,soHD) );
}
struct hoadon_error{
	char* error_st[6];
	int error_color[6];
	bool check = true;
};
int dayofmonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
hoadon_error Check_HD_new(NodeHD* &hd, char soHD[], char ngay[], char thang[], char nam[], char loai,char MaNV[])
{
	int x = 4;
		hoadon_error p;
		for(int i =0;i<6;i++)
		{
			p.error_st[i]="\0";
			p.error_color[i]=4;
		}
		cout <<x++<<endl;
		int month_t = parseInt(thang);
		cout <<"m::"<<month_t <<endl;
		int year_t  = parseInt(nam);
		cout <<"y::" <<year_t<<endl;
		int day_t   = parseInt(ngay);
		cout <<"d::"<<day_t<<endl;
		cout <<x++<<endl;
		// xu li ma vat tu
		if(strlen(soHD)==0){
			cout <<x++<<endl;
			p.error_st[0] = "Khong duoc rong\0";
			p.check = false;
			p.error_color[0] = 4;
			return p;
		}
		else{
			if(Find_HD(DataNhanvien._nhanvien,soHD)) {
			p.error_st[0] = "So hoa don trung\0";
			p.check = false;
			p.error_color[0] = 4;
			return p;
			}
		}
		// xu li nam
		cout <<x++<<endl;
			int len_nam = strlen(nam);
			 {
				if(len_nam<4){
					for(int i=3;i>=4-len_nam;i--){
						nam[i] = nam[i-1];
					}
					for(int i=0;i<4-len_nam;i++){
						nam[i] ='0';
					}
				}
			}
		//xu li thang
		cout <<x++<<endl;
			int len_thang = strlen(thang);
		 {
				if(strlen(thang)==1){
					thang [1] = thang[0];
					thang [0] = '0';
				}
				else{
					if(parseInt(thang)>=12){
						p.error_st[1] = "Ngay khong hop le\0";
						p.check = false;
						p.error_color[1] = 4;
						return p;
					}
				}
			}
		
		// xu li ngay
		cout <<x++<<endl;
			int len_ngay = strlen(ngay);
			{
				if(len_ngay==1){
					ngay[1] = ngay[0];
					ngay[0] = '0';
				}
				else{
					int get = dayofmonth[month_t];
					if(month_t == 2 &&year_t%4==0 ) get++;
					if(day_t > get){
						p.error_st[1] = "Ngay khong hop le\0";
						p.check = false;
						p.error_color[1] = 4;
						return p;
					}
				}
			}
		// xu li loai 
		cout <<x++<<endl;
		if(loai!='N' && loai !='X') {
			p.error_st[4] = "Khong hop le    \0";
			p.check = false;
			p.error_color[4] = 4;
			return p;
		}
		cout <<x++<<endl;
			if(!Find_NV(DataNhanvien._nhanvien,MaNV)) {
			p.error_st[5] = "Khong tim thay  \0";
			p.check = false;
			p.error_color[5] = 4;
			return p;
			}
			if(p.check == true){
			
			strcpy(hd->soHD, soHD);
			strcpy(hd->day , ngay);
			strcpy(hd->month,thang);
			strcpy(hd->year , nam);
			hd->loai=loai;
			hd->_next = NULL;
			
			}
		return p;
}

// ct hoa don
struct ct_hoadon_error{
	char* error_st[5];
	int error_color[5];
	bool check = true;
};
ct_hoadon_error Check_CT_new(NodeCT* &hd,char loai,char MaVT[],char soluong[],char dongia[],char VAT[])
{
		ct_hoadon_error p;
		//xu li MaVT
		if(!Find_VT(DataVattu,MaVT)){
			p.check =false;
			p.error_st[0] = "Khong ton tai";
			p.error_color[0] = 4;
			return p;
		}
		// xu li soluong
		if(strlen(soluong)==0){
			p.check =false;
			p.error_st[1] = "Khong duoc rong";
			p.error_color[1] = 4;
		}
		else if(loai =='X'){
				int pos = Find_VT_return(DataVattu,MaVT);
				
				char *give = DataVattu._vattu[pos].soluongton;
				if(parseInt(soluong)>parseInt(give)){
					p.check = false;
					p.error_st[1] = "so luong ton ko du";
				}
				else p.error_st[1] = "Co the su dung   \0",p.error_color[1] = COLOR(0,255,0);
		}
		
		// xu li don gia
		if(strlen(dongia)==0){
			p.error_st[2] = "Khong duoc rong\0";
			p.check = false;
			p.error_color[2] = 4;
		}
		else p.error_st[2] = "Co the su dung   \0",p.error_color[2] = COLOR(0,255,0);
		
		// xu li VAT
		
			
			if(strlen(VAT) == 0){
				p.error_st[3] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[3] = 4;
			}
			else p.error_st[3] = "Co the su dung \0",p.error_color[3] = COLOR(0,255,0);
		

		
		
			if(p.check == true){
			
			strcpy(hd->MAVT, MaVT);
			strcpy(hd->soluong , soluong);
			strcpy(hd->Dongia,dongia);
			strcpy(hd->VAT , VAT);
			hd->_next = NULL;
			
			}
		return p;
}
