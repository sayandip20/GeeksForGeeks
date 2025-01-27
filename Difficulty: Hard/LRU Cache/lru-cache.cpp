//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
private:
    std::list<int> dll; 
    std::map<int, std::pair<std::list<int>::iterator, int>> mp; 
    int cap; 

public:
    LRUCache(int cap) {
        this->cap = cap;
    }

    void pushToFront(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin(); 
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        pushToFront(key);
        return mp[key].second; 
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            pushToFront(key); 
        } else {
            dll.push_front(key); 
            mp[key] = {dll.begin(), value}; 
            --cap; 
        }

        if (cap < 0) {
            int delKey = dll.back();
            dll.pop_back(); 
            mp.erase(delKey); 
            ++cap; 
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends