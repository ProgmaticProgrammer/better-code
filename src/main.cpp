#include <boost/range/algorithm.hpp>
#include <array>
#include <iostream>

using namespace boost;

int main(int argc, const char** argv) {
  std::array<int, 6> a{{2, 1, 0, 1, 0, 1}};
  std::cout << boost::count(a, 0) << '\n';
  auto p = boost::find (a, 0);
  std::cout << boost::distance(a.begin(), p) << '\n';
  return 0;
}
