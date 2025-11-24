#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
struct dat {
  ll op, x, y;
};
map<string, vector<string>> st;
map<string, dat> mp;
PLL get(string s) {
  dat &w = mp[s];
  if (w.op == 0) return {w.x, w.y};
  Z &v = st[s];
  if (v.empty()) return w = {0, 0, 0}, PLL{0, 0};
  ll x = 0, y = 0;
  for (string &n : v) {
    Z [xx, yy] = get(n);
    if (w.op == 1) chmax(x, xx), y += yy;
    else chmax(y, yy), x += xx;
  }
  x += w.x << 1, y += w.x << 1;
  if (w.op == 1) y += w.y * (len(v) - 1);
  else x += w.y * (len(v) - 1);
  return w = {0, x, y}, PLL{x, y};
}
void Yorisou() {
  INT(N);
  cin.ignore();
  FOR(N) {
    string s;
    std::getline(cin, s);
    if (s[0] == 'W') {
      int a = s.find('('), b = s.find(','), c = s.find(')');
      string t = s.substr(7, a - 7);
      mp[t] = {0, std::stoll(s.substr(a + 1, b - a - 1)),
          std::stoll(s.substr(b + 1, c - b - 1))};
      st[t] = {};
    } else if (s[0] == 'V') {
      string t = s.substr(5);
      mp[t] = {1, 0, 0};
      st[t] = {};
    } else if (s[0] == 'H') {
      string t = s.substr(5);
      mp[t] = {2, 0, 0};
      st[t] = {};
    } else {
      int a = s.find('.'), b = s.find('('), c = s.find(')');
      string t = s.substr(0, a);
      if (s.substr(a + 1, b - a - 1) == "pack") {
        st[t].ep(s.substr(b + 1, c - b - 1));
      } else {
        ll x = std::stoll(s.substr(b + 1, c - b - 1));
        if (s.substr(a + 1, b - a - 1) == "set_border") {
          mp[t].x = x;
        } else {
          mp[t].y = x;
        }
      }
    }
  }
  for (Z &x : st) print(x.fi, get(x.fi));
}
#include "YRS/Z_H/main.hpp"