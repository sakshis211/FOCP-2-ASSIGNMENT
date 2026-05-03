#include <bits/stdc++.h>
using namespace std;

class Bank {
    unordered_map<int, int> balance;

public:
    bool create(int x, int y) {
        if (balance.count(x)) {
            balance[x] += y;
            return false;
        }
        balance[x] = y;
        return true;
    }

    bool debit(int x, int y) {
        if (!balance.count(x) || balance[x] < y) return false;

        balance[x] -= y;
        return true;
    }

    bool credit(int x, int y) {
        if (!balance.count(x)) return false;

        balance[x] += y;
        return true;
    }

    int getBalance(int x) {
        if (!balance.count(x)) return -1;
        return balance[x];
    }
};

int main() {
    int Q;
    cin >> Q;
    Bank bank;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "CREATE") {
            int x, y;
            cin >> x >> y;
            cout << (bank.create(x, y) ? "true" : "false") << endl;
        }
        else if (op == "DEBIT") {
            int x, y;
            cin >> x >> y;
            cout << (bank.debit(x, y) ? "true" : "false") << endl;
        }
        else if (op == "CREDIT") {
            int x, y;
            cin >> x >> y;
            cout << (bank.credit(x, y) ? "true" : "false") << endl;
        }
        else if (op == "BALANCE") {
            int x;
            cin >> x;
            cout << bank.getBalance(x) << endl;
        }
    }
}