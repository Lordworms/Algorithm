import torch
import torch.nn as nn
import pandas as pd
import torch.nn.functional as F
import numpy as np
import matplotlib.pyplot as plt
import torch.utils.data as Data
import  torch.nn.functional as F

def get_data():
    f = open('./test.txt')
    data_train = []
    target_train = []
    for line in f.readlines():
        arr = line.strip().split(' ')
       
        target_train.append(float(arr[-1]))
        num=[float(k) for k in arr]
        num=num[:-1]
        data_train.append(num)
         
    data_test = data_train[24000:]
    target_test = target_train[24000:]
    data_train=data_train[:24000]
    target_train=target_train[:24000]
    return data_train, target_train, data_test, target_test
    #return data_train, target_train


data_train,target_train,data_test,target_test=get_data()
data_train=torch.from_numpy(np.array(data_train))
data_test=torch.from_numpy(np.array(data_test))
target_train=torch.from_numpy(np.array(target_train))
target_test=torch.from_numpy(np.array(target_test))
data_train=data_train.float()
data_test=data_test.float()
target_train=target_train.float()
target_test=target_test.float()

class Model(nn.Module):
    def __init__(self, in_features):
        super(Model, self).__init__()
        self.linear_relu1 = nn.Linear(in_features, 20) # 输入层
        self.linear_relu2 = nn.Linear(128, 256) # 隐藏层
        self.linear_relu3 = nn.Linear(256, 256) # 隐藏层
        self.linear_relu4 = nn.Linear(256, 256) # 隐藏层
        self.linear5 = nn.Linear(256, 1) # 输出层
        self.tmp=nn.Linear(20,20)
        self.out_layer=nn.Linear(20,1)
    def forward(self, x):
        #y_pred = self.linear_relu1(x)
        #y_pred = nn.functional.relu(y_pred)
 
        #y_pred = self.linear_relu2(y_pred)
        #y_pred = nn.functional.relu(y_pred)
 
        #y_pred = self.linear_relu3(y_pred)
        #y_pred = nn.functional.relu(y_pred)
 
        #y_pred = self.linear_relu4(y_pred)
        #y_pred = nn.functional.relu(y_pred)
 
        #y_pred = self.linear5(y_pred)
        y_pred=self.linear_relu1(x)
        y_pred=nn.functional.relu(self.tmp(y_pred))
        y_pred=self.out_layer(y_pred)
        return y_pred



model = Model(161)
optimizer = torch.optim.Adam(model.parameters(), lr=0.1)
loss_fun = nn.MSELoss()



#target_train=torch.unsqueeze(target_train,1)
model.train()
for i in range(50):
    loss_all=0
    for k in range(50):
        np.random.seed(0)
        num=np.random.randint(0,len(data_train),size=128)
        out = model(data_train[num])
        loss = loss_fun(out, target_train)
        loss_all+=loss
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
    count=0
    for j in range(5999):
        out=model(data_test[j])
        out=out.float()
        x=target_test[j]
        if abs(out-target_test[j])/target_test[j]<=0.05:
            count+=1
    print('count:',count)
    print('loss:',loss_all)
    print("epoch ",i," accuracy:",count/5999)
