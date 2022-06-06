#!/usr/bin/python3

import requests
"""
a recursive function that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords
(case-insensitive, delimited by spaces.
Javascript should count as javascript, but java should not).

"""


def count_words(subreddit, word_list, after='', count={}):
    """Queries the Reddit API and returns all hot posts
    of the subreddit"""
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'custom'}
    payload = {'limit': '100', 'after': after}
    response = requests.get(url, headers=headers,
                            params=payload, allow_redirects=False)

    if response.status_code != 200:
        return
    data = response.json().get('data')
    after = data['after']
    children_list = data['children']
    for child in children_list:
        title = child['data']['title']
        for word in word_list:
            n = title.lower().split().count(word.lower())
            if n > 0:
                if word in count:
                    count[word] += n
                else:
                    count[word] = n

    if after is not None:
        return count_words(subreddit, word_list, after, count)
    else:
        if not len(count) > 0:
            return
        sort = sorted(count.items(), key=lambda kv: (-kv[1], kv[0]))
        for key, value in sort:
            print('{}: {}'.format(key.lower(), value))
