from croe.exec_system import exec_system
import random
from tld import get_tld

def siteScreenshot(site):

    file_name = 'img/{}-{}.jpg'.format(get_tld(site, as_object=True).parsed_url.netloc,random.randint(0,9))
    cmd_parameters = ['/Users/sqlw/tools/bugbountytips/tools/phantomjs',
                      '--ignore-ssl-errors true',
                      '--ssl-protocol any',
                      '--ssl-ciphers ALL',
                      '/Users/sqlw/tools/bugbountytips/tools/screenshot.js',
                      '-u={}'.format(site),
                      '-s={}'.format(file_name),
                      ]

    exec_system(cmd_parameters)
    return file_name