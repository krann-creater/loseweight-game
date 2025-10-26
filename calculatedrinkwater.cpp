#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double weight;
    cout << "Enter your weight (kg): ";
    if (!(cin >> weight) || weight <= 0) {
        cout << "Please enter a positive number.\n";
        return 1;
    }

    cout << "Select your activity level:\n";
    cout << "1 = Low (mostly sitting)\n";
    cout << "2 = Moderate\n";
    cout << "3 = High (heavy exercise)\n";
    int level;
    cin >> level;

    double base_ml_per_kg = 35.0;
    double factor = 1.0;
    if (level == 1) factor = 0.9;
    else if (level == 2) factor = 1.0;
    else if (level == 3) factor = 1.2;
    else {
        cout << "Invalid level. Using moderate by default.\n";
    }

    double total_ml = weight * base_ml_per_kg * factor;
    double liters = total_ml / 1000.0;

    cout << fixed << setprecision(1);
    cout << "\nRecommended water intake per day: "
         << total_ml << " ml (" << liters << " L)\n";
    cout << "(Based on " << base_ml_per_kg
         << " ml/kg and activity multiplier " << factor << ")\n";
    return 0;
}
