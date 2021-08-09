// full solution using memoization in subtask 4
#include <iostream>
using namespace std;

int W2, W4, N4, N6, N9;
int Max_nuggets[10001];    // memoization table

int f(int n) {
    if (n <= 0) {
        return 0;
    }
    int cost1 = N4 + f(n - 4);
    int cost2 = N6 + f(n - 6);
    int cost3 = N9 + f(n - 9);
    return min(cost1, min(cost2, cost3));
}

int max_nuggets(int money) {
    if (money < N4)
        return 0;
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
        cout << f(x) << endl;
    } else if (task == 4) {
        int i, y;
        cin >> N4 >> N6 >> N9 >> y;
        for (i=1; i<=y; i++) {
            Max_nuggets[i] = -1;
        }
        cout << max_nuggets(y) << endl;
    }

    return 0;
}