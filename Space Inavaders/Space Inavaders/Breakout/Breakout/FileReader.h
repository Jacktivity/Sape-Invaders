#pragma once
#include <fstream>
#include <string>
class FileReader
{
public:
	FileReader();
	~FileReader();

public:
	std::ifstream OpenFile(std::string filePath);
	void closeFileStream(std::ifstream& stream);
};

