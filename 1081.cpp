
#include <iostream>
#include <cstdio>
typedef long long LL;
using namespace std;

struct fraction {
	LL up;
	LL down;
};


LL gcd(LL max, LL min) {
	if (max < min) {
		LL temp = min;
		min = max;
		max = temp;
	}
	if (min == 0) return max;
	else {
		gcd(min, max%min);
	}
}
// 化简分数
// 1. 保证分母为正
// 2. 若分子为0， 分母=1
// 3. 分子分母同除以最大公约数
void reduction(fraction &f) {
	if (f.down < 0) {
		f.down = -f.down;
		f.up = -f.up;
	}
	if (f.up == 0) f.down = 1;
	LL d = gcd(abs(f.up), abs(f.down));
	f.down /= d;
	f.up /= d;
}

fraction add(fraction &f1, fraction &f2) {
	fraction f;
	f.down = f1.down*f2.down;
	f.up = f1.up*f2.down + f2.up*f1.down;
	return f;
}

void print(fraction &f) {
	if (f.down == 1) {
		cout << f.up << endl;
	}
	else if (f.up > f.down) {
		cout << f.up / f.down << " " << f.up%f.down << "/" << f.down << endl;
	}
	else if (f.up == f.down) {
		cout << 1 << endl;
	}
	else if(f.up !=0){
		cout << f.up << "/" << f.down << endl;
	}
	else {
		cout << 0 << endl;
	}
}


int main(){
	LL n;
	cin >> n;
	fraction f;
	f.up = 0;
	f.down = 1;
	fraction f1;
	for (LL i = 0; i < n; i++) {
		scanf("%lld/%lld", &f1.up, &f1.down);
		reduction(f1);
		f = add(f, f1);
		reduction(f);
	}
	print(f);
	return 0;
}

