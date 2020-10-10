#include <bits/stdc++.h>

using namespace std;

struct node {
  node *child[26];
  bool isEnd;
};

node* make() {
  node *u = new node;
  for (int i = 0; i < 26; i++) {
    u->child[i] = nullptr;
  }
  u->isEnd = false;
  return u;
}

void insert(node *root, string s) {
  node *u = root;
  for (char c : s) {
    int idx = c - 'a';
    if (u->child[idx] == nullptr) {
      u->child[idx] = make();
    }
    u = u->child[idx];
  }
  u->isEnd = true;
}

bool search(node *root, string s) {
  node *u = root;
  for (char c : s) {
    int idx = c - 'a';
    if (u->child[idx] == nullptr) {
      return false;
    }
    u = u->child[idx];
  }
  return (u != nullptr and u->isEnd);
}

bool isEmpty(node *root) {
  for (int i = 0; i < 26; i++) {
    if (root->child[i] != nullptr) {
      return false;
    }
  }
  return true;
}

node* remove(node *root, string s, int dep = 0) {
  if (root == nullptr) {
    return nullptr;
  }
  if (dep == (int) s.size()) {
    if (root->isEnd) {
      root->isEnd = false;
    }
    if (isEmpty(root)) {
      delete root;
      root = nullptr;
    }
    return root;
  }
  int idx = s[dep] - 'a';
  root->child[idx] = remove(root->child[idx], s, dep + 1);

  if (isEmpty(root) and !root->isEnd) {
    delete root;
    root = nullptr;
  }
  return root;
}

int main() { 
  ios_base::sync_with_stdio(0); 
  cin.tie(0);
  node *root = make();
  insert(root, "abcd");
  cout << search(root, "abcd") << '\n';
  remove(root, "abcd");
  cout << search(root, "abcd") << '\n';
}
