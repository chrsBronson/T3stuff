#include <iostream>
#include <map>
#include <functional>
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
  std::map< std::string, std::function < void(std::istream &, std::ostream &) > > cmds;
  cmds["CMD1"] = goth::cmd1;
  cmds["CMD2"] = goth::cmd2;
  std::string cmd;
  while (std::cin >> cmd)
  {
    try
    {
      cmds.at(cmd)(std::cin, std::cout);
    }
    catch (const std::out_of_range &)
    {
      std::cerr << "<INVALID COMMAND>\n";
    }
  }
}
