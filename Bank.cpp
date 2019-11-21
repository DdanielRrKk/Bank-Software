#include<iostream>
#include<string>

#include"Login.h"

using namespace std;


void menu();
//=====================CLASS CBANK=================

class Cbank {
public:

	int id;
	double balance;
	int type;
	string name;

public:
	Cbank() {
		id = 0;
		balance = 0.0;
		type = 0;
		name = " ";
	}

	Cbank(double dval, int ival, string sval) {
		balance = dval;
		type = ival;
		name = sval;
	}

	void setID(int ival) {
		id = ival;
	}

	void setBalance(double dval) {
		balance = dval;
	}

	void setType(int ival) {
		type = ival;
	}

	void setName(string sval) {
		name = sval;
	}

	int getID() {
		return id;
	}

	double getBalance() {
		return balance;
	}

	int getType() {
		return type;
	}

	string getName() {
		return name;
	}
	
};

void reorder(int n, Cbank* obj);
void checkAcc(int n, Cbank* obj);
void createAcc(int n, Cbank* obj, Cuser *user);
void depositMoney(int n, Cbank* obj);
void withdrawMoney(int n, Cbank* obj);
void accShow(int n, Cbank* obj);
void allAccShow(int n, Cbank* obj);
void closeAcc(int n, Cbank* obj);
void modifyAcc(int n, Cbank* obj);

//==================FUNCTONS===========

void reorder(int n, Cbank *obj) {
	for (int i = 0; i < n+1; i++) {
		if (obj[i].name == " ") {
			obj[i].name = obj[i + 1].name;
			obj[i].type = obj[i + 1].type;
			obj[i].name = obj[i + 1].name;
			obj[i].balance = obj[i + 1].balance;
		}
	}
}

//void checkAcc(int n, Cbank *obj) {
//	system("cls");
//	int ich;
//	string sch;
//	cout << "Enter your name: ";
//	cin >> sch;
//	cout << endl << "Enter your id: ";
//	cin >> ich;
//	
//	if (obj[ich].name == sch) {
		/*if (n == 1) {
			depositMoney(ich, obj);
		}
		else if (n == 2) {
			withdrawMoney(ich, obj);
		}
		else {
			accShow(ich, obj);
		}*/
//	}
//	else {
//		cout << endl << endl << "Incorrect name or id. Do you want to try again? <1. Yes / 2. No>" << endl << endl;
//		int choice;
//		cin >> choice;
//		if (choice == 1) {
//			checkAcc(n, obj);
//		}
//		else {
//			menu();
//		}
//		system("pause");
//	}
//}

void createAcc(int n, Cbank *obj, Cuser *user) {
	system("cls");
	reg(user, n);
	int ival;
	double dval;
	string sval;
	cout << endl << "Enter your name: ";
	cin >> sval;
	do {
		cout << endl << "Enter the type of your account (1. Savings / 2. Current): ";
		cin >> ival;
	} while (ival < 1 || ival > 2);
	cout << endl << "Enter how much money you will deposit: ";
	cin >> dval;
	obj[n].setName(sval);
	obj[n].setBalance(dval);
	obj[n].setType(ival);
	obj[n].setID(n);
}

void depositMoney(int n, Cbank *obj) {
	system("cls");
	double money;
	cout << "Name: " << obj[n].name;
	cout << endl << "You have " << obj[n].balance << " dolars in your account." << endl;
	cout << "Enter how much money you will deposit: ";
	cin >> money;
	obj[n].balance = obj[n].balance + money;
}

void withdrawMoney(int n, Cbank *obj) {
	system("cls");
	double money;
	int ich;
	cout << "Name: " << obj[n].name;
	cout << endl << "You have " << obj[n].balance << " dolars in your account." << endl;
	cout << "Enter how much money you want to withdraw: ";
	cin >> money;
	if (obj[n].balance > money) {
		obj[n].balance = obj[n].balance - money;
	}
	else {
		cout << endl << endl << "You dont have enough money. Do you want to continue? (1. Yes/ 2. No): ";
		cin >> ich;
		if (ich == 1) {
			withdrawMoney(n, obj);
		}
		else {
			menu();
		}
	}
}

void accShow(int n, Cbank *obj) {
	system("cls");
	cout << "=================================" << endl;
	cout << "ID: " << obj[n].id;
	cout << endl << "Name: " << obj[n].name;
	cout << endl << "Type: ";
	if (obj[n].type == 1) {
		cout << "Savings Account";
	}
	else {
		cout << "Current Account";
	}
	cout << endl << "Balance: " << obj[n].balance;
	cout << endl << "=================================" << endl;
	system("pause");
}

void allAccShow(int n, Cbank *obj) {
	system("cls");
	cout << "========================================" << endl;
	cout << "===============ALL=ACCOUNTS=============" << endl;
	cout << "========================================" << endl << endl;
	for (int i = 0; i < n; i++) {
		cout << "ID: " << obj[i].id;
		cout << endl << "Name: " << obj[i].name;
		cout << endl << "Type: ";
		if (obj[i].type == 1) {
			cout << "Savings Account";
		}
		else {
			cout << "Current Account";
		}
		cout << endl << "Balance: " << obj[i].balance;
		cout << endl << "========================================" << endl;
	}
	system("pause");
}

void closeAcc(int n, Cbank *obj) {
	system("cls");
	int ich, choice;
	string sch, objname;
	cout << "Enter your name: ";
	cin >> sch;
	cout << endl << "Enter your id: ";
	cin >> ich;

	objname = obj[ich].name;
	if (objname == sch) {
		cout << endl << "Do you realy wnat to close this account? (1. Yes/ 2. No): ";
		cin >> choice;
		if (choice == 1) {
			obj[ich].name = " ";
			obj[ich].type = 0;
			obj[ich].balance = 0.0;
			obj[ich].id = 0;
			reorder(n, obj);
		}
		else {
			menu();
		}
	}
	else {
		cout << endl << endl << "Incorrect name or id. Press an key to try again." << endl << endl;
		system("pause");
		closeAcc(ich, obj);
	}
}

void modifyAcc(int n, Cbank *obj) {
	system("cls");
	int ich, choice;
	string sch, objname;
	cout << "Enter your name: ";
	cin >> sch;
	cout << endl << "Enter your id: ";
	cin >> ich;

	objname = obj[ich].name;
	if (objname == sch) {
		system("cls");
		cout << endl << "What do you want to change in your account? (1. Name /2. Type): ";
		cin >> choice;
		if (choice == 1) {
			string newname;
			cout << endl << "Your curent name is: " << obj[ich].name;
			cout << "What is your new name: ";
			cin >> newname;
			obj[ich].setName(newname);
			cout << "Your name has changed to: " << obj[ich].name;
		}
		else {
			int newtype;
			cout << endl << obj[ich].name << " your curent type is: ";
			if (obj[ich].type == 1) {
				cout << "Savings Account";
			}
			else {
				cout << "Current Account";
			}
			cout << "To what type you want to change your account: ";
			cin >> newtype;
			obj[ich].setType(newtype);
			cout << "Your account type has changed to: ";
			if (obj[ich].type == 1) {
				cout << "Savings Account";
			}
			else {
				cout << "Current Account";
			}
		}
	}
	else {
		cout << endl << endl << "Incorrect name or id. Press an key to try again." << endl << endl;
		system("pause");
		closeAcc(ich, obj);
	}
}

//=========================MENU================

int main() {
	menu();
	return 0;
}

void menu() {

	Cbank obj[50];
	Cuser user[50];
	int num = 0;

	int choice;
	do{
		do {
			system("cls");
			cout << "          =============================" << endl;
			cout << "             BANK MANAGEMENT SYSTEM" << endl;
			cout << "          =============================" << endl;
			cout << "                    ::MENU::" << endl;
			cout << endl;
			cout << "             1. NEW ACCOUNT" << endl;
			cout << "             2. DEPOSIT AMOUNT" << endl;
			cout << "             3. WITHDRAW AMOUNT" << endl;
			cout << "             4. BALANCE ENQUIRY" << endl;
			cout << "             5. ALL ACCOUNT HOLDER LIST" << endl;
			cout << "             6. CLOSE AN ACCOUNT" << endl;
			cout << "             7. MODIFY AN ACCOUNT" << endl;
			cout << "             8. Exit" << endl;
			cout << endl;
			cout << "             Select Your Option (1 - 8): ";
			cin >> choice;
		} while (choice < 1 || choice > 8);
		switch (choice) {
		case 1: 
			createAcc(num, obj, user);
			num++;
			break;

		case 2: 
			log(user, num, 1, obj);
			break;

		case 3: 
			log(user, num, 2, obj);
			break;

		case 4: 
			log(user, num, 3, obj);
			break;

		case 5: 
			allAccShow(num, obj);
			break;

		case 6: 
			closeAcc(num, obj);
			break;

		case 7: 
			modifyAcc(num, obj);
			break;

		default: 
			system("cls");
			cout << endl << "         =================================";
			cout << endl << "         ==============EXITING============";
			cout << endl << "         =================================" << endl;
		}
	} while (choice != 8);
}
