
"Exercício complexidade de algoritmo: Floyd"

FloydModificado() {
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			A[i][j] = D[i][j];
			R[i][j] = 0;
		}
	}
	for (int i = 0 ; i < n ; ++i) {
		A[i][i] = 0;
	}
	for (int k = 0 ; k < n ; ++k) {
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < n ; ++j) {
				if ( A[i][k] + A[k][j] < A[i][j] ) {	
					 A[i][j] = A[i][k] + A[k][j];
					 R[i][j] = k;
				}
			}
		}
	}
}