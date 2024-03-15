#include <iostream>
#include <vector>
#include <algorithm>

void println(const std::vector<int>& vec)
{
  for (std::vector<int>::const_iterator it = vec.begin(), last = vec.end(); it != last; ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
}

std::vector<int> splitNum(int num) {
  std::vector<int> tmp;
  while (num) {
    tmp.push_back(num % 10);
    num /= 10;
  }
  std::reverse(tmp.begin(), tmp.end());
  return tmp;
}


bool trysplit(std::vector<int> &vec) {
  for (std::vector<int>::iterator it = vec.begin(), last = vec.end(); it != last; ++it) {
    if (it + 1 == last) {
      break;
    }
    int n1 = *it;
    int n2 = *(it + 1);
    if (n1 <= n2) {
      continue;
    }
    std::vector<int> tmp = splitNum(n1);
    if (tmp.size() == 1) {
      return false;
    }
    *it = tmp.back();
    vec.insert(it, tmp.begin(), tmp.end() - 1);
    return trysplit(vec);
  }
  return true;
}

int main(void) {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i != t; ++i) {
    int n = 0;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for (int j = 0 ; j < n; ++j) {
      std::cin >> vec[j];
    }
    if (trysplit(vec)) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}
