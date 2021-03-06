//This file implememts the overlap function for 2 strings and
//returns the length of the overlaps.

#include <string>
#include <algorithm>
#include <utility>

using namespace std;

/***********************************************************
 *Parameter: String a and String b by reference as input
 *           strings.
 *Return: Returns the overlap length of the 2 input stirngs
 *Description: This function loops from 1 to the length
 *             of the minimum string. Creates temporary
 *             strings that are compared with each other
 *             to find the overlap
 * *********************************************************/
int overlapStrings(string& a, string& b) {
  int overlap_length = 0;
  int min_length = min(a.length(), b.length());
  string temp_a = a.substr(a.length() - min_length), //holds last part of string a
         temp_b = b.substr(0, min_length); //holds first part of string b


  for(int i = 0; i < min_length; i++) {
    temp_b.resize(min_length - i); //get first end of str b

    //get first end of string a
    reverse(temp_a.begin(), temp_a.end());
    temp_a.resize(min_length - i);
    reverse(temp_a.begin(), temp_a.end());

    //compare start of a to end of b
    if(temp_a == temp_b) {
      overlap_length = temp_a.length();
      break;
    }

  }

  return overlap_length;
}


/***************************************************************
 *Parameter: Recieves a pair of strings
 *Return: Returns a pair of ints with both overlaps
 *Description: Finds both possible overlaps using a first and b
 *			       second and using b first and a second. The first
 *	           in the pair represents the overlap of tail of a
 *             with head of b. And second element of the pair
 *             represents the overlap in the reverse order.
 * ************************************************************/
pair<int, int> overlapStrings(pair<string, string> str_pair) {

  int first = overlapStrings(str_pair.first, str_pair.second);
  int second = overlapStrings(str_pair.second, str_pair.first);

  return make_pair(first, second);
}


/**************************************************************************
 * Function to remove strings that are subtrings of other strings in the
 * same vector
 * Parameters: A vector of strings
 **************************************************************************/
void removeSubstrings(vector<string>& data)
{
  for(int i = 0; i < data.size(); i++) {
    for(int j = i+1; j < data.size(); j++) {
      //If string i is a substring of string j, remove string i from the set of strings
      if(data[j].find(data[i]) != string::npos) {
        data.erase(data.begin()+i);
        i--;
        break;
      }
    }
  }
}


//Functor to sort by length
struct SortByLength
{
  bool inline operator()(const string& a, const string& b)
  {
    //If the lengths are equal, compare normally
    if(a.length() == b.length()){
      return a < b;
    }
    //else compare lengths
    return a.length() < b.length();
  }
};
