#include <iostream>

int n;
int sorted[500'000];
long long cnt_swap = 0;

void merge(int a[], int first, int last) {
    int mid = (first + last) / 2;
    int l = first, r = mid + 1, i = first;
    
    while (l <= mid && r <= last) {
        if (a[l] <= a[r]) sorted[i++] = a[l++];
        else {
            sorted[i++] = a[r++];
            cnt_swap += (mid - l + 1);
        }
    }
    
    while (l <= mid) sorted[i++] = a[l++];
    while (r <= last) sorted[i++] = a[r++];
    for (int i = first; i <= last; i++) a[i] = sorted[i];
}

void merge_sort(int a[], int first, int last) {
    if (first == last) return;
    
    int mid = (first + last) / 2;
    merge_sort(a, first, mid);
    merge_sort(a, mid + 1, last);
    merge(a, first, last);
}

int main() {
    scanf("%d", &n);
    
    int numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    merge_sort(numbers, 0, n - 1);
    
    printf("%lld\n", cnt_swap);
    
    return 0;
}
