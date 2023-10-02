#include "MyString.hpp"

int ioFileStatus(std::ifstream &inputFile, std::ofstream &outputFile, std::string src_filename, std::string dst_filename)
{
	int	inerror = 0;
	int	outerror = 0;

	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open file: " << src_filename << std::endl;
		inerror = 1;
	}
	if (!outputFile.is_open())
	{
		std::cerr << "Failed to create file: " << dst_filename << std::endl;
		outerror = 1;
	}
	if (inerror == 1 || outerror == 1)
	{
		if (inerror == 1)
			inputFile.close();
		if (outerror == 2)
			outputFile.close();
		return (1);
	}
	return (0);
}

void getFileText(std::ifstream &inputFile, std::string &fileText)
{
	std::string buff;

	inputFile.seekg(0, std::ios::end);
    std::streampos	fileSize = inputFile.tellg();
	inputFile.seekg(0, std::ios::beg);

	while (std::getline(inputFile, buff))
	{
		fileText.append(buff).append("\n");
	}
	long long	fileTextSize = fileText.size();
	if (fileTextSize != fileSize)
	 	fileText.erase(fileTextSize - 1, 1);
}

void allReplace(std::string &fileText, std::string &src_str, std::string &dst_str)
{
	size_t pos = 0;

	MyString mystr(fileText);
	size_t src_str_length = src_str.size();
	if (src_str_length == 0)
		return ;
	pos = fileText.find(src_str);
	while (pos != std::string::npos)
	{
		mystr.myReplace(pos, src_str_length, dst_str);
		pos = fileText.find(src_str);
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	std::string src_filename = argv[1];
	std::string dst_filename = src_filename + ".replace";
	std::string src_str = argv[2];
	std::string dst_str = argv[3];
	std::string fileText;
	std::ifstream inputFile(src_filename.c_str());
	std::ofstream outputFile(dst_filename.c_str());

	if (ioFileStatus(inputFile, outputFile, src_filename, dst_filename) == 1)
		return (1);
	getFileText(inputFile, fileText);
	inputFile.close();
	allReplace(fileText, src_str, dst_str);
	outputFile << fileText; 
	outputFile.close();
	return (0);
}