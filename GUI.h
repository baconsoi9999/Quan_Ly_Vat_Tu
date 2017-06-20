	#include "Data\ERRORCHECK.h"
	#include <E:\#PTIT CAU TRUC DU LIEU GIAI THUAT\de tai CTDLGT\Quan_Ly_Vat_Tu\conponentBGI.h>
	#include <iostream>
	#include <string.h>
	//#include "Data\topexport.h"
	
	using namespace std;
	 // Just using for testing

int CURRENT_STRAGE;	
const unsigned int VT_ID=100,NV_ID=200,HD_ID=300,TOP_10_VT_ID = 400;
int ps;
Thongtin_HD tt;
CT_HOADON ct_hd;

Frame m_f(APP_LEFT, APP_TOP, APP_RIGHT, APP_BOTTOM,COLOR(255,255,255));

Panel active_bar(APP_LEFT,APP_BOTTOM-130,APP_RIGHT,APP_BOTTOM);

Button Exit_App(1,APP_RIGHT-58,APP_TOP,APP_RIGHT,APP_TOP+29,4,2," X ");

Button Menu_Button(2,APP_LEFT, APP_TOP, APP_LEFT+ 399, APP_TOP+39, COLOR(0,0,255),3,"MENU");

Button New_Button(0, Menu_Button.right+10, APP_TOP,Menu_Button.right+160, APP_TOP+39, COLOR(0,255,0),3," NEW\0");//change ID not 0

Button Save_Button(0,New_Button.right +5, APP_TOP, New_Button.right +165, APP_TOP+39, COLOR(0,0,220),3," SAVE\0");

char*Menu_Content_Tile[5]={"Trang chu\0","Quan ly vat tu\0","Quan ly nhan vien\0","Quan ly hoa don\0","Top 10 VT xuat"};
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
Button VT_Select_delete(117,APP_RIGHT-95,APP_BOTTOM-78,APP_RIGHT-5,APP_BOTTOM-40,COLOR(0,0,220),2," XOA\0");

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
Button NV_Select_save(217,APP_RIGHT-95, APP_BOTTOM-120,APP_RIGHT-5,APP_BOTTOM-82,COLOR(0,0,220),2," OK\0");

/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
Button Lap_HD_Button(301,APP_LEFT+50,APP_TOP+150,APP_LEFT+50+186,APP_TOP+200,COLOR(0,255,0),2,"LAP HOA DON\0");
Button Print_HD_by_SHD_button(330,APP_LEFT+50+196,APP_TOP+150,APP_LEFT+50+496,APP_TOP+200,COLOR(0,255,0),2," IN HD THEO SO HD\0");

Panel Lap_HD_Panel(APP_LEFT, APP_TOP+39, APP_RIGHT, APP_BOTTOM);


unsigned short int Lap_HD_TT_c_Line[5]={266,356,446,536,626};
char* Lap_HD_TT_c_Tile[6]={"So Hoa don\0","Ngay\0","Thang\0","Nam\0", "Loai\0", "Ma nhan vien lap\0"};
Array_Table Lap_HD_TT(APP_LEFT+5, APP_TOP+39+50, APP_LEFT+897, APP_TOP+110+50,2,COLOR(234,244,253),COLOR(0,255,0),6,Lap_HD_TT_c_Line,Lap_HD_TT_c_Tile);
Panel Lap_HD_TT_OK_panel(APP_LEFT+903,Lap_HD_TT.top_main, APP_LEFT+977,Lap_HD_TT.bottom);
Button Lap_HD_TT_OK(302,APP_LEFT+903,Lap_HD_TT.top_main, APP_LEFT+977,Lap_HD_TT.bottom,COLOR(0,0,220),2," OK \0");

Button Lap_HD_final_OK(309,APP_LEFT+353,APP_BOTTOM-100,APP_LEFT+543,APP_BOTTOM-30,COLOR(0,0,220),2,"  LAP HD\0");


Button Lap_HD_add_VT(310,APP_LEFT+553,APP_BOTTOM-100,APP_LEFT+743,APP_BOTTOM-30,COLOR(0,0,220),2,"THEM VAT TU\0");
Button Lap_HD_cancel(311,APP_LEFT+753,APP_BOTTOM-100,APP_LEFT+943,APP_BOTTOM-30,COLOR(0,0,220),2,"    HUY\0");

unsigned short int CT_HD_c_Line[4]={74,442,596,750};
char* CT_HD_c_Tile[5]= {"STT\0","Ma Vat tu\0","So luong\0","Dong gia\0", "%VAT"};
char* CT_HD_l_tile[10]={"1\0","2\0","3\0","4\0","5\0"};
Book CT_HD_Book(APP_LEFT+5,APP_TOP+160+50,APP_LEFT+850, 2 ,COLOR(234,244,253),COLOR(83,174,242),5,5,CT_HD_c_Line,CT_HD_c_Tile, CT_HD_l_tile);
unsigned short int CT_HD_new_c_Line[3]={388,562,736};
char* CT_HD_new_Tile[4]={"Ma Vat tu\0","So luong\0","Dong gia\0", "%VAT"};
Array_Table CT_HD_new(APP_LEFT+5, APP_BOTTOM-120, APP_LEFT+850, APP_BOTTOM-40, 2,COLOR(234,244,253),COLOR(83,174,242),4,CT_HD_new_c_Line,CT_HD_new_Tile);
Button CT_HD_new_save(316,APP_LEFT+860, APP_BOTTOM-120,APP_LEFT+934,APP_BOTTOM-82,COLOR(0,0,220),2," OK\0");
Button CT_HD_new_cancel(317,APP_LEFT+860,APP_BOTTOM-78,APP_LEFT+934,APP_BOTTOM-40,COLOR(0,0,220),2," HUY\0");

unsigned short int search_HD_by_SHD_c_Line[1]={};
char* search_HD_by_SHD_c_Tile[1]={"Nhap So hoa don\0"};
Array_Table search_HD_by_SHD((APP_RIGHT+APP_LEFT-560)/2,APP_TOP+210,(APP_RIGHT+APP_LEFT+400)/2,APP_TOP+300,2,15,COLOR(83,174,242),1,search_HD_by_SHD_c_Line,search_HD_by_SHD_c_Tile);
Array_Table return_search_HD_TT(APP_LEFT+5, APP_TOP+39+50, APP_LEFT+631, APP_TOP+110+50,2,COLOR(234,244,253),COLOR(0,255,0),5,Lap_HD_TT_c_Line,Lap_HD_TT_c_Tile);
Button search_HD_by_SHD_OK(331,(APP_RIGHT+APP_LEFT+400)/2+10,APP_TOP+210+36,(APP_RIGHT+APP_LEFT+400)/2+80,APP_TOP+300,COLOR(0,0,200),2,"TIM\0");
Button search_HD_by_SHD_exit(HD_ID,APP_RIGHT-95,APP_BOTTOM-78,APP_RIGHT-5,APP_BOTTOM-40,COLOR(0,0,200),2,"THOAT\0");
Book return_search_CT_HD_Book(APP_LEFT+5,APP_TOP+160+50,APP_LEFT+850, 2 ,COLOR(234,244,253),COLOR(83,174,242),5,5,CT_HD_c_Line,CT_HD_c_Tile, CT_HD_l_tile);
/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
unsigned short int Top_E_Begin_c_line[3]= {133,266,266};
char* Top_E_Begin_c_Tile[3]={"Ngay\0","Thang\0","Nam\0"};
Array_Table Top_E_Begin((APP_RIGHT+APP_LEFT)/2-400,APP_TOP+210,(APP_RIGHT+APP_LEFT)/2,APP_TOP+300,2,15,COLOR(83,174,242),3,Top_E_Begin_c_line,Top_E_Begin_c_Tile);
Array_Table Top_E_End((APP_RIGHT+APP_LEFT)/2+138,APP_TOP+210,(APP_RIGHT+APP_LEFT)/2+538,APP_TOP+300,2,15,COLOR(83,174,242),3,Top_E_Begin_c_line,Top_E_Begin_c_Tile);
Button Top_E_OK(407,(APP_RIGHT+APP_LEFT)/2-50,APP_TOP+400,(APP_RIGHT+APP_LEFT)/2+50,APP_TOP+450,COLOR(0,0,200),2," XEM\0");
Button Top_E_exit(TOP_10_VT_ID,APP_RIGHT-95,APP_BOTTOM-78,APP_RIGHT-5,APP_BOTTOM-40,COLOR(0,0,200),2,"THOAT\0");

unsigned short int Top_E_Book_c_line[3]={100,449,913};
char* Top_E_Book_c_tile[4]={"STT\0","Ma Vat tu\0","Ten Vat tu\0","So Luong\0"};
char* Top_E_Book_l_tile[10]= {"1\0","2\0","3\0","4\0","5\0","6\0","7\0","8\0","9\0","10\0"};
Book Top_E_Book(APP_LEFT+5, Menu_Button.bottom+5, APP_RIGHT-5 ,2 ,COLOR(234,244,253),COLOR(83,174,242), 10,4,Top_E_Book_c_line,Top_E_Book_c_tile,Top_E_Book_l_tile);
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
void Lap_HD_frame()
{
	if(Lap_HD_Panel.is_active) Lap_HD_Panel.cancel();
	Lap_HD_Panel.Show();
	setfillstyle(1, 15);
	bar(APP_LEFT, APP_TOP+39,APP_RIGHT,APP_BOTTOM-130);
	setfillstyle(1,COLOR(128,128,255));
	bar(APP_LEFT,APP_BOTTOM-130,APP_RIGHT,APP_BOTTOM);
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
	ScannerCode(VT_new.List_content[0],15,VT_new.left+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[0]);
}
void new_TVT()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerString(VT_new.List_content[1],20,VT_new.left+VT_new.column[0]+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[1]);
}
void new_DVTVT()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerString(VT_new.List_content[2],15,VT_new.left+VT_new.column[1]+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[2]);
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
	VT_Book.TOTAL_PAGE =  DataVattu.num/10+ (DataVattu.num%10!=0);
	
	cout <<"TTPAGE::" <<VT_Book.TOTAL_PAGE;
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
	ScannerCode(VT_Select.List_content[0],15,VT_Select.left+5,(VT_Select.top_main+VT_Select.bottom-textheight("S"))/2,VT_Select.List_content_ID[0]);
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
	ScannerString(VT_Select.List_content[1],20,VT_new.left+VT_new.column[0]+5,(VT_Select.top_main+VT_Select.bottom-textheight("S"))/2,VT_Select.List_content_ID[1]);
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
void delete_VT_seclect()
{
	deleteVattu(ps,DataVattu);
	VT_Book.TOTAL_PAGE=  DataVattu.num/10+ (DataVattu.num%10!=0);
	if(VT_Book.CURENT_PAGE > VT_Book.TOTAL_PAGE) VT_Book.CURENT_PAGE --;
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
	
	delete_VT_seclect();
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
	VT_Select.free_Table();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_delete.show();
	VT_Select_save.show();
	}
}
void VT_Book_line2()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 1;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	VT_Select.free_Table();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_delete.show();
	VT_Select_save.show();
	}
}
void VT_Book_line3()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 2;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	VT_Select.free_Table();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_delete.show();
	VT_Select_save.show();
	}
}
void VT_Book_line4()
{

	ps = (VT_Book.CURENT_PAGE-1)*10 + 3;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{	if(active_bar.is_active) active_bar.cancel();
	VT_Select.free_Table();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
//	VT_Select_cancel.show();
	VT_Select_save.show();
	}
}
void VT_Book_line5()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 4;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	VT_Select.free_Table();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_delete.show();
	VT_Select_save.show();
	}
}
void VT_Book_line6()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 5;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	VT_Select.free_Table();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_delete.show();
	VT_Select_save.show();
	}
}
void VT_Book_line7()
{

	ps = (VT_Book.CURENT_PAGE-1)*10 + 6;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{if(active_bar.is_active) active_bar.cancel();
	VT_Select.free_Table();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_delete.show();
	VT_Select_save.show();
	}
}
void VT_Book_line8()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 7;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{
	if(active_bar.is_active) active_bar.cancel();
	VT_Select.free_Table();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_delete.show();
	VT_Select_save.show();
	}
}
void VT_Book_line9()
{
	
	ps = (VT_Book.CURENT_PAGE-1)*10 + 8;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{
	if(active_bar.is_active) active_bar.cancel();
	VT_Select.free_Table();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_delete.show();
	VT_Select_save.show();
	}
}
void VT_Book_line10()
{
	ps = (VT_Book.CURENT_PAGE-1)*10 + 9;
	if(strlen(DataVattu._vattu[ps].MAVT)!=0)
	{
	if(active_bar.is_active) active_bar.cancel();
	VT_Select.free_Table();
	strcpy(VT_Select.List_content[0] , DataVattu._vattu[ps].MAVT);
	strcpy(VT_Select.List_content[1] , DataVattu._vattu[ps].TENVT);
	strcpy(VT_Select.List_content[2] , DataVattu._vattu[ps].DVT);
	strcpy(VT_Select.List_content[3] , DataVattu._vattu[ps].soluongton);
	if(VT_Select.is_active) VT_Select.cancel();
	active_bar.Show();
	VT_Select.show();
	VT_Select_delete.show();
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
	ScannerString(NV_new.List_content[3],4,VT_new.left+NV_new.column[2]+5,(NV_new.top_main+NV_new.bottom-textheight("S"))/2,NV_new.List_content_ID[3]);
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
	ScannerString(NV_Select.List_content[3],4,NV_new.left+NV_new.column[2]+5,(NV_Select.top_main+NV_Select.bottom-textheight("S"))/2,NV_Select.List_content_ID[3]);
	//	strcpy(DataVattu._vattu[ps].DVT,scan);
	
}
void cancel_NV_seclect()
{
	VT_Book.TOTAL_PAGE=  DataNhanvien.num/10+ (DataNhanvien.num%10!=0) ;
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
	error = Check_NV_seclect(pre_add, NV_Select.List_content[0], NV_Select.List_content[1], NV_Select.List_content[2], NV_Select.List_content[3],buf.thongtin.MANV);
	if(error.check)
	{
	
	cancel_NV_seclect();
	if(Find_NV(DataNhanvien._nhanvien,buf.thongtin.MANV)) cout<<"1?\n";
	//cout<<"buf::"<<buf.MANV<<endl;
//	cout<<"Data:::"<<DataNhanvien.num<<endl;
	delKey(DataNhanvien._nhanvien,buf.thongtin.MANV);
	//cout<<"Data:::"<<--DataNhanvien.num<<endl;
	addNhanvien(DataNhanvien._nhanvien,pre_add);
	
	NV_Book.show();
	setbkcolor(NV_Book.color);
	setcolor(0);
//	cout<<"data:::"<<DataNhanvien.num<<endl;
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
	
	if(ps<=DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();
	NV_Select.free_Table();
	strcpy(NV_Select.List_content[0] , buf.thongtin.MANV);
	strcpy(NV_Select.List_content[1] , buf.thongtin.HO);
	strcpy(NV_Select.List_content[2] , buf.thongtin.TEN);
	strcpy(NV_Select.List_content[3] , buf.thongtin.PHAI);
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
	
	if(ps<=DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();
	NV_Select.free_Table();
	strcpy(NV_Select.List_content[0] , buf.thongtin.MANV);
	strcpy(NV_Select.List_content[1] , buf.thongtin.HO);
	strcpy(NV_Select.List_content[2] , buf.thongtin.TEN);
	strcpy(NV_Select.List_content[3] , buf.thongtin.PHAI);
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
	
	if(ps<=DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();
	NV_Select.free_Table();
	strcpy(NV_Select.List_content[0] , buf.thongtin.MANV);
	strcpy(NV_Select.List_content[1] , buf.thongtin.HO);
	strcpy(NV_Select.List_content[2] , buf.thongtin.TEN);
	strcpy(NV_Select.List_content[3] , buf.thongtin.PHAI);
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
	
	if(ps<=DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();
	NV_Select.free_Table();
	strcpy(NV_Select.List_content[0] , buf.thongtin.MANV);
	strcpy(NV_Select.List_content[1] , buf.thongtin.HO);
	strcpy(NV_Select.List_content[2] , buf.thongtin.TEN);
	strcpy(NV_Select.List_content[3] , buf.thongtin.PHAI);
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
	
	if(ps<=DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();
	NV_Select.free_Table();
	strcpy(NV_Select.List_content[0] , buf.thongtin.MANV);
	strcpy(NV_Select.List_content[1] , buf.thongtin.HO);
	strcpy(NV_Select.List_content[2] , buf.thongtin.TEN);
	strcpy(NV_Select.List_content[3] , buf.thongtin.PHAI);
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
	
	if(ps<=DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();
	NV_Select.free_Table();
	strcpy(NV_Select.List_content[0] , buf.thongtin.MANV);
	strcpy(NV_Select.List_content[1] , buf.thongtin.HO);
	strcpy(NV_Select.List_content[2] , buf.thongtin.TEN);
	strcpy(NV_Select.List_content[3] , buf.thongtin.PHAI);
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
	
	if(ps<=DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();
	NV_Select.free_Table();
	strcpy(NV_Select.List_content[0] , buf.thongtin.MANV);
	strcpy(NV_Select.List_content[1] , buf.thongtin.HO);
	strcpy(NV_Select.List_content[2] , buf.thongtin.TEN);
	strcpy(NV_Select.List_content[3] , buf.thongtin.PHAI);
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
	
	if(ps<=DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();
	NV_Select.free_Table();
	strcpy(NV_Select.List_content[0] , buf.thongtin.MANV);
	strcpy(NV_Select.List_content[1] , buf.thongtin.HO);
	strcpy(NV_Select.List_content[2] , buf.thongtin.TEN);
	strcpy(NV_Select.List_content[3] , buf.thongtin.PHAI);
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
	
	if(ps<=DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();
	NV_Select.free_Table();
	strcpy(NV_Select.List_content[0] , buf.thongtin.MANV);
	strcpy(NV_Select.List_content[1] , buf.thongtin.HO);
	strcpy(NV_Select.List_content[2] , buf.thongtin.TEN);
	strcpy(NV_Select.List_content[3] , buf.thongtin.PHAI);
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
	
	if(ps<=DataNhanvien.num)
	{
	buf = searchTreebyNum(DataNhanvien._nhanvien,ps);
	if(active_bar.is_active) active_bar.cancel();
	NV_Select.free_Table();
	strcpy(NV_Select.List_content[0] , buf.thongtin.MANV);
	strcpy(NV_Select.List_content[1] , buf.thongtin.HO);
	strcpy(NV_Select.List_content[2] , buf.thongtin.TEN);
	strcpy(NV_Select.List_content[3] , buf.thongtin.PHAI);
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

void Lap_HD_TT_SoHD()
{
	if(Lap_HD_TT.lock==false) return;
	setbkcolor(Lap_HD_TT.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerNum(Lap_HD_TT.List_content[0],15,Lap_HD_TT.left+5,(Lap_HD_TT.top_main+Lap_HD_TT.bottom-textheight("S"))/2,Lap_HD_TT.List_content_ID[0]);
}
void Lap_HD_TT_Ngay()
{
	if(Lap_HD_TT.lock==false) return;
	setbkcolor(Lap_HD_TT.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerNum(Lap_HD_TT.List_content[1],2,Lap_HD_TT.left+Lap_HD_TT.column[0]+5,(Lap_HD_TT.top_main+Lap_HD_TT.bottom-textheight("S"))/2,Lap_HD_TT.List_content_ID[1]);
}
void Lap_HD_TT_Thang()
{
	if(Lap_HD_TT.lock==false) return;
	setbkcolor(Lap_HD_TT.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerNum(Lap_HD_TT.List_content[2],2,Lap_HD_TT.left+Lap_HD_TT.column[1]+5,(Lap_HD_TT.top_main+Lap_HD_TT.bottom-textheight("S"))/2,Lap_HD_TT.List_content_ID[2]);
}
void Lap_HD_TT_Nam()
{
	if(Lap_HD_TT.lock==false) return;
	setbkcolor(Lap_HD_TT.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerNum(Lap_HD_TT.List_content[3],4,Lap_HD_TT.left+Lap_HD_TT.column[2]+5,(Lap_HD_TT.top_main+Lap_HD_TT.bottom-textheight("S"))/2,Lap_HD_TT.List_content_ID[3]);
}
void Lap_HD_Loai()
{
	if(Lap_HD_TT.lock==false) return;
	setbkcolor(Lap_HD_TT.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerLoai(Lap_HD_TT.List_content[4],1,Lap_HD_TT.left+Lap_HD_TT.column[3]+5,(Lap_HD_TT.top_main+Lap_HD_TT.bottom-textheight("S"))/2,Lap_HD_TT.List_content_ID[4]);
}
void Lap_HD_TT_MaNV()
{
	if(Lap_HD_TT.lock==false) return;
	setbkcolor(Lap_HD_TT.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerCode(Lap_HD_TT.List_content[5],15,Lap_HD_TT.left+Lap_HD_TT.column[4]+5,(Lap_HD_TT.top_main+Lap_HD_TT.bottom-textheight("S"))/2,Lap_HD_TT.List_content_ID[5]);
}
void Lap_HD_TT_save()
{

	hoadon_error error;
	cout<<"::listcontent::"<<Lap_HD_TT.List_content[0]<<endl;
	error = Check_HD_new(tt,Lap_HD_TT.List_content[0],Lap_HD_TT.List_content[1],Lap_HD_TT.List_content[2],Lap_HD_TT.List_content[3],Lap_HD_TT.List_content[4][0],Lap_HD_TT.List_content[5]);
	if(error.check)
	{
		Lap_HD_TT.lock=false;
		Lap_HD_TT_OK_panel.cancel();
		Lap_HD_add_VT.lock = true;
		Lap_HD_add_VT.show();		
		cout<<"loai3::: "<<tt.loai<<endl;
	}
	else 
	{
		setbkcolor(getpixel(Lap_HD_TT.left,Lap_HD_TT.bottom+5));
		setcolor(4);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
		setcolor(error.error_color[0]);
		outtextxy(Lap_HD_TT.left+5,Lap_HD_TT.bottom+5,error.error_st[0]);
		for(int i = 1; i<6;i++)
		{
			setcolor(error.error_color[i]);
			outtextxy(Lap_HD_TT.left+Lap_HD_TT_c_Line[i-1],Lap_HD_TT.bottom+5,error.error_st[i]);
		}
	}

}
void Lap_HD()
{
	
	Lap_HD_final_OK.lock = false;
	Lap_HD_add_VT.lock = false;
	Lap_HD_frame();
	init_ct(ct_hd);
	settextstyle(DEFAULT_FONT, HORIZ_DIR,3);
	setbkcolor(15);
	setcolor(0);
	outtextxy((APP_LEFT+APP_RIGHT-8*3*11)/2,APP_TOP+45,"LAP HOA DON");
	Lap_HD_final_OK.show();
	Lap_HD_add_VT.show();
	Lap_HD_cancel.show();
	Lap_HD_TT.free_Table();
	Lap_HD_TT.show();
	Lap_HD_TT_OK_panel.Show();
	Lap_HD_TT_OK.show();
	CT_HD_Book.show();	
}
void cancel_Lap_HD()
{
	
	Lap_HD_Panel.cancel();
}

void new_CT_HD_MVT()
{
	setbkcolor(CT_HD_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
	clearStream();
	ScannerCode(CT_HD_new.List_content[0],15,CT_HD_new.left+5,(CT_HD_new.top_main+CT_HD_new.bottom-textheight("S"))/2,CT_HD_new.List_content_ID[0]);
}
void new_CT_HD_SL()
{
	
	setbkcolor(CT_HD_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
	clearStream();
	ScannerNum(CT_HD_new.List_content[1],9,CT_HD_new.left+CT_HD_new.column[0]+5,(CT_HD_new.top_main+CT_HD_new.bottom-textheight("S"))/2,CT_HD_new.List_content_ID[1]);
}
void new_CT_HD_DG()
{
	setbkcolor(CT_HD_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
	clearStream();
	ScannerNum(CT_HD_new.List_content[2],9,CT_HD_new.left+CT_HD_new.column[1]+5,(CT_HD_new.top_main+CT_HD_new.bottom-textheight("S"))/2,CT_HD_new.List_content_ID[2]);
}
void new_CT_HD_VAT()
{
	setbkcolor(CT_HD_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
	clearStream();
	ScannerNum(CT_HD_new.List_content[3],3,CT_HD_new.left+CT_HD_new.column[2]+5,(CT_HD_new.top_main+CT_HD_new.bottom-textheight("S"))/2,CT_HD_new.List_content_ID[3]);
}
void prev_CT_HD_Book()
{
	CT_HD_Book.prev_PAGE();
	CT_HD_Book.show();
	Print_CT_HD(ct_hd,CT_HD_Book.left+5,CT_HD_Book.top_main+CT_HD_Book.CONTENT_SPACE,CT_HD_Book.CURENT_PAGE,CT_HD_c_Line);
}
void next_CT_HD_Book()
{
	CT_HD_Book.next_PAGE();
	CT_HD_Book.show();
	Print_CT_HD(ct_hd,CT_HD_Book.left+5,CT_HD_Book.top_main+CT_HD_Book.CONTENT_SPACE,CT_HD_Book.CURENT_PAGE,CT_HD_c_Line);
}
void new_CT_HD_cancel()
{
	active_bar.cancel();
}

void new_CT_HD_save()
{
	ct_hoadon_error error;
	Thongtin_CT pre_add;
	cout<<"1????";
	error = Check_CT_new(pre_add,CT_HD_new.List_content[0],CT_HD_new.List_content[1],CT_HD_new.List_content[2],CT_HD_new.List_content[3],Lap_HD_TT.List_content[4][0]);	
	
	if(error.check)
	{
		cout<<"1>>>>\n";
		NodeCT* p = GetNode_CT(pre_add);
		cout<<"2>>>>\n";
		new_CT_HD_cancel();	
		addTail_CT(ct_hd,p);
		cout<<"3>>>>\n"<<CT_HD_Book.CURENT_PAGE<<endl;
		CT_HD_Book.TOTAL_PAGE = ct_hd.num/5 +  (ct_hd.num%5!=0);
		cout<<"ct hd totalpage:::"<<CT_HD_Book.TOTAL_PAGE<<endl;
		cout<<"3>>>>\n"<<ct_hd.num<<endl;
		CT_HD_Book.show();
		Print_CT_HD(ct_hd,CT_HD_Book.left+5,CT_HD_Book.top_main+CT_HD_Book.CONTENT_SPACE,CT_HD_Book.CURENT_PAGE,CT_HD_c_Line);
		cout<<"4>>>>\n";
		Lap_HD_final_OK.lock = true;
		Lap_HD_final_OK.show();
	}
	else 
	{
		setbkcolor(getpixel(CT_HD_new.left,CT_HD_new.bottom+5));
		setcolor(4);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
		setcolor(error.error_color[0]);
		outtextxy(CT_HD_new.left+5,CT_HD_new.bottom+5,error.error_st[0]);
		for(int i = 1; i<5;i++)
		{
			setcolor(error.error_color[i]);
			outtextxy(CT_HD_new.left+CT_HD_new_c_Line[i-1],CT_HD_new.bottom+5,error.error_st[i]);
		}
	}
}

void add_Lap_HD_VT()
{
	if(Lap_HD_add_VT.lock == false) return;
	active_bar.set_active();
	//bar
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-130 , m_f.right, m_f.bottom);
	CT_HD_new.free_Table();
	CT_HD_new.show();
	CT_HD_new_save.show();
	CT_HD_new_cancel.show();
	
	
}


void Sync_VT(DsVattu &ds,char MaVT[],char loai,char sluong[]){
	if(loai == 'N' || loai == 'n'){
		int pos = bsearch(ds,MaVT);
		cout<<"loai1::"<<loai<<endl;
		int soluongton = Number(ds._vattu[pos].soluongton);
		int soluongnhap = Number(sluong);
		int soluongton_s = soluongnhap + soluongton;
		char tam [100];
		itoa(soluongton_s,tam,10);
		strcpy(ds._vattu[pos].soluongton , tam);
	}
	else {
		cout<<"loai2::"<<loai<<endl;
		int pos = bsearch(ds,MaVT);
		int soluongton = Number(ds._vattu[pos].soluongton);
		int soluongxuat = Number(sluong);
		int soluongton_s = soluongton - soluongxuat;
		char tam [100];
		itoa(soluongton_s,tam,10);
		strcpy(ds._vattu[pos].soluongton , tam);
	}
}

void Sync_VT_all(CT_HOADON ct,Thongtin_HD tt){
	for(NodeCT* p = ct_hd.ctHead;p!=NULL;p = p->_next){
		Sync_VT(DataVattu,p->thongtin.MAVT,tt.loai,p->thongtin.soluong);
	}
}
void Lap_HD_final()
{
	if(Lap_HD_final_OK.lock == false ) return;
	NodeHD* q_hd = new NodeHD;
	q_hd->thongtin = tt;
	q_hd->chitiet = ct_hd;
	q_hd->_next = NULL;
	Sync_VT_all(ct_hd,tt);
	save_HD_to_NV(DataNhanvien._nhanvien,Lap_HD_TT.List_content[5],q_hd);
	Lap_HD_Panel.cancel();
}
void return_search_HD()
{
	return_search_HD_TT.show();
	return_search_CT_HD_Book.show();
}
void prev_return_search_CT_HD_Book()
{
	
	return_search_CT_HD_Book.prev_PAGE();
	return_search_CT_HD_Book.TOTAL_PAGE = ct_hd.num/5 +  (ct_hd.num%5!=0);
	return_search_CT_HD_Book.show();
	setbkcolor(15);
	setcolor(0);
	Print_CT_HD(ct_hd,return_search_CT_HD_Book.left+5,return_search_CT_HD_Book.top_main+return_search_CT_HD_Book.CONTENT_SPACE,return_search_CT_HD_Book.CURENT_PAGE,CT_HD_c_Line);
}
void next_return_search_CT_HD_Book()
{
	
	return_search_CT_HD_Book.next_PAGE();
	return_search_CT_HD_Book.TOTAL_PAGE = ct_hd.num/5 +  (ct_hd.num%5!=0);
	return_search_CT_HD_Book.show();
	setbkcolor(15);
	setcolor(0);
	Print_CT_HD(ct_hd,return_search_CT_HD_Book.left+5,return_search_CT_HD_Book.top_main+return_search_CT_HD_Book.CONTENT_SPACE,return_search_CT_HD_Book.CURENT_PAGE,CT_HD_c_Line);
}
void input_SHD()
{
	setbkcolor(search_HD_by_SHD.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
	clearStream();
	ScannerNum(search_HD_by_SHD.List_content[0],15,search_HD_by_SHD.left+5,(search_HD_by_SHD.top_main+search_HD_by_SHD.bottom-textheight("S"))/2,search_HD_by_SHD.List_content_ID[0]);
		
}

void search_HD()
{
	init_ct(ct_hd);
	Thongtin_HD tt_hd;
	bool check = Find_HD_byNum(tt_hd,ct_hd,DataNhanvien._nhanvien,search_HD_by_SHD.List_content[0])	;
	if(check){
		Lap_HD_Panel.cancel();
		Lap_HD_frame();
		settextstyle(DEFAULT_FONT, HORIZ_DIR,3);
		outtextxy((APP_LEFT+APP_RIGHT-8*3*17)/2,APP_TOP+45,"THONG TIN HOA DON\0");
		return_search_HD();
		search_HD_by_SHD_exit.show();
		return_search_CT_HD_Book.TOTAL_PAGE = ct_hd.num/5 +  (ct_hd.num%5!=0);
		return_search_CT_HD_Book.show();
		cout<<"total page:::"<<return_search_CT_HD_Book.TOTAL_PAGE<<endl;
		setbkcolor(15);
		setcolor(0);
		Print_thongtin_HD(tt_hd,return_search_HD_TT.left+5,return_search_HD_TT.top_main+10,Lap_HD_TT_c_Line);
		Print_CT_HD(ct_hd,return_search_CT_HD_Book.left+5,return_search_CT_HD_Book.top_main+return_search_CT_HD_Book.CONTENT_SPACE,return_search_CT_HD_Book.CURENT_PAGE,CT_HD_c_Line);
		
	}
	else {
		setbkcolor(COLOR(200,230,251));
		setcolor(4);
		outtextxy(search_HD_by_SHD.left+5,search_HD_by_SHD.bottom+10,"Khong tim thay\0");
	}
}

void Print_HD_by_SHD()
{
	Lap_HD_frame();
	setfillstyle(1,COLOR(200,230,251));
	bar((APP_RIGHT+APP_LEFT-600)/2,APP_TOP+200,(APP_RIGHT+APP_LEFT+600)/2,APP_TOP+350);
	search_HD_by_SHD.free_Table();
	search_HD_by_SHD.show();
	search_HD_by_SHD_OK.show();
	search_HD_by_SHD_exit.show();
}
void Show_HD ()
{
	init_R();
	CURRENT_STRAGE = 300;
	main_frame();
	menu_slash("Hoa don");
	
	Lap_HD_Button.show();
	Print_HD_by_SHD_button.show();
	cout <<"hoa don page open" <<endl; // Delete this line when release!!!
}
void Top_E_Begin_Ngay()
{
	setbkcolor(Top_E_Begin.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,Top_E_Begin.font_size);
	clearStream();
	ScannerNum(Top_E_Begin.List_content[0],2,Top_E_Begin.left+5,(Top_E_Begin.top_main+Top_E_Begin.bottom-textheight("S"))/2,Top_E_Begin.List_content_ID[0]);
}
void Top_E_Begin_Thang()
{
	setbkcolor(Top_E_Begin.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,Top_E_Begin.font_size);
	clearStream();
	ScannerNum(Top_E_Begin.List_content[1],2,Top_E_Begin.left+Top_E_Begin.column[0]+5,(Top_E_Begin.top_main+Top_E_Begin.bottom-textheight("S"))/2,Top_E_Begin.List_content_ID[1]);
}
void Top_E_Begin_Nam()
{
	setbkcolor(Top_E_Begin.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,Top_E_Begin.font_size);
	clearStream();
	ScannerNum(Top_E_Begin.List_content[2],4,Top_E_Begin.left+Top_E_Begin.column[1]+5,(Top_E_Begin.top_main+Top_E_Begin.bottom-textheight("S"))/2,Top_E_Begin.List_content_ID[2]);
}
void Top_E_End_Ngay()
{
	setbkcolor(Top_E_End.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,Top_E_End.font_size);
	clearStream();
	ScannerNum(Top_E_End.List_content[0],2,Top_E_End.left+5,(Top_E_End.top_main+Top_E_End.bottom-textheight("S"))/2,Top_E_End.List_content_ID[0]);
}

void Top_E_End_Thang()
{
	setbkcolor(Top_E_End.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,Top_E_End.font_size);
	clearStream();
	ScannerNum(Top_E_End.List_content[1],2,Top_E_End.left+Top_E_End.column[0]+5,(Top_E_End.top_main+Top_E_End.bottom-textheight("S"))/2,Top_E_End.List_content_ID[1]);
}
void Top_E_End_Nam()
{
	setbkcolor(Top_E_End.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,Top_E_End.font_size);
	clearStream();
	ScannerNum(Top_E_End.List_content[2],4,Top_E_End.left+Top_E_End.column[1]+5,(Top_E_End.top_main+Top_E_End.bottom-textheight("S"))/2,Top_E_End.List_content_ID[2]);
}
void Top_E_Print()
{
	day_error error;
	int Num1,Num2;
	
	error = Check_day(Num1,Top_E_Begin.List_content[0],Top_E_Begin.List_content[1],Top_E_Begin.List_content[2],Num2,Top_E_End.List_content[0],Top_E_End.List_content[1],Top_E_End.List_content[2]);
	if(error.check)
	{
		DsExport_top Top_E_ds;
		Top_E_ds = Top_Export(DataVattu,Num1,Num2);
		Top_E_Book.show();
		Print_top(Top_E_ds,Top_E_Book.left+5,Top_E_Book.top_main+10,Top_E_Book_c_line);
		Top_E_exit.show();
	}
	else{
		setcolor(4);
		setbkcolor(COLOR(200,230,251));
		outtextxy(Top_E_Begin.left+5,Top_E_Begin.bottom+10,error.error_st[0]);
		outtextxy(Top_E_End.left+5,Top_E_End.bottom+10,error.error_st[1]);
	}
}
void show_TOP_10_VT()
{
	init_R();
	CURRENT_STRAGE = 400;
	main_frame();
	menu_slash("TOP 10 VT");
	Top_E_Begin.free_Table();
	Top_E_End.free_Table();
	setfillstyle(1,COLOR(200,230,251));
	bar(129,200,1254,397);
	setbkcolor(COLOR(200,230,251));
	setcolor(4);
	settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
	outtextxy(Top_E_Begin.left-117,(Top_E_Begin.top_main+Top_E_Begin.bottom-16)/2,"BAT DAU\0");
	outtextxy(Top_E_End.left- 133,(Top_E_Begin.top_main+Top_E_Begin.bottom-16)/2,"KET THUC\0");
	Top_E_Begin.show();
	Top_E_End.show();
	Top_E_OK.show();
	
	cout <<"TOP 10 VT page open" <<endl; // Delete this line when release!!!
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
	Menu_Tab.List_content_ID[1] = VT_ID;
	Menu_Tab.List_content_ID[2] = NV_ID;
	Menu_Tab.List_content_ID[3] = HD_ID;
	Menu_Tab.List_content_ID[4] = TOP_10_VT_ID;
		
	/*Vattu ID*/
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
	F_R[VT_Select_delete.ID]= delete_VT_seclect;
	
	F_R[VT_ID+99] = save_Vattu;
	VT_Book.prev_ID=111;
	F_R[VT_Book.prev_ID] = prev_VT_Book;
	VT_Book.next_ID=112;
	F_R[VT_Book.next_ID] = next_VT_Book;
	
	/*Nhan vien ID*/
	
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

	F_R[HD_ID]=Show_HD;
	F_R[Lap_HD_Button.ID]= Lap_HD;
	F_R[Lap_HD_TT_OK.ID] = Lap_HD_TT_save;//302
	Lap_HD_TT.List_content_ID[0] = 303;
	F_R[Lap_HD_TT.List_content_ID[0]] = Lap_HD_TT_SoHD;
	Lap_HD_TT.List_content_ID[1] = 304;
	F_R[Lap_HD_TT.List_content_ID[1]] = Lap_HD_TT_Ngay;
	Lap_HD_TT.List_content_ID[2] = 305;
	F_R[Lap_HD_TT.List_content_ID[2]] = Lap_HD_TT_Thang;
	Lap_HD_TT.List_content_ID[3] = 306;
	F_R[Lap_HD_TT.List_content_ID[3]] = Lap_HD_TT_Nam;
	Lap_HD_TT.List_content_ID[4] = 307;
	F_R[Lap_HD_TT.List_content_ID[4]] = Lap_HD_Loai;
	Lap_HD_TT.List_content_ID[5] = 308;
	F_R[Lap_HD_TT.List_content_ID[5]] =  Lap_HD_TT_MaNV;
	F_R[Lap_HD_final_OK.ID]= Lap_HD_final; //309
	F_R[Lap_HD_add_VT.ID] = add_Lap_HD_VT;//310
	F_R[Lap_HD_cancel.ID] = Show_HD;//311
	
	CT_HD_new.List_content_ID[0] = 312;
	F_R[CT_HD_new.List_content_ID[0]] =  new_CT_HD_MVT;
	CT_HD_new.List_content_ID[1] = 313;
	F_R[CT_HD_new.List_content_ID[1]] = new_CT_HD_SL;
	CT_HD_new.List_content_ID[2] = 314;
	F_R[CT_HD_new.List_content_ID[2]] = new_CT_HD_DG;
	CT_HD_new.List_content_ID[3] = 315;
	F_R[CT_HD_new.List_content_ID[3]] = new_CT_HD_VAT;
	F_R[CT_HD_new_save.ID] = new_CT_HD_save;//316
	F_R[CT_HD_new_cancel.ID] = new_CT_HD_cancel;//317
	CT_HD_Book.prev_ID = 318;
	F_R[CT_HD_Book.prev_ID] = prev_CT_HD_Book;
	CT_HD_Book.next_ID = 319;
	for(int i = 0; i<5;i++)
	CT_HD_Book.List_content_ID[i]= 0;
	F_R[CT_HD_Book.next_ID] = next_CT_HD_Book;
	F_R[Print_HD_by_SHD_button.ID] = Print_HD_by_SHD; //330
	F_R[search_HD_by_SHD_OK.ID] = search_HD; //331
	search_HD_by_SHD.List_content_ID[0] = 332;
	F_R[search_HD_by_SHD.List_content_ID[0]]= input_SHD;
	return_search_CT_HD_Book.prev_ID = 333;
	F_R[return_search_CT_HD_Book.prev_ID] = prev_return_search_CT_HD_Book;
	return_search_CT_HD_Book.next_ID = 334;
	F_R[return_search_CT_HD_Book.next_ID] = next_return_search_CT_HD_Book;
	/*Dic ID*/
	F_R[TOP_10_VT_ID] = show_TOP_10_VT;
	
	Top_E_Begin.List_content_ID[0] = 401;
	F_R[Top_E_Begin.List_content_ID[0]] = Top_E_Begin_Ngay;
	
	Top_E_Begin.List_content_ID[1] = 402;
	F_R[Top_E_Begin.List_content_ID[1]] = Top_E_Begin_Thang;
	Top_E_Begin.List_content_ID[2] = 403;
	F_R[Top_E_Begin.List_content_ID[2]] = Top_E_Begin_Nam;
	
	Top_E_End.List_content_ID[0] =  404;
	F_R[Top_E_End.List_content_ID[0]] = Top_E_End_Ngay;
	Top_E_End.List_content_ID[1] =  405;
	F_R[Top_E_End.List_content_ID[1]] =  Top_E_End_Thang;
	Top_E_End.List_content_ID[2] =  406;	
	F_R[Top_E_End.List_content_ID[2]] = Top_E_End_Nam;
	F_R[Top_E_OK.ID] = Top_E_Print;
	
	/*main menu init*/
	Menu_Tab.line_color = COLOR(200,200,200);
	/*Vat Tu init*/
	VT_Book.TOTAL_PAGE=  DataVattu.num/10+ (DataVattu.num%10!=0);
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
