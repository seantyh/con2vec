#pragma once

#include <vector>
#include <string>
#include <regex>
using namespace std;

struct ConstructRule {
    regex pattern;
    vector<string> constructs;
};

vector<string> split_char(const string& text);
const string get_construction(
    const string& word, 
    const vector<regex>& rules);

vector<ConstructRule>
parse_input_rules(const string& rule_path);

vector<string> readTokens(const string& intext, const char& delim);