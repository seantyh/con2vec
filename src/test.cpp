
#include <iostream>
#include <cassert>
#include "sandbox.h"
using namespace std;

int main(){
    assert(1==1);

    cout << "testing split_char" << endl;
    const string intext = "測試字串";
    const vector<string> splitted {"測", "試", "字", "串"};
    assert(split_char(intext) == splitted);

    vector<regex> rules_pat {regex{"(sub)(.*)"}};
    get_construction("subject", rules_pat);
    cout << "all done." << endl;
}