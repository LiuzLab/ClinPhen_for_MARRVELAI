import sys
import os
from get_phenotypes import *

myDir = "/".join(os.path.realpath(__file__).split("/")[:-1])
hpo_main_names = myDir + "/data/hpo_term_names.txt"

def getNames():
  returnMap = {}
  for line in open(hpo_main_names):
    lineData = line.strip().split("\t")
    returnMap[lineData[0]] = lineData[1]
  return returnMap
hpo_to_name = getNames()

inputStr = ""
inputFile = sys.argv[1]
for line in open(inputFile): inputStr += line
if len(sys.argv) < 3: returnString = extract_phenotypes(inputStr, hpo_to_name)
else: returnString = extract_phenotypes_custom_thesaurus(inputStr, sys.argv[2], hpo_to_name)
print returnString
