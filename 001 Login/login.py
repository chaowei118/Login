# -*- coding:utf-8 -*-
# Author: Rookie118
# Purpose: 编写登录接口
#          Implementing login interface

with open("username.txt",'r') as fi_user:  #读取存储的用户名
    usernames = fi_user.readlines()
with open("password.txt",'r') as fi_pass:  #读取存储的密码
    passwords = fi_pass.readlines()
with open("lock.txt",'r') as fi_lock:  #读取存储的锁定用户名
    locks = fi_lock.readlines()

count = 0  #记录登入次数
flag_lock = False  #锁定用户标志
flag_pass = False  #用户密码正确标志
flag_user = False  #用户名正确标志

while count < 3:  #输错三次后锁定用户
    _username = input("username:")
    _password = input("password:")
    for lock in locks:
        if _username == lock.rstrip():
            flag_lock = True
            print("You have tried too many times, the account has been locked!")
            break
    if flag_lock:  #此用户已被锁定，结束程序
        break
    for username in usernames:
        if _username == username.rstrip():
           flag_user = True
           for password in passwords:
               if _password == password.rstrip():
                   print("Welcome to login!")
                   flag_pass = True
                   break
           if not flag_pass:
               print("Incorrect password!")
               break
           else:
               break  #用户登入成功，不用继续遍历用户名
    if flag_pass:
        break #用户登入成功，程序结束
    if not flag_user:
        print("Incorrect username!")
    count += 1
    if count == 3:  #输错三次，用户名被存储到锁定用户文档中
        with open("lock.txt",'a') as fo_lock:
            fo_lock.write(_username.rstrip()+'\n')
