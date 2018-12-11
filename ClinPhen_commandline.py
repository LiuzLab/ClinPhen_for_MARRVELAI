#!/usr/bin/env python
"""
ClinPhen commandline.
"""
import sys
import os
import argparse
from get_phenotypes import *

myDir = os.path.dirname(os.path.realpath(__file__))
hpo_main_names = os.path.join(myDir, "data/hpo_term_names.txt")
assert os.path.isfile(hpo_main_names), "Cannot find HPO term names mapping file {}".format(hpo_main_names)

def getNames():
  returnMap = {}
  for line in open(hpo_main_names):
    lineData = line.strip().split("\t")
    returnMap[lineData[0]] = lineData[1]
  return returnMap

def build_parser():
  """Build commandline parser"""
  parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.ArgumentDefaultsHelpFormatter)
  parser.add_argument("recordfile", type=str, help="File containing records to parse")
  parser.add_argument("--thesaurus", type=str, required=False, default=None, help="Custom thesaurus to use")
  return parser

def main():
  """Run the script"""
  # Parse commandline arguments
  parser = build_parser()
  args = parser.parse_args()

  inputStr = ""
  inputFile = args.recordfile
  for line in open(inputFile): inputStr += line
  hpo_to_name = getNames()
  if not args.thesaurus: returnString = extract_phenotypes(inputStr, hpo_to_name)
  else: returnString = extract_phenotypes_custom_thesaurus(inputStr, args.thesaurus, hpo_to_name)

  print returnString

if __name__ == "__main__":
  main()
