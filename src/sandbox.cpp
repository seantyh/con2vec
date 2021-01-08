#include <iostream>
#include <vector>
#include <string>
#include <regex>

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