#Running the ClinPhen GUI on a mac:
##Double-click ClinPhen.command

#Running the ClinPhen GUI on a non-mac:
##Double-click ClinPhen.sh.x

#Running the ClinPhen GUI on the command line:
##Open the terminal
##cd to the ClinPhen directory
##Run the following command:
sh ClinPhen.sh

#Running ClinPhen directly on the command line:
##Open the terminal
##cd to the ClinPhen directory
##Run the following command:
python ClinPhen_commandline.py input.txt
##Replace "input.txt" with the path to the free-text clinical note file that you want to parse.
##You can also run the command line with a custom thesaurus:
python ClinPhen_commandline.py input.txt thesaurus.txt
##Replace "thesaurus.txt" with the path to your custom thesaurus, which should be in the format: HPO_ID<tab>Synonym
