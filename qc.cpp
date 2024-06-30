#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Question {
private:
    string questionText;
    vector<string> options;
    int correctOption;

public:
    Question(const string& text, const vector<string>& opts, int correct)
        : questionText(text), options(opts), correctOption(correct) {}

    void displayQuestion() const {
        cout << questionText << "\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << "\n";
        }
    }

    bool isAnswerCorrect(int chosenOption) const {
        return (chosenOption == correctOption);
    }

    string getCorrectOption() const {
        return options[correctOption];
    }

    string getOption(int index) const {
        return options[index];
    }
};

class Student {
private:
    string name;
    int id;

public:
    Student(const string& studentName, int studentID)
        : name(studentName), id(studentID) {}

    void takeQuiz(const vector<Question>& questions) {
        int score = 0;
        cout << "Welcome, " << name << "! Let's start the quiz.\n";

        vector<int> userAnswers;

        for (size_t i = 0; i < questions.size(); ++i) {
    cout << "\nQuestion " << i + 1 << ":\n";
    questions[i].displayQuestion();
    int chosenOption;
    cout << "Your choice: ";
    cin >> chosenOption;

    if (chosenOption >= 1 && chosenOption <= 4) {
        userAnswers.push_back(chosenOption - 1);

        if (questions[i].isAnswerCorrect(chosenOption - 1)) {

            cout << "\033[38;2;0;128;0m" << "Correct!" << "\033[0m" << endl;
            score++;
        } else {
            cout << "\033[31m" << "Incorrect!" << "\033[0m" << endl;
        }
    } else {
        cout << "Invalid choice. Take the right choice.\n";
        userAnswers.push_back(-1);
        i--;
    }
}


        cout << "\nQuiz completed, " << name << "!\n";
        cout << "Your score: " << score << " out of " << questions.size() << "\n";

        cout << "\nCorrect answers:\n";
        for (size_t i = 0; i < questions.size(); ++i) {
            cout << "Question " << i + 1 << ": " << questions[i].getCorrectOption() << "\n";
        }

        cout << "\nYour answers:\n";
        for (size_t i = 0; i < userAnswers.size(); ++i) {
            cout << "Question " << i + 1 << ": ";
            if (userAnswers[i] == -1) {
                cout << "Skipped or invalid answer\n";
            } else {
                cout << questions[i].getOption(userAnswers[i]) << "\n";
            }
        }
    }
};

int main() {

    cout << "Welcome to QuizCraft!\n";

    vector<Question> questions = {
        Question("What is the capital of Bangladesh?", {"Rajshahi", "Dhaka", "Sylhet", "Rangpur"}, 1),
        Question("Which sign is known as Terminator in C and C++ code?", {":", "/", "|", ";"}, 3),
        Question("What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 1),
        Question("What gas do plants use for photosynthesis?", {"Oxygen", "Carbon Dioxide", "Nitrogen", "Hydrogen"}, 1),
        Question("What is the largest organ in the human body?", {"Heart", "Lungs", "Skin", "Liver"}, 2)
    };


    string studentName;
    int studentID;

    cout << "Student Name: ";
    getline(cin, studentName);
    cout << "Student ID: ";
    cin >> studentID;


    Student student(studentName, studentID);
    student.takeQuiz(questions);

    cout << "\nThank You For Participate!" << endl;
}
