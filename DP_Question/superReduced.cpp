#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back

const int inf = (int)1e9;

// dp memo solution
int memo[10000];

int minSteps(int n) {
  int ans1 = inf , ans2 = inf , ans3 = inf ;
  if (n == 1) {
    return 0;
  }
  if(memo[n]!= -1) return memo[n];

  if (n % 3 == 0) ans1 = 1 + minSteps(n / 3);

  if (n % 2 == 0) ans2 = 1 + minSteps(n / 2);

  ans3 = 1 + minSteps(n - 1);

  memo[n] = min(min(ans1, ans2), ans3); 

  return memo[n];
}

int main() {

  int n;
  cin >> n;
  fill(memo,memo+n+1,-1);
  
  int ans = minSteps(n);

  cout << ans;

  return 0;
}
