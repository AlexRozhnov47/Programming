double taylor(double x, double s, int i) {
    s = 0.0;
    i = 1;
    do {
        s += n;
        n *= -1 * x * x / ((2 * i) * (2 * i + 1));
        i++;
    } while ((n > 0.0 ? n : n) > 1E-10);
    cout << s; return s;

}