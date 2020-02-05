
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

struct factor {
	int val;
	int num;
};
// 求size范围内所有素数
void generatePrimes(vector<int> &primes, vector<bool> &h) {
	int size = h.size() - 1;
	for (int i = 2; i < size; i++) {
		if (h[i] == false) {
			primes.push_back(i);
			for (int j = i; j < size; j += i) {
				h[j] = true;
			}
		}
	}
}

int main(){
	// 输入
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1=1" << endl;
		return 0;
	}
	int a = n;
	int sqr = sqrt(n * 1.0);
	vector<int> primes;
	vector<bool> h(sqr + 1, false);
	vector<factor> v;
	// 生成素数表
	generatePrimes(primes, h);
	// 查表
	for (int i = 0; i < primes.size(); i++) {
		// 是因数
		if (n%primes[i] == 0) {
			factor f;
			f.val = primes[i];
			f.num = 0;
			while (n % primes[i] == 0) {
				n /= primes[i];
				f.num++;
			}
			v.push_back(f);
		}
	}
	// 有可能存在大于sqrt的因数
	if (n > 1) {
		factor f;
		f.val = n;
		f.num = 1;
		v.push_back(f);
	}

	// 输出
	if (v[0].num > 1) {
		cout << a << "=" << v[0].val << "^" << v[0].num;
	}
	else {
		cout << a << "=" << v[0].val;
	}
	for (int i = 1; i < v.size(); i++) {
		if (v[i].num > 1) {
			cout << "*" << v[i].val << "^" << v[i].num;
		}
		else {
			cout<< "*" << v[i].val;
		}
	}
	return 0;
}

