#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance /*This is the exe handle when loaded into memory*/
                    , HINSTANCE hPrevInstance /*this has no meaning today, used previously in 16-bit windows*/
                    , PWSTR pCmdLine /*contains command-line arguments as a unicode string*/
                    , int nCmdShow /*flag designating how to show the main app window*/)

//The wWinMain function returns an int value - this is not used by the OS but can be used by other apps
//the 'w' in 'wWinMain' signals it uses unicode, not ansi in the command-line args

{

    //Register Window Class
    const wchar_t CLASS_NAME[] = L"Sample Window Class";    //declare array to store name of class
    WNDCLASS wc = {};   //declare WNDCLASS object

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    //Create Window
    HWND hwnd = CreateWindowEx(
        0,                  //Optional Window styles
        CLASS_NAME,         //Window Class
        L"Learn to Program Windows",    //Window Text
        WS_OVERLAPPEDWINDOW,            //Window style
        
        //Size and Position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        
        NULL,               //Parent WIndow
        NULL,               //Menu
        hInstance,          //Instance handle
        NULL                //Additional application data
        );
    
    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    //Run the message loop

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
            EndPaint(hwnd, &ps);
        }
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

