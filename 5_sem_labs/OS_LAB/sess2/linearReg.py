import numpy as np
import pandas as pd
from sklearn import datasets,model_selection,preprocessing

boston = datasets.load_boston()
print(boston.feature_names)
x = boston.data
y = boston.target
x = pd.DataFrame(x, columns=boston.feature_names)
y = pd.DataFrame(y, columns=["MEDV"])
x_train,x_test,y_train,y_test = model_selection.train_test_split(x,y)
scale = preprocessing.StandardScaler()
scale.fit_transform(x_train)
scale.transform(x_test)
def cost(m,c,x,y):
    cost = 0
    for i in range(len(x)):
        cost+=((y.iloc[i]-np.dot(m,x.iloc[i])-c)**2)/len(x)
    return cost

def stepGradient(m,c,lr):
    m_slope = np.zeros(len(m),dtype=float)
    c_slope = 0
    for i in range(len(x_train)):
        for j in range(m):
            m_slope[j]+=(-2/len(x_train))*(y_train.iloc[i]-np.dot(m,x_train.iloc[i])-c)*x_train[i][j]
        c_slope+=(-2/len(x_train))*(y_train.iloc[i]-np.dot(m,x_train.iloc[i])-c)
    m = m - lr*m_slope
    c = c - lr*c_slope
    return m,c
