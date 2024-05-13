# DSA
//these where the codes that i have written while doing DSA
----------------------------------------------------------------------------------MERGE SORT------------------------------------------------------------------------------------------------------------------------
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
-----------------------------------------------------------------------------------------------------QUICK SORT----------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while(i <= j) {
        while(i <= high && arr[i] <= pivot)
            i++;
        while(j >= low && arr[j] > pivot)
            j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pIndex = fun(arr, low, high);
        QuickSort(arr, low, pIndex - 1);
        QuickSort(arr, pIndex + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    QuickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
--------------------------------------------------------------------------BINARY SEARCH-----------------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr,int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;cin>>target;
    sort(arr.begin(),arr.end());
    int ans=fun(arr,n,target);
    cout<<ans<<endl;
    
    
}
