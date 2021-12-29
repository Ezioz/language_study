import random
from croe.conf import Conf
import requests
from requests.models import PreparedRequest
from urllib.parse import urlsplit

UA = "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.45 Safari/537.36"
# http 请求封装函数
def http_req(url, method='get', **kwargs):
    if kwargs.get("disable_normal"):
        # 禁用 URL 规范化处理，仅仅支持GET
        kwargs.pop("disable_normal")
        return req_disable_normal(url, method, **kwargs)

    kwargs.setdefault('verify', False)
    kwargs.setdefault('timeout', (Conf.CONNECT_TIMEOUT, Conf.READ_TIMEOUT))
    kwargs.setdefault('allow_redirects', False)

    headers = kwargs.get("headers", {})
    if headers is None:
        headers = {}

    headers.setdefault("User-Agent", UA)

    random_ip = "10.0.{}.{}".format(random.randint(1, 254), random.randint(1, 254))
    headers.setdefault("X-Real-IP", random_ip)
    headers.setdefault("X-Forwarded-For", random_ip)

    kwargs["headers"] = headers

    proxies = {
        'https': Conf.PROXY_URL,
        'http': Conf.PROXY_URL
    }

    if Conf.PROXY_URL:
        kwargs["proxies"] = proxies

    conn = getattr(requests, method)(url, **kwargs)

    return conn
# 禁用规范化URL处理
# 下面这个函数在开代理的情况下依然是没有用的
def req_disable_normal(url, method='get', **kwargs):
    headers = kwargs.get("headers", {})
    if headers is None:
        headers = {}

    headers.setdefault("User-Agent", UA)

    kwargs["headers"] = headers

    req = requests.Request(method=method, url=url, **kwargs)
    prep = req.prepare()
    prep.url = url

    proxies = {}

    if Conf.PROXY_URL:
        proxies = {
            'http': Conf.PROXY_URL,
            'https': Conf.PROXY_URL
        }

    if "#" in url:
        my_prep = MyPreparedRequest()
        my_prep.prepare(method='GET', url=url)
        my_prep.url = url
        prep = my_prep

    with requests.Session() as session:
        return session.send(prep, verify=False, proxies=proxies, allow_redirects=False,
                            timeout=(Conf.CONNECT_TIMEOUT, Conf.READ_TIMEOUT))
class MyPreparedRequest(PreparedRequest):
    def __init__(self):
        super().__init__()

    @property
    def path_url(self):
        url = []

        p = urlsplit(self.url, allow_fragments=False)

        path = p.path
        if not path:
            path = '/'

        url.append(path)

        query = p.query
        if query:
            url.append('?')
            url.append(query)

        return ''.join(url)