#include "FileSystem.h"

#include <iostream>


FileSystem::FileSystem() : root("root") {

    currentDirectory = &root;

}

void FileSystem::changeDirectory(const std::string& dirName){

    if (dirName == ".."){
        if(currentDirectory->getParent() != nullptr){
            currentDirectory = currentDirectory->getParent();
        } else {
            std::cout << "Already at root directory." << std::endl;
        }
    } else {
        Directory* newDir = currentDirectory->getDirectory(dirName);
        if (newDir){
            currentDirectory = newDir;
        }
    }
}

void FileSystem::listCurrentDirectory() const {
    currentDirectory->listContents();
}

void FileSystem::createFile(const std::string& fileName) {
    currentDirectory->createFile(fileName);
}

void FileSystem::deleteFile(const std::string& fileName) {
    currentDirectory->deleteFile(fileName);
}

void FileSystem::createDirectory(const std::string& dirName) {
    currentDirectory->createDirectory(dirName);
}

void FileSystem::deleteDirectory(const std::string& dirName) {
    currentDirectory->deleteDirectory(dirName);
}

void FileSystem::readFile(const std::string& fileName) {
    File* file = currentDirectory->getFile(fileName);
    if (file) {
        std::cout << file->read() << "\n";
    }
}

void FileSystem::writeFile(const std::string& fileName, const std::string& data) {
    File* file = currentDirectory->getFile(fileName);
    if (file) {
        file->write(data);
    }
}