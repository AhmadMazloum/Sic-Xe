#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
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
  void validate(unordered_set<string> &mustLabelled, unordered_set<string> &mustUnlabelled, map<string,regex> &operandPatterns, unordered_set<string> &labels, unordered_map<string,int> &unknownLabels); // validates line for errors and saves its address
  int getNewPc(); // return the new pc
private:
  void validateFreeFormat(unordered_set<string> &mustLabelled, unordered_set<string> &mustUnlabelled, map<string,regex> &operandPatterns, unordered_set<string> &labels, unordered_map<string,int> &unknownLabels);
  void validateFixedFormat(unordered_set<string> &mustLabelled, unordered_set<string> &mustUnlabelled, map<string,regex> &operandPatterns, unordered_set<string> &labels, unordered_map<string,int> &unknownLabels);
}; 
