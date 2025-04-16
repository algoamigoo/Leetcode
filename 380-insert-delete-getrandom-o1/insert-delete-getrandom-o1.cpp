class RandomizedSet {
public:
    set<int> rset;
    unordered_map<int,int> map;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(map.count(val)==1)
        return false;
        
        rset.insert(val);
        map[val]++;
        return true;
    }
    
    bool remove(int val) {
        if(map.count(val)==0)
        return false;
        map[val]--;
        if(map[val]==0)
        {rset.erase(val);
        map.erase(val);}
        return true;
    }
    
    int getRandom() {
        if(rset.size()==0)
        return NULL;
        int x = rand()%rset.size();
        return *next(rset.begin(), x);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */