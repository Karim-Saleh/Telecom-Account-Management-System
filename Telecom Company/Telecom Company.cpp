#include <iostream>
#include <string>
using namespace std;
int user_index = -1;
string numbers[10] = { "9025263916",
"9099341028","9082502705","9056735867",
"9063122021","9031667876","9008424632",
"9014581206","9077936031","9040191212" };
struct Card
{
	string serial_number[10] = { "31647308109266","64899102314571",
		"71433610542298","23369415022879","10094605144397","66054139657012",
		"51339624610831","44574104042396","29762775400361","77160894122913" };
	int value[10] = { 50,100,20,25,10,50,20,100,25,10 };
}cards;
struct Line {
	string mobile_number, package_type = { "Standard" }, start_date = { "28/07/2020" }, renwal_date = { "28/08/2020" };
	float balance = 100.00;
	bool exist = 0;
};
struct Information
{
	string ID, Email, name, password, address;
	Line lines[3];
	bool exist = 0;
}user[100];

//....Functions....//
void SignUp();
int SignIn();
int ChooseLineNumber();
int TransString(string s);
void GetLine();
void Recharge();
void TranferBalance();
void Packages();
void CallOrMessage();
void AccountInformation();
//.................//

int main()
{
	int chosen;
	string choice, any_key;
	while (1)
	{
		while (1)
		{
			cout << "Main Menu\n\n";
			if (user_index != -1)
			{
				cout << "Welcome " << user[user_index].name << "\n\n";
			}
			cout << "1-Sign up\n2-Sign in\n3-Get a line number\n4-Packages\n"
				<< "5-Recharge balance\n6-Tranfer balance\n7-Make a call or send a message\n"
				<< "8-Show account information\n9-Sign out\n0-Exit\n";
			getline(cin, choice);
			chosen = TransString(choice);
			if (chosen == 1)
			{
				if (user_index == -1)
				{
					system("cls");
					SignUp();
				}
				else
				{
					system("cls");
					cout << "You Have to sign out first\n";
					cout << "Enter any key to go to Main menu\n";
					getline(cin, any_key);
					system("cls");
				}
			}
			else if (chosen == 2)
			{
				if (user_index == -1)
				{
					system("cls");
					user_index = SignIn();
				}
				else
				{
					system("cls");
					cout << "You Have to sign out first\n";
					cout << "Enter any key to go to Main menu\n";
					getline(cin, any_key);
					system("cls");
				}
			}
			else
			{
				////////if the user didn`t sign in///////
				if (user_index == -1)
				{
					if (chosen > 2 && chosen < 10)
					{
						system("cls");
						cout << "You Have to sign in first\n";
						cout << "Enter any key to go to Main menu\n";
						getline(cin, any_key);
						system("cls");
					}
					else if (chosen == 0)
					{
						return 0;
					}
					else
					{
						system("cls");
						cout << "Wrong choice\nEnter any key to go to Main menu\n";
						getline(cin, any_key);
						system("cls");
					}
				}
				/////////if the user signed in/////////
				else
				{
					if (chosen == 3)
					{
						system("cls");
						GetLine();
					}
					else if (chosen == 4)
					{
						system("cls");
						Packages();
					}
					else if (chosen == 5)
					{
						system("cls");
						Recharge();
					}
					else if (chosen == 6)
					{
						system("cls");
						TranferBalance();
					}
					else if (chosen == 7)
					{
						system("cls");
						CallOrMessage();
					}
					else if (chosen == 8)
					{
						system("cls");
						AccountInformation();
					}
					else if (chosen == 9)
					{
						system("cls");
						user_index = -1;
					}
					else if (chosen == 0)
					{
						return 0;
					}
					else
					{
						system("cls");
						cout << "Wrong choice\nEnter any key to go to Main menu\n";
						getline(cin, any_key);
						system("cls");
						break;
					}
				}
			}
		}
	}
	return 0;
}

void SignUp()
{
	cout << "Signing up\n\n";
	int index;

	//.........search for an empty element in the array........//
	for (int i = 0; i < 100; i++)
	{
		if (user[i].exist == 0)
		{
			index = i;
			user[index].exist = 1;
			break;
		}
	}
	//.........................................................//

	cout << "Enter your name\n";
	getline(cin, user[index].name);
	cout << "Enter your e-mail\n";
	getline(cin, user[index].Email);
	cout << "Enter your adress\n";
	getline(cin, user[index].address);
	cout << "Enter your ID\n";
	getline(cin, user[index].ID);
	cout << "Enter your password\n";
	getline(cin, user[index].password);
	system("cls");
}
int SignIn()
{
	bool wrong_choice = 0;
	string ID, password;
	cout << "Signing in \n\n" << "0-Main menu\n" << "\nEnter your ID\n";
	getline(cin, ID);
	if (ID == "0")
	{
		system("cls");
		return -1;
	}
	cout << "Enter your password\n";
	getline(cin, password);
	if (password == "0")
	{
		system("cls");
		return -1;
	}
	system("cls");
	for (int i = 0; i < 100; i++)
	{
		if (user[i].exist == 0)
		{
			if (wrong_choice == 0)
			{
				string choice;
				cout << "Signing in \n\n";
				cout << "Incorrect password or ID\n";
				cout << "If you don't have an account return to the main menu and sign up\n";
				cout << "\n0-Main menu\n1-Continue\n";
				getline(cin, choice);
				system("cls");
				if (choice == "1")
				{
					cout << "Signing in \n\n";
					cout << "Enter your ID\n";
					getline(cin, ID);
					cout << "\nEnter your password\n";
					getline(cin, password);
					system("cls");
					i = -1;
				}
				else if (choice == "0")
					return -1;
				else
				{
					wrong_choice = 1;
					i--;
				}
				continue;
			}
			else
			{
				string choice;
				cout << "Signing in \n\n";
				cout << "Wrong choice\n";
				cout << "\n0-Main menu\n1-Continue\n";
				getline(cin, choice);
				system("cls");
				if (choice == "1")
				{
					cout << "Signing in \n\n";
					cout << "Enter your ID\n";
					getline(cin, ID);
					cout << "\nEnter your password\n";
					getline(cin, password);
					system("cls");
					i = -1;
					wrong_choice = 0;
				}
				else if (choice == "0")
				{
					return -1;
				}
				else
					i--;
				continue;
			}
		}
		else if (user[i].ID == ID && user[i].password == password)
		{
			user_index = i;
			return user_index;
			break;
		}
	}
}
int ChooseLineNumber()
{
	int line_index;
	int chosen;
	bool wrong_choice = 1;
	string choice;
	while (1)
	{
		if (wrong_choice)
		{
			while (1)
			{
				cout << "Choose the mobile number you want\n\n0-Main Menu\n";
				for (int i = 0; i < 3; i++)
				{
					if (user[user_index].lines[i].exist)
					{
						cout << i + 1 << "- " << user[user_index].lines[i].mobile_number << "\n";
					}
				}
				getline(cin, choice);
				chosen = TransString(choice);
				if (1 == chosen)
				{
					line_index = 0;
					break;
				}
				if (2 == chosen)
				{
					line_index = 1;
					break;
				}
				if (3 == chosen)
				{
					line_index = 2;
					break;
				}
				else if (0 == chosen)
				{
					return -1;
				}
				else
				{
					system("cls");
					cout << "Wrong choice\n";
				}
			}

		}
		else
		{
			system("cls");
			break;
		}
		if (line_index < 3 && line_index > -1 && user[user_index].lines[line_index].exist)
		{
			wrong_choice = 0;
		}
		else
		{
			system("cls");
			cout << "Wrong choice\n";
			wrong_choice = 1;
		}
	}
	return line_index;
}
//it Transfers string numbers to integer and if there is a character or it is empty it returns -1
int TransString(string s)
{
	int total = 0, multiple = 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '0')
		{
			total += multiple * 0;
			multiple *= 10;
		}
		else if (s[i] == '1')
		{
			total += multiple * 1;
			multiple *= 10;
		}
		else if (s[i] == '2')
		{
			total += multiple * 2;
			multiple *= 10;
		}
		else if (s[i] == '3')
		{
			total += multiple * 3;
			multiple *= 10;
		}
		else if (s[i] == '4')
		{
			total += multiple * 4;
			multiple *= 10;
		}
		else if (s[i] == '5')
		{
			total += multiple * 5;
			multiple *= 10;
		}
		else if (s[i] == '6')
		{
			total += multiple * 6;
			multiple *= 10;
		}
		else if (s[i] == '7')
		{
			total += multiple * 7;
			multiple *= 10;
		}
		else if (s[i] == '8')
		{
			total += multiple * 8;
			multiple *= 10;
		}
		else if (s[i] == '9')
		{
			total += multiple * 9;
			multiple *= 10;
		}
		else
		{
			return -1;
		}
	}
	if (s.size() == 0)
		return -1;
	else
		return total;
}
//..............................................//
void GetLine()
{
	int line_index, counter = 0, chosen;
	string shift[10], any_key, choice;
	bool maximum = 1, wrong_choice = 0;
	////////check how many lines do you have/////////
	for (int i = 0; i < 3; i++)
	{
		if (user[user_index].lines[i].exist == 0)
		{
			line_index = i;
			maximum = 0;
			break;
		}
	}
	/////////if you have 3 numbers/////////
	if (maximum)
	{
		cout << "Sorry you cannot have more than 3 lines\n"
			<< "Enter any key to go to Main Menu\n";
		getline(cin, any_key);
	}
	////////if you have less than 3 numbers/////////
	else
	{
		cout << "Choose a mobile number\n\n";
		for (int i = 0; i < 10; i++)
		{
			if (numbers[i].empty())
			{
				continue;
			}
			else
				cout << ++counter << "-  " << numbers[i] << "\n\n";
		}
		cout << "Or\n\n0-Main menu\n";
		getline(cin, choice);
		chosen = TransString(choice);
		while (1)
		{
			if (choice == "0")
			{
				break;
			}
			if (wrong_choice)
			{
				system("cls");
				cout << "Wrong choice\n\nAre you sure you want this number(" << numbers[chosen - 1]
					<< ")\n" << "1-Yes\n" << "2-No\n" << "0-Main menu\n";
				getline(cin, choice);
				if (choice == "1")
				{
					swap(numbers[chosen - 1], user[user_index].lines[line_index].mobile_number);
					cout << "You got The number "
						<< user[user_index].lines[line_index].mobile_number
						<< ".\nEnter any key to Go to Main Menu\n";
					user[user_index].lines[line_index].exist = 1;
					getline(cin, any_key);
					break;
				}
				else if (choice == "0")
				{
					break;
				}
				else if (choice == "2")
				{
					wrong_choice = 0;
					counter = 0;
					system("cls");
					cout << "Choose a mobile number\n\n";
					for (int i = 0; i < 10; i++)
					{
						if (numbers[i].empty())
						{
							continue;
						}
						else
							cout << ++counter << "-  " << numbers[i] << "\n\n";
					}
					cout << "Or\n\n0-Main menu\n";
					getline(cin, choice);
					chosen = TransString(choice);
				}
			}
			else
			{
				if (chosen <= counter && chosen > 0)
				{
					system("cls");
					cout << "Are you sure you want this number(" << numbers[chosen - 1] << ")\n"
						<< "1-Yes\n" << "2-No\n" << "0-Main menu\n";
					getline(cin, choice);
					if (choice == "1")
					{
						swap(numbers[chosen - 1], user[user_index].lines[line_index].mobile_number);
						cout << "You got The number "
							<< user[user_index].lines[line_index].mobile_number
							<< ".\nEnter any key to Go to Main Menu\n";
						user[user_index].lines[line_index].exist = 1;
						getline(cin, any_key);
						break;
					}
					else if (choice == "0")
					{
						break;
					}
					else if (choice == "2")
					{
						system("cls");
						counter = 0;
						cout << "Choose a mobile number\n\n";
						for (int i = 0; i < 10; i++)
						{
							if (numbers[i].empty())
							{
								continue;
							}
							else
								cout << ++counter << "-  " << numbers[i] << "\n\n";
						}
						cout << "Or\n\n0-Main menu\n";
						getline(cin, choice);
						chosen = TransString(choice);
					}
					else
					{
						wrong_choice = 1;
					}

				}
				else
				{
					system("cls");
					cout << "Wrong choice\n" << "Choose a mobile number\n\n";
					counter = 0;
					for (int i = 0; i < 10; i++)
					{
						if (numbers[i].empty())
						{
							continue;
						}
						else
							cout << ++counter << "-  " << numbers[i] << "\n\n";
					}
					cout << "Or\n\n0-Main menu\n";
					getline(cin, choice);
					chosen = TransString(choice);
				}
			}
		}
		counter = -1;
		for (int i = 0; i < 10; i++)
		{
			if (numbers[i].empty() == 0)
			{
				shift[++counter] = numbers[i];
			}
		}
		for (int i = 0; i < 10; i++)
		{
			numbers[i] = shift[i];
		}
	}
	system("cls");
}
void Recharge()
{
	bool invalid = 1, wrong_choice = 1;
	int value_index, line_index;
	string serial_number;
	if (user[user_index].lines[0].exist)
	{
		////////choose the mobile number you want to charge/////////
		line_index = ChooseLineNumber();
		//........................................................//
		if (line_index != -1)
		{
			////////check the card serial number////////
			cout << "Enter the card serial number\nOr\n0-Main Menu\n";
			getline(cin, serial_number);
			if (serial_number != "0")
			{
				while (1)
				{
					if (invalid == 0)
					{
						user[user_index].lines[line_index].balance += cards.value[value_index];
						system("cls");
						cout << "Your balance have been charged successfully. Your new balance is: "
							<< user[user_index].lines[line_index].balance << " LE\n\n"
							<< "Enter any key to go to Main Menu\n";
						getline(cin, serial_number);
						wrong_choice = 0;
						break;
					}
					for (int i = 0; i < 10; i++)
					{
						invalid = 1;
						if (serial_number == cards.serial_number[i])
						{
							value_index = i;
							invalid = 0;
							break;
						}
						if (i == 9 && invalid)
						{
							system("cls");
							cout << "Invalid card serial number\n";
							cout << "Re-enter a valid card serial number\nOr\n0-Main Menu\n";
							getline(cin, serial_number);
						}
					}
					if (serial_number == "0")
					{
						break;
					}
				}
			}
		}
	}
	else
	{
		cout << "You need to get a line number first\n"
			<< "Enter any key to go to Main Menu\n";
		getline(cin, serial_number);
	}
	system("cls");
}
void TranferBalance()
{
	string number, any_key, choice;
	int line_index;
	float value;
	bool wrong_choice = 1, transferred = 0, Main_Menu = 0;
	if (user[user_index].lines[0].exist)
	{
		/////////check the line number we will transfer from///////
		line_index = ChooseLineNumber();
		if (line_index != -1)
		{
			wrong_choice = 1;
			/////////check the value of money///////
			while (1)
			{
				if (wrong_choice)
				{
					cout << "Enter the value of money you want to transfer.\nOr\n0-Main Menu\n";
					cin >> value;
					if (value == 0)
					{
						Main_Menu = 1;
						break;
					}
					if (value <= user[user_index].lines[line_index].balance && value > 0)
					{
						wrong_choice = 0;
					}
					else
					{
						if (user[user_index].lines[line_index].balance == 0)
						{
							system("cls");
							cout << "Sorry, you don`t have enough money.\n"
								<< "Enter any key to Continue.\n";
							getline(cin, any_key);
							Main_Menu = 1;
							break;
						}
						else
						{
							system("cls");
							cout << "Sorry, you don`t have enough money but you still have "
								<< user[user_index].lines[line_index].balance << " LE.\n";
						}
					}
				}
				else
				{
					system("cls");
					break;
				}
			}

			wrong_choice = 1;
			getline(cin, any_key);
			/////////check the line number we will transfer to///////
			if (Main_Menu == 0)
			{
				while (1)
				{
					if (wrong_choice)
					{
						cout << "Enter the number you want to transfer balance to.\n";
						getline(cin, number);
					}
					else
						break;
					for (int i = 0; i < 100; i++)
					{
						if (user[i].exist == 0)
						{
							system("cls");
							cout << "Invalid number or dosen`t exist\n"
								<< "please Enter a valid number\n";
							break;
						}
						if (number == user[user_index].lines[line_index].mobile_number)
						{
							system("cls");
							cout << "You cannot transfer balance between the same number\n";
							break;
						}
						else
						{
							for (int j = 0; j < 3; j++)
							{
								if (user[i].lines[j].exist == 0)
								{
									break;

								}
								else if (user[i].lines[j].mobile_number == number)
								{
									user[i].lines[j].balance += value;
									user[user_index].lines[line_index].balance -= value;
									cout << "The balance is successfully transfered.\n"
										<< "Your new balance is "
										<< user[user_index].lines[line_index].balance
										<< " LE\n";
									cout << "Enter any key to go to Main Menu\n";
									getline(cin, number);
									wrong_choice = 0;
									transferred = 1;
									break;
								}

							}
						}
						if (transferred)
							break;
					}
				}
			}
		}
	}
	else
	{
		cout << "You need to get a line number first\n"
			<< "Enter any key to go to Main Menu\n";
		getline(cin, number);
	}
	system("cls");
}
void Packages()
{
	int line_index, chosen;
	bool wrong_choice = 1, main_menu = 0, renew = 0, change = 0;
	string choice;

	//.........if the user already have at least a line number.........//
	if (user[user_index].lines[0].exist)
	{
		/////////choose the line number we will renew its package type///////
		line_index = ChooseLineNumber();
		//................................................................//

		if (line_index != -1)
		{

			/////////choose renew or change//////
			while (1)
			{
				if (wrong_choice)
				{
					cout << "0-Main Menu\n1-Renew your package type\n2-Change your package type\n";
					getline(cin, choice);
					if (choice == "1")
					{
						renew = 1;
						wrong_choice = 0;
					}
					else if (choice == "2")
					{
						change = 1;
						wrong_choice = 0;
					}
					else if (choice == "0")
					{
						main_menu = 1;
						wrong_choice = 0;
					}
					else
					{
						system("cls");
						cout << "Wrong choice\n";
					}
				}
				else
					break;
			}
			//.................................//

			wrong_choice = 1;

			/////////change the package type/////
			if (change)
			{
				system("cls");
				while (1)
				{
					if (wrong_choice)
					{
						cout << "0-Main Menu\n1-Standard\n2-Internet\n3-Flexat\n4-Dlofen\n5-Fox\n";
						getline(cin, choice);
						chosen = TransString(choice);
						if (chosen == 1)
						{
							if (user[user_index].lines[line_index].package_type == "Standard")
							{
								system("cls");
								while (1)
								{
									cout << "You are already on this package, please choose another package type.\n\n"
										<< "0-Main Menu\n1-Continue\n";
									getline(cin, choice);
									chosen = TransString(choice);
									if (chosen == 0)
									{
										main_menu = 1;
										wrong_choice = 0;
										break;
									}
									else if (chosen == 1)
									{
										system("cls");
										break;
									}
									else
									{
										system("cls");
										cout << "Wrong Choice\n";
									}
								}
							}
							else
							{
								system("cls");
								cout << "You have successfully changed your package type ("
									<< user[user_index].lines[line_index].package_type << ")" << " to (";
								user[user_index].lines[line_index].package_type = { "Standard" };
								user[user_index].lines[line_index].renwal_date = { "02/09/2020" };
								cout << user[user_index].lines[line_index].package_type
									<< ")\nYour renewal date is "
									<< user[user_index].lines[line_index].renwal_date << "\n";
								wrong_choice = 0;
							}
						}
						else if (chosen == 2)
						{
							if (user[user_index].lines[line_index].package_type == "Internet")
							{
								system("cls");
								while (1)
								{
									cout << "You are already on this package, please choose another package type.\n\n"
										<< "0-Main Menu\n1-Continue\n";
									getline(cin, choice);
									chosen = TransString(choice);
									if (chosen == 0)
									{
										main_menu = 1;
										wrong_choice = 0;
										break;
									}
									else if (chosen == 1)
									{
										system("cls");
										break;
									}
									else
									{
										system("cls");
										cout << "Wrong Choice\n";
									}
								}
							}
							else
							{
								system("cls");
								cout << "You have successfully changed your package type ("
									<< user[user_index].lines[line_index].package_type << ")" << " to (";
								user[user_index].lines[line_index].package_type = { "Internet" };
								user[user_index].lines[line_index].renwal_date = { "02/07/2020" };
								cout << user[user_index].lines[line_index].package_type
									<< ")\nYour renewal date is "
									<< user[user_index].lines[line_index].renwal_date << "\n";
								wrong_choice = 0;
							}
						}
						else if (chosen == 3)
						{
							if (user[user_index].lines[line_index].package_type == "Flexat")
							{
								system("cls");
								while (1)
								{
									cout << "You are already on this package, please choose another package type.\n\n"
										<< "0-Main Menu\n1-Continue\n";
									getline(cin, choice);
									chosen = TransString(choice);
									if (chosen == 0)
									{
										main_menu = 1;
										wrong_choice = 0;
										break;
									}
									else if (chosen == 1)
									{
										system("cls");
										break;
									}
									else
									{
										system("cls");
										cout << "Wrong Choice\n";
									}
								}
							}
							else
							{
								system("cls");
								cout << "You have successfully changed your package type ("
									<< user[user_index].lines[line_index].package_type << ")" << " to (";
								user[user_index].lines[line_index].package_type = { "Flexat" };
								user[user_index].lines[line_index].renwal_date = { "02/07/2020" };
								cout << user[user_index].lines[line_index].package_type
									<< ")\nYour renewal date is "
									<< user[user_index].lines[line_index].renwal_date << "\n";
								wrong_choice = 0;
							}
						}
						else if (chosen == 4)
						{
							if (user[user_index].lines[line_index].package_type == "Dlofen")
							{
								system("cls");
								while (1)
								{
									cout << "You are already on this package, please choose another package type.\n\n"
										<< "0-Main Menu\n1-Continue\n";
									getline(cin, choice);
									chosen = TransString(choice);
									if (chosen == 0)
									{
										main_menu = 1;
										wrong_choice = 0;
										break;
									}
									else if (chosen == 1)
									{
										system("cls");
										break;
									}
									else
									{
										system("cls");
										cout << "Wrong Choice\n";
									}
								}
							}
							else
							{
								system("cls");
								cout << "You have successfully changed your package type ("
									<< user[user_index].lines[line_index].package_type << ")" << " to (";
								user[user_index].lines[line_index].package_type = { "Dlofen" };
								user[user_index].lines[line_index].renwal_date = { "02/07/2020" };
								cout << user[user_index].lines[line_index].package_type
									<< ")\nYour renewal date is "
									<< user[user_index].lines[line_index].renwal_date << "\n";
								wrong_choice = 0;
							}
						}
						else if (chosen == 5)
						{
							if (user[user_index].lines[line_index].package_type == "Fox")
							{
								system("cls");
								while (1)
								{
									cout << "You are already on this package, please choose another package type.\n\n"
										<< "0-Main Menu\n1-Continue\n";
									getline(cin, choice);
									chosen = TransString(choice);
									if (chosen == 0)
									{
										main_menu = 1;
										wrong_choice = 0;
										break;
									}
									else if (chosen == 1)
									{
										system("cls");
										break;
									}
									else
									{
										system("cls");
										cout << "Wrong Choice\n";
									}
								}
							}
							else
							{
								system("cls");
								cout << "You have successfully changed your package type ("
									<< user[user_index].lines[line_index].package_type << ")" << " to (";
								user[user_index].lines[line_index].package_type = { "Fox" };
								user[user_index].lines[line_index].renwal_date = { "02/07/2020" };
								cout << user[user_index].lines[line_index].package_type
									<< ")\nYour renewal date is "
									<< user[user_index].lines[line_index].renwal_date << "\n";
								wrong_choice = 0;
							}
						}
						else if (chosen == 0)
						{
							main_menu = 1;
							change = 0;
							break;
						}
						else
						{
							system("cls");
							cout << "Wrong choice\n";
						}
					}
					else
						break;
				}
			}
			//.................................//

			wrong_choice = 1;

			/////////renew the package type/////
			if (renew)
			{
				system("cls");
				user[user_index].lines[line_index].renwal_date = { "28/08/2020" };
				cout << "You have successfully renewed your package type ("
					<< user[user_index].lines[line_index].package_type << ")\nYour renewal date is "
					<< user[user_index].lines[line_index].renwal_date << "\n";
			}
			//...............................//

			if (main_menu == 0)
			{
				cout << "Enter any key to go to Main Menu\n";
				getline(cin, choice);
			}
			system("cls");
		}
		else
		{
			system("cls");
		}
	}
	//.................................................................//

	else
	{
		cout << "You need to get a line number first\n"
			<< "Enter any key to go to Main Menu\n";
		getline(cin, choice);
		system("cls");
	}
}
void CallOrMessage()
{
	int line_index;
	bool wrong_choice = 1;
	string any_key, choice;
	if (user[user_index].lines[0].exist)
	{
		/////////choose the line number you will call or send a message from///////
		line_index = ChooseLineNumber();
		if (line_index != -1)
		{
			if (user[user_index].lines[line_index].balance > 0)
			{
				//.......choose call or message........//
				while (1)
				{
					if (wrong_choice)
					{
						cout << "Which process do you want?\n0-Main Menu\n1-Make a call\n2-Send a message\n";
						getline(cin, choice);
						if (choice == "0")
						{
							break;
						}
						else if (choice == "1")
						{
							user[user_index].lines[line_index].balance -= 0.25;
							cout << "Your call is done.\nYour new balance is "
								<< user[user_index].lines[line_index].balance << " LE\n"
								<< "Enter any key to go to Main Menu\n";
							getline(cin, any_key);
							wrong_choice = 0;
						}
						else if (choice == "2")
						{
							user[user_index].lines[line_index].balance -= 0.25;
							cout << "Your message is sent.\nYour new balance is "
								<< user[user_index].lines[line_index].balance << " LE\n"
								<< "Enter any key to go to Main Menu\n";
							getline(cin, any_key);
							wrong_choice = 0;
						}
						else
						{
							system("cls");
							cout << "Wrong choice\n";
						}

					}
					else
						break;
				}
				//.....................................//
			}
			else
			{
				cout << "Sorry, you don`t have enough balance to continue this process.\n\n"
					<< "Enter any key to continue.\n";
				getline(cin, any_key);
			}
		}
	}
	else
	{
		cout << "You need to get a line number first\n"
			<< "Enter any key to go to Main Menu\n";
		getline(cin, any_key);;
	}
	system("cls");
}
void AccountInformation()
{
	string any_key;
	cout << "Name:\n" << user[user_index].name << "\n\n";
	cout << "E-Mail:\n" << user[user_index].Email << "\n\n";
	cout << "ID:\n" << user[user_index].ID << "\n\n";
	cout << "Password:\n" << user[user_index].password << "\n\n";
	cout << "Address:\n" << user[user_index].address << "\n\n";
	if (user[user_index].lines[0].exist)
	{
		cout << "Lines numbers:\n";
		for (int i = 0; i < 3; i++)
		{
			if (user[user_index].lines[i].exist)
			{
				cout << i + 1 << "- " << user[user_index].lines[i].mobile_number << "\n";
			}
		}
	}
	else
	{
		cout << "Lines numbers:\nYou don`t have Lines\n";
	}
	cout << "Enter any key to go to Main Menu\n";
	getline(cin, any_key);
	system("cls");
}