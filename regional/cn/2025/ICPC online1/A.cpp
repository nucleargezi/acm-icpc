#include "YRS/Z_H/MeioN.hpp"
#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/all.hpp"

#define tests
constexpr int N = 26;
struct dat {
  int s;
  int dir;
  bool vis[N];
  int c[N];
};
void Yorisou() {
  INT(N);
  using T = tuple<string, char, int, string>;
  VEC(T, a, N);
  sort(a, [&](const Z &L, const Z &R) -> bool {
    return std::get<2>(L) < std::get<2>(R);
  });
  map<string, dat> pass, fail;
  for (Z [team, prob, time, state] : a) {
    int x = prob - 'A';
    Z &s = fail[team];
    if (not s.vis[x]) {
      if (state == "Accepted") {
        s.s += 1;
        s.dir -= s.c[x] * 20 + time;
        s.vis[x] = 1;
      } else if (state == "Rejected") {
        s.c[x] += 1;
      }
    }
  }
  for (Z [team, prob, time, state] : a) {
    int x = prob - 'A';
    Z &s = pass[team];
    if (not s.vis[x]) {
      if (state == "Accepted" or state == "Unknown") {
        s.s += 1;
        s.dir -= s.c[x] * 20 + time;
        s.vis[x] = 1;
      } else if (state == "Rejected") {
        s.c[x] += 1;
      }
    }
  }
  PII mx = {-1, -1};
  for (Z &[team, s] : fail) {
    chmax(mx, PII{s.s, s.dir});
  }
  vector<string> ans;
  for (Z &[team, s] : pass) {
    if (mx <= PII{s.s, s.dir}) {
      ans.emplace_back(team);
    }
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"