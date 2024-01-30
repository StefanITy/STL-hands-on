#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct Problem {
    string name;
    string speciality;
};

struct Doctor {
    string id;
    string speciality;
};


bool matchesSpeciality(const Doctor &doctor,const Problem &problem) {
    return doctor.speciality == problem.speciality;
}

int main() {
    ifstream inFile("HandsOn-Input.txt");
    
    int n, m;
    inFile >> n;
    
    vector<Problem> problems(n);
    for (Problem &p : problems) {
        inFile >> p.name >> p.speciality;
    }

    inFile >> m;
    vector<Doctor> doctors(m);
    for (Doctor &d : doctors) {
        inFile >> d.id >> d.speciality;
    }

    for (Doctor d : doctors) {
        for (Problem p : problems) {
            if (matchesSpeciality(d, p)) {
                cout << d.id << " " << p.name<<"\n";
                break;
            }
        }
    }

    inFile.close();
    
    return 0;
}