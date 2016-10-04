# Assignment_B6 (D1)
# Stages of natural language processing of English
# Roll no. 4431

from nltk import load_parser
from nltk.corpus import treebank
from nltk.corpus import treebank_raw
from nltk.corpus import stopwords
from nltk.tag import DefaultTagger
from nltk.tag import UnigramTagger
from nltk.tag import BigramTagger
from nltk.tokenize import TreebankWordTokenizer
import nltk.data
from nltk.grammar import Nonterminal
from nltk.tree import *
from nltk.draw import *
from nltk import load_parser

# global data to be accessed by all of the functions
train_sent=treebank.tagged_sents()[:3000]
test_sents=treebank.tagged_sents()[1:3000]

def preprocessing(para):
	print "\n\n\nStep 1: Preprocessing"
	print "Involves Processing of text"
	print "\n\nTokenizing Text into Sentences"
	
	sent_tokenizer = nltk.data.load('tokenizers/punkt/english.pickle')
	sent = sent_tokenizer.tokenize(para)
	print "The sentences are:"
	for s in sent:
		print s
	print "\n\nTokenizing Sentences into Words"
	tokenizer=TreebankWordTokenizer(); tokens = []
	for s in sent:
		tokens.extend(tokenizer.tokenize(s))
	print "The words are:"
	print tokens

	return tokens

def lexical(tokens):
	print "\n"
	print "Step 2: Lexical Analysis\n"
	print "Essentially refers to dictionary and obtains the properties of the word"
	print "Part-Of-Speech tagging"
	print "The tagset is:\n"

	tag = DefaultTagger('NN');tagg = UnigramTagger(train_sent, backoff=tag)
	tagger = BigramTagger(train_sent, backoff=tagg)
	
	tagtokens = tagger.tag(tokens)
	for token,tag in tagtokens:
		print token+"->"+tag
	print "\n"
	print "The acurracy of the trained pos tagger is:"
	print tagger.evaluate(test_sents)

	return tagtokens


def syntax(tagtokens):
	print "\n"
	print "Step 3: Syntax Analysis\n"
	
	dataset_size = len(treebank.parsed_sents())
	split_size = int(dataset_size*0.97)
	learning_set = treebank.parsed_sents()[:split_size]
	test_set = treebank.parsed_sents()[split_size:]
	
	#create a set containing the raw sentences
	sents = treebank.sents()
	raw_test_set = [[w for w in sents[i]] for i in range(split_size,dataset_size)]
	
	#construct the PCFG
	tbank_productions = []

	for sent in learning_set:
		for production in sent.productions():
			tbank_productions.append(production)
	
	for word,tag in tagtokens:
		t = Tree.fromstring("("+tag+" "+word+")")
		for production in t.productions():
			tbank_productions.append(production)

	tbank_grammar = nltk.grammar.induce_pcfg(Nonterminal('S'), tbank_productions)
	chart_parser = nltk.ChartParser(tbank_grammar)
	
	trees = chart_parser.parse(tokens)
	count = 1
	for tree in trees:
		print tree # show first few trees
		if(count == 3):
			break
		else:
			count += 1
	return trees

def semantic(parseTrees, para):
	print "\n"
	print "Step 4: Semantic Analysis\n"
 	cp = load_parser('grammars/book_grammars/sql0.fcfg')
 	trees = list(cp.parse(para[:len(para) - 1].split()))
 	answer = trees[0].label()['SEM']
 	answer = [s for s in answer if s]
 	q = ' '.join(answer)
 	return q


para = raw_input("Enter a Question:\n")

tokens = preprocessing(para)

tagged_tokens = lexical(tokens)
Trees = syntax(tagged_tokens)
SQL_query = semantic(Trees, para)

print "NLP processing complete!!"
print "The SQL Query so formed is:\n"
print SQL_query
print "Good BYE"

