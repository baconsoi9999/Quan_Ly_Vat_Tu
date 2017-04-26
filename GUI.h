//	#include "Data/Vattu.h"
//	#include "Data/Nhanvien.h"
//	#include "Data/HOADON.h"
//	#include "Data/CT_HOADON.H"
	#include <E:\#PTIT CAU TRUC DU LIEU GIAI THUAT\de tai CTDLGT\Quan_Ly_Vat_Tu\conponentBGI.h>
	#include <iostream>
	#include <string>
	
	
	using namespace std; // Just using for testing
Frame m_f(APP_LEFT, APP_TOP, APP_RIGHT, APP_BOTTOM,COLOR(255,255,255));

Button Menu_Button(1,APP_LEFT, APP_TOP, APP_LEFT+ 400, APP_TOP+40, COLOR(0,0,255));
Button New_Button(0, m_f.left+20, m_f.bottom-80, m_f.left+220, m_f.bottom-20, COLOR(0,255,0));

Tab_List Menu_Tab( Menu_Button.left, Menu_Button.bottom, Menu_Button.right,2, 15 , 4);	

void main_frame()
{
	/* Draw app background*/
	m_f.Show();
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-100 , m_f.right, m_f.bottom);
	
	for(int i = 0; i<Menu_Tab.NUMBER_OF_LINE;i++)		  // Delete this line when release!!!
	cout<<"&*ct:::" <<Menu_Tab.List_content_ID[i] <<endl; // Delete this line when release!!!

	Menu_Button.show(false);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setbkcolor(Menu_Button.color);
	setcolor(15);
	outtextxy(Menu_Button.left+20,(Menu_Button.bottom+Menu_Button.top - 16)/2,"MENU");
}

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
		delay(0.0001);
		if ((x==-1)&&(y==-1)) continue;
		cout <<x <<" :: " <<y <<"--" <<R[y][x]<<endl;	// Delete this line when release!!!
		
		short int s_f=R[y][x];
		if((s_f==Menu_Button.ID)||(s_f==5)||(s_f==10)||(s_f==15)||(s_f==20))
		{
			
			Menu_Tab.cancel();
			if(s_f!=Menu_Button.ID) F_R[s_f]();
			flag= false;
		}	
	}
	
}

void Show_VT()
{
	main_frame();
	cout <<"vat tu page open" <<endl; // Delete this line when release!!!
	New_Button.show(false);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setbkcolor(New_Button.color);
	setcolor(15);
	outtextxy((New_Button.left+New_Button.right - 3*16)/2, (New_Button.top+New_Button.bottom - 16)/2, "NEW");
	
}


void Show_NV()
{
	main_frame();
	cout <<"nhan vien page open" <<endl; // Delete this line when release!!!
}

void Show_HD ()
{
	main_frame();
	cout <<"hoa don page open" <<endl; // Delete this line when release!!!
}

void Show_Dic()
{
	cout <<"dictionary show" <<endl;	
}
void GUI_Init()
{
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
	Menu_Tab.List_content_tile[3] = "Tra cuu ma vat tu";
	Menu_Tab.List_content_ID[3] = 20;
	F_R[20]=Show_Dic;
	/*Adding Menu Button ID*/
	F_R[Menu_Button.ID]=Show_Menu_List;
}	


	
