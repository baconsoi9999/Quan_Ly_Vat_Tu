#include "GUI.h"

#include <iostream>
int main()
{
	initwindow(SCREAN_W, SCREAN_H);
	init_R();
	main_frame();
	cout <<"Loading complete!" <<endl; // Loading status

/* Example*/
	while(1)
	{
		int x=-1;
		int y=-1;
		getmouseclick(WM_LBUTTONDOWN,x,y);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(10);
		if ((x==-1)&&(y==-1)) continue;
		cout <<x <<" :: " <<y <<endl;
		if(R[y][x]!=0)
		{
			F_R[R[y][x]]();
			
		}	
	}
	return 0;
};
