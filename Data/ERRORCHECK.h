	#include "Nhanvien.h"
	#include "Vattu.h"
	#include <algorithm>
// vat tu error
struct vattu_error{
	char* error_st[4];
	int error_color[4];
	bool check = true;
};
vattu_error Check_VT_new(Vattu &vt,char MaVT[], char TVT[], char Donvi[], char sluong[])
{
		vattu_error p;
	cout<<"\nda goi\n";
		// xu li ma vat tu
		if(Find_VT(DataVattu,MaVT)>0) {
			p.error_st[0] = "Vat tu da ton tai\0";
			cout <<"\nco vao tahng nay\n";
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
			strcpy(nv.thongtin.MANV, MaNV);
			strcpy(nv.thongtin.HO, Ho);
			strcpy(nv.thongtin.TEN , Ten);
			strcpy(nv.thongtin.PHAI,Phai);
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
			strcpy(nv.thongtin.MANV, MaNV);	
			strcpy(nv.thongtin.HO, Ho);
			strcpy(nv.thongtin.TEN, Ten);
			strcpy(nv.thongtin.PHAI,Phai);
		}
		return p;
}
// error hoa don
bool Find_HD(Tree &root,char soHD[]){
	if(root == NULL) return false;
//	cout<<"1:::"<<root->nv.MANV<<endl;
	for(NodeHD* p = root->nv.nv_HOADON.hdHead;p!=NULL;p = p->_next){
		if(strcmp(p->thongtin.soHD,soHD)==0) return true;
	}
	return (Find_HD(root->left,soHD) | Find_HD(root->right,soHD) );
}
struct hoadon_error{
	char* error_st[6];
	int error_color[6];
	bool check = true;
};
int dayofmonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
hoadon_error Check_HD_new(Thongtin_HD &hd, char SOHD[], char ngay[], char thang[], char nam[], char loai,char MaNV[])
{
//	int x = 4;

		hoadon_error p;

		for(int i =0;i<6;i++)

		{

			p.error_st[i]="\0";

			p.error_color[i]=4;

		}

	//	cout <<x++<<endl;

		int month_t = parseInt(thang);

	//	cout <<"m::"<<month_t <<endl;

		int year_t  = parseInt(nam);

	//	cout <<"y::" <<year_t<<endl;

		int day_t   = parseInt(ngay);

	//	cout <<"d::"<<day_t<<endl;

	//	cout <<x++<<endl;

		// xu li ma vat tu

		if(strlen(SOHD)==0){

		//	cout <<x++<<endl;

			p.error_st[0] = "Khong duoc rong\0";

			p.check = false;

			p.error_color[0] = 4;

			return p;

		}

		else{

			if(Find_HD(DataNhanvien._nhanvien,SOHD)) {

			p.error_st[0] = "So hoa don trung\0";

			p.check = false;

			p.error_color[0] = 4;

			return p;

			}

		}

		// xu li nam

	//	cout <<x++<<endl;

			int len_nam = strlen(nam);

			if(len_nam == 0){

			 	p.error_st[1] = "Ngay khong hop le\0";

						p.check = false;

						p.error_color[1] = 4;

						return p;

			 }

			 

		//xu li thang

	//	cout <<"error_st:::"<<p.error_st[1]<<endl;

			int len_thang = strlen(thang);

		 {

				if(month_t == 0){

					p.error_st[1] = "Ngay khong hop le\0";

						p.check = false;

						p.error_color[1] = 4;

						return p;

				}

				else{

					if(parseInt(thang)>12){

						p.error_st[1] = "Ngay khong hop le\0";

						p.check = false;

						p.error_color[1] = 4;

						return p;

					}

				}

			}

		//cout <<"error_st:::"<<p.error_st[1]<<endl;

		// xu li ngay

	//	cout <<x++<<endl;

			int len_ngay = strlen(ngay);

			{

				if(day_t == 0){

					p.error_st[1] = "Ngay khong hop le\0";

						p.check = false;

						p.error_color[1] = 4;

						return p;

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

		//	cout <<"error_st:::"<<p.error_st[1]<<endl;

		// xu li loai 

	//	cout <<x++<<endl;

		if(loai=='/0') {

			p.error_st[4] = "Loai Khong hop le    \0";

			p.check = false;

			p.error_color[4] = 4;

			return p;

		}

		//cout <<"error_st:::4"<<p.error_st[4]<<endl;

		//	if(Find_NV(DataNhanvien._nhanvien,MaNV)) cout<<"tim thay ::::";

			if(!Find_NV(DataNhanvien._nhanvien,MaNV)) {

			//	cout<<"deo tim thay::";

			p.error_st[5] = "Khong tim thay  \0";

			p.check = false;

			p.error_color[5] = 4;

			return p;

			}

		//	cout <<"error_st:::"<<p.error_st[5]<<endl;

			if(p.check == true){

		//	cout<<"1???"<<SOHD;
		//	memset(hd.soHD,NULL,sizeof(hd.soHD));
			strcpy(hd.soHD, SOHD);
		//	cout<<"3>??";
			strcpy(hd.day , ngay);
		//	cout<<"4????";
			strcpy(hd.month,thang);
		//	cout<<"5????";
			strcpy(hd.year , nam);
		//	cout<<"6????";
			hd.loai = loai;
			cout<<"loai::4"<<loai<<endl;
		//	cout<<"2????";
			}

		return p;

}
// ct hoa don
struct ct_hoadon_error{
	char* error_st[5];
	int error_color[5];
	bool check = true;
};
ct_hoadon_error Check_CT_new(Thongtin_CT &hd,char MaVT[],char soluong[],char dongia[],char VAT[],char loai)
{
		ct_hoadon_error p;
		//xu li MaVT
		for(int i =0;i<5;i++)
		{
			p.error_st[i]="\0";
			p.error_color[i]=4;
		}
		if(Find_VT(DataVattu,MaVT)==0){
			p.check =false;
			cout<<"\nco vao\n";
			p.error_st[0] = "Khong ton tai";
			p.error_color[0] = 4;
			return p;
		}
		// xu li soluong
		cout<<"loai nhan dc "<<loai<<"::::";	
		if(strlen(soluong)==0){
			p.check =false;
			p.error_st[1] = "Khong duoc rong";
			p.error_color[1] = 4;
		}	
		else if(loai =='X'|| loai == 'x'){
			int pos = Find_VT_return(DataVattu,MaVT);
			//	cout<<"::::co vao loai::::";
				cout<<"pos ::"<<pos<<endl;
				char *give = DataVattu._vattu[pos].soluongton;
				cout<<"give"<<give<<endl;
				cout<<"parseintsluong"<<parseInt(soluong)<<endl;
				cout<<"parseintgive"<<parseInt(give)<<endl;
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
			strcpy(hd.MAVT, MaVT);
			strcpy(hd.soluong , soluong);
			strcpy(hd.Dongia,dongia);
			strcpy(hd.VAT , VAT);
			//hd->_next = NULL;
			}
		return p;
}
struct day_error{
	char* error_st[5];
	int error_color[5];
	bool check = true;
};
day_error Check_day(int &number_b,char day_b[],char  month_b[],char year_b[],int &number_e,char day_e[],char  month_e[],char year_e[])
{
	   	   
			day_error p;
			for(int i =0;i<5;i++)
		{
			p.error_st[i]="\0";
			p.error_color[i]=4;
		}
			if(parseInt(year_b) == 0){
			 	p.error_st[0] = "Ngay khong hop le\0";
 
						p.check = false;
 
						p.error_color[0] = 4;
 
						return p;
			}
 
		 {
 
				if(parseInt(month_b) == 0){
 
					p.error_st[0] = "Ngay khong hop le\0";
 
						p.check = false;
 
						p.error_color[0] = 4;
 
						return p;
 
				}
 
				else{
 
					if(parseInt(month_b)>12){
 
						p.error_st[0] = "Ngay khong hop le\0";
 
						p.check = false;
 
						p.error_color[0] = 4;
 
						return p;
 
					}
 
				}
 
			}
				if(parseInt(day_b) == 0){
 
					p.error_st[0] = "Ngay khong hop le\0";
 
						p.check = false;
 
						p.error_color[0] = 4;
 
						return p;
 
				}
 
				else{
 
					int get = dayofmonth[parseInt(month_b)];
 
					if(parseInt(month_b) == 2 &&parseInt(year_b)%4==0 ) get++;
 
					if(parseInt(day_b) > get){
 
				p.error_st[0] = "Ngay khong hop le\0";
 
				p.check = false;
 
				p.error_color[0] = 4;
				return p;
			}
		}
 
			if(parseInt(year_e) == 0){
			 	p.error_st[1] = "Ngay khong hop le\0";
 
						p.check = false;
 
						p.error_color[1] = 4;
 
						return p;
			}
 
		 {
 
				if(parseInt(month_e) == 0){
 
					p.error_st[1] = "Ngay khong hop le\0";
 
						p.check = false;
 
						p.error_color[1] = 4;
 
						return p;
 
				}
 
				else{
 
					if(parseInt(month_e)>12){
 
						p.error_st[1] = "Ngay khong hop le\0";
 
						p.check = false;
 
						p.error_color[1] = 4;
 
						return p;
 
					}
 
				}
 
			}
				if(parseInt(day_e) == 0){
 
					p.error_st[1] = "Ngay khong hop le\0";
 
						p.check = false;
 
						p.error_color[1] = 4;
 
						return p;
 
				}
 
				else{
 
					int get = dayofmonth[parseInt(month_e)];
 
					if(parseInt(month_e) == 2 &&parseInt(year_e)%4==0 ) get++;
 
					if(parseInt(day_e) > get){
 
				p.error_st[1] = "Ngay khong hop le\0";
 
				p.check = false;
 
				p.error_color[1] = 4;
				return p;
			}
		}
 
	if(p.check == true){
		number_b = Num_day(day_b,month_b,year_b);
		number_e = Num_day(day_e,month_e,year_e);
		if(number_b>number_e){
			p.error_st[0] = "Ngay khong hop le\0";
			p.check = false;
			p.error_color[0] = 4;
			return p;
		}
 
	}
 
}


int Number(char s[]){
	int ans = 0;
	for(int i=0;i<strlen(s);i++) ans= ans *10 + (s[i]-'0');
	return ans;
}

//  top export
int dd[100];
int dda[100];
int bsearch(DsVattu ds,char MaVT[]){
	int left = 0,right = ds.num;
	int mid;
	while(left!=right){
		mid = (left+right)/2;
		if(strcmp(MaVT,ds._vattu[mid].MAVT)==0) return mid;
		if(strcmp(MaVT,ds._vattu[mid].MAVT)>0) left = mid;
		else right = mid;
	}	
}
struct Export_top{
	int soluong;
	char MaVT[100];
	char TenVT[100];
};
struct DsExport_top{
	Export_top export_top[100];
	int num =0;
};


void duyetLNR(Tree t,int begin ,int end){
	if(t==NULL) return;
	for(NodeHD* p = t->nv.nv_HOADON.hdHead; p !=NULL;p = p->_next){
		int num = Num_day(p->thongtin.day,p->thongtin.month,p->thongtin.year);
		if(num>=begin && num <=end && (p->thongtin.loai == 'X' || p->thongtin.loai == 'x')){
			for(NodeCT* q = p->chitiet.ctHead ; q!=NULL ; q =q->_next ){
				int get = Number(q->thongtin.soluong);
				int pos = bsearch(DataVattu,q->thongtin.MAVT);
				dd[pos] += get;
			}
		}
	}
	duyetLNR(t->left,begin,end);
	duyetLNR(t->right,begin,end);
}
void init_array(int a[],int n){
	for(int i=0;i<n;i++) a[i] = i;
}
bool cmp(int a,int b){
	return dd[a]<dd[b];
}
DsExport_top Top_Export(DsVattu ds ,int begin,int end){
	memset(dd,0,sizeof(dd));
	DsExport_top ds_top;
	duyetLNR(DataNhanvien._nhanvien,begin,end);
	init_array(dda,DataVattu.num);
	sort(dda,dda+DataVattu.num,cmp);
	for(int i=0;i<DataVattu.num;i++){
		if(dd[dda[i]]==0) break;
		ds_top.export_top[ds_top.num].soluong =  dd[dda[i]];
		strcpy(ds_top.export_top[ds_top.num].MaVT , DataVattu._vattu[dda[i]].MAVT);
		strcpy(ds_top.export_top[ds_top.num].TenVT ,DataVattu._vattu[dda[i]].TENVT);
		ds_top.num++;
	}
	return ds_top;
}
void Xuat_export_top(Export_top ex,int x,int y,unsigned short int c_line[]){
	outtextxy(x,y,ex.MaVT);
	outtextxy(x+c_line[0],y,ex.TenVT);
	char sl[100] ;
	itoa(ex.soluong,sl,10);
	outtextxy(x+c_line[1],y,sl);
}
void Print_top(DsExport_top ds,int x,int y,unsigned short int c_line[]){
	for(int i=0;i<ds.num;i++){
		Xuat_export_top(ds.export_top[i],x,y,c_line);
	}
}
