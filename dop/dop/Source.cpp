#include<iostream>
#include<string>
#include<cctype>
#include <vector>

using namespace std;
vector<string> convert(vector<string>  str) {
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < str[i].size(); j++) {
			str[i][j] = tolower(str[i][j]);
		}
	}

	return str;
}
	int main() {
		setlocale(LC_ALL, "ru");
		int size = 0, sizes, obrazec;
		vector<string> stroka;
		vector<string> strokav2;
		vector<int>index;
		int lenth;
		cout << "¬ведите строку:";
		stroka.resize(1000);
		for (int i = 0; i < 1000; i++) {
			cin >> stroka[i];
			size++;
			if (stroka[i] == ".") {
				break;
			}
		}
		stroka.resize(size);
		strokav2 = convert(stroka);
		for (int i = 0; i < size; i++) {
			cout << stroka[i];
			cout << " ";
		}
		cout << "\n";
		for (int i = 0; i < size; i++) {
			obrazec = i;
			for (int k = 1; k < strokav2.size(); k++) {
				if (strokav2[i][0] == strokav2[k][0]) {
					for (int counter = 0; counter < strokav2[i].size() - 1; counter++) {
						if (counter == strokav2[k].size()) {
							break;
						}
						if (strokav2[i][counter] == strokav2[k][counter]) {
							if (counter == strokav2[k].size() - 2) {
								index.push_back(k);
								size = 1;
							}
						}
					}
				}
			}

		}
		int lenobr = stroka[obrazec].size();
		for (int i = 0; i < index.size(); i++) {
			int lenth = stroka[index[i]].size();

			stroka[index[i]][lenth - 1] = stroka[obrazec][lenobr - 1];
		}
		for (int i = 0; i < stroka.size(); i++) {
			cout << stroka[i];
			cout << " ";
		}

		return 0;
	}