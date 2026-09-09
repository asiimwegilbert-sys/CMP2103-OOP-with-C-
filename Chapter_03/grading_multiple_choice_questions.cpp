// This program grades a multiple-choice test for eight students and ten
// questions. Each student's answers are stored as a row in a 2D array,
// and the answer key is stored in a 1D array. The program compares each
// student's answers to the key, counts the number correct, and displays
// the result for every student.

#include <iostream>
using namespace std;

int main() {
    const int NUM_STUDENTS = 8;
    const int NUM_QUESTIONS = 10;

    // Students' answers to the questions
    char answers[NUM_STUDENTS][NUM_QUESTIONS] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 0
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'}, // Student 1
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'}, // Student 2
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'}, // Student 3
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 4
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 5
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 6
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}  // Student 7
    };

    // Key to the questions
    char key[NUM_QUESTIONS] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // Grade each student and display the result
    for (int student = 0; student < NUM_STUDENTS; student++) {
        int correctCount = 0;

        for (int question = 0; question < NUM_QUESTIONS; question++) {
            if (answers[student][question] == key[question]) {
                correctCount++;
            }
        }

        cout << "Student " << student << "'s correct count is "
             << correctCount << endl;
    }

    return 0;
}