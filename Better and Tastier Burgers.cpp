#include<iostream>
#include<time.h>
using namespace std;
#define M 10

int partition(double A[M][3], int p, int r) {
	double x = A[r][0];    //pivot
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (A[j][0] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quicksort(double A[M][3], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

void print(int* A, double B[M][3], int i) {
	if (i == A[i]) {
		cout << "taste value:[" << B[i][0] << "]   health value:[" << B[i][1] << "]    index:[" << B[i][2] << "]" << endl;
		return;
	}
	cout << "taste value:[" << B[i][0] << "]   health value:[" << B[i][1] << "]    index:[" << B[i][2] << "]" << endl;
        print(A, B, A[i]);
}

int Longest_Increasing_Sequence(double A[M][3]) {
	int X[M];
	//X[0]=1;X[i]=max{X[j]}+1;j<i,and A[j]<A[i]
	int S[M];
	X[0] = 1;
	S[0] = 0;
	for (int i = 1; i < M; i++) {
		int q = 1;
		for (int j = 0; j < i; j++) {
			if (A[j][1] < A[i][1]) {
				q = X[j] + 1;
				if (q > X[i]) {
					X[i] = q;
					S[i] = j;
				}
			}
		}
		if (q == 1) {
			X[i] = 1;
			S[i] = i;
		}
	}

	cout << "X[i]" << endl;
	for (int i = 0; i < M; i++) cout << X[i] << ",";
 	cout << endl;

	int max = 0;
	int max_i;
	for (int i = 0; i < M; i++) {
		if (X[i] > max) {
			max = X[i];
			max_i = i;
		}
	}

	cout << "print:" << endl;
	print(S, A, max_i);
	cout << endl;

	return X[max_i];
}

void main() {
	srand((double)time(NULL));
	//Generate test case
	double values[M][3];
	for (int i = 0; i < M; i++) {
		values[i][0] = (double)((rand() % 10) / 10.0) + (rand() % 3) + 1.0;
		values[i][1] = (double)((rand() % 10) / 10.0) + (rand() % 5) + 1.0;
		values[i][2] = i + 1;
	}
	cout << "origin array:" << endl;
	for (int i = 0; i < M; i++) {
		cout << i << " ";
		for (int j = 0; j < 3; j++) {
			cout << values[i][j] << "  ";
		}
		cout << endl;
	}
	quicksort(values, 0, M - 1);

	cout << "sorted:" << endl;
	for (int i = 0; i < M; i++) {
		cout << i << " ";
		for (int j = 0; j < 3; j++)
			cout << values[i][j] << "  ";
		cout << endl;
	}

	int LIS = Longest_Increasing_Sequence(values);

	cout << "LIS:" << LIS << endl;;

	system("pause");

}
