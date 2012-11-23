#!/usr/bin/env python

import os
import io
import json

res_path = "../data"

stat = {}
stat["passed"] = 0
stat["failed"] = 0


def parse_file(filename):
  src_fd = io.open(filename)
  tree = None
  try:
    tree = json.loads(src_fd.read())
  except ValueError as e:
    print("%s ERROR:\n\t%s" % (filename, e))
    stat["failed"] += 1
  else:
    print("%s\t[OK]" % filename)
    stat["passed"] += 1

  return tree


#import pdb

for root, directory, files in os.walk(res_path):
  for file in files:
    if file.endswith(".json"):
      json_file = os.path.join(root,file)
      #pdb.set_trace()
      parse_file(json_file)


print("passed: %d", stat["passed"])
print("failed: %d", stat["failed"])

