//#include <algorithm>
//#include <cassert>
//#include <iostream>
//#include <utility>
#include <forward_list>
#include "reverse_fwd.hpp"

//using std::cout;
//using std::endl;
//using std::max;
//using std::min;
//using std::pair;
//using std::string;
using std::forward_list;

namespace subtile_defects {

template <typename T>
const T& clamp(const T& a, const T& lo, const T& hi) {
  return min(max(a, lo), hi);
}

template <typename T, typename Compare>
const T& clamp(const T& a, const T& lo, const T& hi, Compare comp) {
  return min(max(a, lo, comp), hi, comp);
}

}  // namespace subtile_defects

namespace cppreference {
template <class T>
constexpr const T& clamp(const T& v, const T& lo, const T& hi) {
  assert(!(hi < lo));
  return (v < lo) ? lo : (hi < v) ? hi : v;
}

template <class T, class Compare>
constexpr const T& clamp(const T& v, const T& lo, const T& hi, Compare comp) {
  assert(!comp(hi, lo));
  return comp(v, lo) ? lo : comp(hi, v) ? hi : v;
}

}  // namespace cppreference

int main(int, char**) {
  // int a[0]; compile error
  // constexpr auto x = 0.0 / 0.0;
  using OneDArray = int[3];
  constexpr OneDArray arr[2] = {{1, 1, 1}, {2, 2, 2}};

  //using empty = std::array<int,0>;

  //using pair = pair<int, string>;

  //pair a = {1, "OK"};
  //pair lo = {1, "FAIL: LO"};
  //pair hi = {2, "FAIL: HI"};

  //auto& result1 = subtile_defects::clamp(
  //    a, lo, hi,
  //    [](const auto& a, const auto& b) { return a.first < b.first; });
  //cout << result1.second << endl;

  //auto& result2 = std::clamp(a, lo, hi, [](const auto& a, const auto& b) {
  //  return a.first < b.first;
  //});
  //cout << result2.second << endl;

  //auto& result3 = cppreference::clamp(
  //    a, lo, hi,
  //    [](const auto& a, const auto& b) { return a.first < b.first; });
  //cout << result3.second << endl;

  forward_list<int> l = {1, 2, 3};

  better_code::algo::reverse_r(l.begin(), l.end());
  better_code::algo::reverse_s(l.begin(), l.end());

  return 0;
}
