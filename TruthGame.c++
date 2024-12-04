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

//martyrs
vector<string> mgood = {"dies for your freedom", "suffers for you", "true heros of Iran", "foundation of the nation", "defend Islamic Republic against foreign aggressors", "protects your faith", "devotion to Islam and nation"};//things they do
vector<string> mbad = {"ignore responsibility", "surrender to Iraq aggressors", "take long naps", "denounce Allah", "ignore the Islamic law", "disrespect government officials", "challenge authority"};//things they dont do


//Faith
vector<string> fgood = {"hijab", "chador", "manteau", "roo'been", "abaya", "niqab", "shawl"};//appropriate women attire
vector<string> fbad = {"t-shirt", "short sleeve pants", "dress pants", "short dresses", "high heels", "swimwear", "western clothing", "sleeveless tops", "skin-revealing fabrics"};//not okay articles of clothing



//Enemy of state
vector<string> shgood = {"calligraphy", "carpet weaving", "cooking", "gardening", "hiking", "chess", "backgammon", "cycling", "painting", "pottery"}; //hobbies
vector<string> sogood = {"hospital director", "soldier", ""}//occupation
//personality


/**
 * Generates new questions!!!!
 * @param int gamemode
 */
Question generateQuestion(int gamemode) {
switch(gamemode) { //gamemode
            case 1: //martyr
            
                break;

            case 2: //faith
                break;

            case 3: //state
            
                break;
        }
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

    int gamemode = 0;
    int suspicionMeter = 5;
    cout << "Long live the Islamic Republic of Iran!" << endl;
    while (suspicionMeter < 5) { //main game loop
        cout << "Which subject would you like to play? \n 1. Know Your Martyrs! \n 2. Test of faith! \n 3. Identify the enemy of the state! (1/2/3)" << endl;
        cin >> gamemode; //user input
        
        Question question = generateQuestion(gamemode);
    }

    return 0;
}