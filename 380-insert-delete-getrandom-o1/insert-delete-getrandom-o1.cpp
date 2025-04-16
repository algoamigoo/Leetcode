class RandomizedSet {
public:
    vector<int> elements; // Stores the elements
    unordered_map<int, int> map; // Maps value to its index in elements
    RandomizedSet() {
        srand(time(0)); // Seed random number generator
    }
    
    bool insert(int val) {
        if (map.count(val) && map[val] >= 0) // Value exists at a valid index
            return false;
        
        elements.push_back(val); // Add to vector
        map[val] = elements.size() - 1; // Store index
        return true;
    }
    
    bool remove(int val) {
        if (!map.count(val) || map[val] < 0) // Value doesn't exist or was removed
            return false;
        
        int index = map[val]; // Get index of val
        int lastVal = elements.back(); // Get last element
        
        // Move last element to index of val
        elements[index] = lastVal;
        map[lastVal] = index;
        
        // Remove val
        elements.pop_back();
        map[val] = -1; // Mark as removed (or erase: map.erase(val))
        
        return true;
    }
    
    int getRandom() {
        if (elements.empty())
            throw runtime_error("NULL");
        
        int x = rand() % elements.size();
        return elements[x];
    }
};