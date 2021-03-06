/*
Name:		Youngmin Chung
Date:		Jan 24, 2019
Purpose:	To implement main function
			To get input data and do data validation
			To call major functions
Version:	1.0
*/

#include "pch.h"

using namespace std;

int main(int argc, char * argv[])
{
	locale here("");
	cout.imbue(here);

	cout << "fileusage (c) 2018, Youngmin Chung" << endl;

	//if arguments are more than 4, error and exit
	if (argc > 4)
	{
		cerr << "Error: invalid input" << endl;
		return EXIT_FAILURE;
	}

	//declare variables
	deque<string> dArg;
	map<char, int> mSwitches;
	regex expression;
	string strExpression;
	path folder = ".";
	//vector<ExtManager> vExtManager;
	//vector<FileManager> vFileManager;
	vector<Filebackup> vFilebackup;

	//call parseInput function
	//get the switch options, regular expression, root folder from the input
	dArg = parseInput(argc, argv);

	//call parseSwitch function and do data validation
	if (argc > 1)
	{
		if (dArg.front()[0] != '-' && argc == 2)
			folder = dArg[0];

		if (argc == 3)
		{
			if (dArg.front()[0] != '-')
			{
				cerr << "Error: invalid input" << endl;
				return EXIT_FAILURE;
			}

			if (!mSwitches['x'])
			{
				folder = dArg[1];
			}
			else
			{
				try
				{
					expression = dArg[1];
				}
				catch (regex_error& ex)
				{
					cerr << "Error: Bad Regular Expression\n" << ex.what() << endl;
					return EXIT_FAILURE;
				}

				strExpression = dArg[1];
				if (strExpression[0] != '\\')
				{
					cerr << "Error: extension expression is missing" << endl;
					return EXIT_FAILURE;
				}
			}
		}

		//if unacceptable input , exit
		//if x not followed by regex, exit
		//if regex is invalid, throw an exception
		if (argc == 4)
		{
			if (dArg.front()[0] != '-')
			{
				cerr << "Error: invalid input" << endl;
				return EXIT_FAILURE;
			}
			if (!mSwitches['x'])
			{
				cerr << "Error: invalid input" << endl;
				return EXIT_FAILURE;
			}
			try
			{
				expression = dArg[1];
			}
			catch (regex_error & ex)
			{
				cerr << "Error: Bad Regular Expression" << endl << ex.what() << endl;
				return EXIT_FAILURE;
			}

			strExpression = dArg[1];
			if (strExpression[0] != '\\')
			{
				cerr << "Error: extension expression is missing" << endl;
				return EXIT_FAILURE;
			}
			folder = dArg[2];
		}
	}

	//call parseInfo function 
	//parseInfo(mSwitches, expression, folder, vExtManager, vFileManager);

	//call printInput function to print data information
	//printInput(mSwitches, strExpression, folder, vExtManager, vFileManager);

	//call filebackup function
	report(mSwitches, strExpression, expression, folder, vFilebackup);
}