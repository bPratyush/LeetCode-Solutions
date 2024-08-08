void merge(int* a, int nums1Size, int m, int* b, int nums2Size, int n) {
    int i = 0, j = 0, k = 0;
    int res[n+m];
        while (i < m && j < n) {
            if (a[i] <= b[j]) res[k++] = a[i++];
            else res[k++] = b[j++];
        }
        while (i < m) res[k++] = a[i++];
        while (j < n) res[k++] = b[j++];
        for (int idx = 0; idx < m + n; ++idx) a[idx] = res[idx];
}