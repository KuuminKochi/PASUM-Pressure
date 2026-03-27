#include <thread>
#include <iostream>
#include <string>
#include "utils/faithscode.cpp"
#include "utils/initializeacademicquestions.cpp"
#include "utils/initializejatidiriquestions.cpp"
#include "utils/initializestory.cpp"
#include "utils/structs.hpp"

using namespace std;

// Initialization Week
const int INITIALWEEK = 0;
const int INITIALACADEMIC = 20;
const int INITIALJATIDIRI = 80;
const int INITIALSTRESS = 20;
const int INITIALROUTE = 2;
const int MAXQUESTION = 10;

// Ending Conditions
const int FINALWEEK = 7;

void clearScreen() {
    system("cls");
    system("clear");
}

GameState initializeGame() {
    GameState state;
    state.week = INITIALWEEK;
    state.academic = INITIALACADEMIC;
    state.jatiDiri = INITIALJATIDIRI;
    state.stress = INITIALSTRESS;
    state.route = INITIALROUTE;
    return state;
}

GameState checkRoute(GameState state) {
    if (state.stress <= 50) {
        state.route = 1; 
    }

    if (state.stress > 50) {
        state.route = 2; 
    }

    return state;
}

GameState run_academic_quiz(GameState state, int subjects) {
    Question* questions = initializeAcademicQuestions(state, subjects);
    for ( int i = 0 ; i < MAXQUESTION; i++) {
        clearScreen();
        Question cur_question = *(questions + i);
        displayBar("Academic", state.academic);
        displayBar("Stress", state.stress);
        int selection = displayQuestion(i, cur_question.questionText, cur_question.options);
        if (selection == cur_question.answer) {
            state.academic += 10;
        } else {
            state.jatiDiri > 80 ? state.stress += 5 : state.stress += (5 * 1.5);
            state.academic -= 3;
        }
    }
    return state;
}


// Write `runJatiDiriQuiz()` — score questions, apply `stress *= 1.2` if < 80%
GameState run_jatidiri_quiz(GameState state) {
    Question* questions = initializeJatiDiriQuestions(state);
    for ( int i = 0 ; i < MAXQUESTION; i++) {
        clearScreen();
        Question cur_question = *(questions + i);
        system("cls");
        system("clear");
        displayBar("Jati Diri", state.jatiDiri);
        int selection = displayQuestion(i, cur_question.questionText, cur_question.options);
        if (selection == cur_question.answer) {
            state.jatiDiri += 5;
        } else {
            state.jatiDiri -= 8;
        }
    }
    return state;
}

GameState endingEvaluator(GameState state) {
    switch (state.route) {
        case 0:
            cout << "Suicide Route: oh..." << endl;
        case 1:
            cout << "Counselor Route: You good cuh?" << endl;
        case 2:
            cout << "Healthy Route: Yay!" << endl;
        default:
            cout << "I guess... You're none?";
    }
    return state;
}

void dialogueParser(string* dialogues) {
    clearScreen();
    string keywords[10] = {"$CLEAR", "$END", "$STREAM", "$STREAMFAST", "$STREAMSLOW"};
    for ( int i = 0 ; i < 300 ; i++ ) {
        if ( *(dialogues + i) == keywords[0] ){
            clearScreen();
        }
        else if ( *(dialogues + i) == keywords[1] ){
            clearScreen();
            break;
        }
        else if ( *(dialogues + i ) == keywords[2] ){
            i++;
            for (char ch : *(dialogues + i) ) {
                cout << ch << flush;
                this_thread::sleep_for(80ms);
            }
            this_thread::sleep_for(3000ms);
            clearScreen();
        }
        else if ( *(dialogues + i ) == keywords[3] ){
            i++;
            for (char ch : *(dialogues + i) ) {
                cout << ch << flush;
            }
            this_thread::sleep_for(500ms);
            clearScreen();
        }

        else if ( *(dialogues + i ) == keywords[4] ){
            i++;
            for (char ch : *(dialogues + i) ) {
                cout << ch << flush;
                this_thread::sleep_for(200ms);
            }
            this_thread::sleep_for(3000ms);
            clearScreen();
        }

        else if (i > 250) {
            cout << "YOU FORGOT \"$END\"" << endl;
        } else {
            cout << *(dialogues + i) << endl;
            cin.get();
        }
    }
}

void displayStory(GameState state) {
    string* dialogues = initializeStory(state);
    dialogueParser(dialogues);
}


void displayInterlude(GameState state) {
    string* dialogues = initializeInterlude(state);
    dialogueParser(dialogues);
}

int main(int argc, char const *argv[])
{
    clearScreen();
    GameState state = initializeGame(); 
    while (state.week <= FINALWEEK) {
        displayStory(state);
        int subjects = displaySubjectMenu();
        state = run_academic_quiz(state, subjects);
        this_thread::sleep_for(300ms);
        displayInterlude(state);
        state = run_jatidiri_quiz(state);
        displayWeekSummary(state);
        cout << "\n Continue: ...";
        cin.get();
        state.week++;
        clearScreen();
    }
    return 0;
}
