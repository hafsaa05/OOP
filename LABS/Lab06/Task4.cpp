/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;
#include <iostream>

inline double BattingAverage(int totalRuns, int timesDismissed) {
    {
        return totalRuns/timesDismissed;
    }
}

inline double StrikeRate(int totalRuns, int totalBallsFaced) {
{
    return totalRuns/totalBallsFaced * 100;

}    
}

int main() {
    int totalRuns, timesDismissed, totalBalls;

    cout << "Enter total runs scored: ";
    cin >> totalRuns;
    cout << "Enter number of times dismissed: ";
    cin >> timesDismissed;
    cout << "Enter total balls faced: ";
    cin >> totalBalls;

    double battingAvg = BattingAverage(totalRuns, timesDismissed);
    double strikeRate = StrikeRate(totalRuns, totalBalls);

    cout << "Batting Average: " << battingAvg << std::endl;
    cout << "Strike Rate: " << strikeRate << std::endl;

    return 0;
}

