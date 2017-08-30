class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        stringstream ss(sentence);
        vector<string>res;
        string word;
        while(!ss.eof()){
            ss>>word;
            res.emplace_back(word);
        }
        for(auto d:dict)
            for(auto &w:res)
                if(w.find(d)==0)
                    w=d;
        word="";
        for(auto w:res)
            word+=w+" ";
        word.pop_back();
        return word;
    }
};
