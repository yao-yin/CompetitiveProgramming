 # My solutions to the ant book (プログラミングコンテストチャレンジブック [第2版], aka 蟻本, aka 白书)

## What is the ant book?
It's a popular competitive programming book in Japan and China.

Amazon link in JP: [蟻本](https://www.amazon.co.jp/%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0%E3%82%B3%E3%83%B3%E3%83%86%E3%82%B9%E3%83%88%E3%83%81%E3%83%A3%E3%83%AC%E3%83%B3%E3%82%B8%E3%83%96%E3%83%83%E3%82%AF-%E7%AC%AC2%E7%89%88-%EF%BD%9E%E5%95%8F%E9%A1%8C%E8%A7%A3%E6%B1%BA%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E6%B4%BB%E7%94%A8%E5%8A%9B%E3%81%A8%E3%82%B3%E3%83%BC%E3%83%87%E3%82%A3%E3%83%B3%E3%82%B0%E3%83%86%E3%82%AF%E3%83%8B%E3%83%83%E3%82%AF%E3%82%92%E9%8D%9B%E3%81%88%E3%82%8B%EF%BD%9E-%E7%A7%8B%E8%91%89%E6%8B%93%E5%93%89/dp/4839941068)
Douban link: [挑战程序设计竞赛](https://book.douban.com/subject/24749842/)

## Motivition

To pass the coding interviews from big tech companies like FAANGMULA, I need to practice LeetCode-like problems. But tbh, I didn't learn much from the LeetCode after a certain stage (my leetcode contest rating is 2435, which is at the top 0.33% on 2022-03-26). Out of the consideration of interests and marginal benefit, I think it's a good idea to learn and practice entry level cp problems. To have an overall impression on cp about general problems and techniques, I chose to follow the ant book. 

## About the problems

I use the [list](https://vjudge.net/article/46) on vjudge to track my effort. However, there are some problems we can't find the OJ like バクテリアの増殖 from Google Code Jam Japan 2011 Final. 

## About the solutions

Nearly all of the code are written by me. But some of them are from the internet, there could be 2 reasons. 

- Most of problems are from POJ (Peking University JudgeOnline). POJ is using very old compilers and machines. It doesn't support the common optimization of STL and might require a tighter constant on implementation. I don't want to waste my time to do constant optimization to please the compilers and machines, especially on C++98. Instead I just use others' solutions with the source and put my code (good enough in time complexity) under it.

- Some problems need long implementations, I don't like that so skipped them for now. I will implement them in the future (gugugu).

## MISCELLANEOUS

### Why is it called 蟻本 (the ant book) in JP?

Because there are 2 ants on the cover and the first problem of the book is Ants ([POJ 1852](https://vjudge.net/problem/POJ-1852)).

### Why is it called 白书 (the white book, 白い本) in China?

Because the cover is in white, people that love OI/ICPC have the convention to call famous cp textbooks with the color of the cover.

### Comments on the book

It's definitely a great book. Problems are great, code in the book is clear and good to learn. But there are some concerns.

- This book is more like an exercise book over textbook. It's good for OI/ACM-ICPC because we don't need to prove our solutions during the contest. However, it's not good for students as the only reference of data structures and algorithms. Students should learn basics from standard textbooks like CLRS or Algorithms, 4th Edition by Robert Sedgewick and Kevin Wayne or Algorithm Design (my favorite) from Kleinberg and Tardos.

- Problems are old and most of them are from POJ. The C++ compilers supported by POJ is out of date and machines are slow. It's okay to practice because these problems are in good qualities but we have much more user friendly OJ to choose for now. Why not solve some problems on them?
  - Codeforces
  - AtCoder
  - Luogu (Chinese)

- If you like the architecture of the book, here are some [articles](https://qiita.com/drken/items/e77685614f3c6bf86f44) from drken with "modern" problems from AtCoder related to the same patterns as those in the ant books.

- Some other great cp books, some books are not listed here just because I don't know them:
  
  - [算法竞赛进阶指南](https://book.douban.com/subject/30136932/)
  - [プログラミングコンテスト攻略のためのアルゴリズムとデータ構造](https://www.amazon.co.jp/-/en/%E6%B8%A1%E9%83%A8-%E6%9C%89%E9%9A%86/dp/4839952957/ref=sr_1_2?crid=18UKNU6Y004TM&keywords=%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0%E3%82%B3%E3%83%B3%E3%83%86%E3%82%B9%E3%83%88&qid=1648255332&s=books&sprefix=%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0%E3%82%B3%E3%83%B3%E3%83%86%E3%82%B9%E3%83%88%2Cstripbooks%2C206&sr=1-2)
  - [問題解決力を鍛える!アルゴリズムとデータ構造] from drken
  - [問題解決のための「アルゴリズム×数学」が基礎からしっかり身につく本](https://www.amazon.co.jp/-/en/%E7%B1%B3%E7%94%B0-%E5%84%AA%E5%B3%BB/dp/4297125218/ref=sr_1_28?crid=18UKNU6Y004TM&keywords=%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0%E3%82%B3%E3%83%B3%E3%83%86%E3%82%B9%E3%83%88&qid=1648255424&s=books&sprefix=%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0%E3%82%B3%E3%83%B3%E3%83%86%E3%82%B9%E3%83%88%2Cstripbooks%2C206&sr=1-28)


Please feel free to contact me if you have any feedbacks.

Email: InYuo1997 at gmail.com

