#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

inline std::string __current_path = std::filesystem::current_path().string(); 

inline void readFile(const std::string& path,std::string& source){

    if(!std::filesystem::exists(path)){
        std::cout << "Failed to read file ";
        std::cout << "No such file or directories " << path << "\n";
    }

    std::ifstream input(path);
    std::string temp;
    while(std::getline(input,temp)){
        source += "\n" + temp;
    }
    
}