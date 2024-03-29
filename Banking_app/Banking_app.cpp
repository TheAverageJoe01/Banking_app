#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include "Current.h"
#include "Saving.h"

//to comment a large chunk of code press ctrl + k , then ctrl + c
// to undo comments on a large chunk of code press ctrl + k , then ctrl + u
bool isnumber(const std::string& str);

int main()
{
	std::vector <std::string> parameters;
	std::vector<Account*> openedAccount;
	int currentlyViewed;
	std::string usercommand;
	bool F1 = false;
	bool F2 = false;
	bool F3 = false;
	// you may also want to store a collection of opened accounts here

	std::cout << "~~~ welcome to lincbank! ~~~" << std::endl;
	std::cout << "open type initial_deposit: open a current (1), savings (2) or ISA (3) account\nview[index]: view balance and recent transactions\nwithdraw sum : withdraw funds from most recently viewed account\ndeposit sum : deposit funds into most recently viewed account\ntransfer src dest sum : transfer funds between accounts\nproject years : project balance forward in time\nsearch value : searching history for values that match the input of currently viewed account\nexit : close this application\noptions : view these options again";
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
		if (parameters.size() == 0)
		{
			std::cout << "Please input a valid answer\n";
		}
		else
		{

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
				std::cout << "search - searches for a specific value in transaction history of currently viewed account" << std::endl;
			}
			else if (command.compare("open") == 0)
			{
				if (parameters.size() !=3)
				{
					std::cout << "Please input a valid answer\n";
				}
				else
				{
					// allow a user to open an account
					// e.g., account* a = new savings(...);

					if (parameters[1].compare("1") == 0)
					{
						if (F1 == true) 
						{
							std::cout << "You have already made a current account:\n";
						}
						else 
						{
							if (isnumber(parameters[2]) == true)
							{
								Transaction transaction("Starting balance", std::stof(parameters[2]));
								Account* current = new Current(std::stof(parameters[2]));
								current->add_history(transaction);//adds satrting balance to history
								std::cout << std::fixed << std::setprecision(2);// formates float in certain way
								std::cout << "balance: \x9C" << current->getbalance();
								openedAccount.push_back(current);//pushes back account to seperat list 
								currentlyViewed = openedAccount.size() - 1;//sets this account as currently viewed
								F1 = true;
							}
							else
							{
								std::cout << "Please input a valid answer\n";
							}

						}
					}
					// \x9C makes pound sign in c++ 

					else if (parameters[1].compare("2") == 0 )
					{
						if (isnumber(parameters[2]) == true)
						{
							Transaction transaction("Starting balance", std::stof(parameters[2]));//converts parameter[2] into a float 
							Account* saving = new Saving(std::stof(parameters[2]), false);
							saving->add_history(transaction);
							std::cout << std::fixed << std::setprecision(2);
							std::cout << "balance: \x9C" << saving->getbalance();
							openedAccount.push_back(saving);
							currentlyViewed = openedAccount.size() - 1;
						}
						else
						{
							std::cout << "Please input a valid answer\n";
						}
					}

					else if (parameters[1].compare("3") == 0)
					{
						if (F2 == true)
						{
							std::cout << "you already own a isa account:\n";
						}
						else if (isnumber(parameters[2]) == true)
						{
							if (std::stof(parameters[2]) >= 1000)
							{
								Transaction transaction("Starting balance", std::stof(parameters[2]));
								Account* Isa = new Saving(std::stof(parameters[2]), true);
								Isa->add_history(transaction);
								std::cout << std::fixed << std::setprecision(2);
								std::cout << "balance: \x9C" << Isa->getbalance();
								openedAccount.push_back(Isa);
								currentlyViewed = openedAccount.size() - 1;
								F2 = true;
							}
							else
							{
								std::cout << "Not enough money to make an ISA:";
							}
						}
						else
						{
							std::cout << "Please input a valid answer\n";
						}
					}
					else
					{
						std::cout << "please input a valid answer\n";
					}
				}

			}
			else if (command.compare("view") == 0)
			{
				if (parameters.size() > 2)
				{
					std::cout << "please input a valid answer:";
				}
				// alternatively, display all accounts if no index is provided
				else if (parameters.size() < 2)
				{
					std::cout << "History:\n";
					for (auto i : openedAccount)// iterates through openedaccounts vector
					{
						std::cout << i->getacType() << " Account " << "\x9C" << i->getbalance() << std::endl;
						i->showHistory();
					
					}
				}
				// display an account according to an index (starting from 1)
				else
				{
					//Check for number
					if (isnumber(parameters[1]) == true)
					{
						std::cout << openedAccount[stoi(parameters[1]) - 1]->getacType() <<" \x9C" << openedAccount[stoi(parameters[1]) - 1]->getbalance() << std::endl;
						currentlyViewed = stoi(parameters[1]) - 1;
						openedAccount[stoi(parameters[1]) - 1]->showHistory();//disapays history of chosen account
					}
					else
					{
						std::cout << "please input a valid answer:";
					}
				}
			
			}
			else if (command.compare("withdraw") == 0)
			{
				if (parameters.size() != 2) 
				{
					std::cout << "please input a valid answer:";
				}
				else
				{
					// allow user to withdraw funds from an account
					if (isnumber(parameters[1]) == true)
					{
						openedAccount[currentlyViewed]->withdraw(stof(parameters[1]));
					}
					else
					{
						std::cout << "please input a valid answer:";
					}
				}
			}
			else if (command.compare("deposit") == 0)
			{
				if (parameters.size() != 2)
				{
					std::cout << "please input a valid answer:";
				}
				else
				{
					// allow user to deposit funds into an account
					if (isnumber(parameters[1]) == true)
					{
						openedAccount[currentlyViewed]->deposit(stof(parameters[1]));
					}
					else
					{
						std::cout << "please input a valid answer:";
					}
				}
			}
			else if (command.compare("transfer") == 0)
			{
				// allow user to transfer funds between accounts
				if (parameters.size() != 3)
				{
					std::cout << "please input a valid answer:";
				}
				else
				{
					int source = stoi(parameters[1]) - 1;
					int destination = stoi(parameters[2]) - 1;
					float input_amount = stof(parameters[3]);
					if (openedAccount[source]->withdraw(input_amount))// withdraws from first account
					{
						openedAccount[destination]->deposit(input_amount);//deposits into second 
						Transaction transaction("--Transfer", input_amount);
						openedAccount[destination]->add_history(transaction);
						openedAccount[source]->add_history(transaction);
					}
					else
					{
						std::cout << "please input a valid answer:";
					}
				}
			
			
				// i.e., a withdrawal followed by a deposit!
			}
			else if (command.compare("project") == 0)
			{
				// compute compound interest t years into the future
				if (parameters.size() != 2)
				{
					std::cout << "please input a valid answer:";
				}
				else 
				{
					float years = stof(parameters[1]);
					if (openedAccount[currentlyViewed]->getacType() == "current")
					{
						std::cout << "Current accounts do not have any interest:";
					}
					else if (openedAccount[currentlyViewed]->getacType() == "savings" || openedAccount[currentlyViewed]->getacType() == "ISA")// checks to see if the account type is a savings or an isa
					{
						Saving* temp = dynamic_cast<Saving*>(openedAccount[currentlyViewed]);
						std::cout << temp->computeInterest(years);
					}
					else
					{
						std::cout << "please input a valid answer:";
					}
				}
			}
			else if (command.compare("search") == 0)
			{
			//	allow users to search their account history for a transaction
			//  (this is a stretch task)
				if (parameters.size() != 2)
				{
					std::cout << "please input a valid answer:";
				}
				else
				{
					// allow user to withdraw funds from an account
					if (isnumber(parameters[1]) == true)
					{
						openedAccount[currentlyViewed]->searchTransaction(stof(parameters[1]));
					}
					else
					{
						std::cout << "please input a valid answer:";
					}
				}
			}
		}


	}

	std::cout << "Press any key to quit...";
	std::getchar();

}

// checking to see if variable is a number 
bool isnumber(const std::string& str)
{
	{
		for (char const& i : str) // checking char for number returning a bool
		{
			if (std::isdigit(i) == 0) return false;
		}
		return true;
	}
}