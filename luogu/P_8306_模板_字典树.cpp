#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

char I[0721];
void before() {
  char id = 0;
  for (char i = 'a'; i <= 'z'; ++i) {
    I[i] = id++;
  }
  for (char i = 'A'; i <= 'Z'; ++i) {
    I[i] = id++;
  }
  for (char i = '0'; i <= '9'; ++i) {
    I[i] = id++;
  }
}

#define tests
constexpr int N = 3'000'000, W = 26 + 26 + 10;
struct trie {
  int tr[N][W];
  int cnt[N];
  int tot;

  void insert(const string &s, char off) {
    int p = 0;
    for (char c : s) {
      c -= off;
      if (not tr[p][c]) {
        tr[p][c] = ++tot;
      }
      p = tr[p][c];
      ++cnt[p];
    }
  }
  int count(const string &s, char off) {
    int p = 0;
    for (char c : s) {
      c -= off;
      if (not tr[p][c]) return 0;
      p = tr[p][c];
    }
    return cnt[p];
  }
  void clear() {
    memset(tr, 0, sizeof(int) * (tot + 1) * W);
    memset(cnt, 0, sizeof(int) * (tot + 1));
    tot = 0;
  }
} tr;
void Yorisou() {
  tr.clear();
  LL(n, q);
  FOR(n) {
    S(s);
    for (char &c : s) c = I[c];
    tr.insert(s, 0);
  }
  FOR(q) {
    S(s);
    for (char &c : s) c = I[c];
    UL(tr.count(s, 0));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"