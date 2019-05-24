
import pandas as pd;
import csv;

import math as m


print("NUmber of people in each degree category\n");
data=pd.read_csv("survey_results.csv");

#looks at formal education and slary
degrees=data.FormalEducation;

num_of_degrees={}

#finds the number of people in each degree categoriy
for i in range( len(degrees)):
	if degrees[i] in num_of_degrees:
		num_of_degrees[degrees[i]]+=1;
	else:
		num_of_degrees[degrees[i]]=1;

#prints category and corresponding number
for key in num_of_degrees:
	print(key+":", num_of_degrees[key]);
	
print("\n");

salaried_developers={key:0 for key in num_of_degrees};

salary=data.Salary;

salary_of_developers={key : 0 for key in num_of_degrees};

print("Average Salary of Developers based on level of education")

#finds all developers who have a salary and tracks salary
for i in range(len(degrees)):
	num=salary[i];
	if(not m.isnan(num)):
		salary_of_developers[degrees[i]]+=salary[i];
		salaried_developers[degrees[i]]+=1;

#prints value of salary		
for key in salary_of_developers:
	print(key+":",round(salary_of_developers[key]/salaried_developers[key],2));

# looks at undergrad degree and corresponding 
print("\n");	
undergrad=data.MajorUndergrad;

majors={}

# keeps track of number o undergrads and degree
for i in range( len(undergrad)):
	if undergrad[i] in majors:
		majors[undergrad[i]]+=1;
	else:
		majors[undergrad[i]]=1;
# prints number of undergrads in each
for key in majors:
	print(key,majors[key]);

#finds undergrads who have a salary attached to them.
majors={key:0 for key in majors};
salary_undergrad={key:0 for key in majors};

for i in range(len(undergrad)):
	num=salary[i]
	
	if (not m.isnan(salary[i])):
		salary_undergrad[undergrad[i]]+=salary[i];
		majors[undergrad[i]]+=1;

print("\n");
for key in salary_undergrad:
	print(key,round(salary_undergrad[key]/majors[key],2));
		


