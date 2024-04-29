#include <iostream>
#include <map>
#include <functional>
namespace goth
{
  void cmd1(int &, std::istream &, std::ostream & out)
  {
    out << "CMD1 dispatched\n";
  }
  void cmd2(int &, std::istream &, std::ostream & out)
  {
    out << "CMD2 dispatched\n";
  }
 void cmd3(const int &, std::istream &, std::ostream & out)
  {
    out << "CMD3 dispatched\n";
  }
}
int main()
{
  int context = 0;
  std::map< std::string, std::function < void(int &, std::istream &, std::ostream &) > > cmds;
  cmds["CMD1"] = goth::cmd1;
  cmds["CMD2"] = goth::cmd2;
  std::map< std::string, std::function < void(const int &, std::istream &, std::ostream &) > > const_cmds;
  const_cmds["CMD3"] = goth::cmd3;
  std::string cmd;
  while (std::cin >> cmd)
  {
    try
    {
      cmds.at(cmd)(context, std::cin, std::cout);
    }
    catch (const std::out_of_range &)
    {}
    try
    {
      const_cmds.at(cmd)(context, std::cin, std::cout);
    }
    catch (const std::out_of_range &)
    {
      std::cerr << "<INVALID COMMAND>\n";
    }
  }
}
