#ifndef AFTER_IDLE_HEADER
#define AFTER_IDLE_HEADER

#include <chrono>
#include <functional>

namespace better_code {
namespace v1 {

// using system_clock = std::chrono::system_clock;
// using time_point = system_clock::time_point;
// using duration = std::chrono::milliseconds;

// extern time_point _last_idle;

// void invoke_after(duration, std::function<void()>);

// template <class F>
// void after_idle(duration delay, F task) {
//   auto when = delay - (system_clock::now() - _last_idle);
//   if (system_clock::duration::min() < when) {
//     invoke_after(when, [=] { after_idle(delay, task); });
//   } else {
//     task();
//   }
// }

namespace detail {

template <class S, class T, class F>
void on_expiration_(S scheduler, T timer, F task) {
  auto remaining = timer();
  if (decltype(remaining){0} < remaining) {
    scheduler(remaining, [=] { on_expiration_(scheduler, timer, task); });
  } else {
    task();
  }
}

template <class S, class T, class F>
void on_expiration(S scheduler, T timer, F task) {
  scheduler(timer(),
            [=] { detail::on_expiration_(scheduler, timer, task); });
}

}  // namespace implementation

}  // namespace v1
}  // namespace better_code
#endif