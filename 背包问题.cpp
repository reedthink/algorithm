//动态规划
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int n = 100000;
int ans[n] = {};

// 01背包
int zero_one_pack(int *w, int *v, int wb, int n) {
    for (int i = 0; i < n; i++) {
        for (int l = wb; l >= w[i]; l--) {
            ans[l] = max(ans[l], ans[l - w[i]] + v[i]);
        }
    }
    return ans[wb];
}

int main() {
    cout << "test comp" << endl;
    return 0;
}