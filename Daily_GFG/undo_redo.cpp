class Solution {
  public:
    string str;
  vector<char> vec;
    void append(char x) {
        // append x into document
        str.push_back(x);
    }

    void undo() {
        // undo last change
        vec.push_back(str[str.size() - 1]);
        str.pop_back();
    }

    void redo() {
        // redo changes
        if(vec.size() == 0) return;
        str.push_back(vec[vec.size() - 1]);
        vec.pop_back();
    }

    string read() {
        // read the document
        return str;
    }
};
