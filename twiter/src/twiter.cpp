/**
 * @file twiter.cpp
 * @brief Implementación de la clase Twitter para simular una red social básica.
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @class Twitter
 * @brief Clase que representa una red social donde los usuarios pueden publicar tweets, seguir a otros usuarios y obtener un feed de noticias.
 */
class Twitter {
    private:
        int timestamp; /**< Marca de tiempo para ordenar los tweets. */
        unordered_map<int, unordered_set<int>> following; /**< Mapa de usuarios y los usuarios que siguen. */
        unordered_map<int, deque<pair<int, int>>> tweets; /**< Mapa de usuarios y sus tweets con marca de tiempo. */
        static const int FEED_LIMIT = 10; /**< Límite de tweets en el feed de noticias. */

    public:
        /**
         * @brief Constructor de la clase Twitter.
         */
        Twitter() {
            timestamp = 0;
        }
        
        /**
         * @brief Publica un tweet para un usuario dado.
         * @param userId ID del usuario que publica el tweet.
         * @param tweetId ID del tweet que se publica.
         */
        void postTweet(int userId, int tweetId) {
            timestamp++;
            tweets[userId].emplace_front(timestamp, tweetId);
            if (tweets[userId].size() > FEED_LIMIT) {
                tweets[userId].pop_back(); // mantenemos solo los 10 más recientes por usuario
            }
        }
        
        /**
         * @brief Obtiene el feed de noticias de un usuario.
         * @param userId ID del usuario cuyo feed se solicita.
         * @return Vector con los IDs de los tweets en el feed.
         */
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
        
        /**
         * @brief Permite que un usuario siga a otro.
         * @param followerId ID del usuario que sigue.
         * @param followeeId ID del usuario a seguir.
         */
        void follow(int followerId, int followeeId) {
            if (followerId != followeeId) {
                following[followerId].insert(followeeId);
            }
        }
        
        /**
         * @brief Permite que un usuario deje de seguir a otro.
         * @param followerId ID del usuario que deja de seguir.
         * @param followeeId ID del usuario a dejar de seguir.
         */
        void unfollow(int followerId, int followeeId) {
            following[followerId].erase(followeeId);
        }
};

/**
 * @brief Función principal para probar la funcionalidad de la clase Twitter.
 * @return 0 si la ejecución es exitosa.
 */
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