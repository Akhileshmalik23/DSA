class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3)
            return false;

        int vowel = 0, consonant = 0;

        for (char c : word) {
            if (!isalnum(c))  
                return false;

            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowel++;
            } else if (isalpha(c)) {
                consonant++;
            }
        }

        return vowel > 0 && consonant > 0;
    }
};
