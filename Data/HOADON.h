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
	NodeHD* hdHead;
};
void init_hd(DsHOADON &hd){
	hd.hdHead = NULL;
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
}
#define CTHEAD hd.hdHead->chitiet.ctHead
void DeleteHD(DsHOADON &hd,char maVT[]){
	if(strcmp(CTHEAD -> MAVT , maVT)==0){
		CTHEAD = CTHEAD->_next;
	}
	else{
		for(NodeCT* p = CTHEAD ;p!=NULL ; p = p->_next){
			if(strcmp(p->_next->MAVT , maVT)==0){
				NodeCT* q = new NodeCT;
				q = p->_next;
				p->_next = q->_next;
				delete q;
				return;
			}
		}
	}
}

