# DSA
//these where the codes that i have written while doing DSA
//MERGE SORT
#include<bits/stdc++.h>
using namespace std;

int fact(int x) {
    if(x <= 1)
        return 1;
    return x * fact(x - 1);
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        int z;cin>>z;
        a.push_back(pow(2,z));
    }
    sort(a.begin(), a.end());
    int sum = a[n - 1] + a[n - 2];
    int count = 0;
    map<int, int> mpp;
    mpp[a[n - 1]]++;
    mpp[a[n - 2]]++;
    count += 2;
    for(int i = 0; i < n - 2; i++) {
    
        mpp[a[i]]++;
        count++;
        
    }
    cout<<count<<" "<<mpp.size()<<endl;
    int No_of_triangle = 0;
    if(count < 3 || n < 3) {
        cout << 0 << endl;
    }
    else {
        No_of_triangle = ((count) * (count - 1) * (count - 2)) / 6;
        for(auto it : mpp) {
            if(it.second > 1) {
                No_of_triangle /= fact(it.second);
            }
        }
        cout << No_of_triangle << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while(t--) {
        sol();
    }
    return 0;
}
