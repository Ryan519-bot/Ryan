#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Student{

public:

    string m_name;
    int m_score;

    Student(string name, int score): m_name(name), m_score(score){}

};

void printMenu(){
    cout << "0. EXIT" << endl;
    cout << "1. ADD STUDENT" << endl;
    cout << "2. DELETE STUDENT" << endl;
    cout << "3. SHOW STUDENT LIST" << endl;
    cout << "4. SEARCH STUDENT'S SCORE" << endl;
    cout << "5. FIND AVERAGE, HIGHEST AND LOWEST SCORE" << endl;
    cout << "6. CLEAR ALL STUDENTS" << endl;
}

void saveToFile(vector<Student>&v){
    ofstream ofs;

    ofs.open("Student_List", ios::out);
    
    if(!ofs.is_open()){
        cout << "Failed to open file!" << endl;
        return;
    }

    for(const auto &Student : v){
        ofs << Student.m_name << "  " << Student.m_score << endl;
    }

    ofs.close();
}

void readFromFile(){
    ifstream ifs;
    ifs.open("Student_List", ios::in);

    if(!ifs.is_open()){
        cout << "Failed to open file!" << endl;
        return;
    }

    char buf[1024] = {0};

    while(ifs.getline(buf, sizeof(buf))){
         cout << buf << endl;
    }

    ifs.close();
}

void loadFromFile(vector<Student>&v){
    ifstream ifs;

    ifs.open("Student_List", ios::in);

    if(!ifs.is_open()){
        return;
    }

    string name;
    int score;

    while(ifs >> name >> score){
        v.push_back(Student(name, score));
    }

    ifs.close();
}


int main(){

    vector<Student>v;

    loadFromFile(v);

    printMenu();

    string name;
    int score;

    bool End = true;

    while (true){
        cout << "Choose 0 - 6: ";
        int choice;
        cin >> choice;

        while(choice < 0 || choice > 6){
            cout << "Out of range, try again" << endl;
            cout << "Choose 1 - 6: ";
            cin >> choice;
        }

        switch (choice){
            case 0:
            {
                return 0;
                break;
            }

            case 1:
            {
                cout << "Enter the name of student: ";
                cin >> name;

                cout << endl;

                cout << "Enter the score of student: ";
                cin >> score;

                while(score < 0 || score > 100){
                    cout << "Out of range, invalid score" << endl;
                    cout << "Enter the score of student: ";
                    cin >> score;
                }

                Student s(name, score);

                v.push_back(s);

                saveToFile(v);

                break;
            }

            case 2:
            {
                cout << "Enter the name of student to delete: ";
                cin >> name;

                bool found = false;

                auto it = v.begin();
                while (it != v.end()){
                    if(name == it->m_name){
                        it = v.erase(it);
                        cout << "Student deleted" << endl;
                        found = true;
                        saveToFile(v);
                    }
                    else{
                        it++;
                    }
                }

                if(!found){
                    cout << "Student not found!" << endl;
                }

                break;
            }

            case 3:
            {
                if(v.empty()){
                    cout << "Student List is empty" << endl;
                }
                else{
                    readFromFile();
                }

                break;
            }

            case 4:
            {
                cout << "Enter name of student to search: ";
                cin >> name;

                bool found = false;

                for(vector<Student>::iterator it = v.begin(); it != v.end(); it++){
                    if(name == it->m_name){
                        cout << it->m_name << "'s score: " << it->m_score << endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout << "Student Not Found" << endl;
                }

                break;
            }

            case 5:
            {
                int sum = 0;
                int highest = 0;
                string highestStudent = " ";
                int lowest = 100;
                string lowestStudent = " ";

                for(vector<Student>::iterator it = v.begin(); it != v.end(); it++){
                    sum = sum + it->m_score;//calculate total mark

                    //find highest mark
                    if(it->m_score > highest){
                        highest = it->m_score;
                        highestStudent = it->m_name;
                    }

                    //find lowest mark
                    if(it->m_score < lowest){
                        lowest = it->m_score;
                        lowestStudent = it->m_name;
                    }
                }
                
                double average = 0;
                //only function when vector is not empty
                if(v.size() != 0){
                    average = sum / v.size();//calculate average mark
                    cout << "Average: " << average << endl;
                    cout << "Highest mark: "  << highest << " (" << highestStudent << ")" << endl;
                    cout << "lowest mark: "  << lowest << " (" << lowestStudent << ")" << endl;
                }
                //if vector is empty, print message
                else{
                    cout << "Student list is empty!" << endl;
                }

                break;
            }

            case 6:
            {
                cout << "Are you sure want to delete all the student's info?" << endl;
                cout << "1 - YES" << endl;
                cout << "2 - NO" << endl;

                int option;
                cin >> option;

                while(option < 1 || option > 2){
                    cout << "Invalid option"  << endl;
                    break;
                }

                //can directly use v.clear()
                if(option == 1){
                    auto it = v.begin();
                    while (it != v.end()){
                        it = v.erase(it);
                    }
                    saveToFile(v);
                    cout << "Student List is empty now" << endl;
                }
                else{
                    break;
                }
                
                break;
            }
        }
    }
}