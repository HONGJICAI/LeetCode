class Solution { // Runtime: 28 ms, faster than 97.38% of C++ online submissions
                 // for Unique Email Addresses.
public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> unique;
    for (auto &e : emails) {
      auto pivot = e.find_first_of('@');
      auto name = e.substr(0, pivot), domain = e.substr(pivot);
      name.erase(remove(name.begin(), name.end(), '.'), name.end());
      auto pos = name.find_first_of('+');
      unique.insert((pos != string::npos) ? name.substr(0, pos) + domain
                                          : name + domain);
    }
    return unique.size();
  }
};