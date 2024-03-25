#!/bin/python
# Written by Erik

import imaplib

def get_env(keyword: str):
    with open(".env", 'r') as file:
        for line in file.readlines():
            name, value = line.split('=')

            if name == keyword:
                return value.strip()

    return "-1"

username = get_env("USERNAME")
password = get_env("PASSWORD")
server = get_env("SERVER")
port = get_env("PORT")

obj = imaplib.IMAP4_SSL(server, int(port))
obj.login(username, password)
obj.select()
print(len(obj.search(None, 'UnSeen')[1][0].split()))
