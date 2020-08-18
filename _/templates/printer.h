#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return s;
}

string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "1" : "0");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return to_string(p.first) + " " + to_string(p.second);
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += " ";
    }
    first = false;
    res += to_string(v[i]);
  }
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "";
  for (const auto &x : v) {
    if (!first) {
      res += " ";
    }
    first = false;
    res += to_string(x);
  }
  return res;
}
 
void print_out() { 
  cout << endl; 
}
 
template <typename Head, typename... Tail>
void print_out(Head H, Tail... T) {
  cout << to_string(H) + " ";
  print_out(T...);
}
 
#define print(...) print_out(__VA_ARGS__)
