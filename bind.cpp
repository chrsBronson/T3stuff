#include <iostream>
#include <functional>
namespace goth
{
  //Функция
  //          _1     _2
  int plus(int a, int b) {
    return a + b;
  }
  //Функтор
  struct Plus {
    int operator() (int a, int b) {
      return plus(a, b);
    }
  };
}
int main()
{
  int x = 10;
  int y = -5;
  //x + y
  std::cout << goth::plus(x, y) << "\n";
  //plus(5, _2) -> plus5(_2)
  using namespace std::placeholders;
  //auto plus5 = std::bind(goth::plus, 5, _1);
  std::function < int(int) > plus5 = std::bind(goth::plus, 5, _1);
  std::cout << plus5(15) << "\n";
  //f(x) = x + x
  auto f2x = std::bind(std::plus< int >{}, _1, _1);
  std::cout << f2x(3) << "\n";
  //f(x) = 2 * x
  auto yaf2x = std::bind(std::multiplies< int >{}, 2, _1);
  std::cout << yaf2x(20) << "\n";
}
