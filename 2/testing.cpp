#include <iostream>
using namespace std;
 
int checkPar(const string& instr, int pos = 0)
{
    static const int len = instr.length();
    static const string op = "([{";
    static const string cp = ")]}";
    while (pos < len)
    {
        const size_t tokpos = op.find_first_of(instr[pos]);
        if (tokpos != string::npos)
        {
            pos = checkPar(instr, pos + 1);
            if (pos < 0 || pos >= len || instr[pos] != cp[tokpos]) return -1;
        }
        else
            if (cp.find_first_of(instr[pos]) != string::npos) return pos;       
        ++pos;
    }   
    return pos;
}
 
int main()
{
    string s = "))((";  
    cout << (checkPar(s) == s.length() ? "Yes" : "No") << endl;
    return 0;
}