/*
MAC_conv-v0.0.1 - Programmed by capncruncky
This program is designed to be a simple CLI MAC address conversion tool
github.com/capncruncky/CppSketches
*/

#include <iostream>
#include <string>
#include <stdlib.h>

//Prototypes
std::string cleanMAC(std::string macAddress); //convert MAC address
void deciMAC(std::string cleanMAC); //convert clean MAC to decimal notation
void hexaMAC(std::string cleanMAC); //convert clean MAC to hexadecimal notation

//Main
int main(int argc, const char *argv[])
{
  //check for minimum arguments
  if (argc < 2)
  {
    std::cout << "Usage: MAC_conv <option> <file>\n";
    return 1;
  }

  //switch options
  if (argv[1][0] == '-')
  {
    if (argv[1][1] == 'd')
    {
      //std::cout << "Converting to decimal ...\n";
      std::string rawMAC = cleanMAC(argv[2]);

      //Check for valid MAC address
      if (rawMAC.length() != 12)
      {
        std::cout << "Too many characters. Please enter valid MAC address" << "\n";
        return 1;   //exit to OS
      }

      //If ok, continue conversion...
      deciMAC(rawMAC);

    }
    else if (argv[1][1] == 'h')
    {
      //std::cout << "Converting hexadecimal to decimal...\n";
      std::string rawMAC = cleanMAC(argv[2]);

      //Check for valid MAC address
      if (rawMAC.length() != 12)
      {
        std::cout << "Invalid MAC address \nPlease enter valid MAC address" << "\n";
        return 1;   //exit to OS
      }

      //If ok, continue conversion...
      hexaMAC(rawMAC);

    }
    else
    {
      std::cout << "Usage: MAC_conv -<option> <file>\n";
      std::cout << "Use: MAC_conv help for additional help\n";
      return 1;
    }
  }
  else if (argv[1][0] == 'h' && argv[1][1] == 'e' && argv[1][2] == 'l' && argv[1][3] == 'p')
  {
    std::cout << "Help: " << std::endl;
  }
  else
  {
    std::cout << "Usage: MAC_conv -<option> <file>\n";
    std::cout << "Use: MAC_conv help for additional help\n";
    return 1;
  }

  //exit to OS
  return 0;
}

/************************************************************
 This function will remove any ':' and '.' from the MAC macAddress
************************************************************/
std::string cleanMAC(std::string macAddress)
{
  for (auto it = macAddress.begin(); it != macAddress.end();++it)
  {
    if( *it == ':' || *it == '.')
    {
      it = macAddress.erase(it); //erase, return pointer to it
    }
  }

  return macAddress;
}

/*************************************************************/
//convert clean MAC to decimal notation
void deciMAC(const std::string cleanMAC)
{
  std::string deciMAC = cleanMAC;

  for( auto it = deciMAC.begin(); it != deciMAC.end(); ++it)
  {
    if( it == deciMAC.begin()+4 || it == deciMAC.begin()+9)
    {
      deciMAC.insert(it,'.');
    }
  }
  std::cout << deciMAC << "\n";
}

/*************************************************************/
//convert clean MAC to hexadecimal notation
void hexaMAC(const std::string cleanMAC)
{
  std::string hexaMAC = cleanMAC;

  /*This for loop uses std::min to compare the values of the number of
  characters in the string minus the position of 'it' or 2 to prevent out of bounds*/
  for( auto it = hexaMAC.begin(); it != hexaMAC.end(); it += std::min<int>(hexaMAC.end() - it, 2))
  {
      it = (it != hexaMAC.begin() ? hexaMAC.insert(it,':') + 1 : it);
  }

  std::cout << hexaMAC << "\n";
}
