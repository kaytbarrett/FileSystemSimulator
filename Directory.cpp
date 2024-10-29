#include "Directory.h"

#include <iostream>
#include <string>

Directory::Directory(const std::string& name, Directory* parent){
    this->name = name;
    this->parent = parent;
}

void Directory::createFile(const std::string& fileName){
    for (const auto& file:files){
        if (file->getName() == fileName){
            std::cerr << "Error: File '" << fileName << "' already exists." << std::endl;
        };
    };

    files.push_back(std::make_unique<File>(fileName));
    std::cout << "File " << fileName << " created." << std::endl;
}

void Directory::deleteFile(const std::string& fileName){
    for (auto it = files.begin(); it != files.end(); ++it){
        if ((*it)->getName() == fileName){
            files.erase(it);
            std::cout << "File '" << fileName << "' deleted." << std::endl;
            return;
        };
    };

    std::cerr << "Error: File '" << fileName << "' does not exist." << std::endl;
}

File* Directory::getFile(const std::string& fileName){
    for (const auto& file:files){
        if (file->getName() == fileName){
            return file.get();
        };
    };

    std::cerr << "Error: File '" << fileName << "' does not exist." << std::endl;
    return nullptr;
}

void Directory::createDirectory(const std::string& dirName){
    for (const auto& dir:subdirectories){
        if (dir->getName() == dirName){
            std::cerr << "Error: Directory '" << dirName << "' already exists." << std::endl;
        };
    };

    subdirectories.push_back(std::make_unique<Directory>(dirName, this));
    std::cout << "Directory " << dirName << " created." << std::endl;
}

void Directory::deleteDirectory(const std::string& dirName){
    for (auto it = subdirectories.begin(); it != subdirectories.end(); ++it){
        if ((*it)->getName() == dirName){
            subdirectories.erase(it);
            std::cout << "Directory '" << dirName << "' deleted." << std::endl;
            return;
        };
    };

    std::cerr << "Error: Directory '" << dirName << "' does not exist." << std::endl;
}

Directory* Directory::getDirectory(const std::string& dirName){
    for (const auto& dir:subdirectories){
        if (dir->getName() == dirName){
            return dir.get();
        };
    };

    std::cerr << "Error: Directory '" << dirName << "' does not exist." << std::endl;
    return nullptr;
}

void Directory::listContents() const {
    std::cout << "Present Working Directory: " << name << "\n";
    std::cout << "Files: \n";
    for (const auto& file:files){
        std::cout << "- " << file->getName() << "\n";
    }

    std::cout << "Subdirectories: \n";
    for (const auto& dir:subdirectories){
        std::cout << "- " << dir->getName() << "\n";
    }
}

std::string Directory::getName() const {
    return name;
}

Directory* Directory::getParent() const{
    return parent;
}