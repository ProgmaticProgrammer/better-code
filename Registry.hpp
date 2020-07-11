#ifndef BETTER_CODE_REGISTRY_HPP
#define BETTER_CODE_REGISTRY_HPP
/**
 * A registry is a container supporting
 *  - add an object and return a binding receipt
 *  - retrieve or remove the receipt binding object
 *  - operate on all containing objects
 *
 * Example: signal handler
 *
 **/
#include <algorithm>
#include <optional>
#include <unordered_map>
#include <vector>

namespace better_code {
namespace v1 {

using Receipt = size_t;

template <class T>
class RegistryMap {
 private:
  using key_t = Receipt;
  using value_t = T;
  using container_t = std::unordered_map<Receipt, T>;

  container_t map_;
  size_t id_ = 0u;

 public:
  auto add(value_t obj) -> Receipt {
    map_.emplace(id_, std::move(obj));
    return Receipt{id_++};
  }

  bool remove(Receipt receipt) { return 0 < map_.erase(receipt); }

  template <typename Func>
  void apply_each(Func f) const {
    for (const auto& e : map_) {
      f(e.second);
    }
  }
};

template <class T>
class RegistryVector {
 private:
  using value_t = T;
  using element_t = std::pair<Receipt, std::optional<T>>;
  using container_t = std::vector<element_t>;

  container_t map_;
  size_t size_ = 0u;
  size_t id_ = 0u;

 public:
  auto add(value_t obj) -> Receipt {
    map_.emplace_back(id_, std::move(obj));
    ++size_;
    return Receipt{id_++};
  }

  bool remove(Receipt receipt) {
    auto p = std::lower_bound(
        std::begin(map_), std::end(map_), receipt,
        [](const auto& a, const auto& b) { return a.first < b; });
    if (p == std::end(map_) || p->first != receipt || !p->second) {
      return false;
    }

    p->second.reset();
    --size_;

    if (size_ < map_.size() / 2) {
      std::cout << "size_" << size_ << "\n";
      std::cout << "map_size_" << map_.size() << "\n";
      std::cout << "map_ erase\n";
      map_.erase(std::remove_if(std::begin(map_), std::end(map_),
                                [](const auto& e) { return !e.second; }),
                 std::end(map_));
      std::cout << "map_size_" << map_.size() << "\n";
    }

    return true;
  }

  template <typename Func>
  void apply_each(Func f) const {
    for (const auto& e : map_) {
      if (e.second) f(*e.second);
    }
  }
};

}  // namespace v1
}  // namespace better_code

#endif