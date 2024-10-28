#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "File.h"
#include <vector>
#include <string>
#include <memory>

class Directory {

private:
    std::string name;
    std::vector<std::unique_ptr<File>> files;
    std::vector<std::unique_ptr<Directory>> subdirectories;
    Directory* parent;

public:
    Directory(const std::string& name, Directory* parent = nullptr);
    
    void createFile(const std::string& fileName);
    void deleteFile(const std::string& fileName);
    File* getFile(const std::string& fileName);

    void createDirectory(const std::string& dirName);
    void deleteDirectory(const std::string& dirName);
    Directory* getDirectory(const std::string& dirName);
    void listContents() const;
    std::string getName() const;

    Directory* getParent() const;

};


#endif