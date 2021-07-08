void build_suffix_array(int** a, int r, int c) {
    //row wise
    for(int i = r-2; i >= 0; i--) {
        for(int j = 0; j < c; j++) {
            a[i][j] += a[i+1][j];
        }
    }

    //col wise
    for(int i = 0; i < r; i++) {
        for(int j = c-2; j >= 0; j--) {
            a[i][j] += a[i][j+1];
        }
    }
}