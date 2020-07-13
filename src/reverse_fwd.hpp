#ifndef BETTER_CODE_ALGO_H
#define BETTER_CODE_ALGO_H

#include <algorithm>

namespace better_code {
namespace algo {

namespace detail {
template <class FwdIt>
void reverse_with_rotate(FwdIt f, FwdIt l) {
  auto n = std::distance(f, l);
  if (n == 0 || n == 1) return;

  auto m = std::next(f, n / 2);

  reverse_with_rotate(f, m);
  reverse_with_rotate(m, l);
  std::rotate(f, m, l);
}

template <class ForwardIterator, class N>
auto reverse_n(ForwardIterator f, N n) {
  if (n < 2) return std::next(f, n);

  auto h = n / 2;
  auto m1 = reverse_n(f, h);
  auto m2 = std::next(m1, n % 2);
  auto l = reverse_n(m2, h);

  std::swap_ranges(f, m1, m2);

  return l;
}

}  // namespace detail

template <class ForwardIterator>
void reverse_r(ForwardIterator f, ForwardIterator l) {
  detail::reverse_with_rotate(f, l);
}

template <class ForwardIterator>
void reverse_s(ForwardIterator f, ForwardIterator l) {
  detail::reverse_n(f, distance(f, l));
}

}  // namespace algo
}  // namespace better_code

#endif
