int nth_fibonacci(int n) {
  vector<int> f = {0, 1, 1, 2};
  if (n < 4) return f[n];
  const double r = sqrt(5);
  const double Phi = (1 + r) / 2;
  const double phi = (1 - r) / 2;
  return (pow(Phi, n) - pow(phi, n)) / r;
}
