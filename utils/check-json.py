#!/usr/bin/env python

import os
import io
import json
import subprocess
import re

res_path = "../data"


stat = {}
stat["passed"] = 0
stat["failed"] = 0


def check_json_file(filename):
    src_fd = io.open(filename)
    tree = None
    try:
        tree = json.loads(src_fd.read())
    except ValueError as e:
        print("%s ERROR:\n\t%s" % (filename, e))
        raw_input("Press Enter...")
        if args.fix_errors:
            call_editor(filename, e)
        
        #else:
        stat["failed"] += 1

    else:
        print("%s\t[OK]" % filename)
        stat["passed"] += 1

    return tree


def check_all_json():

    for root, directory, files in os.walk(res_path):
        for file in files:
            if file.endswith(".json"):
                json_file = os.path.join(root,file)
                check_json_file(json_file)

    return


def call_editor(filename, error_message):
    #pattern = r'Expecting , delimiter: line (\d+) column (\d+)'
    pattern1 = r'Expecting , delimiter: line (\d+) column (\d+)'
    pattern2 = r'Expecting property name: line (\d+) column (\d+)'
    err_position = re.match(pattern1, str(error_message)) or re.match(pattern2, str(error_message))
    if not err_position:
        return

    err_line = err_position.group(1)
    
    cmd = ["/usr/bin/vim", "+%s" % err_line, os.path.abspath(filename)]
    print(cmd)

    subprocess.call(cmd, shell=False)


#
# checking script aruments
#
import argparse
parser = argparse.ArgumentParser(description='Check specified json file, or all files'
                                             '(by default) in gamedata')

#parser.add_argument('infilee', nargs='*', dest='in_json_file')
parser.add_argument('in_file', nargs='*')

parser.add_argument('-f', '--fix-errors',
                    action="store_true",
                    help="if syntax error detected, manually fix it (from $EDITOR)")

#parser.add_argument('-a', '--all',
#                    action="store_true",
#                    help="Check all json files in data dir")

args = parser.parse_args()

if args.in_file:
    check_json_file(args.in_file)
#elif args.all:
else:
    check_all_json()
    
    

print("passed: %d" % stat["passed"])
print("failed: %d" % stat["failed"])

