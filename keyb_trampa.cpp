#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>
 
void run(std::istream &in, std::ostream &out) {
    std::string s;
    std::getline(in, s);
    int n = s.length();
    std::array<std::vector<int>, 2> dyn;
    dyn[0].assign(n + 1, 0);
    dyn[1].assign(n + 1, 0);
    dyn[1][0] = 2 * n + 2;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            dyn[1][i + 1] = dyn[1][i] + 1;
            dyn[0][i + 1] = std::min(dyn[0][i], dyn[1][i] + 2);
        } else if (c >= 'A' && c <= 'Z') {
            dyn[0][i + 1] = dyn[0][i] + 1;
            dyn[1][i + 1] = std::min(dyn[1][i], dyn[0][i] + 2);
        } else {
            dyn[0][i + 1] = dyn[0][i];
            dyn[1][i + 1] = dyn[1][i];
        }
    }
    int ans = std::min(dyn[0][n], dyn[1][n]) + n;
    out << ans << "\n";
}
 
int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}