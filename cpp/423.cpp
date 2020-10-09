// ugly.cpp
class Solution {
public:
  string originalDigits(string s) {
    unordered_map<int, int> hashmap;
    for (auto ch : s)
      hashmap[ch]++;
    string res;
    int count;

    count = hashmap['z'];
    res.append(count, '0');
    //        hashmap['z']-=count;
    hashmap['e'] -= count;
    hashmap['r'] -= count;
    hashmap['o'] -= count;

    count = hashmap['g'];
    res.append(count, '8');
    hashmap['e'] -= count;
    hashmap['i'] -= count;
    //        hashmap['g']-=count;
    hashmap['h'] -= count;
    hashmap['t'] -= count;

    count = hashmap['x'];
    res.append(count, '6');
    hashmap['s'] -= count;
    hashmap['i'] -= count;
    //        hashmap['x']-=count;

    count = hashmap['w'];
    res.append(count, '2');
    hashmap['t'] -= count;
    //        hashmap['w']-=count;
    hashmap['o'] -= count;

    count = hashmap['u'];
    res.append(count, '4');
    hashmap['f'] -= count;
    hashmap['o'] -= count;
    //        hashmap['u']-=count;
    hashmap['r'] -= count;

    count = hashmap['s'];
    res.append(count, '7');
    //        hashmap['s']-=count;
    hashmap['e'] -= count;
    hashmap['v'] -= count;
    hashmap['e'] -= count;
    hashmap['n'] -= count;

    count = hashmap['v'];
    res.append(count, '5');
    hashmap['f'] -= count;
    hashmap['i'] -= count;
    //        hashmap['v']-=count;
    hashmap['e'] -= count;

    count = hashmap['h'];
    res.append(count, '3');
    hashmap['t'] -= count;
    //        hashmap['h']-=count;
    hashmap['r'] -= count;
    hashmap['e'] -= count;
    hashmap['e'] -= count;

    count = hashmap['o'];
    res.append(count, '1');
    //        hashmap['o']-=count;
    hashmap['n'] -= count;
    hashmap['e'] -= count;

    count = hashmap['i'];
    res.append(count, '9');
    sort(res.begin(), res.end());
    return res;
  }
};
