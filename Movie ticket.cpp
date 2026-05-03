#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
    unordered_map<int, set<int>> movieBookings; // movieID -> set of userIDs
    unordered_map<int, int> available; // movieID -> available seats

public:
    MovieTicket() {}

    bool book(int x, int y) {
        if (movieBookings[y].count(x)) return false;
        if (available[y] == 0 && movieBookings[y].size() >= 100) return false;

        movieBookings[y].insert(x);
        available[y] = 100 - movieBookings[y].size();
        return true;
    }

    bool cancel(int x, int y) {
        if (!movieBookings[y].count(x)) return false;

        movieBookings[y].erase(x);
        available[y] = 100 - movieBookings[y].size();
        return true;
    }

    bool isBooked(int x, int y) {
        return movieBookings[y].count(x);
    }

    int availableTickets(int y) {
        return 100 - movieBookings[y].size();
    }
};

int main() {
    int Q;
    cin >> Q;
    MovieTicket mt;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (mt.book(x, y) ? "true" : "false") << endl;
        }
        else if (op == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (mt.cancel(x, y) ? "true" : "false") << endl;
        }
        else if (op == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (mt.isBooked(x, y) ? "true" : "false") << endl;
        }
        else if (op == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << mt.availableTickets(y) << endl;
        }
    }
}