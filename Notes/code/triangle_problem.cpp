//Top-Down
int T[N + 1][N + 1];
int M[N + 1][N + 1]; //Initialize the values to -1 or some erroneous value

for(int j = 1; j <= N; j++) M[N][j] = T[N][j];

int triangle(int i, int j){
  if(M[i][j] != -1) return M[i][j];
  int left = triangle(i + 1, j);
  int right = traingle(i + 1, j + 1);
  return M[i][j] = T[i][j] + max(left, right);
}

//Bottom-Up
int T[N + 1][N + 1];
int M[N + 1][N + 1];

for(int i = N; i >= 1; i--)
  for(int j = i; j >= 1; j--)
    if(i == n) M[i][j] =  T[i][j];
    else M = [i][j] = T[i][j] + max(M[i + 1][j], M[i + 1][j + 1]);
