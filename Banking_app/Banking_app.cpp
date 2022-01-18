#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include "Current.h"
#include "Saving.h"

//to comment a large chunk of code press ctrl + k , then ctrl + c
// to undo comments on a large chunk of code press ctrl + k , then ctrl + u


int main()
{
	std::vector <std::string> parameters;
	std::vector<Account*> openedAccount;
	std::string usercommand;
	bool F1 = false;
	bool F2 = false;
	// you may also want to store a collection of opened accounts here

	std::cout << "~~~ welcome to lincbank! ~~~" << std::endl;
	while (usercommand != "exit")
	{
		parameters.clear(); // clear ready for next command
		std::cout << std::endl << ">>> ";

		std::getline(std::cin, usercommand);
		char* cstr = new char[usercommand.length() + 1];
		strcpy(cstr, usercommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		// define all commands as per the brief
		std::string command = parameters[0];
		if (command.compare("options") == 0)
		{
			// display the various commands to the user
			std::cout << "these are the commands for the banking system:" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "open - to open an account" << std::endl;
			std::cout << "view - to display an accounts" << std::endl;
			std::cout << "withdraw - to withdraw money from account" << std::endl;
			std::cout << "deposit - to deposit money to an account" << std::endl;
			std::cout << "transfer - transfer money across accounts" << std::endl;
			std::cout << "project - computes compound interest" << std::endl;
		}
		else if (command.compare("open") == 0)
		{
			// allow a user to open an account
			// e.g., account* a = new savings(...);

			std::string command1 = parameters[1];
			std::string command2 = parameters[2];
			float command2f = std::stof(command2);

			if (command1 == "1" && F1 == true)
			{
				std::cout << "You have already made a current account:\n";
			}
			if (command1 == "1" && F1 == false)
			{
				Account* current = new Current(command2f);
				std::cout << "balance: \x9C" << current->getbalance();
				openedAccount.push_back(current);
				F1 = true;
			}
			// \x9C makes pound sign in c++ 

			if(command1 == "2")
			{
				Account* saving = new Saving(command2f,false);
				std::cout << "balance: \x9C" << saving->getbalance();
				openedAccount.push_back(saving);
			}

			if (command1 == "3" && F2 == true)
			{
				std::cout << "you already own a isa account:\n";
			}
			if (command1 == "3" && F2 == false)
			{
				Account* Isa = new Saving(command2f, true);
				std::cout << "balance: \x9C" << Isa->getbalance();
				openedAccount.push_back(Isa);
				F2= true;
			}
			

		}
		else if (command.compare("view") == 0)
		{
			if (parameters.size() > 2)
			{
				std::cout << "please input a valid number:";
			}
			// alternatively, display all accounts if no index is provided
			else if (parameters.size() == 1)
			{
				for (auto i : openedAccount)
				{
					std::cout << "\x9C" << i->getbalance() << std::endl;
					
				}
			}
			// display an account according to an index (starting from 1)
			else
			{
				std::cout << "\x9C" << openedAccount[stoi(parameters[1]) - 1]->getbalance() << std::endl;
			}
			
		}
		else if (command.compare("withdraw") == 0)
		{
			// allow user to withdraw funds from an account
		}
		else if (command.compare("deposit") == 0)
		{
			// allow user to deposit funds into an account
		}
		else if (command.compare("transfer") == 0)
		{
			// allow user to transfer funds between accounts
			// i.e., a withdrawal followed by a deposit!
		}
		else if (command.compare("project") == 0)
		{
			// compute compound interest t years into the future
		}
		//else if (command.compare("search"))
		//{
		//	allow users to search their account history for a transaction
		//  (this is a stretch task)
		//}

	}

	std::cout << "Press any key to quit...";
	std::getchar();


}