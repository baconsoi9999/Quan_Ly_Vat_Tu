

	#include "GUI.h"
#include <iostream>
int main()
{
	initwindow( SCREAN_W, SCREAN_H);
	init_R();
	R[90][51]=10;
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
		if(R[y][x]!=0)
		{
			F_R[R[y][x]]();
			
		}	
	}
	return 0;
};
