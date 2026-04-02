#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint61.hpp"
#include "YRS/ds/basic/hashmap.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = m61;
void Yorisou() {
  STR(str);
  int N = len(str);
  hash_map<char> se;
  FOR(s, 1 << N) {
    string a;
    int l = 0, r = N;
    FOR(i, N) {
      if (s >> i & 1) a += str[l++];
      else a += str[--r];
    }
    mint hs;
    for (char c : a) hs = hs * 131 + c;
    se[hs.val()] = 1;
  }
  print(len(se));
}
#include "YRS/aa/main.hpp"