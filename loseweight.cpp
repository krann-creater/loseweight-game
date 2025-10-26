#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
using namespace std;

int main()
{
    int ran =rand()%3+1; 
    // if (ran==1)
    // {
    //     PlaySound(TEXT("notpro.wav"), NULL, SND_FILENAME | SND_ASYNC);
    // }
    // if (ran==2)
    // {
    //     PlaySound(TEXT("pro_1.wav"), NULL, SND_FILENAME | SND_ASYNC);
    // }
    // if (ran==3)
    // {
    //     PlaySound(TEXT("pro2.wav"), NULL, SND_FILENAME | SND_ASYNC);
    // }

    const double BASELINE_STEPS = 10000.0;
    
    double weight, height_cm, goalbmi = 0, bmi;
    double max_kg_per_month; 

    cout << "How much kg you wanna lose per month (Recommended max 4 kg)(really recommended 2kg): ";
    cin >> max_kg_per_month;
    
    if (max_kg_per_month <= 0) {
        cout << "The target weight loss per month must be greater than 0 kg." << endl;
        return 0;
    }
    
    cout << "How much is your weight (kg): ";
    cin >> weight;
    cout << "How tall are you (cm): ";
    cin >> height_cm;

    double height_m = height_cm / 100.0;
    bmi = weight / (height_m * height_m);
    
    cout << fixed << setprecision(4);
    cout << "Your BMI = " << bmi << endl;


    if (bmi >= 30)
    {
        cout << "Your BMI goal is 25-29" << endl;
        goalbmi = 27;
    }
    else if (bmi >= 25)
    {
        cout << "Your BMI goal is 23-24" << endl;
        goalbmi = 24;
    }
    else if (bmi >= 23)
    {
        cout << "Your BMI goal is 18.5-22" << endl;
        goalbmi = 21;
    }
    else if (bmi < 18.5)
    {
        cout << "You are underweight. Your BMI goal should be around 20." << endl;
        goalbmi = 20;
    }
    else
    {
        cout << "You are in the healthy range! Keep it up!" << endl;
        return 0; 
    }
    double goalWeight = goalbmi * (height_m * height_m);
    double weightToLose = weight - goalWeight;

    if (fabs(weightToLose) < 0.1)
    {
        cout << "You are already at your goal BMI! Fantastic!" << endl;
        return 0;
    }
    if (weightToLose > 0)
    {
        double totalStepsToLoseWeight = weightToLose * 192500.0; 
        
        cout << endl;
        cout << fixed << setprecision(2);
        cout << "You need to lose about " << weightToLose << " kg to reach your goal." << endl;
        double monthsNeeded = weightToLose / max_kg_per_month;
        double daysNeeded = monthsNeeded * 30.0;
            
        double additionalStepsPerDay = totalStepsToLoseWeight / daysNeeded;
        
        double totalStepsPerDay = BASELINE_STEPS + additionalStepsPerDay;

        cout << endl << "--- Your Weight Loss Plan ---" << endl;
        
        cout << fixed << setprecision(1); 
        cout << "Weight loss target: " << max_kg_per_month << " kg/month" << endl;
        cout << "Estimated time: " << monthsNeeded << " months (" << daysNeeded << " days)" << endl;
        
        cout << fixed << setprecision(0); 
        cout << "Total daily steps goal: " << totalStepsPerDay << " steps/day" << endl;
        
        cout << setprecision(2) << endl; 
        cout << "Tip: This step count includes the baseline 10,000 steps for general health. Combine walking, light workouts, and a balanced diet for best results! TUTA 💪" << endl;
    }
    else 
    {
        double weightToGain = -weightToLose;
        cout << endl;
        cout << "You need to gain about " << fixed << setprecision(2) << weightToGain << " kg to reach your goal." << endl;
        cout << "A healthy pace to gain weight is about 1 up to 2 kg per month. Focus on nutrient-dense foods and strength training." << endl;
    }

    return 0;
}