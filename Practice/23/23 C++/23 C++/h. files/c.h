int c(int m, int k){
    cin >> m;
    cin >> k;
    if ((m == 0) || (m == k)) {
        cout << 1;
    }
    else return c(m,k-1)+c(m-1,k-1);
}