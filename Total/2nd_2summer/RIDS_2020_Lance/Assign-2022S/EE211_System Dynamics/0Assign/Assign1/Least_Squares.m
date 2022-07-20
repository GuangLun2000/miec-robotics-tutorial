%% 实现最小二乘法的四种方法
x=[0.1;0.3;0.4;0.75;0.9]; 
y=[1.7805;2.2285;2.3941;3.2226;3.5697];
plot(x,y,'o')
% xaxis(0,1);
% yaxis(1.6,3.7);
hold on;

%% 方法1：代数方法计算
% N=length(x);
% k=(sum(y.*x)-N*mean(y)*mean(x))/(sum(x.^2)-N*mean(x)^2);
% b=mean(y)-k*mean(x);
% x_line1=linspace(0,1,101);
% y_line1=k*x_line1+b;
% plot(x_line1,y_line1,'Color','r','LineWidth',1)

%% 方法2：伪逆计算
% N=length(x);
% X=[x,ones(N,1)];
% Y=y;
% K=inv(X'*X)*X'*Y;
% k=K(1);
% b=K(2);
% x_line2=linspace(0,1,101);
% y_line2=k*x_line2+b;
% plot(x_line2,y_line2,'Color','r','LineWidth',1)

%% 方法3：利用matlab自带的lsqcurvefit函数计算
% fun=@(K,x)K(1)*x+K(2);
% K0=[1,1];
% K=lsqcurvefit(fun, K0, x,y)
% k=K(1);
% b=K(2);
% x_line3=linspace(0,1,101);
% y_line3=k*x_line3+b;
% plot(x_line3,y_line3,'Color','r','LineWidth',1)

%% 方法4：利用matlab自带的polyfit函数计算（多项式函数拟合）
K=polyfit(x,y,1);
k=K(1);
b=K(2);
x_line4=linspace(0,1,101);
y_line4=k*x_line4+b;
plot(x_line4,y_line4,'Color','r','LineWidth',1)

%% 一些备注



