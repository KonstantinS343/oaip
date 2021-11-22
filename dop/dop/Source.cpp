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
		int index;
		string str;
		string word;
		int lenth;
		cout << "¬ведите строку:";
		getline(cin, str);
		char space = ' ';
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				
					word = str.substr(0, i);
					stroka.push_back(word);
;					str.erase(0, i + 1);
				
				i = 0;
			}
		}
		stroka.push_back(str);
		strokav2 = convert(stroka);
		for (int i = 0; i < stroka.size(); i++) {
			cout << stroka[i];
			cout << " ";
		}
		cout << "\n";
		int y = stroka.size();
		for (int i = 0; i < y; i++) {
			obrazec = i;
			for (int k = i+1; k < strokav2.size(); k++) {
				if (strokav2[i][0] == strokav2[k][0]) {
					for (int counter = 0; counter < strokav2[i].size() - 1; counter++) {
						if (strokav2[i].size() > strokav2[k].size()) {
							break;
						}
						if (strokav2[k].size() > strokav2[i].size()) {
							break;
						}
						if (strokav2[i][counter] == strokav2[k][counter]) {
							if (counter == strokav2[k].size() - 2) {
								index=k;
								int lenobr = stroka[obrazec].size();
								
									int lenth = stroka[index].size();
									if (stroka[index][lenth - 1] == toupper(stroka[index][lenth - 1])) {
										stroka[index][lenth - 1] = toupper(stroka[obrazec][lenobr - 1]);
									}
									else {
										if (stroka[obrazec][lenobr - 1] == toupper(stroka[obrazec][lenobr - 1]) && stroka[index][lenth - 1] == tolower(stroka[index][lenth - 1])) {
											stroka[index][lenth - 1] = tolower(stroka[obrazec][lenobr - 1]);
										}
										else {
											stroka[index][lenth - 1] = stroka[obrazec][lenobr - 1];
										}
									}
									strokav2 = convert(stroka);
							}
						}
					}
				}
			}

		}
		string answer;
		for (int i = 0; i < stroka.size(); i++) {
			answer+=stroka[i];
			answer+=" ";
		}
		cout << answer;

		return 0;
	}