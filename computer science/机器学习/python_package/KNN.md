# KNN

### K-近邻（K-Nearest Neighbors, KNN）

K-近邻（KNN）是一种基于实例的学习方法，预测时通过计算待预测样本与训练集中所有样本的距离，选取距离最近的 K 个邻居，并根据邻居的标签进行预测。

主要参数:

- **K**：选择的邻居数量。
- **距离度量**：常用欧氏距离，也可以使用曼哈顿距离、闵可夫斯基距离等。

scikit-learn 实现:

## 实例

```python
from sklearn.neighbors import KNeighborsClassifier  
from sklearn.model_selection import train_test_split  
```

  
# 假设 X 是特征矩阵，y 是标签  

```python
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)  
  
model = KNeighborsClassifier(n_neighbors=3)  
model.fit(X_train, y_train)
```
  
  
# 预测  
```python
y_pred = model.predict(X_test)  
```

