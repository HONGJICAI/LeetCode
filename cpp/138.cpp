// noExtraSpace.cpp
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *tmp_head = new RandomListNode(-1);
    for (auto *cur = head; cur; cur = cur->next->next) {
      RandomListNode *copy = new RandomListNode(cur->label);
      copy->next = cur->next;
      cur->next = copy;
    }
    for (auto *cur = head; cur; cur = cur->next->next) {
      if (cur->random)
        cur->next->random = cur->random->next;
    }
    for (auto *cur = head, *copy = tmp_head; cur;
         cur = cur->next, copy = copy->next) {
      copy->next = cur->next;
      cur->next = cur->next->next;
    }
    return tmp_head->next;
  }
};
// scanTWice-60ms.cpp
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    unordered_map<RandomListNode *, int> hash;
    vector<RandomListNode *> arr;
    int count = 0;
    for (auto p = head; p != nullptr; p = p->next) {
      auto n = new RandomListNode(p->label);
      if (count)
        arr.back()->next = n;
      arr.push_back(n);
      hash[p] = count++;
    }
    count = 0;
    for (auto p = head; p != nullptr; p = p->next, ++count) {
      if (p->random) {
        auto index = hash[p->random];
        arr[count]->random = arr[index];
      }
    }
    return arr.size() ? arr[0] : nullptr;
  }
};
