#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using mint = mint_t<1'000'000 + 3>;
void Yorisou() {
  map<int, vc<int>> mp;
  mp['>'] = {1, 0, 0, 0};
  mp['<'] = {1, 0, 0, 1};
  mp['+'] = {1, 0, 1, 0};
  mp['-'] = {1, 0, 1, 1};
  mp['.'] = {1, 1, 0, 0};
  mp[','] = {1, 1, 0, 1};
  mp['['] = {1, 1, 1, 0};
  mp[']'] = {1, 1, 1, 1};
  STR(s);
  mint rs;
  for (int c : s) for (int x : mp[c]) rs = rs * 2 + x;
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}