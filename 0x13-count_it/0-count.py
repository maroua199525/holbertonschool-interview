#!/usr/bin/python3

""" a recursive function that queries the hot Reddit API """

import requests
"""
a recursive function that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords
(case-insensitive, delimited by spaces.
Javascript should count as javascript, but java should not).

"""


def count_words(subreddit, word_list, after='', words_counting={}):
    """ Word counting function """

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'custom'}
    payload = {'limit': '100', 'after': after}
    response = requests.get(url, headers=headers,
                            params=payload, allow_redirects=False)

    if not response.status_code == 200:
        return
    data = response.json().get('data')
    after = data.get('after')
    children_list = data.get('children')

    for child in children_list:
        title = child.get('data').get('title')
        for word in word_list:
            ocurrences = title.lower().split().count(word.lower())
            if ocurrences > 0:
                if word in words_counting:
                    words_counting[word] += ocurrences
                else:
                    words_counting[word] = ocurrences

    if after is not None:
        return count_words(subreddit, word_list, after, words_counting)
    else:
        if not len(words_counting) > 0:
            return
        iterator = sorted(words_counting.items(),
                          key=lambda kv: (-kv[1], kv[0]))
        for key, value in iterator:
            print('{}: {}'.format(key.lower(), value))
