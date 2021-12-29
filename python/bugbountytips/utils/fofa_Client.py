import base64
from croe.http_re import http_req
from config.config import Config
from croe.file import append_file


class FofaClient:
    def __init__(self, email, key, page_size = 9999):
        self.email = email
        self.key = key
        self.base_url = "https://fofa.so"
        self.search_api_url = "/api/v1/search/all"
        self.page_size = page_size #终身用户
        self.param = {}

    def fofa_search_all(self, query):
        qbase64 = base64.b64encode(query.encode())
        param = {
            "email": self.email,
            "key": self.key,
            "qbase64": qbase64.decode('utf-8'),
            "size": self.page_size
        }

        self.param = param
        data =  self._api(self.base_url + self.search_api_url)
        return data

    def _api(self, url):
        data =  http_req(url, 'get', params = self.param).json()
        return data


    def search_cert(self, cert):
        query = 'domain="{}"'.format(cert)
        data = self.fofa_search_all(query)
        if data["error"] and data["errmsg"]:
            raise Exception(data["errmsg"])

        results = data["results"]
        return results
    def search_ip(self, cert):
        query = 'ip="{}"'.format(cert)
        data = self.fofa_search_all(query)
        if data["error"] and data["errmsg"]:
            raise Exception(data["errmsg"])

        results = data["results"]
        return results
    def search_app(self, cert):
        query = 'app="{}"'.format(cert)
        data = self.fofa_search_all(query)
        if data["error"] and data["errmsg"]:
            raise Exception(data["errmsg"])

        results = data["results"]
        return results
def fetch_domain(cert, size=9999):
    ip_set = set()

    try:
        client = FofaClient(Config.FOFA_EMAIL, Config.FOFA_KEY, page_size=size)
        items = client.search_cert(cert)
        for item in items:
            ip_set.add(item[0].strip("https://").strip("http://").split(':')[0])
    except Exception as e:
        print(e)
    print(ip_set)
def fetch_ip(cert, size=9999):
    ip_set = set()

    try:
        client = FofaClient(Config.FOFA_EMAIL, Config.FOFA_KEY, page_size=size)
        items = client.search_ip(cert)
        print(items)
        for i in range(len(items)):
            print(items[i])
            if "http" in items[i][0]:
                ip_set.add(items[i][0])
    except Exception as e:
        print(e)
    print(ip_set)
def fetch_app(app, size=9999):
    ip_set = set()

    try:
        client = FofaClient(Config.FOFA_EMAIL, Config.FOFA_KEY, page_size=size)
        items = client.search_app(app)
        for i in range(len(items)):
            if "http" in items[i][0]:
                ip_set.add(items[i][0])
            else:
                ip_set.add("http://"+items[i][0])
    except Exception as e:
        print(e)
    return ip_set