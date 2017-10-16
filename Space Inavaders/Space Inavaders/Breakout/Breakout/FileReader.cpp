#include "pch.h"
#include "FileReader.h"


FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}

std::ifstream FileReader::OpenFile(std::string filePath)
{
	std::ifstream myFile(filePath);
	return myFile;
}

void FileReader::closeFileStream(std::ifstream& stream)
{
	stream.close();
}