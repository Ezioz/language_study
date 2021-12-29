from croe.siteScreenshot import siteScreenshot
from config.config import Config
import oss2
import os

auth = oss2.Auth(Config.oss_AK, Config.oss_SK)
bucket = oss2.Bucket(auth, Config.oss_url, Config.oss_name)
def img_upload_obs(domain):
    file_img = siteScreenshot(domain)
    img_resp = open(file_img,'rb')
    bucket.put_object("ldhz/"+file_img, img_resp)
    os.remove(file_img)
    return "https://vulboxlw.oss-cn-beijing.aliyuncs.com/ldhz/"+file_img