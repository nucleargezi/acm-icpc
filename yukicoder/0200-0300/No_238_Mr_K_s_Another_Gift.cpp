#include "YRS/all.hpp"
#include "YRS/string/hs.hpp"

void Yorisou() {
  STR(s);
  string rs = s;
  reverse(rs);
  hsh hs(s + rs);
  int N = len(s);
  Z pa = [&](int l, int r) {
    return hs.get(l, r) == hs.get(N + N - r, N + N - l);
  };

  FOR(lsz, N + 1) {
    int rsz = N - lsz, l = 0, r = lsz, ll = r, rr = N;
    if (lsz == rsz) {
      if (hs.get(l, r) == hs.get(N + N - rr, N + N - ll)) {
        return print(s.substr(l, lsz) + 'a' + s.substr(ll));
      }
    } else if (lsz < rsz) {
      if (hs.get(l, r) == hs.get(N + N - rr, N + N - (rr - lsz))) {
        rr -= lsz;
        char c = s[--rr];
        if (pa(ll, rr)) {
          return print(s.substr(l, lsz) + c + s.substr(ll));
        }
      }
    } else {
      if (hs.get(l, l + rsz) == hs.get(N + N - rr, N + N - ll)) {
        l += rsz;
        char c = s[l++];
        if (pa(l, r)) {
          return print(s.substr(0, lsz) + c + s.substr(lsz));
        }
      }
    }
  }
  print("NA");
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"