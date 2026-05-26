#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  CH(C);
  STR(a, b);
  map<char, int> mp;
  int t = 0;
  FOR(i, 6, 10) mp[i + '0'] = t++;
  for (char c : {'T', 'J', 'Q', 'K', 'A'}) mp[c] = t++;
  if (a[1] == b[1] and mp[a[0]] > mp[b[0]]) return YES();
  if (a[1] == C and b[1] != C) return YES();
  NO();
}

int main() {
  Yorisou();
  return 0;
}