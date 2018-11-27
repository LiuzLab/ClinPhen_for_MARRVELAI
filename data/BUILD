DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

curl https://files.pythonhosted.org/packages/6f/ed/9c755d357d33bc1931e157f537721efb5b88d2c583fe593cc09603076cc3/nltk-3.4.zip > $DIR/nltk-3.4.zip
unzip $DIR/nltk-3.4.zip -d $DIR
#rm -r $DIR/../nltk/
mv $DIR/nltk-3.4/nltk/ $DIR/../
rm -r $DIR/nltk-3.4/
rm $DIR/nltk-3.4.zip

curl https://raw.githubusercontent.com/obophenotype/human-phenotype-ontology/master/hp.obo > $DIR/hp.obo
python $DIR/../src/hpo_syns.py $DIR/hp.obo > $DIR/tmp
python $DIR/../src/standardize_syn_map.py $DIR/tmp > $DIR/hpo_synonyms.txt
rm $DIR/tmp
python $DIR/../src/hpo_names.py $DIR/hp.obo > $DIR/hpo_term_names.txt 

