from croe.http_re import http_req
from croe.file import append_file, load_file, clear_empty
from croe.ThreadMap import thread_map
from requests_toolbelt.utils import dump


def poc(domain):
    path = "/servlet/~ic/bsh.servlet.BshServlet"
    url = domain + path
    conn = http_req(url)
    if b">BeanShell Test Servlet<" in conn.content:
        print("found 用友NC RCE {}".format(domain))
        request_data = dump.dump_all(conn)
        return url,request_data.decode('utf-8')
    else:
        return None