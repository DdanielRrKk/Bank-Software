#include<iostream>
#include<string>

#include"Source.cpp"

using namespace std;

void Lmenu();

class Cuser {
	int id;
	string name;
	string pass;

public:

	Cuser() {
		id = 0;
		name = " ";
		pass = " ";
	}

	Cuser(string sval1, string sval2, int ival) {
		id = ival;
		name = sval1;
		pass = sval2;
	}

	void setName(string sval) {
		name = sval;
	}

	void setPass(string sval) {
		pass = sval;
	}

	void setID(int ival) {
		id = ival;
	}

	string getName() {
		return name;
	}

	string getPass() {
		return pass;
	}

	int getID() {
		return id;
	}

};


void reg(Cuser* user, int n);
bool checkName(Cuser* user, string s, int n);
bool checkPass(Cuser* user, string s, int n);
void log(Cuser *user, int n, int option, Cbank *obj);
void showAll(Cuser* user, int n);


void showAll(Cuser* user, int n) {
	system("cls");
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << "your name is " << user[i].getName() << endl;
		cout << "your pass is " << user[i].getPass() << endl;
		cout << "your id is " << user[i].getID() << endl;
		cout << endl;
	}
	system("pause");
}

void reg(Cuser* user, int n) {
	string uname;
	string upass;
	system("cls");

	cout << "Enter username: ";
	cin >> uname;

	bool flag = checkName(user, uname, n);
	while (flag == true) {
		cout << endl << "This name is already taken." << endl;
		cout << "Enter username: ";
		cin >> uname;
		flag = checkName(user, uname, n);
	}

	cout << endl << "Enter password: ";
	cin >> upass;

	user[n].setName(uname);
	user[n].setPass(upass);
	user[n].setID(n);
}

bool checkName(Cuser* user, string s, int n) {
	for (int i = 0; i < n; i++) {
		if (user[i].getName() == s) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool checkPass(Cuser* user, string s, int n) {
	for (int i = 0; i < n; i++) {
		if (user[i].getPass() == s) {
			return true;
		}
		else {
			return false;
		}
	}
}

void log(Cuser* user, int n, int option, Cbank* obj) {
	string unm;
	string ups;
	system("cls");

	cout << "Enter your username: ";
	cin >> unm;

	for (int i = 0; i < n; i++) {

		if (unm == user[i].getName()) {

			cout << endl << "Enter your password: ";
			cin >> ups;

			if (ups == user[i].getPass()) {
				cout << endl << endl << "Successfully logged" << endl;
				system("pause");
				if (option == 1) {
					depositMoney(n, obj);
				}
				else if (option == 2) {
					withdrawMoney(n, obj);
				}
				else {
					accShow(n, obj);
				}
				system("pause");
				menu();
			}

			else {
				bool flag = checkPass(user, ups, n);
				do {
					cout << endl << endl << "Wrong Password !" << endl << endl;
					cout << endl << "Enter your password: ";
					cin >> ups;
					flag = checkPass(user, ups, n);
				} while (flag == false);

				cout << endl << endl << "Successfully logged" << endl;
				system("pause");
				if (option == 1) {
					depositMoney(n, obj);
				}
				else if (option == 2) {
					withdrawMoney(n, obj);
				}
				else {
					accShow(n, obj);
				}
				system("pause");
				menu();
			}
		}

		else {
			bool flag = checkName(user, unm, n);
			do {
				cout << endl << endl << "Wrong Username !" << endl << endl;
				cout << "Enter your username: ";
				cin >> unm;
				flag = checkName(user, unm, n);
			} while (flag == false);

			cout << endl << "Enter your password: ";
			cin >> ups;

			if (ups == user[i].getPass()) {
				cout << endl << endl << "Successfully logged" << endl;
				system("pause");
				if (option == 1) {
					depositMoney(n, obj);
				}
				else if (option == 2) {
					withdrawMoney(n, obj);
				}
				else {
					accShow(n, obj);
				}
				system("pause");
				menu();
			}

			else {
				bool flag = checkPass(user, ups, n);
				do {
					cout << endl << endl << "Wrong Password !" << endl << endl;
					cout << endl << "Enter your password: ";
					cin >> ups;
					flag = checkPass(user, ups, n);
				} while (flag == false);

				cout << endl << endl << "Successfully logged" << endl;
				system("pause");
				if (option == 1) {
					depositMoney(n, obj);
				}
				else if (option == 2) {
					withdrawMoney(n, obj);
				}
				else {
					accShow(n, obj);
				}
				system("pause");
				menu();
			}
		}
	}
	system("pause");
}

//int main() {
//	Lmenu();
//	return 0;
//}
//
//void Lmenu() {
//
//	int choice;
//	Cuser user[50];
//	int n = 0;
//
//	do {
//		do {
//			system("cls");
//			cout << "===============MENU===============" << endl;
//			cout << "1. Log in" << endl;
//			cout << "2. Register" << endl;
//			cout << "3. Exit" << endl;
//			cout << "4. show all" << endl;
//			cout << endl;
//			cout << "Your choice: ";
//			cin >> choice;
//		} while (choice < 1 || choice > 4);
//		switch (choice) {
//		case 1:
//			log(user, n);
//			break;
//
//		case 2:
//			reg(user, n);
//			n++;
//			break;
//
//		case 4:
//			showAll(user, n);
//			break;
//
//		default:
//			system("cls");
//			cout << "=========GOODBYE=========" << endl;
//			return;
//		}
//	} while (choice != 3);
//
//}


