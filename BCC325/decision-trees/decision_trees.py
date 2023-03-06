# -*- coding: utf-8 -*-
"""decision_trees.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1EuiBx3RPCdwvcEyfi7KFyBYftzWEDqxl
"""

import pandas as pd

data_frame = pd.read_csv('/content/drive/MyDrive/Colab Notebooks/decision_tree.csv')

data_frame.head()

#removing answer to teach model
input = data_frame.drop('salary', axis='columns')
target = data_frame['salary']
input

from sklearn.preprocessing import LabelEncoder
#turn variables into numbers (decode in keys)

le_company = LabelEncoder()
le_job = LabelEncoder()
le_degree = LabelEncoder()

input['company_n'] = le_company.fit_transform(input['company']) #creates new columns
input['job_n'] = le_job.fit_transform(input['job'])
input['degree_n'] = le_degree.fit_transform(input['degree'])
input

inputs_n = input.drop(['company', 'job', 'degree'], axis='columns')
inputs_n #encoded input. now we can train the decision tree

from sklearn import tree

model = tree.DecisionTreeClassifier()
model.fit(inputs_n, target) #target is the answer

model.predict([[2,2,1]]) #predicts google, sales executive, masters degree

model.predict([[1,2,2]])