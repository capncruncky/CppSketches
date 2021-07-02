#include <iostream>
#include <cstring>

int main()
{
    //Declare variable and pointer to variable
    int number = 5;
    int* ptr_number = &number;

    std::cout << "*********************************************************" << std::endl;
    std::cout << "We've stored the value " << number << " into the 'number' variable..." << std::endl;
    std::cout << "We've also referenced that variable with a pointer, ptr_number..." << std::endl;
    std::cout << "\tDereferencing ptr_number: " << *ptr_number << std::endl;
    std::cout << "\tptr_number value: " << ptr_number << std::endl;
    std::cout << "This above value is the memory location for the variable 'number'" << std::endl;
    std::cout << std::endl;

    //Here we create an array of integers on the heap memory
    //and use an interger pointer 'buffer' to point to the first
    //element of the array
    //we also zero out the array using 'memset'
    int* buffer = new int[26];
    std::memset(buffer, 0, 26);

    std::cout << "*********************************************************" << std::endl;
    std::cout << "Here we will loop through the array and ID each element's " << std::endl;
    std::cout << "memory location as well as its value..." << std::endl;

    for (int i = 0; i < 26; i++)
    {
        //std::cout << "Memset value: " << buffer[i];
        std::cout << "\tmemLoc: " << &buffer[i];
        std::cout << "\tvalue: " << *buffer << std::endl;
        *buffer += sizeof(char);
    }

    delete[] buffer;
    return 0;
}