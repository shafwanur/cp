long long bigpow(long long a, long long b) {
  if (b == 0) 
    return 1;
  if (b & 1) 
    return a * bigpow(a, b - 1);
  else {
    long long t = bigpow(a, b >> 1);
    return (t * t);
  }
}
