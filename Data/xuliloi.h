#include <iostream>
struct vattu_error{
	char* error_st[4];
	bool check = true;
};
using namespace std;
vattu_error Check_VT(Vattu &vt,char* MaVT, char* TVT, char* Donvi, char* sluong){
		vattu_error p;
		// xu li ma vat tu
		if(Find(ds,MaVT)) {
			p[0].error_st[0] = "Vat tu da ton tai!!!";
			p.check = false;
		}
		else p[0].error_st[0] = "Ma vat tu co the su dung";
		// xu li ten vat tu
		{
			int len_TVT = strlen(TVT);
			if(len_TVT == 0) {
				p[1].error_st = "Ten vat tu khong duoc rong";
				p.check = false;
			}
			else p[1].error_st = "Ten vat tu co the su dung";
		}
		// xu li Don vi
		{
			int len_DV = strlen(Donvi);
			if(len_DV == 0){
				p[2].error_st = "Ten vat tu khong duoc rong";
				p.check = false;
			}
			else p[2].error_st = "Co the su dung";
		}
		//xu li so luong
		{
			int len_slt = strlen(sluong);
			if(len_slt == 0){
				p[3].error_st = "Khong duoc rong";
				p.check = false;
			}
			else p[3].error_st = "Co the su dung";
		}
		if(p.check == true){
			vt.MAVT = MaVT;
			if(TVT[len_TVT-1] == ' ') TVT[len_TVT-1] = NULL;
			vt.TVT = TVT;
			if(Donvi[len_DV-1] == ' ') Donvi[len_DV-1] = NULL;
			vt.DVT = Donvi;
			int num = 0;
			for(int i=0;i<len_slt ;i++){
				num = num*10 + (sluong[i] - '0');
			}
			vt.soluongton = num; 
		}
		return p;
}

int main(){
	
}
