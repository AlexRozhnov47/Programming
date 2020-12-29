long fact(long nf) {
    if (nf < 1)
        return 1;
    else return fact(nf -= 1)  * n ;
}