#pragma once

#include "common.hpp"

namespace framework {
struct mail {
  uint64_t to;
  std::string kind;
  std::string body;

  mail(uint64_t to, const std::string_view kind, const std::string_view body)
      : to(to), kind(kind), body(body) {}
};

class postalservice {
public:
  postalservice() = default;

  void post(const mail &message);
};
}
