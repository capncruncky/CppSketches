//This code will explore the struct and access using pointers
#include <iostream>

struct SongData 
{
    char *title;
    char *keySig;
    int tempo;
};

struct Rectangle
{
    int x;
    int y;
};

int main()
{
    //Create instance of songData
    struct SongData song1;

    //Populate data in struct
    song1.title = "Surface_Submarine\0";
    song1.keySig = "G\0";
    song1.tempo = 150;

    //Create struct pointer and access data
    struct SongData *ptr_struct = &song1;
    char* title = ptr_struct->title;
    char* key = ptr_struct->keySig;
    int temp = ptr_struct->tempo;

    std::cout << "Title: " << title << "\t" << &title << std::endl;
    std::cout << "KeySign: " << key << "\t" << &key << std::endl;
    std::cout << "Tempo: " << temp << "\t" << &temp << std::endl;

    //Create instance of rectangle
    struct Rectangle rect1;

    //Populate rectangle info
    rect1.x = 3;
    rect1.y = 5;

    //Create struct pointer and access data
    struct Rectangle *ptr_rect = &rect1;

    std::cout << "X: " << ptr_rect->x << "\t" << &ptr_rect->x << std::endl;
    std::cout << "Y: " << ptr_rect->y << "\t" << &ptr_rect->y << std::endl;

    //Create pointer to view 4 bytes
    int* ptr_int = (int *)ptr_rect;
    int var = *ptr_int;
    //int var = *((int *)ptr_rect);

    std::cout << "var: " << var << "\t" << &var << std::endl;

    //Move ahead pointer...
    var = *(ptr_int + 1);

    std::cout << "var+1: " << var << "\t" << &var << std::endl;

    int* ptr_int2 = (int *)0x61fe8c;

    std::cout << "ptr_int2: " << *ptr_int2 << std::endl;

    //Create null pointer
    int *ptr_null = (int *)0x61fe00;

    std::cout << "ptr_null: " << *ptr_null << std::endl;


    return 0;
}


