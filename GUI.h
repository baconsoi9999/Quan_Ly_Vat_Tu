	#include "Data/Vattu.h"
	#include "Data/Nhanvien.h"
//	#include "Data/HOADON.h"
//	#include "Data/CT_HOADON.H"
	#include <E:\#PTIT CAU TRUC DU LIEU GIAI THUAT\de tai CTDLGT\Quan_Ly_Vat_Tu\conponentBGI.h>
	#include <iostream>
	#include <string.h>
	
	
	using namespace std;
	 // Just using for testing

int CURRENT_STRAGE;	
unsigned int VT_ID=100,NV_ID=200,HD_ID=300;
int ps;
Frame m_f(APP_LEFT, APP_TOP, APP_RIGHT, APP_BOTTOM,COLOR(255,255,255));

Panel active_bar(APP_LEFT,APP_BOTTOM-130,APP_RIGHT,APP_BOTTOM);

Button Exit_App(1,APP_RIGHT-58,APP_TOP,APP_RIGHT,APP_TOP+29,4,2," X ");

Button Menu_Button(2,APP_LEFT, APP_TOP, APP_LEFT+ 399, APP_TOP+39, COLOR(0,0,255),3,"MENU");

Button New_Button(0, Menu_Button.right+10, APP_TOP,Menu_Button.right+160, APP_TOP+39, COLOR(0,255,0),3," NEW\0");//change ID not 0

Button Save_Button(0,New_Button.right +5, APP_TOP, New_Button.right +165, APP_TOP+39, COLOR(0,0,220),3," SAVE\0");

char*Menu_Content_Tile[5]={"Trang chu\0","Quan ly vat tu\0","Quan ly nhan vien\0","Quan ly hoa don\0","Tra cuu ma"};
Tab_List Menu_Tab( Menu_Button.left, Menu_Button.bottom, Menu_Button.right,2, 15 , 5, Menu_Content_Tile);	
/*
FONT SIZE: 2
LINE SPACE: 47
NUMBER OF LINES: 4
*****
*/
unsigned short int VT_Book_c_line[4]={71,349,713,985};
char* VT_Book_c_tile[5]={"STT\0","Ma Vat tu\0","Ten Vat tu\0", "don vi tinh\0", "SL ton\0"};
char* VT_Book_l_tile[10]={"1\0","2\0","3\0","4\0","5\0","6\0","7\0","8\0","9\0","10\0"};
Book VT_Book(APP_LEFT+5, Menu_Button.bottom+5, APP_RIGHT-5 ,2 ,COLOR(234,244,253),COLOR(83,174,242), 10,5,VT_Book_c_line,VT_Book_c_tile,VT_Book_l_tile);
//new VAT TU function
unsigned short int VT_new_c_line[3]={278,642,914};
char* VT_new_c_tile[4]={"Ma Vat tu\0","Ten Vat tu\0", "don vi tinh\0", "SL ton\0"};
Array_Table VT_new(APP_LEFT+5, APP_BOTTOM-120, APP_RIGHT-100, APP_BOTTOM-40, 2,COLOR(234,244,253),COLOR(0,255,0), 4, VT_new_c_line, VT_new_c_tile);
Button VT_new_save(125,APP_RIGHT-95, APP_BOTTOM-120,APP_RIGHT-5,APP_BOTTOM-82,COLOR(0,0,220),2," OK\0");
Button VT_new_cancel(126,APP_RIGHT-95,APP_BOTTOM-78,APP_RIGHT-5,APP_BOTTOM-40,COLOR(0,0,220),2," HUY\0");
//select table
Array_Table VT_Select(APP_LEFT+5, APP_BOTTOM-120, APP_RIGHT-100, APP_BOTTOM-40, 2,COLOR(234,244,253),COLOR(0,255,0), 4, VT_new_c_line, VT_new_c_tile);
Button VT_Select_save(116,APP_RIGHT-95, APP_BOTTOM-120,APP_RIGHT-5,APP_BOTTOM-82,COLOR(0,0,220),2," OK\0");
Button VT_Select_cancel(117,APP_RIGHT-95,APP_BOTTOM-78,APP_RIGHT-5,APP_BOTTOM-40,COLOR(0,0,220),2," XOA\0");

/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
unsigned short int NV_Book_c_line[4]={71,349,713,985};
char* NV_Book_c_tile[5]={"STT\0","Ma Nhan vien\0","Ho \0", "Ten\0", "Gioi tinh\0"};
char* NV_Book_l_tile[10]={"1\0","2\0","3\0","4\0","5\0","6\0","7\0","8\0","9\0","10\0"};
Book NV_Book(APP_LEFT+5, Menu_Button.bottom+5, APP_RIGHT-5 ,2 ,COLOR(234,244,253),COLOR(83,174,242), 10,5,NV_Book_c_line,NV_Book_c_tile,NV_Book_l_tile);

unsigned short int NV_new_c_line[3]={278,642,914};
char* NV_new_c_tile[4]={"Ma Nhan vien\0","Ho\0", "Ten\0", "Gioi tinh\0"};
Array_Table NV_new(APP_LEFT+5, APP_BOTTOM-120, APP_RIGHT-100, APP_BOTTOM-40, 2,COLOR(234,244,253),COLOR(0,255,0), 4, NV_new_c_line, NV_new_c_tile);
Button NV_new_save(225,APP_RIGHT-95, APP_BOTTOM-120,APP_RIGHT-5,APP_BOTTOM-82,COLOR(0,0,220),2," OK\0");
Button NV_new_cancel(226,APP_RIGHT-95,APP_BOTTOM-78,APP_RIGHT-5,APP_BOTTOM-40,COLOR(0,0,220),2," HUY\0");
//Select table
Nhanvien buf;
Array_Table NV_Select(APP_LEFT+5, APP_BOTTOM-120, APP_RIGHT-100, APP_BOTTOM-40, 2,COLOR(234,244,253),COLOR(0,255,0), 4, NV_new_c_line, NV_new_c_tile);
Button NV_Select_save(216,APP_RIGHT-95, APP_BOTTOM-120,APP_RIGHT-5,APP_BOTTOM-82,COLOR(0,0,220),2," OK\0");

/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
//Tab_List HD_List(APP_LEFT+5, Menu_Button.bottom+39+5, APP_RIGHT-5 ,1 ,COLOR(254,244,205), 10,l_tile);
/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
Dialog Dic_Dialog(401,402,APP_LEFT+5, Menu_Button.bottom+5, APP_RIGHT-5, APP_BOTTOM-135,COLOR(255,255,255),"Bang tra cuu vat tu\0");

void menu_slash(char* menu_content_tile)
{
	setcolor(15);
	line(Menu_Button.left+136, Menu_Button.top,Menu_Button.left+136+20,Menu_Button.top+20);
	line( Menu_Button.left+136+20, Menu_Button.top+20,Menu_Button.left+137, Menu_Button.bottom);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	setbkcolor(Menu_Button.color);
	setcolor(15);
	outtextxy(Menu_Button.left+160,(Menu_Button.bottom+Menu_Button.top - 24)/2, menu_content_tile);
}
void main_frame()
{
	/* Draw app background*/
	m_f.Show();
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-130 , m_f.right, m_f.bottom);
	
	for(int i = 0; i<Menu_Tab.NUMBER_OF_LINE;i++)		  // Delete this line when release!!!
	cout<<"&*ct:::" <<Menu_Tab.List_content_ID[i] <<endl; // Delete this line when release!!!	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	setbkcolor(Menu_Button.color);
	setcolor(15);
	Menu_Button.show();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	Exit_App.show();
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
		delay(0);
		if ((x==-1)&&(y==-1)) continue;
		cout <<x <<" :: " <<y <<"--" <<R[y][x]<<endl;	// Delete this line when release!!!
		
		short int s_f=R[y][x];
		if(
		(s_f==Menu_Button.ID)
		||(s_f==Menu_Tab.List_content_ID[0])
		||(s_f==Menu_Tab.List_content_ID[1])
		||(s_f==Menu_Tab.List_content_ID[2])
		||(s_f==Menu_Tab.List_content_ID[3])
		||(s_f==Menu_Tab.List_content_ID[4])
		)
		{
			Menu_Tab.cancel();
			if(s_f!=Menu_Button.ID) F_R[s_f]();
			flag= false;
		}	
		else
		{
			Menu_Tab.cancel();
			flag= false;
		}
	}	
}
/*home*/
void Home()
{
	main_frame();
}
/*VAT TU  fuction*/
void new_MVT()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerCode(VT_new.List_content[0],16,VT_new.left+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[0]);
}
void new_TVT()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerString(VT_new.List_content[1],21,VT_new.left+VT_new.column[0]+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[1]);
}
void new_DVTVT()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerString(VT_new.List_content[2],16,VT_new.left+VT_new.column[1]+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[2]);
}
void new_SLTVT()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerNum(VT_new.List_content[3],9,VT_new.left+VT_new.column[2]+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[3]);
}
void cancel_VT_new()
{
	VT_new.free_Table();
	VT_new.cancel();
	active_bar.cancel();
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-130 , m_f.right, m_f.bottom);
	
}
void save_VT_new()
{
	vattu_error error;
	Vattu pre_add;
	error = Check_VT_new(pre_add,VT_new.List_content[0],VT_new.List_content[1],VT_new.List_content[2],VT_new.List_content[3]);
	if(error.check)
	{
	
	FindandInsert(DataVattu,pre_add);
	cancel_VT_new();
	VT_Book.show();
	lietkeVattu(DataVattu,
	    (VT_Book.CURENT_PAGE-1)*10,min((VT_Book.CURENT_PAGE*10-1),(DataVattu.num-1)),
    	VT_Book.left,VT_Book.top_main,10,VT_Book_c_line);
	} 
	else 
	{
		setbkcolor(getpixel(VT_new.left,VT_new.bottom+5));
		setcolor(4);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
		setcolor(error.error_color[0]);
		outtextxy(VT_new.left,VT_new.bottom+5,error.error_st[0]);
		for(int i = 1; i<4;i++)
		{
			setcolor(error.error_color[i]);
			outtextxy(VT_new.left+VT_new_c_line[i-1],VT_new.bottom+5,error.error_st[i]);
		}
	}
	
	
}
void Show_VT_new()
{
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-130 , m_f.right, m_f.bottom);
	
	if(active_bar.is_active) active_bar.cancel();
	if(VT_new.is_active) VT_new.cancel();
	active_bar.Show();
	VT_new.free_Table();
	VT_new_save.show();//button
	VT_new_cancel.show();//button
	VT_new.show();
}

void Select_MVT()
{
	setbkcolor(VT_Select.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	char scan[100];
	
	memset(scan,NULL,sizeof(scan));
	strcpy(scan ,DataVattu._vattu[ps].MAVT);
//	int leng = strlen(scan);
//	for(int i=leng;i<100;i++){
//		scan[i] = '/0';
//	}
	strcpy(VT_Select.List_content[0],scan);
	ScannerCode(VT_Select.List_content[0],16,VT_Select.left+5,(VT_Select.top_main+VT_Select.bottom-textheight("S"))/2,VT_Select.List_content_ID[0]);
//strcpy(DataVattu._vattu[ps].MAVT,scan);
	
	cout<<"listcontent 2 ::::"<<VT_Select.List_content[0]<<endl;
}
void Select_TVT()
{
	setbkcolor(VT_Select.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	char scan[100];
	memset(scan,NULL,sizeof(scan));
	strcpy(scan ,DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[1],scan);
	ScannerString(VT_Select.List_content[1],21,VT_new.left+VT_new.column[0]+5,(VT_Select.top_main+VT_Select.bottom-textheight("S"))/2,VT_Select.List_content_ID[1]);
//	strcpy(DataVattu._vattu[ps].TENVT,scan);

}
void Select_DVTVT()
{
	setbkcolor(VT_Select.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	char scan[100];
	memset(scan,NULL,sizeof(scan));
	strcpy(scan ,DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[2],scan);
	ScannerString(VT_Select.List_content[2],9,VT_new.left+VT_new.column[1]+5,(VT_Select.top_main+VT_Select.bottom-textheight("S"))/2,VT_Select.List_content_ID[2]);
//	strcpy(DataVattu._vattu[ps].DVT,scan);
	
	
}
void cancel_VT_seclect()
{
	deleteVattu(ps,DataVattu);
	VT_Book.TOTAL_PAGE=  DataVattu.num/10+ (DataVattu.num%10!=0) ;
	VT_Select.cancel();
	active_bar.cancel();
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-130 , m_f.right, m_f.bottom);
	VT_Book.show();
	lietkeVattu(DataVattu,
	    (VT_Book.CURENT_PAGE-1)*10,min((VT_Book.CURENT_PAGE*10-1),(DataVattu.num-1)),
    	VT_Book.left,VT_Book.top_main,10,VT_Book_c_line);
    VT_Select.free_Table();
	
}
void save_VT_seclect()
{
	vattu_error error;
	Vattu pre_add;
	cout<<"listcontent 2 ::::"<<VT_Select.List_content[0]<<" listcontent 1 :::"<<VT_Select.List_content[1]<<endl;
	error = Check_VT_seclect(pre_add, VT_Select.List_content[0], VT_Select.List_content[1], VT_Select.List_content[2], VT_Select.List_content[3],ps);
	if(error.check)
	{
	
	cancel_VT_seclect();
	FindandInsert(DataVattu,pre_add);
	VT_Book.show();
	lietkeVattu(DataVattu,
	    (VT_Book.CURENT_PAGE-1)*10,min((VT_Book.CURENT_PAGE*10-1),(DataVattu.num-1)),
    	VT_Book.left,VT_Book.top_main,10,VT_Book_c_line);
    
	} 
	else 
	{
		setbkcolor(getpixel(VT_new.left,VT_new.bottom+5));
		setcolor(4);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
		setcolor(error.error_color[0]);
		outtextxy(VT_new.left,VT_new.bottom+5,error.error_st[0]);
		for(int i = 1; i<4;i++)
		{
			setcolor(error.error_color[i]);
			outtextxy(VT_new.left+VT_new_c_line[i-1],VT_new.bottom+5,error.error_st[i]);
		}
	}
	
	
}
void VT_Book_line1()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 0;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}
void VT_Book_line2()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 1;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}
void VT_Book_line3()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 2;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}
void VT_Book_line4()
{

	ps = (VT_Book.CURENT_PAGE-1)*10 + 3;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{	if(active_bar.is_active) active_bar.cancel();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}
void VT_Book_line5()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 4;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}
void VT_Book_line6()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 5;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}
void VT_Book_line7()
{

	ps = (VT_Book.CURENT_PAGE-1)*10 + 6;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}
void VT_Book_line8()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 7;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{
	if(active_bar.is_active) active_bar.cancel();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}
void VT_Book_line9()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 8;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{
	if(active_bar.is_active) active_bar.cancel();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}
void VT_Book_line10()
{
	ps = (VT_Book.CURENT_PAGE-1)*10 + 9;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{
	if(active_bar.is_active) active_bar.cancel();
strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}

void next_VT_Book()
{
	VT_Book.next_PAGE();
	lietkeVattu(DataVattu,
	    (VT_Book.CURENT_PAGE-1)*10,min((VT_Book.CURENT_PAGE*10-1),(DataVattu.num-1)),
    	VT_Book.left,VT_Book.top_main,10,VT_Book_c_line);
}
void prev_VT_Book()
{
	VT_Book.prev_PAGE();
	lietkeVattu(DataVattu,
	    (VT_Book.CURENT_PAGE-1)*10,min((VT_Book.CURENT_PAGE*10-1),(DataVattu.num-1)),
    	VT_Book.left,VT_Book.top_main,10,VT_Book_c_line);
}
void Show_VT()
{
	init_R();
	cout <<"vat tu page open" <<endl; // Delete this line when release!!!
	CURRENT_STRAGE = 100;
	
	main_frame();
	menu_slash("vat tu");
	
	cout <<"vat tu page open" <<endl; // Delete this line when release!!!
	New_Button.ID=CURRENT_STRAGE+20;
	New_Button.show();
	Save_Button.ID=CURRENT_STRAGE+99;
	Save_Button.show();
	VT_Book.show();
	setcolor(0);
	setbkcolor(VT_Book.color);
	lietkeVattu(DataVattu,
	    (VT_Book.CURENT_PAGE-1)*10,min((VT_Book.CURENT_PAGE*10-1),(DataVattu.num-1)),
    	VT_Book.left,VT_Book.top_main,10,VT_Book_c_line);
}
void new_MNV()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,NV_new.font_size);
	clearStream();
	ScannerCode(NV_new.List_content[0],16,NV_new.left+5,(NV_new.top_main+NV_new.bottom-textheight("S"))/2,NV_new.List_content_ID[0]);
}
void new_Ho()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,NV_new.font_size);
	clearStream();
	ScannerString(NV_new.List_content[1],21,NV_new.left+NV_new.column[0]+5,(NV_new.top_main+NV_new.bottom-textheight("S"))/2,NV_new.List_content_ID[1]);
}
void new_Ten()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,NV_new.font_size);
	clearStream();
	ScannerString(NV_new.List_content[2],16,NV_new.left+NV_new.column[1]+5,(NV_new.top_main+NV_new.bottom-textheight("S"))/2,NV_new.List_content_ID[2]);
}
void new_Phai()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerString(NV_new.List_content[3],5,VT_new.left+NV_new.column[2]+5,(NV_new.top_main+NV_new.bottom-textheight("S"))/2,NV_new.List_content_ID[3]);
}
void cancel_NV_new()
{
	NV_Book.TOTAL_PAGE=  DataNhanvien.num/10+ (DataNhanvien.num%10!=0) ;
	NV_new.free_Table();
	NV_new.cancel();
	active_bar.cancel();
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-130 , m_f.right, m_f.bottom);
	
}
void save_NV_new()
{
	nhanvien_error error;
	Nhanvien pre_add;
	error = Check_NV_new(pre_add,NV_new.List_content[0],NV_new.List_content[1],NV_new.List_content[2],NV_new.List_content[3]);
	if(error.check)
	{
	addNhanvien(DataNhanvien._nhanvien,pre_add);
	cancel_NV_new();
	NV_Book.show();
	setcolor(0);
	setbkcolor(NV_Book.color);
	PrintNhanvien(DataNhanvien._nhanvien,NV_Book.CURENT_PAGE,NV_Book.left+5,NV_Book.top_main+NV_Book.CONTENT_SPACE,NV_Book_c_line);
	} 
	else 
	{
		setbkcolor(getpixel(NV_new.left,NV_new.bottom+5));
		setcolor(4);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
		setcolor(error.error_color[0]);
		outtextxy(NV_new.left,NV_new.bottom+5,error.error_st[0]);
		for(int i = 1; i<4;i++)
		{
			setcolor(error.error_color[i]);
			outtextxy(NV_new.left+NV_new_c_line[i-1],NV_new.bottom+5,error.error_st[i]);
		}
	}
	
	
}
void Show_NV_new()
{
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-130 , m_f.right, m_f.bottom);
	
	if(active_bar.is_active) active_bar.cancel();
	if(NV_new.is_active) NV_new.cancel();
	active_bar.Show();
	NV_new.free_Table();
	NV_new_save.show();//button
	NV_new_cancel.show();//button
	NV_new.show();
}
void Select_MNV()
{
	setbkcolor(VT_Select.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
//	int leng = strlen(scan);
//	for(int i=leng;i<100;i++){
//		scan[i] = '/0';
//	}
//	cout<<"listcontent 2 ::::"<<NV_Select.List_content[0]<<" listcontent 1 :::"<<NV_Select.List_content[1]<<endl;
	ScannerCode(NV_Select.List_content[0],16,NV_Select.left+5,(NV_Select.top_main+NV_Select.bottom-textheight("S"))/2,NV_Select.List_content_ID[0]);
//	cout<<"listcontent 2 ::::"<<NV_Select.List_content[0]<<" listcontent 1 :::"<<NV_Select.List_content[1]<<endl;
//strcpy(DataVattu._vattu[ps].MAVT,scan);
	
}
void Select_HO()
{
	setbkcolor(VT_Select.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
//	char scan[100];
//	memset(scan,NULL,sizeof(scan));
//	strcpy(scan ,buf.HO);
//	strcpy(NV_Select.List_content[1],scan);
	ScannerString(NV_Select.List_content[1],21,NV_new.left+NV_new.column[0]+5,(NV_Select.top_main+NV_Select.bottom-textheight("S"))/2,NV_Select.List_content_ID[1]);
//	strcpy(DataVattu._vattu[ps].TENVT,scan);
}
void Select_TEN()
{
	setbkcolor(VT_Select.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
//	char scan[100];
//	memset(scan,NULL,sizeof(scan));
//	strcpy(scan ,buf.TEN);
//	strcpy(NV_Select.List_content[2],scan);
	ScannerString(NV_Select.List_content[2],16,NV_new.left+NV_new.column[1]+5,(NV_Select.top_main+NV_Select.bottom-textheight("S"))/2,NV_Select.List_content_ID[2]);
	//	strcpy(DataVattu._vattu[ps].DVT,scan);	
}
void Select_PHAI()
{
	setbkcolor(VT_Select.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
//	char scan[100];
//	memset(scan,NULL,sizeof(scan));
//	strcpy(scan ,buf.PHAI);
//	strcpy(NV_Select.List_content[3],scan);
cout <<"::::>>" ;
	ScannerString(NV_Select.List_content[3],5,NV_new.left+NV_new.column[2]+5,(NV_Select.top_main+NV_Select.bottom-textheight("S"))/2,NV_Select.List_content_ID[3]);
	//	strcpy(DataVattu._vattu[ps].DVT,scan);
	
}
void cancel_NV_seclect()
{
	VT_new.free_Table();
	VT_new.cancel();
	active_bar.cancel();
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-130 , m_f.right, m_f.bottom);
	
}
void save_NV_seclect()
{
	nhanvien_error error;
	Nhanvien pre_add ;
	cout<<"listcontent 2 ::::"<<NV_Select.List_content[0]<<" listcontent 1 :::"<<NV_Select.List_content[1]<<endl;
	error = Check_NV_seclect(pre_add, NV_Select.List_content[0], NV_Select.List_content[1], NV_Select.List_content[2], NV_Select.List_content[3],ps);
	if(error.check)
	{
	
	cancel_NV_seclect();
	Delete_NV(DataNhanvien._nhanvien,ps);
	addNhanvien(DataNhanvien._nhanvien,pre_add);
	NV_Book.show();
	setbkcolor(NV_Book.color);
	setcolor(0);
	PrintNhanvien(DataNhanvien._nhanvien,NV_Book.CURENT_PAGE,NV_Book.left+5,NV_Book.top_main+NV_Book.CONTENT_SPACE,NV_Book_c_line);
	} 
	else 
	{
		setbkcolor(getpixel(NV_new.left,NV_new.bottom+5));
		setcolor(4);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
		setcolor(error.error_color[0]);
		outtextxy(NV_new.left,NV_new.bottom+5,error.error_st[0]);
		for(int i = 1; i<4;i++)
		{
			setcolor(error.error_color[i]);
			outtextxy(NV_new.left+VT_new_c_line[i-1],NV_new.bottom+5,error.error_st[i]);
		}
	}
	
	
}
void NV_Book_line1()
{
	
	ps = (NV_Book.CURENT_PAGE-1)*10 + 1;
	
	if(ps<DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();

	strcpy(NV_Select.List_content[0] , buf.MANV);
	strcpy(NV_Select.List_content[1] , buf.HO);
	strcpy(NV_Select.List_content[2] , buf.TEN);
	strcpy(NV_Select.List_content[3] , buf.PHAI);
	if(NV_Select.is_active) NV_Select.cancel();
	active_bar.Show();
	NV_Select.show();
//	cout <<"NV_Book:?:"<<NV_Select.List_content_ID[0]<<":::"<<NV_Select.List_content_ID[1]<<":::"<<NV_Select.List_content_ID[2]<<":::"<<NV_Select.List_content_ID[3]<<endl;
	NV_Select_save.show();
	}
}
void NV_Book_line2()
{
	
	ps = (NV_Book.CURENT_PAGE-1)*10 + 2;
	
	if(ps<DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();

	strcpy(NV_Select.List_content[0] , buf.MANV);
	strcpy(NV_Select.List_content[1] , buf.HO);
	strcpy(NV_Select.List_content[2] , buf.TEN);
	strcpy(NV_Select.List_content[3] , buf.PHAI);
	if(NV_Select.is_active) NV_Select.cancel();
	active_bar.Show();
	NV_Select.show();
//	cout <<"NV_Book:?:"<<NV_Select.List_content_ID[0]<<":::"<<NV_Select.List_content_ID[1]<<":::"<<NV_Select.List_content_ID[2]<<":::"<<NV_Select.List_content_ID[3]<<endl;
	NV_Select_save.show();
	}
}
void NV_Book_line3()
{
	
	ps = (NV_Book.CURENT_PAGE-1)*10 + 3;
	
	if(ps<DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();

	strcpy(NV_Select.List_content[0] , buf.MANV);
	strcpy(NV_Select.List_content[1] , buf.HO);
	strcpy(NV_Select.List_content[2] , buf.TEN);
	strcpy(NV_Select.List_content[3] , buf.PHAI);
	if(NV_Select.is_active) NV_Select.cancel();
	active_bar.Show();
	NV_Select.show();
//	cout <<"NV_Book:?:"<<NV_Select.List_content_ID[0]<<":::"<<NV_Select.List_content_ID[1]<<":::"<<NV_Select.List_content_ID[2]<<":::"<<NV_Select.List_content_ID[3]<<endl;
	NV_Select_save.show();
	}
}
void NV_Book_line4()
{
	
	ps = (NV_Book.CURENT_PAGE-1)*10 + 4;
	
	if(ps<DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();

	strcpy(NV_Select.List_content[0] , buf.MANV);
	strcpy(NV_Select.List_content[1] , buf.HO);
	strcpy(NV_Select.List_content[2] , buf.TEN);
	strcpy(NV_Select.List_content[3] , buf.PHAI);
	if(NV_Select.is_active) NV_Select.cancel();
	active_bar.Show();
	NV_Select.show();
//	cout <<"NV_Book:?:"<<NV_Select.List_content_ID[0]<<":::"<<NV_Select.List_content_ID[1]<<":::"<<NV_Select.List_content_ID[2]<<":::"<<NV_Select.List_content_ID[3]<<endl;
	NV_Select_save.show();
	}
}
void NV_Book_line5()
{
	
	ps = (NV_Book.CURENT_PAGE-1)*10 + 5;
	
	if(ps<DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();

	strcpy(NV_Select.List_content[0] , buf.MANV);
	strcpy(NV_Select.List_content[1] , buf.HO);
	strcpy(NV_Select.List_content[2] , buf.TEN);
	strcpy(NV_Select.List_content[3] , buf.PHAI);
	if(NV_Select.is_active) NV_Select.cancel();
	active_bar.Show();
	NV_Select.show();
//	cout <<"NV_Book:?:"<<NV_Select.List_content_ID[0]<<":::"<<NV_Select.List_content_ID[1]<<":::"<<NV_Select.List_content_ID[2]<<":::"<<NV_Select.List_content_ID[3]<<endl;
	NV_Select_save.show();
	}
}
void NV_Book_line6()
{
	
	ps = (NV_Book.CURENT_PAGE-1)*10 + 6;
	
	if(ps<DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();

	strcpy(NV_Select.List_content[0] , buf.MANV);
	strcpy(NV_Select.List_content[1] , buf.HO);
	strcpy(NV_Select.List_content[2] , buf.TEN);
	strcpy(NV_Select.List_content[3] , buf.PHAI);
	if(NV_Select.is_active) NV_Select.cancel();
	active_bar.Show();
	NV_Select.show();
//	cout <<"NV_Book:?:"<<NV_Select.List_content_ID[0]<<":::"<<NV_Select.List_content_ID[1]<<":::"<<NV_Select.List_content_ID[2]<<":::"<<NV_Select.List_content_ID[3]<<endl;
	NV_Select_save.show();
	}
}
void NV_Book_line7()
{
	
	ps = (NV_Book.CURENT_PAGE-1)*10 + 7;
	
	if(ps<DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();

	strcpy(NV_Select.List_content[0] , buf.MANV);
	strcpy(NV_Select.List_content[1] , buf.HO);
	strcpy(NV_Select.List_content[2] , buf.TEN);
	strcpy(NV_Select.List_content[3] , buf.PHAI);
	if(NV_Select.is_active) NV_Select.cancel();
	active_bar.Show();
	NV_Select.show();
//	cout <<"NV_Book:?:"<<NV_Select.List_content_ID[0]<<":::"<<NV_Select.List_content_ID[1]<<":::"<<NV_Select.List_content_ID[2]<<":::"<<NV_Select.List_content_ID[3]<<endl;
	NV_Select_save.show();
	}
}
void NV_Book_line8()
{
	
	ps = (NV_Book.CURENT_PAGE-1)*10 + 8;
	
	if(ps<DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();

	strcpy(NV_Select.List_content[0] , buf.MANV);
	strcpy(NV_Select.List_content[1] , buf.HO);
	strcpy(NV_Select.List_content[2] , buf.TEN);
	strcpy(NV_Select.List_content[3] , buf.PHAI);
	if(NV_Select.is_active) NV_Select.cancel();
	active_bar.Show();
	NV_Select.show();
//	cout <<"NV_Book:?:"<<NV_Select.List_content_ID[0]<<":::"<<NV_Select.List_content_ID[1]<<":::"<<NV_Select.List_content_ID[2]<<":::"<<NV_Select.List_content_ID[3]<<endl;
	NV_Select_save.show();
	}
}
void NV_Book_line9()
{
	
	ps = (NV_Book.CURENT_PAGE-1)*10 + 9;
	
	if(ps<DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();

	strcpy(NV_Select.List_content[0] , buf.MANV);
	strcpy(NV_Select.List_content[1] , buf.HO);
	strcpy(NV_Select.List_content[2] , buf.TEN);
	strcpy(NV_Select.List_content[3] , buf.PHAI);
	if(NV_Select.is_active) NV_Select.cancel();
	active_bar.Show();
	NV_Select.show();
//	cout <<"NV_Book:?:"<<NV_Select.List_content_ID[0]<<":::"<<NV_Select.List_content_ID[1]<<":::"<<NV_Select.List_content_ID[2]<<":::"<<NV_Select.List_content_ID[3]<<endl;
	NV_Select_save.show();
	}
}
void NV_Book_line10()
{
	
	ps = (NV_Book.CURENT_PAGE-1)*10 + 10;
	
	if(ps<DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();

	strcpy(NV_Select.List_content[0] , buf.MANV);
	strcpy(NV_Select.List_content[1] , buf.HO);
	strcpy(NV_Select.List_content[2] , buf.TEN);
	strcpy(NV_Select.List_content[3] , buf.PHAI);
	if(NV_Select.is_active) NV_Select.cancel();
	active_bar.Show();
	NV_Select.show();
//	cout <<"NV_Book:?:"<<NV_Select.List_content_ID[0]<<":::"<<NV_Select.List_content_ID[1]<<":::"<<NV_Select.List_content_ID[2]<<":::"<<NV_Select.List_content_ID[3]<<endl;
	NV_Select_save.show();
	}
}
void next_NV_Book()
{
	NV_Book.next_PAGE();
	setcolor(0);
	setbkcolor(NV_Book.color);
	PrintNhanvien(DataNhanvien._nhanvien,NV_Book.CURENT_PAGE,NV_Book.left+5,NV_Book.top_main+NV_Book.CONTENT_SPACE,NV_Book_c_line);
}
void prev_NV_Book()
{
	NV_Book.prev_PAGE();
	setcolor(0);
	setbkcolor(NV_Book.color);
	PrintNhanvien(DataNhanvien._nhanvien,NV_Book.CURENT_PAGE,NV_Book.left+5,NV_Book.top_main+NV_Book.CONTENT_SPACE,NV_Book_c_line);
}
void Show_NV()
{
	init_R();
	CURRENT_STRAGE = 200;
	main_frame();
	menu_slash("Nhan vien");
	cout <<"nhan vien page open" <<endl; // Delete this line when release!!!
	New_Button.ID=CURRENT_STRAGE+20;
	New_Button.show();
	Save_Button.ID=CURRENT_STRAGE+99;
	Save_Button.show();
	NV_Book.show();
	setcolor(0);
	setbkcolor(NV_Book.color);
	PrintNhanvien(DataNhanvien._nhanvien,NV_Book.CURENT_PAGE,NV_Book.left+5,NV_Book.top_main+NV_Book.CONTENT_SPACE,NV_Book_c_line);
	
	cout <<"nhan vien page open" <<endl; // Delete this line when release!!!
}

void Show_HD ()
{
	init_R();
	CURRENT_STRAGE = 300;
	main_frame();
	menu_slash("Hoa don");
	cout <<"hoa don page open" <<endl; // Delete this line when release!!!
}

void Show_Dic()
{
	cout <<"dictionary show" <<endl;
	Dic_Dialog.show();
}
void Cancel_Dic()
{
	cout <<"dictionary cancel" <<endl;
	Dic_Dialog.cancel();
}

void GUI_Init()
{
	
	F_R[0]= notthing;
//	F_R[2]= newconsole;
	/*Adding Exit button ID*/
	F_R[Exit_App.ID]=Exit;
	F_R[3]=Home;
	/*Adding Menu Button ID*/
	F_R[Menu_Button.ID]=Show_Menu_List;
	/*Adding menu tab contents*/
	Menu_Tab.List_content_ID[0]= 3;
	/*Vattu ID*/
	Menu_Tab.List_content_ID[1] = VT_ID;
	F_R[VT_ID]=Show_VT;
	for(int i = 0; i<VT_Book.NUMBER_OF_LINE;i++)
		VT_Book.List_content_ID[i]=VT_ID+i+1;
	//Link add 1 -> 10
	F_R[VT_Book.List_content_ID[0]] = VT_Book_line1;
	F_R[VT_Book.List_content_ID[1]] = VT_Book_line2;
	F_R[VT_Book.List_content_ID[2]] = VT_Book_line3;
	F_R[VT_Book.List_content_ID[3]] = VT_Book_line4;
	F_R[VT_Book.List_content_ID[4]] = VT_Book_line5;
	F_R[VT_Book.List_content_ID[5]] = VT_Book_line6;
	F_R[VT_Book.List_content_ID[6]] = VT_Book_line7;
	F_R[VT_Book.List_content_ID[7]] = VT_Book_line8;
	F_R[VT_Book.List_content_ID[8]] = VT_Book_line9;
	F_R[VT_Book.List_content_ID[9]] = VT_Book_line10;
	//Link add 1 -> 10
	
	F_R[VT_ID+20]=Show_VT_new;
	VT_new.List_content_ID[0]=VT_ID+21;
	F_R[VT_new.List_content_ID[0]]=new_MVT;
	VT_new.List_content_ID[1]=VT_ID+22;
	F_R[VT_new.List_content_ID[1]]=new_TVT;
	VT_new.List_content_ID[2]=VT_ID+23;
	F_R[VT_new.List_content_ID[2]]=new_DVTVT;
	VT_new.List_content_ID[3]=VT_ID+24;
	F_R[VT_new.List_content_ID[3]]=new_SLTVT;
	F_R[VT_new_save.ID]=save_VT_new;
	F_R[VT_new_cancel.ID]=cancel_VT_new;
	

	VT_Select.List_content_ID[0]=113;
	F_R[VT_Select.List_content_ID[0]]=Select_MVT;
	VT_Select.List_content_ID[1]=114;
	F_R[VT_Select.List_content_ID[1]]=Select_TVT;
	VT_Select.List_content_ID[2]=115;
	F_R[VT_Select.List_content_ID[2]]=Select_DVTVT;
	
	F_R[VT_Select_save.ID]= save_VT_seclect;
	F_R[VT_Select_cancel.ID]= cancel_VT_seclect;
	
	F_R[VT_ID+99] = save_Vattu;
	VT_Book.prev_ID=111;
	F_R[VT_Book.prev_ID] = prev_VT_Book;
	VT_Book.next_ID=112;
	F_R[VT_Book.next_ID] = next_VT_Book;
	
	/*Nhan vien ID*/
	Menu_Tab.List_content_ID[2] = NV_ID;
	F_R[NV_ID]=Show_NV;
	for(int i = 0; i<NV_Book.NUMBER_OF_LINE;i++)
	NV_Book.List_content_ID[i]=NV_ID+i+1;
	//Link add 1 -> 10
	F_R[NV_Book.List_content_ID[0]] = NV_Book_line1;
	F_R[NV_Book.List_content_ID[1]] = NV_Book_line2;
	F_R[NV_Book.List_content_ID[2]] = NV_Book_line3;
	F_R[NV_Book.List_content_ID[3]] = NV_Book_line4;
	F_R[NV_Book.List_content_ID[4]] = NV_Book_line5;
	F_R[NV_Book.List_content_ID[5]] = NV_Book_line6;
	F_R[NV_Book.List_content_ID[6]] = NV_Book_line7;
	F_R[NV_Book.List_content_ID[7]] = NV_Book_line8;
	F_R[NV_Book.List_content_ID[8]] = NV_Book_line9;
	F_R[NV_Book.List_content_ID[9]] = NV_Book_line10;
	//Link add 1 -> 10		
	F_R[NV_ID+20]=Show_NV_new;	
	NV_new.List_content_ID[0]=NV_ID+21;
	F_R[NV_new.List_content_ID[0]]=new_MNV;
	NV_new.List_content_ID[1]=NV_ID+22;
	F_R[NV_new.List_content_ID[1]]=new_Ho;
	NV_new.List_content_ID[2]=NV_ID+23;
	F_R[NV_new.List_content_ID[2]]=new_Ten;
	NV_new.List_content_ID[3]=NV_ID+24;
	F_R[NV_new.List_content_ID[3]]=new_Phai;
	F_R[NV_new_save.ID]=save_NV_new;
	F_R[NV_new_cancel.ID]=cancel_NV_new;
	
	NV_Select.List_content_ID[0]=213;
	F_R[NV_Select.List_content_ID[0]]=Select_MNV;
	NV_Select.List_content_ID[1]=214;
	F_R[NV_Select.List_content_ID[1]]=Select_HO;
	NV_Select.List_content_ID[2]=215;
	F_R[NV_Select.List_content_ID[2]]=Select_TEN;
	NV_Select.List_content_ID[3]=216;
	F_R[NV_Select.List_content_ID[3]]=Select_PHAI;
		F_R[NV_Select_save.ID]= save_NV_seclect;
		
	F_R[NV_ID+99] = save_Nhanvien;
	NV_Book.prev_ID=211;
	F_R[NV_Book.prev_ID] = prev_NV_Book;
	NV_Book.next_ID=212;
	F_R[NV_Book.next_ID] = next_NV_Book;
	/*Hoa don ID*/
	Menu_Tab.List_content_ID[3] = HD_ID;
	F_R[HD_ID]=Show_HD;
	/*Dic ID*/
	Menu_Tab.List_content_ID[4] = Dic_Dialog.ID;
	F_R[Dic_Dialog.ID]=Show_Dic;
	F_R[Dic_Dialog.cID]=Cancel_Dic;
	/*main menu init*/
	Menu_Tab.line_color = COLOR(200,200,200);
	/*Vat Tu init*/
	VT_Book.TOTAL_PAGE=  DataVattu.num/10+ (DataVattu.num%10!=0) ;
	if(VT_Book.TOTAL_PAGE == 0) VT_Book.TOTAL_PAGE=1;
	cout <<"TOTAL_PAGE:: "<<VT_Book.TOTAL_PAGE<<endl;
	VT_Book.text_color = 0;
	VT_Book.line_color = COLOR(128,128,128);
	
	/*Nhan vien*/
	NV_Book.TOTAL_PAGE=  DataNhanvien.num/10+ (DataNhanvien.num%10!=0) ;
	if(NV_Book.TOTAL_PAGE == 0) NV_Book.TOTAL_PAGE=1;
	cout <<"TOTAL_PAGE:: "<<NV_Book.TOTAL_PAGE<<endl;
	NV_Book.text_color = 0;
	NV_Book.line_color = COLOR(128,128,128);
	/*Tra Cuu Vat Tu init*/
	cout <<"GUI init complete!\n";
}		
