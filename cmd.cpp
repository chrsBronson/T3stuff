#include <iostream>
int main()
{
  std::string cmd;
  //contextCMD1
  //contextCMD2
  while (std::cin >> cmd)
  {
    if (cmd == "CMD1")
      {
        //input paramsCMD1
        //do smth with contextCMD1 and paramsCMD1
      }
    else if (cmd == "CMD2")
      {
        //input paramsCMD2
        //do smth with contextCMD2 and paramsCMD2
      }
    else
      {
        std::cerr << "<INVALID COMMAND>\n";
      }
  }
}
