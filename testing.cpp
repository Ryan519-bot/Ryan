// for loop
// #include <iostream>
// using namespace std;

// int main(){
//     double totalWeight = 0;

//     int weightCounter;
//     cout << "Enter weight Counter: ";
//     cin >> weightCounter;

//     cout << endl;

//     for(int Num = 0; Num < weightCounter; Num++){
//         double weight;
//         cout << "Enter weight: ";
//         cin >> weight;

//         cout << endl;

//         totalWeight += weight;
//     }

//     double averageWeight;
//     averageWeight = totalWeight / weightCounter;

//     cout << "Average Weight = " << averageWeight << endl;
//     cout << "Total Weight = " << totalWeight << endl;

//     return 0;
// }


// pre-test loop
#include <iostream>
using namespace std;

int main(){
    double totalWeight = 0;

    int weightCounter;
    cout << "Enter Weight Counter: ";
    cin >> weightCounter;

    cout << endl;

    int Num = 0;
    while(Num < weightCounter){
        double weight;
        cout << "Enter weight: ";
        cin >> weight;

        cout << endl;

        totalWeight += weight;
        Num++;
    }

    double averageWeight;
    averageWeight = totalWeight / weightCounter;

    cout << "Average Weight = " << averageWeight << endl;
    cout << "Total Weight = " << totalWeight << endl;

    return 0;
}