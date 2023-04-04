import pandas as pd
import numpy as np

from src.preprocessing.split import SplitProcessing
from src.preprocessing.folds import FoldsProcessing
from src.recommenders.random_item import RandomItem
from src.recommenders.item_knn import LenskitItemKNN
from src.metrics.rmse import LenskitRMSE
from src.metrics.mae import  LenskitMAE

from sklearn.preprocessing import LabelEncoder
from sklearn import tree
from sklearn import linear_model
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.neighbors import KNeighborsClassifier

data_frame = pd.read_csv("data.csv")

data_frame.drop(columns=['ID', 'Start time', 'Completion time'],inplace=True)
#print(data_frame)

#turns data into numbers and
#creates new columns
data_frame['gender_n'] = LabelEncoder().fit_transform(data_frame['Select your Gender :'])
data_frame['age_n'] = LabelEncoder().fit_transform(data_frame['Select your age :'])
data_frame['spicy_n'] = LabelEncoder().fit_transform(data_frame['How much spicy would you like your pizza to be?'])
data_frame['pepperoni_n'] = LabelEncoder().fit_transform(data_frame['Do you like Pepperoni ?'])
data_frame['chicken_grain_n'] = LabelEncoder().fit_transform(data_frame['Which one do you prefer the most :'])
data_frame['tomato_n'] = LabelEncoder().fit_transform(data_frame['Do you Prefer Tomatoes?'])
data_frame['olives_n'] = LabelEncoder().fit_transform(data_frame['Which one of these do you like ?'])
data_frame['capsicum_n'] = LabelEncoder().fit_transform(data_frame['Do you like Capsicum ?'])
data_frame['beef_chicken_n'] = LabelEncoder().fit_transform(data_frame['Which one of these you like ?'])
data_frame['peppers_n'] = LabelEncoder().fit_transform(data_frame['Do you like Peppers ?'])
data_frame['sauce_n'] = LabelEncoder().fit_transform(data_frame['Do you like Sauce :'])
data_frame['mushroom_n'] = LabelEncoder().fit_transform(data_frame['Do you like Mushroom :'])
data_frame['pesto_n'] = LabelEncoder().fit_transform(data_frame['Do you like Pesto :'])
data_frame['cheese_n'] = LabelEncoder().fit_transform(data_frame['Do you like Cheese :'])
data_frame['health_n'] = LabelEncoder().fit_transform(data_frame['Have any Health or diet issue ?'])

# delete old columns
data_frame_n = data_frame.drop(['Select your Gender :', 'Select your age :', 'How much spicy would you like your pizza to be?', 'Do you like Pepperoni ?', 'Which one do you prefer the most :','Do you Prefer Tomatoes?', 'Which one of these do you like ?','Do you like Capsicum ?', 'Which one of these you like ?', 'Do you like Peppers ?', 'Do you like Sauce :', 'Do you like Mushroom :', 'Do you like Pesto :',  'Do you like Cheese :','Have any Health or diet issue ?' ], axis='columns')
#print(data_frame_n)

split_processing = SplitProcessing({
                "target": "tomato_n",
                "train_size": 80,
                "test_size": 20,
                "random_state": 42,
                "shuffle": True,
                "stratify": ""
})

split_processing.pre_processing(data_frame_n)

'''k_fold = FoldsProcessing({
        "target_column": "tomato_n",
        "folds": 5,
        "shuffle": False,
        "random_state": 42,
        "strategy": "kfold"
})'''

'''k_fold = FoldsProcessing({
        "target_column": "tomato_n",
        "folds": 10,
        "shuffle": True,
        "random_state": 42,
        "strategy": "stratifiedkfolds"
})'''

'''k_fold = FoldsProcessing({
        "target_column": "tomato_n",
        "folds": 2,
        "shuffle": True,
        "random_state": 42,
        "strategy": "stratifiedshufflesplit"
})'''
#k_fold.pre_processing(data_frame_n)

x_train = pd.read_csv("/home/clara/PycharmProjects/hybrid_recommender_framework/experiment_output/preprocessing/xtrain.csv")
y_train = pd.read_csv("/home/clara/PycharmProjects/hybrid_recommender_framework/experiment_output/preprocessing/ytrain.csv")
x_test = pd.read_csv("/home/clara/PycharmProjects/hybrid_recommender_framework/experiment_output/preprocessing/xtest.csv")
y_test = pd.read_csv("/home/clara/PycharmProjects/hybrid_recommender_framework/experiment_output/preprocessing/ytest.csv")

#METRICAS
rmse = LenskitRMSE({
        "sample_weight": "None",
        "squared": True,
        "missing": "error"
})

mae = LenskitMAE({
        "multioutput": "uniform_average"
})



print("=================================== KNN ===================================")
knn = KNeighborsClassifier(n_neighbors=4)
knn.fit(x_train, y_train.values.ravel())
predict_knn = knn.predict(x_test)
score_knn = knn.score(x_test,y_test)
score_rmse_knn = rmse.evaluate(predict_knn.flatten(), y_test.values.flatten())
score_mae_knn = mae.evaluate(predict_knn.flatten(), y_test.values.flatten())



print(f'[KNN] Score:', score_knn)
print(f'[KNN] Rmse:', score_rmse_knn)
print(f'[KNN] Mae:', score_mae_knn)


print("=================================== DECISION TREE ===================================")
dt = tree.DecisionTreeClassifier(max_depth=3, min_samples_split=5)
dt.fit(x_train, y_train.values.ravel()) #target (y) is the answer

predict_dt = dt.predict(x_test)
score_tomato_dt = dt.score(x_test,y_test)
score_rmse_dt = rmse.evaluate(predict_dt.flatten(), y_test.values.flatten())
score_mae_dt = mae.evaluate(predict_dt.flatten(), y_test.values.flatten())


print(f'[DECISION TREE] Score:', score_tomato_dt)
print(f'[DECISION TREE] Rmse:', score_rmse_dt)
print(f'[DECISION TREE] Mae:', score_mae_dt)



print("========================== LOGISTIC REGRESSION ==========================")
logistic_regression = LogisticRegression(penalty='l1', solver='saga', C=0.1)
logistic_regression.fit(x_train, y_train.values.ravel())
predict_lo = logistic_regression.predict(x_test)

score_tomato_lo = logistic_regression.score(x_test,y_test)
score_rmse_lo = rmse.evaluate(predict_lo.flatten(), y_test.values.flatten())
score_mae_lo = mae.evaluate(predict_lo, y_test.values.flatten())


print(f'[LOGISTIC REGRESSION] Score:', score_tomato_lo)
print(f'[LOGISTIC REGRESSION] Rmse:', score_rmse_lo)
print(f'[LOGISTIC REGRESSION] Mae:', score_mae_lo)


print("========================== RANDOM FOREST ==========================")
random_forest = RandomForestClassifier(n_estimators=10, max_depth=5)
random_forest.fit(x_train, y_train.values.ravel())
predict_rf = random_forest.predict(x_test)

score_tomato_rf = random_forest.score(x_test,y_test)
score_rmse_rf = rmse.evaluate(predict_rf.flatten(), y_test.values.flatten())
score_mae_rf = mae.evaluate(predict_rf, y_test.values.flatten())


print(f'[RANDOM FOREST] Score:', score_tomato_rf)
print(f'[RANDOM FOREST] Rmse:', score_rmse_rf)
print(f'[RANDOM FOREST] Mae:', score_mae_rf)

print("========================== GRADIENT BOOSTING CLASSIFIER ==========================")
gbc = GradientBoostingClassifier()
gbc.fit(x_train, y_train.values.ravel())
predict_gbc = gbc.predict(x_test)

score_tomato_gbc = gbc.score(x_test,y_test)
score_rmse_gbc = rmse.evaluate(predict_gbc.flatten(), y_test.values.flatten())
score_mae_gbc = mae.evaluate(predict_gbc, y_test.values.flatten())


print(f'[RANDOM FOREST] Score:', score_tomato_gbc)
print(f'[RANDOM FOREST] Rmse:', score_rmse_gbc)
print(f'[RANDOM FOREST] Mae:', score_mae_gbc)