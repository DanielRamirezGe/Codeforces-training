#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll Max = 1e5;

vector <ll> num;

int main() {
    //freopen("1.in", "r", stdin);
    int n;
    scanf("%d", &n);
    long long ans = 100;
    for(int i=0;i<n;i++) {
        ll temp; scanf("%lld", &temp);
        if(i != 0 && temp == num[num.size()-1])//去重
            continue;
        num.push_back(temp);
    }

    ll have = 0;
    num.push_back(-1);//设置最后没有股票剩余
    n = int(num.size());
    for (int i = 0; i < n-1; i++) {
        if(i == 0 && num[i] < num[i+1]) {
            ll cnt = ans / num[i];
            ans -= cnt*num[i];
            have = cnt;
            continue;
        }

        if(num[i] < num[i-1] && num[i] < num[i+1]) {//波谷买
            ll cnt = ans / num[i];
            cnt = min(cnt, Max);
            have = cnt;
            ans -= have*num[i];
        } else if(num[i] > num[i-1] && num[i] > num[i+1]) {//波峰卖
            ans += have * num[i];
            have = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
   }