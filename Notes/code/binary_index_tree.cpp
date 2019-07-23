int sums[N + 1];

void update(int pos, int val){
	for(; pos <= N; pos += pos & -pos)
		sums[pos] += val;
}

int query(int pos){
	int sum = 0;
	for(; pos > 0; pos -= pos & -pos)
		sum += sums[pos];
	return sum;
}

int rangeQuery(int start, int end){
	return query(end) - query(start - 1);
}
