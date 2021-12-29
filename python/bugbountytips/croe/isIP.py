from IPy import IP
def isIP(str):
    try:
        IP(str)
    except ValueError:
        return False
    return True