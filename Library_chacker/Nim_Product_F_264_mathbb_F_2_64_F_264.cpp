#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/nt/nim/nimbase.hpp"

void Yorisou() {
  INT(Q);
  FOR(Q) {
    ULL(a, b);
    print(nim.ml(a, b));
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"