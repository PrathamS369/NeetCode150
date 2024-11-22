import java.util.List;
import java.util.ArrayList;

public class Codec {

    
    public String encode(List<String> strs) {
        // Use StringBuilder to efficiently build the encoded string
        StringBuilder encodedString = new StringBuilder();
      
        // Append the length of each string followed by the string itself to the builder
        for (String str : strs) {
            // Cast length to char to compactly store the length (only safe for strings of length 0-65535)
            encodedString.append((char) str.length()).append(str);
        }
      
        // Convert the StringBuilder to a String and return
        return encodedString.toString();
    }

    public List<String> decode(String s) {
        // Create a list to hold the decoded strings
        List<String> decodedStrings = new ArrayList<>();
      
        // Initialize an index to iterate through the encoded string
        int index = 0;
        int length = s.length();
      
        // Iterate through the encoded string and decode the strings
        while (index < length) {
            // Read the size of the next string
            int size = s.charAt(index++);
            // Extract the actual string by its size and add it to the collection
            decodedStrings.add(s.substring(index, index + size));
            // Move the index past the retrieved string
            index += size;
        }
      
        // Return the list of decoded strings
        return decodedStrings;
    }
}
