#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Directory.h"
#include <string>
#include <memory>


class FileSystem {

private:
    Directory root;
    Directory* currentDirectory;

public:
    FileSystem();
    void changeDirectory(const std::string& dirName);
    void listCurrentDirectory() const; 
    void createFile(const std::string& fileName);
    void deleteFile(const std::string& fileName);
    void createDirectory(const std::string& dirName);
    void deleteDirectory(const std::string& dirName);
    void readFile(const std::string& fileName);
    void writeFile(const std::string& fileName, const std::string& data);

};


#endif