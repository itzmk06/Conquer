// substring generation

// using traditional way 
for (int i = 0; i < s.length(); i++) {      // Start index
    for (int j = i; j < s.length(); j++) {  // End index
        string substring = s.substr(i, j - i + 1);
        cout << substring << endl;
    }
}

// using dynamic sliding window 
for (int start = 0; start < s.length(); start++) {
    string current = "";  // Start with an empty substring
    for (int end = start; end < s.length(); end++) {
        current += s[end];  // Expand the substring by adding the next character
        cout << current << endl;
    }
}
