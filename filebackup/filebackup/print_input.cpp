/*
Name:		Youngmin Chung
Date:		Jan 24, 2019
Purpose:	To print folder, extension, filesize information
			To print summary and detail report
Version:	1.0
*/

#include "pch.h"
using namespace std;

//function print the result
void report(map<char, int> & mSwitches, string strExpression, regex expression, path const& folder, vector<Filebackup> & vFilebackup)
{
	string options = "";
	string extPrint;
		extPrint = ".*";

	//print detail report and summary
	unsigned long totalExtCount = 0;
	unsigned long long totalFileSize = 0;

	//cout << options << " ext: " << extPrint << " folder: " << folder << endl;
	cout << "Root Directory: " << current_path(); 
	cout << endl;

	for (auto x : vFilebackup)
	{
		cout << setw(27) << x.fileName << right << setw(12) << "Size: " << x.filesizeCount << endl;

		totalExtCount += x.fileCount;
		totalFileSize += x.filesizeCount;
	}
	if (totalExtCount == 0)
		cout << "\nThere is no files(.c/.cpp/.h//hpp)\n" << endl;
	cout << "Backup Total: "<< setw(13) << totalExtCount << setw(12) << "Size: " << totalFileSize << endl;
	
	cout << endl;
}