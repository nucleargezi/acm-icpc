#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N, K);
  Z f = [&]() -> string {
    STR(s);
    vc<int> a;
    FOR(i, si(s)) if (string("aeiou").find(s[i]) != -1ull) a.ep(i);
    if (si(a) < K) return {};
    return s.substr(a.end()[-K]);
  };

  bool aaaa = 1, aabb = 1, abab = 1, abba = 1;
  FOR(N) {
    vc<string> s;
    FOR(4) s.ep(f());
    FOR(i, 4) if (s[i].empty()) return NO();
    if (s[0] != s[1] or s[2] != s[3]) aaaa = aabb = 0;
    if (s[0] != s[2] or s[1] != s[3]) aaaa = abab = 0;
    if (s[0] != s[3] or s[1] != s[2]) aaaa = abba = 0;
  }
  if (aaaa) print("aaaa");
  else if (aabb) print("aabb");
  else if (abab) print("abab");
  else if (abba) print("abba");
  else NO();
}

int main() {
  Yorisou();
  return 0;
}