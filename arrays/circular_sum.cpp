#include <iostream>
#include <climits>
using namespace std;

int circular_sum(int a[], int n){
    int sum = 0;
    int max_sum = INT_MIN;
    int first_sum = 0;
    int last_sum = 0;
    int i = 0;
    for(; i < n; i++) {
        if(first_sum + a[i] < 0) {
            break;
        }
        first_sum += a[i];
    }
    for(int j = n - 1; j > i; j--) {
        if(last_sum + a[j] < 0) {
            break;
        }
        last_sum += a[j];
    }
    for(int i = 0; i < n; i++) {
        sum += a[i];
        max_sum = max(sum, max_sum);
        sum = max(sum, 0);
    }
    return max(max_sum, first_sum + last_sum);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin>>a[i];
        }
        cout<<circular_sum(a, n)<<endl;
    }
    return 0;
}