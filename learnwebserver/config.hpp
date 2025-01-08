#pragma once

#include<string>
#include<unordered_map>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<sstream>

class Config
{
public:
    ~Config()
    {
        std::cout << "~Config()" << std::endl;
    }
    Config(const Config&) = delete; //禁止拷贝构造
    Config& operator=(const Config&) = delete; //禁止赋值

    static Config& getInstance()
    {
        static Config config;
        return config;
    }
    std::string get(const std::string& key);
private:
    std::unordered_map<std::string, std::string> config_map;
    Config()
    {
        std::cout << "Config ()" << std::endl;
        load_config_file("config.txt");
    }

    void load_config_file(const char* filename)
    {
        std::ifstream configFile("/root/work/learnwebserver/config.txt");
        if(!configFile.is_open())
        {
            std::cerr << "Failed to open config file: " << filename << std::endl;
        }
        std::string line;
        while(std::getline(configFile, line))
        {
            std::istringstream iss(line);
            std::string key,val;
            if(getline(iss, key, '=')&&getline(iss, val))
            {
                remove_space(key);
                remove_space(val);
                std::cout<<key<<" "<<val<<std::endl;
                config_map[key] = val;
            }

        }
    }
    void remove_space(std::string &str)
    {
        str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    }
};
