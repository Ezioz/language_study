from croe.http_re import http_req
from config.config import Config

##ip反查域名
def ip_ck_domain(ip):
    url = "https://api.zoomeye.org/domain/search?q={}&type=0&page=1".format(ip)
    key = Config.ZOOMEYE_KEY
    headers = {'API-KEY':key}
    conn = http_req(url,headers=headers)
    data = conn.json()
    if data['total'] > 0 :
        domain_ip = data['list'][0]['name']
        return domain_ip