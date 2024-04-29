#include <iostream>
namespace goth
{
  void cmd1(std::istream &, std::ostream & out)
  {
    out << "CMD1 dispatched\n";
  }
  void cmd2(std::istream &, std::ostream & out)
  {
    out << "CMD2 dispatched\n";
  }
}
int main()
{
  std::string cmd;
  while (std::cin >> cmd)
  {
    if (cmd == "CMD1")
      {
        goth::cmd1(std::cin, std::cout);
      }
    else if (cmd == "CMD2")
      {
        goth::cmd2(std::cin, std::cout);
      }
    else
      {
        std::cerr << "<INVALID COMMAND>\n";
      }
  }
}
