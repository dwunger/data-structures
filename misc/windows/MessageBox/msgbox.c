#include <windows.h>
#include <wchar.h>
/*
`hInstance` is the handle to an instance or handle to a module. 
            The operating system uses this value to identify the 
            executable or EXE when it's loaded in memory. 
            Certain Windows functions need the instance handle, 
            for example to load icons or bitmaps.

`hPrevInstance` has no meaning. It was used in 16-bit Windows,
            but is now always zero.

`pCmdLine` contains the command-line arguments as a Unicode string.

`nCmdShow` is a flag that indicates whether the main application 
            window is minimized, maximized, or shown normally.
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    
    MessageBox(NULL, TEXT("Hello from USER32!"), TEXT("HelloMSG"), MB_OKCANCEL | MB_DEFBUTTON2 | MB_ICONQUESTION);

     
    return 0;
}
