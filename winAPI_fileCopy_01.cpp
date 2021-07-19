//This program is based on the example program offered in "Windows System Programming", 4th edition
//by Johnson M. Hart (Pearson, 2010)
//Program 1-3, pg 19

//This program offers an example of using the fileCopy Windows API function

#include <windows.h>
#include <iostream>

int main(int argc, LPTSTR argv[])
{
    if (argc != 3) 
    {
        std::cout << "Usage: winAPI_fileCopy_01 file1 file2\n" << std::endl;
        return 1;
    }

    if(!CopyFile(argv[1], argv[2], FALSE))
    {
        std::cout << "CopyFile Error: " << GetLastError() << std::endl;
        return 2;
    }

    return 0;
}