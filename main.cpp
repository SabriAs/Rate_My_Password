#include <iostream>
using namespace std;
int PWRating(char pw[]);

void main(){
	int ranking = 0, best_cnt = 0, good_cnt = 0, weak_cnt = 0, poor_cnt = 0, unaccept_cnt = 0;
	char ynResp[100];
	char pw[100];
	int pwcnt = 0;

	do{
		cout << "Would you like to evaluate the quality of a password? (Y/N) ";
		cin >> ynResp;
		while (ynResp[0] != 'y' && ynResp[0] != 'Y' && ynResp[0] != 'n' && ynResp[0] != 'N' || strlen(ynResp) != 1){
			cout << "Invalid response, please enter \"Y\" or \"N\": ";
			cin >> ynResp;}

		if (ynResp[0] == 'y' || ynResp[0] == 'Y'){
			cout << "Enter a password:";
			cin >> pw;
			ranking = PWRating(pw);

			if (ranking == 5){
				cout << "Password:" << pw << "\t\t\tRating:" << "Best(5)\n";
				best_cnt++;}

			else if (ranking == 4){
					cout << "Password:" << pw << "\t\t\tRating:" << "Good(4)\n";
					good_cnt++;}

			else if (ranking == 3){
					cout << "Password:" << pw << "\t\t\tRating:" << "Weak(3)\n";
					weak_cnt++;}

			else if (ranking == 2){
					cout << "Password:" << pw << "\t\t\tRating:" << "Poor(2)\n";
					poor_cnt++;}
			
			else if (ranking == 1){
				cout << "Password:" << pw << "\tRating:" << "Unacceptable(1)\n";
				unaccept_cnt++;}}

	} while (ynResp[0] == 'y' || ynResp[0] == 'Y');
	cout << "\n";

	cout << "Total number of passwords for each rating are:\n"
		<< "Best:" << best_cnt << '\n'
		<< "Good:" << good_cnt << '\n'
		<< "Weak:" << weak_cnt << '\n'
		<< "Poor:" << poor_cnt << '\n'
		<< "Unacceptable:" << unaccept_cnt << '\n';}

int PWRating(char pw[]){
	int criteria = 0;
	int upper_test = 0, lower_test = 0, digit_test = 0, nonalpha_test = 0;

	if (strlen(pw) >= 8)
		criteria++;

	for (int i = 0; i < strlen(pw); i++)

		if (pw[i] >= 'A' && pw[i] <= 'Z')
			upper_test++;
		else if (pw[i] >= 'a' && pw[i] <= 'z')
			lower_test++;
		else if (pw[i] >= char(48) && pw[i] <= char(57))
			digit_test++;
		else if ((pw[i] >= char(32) && pw[i] <= char(47)) || 
			(pw[i] >= char(58) && pw[i] <= char(64)) || (pw[i] >= char(91) && pw[i] <= 
				char(96)) || (pw[i] >= char(123) && pw[i] <= char(126)))
			nonalpha_test++;

	if (upper_test != 0)
		criteria++;

	if (lower_test != 0)
		criteria++;

	if (digit_test != 0)
		criteria++;

	if (nonalpha_test != 0)
		criteria++;

	return criteria;
}