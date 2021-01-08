#pragma once

#include <vector>
#include <string>
#include <regex>
using namespace std;

vector<string> split_char(const string& text);
const string get_construction(
    const string& word, 
    const vector<regex>& rules);