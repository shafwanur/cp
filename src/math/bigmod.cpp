long long bigmod(long long a, long long b, long long mod) {
  if (b == 0) 
    return 1;
  if (b & 1) 
    return ((a % mod) * bigmod(a, b - 1, mod)) % mod;
  else {
    long long t = bigmod(a, b >> 1, mod);
    return (t * t) % mod;
  }
}
