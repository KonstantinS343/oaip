#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class set {
private:
    vector<string> unoriented_set;
public:
    int load_from_file(int);
    void make_set(bool*, vector<string>, int);
    void delete_set();
};

void print(vector<string>);

int main() {

    setlocale(LC_ALL, "ru");

    set sets;
    int number_of_test = 1;

    do {
        cout << "Тест " << number_of_test << ":" << endl;
        int size_of_set = sets.load_from_file(number_of_test);

        bool* used = new bool[size_of_set];
        vector<string> buffer_set;

        for (int i = 0; i < size_of_set; i++) {
            used[i] = false;
        }
        cout << "Ориентированные множества:" << endl;
        sets.make_set(used, buffer_set, size_of_set);
        sets.delete_set();
        number_of_test++;
        cout << endl << endl;
    } while (number_of_test <= 4);

    return 0;

}

int set::load_from_file(int number_of_test) {

    ifstream load_file;
    string buffer;
    string name_of_file = string("test_sets") + to_string(number_of_test) + string(".txt");
    load_file.open(name_of_file);

    load_file >> buffer;

    while (buffer != ";") {
        unoriented_set.push_back(buffer);
        load_file >> buffer;
    }

    cout << "A={";
    print(unoriented_set);
    cout << "};" << endl;

    return unoriented_set.size();
}

void print(vector<string> unoriented_set) {

    int counter = 0;

    for (vector<string>::iterator iterator = unoriented_set.begin(); iterator != unoriented_set.end(); iterator++) {

        if (iterator[0][0] == '{') {
            do {
                if (iterator[0][counter] == ',') {
                    cout << ", ";
                    counter++;
                    continue;
                }
                cout << iterator[0][counter];
                counter++;
            } while (iterator[0][counter] != '}');
            cout << "}";
            if (iterator + 1 != unoriented_set.end()) {
                cout << ", ";
            }
            counter = 0;
            continue;
        }

        cout << *iterator;
        if (iterator + 1 != unoriented_set.end()) {
            cout << ", ";
        }
    }


}

void set::make_set(bool* used, vector<string> buffer_set, int size_of_set) {

    if (buffer_set.size() == size_of_set) {
        cout << "A'=<";
        print(buffer_set);
        cout << ">;" << endl;
    }

    vector<string>::iterator iterator = unoriented_set.begin();

    for (int i = 0; i < size_of_set; i++) {
        if (!used[i]) {
            used[i] = true;
            string str = *iterator;
            buffer_set.push_back(str);
            make_set(used, buffer_set, size_of_set);
            used[i] = false;
            buffer_set.pop_back();
        }
        iterator++;
    }
}

void set::delete_set() {
    unoriented_set.clear();
}
