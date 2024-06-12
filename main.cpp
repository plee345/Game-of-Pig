#include "util.h"

void spaceLines(){
    for (int i = 0; i < 3; i++){
        cout << "--------------------" << endl;
    }
}

void oppTurn(int compTurns, int compRoundScore, int compTotalScore){
    while (compRoundScore < 15){
        int randNum = randInt(1,6);
        if (randNum == 1){
            cout << "The computer rolled a 1. End of turn" << endl;
            compRoundScore = 0;
            compTurns++;
            break;
        }
        cout << "The computer rolled a " << randNum << endl;
        compRoundScore += randNum;
        cout << "This round the computer has: " << compRoundScore << endl;
    }
    compTotalScore = compRoundScore;
    compRoundScore = 0;
    compTurns++;
    cout << "The Computer's total points are: " << compTotalScore << endl;
    spaceLines();
}

int main()
{
    // Enter your code here
    int winningVal = 50;
    int turns = 1;
    int compTurns = 1;
    int totalScore;
    int compTotalScore;
    int compRoundScore;
    int roundScore;
    string input;
    bool decision = false;
    while (totalScore < winningVal && compTotalScore < winningVal){
        cout << "Turn " << turns << endl;
        cout << "Your Current Score is: " << totalScore << endl;
        cout << "This round you have: " << roundScore << endl;
        cout << "Would you like to roll or bank? " << endl;
        cin >> input;
        if (input == "roll"){
            while (!decision){
                int randNum = randInt(1,6);
                cout << "You rolled a " << randNum << endl;
                if (randNum == 1){
                    cout << "You rolled a 1! You get zero for this round!" << endl;
                    roundScore = 0;
                    turns++;
                    spaceLines();
                    oppTurn(compTurns, compRoundScore, compTotalScore);
                    break;
                }
                roundScore += randNum;
                cout << "This round you have " << roundScore  << endl;
                cout << "Would you like to roll or bank?" << endl;
                cin >> input;
                if (input == "bank"){
                    totalScore += roundScore;
                    roundScore = 0;
                    turns++;
                    spaceLines();
                    oppTurn(compTurns, compRoundScore, compTotalScore);
                    break;
                }
            }
        }
        else{
            turns++;
            roundScore = 0;
            oppTurn(compTurns, compRoundScore, compTotalScore);
        }
    }
    if (totalScore >= winningVal && compTotalScore >= winningVal){
        if (totalScore == compTotalScore){
            cout << "Tie!" << endl;
        }
        else if (totalScore > compTotalScore){
            cout << "Congratulation! You won on " << turns << "!" << endl;
        }
        else if (compTotalScore > totalScore){
            cout << "Good try! The Computer won " << turns << "!" << endl;
        }
    }
    if (totalScore >= winningVal){
        cout << "Congratulation! You won on " << turns << "!" << endl;
    }
    if (compTotalScore >= winningVal){
        cout << "Good try! The Computer won " << turns << "!" << endl;
    }
    return 0;
}
