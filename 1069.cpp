
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

bool increase(int &a, int &b) {
	return a < b;
}

bool decrease(int &a, int &b) {
	return a > b;
}

// 倒过来
void to_array(int n, int a[]) {
	for (int i = 0; i < 4; i++) {
		a[i] = n % 10;
		n /= 10;
	}
}

void to_num(int &n, int a[]) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum = sum * 10 + a[i];
	}
	n = sum;
}


int main(){
	int n;
	cin >> n;
	int min, max;
	int a[5] = { 0 };
	while (1) {
		to_array(n, a);
		sort(a, a + 4, decrease);
		to_num(max, a);
		sort(a, a + 4, increase);
		to_num(min, a);
		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);
		if (n == 6174 || n == 0) break;

	}
	return 0;
}

