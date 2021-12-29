import os
import logging
import tempfile


class Conf(object):
    """运行配置类"""

    """源码目录"""
    PROJECT_DIRECTORY = os.path.abspath(os.path.dirname(__file__))

    """系统插件目录"""
    SYSTEM_PLUGINS_DIR = os.path.join(PROJECT_DIRECTORY, "plugins")

    """用户自定义目录"""
    USER_PLUGINS_DIR = None

    """代理地址"""
    PROXY_URL = None

    """TXT格式保存文件名"""
    SAVE_TEXT_RESULT_FILENAME = "npoc_result_txt.txt"

    """JSON格式保存文件名"""
    SAVE_JSON_RESULT_FILENAME = "npoc_result_json.txt"

    """DATABASE DIRECTORY"""
    SYSTEM_DATABASE_DIR = os.path.join(PROJECT_DIRECTORY, "database")

    """DNS LOG DB"""
    DNS_LOG_DB = os.path.join(SYSTEM_DATABASE_DIR, "db_log.db")

    DUMP_RESULT_REQ_FLAG = False

    """连接超时时间"""
    CONNECT_TIMEOUT = 8.1
    """读取超时时间"""
    READ_TIMEOUT = 50.1

    """日志等级"""
    LOGGER_LEVEL = logging.INFO

    SUCCESS_LEVEL = 51

    """临时目录"""
    TEMP_DIR = tempfile.gettempdir()

    """HTTP AUTH TOKEN"""
    HTTP_API_AUTH_TOKEN = ''

    """HTTP API TEST"""
    HTTP_API_AUTH_ENABLE = False

    """EXTERNAL BINARY DIRECTORY"""
    SYSTEM_BINARY_DIR = os.path.join(PROJECT_DIRECTORY, "external")

    """JNDI LISTENER PATH"""
    JNDI_LISTENER_PATH = os.path.join(SYSTEM_BINARY_DIR, "jndi_listener-1.0-SNAPSHOT-all.jar")

    """MARSHALSEC JAR PATH"""
    MARSHALSEC_PATH = os.path.join(SYSTEM_BINARY_DIR, "marshalsec-0.0.3-SNAPSHOT-all.jar")

    """RMI LISTEN PORT"""
    RMI_PORT = 1097

    """RMI SERVER NO LOG"""
    RMI_NO_LOG = False

    """RMI PAYLOAD"""
    RMI_PAYLOAD = {
        'antServlet': 'ant',
        'tomcat': '',
        'tomcatServlet': 'yay',
        'tomcatFilter': '',
        'springController': 'yay',
        'springInterceptor': ''
    }

    """JNDI LISTENER PAYLOAD INFO"""
    JNDI_PAYLOAD_INFO = """
    支持payload一览:                                                                                                      
        0类payload (通过HTTP服务器获取class文件，仅限于较低版本的Java，高版本无效):                                        
        tomcat0             - 通过获取当前线程的 tomcat 请求执行命令，有回显，非内存马                                     
        tomcatServlet0      - 通过向 tomcat 添加 servlet 执行命令，路径为yay，参数为cmd，内存马                            
        tomcatFilter0       - 通过向 tomcat 添加 filter 内存马, 参数为y4y                                                  
        antServlet0         - 通过向 tomcat 添加 servlet，需要蚁剑客户端利用，路径为ant，参数为cmd，内存马                 
        springController0   - 通过向 spring 添加 controller，路径为/yay，参数为cmd，内存马                                 
        springInterceptor0  - 通过向 Spring 添加 Interceptor 内存马, 参数为y4y
    
        1类payload (利用Java的ELProcessor绕过对外部URL请求的限制，不依赖HTTP服务器):
        tomcat1             - 通过获取当前线程的 tomcat 请求执行命令，有回显，非内存马
        tomcatServlet1      - 通过向 tomcat 添加 servlet执行命令，路径为/yay，参数为cmd，内存马
        tomcatFilter1       - 通过向 tomcat 添加 filter 内存马, 参数为y4y
        antServlet1         - 通过向 tomcat 添加 servlet，需要蚁剑客户端利用，路径为/ant，参数为cmd，内存马
        springController1   - 通过向 Spring 添加 controller 内存马, 路径为/yay，参数为cmd，内存马   
        springInterceptor1  - 通过向 Spring 添加 Interceptor 内存马, 参数为y4y
    
        通用payload (同样利用ELProcessor进行绕过，但不支持内存马和回显):
        general_<base64编码后的指令> (例: cmd=whoami， payload名=general_d2hvYW1p)
        NPoC中只需要提供"general"，不需要提供后面的base64编码后的指令
        如： -c 'touch /tmp/pwn.txt' -o payload_type=general 
    """