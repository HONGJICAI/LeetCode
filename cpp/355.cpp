// priority_queue.cpp
class Twitter {
  struct ctx {
    int userId;
    vector<pair<int, int>>::reverse_iterator it;
  };
  struct comp {
    bool operator()(ctx &c1, ctx &c2) { return c1.it->first < c2.it->first; }
  };
  unsigned int time;
  unordered_map<int, vector<pair<int, int>>> feed; // pair<time,tweetId>
  unordered_map<int, unordered_set<int>> following;

public:
  /** Initialize your data structure here. */
  Twitter() : time(0) {}

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    feed[userId].emplace_back(pair<int, int>(time++, tweetId));
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    this->follow(userId, userId);
    priority_queue<ctx, vector<ctx>, comp> qe;
    for (auto &p : following[userId])
      if (feed[p].size())
        qe.push(ctx{p, feed[p].rbegin()});
    vector<int> res;
    for (int i = 0; i < 10 && qe.size(); ++i) {
      ctx c = qe.top();
      qe.pop();
      res.push_back(c.it->second);
      if (++c.it != feed[c.userId].rend())
        qe.push(ctx{c.userId, c.it});
    }
    return res;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    following[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    following[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
