#include <iostream>
using namespace std;

int W2, W4, N4, N6, N9;
int Max_nuggets[100001];    // memoization table
int count = 0;

int buy_nuggets(int n) {
    if (n <= 0) {
        return 0;
    }
    int cost1 = N4 + buy_nuggets(n - 4);
    int cost2 = N6 + buy_nuggets(n - 6);
    int cost3 = N9 + buy_nuggets(n - 9);
    return min(cost1, min(cost2, cost3));
}

int max_nuggets(int money) {
    if (Max_nuggets[money] != -1) {
        return Max_nuggets[money];
    }
    int num1 = 0, num2 = 0, num3 = 0;
    if (money >= N4) {
        num1 = 4 + max_nuggets(money - N4);
    }
    if (money >= N6) {
        num2 = 6 + max_nuggets(money - N6);
    }
    if (money >= N9) {
        num3 = 9 + max_nuggets(money - N9);
    }
    Max_nuggets[money] = max(num1, max(num2, num3));
    return Max_nuggets[money];
}

int nugs(int n){
    if (n == 4) {
        cerr << "nugs(4) ";
    }
    if (n < N4){
        return 0;
    }
    if (n < N6){
        return 4;
    }
    int option4, option6, option9 = 0;
    if (n >= N4){
        option4 = 4 + nugs(n - N4);
    }
    if (n >= N6){
        option6 = 6 + nugs(n - N6);
    }
    if (n >= N9){
        option9 = 9 + nugs(n - N9);
    }
    int option = max(option4, option6);
    return max(option, option9); 
}

int max_nuggets2(int money) {
    // solves it iteratively rather than recursively
    int max_table[10001];
    int m;
    for (m=0; m<N4; m++) {
        max_table[m] = 0;
    }
    for (m=N4; m<N6; m++) {
        max_table[m] = 4 + max_table[m - N4];
    }
    for (m=N6; m<N9; m++) {
        max_table[m] = max(6 + max_table[m - N6], 4 + max_table[m - N4]);
    }
    for (m=N9; m<=money; m++) {
        max_table[m] = max(9 + max_table[m - N9], max(6 + max_table[m - N6], 4 + max_table[m - N4]));
    }
    return max_table[money];
}

int main() {
    int task;

    cin >> task;
    if (task == 1) {
        int x;
        cin >> W2 >> W4 >> x;
        if (W2 / 2.0 <= W4 / 4.0) {
            cout << (x+1) / 2 * W2 << endl;
        } else {
            int n_w4 = x / 4;
            int odd_nuggets = x % 4;
            int cost = n_w4 * W4;
            if (odd_nuggets == 0) {

            } else if (odd_nuggets <= 2) {
                cost += W2;
            } else {
                cost += W4;
            }
            cout << cost << endl;
        }
    } else if (task == 2) {
        int y;
        cin >> W2 >> W4 >> y;
        if (W2 / 2.0 <= W4 / 4.0) {
            cout << y / W2  * 2 << endl;
        } else {
            int n = y / W4 * 4;
            y -= n / 4 * W4;
            cout << n + y / W2 * 2 << endl;
        }
    } else if (task == 3) {
        int x;
        cin >> N4 >> N6 >> N9 >> x;
        cout << buy_nuggets(x) << endl;
    } else if (task == 4) {
        int y;
        for (y=1; y<10001; y++) {
            Max_nuggets[y] = -1;
        }
        cin >> N4 >> N6 >> N9 >> y;
        cout << max_nuggets(y) << endl;
        // for (y=1; y<=40; y++) {
        //     cerr << y << ": " << Max_nuggets[y] << endl;
        // }
    }

    return 0;
}