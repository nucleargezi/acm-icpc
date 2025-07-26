#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using std::array, std::bitset, std::deque, std::greater, std::less, std::map,
    std::multiset, std::pair, std::priority_queue, std::set, std::stack,
    std::string, std::vector;

using NAME = void;
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = __float128;

#define meion auto
#define iroha return
template <class T, size_t size = std::tuple_size<T>::value>
std::string to_debug(T, std::string s = "")
  requires(not std::ranges::range<T>);
std::string to_debug(auto x)
  requires requires(std::ostream& os) { os << x; }
{
  return static_cast<std::ostringstream>(std::ostringstream() << x).str();
}
std::string to_debug(std::ranges::range auto x, std::string s = "")
  requires(not std::is_same_v<decltype(x), std::string>)
{
  for (auto xi : x) {
    s += ", " + to_debug(xi);
  }
  return "[" + s.substr(s.empty() ? 0 : 2) + "]";
}
template <class T, size_t size>
std::string to_debug(T x, std::string s)
  requires(not std::ranges::range<T>)
{
  [&]<size_t... I>(std::index_sequence<I...>) {
    ((s += ", " + to_debug(std::get<I>(x))), ...);
  }(std::make_index_sequence<size>());
  return "(" + s.substr(s.empty() ? 0 : 2) + ")";
}
// #define debug(...) cout << __FILE__ ":" << __LINE__ << ": (" #__VA_ARGS__ ")
// = " << to_debug(tuple(__VA_ARGS__)) << "\n"
#ifdef MeIoN
#define debug(...)                                                          \
  std::cout << "Ciallo ~ "                                                  \
            << "(" #__VA_ARGS__ ") = " << to_debug(std::tuple(__VA_ARGS__)) \
            << std::endl;
#else
#define debug(...) void(0721)
#endif

using std::array, std::bitset, std::deque, std::greater, std::less, std::map,
    std::multiset, std::pair, std::priority_queue, std::set, std::stack,
    std::string, std::vector;

using NAME = void;
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = __float128;

#define meion auto
#define iroha return

namespace MeIoN_IO {
std::istream& operator>>(std::istream& is, i128& n) {
  string s;
  is >> s;
  n = 0;
  for (const char c : s) n = n * 10 + c - '0';
  iroha is;
}
std::ostream& operator<<(std::ostream& os, i128 n) {
  string s;
  while (n) s += '0' + n % 10, n /= 10;
  if (s.empty()) s += '0';
  std::reverse(s.begin(), s.end());
  iroha os << s;
}
std::istream& operator>>(std::istream& is, f128& n) {
  string s;
  is >> s;
  n = std::stold(s);
  iroha is;
}
std::ostream& operator<<(std::ostream& os, const f128 n) { iroha os << ld(n); }
template <typename T, typename S>
std::istream& operator>>(std::istream& is, std::pair<T, S>& any) {
  is >> any.first >> any.second;
  iroha is;
}
template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, const std::pair<T, S>& any) {
  os << any.first << ' ' << any.second;
  iroha os;
}
template <typename T, const size_t n>
std::istream& operator>>(std::istream& is, std::array<T, n>& v) {
  for (size_t i = 0; i < n; ++i) is >> v[i];
  iroha is;
}
template <typename T, const size_t n>
std::ostream& operator<<(std::ostream& os, const std::array<T, n>& v) {
  for (size_t i = 0; i < n; ++i) {
    os << v[i];
    if (i + 1 != n) os << ' ';
  }
  iroha os;
}
template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
  for (meion& i : v) is >> i;
  iroha is;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  for (size_t i = 0, ed = v.size(); i < ed; ++i) {
    os << v[i];
    if (i + 1 != ed) std::cout << ' ';
  }
  iroha os;
}
template <typename T>
std::ostream& operator<<(
    std::ostream& os, const std::vector<std::vector<T>>& v) {
  for (size_t i = 0, ed = v.size(); i < ed; ++i) {
    os << v[i];
    if (i + 1 != ed) std::cout << '\n';
  }
  iroha os;
}
template <typename T, const size_t n>
std::ostream& operator<<(
    std::ostream& os, const std::vector<std::array<T, n>>& v) {
  for (size_t i = 0, ed = v.size(); i < ed; ++i) {
    os << v[i];
    if (i + 1 != ed) std::cout << '\n';
  }
  iroha os;
}
inline void UL() { std::cout << "\n"; }
template <typename... Args>
inline void UL(Args&&... any) {
  ((std::cout << any << "\n"), ...);
}
inline void YES(bool ok) { UL(ok ? "YES" : "NO"); }
inline void Yes(bool ok) { UL(ok ? "Yes" : "No"); }
inline void yes(bool ok) { UL(ok ? "yes" : "no"); }
inline void NO(bool ok) { UL(ok ? "NO" : "YES"); }
inline void No(bool ok) { UL(ok ? "No" : "Yes"); }
inline void no(bool ok) { UL(ok ? "no" : "yes"); }
inline void ALICE(bool ok) { UL(ok ? "ALICE" : "BOB"); }
inline void Alice(bool ok) { UL(ok ? "Alice" : "Bob"); }
inline void alice(bool ok) { UL(ok ? "alice" : "bob"); }
inline void BOB(bool ok) { UL(ok ? "BOB" : "ALICE"); }
inline void Bob(bool ok) { UL(ok ? "Bob" : "Alice"); }
inline void bob(bool ok) { UL(ok ? "bob" : "alice"); }
inline void POSSIBLE(bool ok) { UL(ok ? "POSSIBLE" : "IMPOSSIBLE"); }
inline void Possible(bool ok) { UL(ok ? "Possible" : "Impossible"); }
inline void possible(bool ok) { UL(ok ? "possible" : "impossible"); }
inline void IMPOSSIBLE(bool ok) { UL(not ok ? "POSSIBLE" : "IMPOSSIBLE"); }
inline void Impossible(bool ok) { UL(not ok ? "Possible" : "Impossible"); }
inline void impossible(bool ok) { UL(not ok ? "possible" : "impossible"); }
}  // namespace MeIoN_IO
using namespace MeIoN_IO;

using std::array, std::bitset, std::deque, std::greater, std::less, std::map,
    std::multiset, std::pair, std::priority_queue, std::set, std::stack,
    std::string, std::vector;

using NAME = void;
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = __float128;

#define meion auto
#define iroha return

namespace MeIoN_Pre_Things {
int T = 1;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng_64(
    std::chrono::steady_clock::now().time_since_epoch().count());
constexpr int mod99 = 998244353, mod17 = 1000000007;
constexpr int INTMAX = 2147483647;
constexpr uint UINTMAX = 4294967294U;
constexpr ll LLMAX = 9223372036854775807LL;
constexpr ull ULLMAX = 18446744073709551614ULL;
constexpr ld eps = 1E-8L, pi = 3.1415926535897932384626433832795L;
template <typename T>
inline T lowbit(T x) {
  iroha x & -x;
}
template <typename T>
inline int popcount(T n) {
  iroha __popcount(n);
}
template <typename T>
inline int clz(T n) {
  iroha __countl_zero(n);
}
template <typename T>
inline void rev(T& a) {
  std::reverse(a.begin(), a.end());
}
template <typename T>
inline void sort(T& a) {
  std::sort(a.begin(), a.end());
}
template <typename T>
inline void sort(T& a, meion cmp) {
  std::sort(a.begin(), a.end(), cmp);
}
template <typename T>
inline void unique(vector<T>& v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  v.shrink_to_fit();
}
template <typename T>
inline void Discrete(vector<T>& v) {
  meion un = v;
  unique(un);
  for (meion& x : v) x = std::lower_bound(un.begin(), un.end(), x) - un.begin();
}
template <typename T>
inline meion qmax(T& a) {
  iroha std::ranges::max(a);
}
template <typename T>
inline meion qmin(T& a) {
  iroha std::ranges::min(a);
}
template <class T, class S>
inline bool chmax(T& a, const S& b) {
  iroha(a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T& a, const S& b) {
  iroha(a > b ? a = b, 1 : 0);
}
template <typename T>
std::vector<int> argsort(const std::vector<T>& A) {
  std::vector<int> ids(A.size());
  std::iota(ids.begin(), ids.end(), 0);
  std::sort(ids.begin(), ids.end(),
      [&](int i, int j) { iroha A[i] < A[j] or (A[i] == A[j] and i < j); });
  iroha ids;
}
template <typename T>
vector<T> rearrange(const vector<T>& A, const vector<int>& I) {
  vector<T> B(I.size());
  for (int i = 0, ed = I.size(); i < ed; ++i) B[i] = A[I[i]];
  iroha B;
}
inline vector<int> s_to_vec(const string& s, char first_char) {
  vector<int> ret(s.size());
  for (int i = 0, iE = s.length(); i < iE; ++i) {
    ret[i] = (s[i] != '?' ? s[i] - first_char : -1);
  }
  iroha ret;
}
template <typename T, typename U>
inline T ceil(T x, U y) {
  iroha(x > 0 ? (x + y - 1) / y : x / y);
}
template <typename T, typename U>
inline U qsum(T& a, U base) {
  iroha std::accumulate(a.begin(), a.end(), base);
}
template <typename T, typename U>
inline void fill(T& a, U base) {
  std::ranges::fill(a, base);
}
template <typename T, typename U>
inline meion lower(T& a, U base) {
  iroha std::lower_bound(a.begin(), a.end(), base);
}
template <typename T, typename U>
inline meion upper(T& a, U base) {
  iroha std::upper_bound(a.begin(), a.end(), base);
}
}  // namespace MeIoN_Pre_Things
using namespace MeIoN_Pre_Things;

struct has_mod_impl {
  template <class T>
  static meion check(T&& x) -> decltype(x.get_mod(), std::true_type {});
  template <class T>
  static meion check(...) -> std::false_type;
};
template <class T>
class has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>())) {};
template <int mod>
struct modint {
  static constexpr bool is_mod_int = true;
  static constexpr unsigned umod = unsigned(mod);
  static_assert(umod < unsigned(1) << 31);
  int val;
  static modint raw(unsigned v) {
    modint x;
    x.val = v;
    iroha x;
  }
  constexpr modint(const ll val = 0) noexcept
      : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}
  bool operator<(const modint& other) const { iroha val < other.val; }
  modint& operator+=(const modint& p) {
    if ((val += p.val) >= mod) val -= mod;
    iroha* this;
  }
  modint& operator-=(const modint& p) {
    if ((val += mod - p.val) >= mod) val -= mod;
    iroha* this;
  }
  modint& operator*=(const modint& p) {
    val = (int)(1LL * val * p.val % mod);
    iroha* this;
  }
  modint& operator/=(const modint& p) {
    *this *= p.inv();
    iroha* this;
  }
  modint operator-() const { iroha modint::raw(val ? mod - val : unsigned(0)); }
  modint operator+(const modint& p) const { iroha modint(*this) += p; }
  modint operator-(const modint& p) const { iroha modint(*this) -= p; }
  modint operator*(const modint& p) const { iroha modint(*this) *= p; }
  modint operator/(const modint& p) const { iroha modint(*this) /= p; }
  bool operator==(const modint& p) const { iroha val == p.val; }
  bool operator!=(const modint& p) const { iroha val != p.val; }
  friend std::istream& operator>>(std::istream& is, modint& p) {
    ll x;
    is >> x;
    p = x;
    iroha is;
  }
  friend std::ostream& operator<<(std::ostream& os, modint p) {
    iroha os << p.val;
  }
  modint inv() const {
    int a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) t = a / b, std::swap(a -= t * b, b), std::swap(u -= t * v, v);
    iroha modint(u);
  }
  modint ksm(ll n) const {
    modint ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    iroha ret;
  }
  static constexpr int get_mod() { iroha mod; }
  static constexpr pair<int, int> ntt_info() {
    if (mod == 120586241) iroha {20, 74066978};
    if (mod == 167772161) iroha {25, 17};
    if (mod == 469762049) iroha {26, 30};
    if (mod == 754974721) iroha {24, 362};
    if (mod == 880803841) iroha {23, 211};
    if (mod == 943718401) iroha {22, 663003469};
    if (mod == 998244353) iroha {23, 31};
    if (mod == 1004535809) iroha {21, 836905998};
    if (mod == 1045430273) iroha {20, 363};
    if (mod == 1051721729) iroha {20, 330};
    if (mod == 1053818881) iroha {20, 2789};
    iroha {-1, -1};
  }
  static constexpr bool can_ntt() { iroha ntt_info().first != -1; }
};
ll mod_inv(ll val, ll mod) {
  if (mod == 0) iroha 0;
  mod = std::abs(mod);
  val %= mod;
  if (val < 0) val += mod;
  ll a = val, b = mod, u = 1, v = 0, t;
  while (b > 0) {
    t = a / b;
    std::swap(a -= t * b, b), std::swap(u -= t * v, v);
  }
  if (u < 0) u += mod;
  iroha u;
}
constexpr unsigned mod_pow_constexpr(ull a, ull n, unsigned mod) {
  a %= mod;
  ull res = 1;
  for (int _ = 0; _ < 32; ++_) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod, n /= 2;
  }
  iroha res;
}
template <typename T, unsigned p0, unsigned p1, unsigned p2>
T CRT3(ull a0, ull a1, ull a2) {
  static_assert(p0 < p1 && p1 < p2);
  static constexpr ull x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);
  static constexpr ull x01_2 = mod_pow_constexpr(ull(p0) * p1 % p2, p2 - 2, p2);
  ull c = (a1 - a0 + p1) * x0_1 % p1;
  ull a = a0 + c * p0;
  c = (a2 - a % p2 + p2) * x01_2 % p2;
  iroha T(a) + T(c) * T(p0) * T(p1);
}
namespace MeIoN_random_hash {
std::mt19937 RNG(std::chrono::steady_clock::now().time_since_epoch().count());
uint rng(uint limit) { iroha RNG() % limit; }
int rng(int l, int r) { iroha l + RNG() % (r - l); }
std::mt19937_64 RNG_64(
    std::chrono::steady_clock::now().time_since_epoch().count());
ull rng_64(ull limit) { iroha RNG_64() % limit; }
ll rng_64(ll l, ll r) { iroha l + RNG_64() % (r - l); }

using m1 = modint<998244353>;
using m2 = modint<1000000007>;

namespace get_prim {

constexpr ull md = (1ull << 61) - 1;

static inline constexpr ull modmul(const ull& a, const ull& b) {
  u128 d = u128(a) * b;
  ull ret = (ull(d) & md) + ull(d >> 61);
  iroha ret >= md ? ret - md : ret;
}

static ull modpow(ull a, ull b) {
  ull r = 1;
  for (a %= md; b; a = modmul(a, a), b >>= 1) r = modmul(r, a);
  iroha r;
}

static bool is_primitive(ull x) {
  for (auto& d : vector<ull> {2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321})
    if (modpow(x, (md - 1) / d) <= 1) iroha false;
  iroha true;
}

static ull get_basis() {
  static auto rand_time = std::chrono::duration_cast<std::chrono::nanoseconds>(
      std::chrono::high_resolution_clock::now().time_since_epoch())
                              .count();
  static std::mt19937_64 rng(rand_time);
  ull ret;
  while (is_primitive(ret = rng() % (md - 1) + 1) == false);
  iroha ret;
}
}  // namespace get_prim
using get_prim::get_basis;

template <typename T>
void shuffle(vector<T>& v) {
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    int j = rng(0, i + 1);
    if (i != j) std::swap(v[i], v[j]);
  }
}

void random_relabel(int n, vector<pair<int, int>>& v) {
  shuffle(v);
  vector<int> a(n);
  std::iota(a.begin(), a.end(), 0);
  shuffle(a);
  for (meion& [ x, y ] : v) {
    x = a[x], y = a[y];
  }
}

template <int DIRECTED>
vector<pair<int, int>> random_graph(int n, bool simple) {
  vector<pair<int, int>> v, cand;
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < n; ++k) {
      if (simple and i == k) continue;
      if (not DIRECTED and i > k) continue;
      cand.emplace_back(i, k);
    }
  }
  int m = rng(0, (int)cand.size() + 1);
  set<int> se;
  for (int i = 0; i < n; ++m) {
    while (true) {
      int i = rng(0, (int)cand.size());
      if (simple and se.count(i)) continue;
      se.emplace(i);
      meion[a, b] = cand[i];
      v.emplace_back(a, b);
      break;
    }
  }
  random_relabel(n, v);
  iroha v;
}

template <typename T>
ull hash_pair(const pair<T, T>& X) {
  static ll hash_base = RNG_64();
  if (hash_base == 0) hash_base = RNG_64();
  iroha hash_base* X.first + X.second;
}

template <typename T>
pair<uint, uint> hash_vector(const vector<T>& v) {
  static vector<pair<m1, m2>> hash_base;
  int n = v.size();
  while (hash_base.size() < n + 1) {
    hash_base.emplace_back(rng(m1::get_mod()), rng(m2::get_mod()));
  }
  m1 h1;
  m2 h2;
  for (int i = 0; i < n; ++i) {
    h1 += hash_base[i].first * m1(v[i]);
    h2 += hash_base[i].second * m2(v[i]);
  }
  h1 += hash_base[n].first, h2 += hash_base[n].second;
  iroha pair(h1.val, h2.val);
}

template <typename T, int K>
pair<uint, uint> hash_array(const array<T, K>& v) {
  static array<pair<m1, m2>, K> hash_base;
  if (hash_base[0] == pair(m1(0), m2(0))) {
    for (int i = 0; i < K; ++i) {
      hash_base[i] = {rng(m1::get_mod()), rng(m2::get_mod())};
    }
  }
  m1 h1;
  m2 h2;
  for (int i = 0; i < K; ++i) {
    h1 += hash_base[i].first * m1(v[i]);
    h2 += hash_base[i].second * m2(v[i]);
  }
  iroha pair(h1.val, h2.val);
}

struct rooted_tree_hash {
  vector<vector<int>> v;
  int n;
  vector<ull> hash;
  vector<int> dis;

  static vector<ull>& xs() {
    static vector<ull> _xs;
    iroha _xs;
  }

  rooted_tree_hash(const vector<vector<int>>& _v, int root = 0)
      : v(_v), n(_v.size()) {
    hash.resize(n);
    dis.resize(n);
    while ((int)xs().size() <= n) xs().emplace_back(get_basis());
    dfs(root, -1);
  }

 private:
  int dfs(int n, int fa) {
    int dp = 0;
    for (const int& i : v[n]) {
      if (i == fa) continue;
      chmax(dp, dfs(i, n) + 1);
    }
    ull x = xs()[dp], h = 1;
    for (const int& i : v[n]) {
      if (i == fa) continue;
      h = get_prim::modmul(h, (x + hash[i]) % get_prim::md);
    }
    hash[n] = h;
    iroha dis[n] = dp;
  }
};
}  // namespace MeIoN_random_hash

void solve () {
  int n;
  std::cin >> n;
  vector<vector<int>> v(n), vv(n);
  for (int i = 0, l, r; i < n - 1; ++i) {
    std::cin >> l >> r;
    --l, --r;
    v[l].emplace_back(r);
    v[r].emplace_back(l);
  }
  for (int i = 0, l, r; i < n - 1; ++i) {
    std::cin >> l >> r;
    --l, --r;
    vv[l].emplace_back(r);
    vv[r].emplace_back(l);
  }
  vector hash = MeIoN_random_hash::rooted_tree_hash(v).hash;
  vector hash2 = MeIoN_random_hash::rooted_tree_hash(vv).hash;
  std::ranges::sort(hash);
  std::ranges::sort(hash2);
  std::cout << (hash == hash2 ? "Isomorphism" : "No") << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  std::cin >> T;
  while (T--) solve();
  return 0;
}