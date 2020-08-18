const int N = 100100;

vector<int> prime;
bool composite[N];

void sieve() {
  for (int i = 2; i < N; i++) {
    if (!composite[i]) prime.push_back(i);
    for (int j = 0; j < (int) prime.size() and i * prime[j] < N; j++) {
      composite[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
