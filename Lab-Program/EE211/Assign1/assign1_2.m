%% Assign1-2 2022/05/03 Hanlin Cai
% The least square method was used for fitting

clear;clc;close all;

%% 1、导入建模训练集
% Import the modeling training set

data1 = importdata('2data/Gr3.txt');
data2 = data1.data;
data3 = data2(1:1000,:);
data4 = data2(2001:3000,:);

t1 = data3(:,1); %time_1
u1 = data3(:,2); %input_1
y1 = data3(:,3); %output_1

t2 = data4(:,1); %time_2
u2 = data4(:,2); %input_2
y2 = data4(:,3); %output_2

data4 = importdata('2data/Gr13.txt');
data5 = data4.data;
data6 = data5(1:1000,:);

t3 = data6(:,1); %time_1
u3 = data6(:,2); %input_1
y3 = data6(:,3); %output_1

% % plot(t1,y1,'o')


%% 使用最小二乘法计算中间参数
% The intermediate parameters were calculated using the least square method
% y1 = O*(u1)
% 定义O为中间变量 Define O as the intermediate variable

u11 = (u1)';
u22 = (u2)';
u33 = (u3)';

% O = ( (u1)'*u1 )^(-1) * (u1)' * y1;
O1 =  ( (u11)*u1 )^(-1) * (u11) * y1; % O1 = 0.0789
O2 =  ( (u22)*u2 )^(-1) * (u22) * y2; % O2 = 0.0668
O3 =  ( (u33)*u3 )^(-1) * (u33) * y3; % O3 = 0.4267


