#include <iostream>
#include <vector>
#include <string>
#include <ctime>   // For time()
#include <cstdlib> // For rand() and srand()

using namespace std;

int main() {
    // Seed the random number generator so we get different results every run
    srand(static_cast<unsigned int>(time(0)));

    string userName;
    cout << "Enter your name to get roasted: ";
    getline(cin, userName);

    // List of 10 roast templates
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed.",
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name} has a 'get rich quick' scheme that involves returning empty bottles.",
        "I’d explain it to {name}, but I left my crayons at home.",
        "{name} is the reason why instructions are put on shampoo bottles.",
        "If brains were dynamite, {name} wouldn't have enough to blow their nose."
    };

    // Randomly select an index
    int randomIndex = rand() % roasts.size();
    string selectedRoast = roasts[randomIndex];

    // Find and replace the {name} placeholder
    string placeholder = "{name}";
    size_t pos = selectedRoast.find(placeholder);
    
    if (pos != string::npos) {
        selectedRoast.replace(pos, placeholder.length(), userName);
    }

    cout << "\n--- YOUR ROAST ---" << endl;
    cout << selectedRoast << endl;

    return 0;
}
