curl https://files.pythonhosted.org/packages/6f/ed/9c755d357d33bc1931e157f537721efb5b88d2c583fe593cc09603076cc3/nltk-3.4.zip > nltk-3.4.zip
unzip nltk-3.4.zip
mv nltk-3.4/nltk ../
rm -r nltk-3.4
rm nltk-3.4.zip

curl https://raw.githubusercontent.com/obophenotype/human-phenotype-ontology/master/hp.obo > hp.obo
python ../src/hpo_syns.py hp.obo > tmp
python ../src/standardize_syn_map.py tmp > hpo_synonyms.txt
rm tmp
python ../src/hpo_names.py hp.obo > hpo_term_names.txt 


