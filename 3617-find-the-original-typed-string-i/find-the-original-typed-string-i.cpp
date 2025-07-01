class Solution {
public:
    int possibleStringCount(string word) {
        int c=0;
        for(int i=0;i<word.length()-1;i++){
            if(word[i]==word[i+1])
            c++;
        }

        return c+1; // case when she wanted to type the word as it is, no mistakes
    }
};