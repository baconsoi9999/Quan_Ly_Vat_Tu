
	#include "GUI.h"
	#include <windows.h>

#include <iostream>

int main()
{
	initdataVattu();
//	nhapVattu();
	inconsole();
	initwindow( SCREAN_W, SCREAN_H);
	cout <<"Loading 1\n";
	init_R();
	cout <<"Loading 2\n";
	GUI_Init();
	cout <<"Loading 3\n";
	main_frame();
	cout <<"Loading complete!" <<endl; // Loading status // Delete this line when release!!!
	
/* Example*/
	while(GUIkey)
	{
		int x=-1;
		int y=-1;
		getmouseclick(WM_LBUTTONDOWN,x,y);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if ((x==-1)&&(y==-1)) continue;
		cout <<x <<" :: " <<y <<":::"<<R[y][x] <<endl; // Delete this line when release!!!
			F_R[R[y][x]]();	
	}
	f1.open("Data/DataVattu.data",ios::binary );
	f1.write((char*)&DataVattu, sizeof(DataVattu));
	f1.close();
	return 0;
};
