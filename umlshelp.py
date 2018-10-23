import sys
import os
import re

#TODO: Mention the phenotype name and description
#TODO: Resize the items in the GUI
#TODO: allow pasting in of files

from appJar import gui
from get_phenotypes import *

myDir = "/".join(os.path.realpath(__file__).split("/")[:-1])
targetDir = myDir + "/data/"
prepperPath = myDir + "/prep_thesaurus.py"
getterPath = myDir + "/umls_thesaurus_extraction.sh"

def umlsExtract(button):
  umlsDir = ClinPhen.getEntry("umlsDir")
  results = os.popen(" ".join(["bash -e", getterPath, umlsDir, targetDir, prepperPath, "2>&1 >/dev/null"])).readline()
  if not results:
    ClinPhen.setLabel("Results", "Extraction successful :)")
  else: ClinPhen.setLabel("Results", results)

bigDiv = 30
medDiv = 50
smallDiv = 70
bigLabels = ["Title"]
medLabels = ["Results"]
smallLabels = ["Description", "Instructions"]
webLinks = ["Licensed UMLS users can download the latest release of the Metathesaurus here"]
buttons = ["Extract", "Select UMLS folder"]
entries = ["umlsDir"]

def rescaleWidgets():
    ClinPhen.setLabelWidth("Title", 50)
    for label in bigLabels: ClinPhen.getLabelWidget(label).config(font="Times "+str(windowWidth/bigDiv)+" bold")
    for label in medLabels: ClinPhen.getLabelWidget(label).config(font="Times "+str(windowWidth/medDiv)+" bold")
    for label in smallLabels: ClinPhen.getLabelWidget(label).config(font="Times "+str(windowWidth/smallDiv))
    for button in buttons: ClinPhen.getButtonWidget(button).config(font="Times "+str(windowWidth/smallDiv))
    for entry in entries: ClinPhen.getEntryWidget(entry).config(font="Times "+str(windowWidth/smallDiv))
    for webLink in webLinks: ClinPhen.getLinkWidget(webLink).config(font="Times "+str(windowWidth/smallDiv))


def checkSize(event="None"):
    global windowWidth
        #global windowHeight
    newWidth = ClinPhen.topLevel.winfo_width()
    newHeight = ClinPhen.topLevel.winfo_height()
    if windowWidth == newWidth:
        return
    windowWidth = newWidth
    #windowHeight = newHeight
    rescaleWidgets()

def pickUMLSDir(button):
  dir = ClinPhen.directoryBox(title="Select unzipped UMLS folder")
  ClinPhen.setEntry("umlsDir", dir)

ClinPhen = gui()

scaleFactor = 0.75
screenWidth = ClinPhen.topLevel.winfo_screenwidth()
screenHeight = ClinPhen.topLevel.winfo_screenheight()
windowWidth = int(screenWidth * scaleFactor)
windowHeight = int(screenHeight * scaleFactor)
ClinPhen.setGeometry(str(windowWidth) + "x" + str(windowHeight))

ClinPhen.setTitle("UMLS metathesaurus extraction")
ClinPhen.setBg("grey")
ClinPhen.startScrollPane("MainScroll")
ClinPhen.addLabel("Title", "Getting UMLS", 0, 0)
ClinPhen.addLabel("Description", "While not necessary, the UMLS Metathesaurus can considerably improve the performance of ClinPhen.\nWe can't just give out the Metathesaurus to everyone though--that would be illegal.", 1, 0)
ClinPhen.addWebLink("Licensed UMLS users can download the latest release of the Metathesaurus here", "https://www.nlm.nih.gov/research/umls/licensedcontent/umlsknowledgesources.html", 2, 0)
ClinPhen.addLabel("Instructions", "Once you have downloaded and unzipped the UMLS data folder, select the folder below, and it will be processed into a thesaurus for ClinPhen.", 3, 0)
ClinPhen.addEntry("umlsDir", 4, 0)
ClinPhen.addButton("Select UMLS folder", pickUMLSDir, 4, 1)
ClinPhen.addButton("Extract", umlsExtract, 5, 0)
ClinPhen.addLabel("Results", "", 6, 0)

ClinPhen.stopScrollPane()
ClinPhen.topLevel.bind("<Configure>", checkSize)
checkSize()
ClinPhen.go()

