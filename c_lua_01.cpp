#include <iostream>

struct Player 
{
    std::string name;
    int age;

};

int main()
{
    Player p1;
    p1.name = "Nikki";
    p1.age = 42;

    Player p2;
    p2.name = "Brian";
    p2.age = 37;   

    std::cout << p1.name << " " << p1.age << std::endl;
    std::cout << p2.name << " " << p2.age << std::endl;

    return 0; 
}