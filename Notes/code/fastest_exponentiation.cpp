int fastestExponentiation(int a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;
  int mul = fastestExponentiation(a, b / 2);
  return b % 2 == 0 ? mul * mul : a * mul * mul;
}
