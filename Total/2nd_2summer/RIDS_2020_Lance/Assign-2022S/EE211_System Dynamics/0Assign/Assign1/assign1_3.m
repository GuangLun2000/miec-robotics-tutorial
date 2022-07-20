%% Assign1 other
% 完全使用代码实现最小二乘法
% Use code to implement least square method

clear;clc;close all;

%% 最小二乘法实现部分

data1=importdata('2data/Gr3.txt');
data2=data1.data;
t=data2(:,1);
u=data2(:,2);
y=data2(:,3);

u1=u(1:1000,1);
y1=y(1:1000,1);
t1=t(1:1000,1);

u2=u(2001:3000,1);
y2=y(2001:3000,1);
t2=t(2001:3000,1);

NN = struc(1:3, 1:3, 0:2);
data4=iddata(y1,u1,1000);
data3=iddata(y2,u2,1000);

V = arxstruc(data4(1:500),data4(501:1000),NN);
[NN,Vm] = selstruc(V,0);
NA=NN(1);
NB=NN(2);
NK=NN(3);

%% Use code to implement least square method
% 1st
j=1;
for i=NB+1:length(y1)
    for m=1:NA
      X(1,m)=-y1(i-m);
    end
    for m=1:NB
        X(2,m)=u1(i-m);
    end
    X1=[X(1,:),X(2,:)];
    X1=X1';
    Y=y1(i);
    f=inv(X1'*X1)*X1'*Y;
    F{j}=f;
    j=j+1;
end 

% 2nd
j=1;
for i=NB+1:length(y2)
     for m=1:NA
      X(1,m)=-y2(i-m);
    end
    for m=1:NB
        X(2,m)=u2(i-m);
    end
    X1=[X(1,:),X(2,:)];
    X1=X1';
    for s=1:length(F)
        f=F{s};
        Ya=f*X1;
        Ya_t(s)=Ya;  
    end
    Ya_l{j}=Ya_t;
    j=j+1;
end

% 3rd
y2=y2(NB+1:length(y2));
y2=y2';
for j=1:length(Ya_l)
    Ya_o=Ya_l{j};
    Y1_l(1,:)=Ya_o;
    Y1_l(2,:)=y2;
    Var=var(Y1_l);
    avg=mean(Var);
    Avg(j)=avg;
end

% 4th
[tg,index]=min(Avg);
j=1;
for i=NB+1:length(y2)
     for m=1:NA
      X(1,m)=-y2(i-m);
    end
    for m=1:NB
        X(2,m)=u2(i-m);
    end
    X1=[X(1,:),X(2,:)];
    X1=X1';
    f=F{10};
    Ya=f*X1;
    Ya_f(j)=Ya;
    j=j+1;
end

%% 增加噪音部分
% 1、均匀分布噪声
Ya_f2 = Ya_f + 0.1*(2*rand(size(Ya_f))-1).*Ya_f; 

% 2、正态分布噪声
Ya_f3 = Ya_f + 0.1*randn(size(Ya_f)).*(Ya_f);


%% plot部分，前后对比进行判断
% Draw images for comparison

% 1、使用原始模型预测
plot(Ya_f);

% 2、使用加噪后的模型进行预测
% plot(Ya_f2);
% plot(Ya_f3);
hold on

% 原始数据进行对比
plot(y2);
legend('pre','real');
hold on;