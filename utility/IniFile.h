#pragma once

#include <string.h>
#include <string>
#include <map>
using namespace std;


namespace yazi {
namespace utility {

class Value
{
public:
    Value();
    Value(bool value);
    Value(int value);
    Value(double value);
    Value(const char * value);
    Value(const string & value);
    ~Value();

    Value & operator = (bool value);
    Value & operator = (int value);
    Value & operator = (double value);
    Value & operator = (const char * value);
    Value & operator = (const string & value);
    Value & operator = (const Value & value);

    bool operator == (const Value & other);
    bool operator != (const Value & other);
    
    operator bool();
    operator int();
    operator double();
    operator string();

private:
    string m_value;
};

typedef std::map<string, Value> Section;

class IniFile
{
public:
    IniFile();
    IniFile(const string & filename);
    ~IniFile();

    bool load(const string & filename);
    void save(const string & filename);
    void show();
    void clear();

    Value & get(const string & section, const string & key);
    void set(const string & section, const string & key, const Value & value);

    bool has(const string & section);
    bool has(const string & section, const string & key);

    void remove(const string & section);
    void remove(const string & section, const string & key);

    Section & operator [] (const string & section)
    {
        return m_sections[section];
    }

    string str();

private:
    string trim(string s);

private:
    string m_filename;
    std::map<string, Section> m_sections;
};

}}
