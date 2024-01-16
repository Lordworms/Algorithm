class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
    }
    
    int peek() {
        return nextElement;
    }
    
    int next() {
        int ret = nextElement;
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
        return ret;
    }
    
    bool hasNext() const {
        return flag;
    }
private:
    int nextElement;
    bool flag;
};
