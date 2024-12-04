#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
/*
Author: Alex Chan
Description:
Text based educational game for ENG4U film analysis on Persepolis (2007)
- Question types
    - Know your Martyrs!
    - Test of faith!
    - Identify the enemy of the state!

If your suspicion meter reaches 5, you are arrested (game over)
*/

struct Question { //structure to hold question info
    string question;
    vector<string> answers;
    int correctIndex;
};

Question generateQuestion(string gamemode) {
    
}

/**
 * 
 * @param Question structure
 */
bool askQuestion(const Question &q) {
    cout << q.question + "(1 - " << q.answers.size() + ")" << endl;

    for (int i = 0; i < q.answers.size(); i++) {
        cout << i + ": " + q.answers[i] + "\n" << endl;
    }

    return true;
}

int main() {

    int userChoice = 0;
    int suspicionMeter = 5;
    cout << "Long live the Islamic Republic of Iran!" << endl;
    while (suspicionMeter < 5) { //main game loop
        cout << "Which gamemode would you like to play? \n 1. Know Your Martyrs! \n 2. Test of faith! \n 3. Identify the enemy of the state! (1/2/3)" << endl;
        cin >> userChoice; //user input
        
        switch(userChoice) { //gamemode
            case 1: //martyr
            
                break;

            case 2: //faith
                break;

            case 3: //state
                break;
        }
    }

    return 0;
}