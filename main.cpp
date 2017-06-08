
	#include "GUI.h"
	#include <windows.h>

#include <iostream>
int main()
{
	initdataVattu();
//	nhapVattu();
	inconsole();
	initwindow( SCREAN_W, SCREAN_H);
	init_R();
	GUI_Init();
	main_frame();
	cout <<"Loading complete!" <<endl; // Loading status // Delete this line when release!!!
	
/* Example*/
	while(1)
	{
		int x=-1;
		int y=-1;
		getmouseclick(WM_LBUTTONDOWN,x,y);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if ((x==-1)&&(y==-1)) continue;
		cout <<x <<" :: " <<y <<endl; // Delete this line when release!!!
			F_R[R[y][x]]();	
	}
	return 0;
};
