#include<iostream>
using namespace std;

const int SPECIALIZATION{20};
const int BEDS{5};
const int DATA{2}; //name & status

string patients[SPECIALIZATION][BEDS][DATA];
int Menu();

void Add_new_patient()
{
	int specialization;
	string name, status;
	cout << "Enter specialization and name:  ";
	cin >> specialization >> name ;
	cout << "\nNow enter the status of the patient (0 = Regular , 1 = Urgent)";
	specialization--;  //as our arr is zero based

	if (patients[specialization][4][0] != "")  //make sure that all five spots are busy
	{
		cout << "Sorry we can`t add more patients for this specialization.\n\n";
		Menu();
	}


	if (status == "0")  //if it was a regular case just add at the end of the queue
	{
		for (int i = 0; i < 5; i++)
		{
			if (patients[specialization][i][0] == "")
			{
				patients[specialization][i][0] = name;
				patients[specialization][i][1] = status;
				break;
			}

		}
	}

	else   //for adding urgent cases
	{

		int n = 5;
		for (int patient = 0; patient < 5; patient++)
		{
			if (patients[specialization][patient][0] == "")
			{
				n = patient;
				break;
			}

		} //to know how many cases are already existing in this specialization

		

		if(n==0) 
		{
			patients[specialization][0][0] = name;
			patients[specialization][0][1] = status;
		}

		else {
			for (int i = n; i > 0; i--)
			{
				patients[specialization][i][0] = patients[specialization][i - 1][0];
				patients[specialization][i][1] = patients[specialization][i - 1][1];
			}

			patients[specialization][0][0] = name;
			patients[specialization][0][1] = status;
		}
	}

}


void Print_all_patients()
{
	cout << "*************************************************\n";
	for (int specialization = 0; specialization < 20; specialization++)
	{
		if (patients[specialization][0][0] == "") //just ignore the empty specialization
			continue;

		else
		{
			int n=5;
			for (int patient = 1; patient < 5; patient++)
			{
				if (patients[specialization][patient][0] == "")
				{
					n = patient;
					break;
			     }

			} //to know number of patients in every specialization

			cout << "There are " << n << " patient in specialization " << specialization + 1 << ".\n";

			for (int patient = 0; patient < n; patient++)
			{
				cout << patients[specialization][patient][0] << " ";
				if (patients[specialization][patient][1] == "1")
					cout << "Urgent\n";
				else
					cout << "Regular\n";
			}


		}
		cout << endl;
    }
	cout << endl;
}

void Get_next_patient()
{
	cout << "Enter specialization: ";
	int specialization;
	cin >> specialization;
	specialization--;//as our arr is zero based

		if (patients[specialization][0][0] != "") //make sure that the specialization queue is not empty
		{
			cout << patients[specialization][0][0] << "! Please go with the Dr.\n";

			for (int i = 0; i < 4; i++)
			{
				patients[specialization][i][0] = patients[specialization][i + 1][0];
				patients[specialization][i][1] = patients[specialization][i + 1][1];
			}

			patients[specialization][4][0] = "";
			patients[specialization][4][1] = "";
		}

		else
		{
			cout << "No patients at the moment. Have a rest,Dr.\n";

		}
	
}

int Menu() 
{
	string choice;

	while (true) {
		cout << "\nEnter your choice:" << endl << "1)Add new patient." << endl << "2)Print all patients." << endl << "3)Get next patient." << endl << "4)Exit." << endl;

		cin >> choice;

		if (choice == "1")
			Add_new_patient();

		else if (choice == "2")
			Print_all_patients();

		else if (choice == "3")
			Get_next_patient();

		else if (choice == "4")
		{
			"Thanks for using our hospital system.\n";
			return 0;
		}

		else
		{
			cout << "Invalid choice..Please read the menu carfully and chose an valid option.\n";
		}
	}

}

int main()
{
	Menu();
	return 0;
}