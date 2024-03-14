#include <iostream>
#include <cstdlib>
#include <cmath>
#include <windows.h>
#include <ctime>

using namespace std;
void FillUp(int *A, int N, int min, int max);
void print_array(int *A, int N);
int SequentialSearch(int *A, int N, int key);
int BinarySearch(int *A, int N, int key);
int JumpSearch(int *A, int N, int key);
int SequentialSearch(int *A, int begin, int end, int key);

int Cmp = 0;

int EqualCmp(int a, int b){
	Cmp++;
	return (a == b);
}

int LessCmp(int a, int b){
	Cmp++;
	return (a < b);
}

int MoreCmp(int a, int b){
//	Cmp++;
	return (a > b);
}

int LessEqualCmp(int a, int b){
//	Cmp++;
	return (a <= b);
}

int MoreEqualCmp(int a, int b){
	Cmp++;
	return (a >= b);
}

int main(){
	
	int min = 0, max = 10000000*2, N = max/2; //10 000 - 100 000
	int *A;
	A = new int[N];
	srand(time(NULL));
	int all = 0;
	int find = 0;
	double t, tsr = 0;
	
	FillUp(A, N, min, max);
	
	for(int Nn = N/10; Nn <= N; Nn += N/10){
		for(int i = 0; i < 10; i++){
			FillUp(A, Nn, min, max);
			find = ((rand() << 15) | rand())%Nn;
			BinarySearch(A, Nn, A[find]);
			all += Cmp;
			Cmp = 0;
//			cout << Nn << endl;
		}
		cout << all/10 << endl;
		all = 0;
	}
	
	
	
	
	
	
	return 0;
}


// последовательный
int SequentialSearch(int *A, int N, int key){
	for(int i = 0; i < N; i++){
		if(EqualCmp(A[i], key)) return i;
	}
	return -1;
}

// бинарный
int BinarySearch(int *A, int N, int key){
	int low = 0;
	int high = N-1;
	int mid;
	
	while(LessEqualCmp(low,high)){
		mid = (low+high)/2;
		if(EqualCmp(A[mid], key)) return mid;
		if(MoreCmp(A[mid], key)) high = mid-1;
		else low = mid+1;
	}
	return -1;
}

// поиск прыжками
int JumpSearch(int *A, int N, int key){
	int JumpStep = sqrt(N);
	int PrevStep = 0;
	while(LessCmp(A[min(JumpStep, N)-1], key)){
		PrevStep = JumpStep;
		JumpStep += sqrt(N);
		if(MoreEqualCmp(PrevStep, N)) return -1;
	}
	SequentialSearch(A, PrevStep, (JumpStep > N)?N:JumpStep , key);
}

int SequentialSearch(int *A, int begin, int end, int key){
	for(int i = begin; i < end; i++){
		if(EqualCmp(A[i], key)) return i;
	}
	return -1;
}

void FillUp(int *A, int N, int min, int max){
	double delta = ((double)(max - min))/N;
	for(int i = 0; i < N; i++){
		A[i] = delta*i+min;
	}
}

void print_array(int *A, int N){
	for(int i = 0; i < N; i++){
		cout << A[i] << ' ';
	}
	cout << endl;
}



