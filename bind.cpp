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
  //структура с каким-то методом
  struct A {
    //foo(A &, int)
    void foo(int a) {
      std::cout << "call foo with " << a << "\n";
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
  //g0(x, y) = x^2 + y * x
  auto square = std::bind(std::multiplies< int >{}, _1, _1);
  auto g0 = std::bind(std::plus< int >{},
    square,
    std::bind(std::multiplies< int >{}, _1, _2)
    );
  std::cout << g0(2, 3) << "\n";
  //g1(x, y) = x^2 + y * x + y^2
  auto g1 = std::bind(std::plus< int >{},
    g0,
    std::bind(square, _2)
  );
  std::cout << g1(2, 3) << "\n";
  //bind to method
  goth::A a;
  auto bindToMethod = std::bind(&goth::A::foo, std::ref(a), _1);
  bindToMethod(100);
  std::cout << "\n";
}
