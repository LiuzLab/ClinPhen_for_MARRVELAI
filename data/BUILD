DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

curl https://files.pythonhosted.org/packages/6f/ed/9c755d357d33bc1931e157f537721efb5b88d2c583fe593cc09603076cc3/nltk-3.4.zip > $DIR/nltk-3.4.zip
unzip $DIR/nltk-3.4.zip -d $DIR
mv $DIR/nltk-3.4/nltk/ $DIR/../
rm -r $DIR/nltk-3.4/
rm $DIR/nltk-3.4.zip

mkdir $DIR/../nltk_data
mkdir $DIR/../nltk_data/corpora
curl https://raw.githubusercontent.com/nltk/nltk_data/gh-pages/packages/corpora/wordnet.zip > $DIR/../nltk_data/corpora/wordnet.zip
unzip $DIR/../nltk_data/corpora/wordnet.zip -d $DIR/../nltk_data/corpora/
rm $DIR/../nltk_data/corpora/wordnet.zip
cat $DIR/../nltk/data.py | awk 'BEGIN {FS = "\t"} {if($1 == "path = []"){print $1 "\npath.append(\"'$DIR/../nltk_data'\")"} else{print}}' > $DIR/../tmp
mv $DIR/../tmp $DIR/../nltk/data.py

curl https://raw.githubusercontent.com/obophenotype/human-phenotype-ontology/master/hp.obo > $DIR/hp.obo
python $DIR/../src/hpo_syns.py $DIR/hp.obo > $DIR/tmp
python $DIR/../src/standardize_syn_map.py $DIR/tmp > $DIR/hpo_synonyms.txt
rm $DIR/tmp
python $DIR/../src/hpo_names.py $DIR/hp.obo > $DIR/hpo_term_names.txt 

