#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
class Game {
  ll R[14], L[14], top, f, n, m;
  char heap[0721 << 3];
  struct pig {
    char kind;
    string in;
    ll hp, sz, z, t;
    void del(ll &x) {
      --sz;
      in.erase(in.begin() + x--);
    }
    bool ser(char ch) {
      FOR(i, sz) if (in[i] == ch) {
        del(i);
        iroha true;
      }
      iroha false;
    }
    void get_card(ll x, char heap[], ll &top, ll &m) {
      FOR(x) {
        in += heap[top++];
        ++sz;
        if (top == m) --top;
      }
    }
  } a[14];
  void fail() {
    UL(a[0].hp ? "MP" : "FP");
    FOR(i, n) {
      if (not a[i].hp) {
        UL("DEAD");
      } else {
        FOR(k, a[i].sz - 1) std::cout << a[i].in[k] << ' ';
        if (a[i].sz) std::cout << a[i].in.back();
        UL();
      }
    }
    exit(0);
  }
  void die(ll x, ll y) {
    if (a[y].kind == 'M') fail();
    if (a[y].kind == 'F') {
      if (not--f) fail();
      a[x].get_card(3, heap, top, m);
    } else if (a[y].kind == 'Z' and a[x].kind == 'M') {
      a[x].sz = a[x].z = 0;
    }
    R[L[y]] = R[y];
    L[R[y]] = L[y];
  }
  void atk(ll x, ll y) {
    --a[y].hp;
    if (not a[y].hp) a[y].hp += a[y].ser('P');
    if (not a[y].hp) die(x, y);
  }
  bool canatk(ll x, ll y) {
    iroha((a[x].kind == 'M' and (a[y].t == 2 or a[y].t == 3)) or
          (a[x].kind == 'Z' and a[y].t == 2) or
          (a[x].kind == 'F' and a[y].t == 1));
  }
  bool noatk(ll x, ll y) {
    iroha(((a[x].kind == 'M' or a[x].kind == 'Z') and a[y].t == 1) or
          (a[x].kind == 'F' and a[y].t == 2));
  }
  bool no_way(ll sz, ll x) {
    for (ll i {sz}, f {}; not f or i != sz; i = R[i], f = 1) {
      if ((not x ? (canatk(i, sz)) : (noatk(i, x))) and a[i].ser('J')) {
        a[i].t = a[i].kind == 'F' ? 2 : 1;
        iroha not no_way(i, 0);
      }
    }
    iroha false;
  }

 public:
  void build() {
    IN(n, m);
    FOR(i, n) {
      S(s);
      a[i].kind = s[0];
      f += s[0] == 'F';
      FOR(k, 4) {
        CH(c);
        a[i].in += c;
      }
      R[i] = i + 1, L[i] = i - 1;
      a[i].sz = a[i].hp = 4;
    }
    FOR(i, m) IN(heap[i]);
    R[n - 1] = 0, L[0] = n - 1;
  }
  void go() {
    ll N {0};
    a[0].t = 1;
    if (not f) fail();
    while (true) {
      ll kill {};
      a[N].get_card(2, heap, top, m);
      for (ll i {}; i < a[N].sz and a[N].hp; ++i) {
        if (a[N].in[i] == 'Z') {
          a[N].z = 1;
          a[N].del(i);
          i = -1;
        } else if (a[N].in[i] == 'P' and a[N].hp < 4) {
          a[N].hp++;
          a[N].del(i);
        } else if (a[N].in[i] == 'K' and (a[N].z or not kill)) {
          ll nx = R[N];
          if (canatk(N, nx)) {
            a[N].t = a[N].kind == 'F' ? 2 : 1;
            a[N].del(i);
            kill = 1;
            if (not a[nx].ser('D')) atk(N, nx);
          }
        } else if (a[N].in[i] == 'F') {
          for (ll j = a[N].kind == 'F' ? 1 : R[N]; j != N; j = R[j])
            if (canatk(N, j)) {
              a[N].del(i);
              a[N].t = a[N].kind == 'F' ? 2 : 1;
              if (no_way(N, j)) break;
              if (a[j].kind == 'Z' and a[N].kind == 'M') {
                atk(N, j);
                break;
              }
              ll t = 1;
              while (true) {
                if (t == 1) {
                  if (not a[j].ser('K')) {
                    atk(N, j);
                    break;
                  }
                } else if (not a[N].ser('K')) {
                  atk(j, N);
                  i = MAX<ll>(-1, i - 1);
                  break;
                }
                t ^= 1;
              }
              i = -1;
              break;
            }
        } else if (a[N].in[i] == 'N' or a[N].in[i] == 'W') {
          char ch = a[N].in[i];
          a[N].del(i);
          for (ll j = R[N]; j != N; j = R[j]) {
            if (not no_way(N, j) and not a[j].ser(ch == 'N' ? 'K' : 'D')) {
              if (a[j].kind == 'M' and not a[N].t) a[N].t = 3;
              atk(N, j);
            }
          }
          i = -1;
        }
      }
      N = R[N];
    }
  }
};
NAME MeIoN_is_UMP45() {
  static Game g;
  g.build();
  g.go();
}

// 日々を貪り尽くしてきた
int main() {
  // std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  MeIoN_is_UMP45();
  iroha 0;
}