//pointer_02.cpp by capncruncky - github.com/capncruncky
#include <iostream>
#include <cstring> //library for memset()

int main()
{
    //Here we will create an array on the stack memory
    int stackArray[10];

    //Here we cycle through the array and list the memory location and values
    for (int &i : stackArray)
    {
        std::cout << "\tmemLoc: " << (&i);
        std::cout << "\t value: " << i << std::endl;
    }
    std::cout << "\n";

    //Here we will create an array on the heap memory
    int* heapArray = new int[10];
    std::memset(heapArray, 0, 10);

    //Here we will again cycle through...
    for (int i = 0; i < 10; i++ )
    {
        std::cout << "\tmemLoc: " << &heapArray + i;
        std::cout << "\t value: " << *heapArray + i << std::endl;
    }
    std::cout << "\n";

    //Create int pointer
    int* ptr_int = &stackArray[0];

     for (int i = 0; i < sizeof(stackArray)/sizeof(int); i++)
    {
        std::cout << "\titLoc: " << &i;
        std::cout << "\tmemLoc: " << (&stackArray + i);
        std::cout << "\t value: " << stackArray[i] << std::endl;
    }
    std::cout << "\n";

    //Here we will use memset to zero out the array values
    std::memset(stackArray, 0, sizeof(stackArray));

    for (int i = 0; i < sizeof(stackArray)/sizeof(int) + 1; i++)
    {
        std::cout << "\titLoc: " << &i;
        std::cout << "\tmemLoc: " << &stackArray[i];
        std::cout << "\t value: " << stackArray[i] << std::endl;
    }

    return 0;
}