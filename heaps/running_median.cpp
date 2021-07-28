#include <iostream>
#include <vector>
#include <queue>
using namespace std;

float runningMedian(
    int x,
    priority_queue<int>& maxHeap,
    priority_queue<int,vector<int>, greater<int>>& minHeap, 
    float* prevMedian) {
    
    // if empty insert
    if(maxHeap.empty() && minHeap.empty()) {
        maxHeap.push(x);
        *prevMedian = x;
        return x;
    }
    
    int minSize = minHeap.size();
    int maxSize = maxHeap.size();

    if(minSize == maxSize) {
        if(x <= *prevMedian) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }
    } else if(minSize > maxSize) {
        if(x <= *prevMedian) {
            maxHeap.push(x);
        } else {
            int p = minHeap.top();
            minHeap.pop();
            maxHeap.push(p);
            minHeap.push(x);
        }
    } else {
        if(x <= *prevMedian) {
            int p = maxHeap.top();
            maxHeap.pop();
            minHeap.push(p);
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }
    }

    minSize = minHeap.size();
    maxSize = maxHeap.size();
    float median;
    if(minSize == maxSize) {
        median = (maxHeap.top() + minHeap.top()) / 2.0;
    } else {
        if(minSize > maxSize) {
            median = minHeap.top();
        } else {
            median = maxHeap.top();
        }
    }
    *prevMedian = median;
    return median;
}

// float runningMedian(
//     int x, 
//     priority_queue<int>& maxHeap, 
//     priority_queue<int, vector<int>, greater<int>>& minHeap, 
//     float* prevMedian
//     ) {
    
//     // if empty insert
//     if(maxHeap.empty() && minHeap.empty()) {
//         maxHeap.push(x);
//         *prevMedian = x;
//         return x;
//     }
    
//     int minSize = minHeap.size();
//     int maxSize = maxHeap.size();
    
    
//     // if element is smaller or equal to median insert in the max heap
//     if(x <= *prevMedian) {
//         // if size of max heap is size(minHeap + 1) shift one element from maxHeap to minHeap
//         if(maxSize > minSize) {
//             int p = maxHeap.top();
//             maxHeap.pop();
//             minHeap.push(p);
//         }
//         maxHeap.push(x);
//     }
//     // if element is larger than median insert in the min heap
//     if(x > *prevMedian) {
//         if(minSize > maxSize) {
//             int p = minHeap.top();
//             maxHeap.push(p);
//             minHeap.pop();
//         }
//         minHeap.push(x);
//     }

//     float median;
//     minSize = minHeap.size();
//     maxSize = maxHeap.size();

//     if(minSize == maxSize) {
//         median = ((minHeap.top() + maxHeap.top()) * 1.0) / 2;
//     } else {
//         if(minSize > maxSize) {
//             median = minHeap.top();
//         } else {
//             median = maxHeap.top();
//         }
//     }
//     *prevMedian = median;
//     return median;
// }


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        float* prevMedian = new float;

        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cout << runningMedian(x, maxHeap, minHeap, prevMedian) << endl;
        }
    }
    return 0;
}