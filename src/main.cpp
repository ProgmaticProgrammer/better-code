#include <chrono>
#include <fstream>
#include <future>
#include <iostream>
#include <numeric>

#include "FibBase.h"
#include "Fibonacci.h"
using std::cout;
using std::endl;
using namespace fibonacci_namespace;
// calculate 1,000,000th Fibonacci number
// save it to file and calculation time as well
int main() {
  auto start = std::chrono::steady_clock::now();
  // std::future<cpp_int> x = std::async([] { return fibonacci(1'000'000);
  // });//call nontemplate one, 20s

  // std::future<cpp_int> x = std::async([] { return
  // fibonacci<cpp_int>(1'000'000); });//return immediately auto result =
  // x.get();

  cpp_int result = fibonacci<cpp_int, size_t>(1000000);  // 3s

  auto end = std::chrono::steady_clock::now();

  std::chrono::duration<double> elapsed_seconds = end - start;
  std::ofstream ofs{"test.txt", std::ofstream::out};
  ofs << "elapsed time: " << elapsed_seconds.count() << "s\n";

  ofs << result << "n";
  return 0;
}

// int main() {
//   cout << FibBase<size_t, 0>::value[0] << endl;
//   cout << FibBase<size_t, 1>::value[0] << endl;
//   cout << FibBase<size_t, 2>::value[0] << endl;
//   cout << FibBase<size_t, 3>::value[0] << endl;
//   cout << FibBase<size_t, 4>::value[0] << endl;

//   return 0;
// }
