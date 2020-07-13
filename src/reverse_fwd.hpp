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
auto reverse_n(ForwardIterator first_of_full_range, N length) {
  // already reverved, so return end_of_the_range
  if (length < 2) return std::next(first_of_full_range, length);
  //  1st rng 2nd rng
  //  (12345).(67890)
  //  (54321).(09876)
  //  (09876).(54321)

  auto first_of_first_range = first_of_full_range;
  auto half_length = length / 2;
  auto last_of_first_range = reverse_n(first_of_first_range, half_length);
  auto first_of_second_range = std::next(last_of_first_range, length % 2);
  auto last_of_second_range = reverse_n(first_of_second_range, half_length);

  std::swap_ranges(first_of_first_range, last_of_first_range, first_of_second_range);

  return last_of_second_range;
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
