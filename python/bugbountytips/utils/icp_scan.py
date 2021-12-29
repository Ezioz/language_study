from croe.file import append_file, load_file, clear_empty
from croe.http_re import http_req


##域名查备案
def icp_scan(domain):
    url = "https://apidatav2.chinaz.com/single/icp?key=096268861e0342cdac43982d4b5169e1&domain={}".format(domain)
    conn = http_req(url)
    data = conn.json()
    #print(data['Result']['MainPage'],data['Result']['CompanyName'])
    #print(type(data['Result']['CompanyName']))
    if data['Result'] == None:
        return None
    else:
        return data['Result']['CompanyName']