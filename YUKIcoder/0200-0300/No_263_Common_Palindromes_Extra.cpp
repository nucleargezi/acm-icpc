#include "YRS/all.hpp"
#include "YRS/string/enum_dif_pa.hpp"

void Yorisou() {
  STR(l, r);
  hashmap a = enum_diff_pa(l), b = enum_diff_pa(r);
  ll s = 0;
  for (Z [x, c] : a.get_all()) {
    s += c * b.get(x, 0);
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"