int modularExponentiation(int a, int b[], int k, int n){
  int c = 0, d = 1;
  for (int i = k ; i >= 0; i--){
    c = 2 * c;
    d = (d * d) % n;
    if(b[i] == 1){
      c++;
      d = (a * d) % n;
    }
  }
  return d;
}
