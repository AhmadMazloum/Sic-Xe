#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <map>
#include <set>
#include <regex>

using namespace std;
class codeLine
{
  int pc; // pc value before this line
  bool mode;
public:
  int lineNo;
  int address;
  string line;
  vector<int> errorIds;
  codeLine(string &line, int lineNo);
  void setMode(bool mode);
  void loadPc(int pc); 
  void validate(set<string> &mustLabelled, set<string> &mustUnlabelled, map<string,regex> &operandPatterns, set<string> &labels, map<string,int> &unknownLabels); // validates line for errors and saves its address
  int getNewPc(); // return the new pc
  int hex2dec(string hex);
  string dec2hex(int dec);
  string getHexAddress();
private:
  void validateFreeFormat(set<string> &mustLabelled, set<string> &mustUnlabelled, map<string,regex> &operandPatterns, set<string> &labels, map<string,int> &unknownLabels);
  void validateFixedFormat(set<string> &mustLabelled, set<string> &mustUnlabelled, map<string,regex> &operandPatterns, set<string> &labels, map<string,int> &unknownLabels);
}; 
