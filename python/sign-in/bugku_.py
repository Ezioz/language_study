#-*- coding:utf-8 -*-

import requests

def bugku(headers):
    bugku_headers = {
        'Host': 'ctf.bugku.com',
        'X-CSRF-TOKEN': 'e9001bdfe269e8faaa854bee6fe6e7ab',
        'Referer': 'https://ctf.bugku.com/',
        'Cookie': '__yjs_duid=1_189bb4c002b38de99ce31406c13ce5681621583401541; autoLogin=kIsL5d9Gi342hQQsxG98rnS9Z0dSe7yDQ66KRg2MjN4RCuAQkGMdGTGaWMD8%2B3gx4BC8uiz%2FMK6VzcAIa%2BrYjuw2E1AfTCjyA1ZOCPglzkkEZCJ8rNMb1BfiNg2WsgXqUgludbEVzG2n; PHPSESSID=5cb2e6946cfdb31dbb9b2fc84c631484; think_lang=zh-cn; X-CSRF-TOKEN=36bcbb2bf560d7fa466eb0257930b3b4',
    }
    bugku_url = 'https://ctf.bugku.com/user/checkin'
    result = requests.get(url=bugku_url, headers=dict(headers, **bugku_headers))
    print(result.content.decode('utf-8'))
    # return result.content.decode('utf-8')

    