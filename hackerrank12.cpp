#include<bits/stdc++.h>

using namespace std;

int main() {
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year ;
	cin >> year;
	if (year < 1919) {
		if (year % 4 == 0) {
			months[1] = 29;
		}

	}
	else{
		if(year % 400 == 0 ){
			months[1] = 29;
		}
		else if( year % 100 !=0 && year % 4==0){
			months[1]=29;
		}
	}
	int days = 0;
	int month = 0;
	for (int i = 0; i < 12; ++i)
	{
		days += months[i];
		if (days >= 256 ) {
			month = i;
			days =  days - months[i];
			break ;
		}
	}
	int  m = month + 1;
	int md = 256 - days;
	if (year == 1918){
		cout << md+13 << "." << "0" << month + 1 << "." << year << endl;
		exit(0);
	}
	if (m < 10) {
		cout << md << "." << "0" << month + 1 << "." << year << endl;
	}
	else {
		cout << md << "." << month + 1 << "." << year << endl;
	}

}