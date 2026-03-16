#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
public:

    int capacity;
    int minFreq;

    unordered_map<int, pair<int,int>> keyValFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyIter;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {

        if(keyValFreq.count(key)==0)
            return -1;

        int value = keyValFreq[key].first;
        int freq = keyValFreq[key].second;

        freqList[freq].erase(keyIter[key]);

        if(freqList[freq].empty() && freq == minFreq)
            minFreq++;

        freq++;

        freqList[freq].push_front(key);
        keyIter[key] = freqList[freq].begin();

        keyValFreq[key].second = freq;

        return value;
    }

    void put(int key, int value) {

        if(capacity == 0)
            return;

        if(keyValFreq.count(key)){

            keyValFreq[key].first = value;
            get(key);
            return;
        }

        if(keyValFreq.size() == capacity){

            int evict = freqList[minFreq].back();

            freqList[minFreq].pop_back();

            keyValFreq.erase(evict);
            keyIter.erase(evict);
        }

        keyValFreq[key] = {value,1};

        freqList[1].push_front(key);

        keyIter[key] = freqList[1].begin();

        minFreq = 1;
    }
};
