#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Author: Alex Chan
Description:
Text based educational game for ENG4U film analysis on Persepolis (2007)
- Question types
    - Know your Martyrs!
    - Test of faith!
    - Identify the enemy of the state! - randomized profiles

If your suspicion meter reaches 3, you are arrested (game over)
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

//State
vector<string> sogood = {"hospital director", "soldier", "quaran reciter", "islamic scholar", "calligrapher", "religious book publisher", "Imam"};//occupation
vector<string> sobad = {"document counterfieter", "prohibited goods merchant", "women's rights advocator"};

vector<string> shgood = {"calligraphy", "carpet weaving", "cooking", "gardening", "hiking", "chess", "cycling", "painting", "pottery"}; //hobbies
vector<string> shbad = {"dancing", "world history", "drinking", "activist", "gambling", "unlawful protests", "violating dress codes", "peaceful demonstrations"};

vector<string> spgood = {"Respectful", "Polite", "Hardworking", "Family-oriented", "Honest", "Modest", "Loyal", "Responsible", "Patient", "Hospitable", "Courteous"};//personality
vector<string> spbad = {"rebellious", "defiant", "disobedient", "disrespectful", "ungrateful"};

/**
 * generates a random number
 */
int generateRandom(int limit) {
    return rand() % limit; //generating a random number, limit is exclusive
}

/**
 * choose a random string from a list
 */
string pickRandom(const vector<string> list) {
    return list[generateRandom(list.size())]; //return random string picked from list
}

/**
 * Generates new questions!!!!
 * @param int gamemode
 */
Question generateQuestion(int gamemode) {
    Question tempQuestion;
    int rightChoice = generateRandom(4);
    tempQuestion.correctIndex = rightChoice;

    switch(gamemode) { //gamemode
        case 1: //martyr
        tempQuestion.question = "Which of these is a characteristic of a martyr?";

            for (int i = 0; i < 4; i++) {
                if (i != rightChoice) {
                    tempQuestion.answers.push_back(pickRandom(mbad)); //add random string from list to the answer vector
                }
                else {
                    tempQuestion.answers.push_back(pickRandom(mgood)); //add random string from list to the answer vector
                }
            }
            //cout << tempQuestion.answers.at(0);
            break;

        case 2: //faith
        tempQuestion.question = "Which article of clothing is best for preserving a woman's dignity from the eyes of men?";
            for (int i = 0; i < 4; i++) {
                if (i != rightChoice) {
                    tempQuestion.answers.push_back(pickRandom(fbad)); //add random string from list to the answer vector
                }
                else {
                    tempQuestion.answers.push_back(pickRandom(fgood)); //add random string from list to the answer vector
                }
            }
            break;

        case 3: //state
        tempQuestion.question = "Who is a secret communist sympathizer?";
            for (int i = 0; i < 4; i++) {
                if (i != rightChoice) {
                    tempQuestion.answers.push_back("Is a " + pickRandom(sogood) + " ! Likes " + pickRandom(shgood) + "! Sometimes " + pickRandom(spgood)); //profile consists of random occupations, hobbies, and personality traits
                }
                else {
                    int ranNum = generateRandom(4); //generating a random number for a random suspicious attribute
                    switch (ranNum) {
                        case 1:
                            tempQuestion.answers.push_back("Is a " + pickRandom(sobad) + " ! Likes " + pickRandom(shgood) + "! Sometimes " + pickRandom(spgood));
                        break;
                        case 2:
                            tempQuestion.answers.push_back("Is a " + pickRandom(sogood) + " ! Likes " + pickRandom(shbad) + "! Sometimes " + pickRandom(spgood));
                        break;
                        case 3:
                            tempQuestion.answers.push_back("Is a " + pickRandom(sogood) + " ! Likes " + pickRandom(shgood) + "! Sometimes " + pickRandom(spbad));
                    }
                }
            }
            break;
    }
    return tempQuestion;
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
    int userAnswer = 0;
    int gamemode = 0;
    int suspicionMeter = 0;
    cout << "Long live the Islamic Republic of Iran!" << endl;
    while (suspicionMeter <= 3) { //main game loop, 3 chances in total until imprisonment
        cout << "Which subject would you like to play? \n 1. Know Your Martyrs! \n 2. Test of faith! \n 3. Identify the enemy of the state!" << endl;
        cin >> gamemode; //user input
        
        //playing game!!!
        Question question = generateQuestion(gamemode); //get random question based on current gamemode
        cout << question.question << "\n" << endl; //print out the question
        
        //print out answers to choose from
        for (int i = 0; i < question.answers.size(); i++) {
            cout << i + ": \t" + question.answers[i] + "\n" << endl;
        }
        
        //ask for answer
        cin >> userAnswer;
        if (userAnswer == question.correctIndex + 1) { //user guesses correctly
            cout << "Good job! It all depends on God's will!" << endl;
        }
        else {
            cout << "Wrong answer! Remember to swear your allegience to the Islamic Republic of Iran, or else you will be damned for all eternity! Suspicion: " + suspicionMeter << endl;
            suspicionMeter++;
        }
    }
    cout << "You are being arrested for treason and will be processed under Quaran law." << endl;
    return 0;
}