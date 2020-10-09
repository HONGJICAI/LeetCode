import os

import requests

print('reading problems list...')
api = "https://leetcode.com/api/problems/all/"
r = requests.get(api)

j = r.json()
problems = [{'id': problem['stat']['question_id'], 'title': problem['stat']['question__title'], 'difficulty':problem['difficulty']['level'], 'vip':problem['paid_only']}
            for problem in j['stat_status_pairs']]
problems.sort(key=lambda x: x['id'])

print('generate markdown...')
md = '''
# LeetCode

my solution for LeetCode

# Problem List

| id | title | language | difficulty |
| ---- | ---- | ---- | ---- |
'''
difficultyMap = {1: 'easy', 2: 'medium', 3: 'hard'}
solvedCpps = set(filter(lambda x: str.isdigit(x) ,[f.split('.')[0] for f in os.listdir('cpp')]))

for problem in problems:
    id = str(problem['id'])
    language = f'[cpp](cpp/{id}.cpp)' if id in solvedCpps else ''
    md += f"| {id} | {problem['title']} | {language} | {difficultyMap[problem['difficulty']]} |\n"

with open('README.md', 'w') as f:
    f.write(md)
