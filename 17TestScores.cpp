#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Student;
class TestScore;
int getlineCount();

class Student {
private:
    string name;
    int score;

public:
    void setName(string name) {
        this->name = name;
    }

    void setScore(int score) {
        this->score = score;
    }

    int getScore() {
        return score;
    }

    void printStudent() {
        cout << name << " " << score << endl;
    }
};

class TestScore {
private:
    Student* students;

public:
    Student* getStudents() {
        return students;
    }

    void setStudents(int size) {
        students = new Student[size];
    }

    Student highestScore(int size) {
        int highScoreIndex = 0;
        int maxScore = 0;

        for (int i = 0; i < size; i++) {
            if ((students + i)->getScore() > maxScore) {
                highScoreIndex = i;
                maxScore = (students + i)->getScore();
            }
        }

        Student copy = *(students + highScoreIndex);
        (students + highScoreIndex)->setScore(0);
        return copy;
    }

    TestScore() {}

    ~TestScore() {
        delete[] students;
        cout << "Deallocating students on heap." << endl;
    }
};

int main() {
    ifstream ifs;
    int score;
    int index = 0;
    string student;

    int lineCount = getlineCount();
    TestScore ts;
    ts.setStudents(lineCount);
    Student* students = ts.getStudents();

    ifs.open("testscore.txt");

    while (getline(ifs, student)) {
        string firstName, secondName, fullName;
        stringstream ss;
        ss << student;
        ss >> firstName >> secondName >> score;
        ss.ignore();
        fullName = firstName + " " + secondName;

        (students + index)->setName(fullName);
        (students + index)->setScore(score);
        ++index;
    }

    for (int i = 0; i < 10; i++) {
        ts.highestScore(lineCount).printStudent();
    }

    ifs.close();
    return 0;
}

int getlineCount() {
    int lineCount = 0;
    string line;
    ifstream ifs;
    ifs.open("testscore.txt");

    while (getline(ifs, line)) {
        ++lineCount;
    }

    ifs.close();
    return lineCount;
}
