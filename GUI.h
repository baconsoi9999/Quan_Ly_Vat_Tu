//	#include "Data/Vattu.h"
//	#include "Data/Nhanvien.h"
//	#include "Data/HOADON.h"
//	#include "Data/CT_HOADON.H"
	#include <E:\#PTIT CAU TRUC DU LIEU GIAI THUAT\de tai CTDLGT\Quan_Ly_Vat_Tu\conponentBGI.h>
	#include <iostream>
	#include <string>
	
	using namespace std; // Just using for testing

Button Menu_Button(1,APP_LEFT, APP_TOP, APP_LEFT+ 400, APP_TOP+40, BLUE);
Tab_List Menu_Tab( Menu_Button.left, Menu_Button.bottom+1, Menu_Button.right, 2, WHITE, 3);	

void Show_Menu_List()
{
	Menu_Tab.show();
	bool flag= true;
	while(flag)
	{
		int x=-1;
		int y=-1;
		getmouseclick(WM_LBUTTONDOWN,x,y);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if ((x==-1)&&(y==-1)) continue;
		cout <<x <<" :: " <<y <<endl;	// Delete this line when release!!!
		short int s_f=R[y][x];
		if((s_f==Menu_Button.ID)||(s_f==5)||(s_f==10)||(s_f==15))
		{
			
			Menu_Tab.cancel();
			if(s_f!=Menu_Button.ID) F_R[s_f]();
			flag= false;
		}	
	}
	
}

void Show_VT()
{
	cout <<"vat tu page open" <<endl; // Delete this line when release!!!
}

void Show_NV()
{
	cout <<"nhan vien page open" <<endl; // Delete this line when release!!!

}

void Show_HD ()
{
	cout <<"hoa don page open" <<endl; // Delete this line when release!!!

}
	
void main_frame()
{
	
	/* Draw app background*/
	Frame m_f(APP_LEFT, APP_TOP, APP_RIGHT, APP_BOTTOM,WHITE);
	m_f.Show();
	setfillstyle(1,LIGHTBLUE);
	bar(m_f.left,m_f.bottom-100 , m_f.right, m_f.bottom);
	
	/*Adding menu tab contents*/

	Menu_Tab.List_content_tile[0] = "Quan ly vat tu";
	Menu_Tab.List_content_ID[0] = 5;
	F_R[5]=Show_VT;
	Menu_Tab.List_content_tile[1] = "Quan ly nhan vien";
	Menu_Tab.List_content_ID[1] = 10;
	F_R[10]=Show_NV;
	Menu_Tab.List_content_tile[2] = "Quan ly hoa don";
	Menu_Tab.List_content_ID[2] = 15;
	F_R[15]=Show_HD;
	//
	for(int i = 0; i<Menu_Tab.NUMBER_OF_LINE;i++)
	cout<<"&*ct:::" <<Menu_Tab.List_content_ID[i] <<endl; // Delete this line when release!!!
	/*Adding Menu Button ID*/
	F_R[Menu_Button.ID]=Show_Menu_List;
	
	Menu_Button.show(false);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setbkcolor(Menu_Button.color);
	outtextxy(Menu_Button.left+20,(Menu_Button.bottom+Menu_Button.top - 16)/2,"MENU");

	
}

	
