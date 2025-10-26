#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const string foodNames[] = {
        "Kaya toast",
        "Salted bread",
        "Pizza",
        "Fried chicken",
        "Donut",
        "Chocolate",
        "Bento snack",
        "Gummy bear",
        "Ice cream",
        "Cappuccino",
        "Americano"
    };

    const int calories[] = {
        420, 300, 800, 550, 250, 230, 600, 150, 200, 120, 15
    };

    double weight;
    int choice;

    cout << "Enter your body weight (kg): ";
    cin >> weight;

    cout << "\nSelect your drink/food:" << endl;
    for (int i = 0; i < 11; i++) {
        cout << i + 1 << ". " << foodNames[i] << endl;
    }

    cout << "\nEnter number (1-11): ";
    cin >> choice;

    if (choice < 1 || choice > 11) {
        cout << "Invalid choice." << endl;
        return 0;
    }

    int index = choice - 1;
    int foodKcal = calories[index];
    double kcalPerStep = weight * 0.0005;
    int steps = static_cast<int>(ceil(foodKcal / kcalPerStep));

    cout << "\n" << foodNames[index]
         << " contains approximately " << foodKcal << " kcal." << endl;
    cout << "You need to walk about " << steps
         << " steps to burn it off." << endl;

    // Food recommendation system
    auto recommend = [&](string altName, int altKcal) {
        int altSteps = static_cast<int>(ceil(altKcal / kcalPerStep));
        int stepsSaved = steps - altSteps;

        cout << "\nSuggestion: " << altName << " is only about "
             << altKcal << " kcal." << endl;
        cout << "You would need about " << altSteps
             << " steps instead." << endl;
        cout << "You save approximately " << stepsSaved
             << " steps and stay healthier." << endl;
    };

    if (foodNames[index] == "Cappuccino" || foodNames[index] == "Americano") {
        recommend("Black coffee", 5);
    }

    if (foodNames[index] == "Ice cream") {
        cout << "\nNote: You should buy this for your son instead of eating it yourself." << endl;
    }

    if (foodNames[index] == "Fried chicken") {
        recommend("Boiled chicken", 200);
        cout << "The best tip ever: You should buy your son some robux";
    }

    if (foodNames[index] == "Pizza") {
        recommend("Salad", 100);
        cout << "The best tip ever: If you cant stop eating you should breath in and out until you buy your son robux";
    }

    if (foodNames[index] == "Chocolate") {
        recommend("Apple", 95);
        cout << "The best tip ever: This will scare docters away from you";
    }

    if (foodNames[index] == "Donut") {
        recommend("Guava", 60);
        cout << "The best tip ever: If you eat donuts you will have holes in your chest like ironman";
    }

    if (foodNames[index] == "Gummy bear") {
        recommend("Orange", 62);
        cout<<"The best tip ever: if you eat orange you wont be round like orange";
    }

    if (foodNames[index] == "Bento snack") {
        recommend("Grilled mushroom", 40);
        cout<< "The best tip ever: if you eat Grilled mushroom you wont get grilled";
    }

    if (foodNames[index] == "Kaya toast") {
        recommend("Water", 0);
        cout << "The best tip: if you eat kaya toast you will turn in to zombie because it was green";
    }

    if (foodNames[index] == "Salted bread") {
        recommend("Tomato", 20);
        cout << "The best tip ever: you should eat the wrost fruit ever";
    }

    return 0;
}
