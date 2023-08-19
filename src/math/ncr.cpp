const int N = 2e5 + 5;
const long long MOD = 1e9 + 7;

vector<long long> f(N);

void init() {
  f[0] = 1LL;
  for (int i = 1; i < N; i++) {
    f[i] = (f[i - 1] * i) % MOD;
  }
}

long long bigmod(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  if (b & 1) {
    return ((a % mod) * bigmod(a, b - 1, mod)) % mod;
  } 
  else {
    long long t = bigmod(a, b >> 1, mod);
    return (t * t) % mod;
  }
}

long long C(int n, int r) {
  if (r > n) {
    return 0;
  }
  if (n == r) {
    return 1;
  }
  long long ret = f[n] * bigmod(f[r], MOD - 2, MOD);
  ret %= MOD;
  ret *= bigmod(f[n - r], MOD - 2, MOD);
  ret %= MOD;
  return ret;
}

init();
