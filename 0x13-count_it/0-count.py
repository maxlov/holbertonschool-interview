#!/usr/bin/python3
'''
Gets top 10 hot posts of subreddit
'''
import requests


def count_words(subreddit, word_list):
    ''' Gets count of occurances of word in word list '''
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-Agent':
               'Python:title.parser:v0.1 (by /u/01100100011011110111)'}
    payload = {'limit': 100}
    res = requests.get(url, headers=headers, allow_redirects=False,
                       params=payload)

    word_counter = {}
    for word in word_list:
        word_counter[word.lower()] = 0

    try:
        count_word_recur(res.json()['data']['children'], word_counter)
    except Exception as e:
        print(None)
    
    sorted_count = sorted(word_counter.items(), key=lambda x: (-x[1], x[0]))
    for item in sorted_count:
        if item[1] > 0:
            print("{}: {}".format(item[0], item[1]))


def count_word_recur(posts, word_counter):
    ''' Recursively counts of occurances of word in word list '''
    if not posts:
        return
    for word in posts[0]['data']['title'].split():
        if word.lower() in word_counter.keys():
            word_counter[word.lower()] += 1
    count_word_recur(posts[1:], word_counter)
