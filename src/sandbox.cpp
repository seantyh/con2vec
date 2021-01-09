#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include "sandbox.h"

using namespace std;

vector<string> split_char(const string& text)
{            
    vector<string> char_list;
    string buf;
    int offset_ch = 0;

    for (int i=0; i<text.size(); i++){
        if((text[i] & 0xc0) != 0x80){
            char_list.push_back(string());            
        }
        
        string& buf = char_list[char_list.size()-1];
        buf.push_back(text[i]);
    }

    return char_list;
}



const string get_construction(
    const string& word, 
    const vector<regex>& rules){
    
    for (const regex& pat: rules){
        smatch match;        
        regex_match(word, match, pat);
        cout << "match size: " << match.size() << endl;
        for (int i=0; i<match.size(); ++i){
            cout << "match iter" << endl;
            cout << match[i] << endl;
        }
    }
    
    return string();
}

vector<ConstructRule>
parse_input_rules(const string& rule_path){
    vector<ConstructRule> rules;
    cout << "input_rule_path: " << rule_path <<  endl;
    ifstream fin(rule_path);
    string line;

    if (!fin.good()){
        cout << "File not found" << endl;
        return rules;
    }

    while (getline(fin, line)){
        ConstructRule rule;
        vector<string> entries = readTokens(line, ',');
        cout << entries[0] << endl;
        vector<string> constructs;
        if(entries.size() > 1){
            constructs = readTokens(entries[1], ';');
            cout << "-- constructs --" << endl;
            for (auto cons: constructs){
                cout << cons << endl;
            }
        }
        rule.pattern = regex(entries[0]);
        rule.constructs = constructs;
        rules.push_back(rule);
    }
    cout << "rules parsed: " << rules.size() << endl;
    return rules;
}

vector<string> readTokens(const string& intext, const char& delim){
    vector<string> tokens;
    string token;
    istringstream ss(intext);
    while (getline(ss, token, delim)){
        int start_idx = token.find_first_not_of(" ");
        int last_idx = token.find_last_not_of(" ");
        string trimmed = token.substr(start_idx, last_idx-start_idx+1);
        tokens.push_back(trimmed);
    }

    return tokens;
}