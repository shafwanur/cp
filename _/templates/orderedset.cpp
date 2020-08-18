#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  ordered_set<int> st;

  st.insert(1);
  st.insert(2);
  st.insert(3);

  cout << *st.find_by_order(0) << '\n'; 

  cout << st.order_of_key(2) << '\n'; 
  
  st.erase(st.find_by_order(st.order_of_key(3))); /* iterator passed through .erase() */
}
