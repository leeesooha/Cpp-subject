#include "TextReplacer.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	std::ifstream inputFile;

	inputFile.open(argv[1]);
	//실패처리

	std::string buff, line;
	line = "";
	while (std::getline(inputFile, buff)) {
		line += buff;
    }
	inputFile.close();

//
	// for ()
//

	std::string filename;
	filename = "";
	filename += argv[1];
	filename += "_copy[0]";
	std::ofstream outputFile(filename.c_str()); // 파일 쓰기 모드로 열기

	outputFile << "asdf" << std::endl;
	return (0);
}