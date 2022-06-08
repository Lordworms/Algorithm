import numpy as np
import math
def sigmoid(inx):
    x=inx
    for i in x:
        if i>=0:     
            i=1.0/(1+np.exp(-i))
        else:
            i=np.exp(i)/(1+np.exp(i))
    return x
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


class DNN:
    def __init__(self, num, per_num, learning_rate):
        # 网络层数
        self.num = num
        # 每层神经元个数
        self.per_num = per_num
        # 学习率
        self.learning_rate = learning_rate
        # 输出序列
        self.output = []
        # 损失序列
        self.error = []
        # 权重序列
        self.weight = []
        # 初始化权重序列,保证在多个标准正太相加的情况下图像不会太平坦

        for i in range(self.num):
            self.weight.append(
                np.random.normal(0.0, pow(self.per_num[i + 1], -0.5), (self.per_num[i + 1], self.per_num[i])))


        self.active_func = lambda x: 1.0 / (1.0 + np.exp(-x))

    def train(self, data, target):
        data = np.array(data, ndmin=2).T
        target = np.array(target, ndmin=2).T
        # 前向传播
        temp = data
        self.output = []
        self.output.append(temp)
        a=self.weight[0][0][0]
        #print(a)
        for i in range(self.num):
            temp_input = np.dot(self.weight[i], temp)
            temp_output =self.active_func(temp_input)
            temp = temp_output
            self.output.append(temp_output)
        # 计算误差值
        self.error = []
        for i in range(self.num):
            if i == 0:
                self.error.append(target - self.output[-1])
            else:
                self.error.append(np.dot(self.weight[self.num - i].T, self.error[i - 1]))
        # bp
        for i in range(self.num):
            b=self.learning_rate * np.dot(
                (self.error[i] * self.output[-1 - i] * (1.0 - self.output[-1 - i])), np.transpose(self.output[-2 - i]))
            self.weight[self.num - i - 1] += self.learning_rate * np.dot(
                (self.error[i] * self.output[-1 - i] * (1.0 - self.output[-1 - i])), np.transpose(self.output[-2 - i]))
        if self.weight[0][0][0]!=a:
            print('yes')
    def predict(self, data):
        tmp = np.array(data, ndmin=2).T
        for i in range(self.num):
            tmp_input = np.dot(self.weight[i], tmp)
            tmp_output = self.active_func(tmp_input)
            tmp = tmp_output
        return tmp
        #return list(tmp).index(max(list(tmp)))


if __name__ == '__main__':
    data_train, target_train, data_test, target_test = get_data()
    print(len(data_train[0]))
    model = DNN(2, [161, 10, 1], 0.1)
    all_accuracy = 0
    accuracy_arr = []
    for epoch in range(10):
        print("epoch:",epoch)
        if epoch == 5:
            model.learning_rate = 0.05
        for i in range(24000):
            model.train(data_train[i], target_train[i])
        count=0
        for i in range(5999):
            k=model.predict(data_test[i])
            j=target_test[i]
            if abs(model.predict(data_test[i])-target_test[i])<0.1:
                count += 1
        print('epoch %d' % (epoch + 1))
        print('accuracy:%f' % (float(count) / 5999))
        accuracy_arr.append(float(count) / 5999)
        
    #for epoch in range(10):
        #count = 0
        #for i in range(5999):
        #    k=model.predict(data_test[i])
        #    j=target_test[i]
        #    if abs(model.predict(data_test[i])-target_test[i])<0.5:
        #        count += 1
        #print('epoch %d' % (epoch + 1))
        #print('accuracy:%f' % (float(count) / 5999))
        #accuracy_arr.append(float(count) / 5999)
        #print('average accuracy:%f' % (np.mean(accuracy_arr)))
        #print('sd:%f' % (np.std(accuracy_arr)))
   
