from croe.http_re import http_req
from croe.img_upload_obs import img_upload_obs
from urllib.parse import quote
from config.vulbox_config import Vu_Config

import re


cookie = Vu_Config.vu_cookie
headers = {'Cookie':cookie}
headers_hd = {'Cookie':cookie,'Content-Type':'application/x-www-form-urlencoded; charset=UTF-8'}
url = "https://www.vulbox.com/user/submit-72"
def msgToken():
    conn = http_req(url, headers=headers)
    return re.findall(r"value=\"([a-f0-9]{8})\"", conn.text)[0]

def replace_html(s):
    s = s.replace('&', '&amp;')
    s = s.replace('<', '&lt;')
    s = s.replace('>', '&gt;')
    s = s.replace(' ', '&nbsp;')
    return s

def vulbox_sub(url_path,bug_title,bug_firm_name,bug_firm_url,poc_data,httpzt = 'get'):
    Token = msgToken()
    bug_description = Vu_Config.bug_description
    if httpzt == 'get':
        img_url = img_upload_obs(url_path)
    else:
        img_url = ""
    bug_Request = poc_data
    bug_jiewei = Vu_Config.bug_jiewei
    bug_content = '<p>URL：<br></p><pre><code>{0}</code></p></pre><br><p>访问poc：<br></p><pre><code>{1}</code></p></pre><p><img alt="Image" src="{2}"><br></p><p>{3}</p>'.format(url_path,replace_html(bug_Request),img_url,bug_jiewei)
    bug_repair = "<p>{0}</p>".format(Vu_Config.bug_repair)
    data = "Token={0}&task_id=72&bug_title={1}&bug_internet_type=1&bug_star=0&bug_firm_name={2}&bug_firm_url={3}&bug_level=3&manu=3&AV=A&AC=H&PR=L&UI=R&S=C&C=H&I=H&A=H&E=X&RL=X&RC=X&CR=X&IR=X&AR=X&MAV=X&MAC=X&MPR=X&MUI=X&MS=X&MC=X&MI=X&MA=X&bug_description={4}&bug_url=&bug_parameter=&bug_poc=&bug_equipment=&bug_platform=&bug_version=&bug_star_desc=&bug_content={5}&bug_additional=&bug_repair={6}&task=互联网/移动互联网/电子商务&hangye=互联网&checkbox=on&bug_type=5&id=72&industry=互联网/移动互联网/电子商务&area=北京/北京市/东城&son_industry=互联网".format(Token,quote(bug_title, 'utf-8'),quote(bug_firm_name, 'utf-8'),quote(bug_firm_url, 'utf-8'),quote(bug_description, 'utf-8'),quote(bug_content, 'utf-8'),quote(bug_repair, 'utf-8'))
    print(url_path," 提交报告成功")
    conn = http_req(url, method='post', headers=headers_hd,data=data.encode())
