import setuptools

with open("README.md", "r") as fh:
    long_description = fh.read()
    
setuptools.setup(
    name='clinphen',
    version='1.0',
    scripts=['ClinPhen.command', 'ClinPhen.sh.x', 'ClinPhen.sh', 'ClinPhen_commandline.py', 'get_phenotypes.py', 'interface.py', 'prep_thesaurus.py', 'umls_thesaurus_extraction.sh', 'umlshelp.py', 'data/BUILD'] ,
    #scripts=['data/BUILD']
    author="Cole A. Deisseroth",
    author_email="cdeisser@stanford.edu",
    description="An automatic phenotype extractor",
    long_description=long_description,
    long_description_content_type="text/markdown",
    packages=setuptools.find_packages(),
     classifiers=[
         "Programming Language :: Python :: 2",
         "Operating System :: OS Independent",
     ],
 )

