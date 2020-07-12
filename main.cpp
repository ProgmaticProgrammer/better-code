#include <Registry.hpp>
#include <chrono>
#include <iostream>

#include "after_idle.hpp"

void print_int(int i) { std::cout << i << "\n"; }

using namespace better_code::v1;

int main() {
  using namespace std::chrono_literals;
  auto five_sec = 5s;
  //after_idle(five_sec, [] { std::cout << "done!\n"; });
  // {
  //   RegistryMap<int> ints_reg;
  //   Receipt receipt1 = ints_reg.add(1);
  //   Receipt receipt2 = ints_reg.add(2);

  //   ints_reg.apply_each(print_int);

  //   if (ints_reg.remove(receipt1))
  //     std::cout << "remove receipt 1 successfully.\n";

  //   ints_reg.apply_each(print_int);
  // }

  // {
  //   RegistryVector<int> ints_regv;
  //   std::vector<Receipt> receipts;
  //   for (auto i = 0; i != 10; ++i) {
  //     auto receipt = ints_regv.add(i);
  //     receipts.push_back(receipt);
  //   }

  //   ints_regv.apply_each(print_int);

  //   for (const auto& receipt : receipts) {
  //     std::cout << "remove Receipt: " << receipt << "\n";
  //     ints_regv.remove(receipt);
  //   }
  // }
  constexpr auto bound = 10'000'000ull;
  {
    // record start time
    auto start = std::chrono::high_resolution_clock::now();
    RegistryVector<uint64_t> ints_regv;
    std::vector<Receipt> receipts;

    for (uint64_t i = 0; i != bound; ++i) {
      auto receipt = ints_regv.add(i);
      receipts.push_back(receipt);
    }
    // record end time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "vector: Time to fill " << bound << " " << diff.count()
              << " s\n";
  }
  {
    // record start time
    auto start = std::chrono::high_resolution_clock::now();
    RegistryMap<uint64_t> ints_regv;
    std::vector<Receipt> receipts;
    for (uint64_t i = 0; i != bound; ++i) {
      auto receipt = ints_regv.add(i);
      receipts.push_back(receipt);
    }
    // record end time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "map: Time to fill " << bound << " " << diff.count() << " s\n";
  }

  return 0;
}