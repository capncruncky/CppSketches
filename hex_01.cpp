//This sketch explores the usage of hexadecimal addresses and pointers
#include <iostream>

int main()
{
    //Initialize int and int*pointer
    int var = 0;
    int * ptr_int1 = &var;

    //Create loop to populate 15 addresses
    for(int i = 0; i<15; i++)
    {
        *ptr_int1 = i;
        std::cout << "Data @ " << &var+i << "\t" << *ptr_int1 << std::endl;
        ptr_int1 += 1;

    } 

    int result = (&var+14) - (&var+3);
    std::cout << result << std::endl;

    for (int i = 0; i < 15; i++)
    {
        std::cout << "Ptr_Data: " << ptr_int1 << "\t" << *ptr_int1 << std::endl;
        ptr_int1 += 1;
    }

    return 0;
}