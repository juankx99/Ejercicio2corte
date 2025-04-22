#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

class Twitter {
    private:
        int timestamp;
        unordered_map<int, unordered_set<int>> following; // usuario -> conjunto de seguidos
        unordered_map<int, deque<pair<int, int>>> tweets; // usuario -> deque de (timestamp, tweetId)
        static const int FEED_LIMIT = 10;
    
    public:
        Twitter() {
            timestamp = 0;
        }
        
        void postTweet(int userId, int tweetId) {
            timestamp++;
            tweets[userId].emplace_front(timestamp, tweetId);
            if (tweets[userId].size() > FEED_LIMIT) {
                tweets[userId].pop_back(); // mantenemos solo los 10 más recientes por usuario
            }
        }
        
        vector<int> getNewsFeed(int userId) {
            auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first > b.first; // ordenamos por tiempo (mínimo primero)
            };
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
            
            unordered_set<int> users = following[userId];
            users.insert(userId); // incluir al propio usuario
    
            for (int uid : users) {
                for (const auto& tweet : tweets[uid]) {
                    minHeap.push(tweet);
                    if (minHeap.size() > FEED_LIMIT) {
                        minHeap.pop();
                    }
                }
            }
    
            vector<int> feed;
            while (!minHeap.empty()) {
                feed.push_back(minHeap.top().second);
                minHeap.pop();
            }
            reverse(feed.begin(), feed.end()); // para que estén del más reciente al más antiguo
            return feed;
        }
        
        void follow(int followerId, int followeeId) {
            if (followerId != followeeId) {
                following[followerId].insert(followeeId);
            }
        }
        
        void unfollow(int followerId, int followeeId) {
            following[followerId].erase(followeeId);
        }
    };
    
int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    cout << "User 1's feed: ";
    vector<int> feed = twitter.getNewsFeed(1);
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;

    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    cout << "User 1's feed after following User 2: ";
    feed = twitter.getNewsFeed(1);
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;

    twitter.unfollow(1, 2);
    cout << "User 1's feed after unfollowing User 2: ";
    feed = twitter.getNewsFeed(1);
    for (int tweet : feed) {
        cout << tweet << " ";
    }
    cout << endl;

    return 0;
}