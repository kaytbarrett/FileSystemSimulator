#ifndef FILE_H
#define FILE_H

#include <string>
#include <ctime>


class File {

private:
    std::string name;
    std::string content;
    size_t size;
    std::time_t createdAt;
    std::time_t modifiedAt;

public:
    File(const std::string& name);
    void write(const std::string& data);
    std::string read() const;
    void update(std::string& data);

    std::string getName() const;
    size_t getSize() const;
    std::string getMetadata() const;

    
};


#endif