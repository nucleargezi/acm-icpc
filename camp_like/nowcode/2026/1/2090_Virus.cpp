#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  map<int, int> mp;
  mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = 1;
  FOR(N) {
    STR(s);
    int x = 0;
    FOR(i, 1, 8, 2) x += mp[s[i]];
    FOR(i, 0, 8, 2) x += not mp[s[i]];
    print((x == 8 and si(s) == 8) ? "Suspected Virus" : "Well-Being");
  }
}

int main() {
  Yorisou();
  return 0;
}