#include <iostream>
#include <map>
#include <functional>
#include <limits>
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
 void cmd4(const int &, std::istream &, std::ostream & out)
  {
    //...
    out << "hello goth programmer nation!!!\n";
    throw std::overflow_error("overflow cmd4");
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
    cmds["CMD4"] = std::bind(goth::cmd4, context, _1, _2);
  }
  std::string cmd;
  while (std::cin >> cmd)
  {
    try
    {
      cmds.at(cmd)(std::cin, std::cout);
    }
    catch (const std::overflow_error & e)
    {
      std::cerr << "<GOTH_ERROR: " << e.what() << ">\n";
    }
    catch (const std::out_of_range &)
    {
      std::cerr << "<INVALID COMMAND>\n";
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    }
  }
}
