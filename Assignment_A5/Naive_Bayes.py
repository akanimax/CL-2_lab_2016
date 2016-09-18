#import required modules
import csv
import sys
import time
import os
from collections import Counter
#-----------------------------------------------
#open dataset file
file='datastr.csv'
f = open(file, 'rb')
query={'Age':'middle_age','Qualification':'MTech.','Experience':'medium','Work_Type':'?'}



reader = csv.reader(f, delimiter=' ')
headers = reader.next()
#-----------------------------------------------
#declare datastructures
column = {}
freq = {}
Probability={}
occurance_counts={}
conditionaloccurance={}
condProb={}
FinalResults={}
Init_total=1.0
#-----------------------------------------------
#Function for calculating conditional probabilities:
def condProbfun(queryattribute_val,classlabel):
	value=0.0
	counter=0.0
	occure=0.0
	result=0.0
	f = open('datastr.csv', 'rb')
	reader = csv.reader(f)
	for row in reader:
		if queryattribute_val in row and classlabel in row:
			value= value+1
	occure=occurance_counts[classlabel]
	result=value/occure
	return result
#-----------------------------------------------
for h in headers:
	column[h] = []

for row in reader:
	for h, v in zip(headers, row):
		column[h].append(v)

print 'Display Dataset \n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*'
		
with open(file,'r') as f:
    for line in f:
        for word in line.split('\t'):
           print(word)
print '\n'
print '-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*'



#table manipulation
sys.stdin.read(1)
print 'Query tuple:',query

           
for h in headers:
	word_list = column[h]
	# Get a set of unique words from the list
	word_set = set(word_list)
	# create frequency dictionary
	
	for word in word_set:
	    occurance_counts[word]=word_list.count(word)  #Get occurance count
	    freq[word] = word_list.count(word) / float(len(word_list)) #Get frequency count
	    Probability[word]=freq[word] #prior probability
#-----------------------------------------------
for name,item in query.items(): #which class
        if item == '?':
                classname=name
               
print 'To Predict:',classname
print '-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n'
sys.stdin.read(1)
print 'Naive Bays Classifier.......\n'
time.sleep(5)
#-----------------------------------------------
word_list = column[classname]
word_set = set(word_list)

for word in word_set:
	classlabel=word # {Consultancy,Service,Research}
	print 'Prior probability of' ,classname,':',classlabel,'=',freq[classlabel]
	total=Init_total
	for queryattribute in query:
		if not queryattribute == classname:
			queryattribute_val=query[queryattribute] 
			#Get Every other attribute than classlabel print query[queryattribute]
			ans=condProbfun(queryattribute_val,classlabel)
			print '\n conditional probability  P(',queryattribute_val ,'|',classlabel,')=',ans
			total=total*ans
			condProb[classlabel]=total
	#print 'Total', total
			
	TotalProbability=total*freq[classlabel]	
	FinalResults[classlabel]=TotalProbability
	print '-----------------------------------------------'
	print 'Multiplication of above probabilities to give Posterior Probability of ',classname,':',classlabel,'=',FinalResults[classlabel]
	print '-----------------------------------------------\n\n\n\n\n\n'
	sys.stdin.read(1)
list=FinalResults.values()
#-----------------------------------------------
#Predict Classname
maxprob=max(list)
for name,item in FinalResults.items():
        if item == maxprob:
                classpredicted=name
print '*********************************************************'
print 'Predicted Class (Highest posterior Probability )for given query tuple is:',classname,':', classpredicted
print '*********************************************************'
#-----------------------------------------------

