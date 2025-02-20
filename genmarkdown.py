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
![Build](https://github.com/HONGJICAI/LeetCode/actions/workflows/ci-cpp.yml/badge.svg)

# LeetCode

my solution for LeetCode

# Problem List

| id | title | language | difficulty |
| ---- | ---- | ---- | ---- |
'''
difficultyMap = {1: 'easy', 2: 'medium', 3: 'hard'}
solvedIds = {}
for f in os.listdir('cpp') + os.listdir('sql'):
    id, ext = os.path.splitext(f)
    ext = ext[1:]
    if str.isdigit(id):
        if int(id) not in solvedIds:
            solvedIds[int(id)] = f'[{ext}]({ext}/{id}.{ext})'
        else:
            solvedIds[int(id)] += f' [{ext}]({ext}/{id}.{ext})'

for problem in filter(lambda x: int(x['id']) <= max(solvedIds), problems):
    id = problem['id']
    language = solvedIds[id] if id in solvedIds else ''
    md += f"| {id} | {problem['title']} | {language} | {difficultyMap[problem['difficulty']]} |\n"

with open('README.md', 'w') as f:
    f.write(md)
