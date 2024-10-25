#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vs = vector<string>;

ll n, m;
vs A, B;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;

  A = vs(n);
  for (auto&& a : A) {
    cin >> a;
  }

  B = vs(n);
  for (auto&& b : B) {
    cin >> b;
  }

  if (n < 3 || m < 3) {
    auto is_eq = true;
    for (auto i = 0; is_eq && i < n; ++i) {
      for (auto j = 0; is_eq && j < m; ++j) {
        if (A[i][j] != B[i][j]) {
          is_eq = false;
          break;
        }
      }
    }

    if (is_eq) {
      cout << 0;
    } else {
      cout << -1;
    }

    return 0;
  }

  ll ans = 0;
  for (auto i = 0; i < n - 2; ++i) {
    for (auto j = 0; j < m - 2; ++j) {
      if (A[i][j] == B[i][j]) continue;

      ++ans;
      for (auto y = 0; y < 3; ++y) {
        for (auto x = 0; x < 3; ++x) {
          if (A[i + y][j + x] == '0') {
            A[i + y][j + x] = '1';
          } else {
            A[i + y][j + x] = '0';
          }
        }
      }
    }
  }

  auto is_eq = true;
  for (auto i = 0; is_eq && i < n; ++i) {
    for (auto j = 0; is_eq && j < m; ++j) {
      if (A[i][j] != B[i][j]) {
        is_eq = false;
        break;
      }
    }
  }

  if (is_eq) {
    cout << ans;
  } else {
    cout << -1;
  }

  return 0;
}