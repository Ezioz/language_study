from croe.file import append_file, load_file, clear_empty
from utils.fofa_Client import fetch_app
from croe.ThreadMap import thread_map
from poc.yonyou_nc_bsh import poc
from urllib.parse import urlparse
from tld import get_fld
from utils.ip_ck_domain import ip_ck_domain
from utils.icp_scan import icp_scan
from croe.isIP import isIP
from utils.vulbox_sub import vulbox_sub
from config.vulbox_config import Vu_Config

ok_domain = set()


def fofa(app):
    fofa_app = fetch_app(app)
    return fofa_app

def scan_poc(fofa_domain,age):
    ok_domain.add(poc(fofa_domain))


def run(fofa_domain,age):
    try:
        poc_list = poc(fofa_domain)
        if poc_list != None:
            o = urlparse(poc_list[0])
            domain = o.netloc.split(':')[0]
            is_ip_domain = isIP(domain)
            if is_ip_domain == True:
                bug_title = domain + " " + Vu_Config.bug_title
                #print(bug_title)
                bug_firm_url = ip_ck_domain(domain)
                if bug_firm_url != None:
                    bug_firm_name = icp_scan(bug_firm_url)
                    vulbox_sub(url_path=poc_list[0],bug_title=bug_title,poc_data=poc_list[1],bug_firm_name=bug_firm_name,bug_firm_url=bug_firm_url)

            else:
                get_fdomain = get_fld(domain, fix_protocol=True)
                bug_title = domain + " " + Vu_Config.bug_title
                bug_firm_name = icp_scan(get_fdomain)
                #print(bug_title)
                if bug_firm_name != None:
                    bug_firm_url = get_fdomain
                    vulbox_sub(url_path=poc_list[0],bug_title=bug_title,poc_data=poc_list[1],bug_firm_name=bug_firm_name,bug_firm_url=bug_firm_url)
        else:
            print("无漏洞",fofa_domain)

    except Exception as e:
        print(e)

#fofa_domain = fofa("YONYOU-NC")
#thread_map(run, fofa_domain, 5)
run("https://www.baidu.com",1)