/*
Name:		Youngmin Chung
Date:		Jan 24, 2019
Purpose:    Header file
			To create a FileManager class
			To write predicate functions for the class
			To declare major functions
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <iomanip>
#include <regex>
#include <locale>

#include <filesystem>
using namespace std::experimental::filesystem::v1;




//declare 'filebackup'class to store file/folder's name record data
class Filebackup
{
public:
	std::string fileName;
	std::string folderName;
	unsigned long fileCount;
	unsigned long long filesizeCount;
	unsigned long fileNumPerFolder;

	Filebackup() {};
	//backup();
	Filebackup(std::string fName, unsigned long fileCount, unsigned long fnpf, uintmax_t fCount, std::string foName) :
		fileName(fName), fileCount(fileCount), fileNumPerFolder(fnpf), filesizeCount(fCount), folderName(foName) {};

};


////declare class to store extension record data
//class ExtManager
//{
//public:
//	std::string filename;
//	unsigned long extCount;
//	unsigned long long filesizeCount;
//
//	ExtManager() {};
//	ExtManager(std::string eName, unsigned long eCount, uintmax_t fCount) :
//		filename(eName), extCount(eCount), filesizeCount(fCount) {};
//};
//
////declare class to store folder record data
//class FileManager
//{
//public:
//	std::string filename;
//	unsigned long extNumPerFolder;
//	std::string folderName;
//
//	FileManager() {};
//	FileManager(std::string eName, unsigned long enpf, std::string fName) :
//		filename(eName), extNumPerFolder(enpf), folderName(fName) {};
//};


//predicate function byExt to pass to sort algorithm, ascending sort
inline bool byExtAscending(Filebackup const& lhs, Filebackup const& rhs)
{
	return lhs.fileName < rhs.fileName;
}

//function to parse input data to a container
std::deque<std::string> parseInput(int argc, char * argv[]);

//function to scan and parse the current folder and all its subfolders
//void parseInfo(std::map<char, int>&, std::regex, path const&, std::vector<ExtManager>&, std::vector<FileManager>&);

//function print the result
//void printInput(std::map<char, int>&, std::string, path const&, std::vector<ExtManager>&, std::vector<FileManager>&);

//function scan and print
void report(std::map<char, int>&, std::string, std::regex, path const&, std::vector<Filebackup>&);
















//
////predicate function byExt to pass to sort algorithm, descending sort
//inline bool byExtDescending(ExtManager const& lhs, ExtManager const& rhs)
//{
//	return lhs.filename > rhs.filename;
//}
//
////predicate function bySize to pass to sort algorithm, ascending sort
//inline bool bySizeAscending(ExtManager const& lhs, ExtManager const& rhs)
//{
//	return lhs.filesizeCount < rhs.filesizeCount;
//}
//
////predicate function bySize to pass to sort algorithm, descending sort
//inline bool bySizeDescending(ExtManager const& lhs, ExtManager const& rhs)
//{
//	return lhs.filesizeCount > rhs.filesizeCount;
//}
//
////predicate function byFolder to pass to sort algorithm, ascending sort
//inline bool byFolderAscending(FileManager const& lhs, FileManager const& rhs)
//{
//	return lhs.folderName < rhs.folderName;
//}
//
////predicate function byFolder to pass to sort algorithm, descending sort
//inline bool byFolderDescending(FileManager const& lhs, FileManager const& rhs)
//{
//	return lhs.folderName > rhs.folderName;
//}
//