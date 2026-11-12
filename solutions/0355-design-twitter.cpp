// 355. Design Twitter
// https://leetcode.com/problems/design-twitter/

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Twitter {
 public:
  Twitter() = default;

  void postTweet(int userId, int tweetId) {
    tweets_[userId].push_back(std::make_pair(time_, tweetId));
    ++time_;
  }

  std::vector<int> getNewsFeed(int userId) const {
    Feed feed;

    if (auto it = tweets_.find(userId); it != tweets_.end())
      scan(feed, it->second);
    if (auto it = following_.find(userId); it != following_.end()) {
      for (int followeeId : it->second) {
        if (auto jt = tweets_.find(followeeId); jt != tweets_.end())
          scan(feed, jt->second);
      }
    }

    std::vector<int> feed_tweets;
    feed_tweets.reserve(feed_size);

    while (!feed.empty()) {
      feed_tweets.push_back(feed.top().second);
      feed.pop();
    }
    std::ranges::reverse(feed_tweets);

    return feed_tweets;
  }

  void follow(int followerId, int followeeId) {
    if (followerId == followeeId) return;

    following_[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId) return;

    following_[followerId].erase(followeeId);
  }

 private:
  using Tweet = std::pair<int, int>;  // time, tweetId
  using Feed =
      std::priority_queue<Tweet, std::vector<Tweet>, std::greater<Tweet>>;

  static constexpr size_t feed_size = 10;
  int time_ = 0;
  std::unordered_map<int, std::vector<Tweet>> tweets_;
  std::unordered_map<int, std::unordered_set<int>> following_;

  static bool update(Feed& pq, const Tweet& tweet) {
    if (pq.size() == feed_size && tweet.first <= pq.top().first) return false;

    pq.push(tweet);
    if (pq.size() > feed_size) pq.pop();

    return true;
  }

  static void scan(Feed& feed, const std::vector<Tweet>& tweets) {
    const int n = static_cast<int>(tweets.size());
    for (int i = n - 1; i >= 0; --i) {
      if (!update(feed, tweets[i])) break;
    }
  }
};

int main() {
  Twitter t1;
  t1.postTweet(1, 5);
  test(t1.getNewsFeed(1), {5});
  t1.follow(1, 2);
  t1.postTweet(2, 6);
  test(t1.getNewsFeed(1), {6, 5});
  t1.unfollow(1, 2);
  test(t1.getNewsFeed(1), {5});

  Twitter t2;
  for (int i = 1; i <= 15; ++i) t2.postTweet(1, i);
  test(t2.getNewsFeed(1), {15, 14, 13, 12, 11, 10, 9, 8, 7, 6});

  Twitter t3;
  t3.follow(1, 2);
  for (int i = 1; i <= 10; ++i) t3.postTweet(2, i);
  t3.postTweet(1, 100);
  test(t3.getNewsFeed(1), {100, 10, 9, 8, 7, 6, 5, 4, 3, 2});
}