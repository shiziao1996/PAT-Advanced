#include <iostream>
#include <string>
using namespace std;

const string ss[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void solve(char s[]){
	int i = 0;
	int sum = 0;
	while(s[i]!='\0'){
		sum += s[i] - '0';
		i++;
	}
    string str = to_string(sum);
	int len = str.length();
	for(int i = 0; i < len - 1; i++){
		cout << ss[str.at(i) - '0'] << " ";
	}
	cout << ss[str.at(len-1) - '0'] << endl;
}

int main(int argc, char *argv[]) {
	char s[200] = {'\0'};
	while(scanf("%s", &s) == 1){
		solve(s);
	}
	return 0;
}