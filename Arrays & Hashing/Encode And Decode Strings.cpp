#include <string>
#include <vector>

class Codec {
public:
    // Encodes a list of strings to a single string.
    // Each string's length is stored as a fixed-size prefix before the actual string content.
    string encode(const vector<string>& strs) {
        string encodedString;
      
        for (const string& str : strs) {
            // Convert the size to a string of bytes and append it to the result.
            int size = str.size();
            encodedString.append(reinterpret_cast<char*>(&size), sizeof(size));
            // Append the actual string data.
            encodedString.append(str);
        }
      
        return encodedString;
    }

    // Decodes a single string to a list of strings by reading the fixed-size length prefix
    // and then reading the corresponding number of characters.
    vector<string> decode(const string& s) {
        vector<string> decodedStrings;
      
        size_t i = 0;
        int stringSize = 0;
      
        while (i < s.size()) {
            // Copy the size information at the current position.
            memcpy(&stringSize, s.data() + i, sizeof(stringSize));
            i += sizeof(stringSize);
          
            // Get the substr starting from the current position with the extracted length
            decodedStrings.push_back(s.substr(i, stringSize));
            i += stringSize;
        }
      
        return decodedStrings;
    }
};
