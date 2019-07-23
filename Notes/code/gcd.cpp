int gcd(int a, int b){
	int temp;
	while(a != 0){
		temp = a;
		a = b % a;
		b = temp;
	}
	return b;
}
