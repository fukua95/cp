#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN = (int)2e5 + 1;

struct Node {
  vector<int> node;
};

bool cmp(Node x, Node y) {
  if (x.node.size() != y.node.size()) 
    return x.node.size() < y.node.size();
  else {
    for (int i = 0; i < x.node.size(); ++i) {
      if (x.node[i] != y.node[i])
        return x.node[i] < y.node[i];
    }
  }
}

Node a[26], b[26];
char s[MAXN], t[MAXN];

bool solve() {
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    a[s[i] - 'a'].node.push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    b[t[i] - 'a'].node.push_back(i);
  }
  for (int i = 0; i < 26; ++i) {
    sort(a[i].node.begin(), a[i].node.end());
    sort(b[i].node.begin(), b[i].node.end());
  }
  sort(a, a + 26, cmp);
  sort(b, b + 26, cmp);
  for (int i = 0; i < 26; ++i) {
    if (a[i].node.size() != b[i].node.size())
      return false;
    for (int j = 0; j < a[i].node.size(); ++j) {
      if (a[i].node[j] != b[i].node[j])
        return false;
    }
  }
  return true;
}

int main() {
  scanf("%s", s);
  scanf("%s", t);
  if (solve()) puts("Yes");
  else puts("No");
  return 0;
}
