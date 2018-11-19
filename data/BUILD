curl https://raw.githubusercontent.com/obophenotype/human-phenotype-ontology/master/hp.obo > hp.obo
python ../src/hpo_syns.py hp.obo > tmp
python ../src/standardize_syn_map.py tmp > hpo_synonyms.txt
rm tmp
python ../src/hpo_names.py hp.obo > hpo_term_names.txt 


