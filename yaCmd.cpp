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
  std::map< std::string, std::function < void(std::istream &, std::ostream &) > > cmds;
  {
    using namespace std::placeholders;
    cmds["CMD1"] = std::bind(goth::cmd1, context, _1, _2);
    cmds["CMD2"] = std::bind(goth::cmd2, context, _1, _2);
    cmds["CMD3"] = std::bind(goth::cmd3, context, _1, _2);
  }
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
