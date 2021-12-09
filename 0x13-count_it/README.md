# #0x13. Count it!
## A recursive function that queries the Reddit API, parses the title of all hot articles, and prints a sorted count of given keywords

* def count_words(subreddit, word_list)
* Results are printed in descending order, by the count, and if the count is the same for separate keywords, they are sorted alphabetically
* Results are based on the number of times a keyword appears, not titles it appears in. java java java counts as 3 separate occurrences of java.
* If no posts match or the subreddit is invalid, print nothing.
