#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;


// perform bubble sort
void bubble_sort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < (size-1); ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < size - (step-1); ++i) {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {

        // swapping elements if elements
        // are not in the intended order
        swap(array[i], array[i + 1]);
      }
    }
  }
}

void display(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
}

int main() {
    int a[100000];
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        a[i] = n - i;
    }

    time_t start = clock();
    bubble_sort(a, n);
    time_t end = clock();
    cout<<(float)(end - start)<<" ms"<<endl;
    for(int i = 0; i < n; i++) {
        a[i] = n - i;
    }
    start = clock();
    sort(a, a + n);
    start = clock() - start;
    cout<<"merge sort "<<start<<" ms";
    return 0;
}