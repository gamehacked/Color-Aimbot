//#include "ScanContents.h"
//
//
///*INSTRUCTIONS ON HOW TO USE:
//1- Set up chams, load up game
//2- turn this hack on
//3- detect based on colour CURRENTLY BLUE
//4-play game and trigger with specific key CURRENTLY RIGHT MOUSE
//*/
//
//
//
//bool TakeScreenshot(std::string WindowToFind, BITMAP &bm, HBITMAP &hbmap, BITMAPINFO &bmi, HDC &hdcShot, HBITMAP &hBitmapOld, HWND &hwnd);
//
//
//void SmoothMouseMovement(int xTo, int yTo)
//{
//	POINT currentPos; 
//	int time = clock();
//	
//	while(true)
//	{
//		//if(clock() - time > 0)
//		//{
//			time = clock();
//			GetCursorPos(&currentPos);
//			if(currentPos.x < xTo)
//			{
//				SetCursorPos(currentPos.x+1, currentPos.y);
//			}
//			else if(currentPos.x > xTo)
//			{
//				SetCursorPos(currentPos.x-1, currentPos.y);
//			}
//			////check our Y axis
//			if(currentPos.y < yTo)
//			{
//				SetCursorPos(currentPos.x, currentPos.y+1);
//			}
//			else if(currentPos.y > yTo)
//			{
//				SetCursorPos(currentPos.x, currentPos.y-1);
//			}
//		
//			if(currentPos.x == xTo && currentPos.y == yTo)
//				break;
//			//else std::cout << "NOT FOUND PINK" << std::endl;
//			if(GetAsyncKeyState(VK_ESCAPE))
//			{
//				exit(0);
//			}
//		//}
//
//
//	}
//
//}
//
//
//
//
//bool CompareColour(RGBQUAD *pPixels, int height, int width, int x, int y)
//{
//	int p = (height-y-1)*width+x; // upside down
//	//int r = (int)pPixels[p].rgbRed;
//	//int g = (int)pPixels[p].rgbGreen;
//	//int b = (int)pPixels[p].rgbBlue;
//	//std::cout << (int)pPixels[p].rgbRed << ", " << (int)pPixels[p].rgbGreen << ", " << (int)pPixels[p].rgbBlue  << std::endl;
//	//SetCursorPos(x, y);
//	//PINK
//	if((int)pPixels[p].rgbRed < 30 && (int)pPixels[p].rgbGreen < 30 && (int)pPixels[p].rgbBlue > 215)
//	//if((int)pPixels[p].rgbRed == 255/*255*/ && (int)pPixels[p].rgbGreen == 0 && (int)pPixels[p].rgbBlue == 220)
//	{
//		//std::cout << "FOUND PINK" << std::endl;
//		//system("PAUSE");
//		//std::cout << r << ", " << g << ", " << b  << std::endl;
//		//std::cout << "Found color" << std::endl;
//
//		return true;
//	}
//	//else std::cout << "NOT FOUND PINK" << std::endl;
//	if(GetAsyncKeyState(VK_ESCAPE))
//	{
//		exit(0);
//	}
//	return false;
//}
//
//
//void ShootBot(int x, int y)
//{
//	mouse_event(MOUSEEVENTF_LEFTDOWN,x, y,0,0);
//	mouse_event(MOUSEEVENTF_LEFTUP,x, y,0,0);
//}
//
//
////our independant thread, used to send our shots
//void ShootThr(MouseCoord * coord)
//{
//	SetCursorPos(coord->X, coord->Y);
//	//Sleep(15);
//	mouse_event(MOUSEEVENTF_LEFTDOWN, coord->X, coord->Y,0,0);
//	mouse_event(MOUSEEVENTF_LEFTUP, coord->X, coord->Y,0,0);
//	_endthread();
//}
//
//
//
//
//
//
//
////OUR MAIN SCANNER LOOP
//void ScanBMPHorizontal(ScanContents * scan)
//{
//	//scan until it reaches the limits/bounds of the game window
//	
//	//THIS CAN BE DIVIDED BY ANY NUMBER, 5 WAS JUST THE CHOICE THAT FELT RIGHT FOR ME, E.G. DOESNT SCAN TOO MUCH OF THE SCREEN. Lower numbers cover
//	//more of the game
//	//Just like well do below with the X, here we start scanning at about 1/4 of the screen, this allows us to scan the screen much faster
//	//and makes our aimbot much more efficient
//	for(int y = (scan->RcWindow.bottom - scan->RcWindow.top)/4;
//		y < ((scan->RcWindow.bottom - scan->RcWindow.top)-(scan->RcWindow.bottom - scan->RcWindow.top)/3.5);
//		y++)
//	//for(scan->Y = scan->StartingY-((int)(scan->RcWindow.bottom - scan->RcWindow.top)/5)/*GET'S THE WINDOW'S HEIGHT/5*/; scan->Y < scan->StartingY + ((int)(scan->RcWindow.bottom - scan->RcWindow.top)/5); scan->Y+=3)
//	{
//		//SetCursorPos(scan->X, scan->Y);
//		//3 because we are checking RGB every time
//		//ONLY SCAN about 2-3/4 of the screen, this way scans are much faster and we have much more control over the aimbot
//		//WE START X at about 1/4 of the screen and stop at 3/4, this way it can work at any window resolution
//		for(int x = (int)((scan->RcWindow.right - scan->RcWindow.left)/4)/*+15*/; 
//			x < (int)((scan->RcWindow.right - scan->RcWindow.left)-(scan->RcWindow.right - scan->RcWindow.left)/4);
//			x ++)
//		{
//			//SetCursorPos(scan->X+scan->RcWindow.left, scan->Y+scan->RcWindow.top);
//			//Sleep(1);
//			//CHECK IF OUR CHOSEN COLOUR = TRUE
//			if(CompareColour(scan->PPixels, scan->Bm.bmHeight, scan->Bm.bmWidth, x, y))
//			{
//				int z = x;
//				while(z < (int)((scan->RcWindow.right - scan->RcWindow.left)-(scan->RcWindow.right - scan->RcWindow.left)/4))
//				{
//					//comment this after
//					//SetCursorPos(z, scan->Y);
//					//search until our color is not the same and then DEFINE A CENTER POINT from the point found
//					//within the for loop(POINT 1 = scan->X to POINT 2 = z (Center  = z - (z - scan->X)/2))
//					//the pixel between point 2 and point 1
//					if(!CompareColour(scan->PPixels, scan->Bm.bmHeight, scan->Bm.bmWidth, z, y))
//					{
//						break;
//					}
//					z++; //COULD ALSO BE 3, 2 is used because i am looking for the exact center point of the first and last pixel
//				}
//
//				//MouseCoord coord((z -( z - scan->X)/2)+scan->RcWindow.left, scan->Y+scan->RcWindow.top);
//				//_beginthread((void(*)(void*))ShootThr, 0, (void*)&coord);
//
//				SetCursorPos((z -( z - x)/2)+scan->RcWindow.left, y+scan->RcWindow.top);
//				//Sleep(55);
//
//				//SmoothMouseMovement((z -( z - x)/2)+scan->RcWindow.left, y+scan->RcWindow.top);
//
//
//				//SHOOT AT THE EXACT CENTER POINT of the color 
//				ShootBot((z -( z - x)/2)+scan->RcWindow.left, y+scan->RcWindow.top);
//				//std::cout << "Bang bang "  << std::endl;
//				//*scan->ColorFoundK = true;
//				return;
//
//			}
//		}
//	}
//}
//
//
//int main()
//{	
//	std::string GameWindow = "Counter-Strike Source";
//	HWND appWnd = FindWindow(0, GameWindow.c_str()); //rgb - Windows Photo Viewer // Call of duty 4 // Counter-Strike Source
//	while(!appWnd)
//	{
//		system("CLS");
//		appWnd = FindWindow(0, GameWindow.c_str());
//		std::cout << "Unable to find " << GameWindow.c_str() << std::endl;
//		Sleep(500);
//	}
//
//	RECT rcWindow;
//	GetWindowRect(appWnd, &rcWindow);
//
//	BITMAP bm;
//	HBITMAP hbmap;
//	HBITMAP hBitmapOld;
//	BITMAPINFO bmi;
//	HDC hdcShot;
//	HDC hdcScreen;
//
//	RGBQUAD *pPixels;
//    //Do things with bits here
//	int TimeTakenScreenAndScan;
//
//	//DELETE ME !!!
//	Sleep(2500);
//	while(true)
//	{
//		//only allow pressing with a x ms difference
//		if(!GetAsyncKeyState('X')) //VK_RBUTTON
//		{
//			TimeTakenScreenAndScan = clock();
//			//get all contents of our screen and store them in bm
//			if(!TakeScreenshot(GameWindow, bm, hbmap, bmi, hdcShot, hBitmapOld, appWnd))
//				break;
//
//
//			////NEED TO CALL THESE AGAIN FOR THE SCREENSHOT TO WORK PROPERLY, screenshotception
//			HBITMAP hbmapNew = CreateCompatibleBitmap(hdcShot, rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top);
//
//			HDC hdcShotNew = CreateCompatibleDC(hdcShot);
//
//			HBITMAP OldBmp  = (HBITMAP) SelectObject(hdcShotNew, hbmapNew); 
//
//			//store our screenshot FROM TO, storing just the size of the window Keeping resource allocation down by a couple of 100,000 pixels
//			BitBlt(hdcShotNew, 0, 0, rcWindow.right - rcWindow.left/*Window WIDTH*/, rcWindow.bottom - rcWindow.top/*Window HEIGHT*/
//				, hdcShot, 0, 0, SRCCOPY);
//
//			//--TOOK ABOUT 50 milliSECONDS TO TAKE SCREENSHOT AND GET HERE--, with improvements approximately 40 ms
//			//std::cout << "Took screenshot in " << clock() - TimeTakenScreenAndScan << " milliseconds" << std::endl;
//
//			pPixels = new RGBQUAD[bm.bmWidth * bm.bmHeight]; 
//			if (!pPixels) return false;
// 
//			SelectObject(hdcShotNew, OldBmp);
//
//			//HDC hdc = GetDC(HWND_DESKTOP);
//			if (!GetDIBits(hdcShotNew, hbmapNew, 0, bm.bmHeight, pPixels, &bmi, DIB_RGB_COLORS))
//			{
//				ReleaseDC(appWnd, hdcShot);
//				delete [] pPixels;
//				return false;
//			}
//			ReleaseDC(appWnd, hdcShot);
//
//			ScanContents scanContentsMain(bm, rcWindow, pPixels);
//
//			ScanBMPHorizontal(&scanContentsMain);
//			//system("pause");
//
//		//CURRENTLY AT 66 MILLISECONDS PER SCAN(A PROBLEM)
//		//IMPROVED TO BETWEEN 40-50 MS WITH FOCUSED SCREENSHOTS, E.G. storing the games screen only instead of the whole desktop
//
//
//		//CHECK IF OUR THREADS are still running and i+f NOT then we allow player to scan aimbot again
//		
//		//system("pause");
//		//if we ended our scan we free up the memory for our next screenshot
//
//			//free our memory again or head on to crash town
//			if(pPixels)free(pPixels);
//			SelectObject(hdcShot, hBitmapOld);
//			DeleteObject(hbmap);
//			DeleteDC(hdcShot);
//			DeleteObject(hbmapNew);
//			DeleteObject(OldBmp);
//			DeleteDC(hdcShotNew);
//					//	std::cout << "out of scan, took " << clock() - TimeTakenScreenAndScan << " milliseconds" << std::endl;
//		}
//		//IMPROVED TO 30-40MS
//		//std::cout << "Scan " << " took " << clock() - TimeTakenScreenAndScan << " ms to complete" << std::endl;
//	}
//	system("pause");
//	return 0;
//}
//
//
//void SetupBitmapInfo(BITMAPINFO &bmi, int bWidth, int bHeight, int bitsPerPixel)
//{
//    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
//    bmi.bmiHeader.biWidth = bWidth;
//    bmi.bmiHeader.biHeight = bHeight;
//    bmi.bmiHeader.biPlanes = 1;
//    bmi.bmiHeader.biBitCount = bitsPerPixel;
//    bmi.bmiHeader.biCompression = BI_RGB;
//    bmi.bmiHeader.biSizeImage = 0;
//}
//
//
////bool TakeScreenshot(std::string WindowToFind, BITMAP &bm, HBITMAP &hbmap, BITMAPINFO &bmi, HDC &hdcShot, HBITMAP &hBitmapOld, HDC &hdcScreen)
//bool TakeScreenshot(std::string WindowToFind, BITMAP &bm, HBITMAP &hbmap, BITMAPINFO &bmi, HDC &hdcShot, HBITMAP &hBitmapOld, HWND &hwnd)
//{
//	//HWND hwnd = FindWindow(0, WindowToFind.c_str());    //the window can't be min
// //   if (hwnd == NULL)
// //   {
// //       std::cout << "Unable to find " << WindowToFind.c_str() << std::endl;
// //       return false;
// //   }
//
//	RECT rc;
//	//get our window's rectangle
//	GetWindowRect(hwnd, &rc);
//
//    hdcShot = CreateCompatibleDC(0);
//    hbmap = CreateCompatibleBitmap(GetDC(0), rc.right - rc.left/*Window WIDTH*/, rc.bottom - rc.top/*Window HEIGHT*/);
//
//	SelectObject(hdcShot, hbmap); 
//
//	//store our screenshot FROM TO, storing just the size of the window Keeping resource allocation down by a couple of 100,000 pixels
//	BitBlt(hdcShot, 0, 0, rc.right - rc.left/*Window WIDTH*/, rc.bottom - rc.top/*Window HEIGHT*/
//		, GetDC(0), rc.left, rc.top, SRCCOPY);
//	//HERE WE decided where we want our screenshot to begin, we chose the left and top of the rectangle(window)
//
//    if (!GetObject(hbmap, sizeof(BITMAP), (LPSTR)&bm)) 
//		return false;
//    int bitsPerPixel = bm.bmBitsPixel;
//
//    if (bitsPerPixel != 32 || bm.bmPlanes != 1) 
//		return false;
//
//	SetupBitmapInfo(bmi, bm.bmWidth, bm.bmHeight, bitsPerPixel);
//	return true;
//
//}