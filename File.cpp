#include "File.h"
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>

File::File(const std::string& name){
    this->name = name;
    this->content = "";
    this->size = content.size();
    this->createdAt = std::time(nullptr);
    this->modifiedAt = createdAt;
}

void File::write(const std::string& data){
    content = data;
    size = content.size();
    modifiedAt = std::time(nullptr);
}

std::string File::read() const{
    return content;
}

void File::update(std::string& data){
    write(data);
}

std::string File::getName() const {
    return name;
}

size_t File::getSize() const {
    return size;
}

std::string File::getMetadata() const {
    std::stringstream metadata;
    metadata << "File name: " << name << "\n"
             << "File size: " << size << " bytes\n"
             << "Created at: " << std::asctime(std::localtime(&createdAt)) << "\n"
             << "Modified last: " << std::asctime(std::localtime(&modifiedAt));

    return metadata.str();
}