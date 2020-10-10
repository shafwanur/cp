using ll = long long;

const ll P = 31;
const ll M = 1e9 + 9;

const int N = 1e5 + 5;

ll ppow[N];
ll h[N];

ll bigmod(ll a, ll b, ll mod) {
  if (b == 0) return 1;
  if (b & 1) {
    return ((a % mod) * bigmod(a, b - 1, mod)) % mod;
  }
  ll temp = bigmod(a, b >> 1, mod);
  return (temp * temp) % mod;
}
 
ll inv(ll a) {
  return bigmod(a, M - 2, M);
}

void prefixhash(string& s) {
  int n = (int) s.size();
  ppow[0] = 1;
  for (int i = 1; i < n; i++) {
    ppow[i] = (ppow[i - 1] * P) % M;
  }
  h[0] = 0;
  for (int i = 0; i < n; i++) {
    h[i + 1] = (h[i] + (s[i] - 'a' + 1) * ppow[i]) % M;
  }
}

ll get(string& s) {
  int n = (int) s.size();
  ll hash = 0;
  for (int i = 0; i < n; i++) {
    hash = (hash + (s[i] - 'a' + 1) * ppow[i]) % M;
  }
  return hash;
}

ll substrhash(int i, int j) {
  // substr[i, j] [mul by inv(ppow[i])]
  // hash[j] - hash[i - 1]
  // h[j + 1] - h[i] [h[] stores 1-indexed, so add 1 to indexes]
  ll hash = (h[j + 1] - h[i] + M) % M;
  hash = (hash * inv(ppow[i])) % M;
  return hash;
}
