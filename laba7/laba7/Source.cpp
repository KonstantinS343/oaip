#include<iostream>
#include<string>
#include <cstdio>
#include <stdio.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	char fixdot[100],answer[100];
	string fdot;
	int lenth,counter=1,index=0,index1=0,n=0,y,m=0,w,f,h;
		cout << "Ведите вашу строку:" << endl;
		gets_s(fixdot);
		lenth = strlen(fixdot);
		for (int i = 0; i < 100; i++) {
			answer[i] = ' ';
		}
		for (int i = 0; i < lenth; i++) {
			if (fixdot[i] == '.' && isdigit(fixdot[i - 1] )&& isdigit(fixdot[i + 1])) {
				int k = i-1;
				n = 0;
				m = 0;
				for (k; k >=0; k--) {
					if (isdigit(fixdot[k])) {
						
						index =k;
						n++;
					}
					else {
						break;
					}

				}
				for ( y = 0; y < n; y++) {
					answer[i+y] = fixdot[index + y];

				}
				answer[y+i] = '.';
				f = y+i+1;
				int j = i+1;
				index1 = j;
				for (j; j < lenth; j++) {
					if (isdigit(fixdot[j])) {
						
						
						m++;
					}
					else {
						break;
					}
				}
				for (w= 0; w < m; w++) {
					answer[f+w] = fixdot[index1 + w];

				}
				
			}

		}
		int l = 0;
		
		for (int t = 0; t < f+w; t++) {
			cout << answer[t];
	}
	
	return 0;
}