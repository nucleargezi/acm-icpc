#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/game/poker.hpp"

bool vis[4][15];
int to[200];

PII gen() {
  char a, b;
  IN(a, b);
  int x = to[(int)b], y = to[(int)a];
  vis[x][y] = 1;
  return {x, y};
}

void Yorisou() {
  static array<PII, 5> a, b;
  FOR(i, 4) a[i] = gen();
  FOR(i, 4) b[i] = gen();
  bool al = 1, mv = 0;
  FOR(i, 52) {
    int x = i / 13, y = i % 13 + 2;
    if (vis[x][y]) continue;
    vis[x][y] = 1;
    b[4] = {x, y};
    bool fl = 1, w = 0;
    FOR(i, 52) {
      int x = i / 13, y = i % 13 + 2;
      if (vis[x][y]) continue;
      a[4] = {x, y};
      Z f(holdem(a)), t(holdem(b));
      w |= f > t;
      fl &= t > f;
    }
    al &= w;
    mv |= fl;
    vis[x][y] = 0;
    if (mv) break;
  }
  if (al) print("WoYaoYanPai");
  else if (mv) print("GeiWoCaPiXie");
  else print("PaiMeiYouWenTi");
  FOR(i, 4) vis[a[i].fi][a[i].se] = 0;
  FOR(i, 4) vis[b[i].fi][b[i].se] = 0;
}

int main() {
  static constexpr string a = "0123456789TJQKA", b = "CDHS";
  FOR(i, 2, 15) to[(int)a[i]] = i;
  FOR(i, 4) to[(int)b[i]] = i;
  INT(T);
  FOR(T) Yorisou();
  return 0;
}