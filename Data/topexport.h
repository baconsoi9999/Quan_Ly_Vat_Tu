#include "Vattu.h"
#include "Nhanvien.h"
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
int Num_day(int ngay[], int thang[],int nam[]){
	int ans =0;
	for(int i=0;i<strlen(nam);i++) ans= ans*10 + nam[i]; 
	for(int i=0;i<strlen(thang);i++) ans= ans*10 + thang[i]; 
	for(int i=0;i<strlen(ngay);i++) ans= ans*10 + ngay[i]; 
	return ans;
}
int Number(char s[]){
	int ans = 0;
	for(int i=0;i<strlen(s);i++) ans= ans *10 + (s[i]-'0');
	return ans;
}
void duyetLNR(Tree t,int begin ,int end){
	if(t==NULL) return;
	for(NodeHD* p = t->nv.nv_HOADON.hdHead; p !=NULL;p = p->_next){
		int num = Num_day(p->thongtin.day,p->thongtin.month,p->thongtin.year);
		if(num>=begin && num <=end && (p->thongtin.loai == 'X' || p->thongtin.loai == 'x')){
			for(NodeCT* q = p->chitiet.ctHead ; q!=NULL ; q =q->_next ){
				int get = Number(q->thongtin.soluong);
				int pos = bsearch(Datavattu,q->thongtin.MAVT);
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
		ds_top.export_top[ds_top.num].MaVT = DataVattu._vattu[dda[i]].MAVT;
		ds_top.export_top[ds_top.num].TenVT = DataVattu._vattu[dda[i]].TENVT;
		ds_top.num++;
	}
	return ds_top;
}
void Xuat_export_top(Export_top ex,int x,int y,int c_line[]){
	outtextxy(x,y,ex.MaVT);
	outtextxy(x+c_line[0],y,ex.TenVT);
	outtextxy(x+c_line[1],y,ex.soluong);
}
void Print_top(DsExport_top ds,int x,int y,int c_line[]){
	for(int i=0;i<ds.num;i++){
	if()	Xuat_export_top(ds.export_top[i],x,y,page,c_line);
	}
}
