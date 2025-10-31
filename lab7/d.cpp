#include <bits/stdc++.h>
using namespace std;
double GPA(const string& grade) {
    if (grade == "A+") return 4.0;
    else if (grade == "A") return 3.75;
    else if (grade == "B+") return 3.5;
    else if (grade == "B") return 3.0;
    else if (grade == "C+") return 2.5;
    else if (grade == "C") return 2.0;
    else if (grade == "D+") return 1.5;
    else if (grade == "D") return 1.0;
    else return 0.0;
}

struct stud{
    string lastname;
    string firstname;
    double gpa;
};

bool sravni(const stud& a, const stud& b) {
    if(a.gpa != b.gpa) {
        return a.gpa < b.gpa;
    }
    if (a.lastname != b.lastname) return a.lastname < b.lastname;
    return a.firstname < b.firstname;
}

void quick_sort(vector<stud>& arr, int l, int r) {
    if (l >= r) return;
    stud p = arr[(l + r) / 2];
    int i = l;
    int j = r;
    while(i < j){
        while(sravni(arr[i], p)) i++;
        while(sravni(p, arr[j])) j--;
        if(i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if(l < j) {
        quick_sort(arr, l, j);
    }
    if(i < r) {
        quick_sort(arr, i, r);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<stud> students;
    for(int i = 0; i < n; i++) {
        string lastname, firstname;
        int predmety;
        cin >> lastname >> firstname >> predmety;

        double totalpoints = 0.0;
        int totalcredits = 0;


        for(int j = 0; j < predmety; j++) {
            string grade;
            int credits;
            cin >> grade >> credits;
            totalpoints += GPA(grade) * credits;
            totalcredits += credits;
        }

        double gpa = totalpoints / totalcredits;
        students.push_back({lastname, firstname, gpa});
    }
    quick_sort(students, 0, students.size() - 1);
    for(auto it = students.begin(); it != students.end(); ++it) {
        cout << it->lastname << " " << it->firstname << " ";
        cout << fixed << setprecision(3) << it->gpa << endl;
    }
}