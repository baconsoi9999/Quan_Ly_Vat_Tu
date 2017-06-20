// danh sach hoa don (danh sach lien ket don)
#include "CT_HOADON.h"
struct Thongtin_HD{
	char soHD[100];
	char day[2];
	char month[2];
	char year[4];
	char loai;
};
struct NodeHD{
	Thongtin_HD thongtin;
	CT_HOADON chitiet;
	NodeHD* _next;
};
struct DsHOADON{
	int num;
	NodeHD* hdHead;
};
void init_hd(DsHOADON &hd){
	hd.hdHead = NULL;
	hd.num =0;
}
NodeHD* GetNode_hd(Thongtin_HD tt,CT_HOADON ct){
	NodeHD* p;
	p->thongtin = tt;
	p->chitiet = ct;
	p->_next = NULL;
}
void addTail_HD(DsHOADON &hd,NodeHD* p){
	if(hd.hdHead == NULL) hd.hdHead = p;
	else{
		NodeHD* q = hd.hdHead;
		while(q != NULL){
			if(q->_next == NULL){
				q->_next = p;
				break;
			}
			else q = q->_next;
		}
	}
	hd.num++;
}
#define CTHEAD hd.hdHead->chitiet.ctHead
void DeleteHD(DsHOADON &hd,char maVT[]){
	if(strcmp(CTHEAD -> thongtin.MAVT , maVT)==0){
		CTHEAD = CTHEAD->_next;
	}
	else{
		for(NodeCT* p = CTHEAD ;p!=NULL ; p = p->_next){
			if(strcmp(p->_next->thongtin.MAVT , maVT)==0){
				NodeCT* q = new NodeCT;
				q = p->_next;
				p->_next = q->_next;
				delete q;
				return;
			}
		}
	}
}
void Print_thongtin_HD(Thongtin_HD tt,int x ,int y,unsigned short int c_line[]){
	outtextxy(x,y,tt.soHD);
	outtextxy(x+c_line[0],y,tt.day);
	outtextxy(x+c_line[1],y,tt.month);
	outtextxy(x+c_line[2],y,tt.year);
	char loai_s [1];
	loai_s[0] = tt.loai;
	outtextxy(x+c_line[3],y,loai_s);
}
