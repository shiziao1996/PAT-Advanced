#include <iostream>

using namespace std;

int main(){
    char ch[3] = {'W', 'T', 'L'};
    double a1[3];
    double a2[3];
    double a3[3];
    cin >> a1[0] >> a1[1] >> a1[2]
        >> a2[0] >> a2[1] >> a2[2]
        >> a3[0] >> a3[1] >> a3[2];

    int max_index1 = -1;
    double max1 = 0;
    for(int i = 0; i < 3; i++){
        if(a1[i] > max1){
            max1 = a1[i];
            max_index1 = i;
        }
    }
    cout << ch[max_index1] << " ";

    int max_index2 = -1;
    double max2 = 0;
    for(int i = 0; i < 3; i++){
        if(a2[i] > max2){
            max2 = a2[i];
            max_index2 = i;
        }
    }
    cout << ch[max_index2] << " ";

    int max_index3 = -1;
    double max3 = 0;
    for(int i = 0; i < 3; i++){
        if(a3[i] > max3){
            max3 = a3[i];
            max_index3 = i;
        }
    }
    cout << ch[max_index3] << " ";
    double result = (max1*max2*max3*0.65 - 1) * 2;
    printf("%.2f\n", result);

    return 0;
}