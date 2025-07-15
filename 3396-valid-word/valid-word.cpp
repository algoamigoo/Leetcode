class Solution {
public:

    bool isValid(string word) {
        int c=0,f=0;
        for(auto x : word){

        if(x == 'a' || x == 'e' || x == 'i' || x == 'o'
        || x == 'u' || x == 'A' || x == 'E' || x == 'I'
        || x == 'O' || x == 'U')
        c=1;
        else if(isalpha(x))
        f=1;

        if(!isalpha(x) && !isdigit(x))
        return false;
        }

    if(f==1 && c==1 && word.length()>=3)
    return true;
    return false;
    }
};