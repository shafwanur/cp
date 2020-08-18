ll bigmod(ll a, ll b, ll mod) {
  if (b == 0) return 1;
  if (b & 1) {
    return ((a % mod) * bigmod(a, b - 1, mod)) % mod;
  } 
  else {
    ll t = bigmod(a, b >> 1, mod);
    return (t * t) % mod;
  }
}
