# LaTeX 学习一本通

## 一本通版本控制

1. *版本一  1030 (案例1-11)*
2. *版本二 1031 (实战训练)*



---

## LaTeX注意事项

1. 英文字母只有在表示变量的时候才使用斜体，其他情况在LaTeX里都是直立体；
2. 斜杆slash，反斜杠backslash；
3. 运算符中名称中超过一个字母时应采用直立体





---

[TOC]





---

## 1、希腊字母

$$
\delta,\lambda\\
\Delta,\Lambda\\
\Alpha,\Beta\\
\phi,\varphi\\
\epsilon,\varepsilon\\
π,\pi\\
$$

### Fig1 希腊字母表

<img src="https://s2.loli.net/2022/10/31/xWVQjJaIT1n4BvH.png" alt="截屏2022-10-31 16.26.27" style="zoom: 20%;" />



---

## 2、上下标

$$
a^2,a_1\\
x^{x+z},p_{i,j}\\
x_i,x_{\rm i},x_{\text i}\\
\text{A B}\\\\
\text e,e\\

a^{a+b}_{a+b}
$$



---

## 3、分式与根式

1. frac
2. sqrt

$$
\frac {1} {2},\frac 1 2\\
\frac 1 {x+y}\\
\frac {x+1} {x+y+1}\\
\\

\sqrt {2}\\
\sqrt {x+y}\\
\sqrt [3] {100}\\
$$



---

## 4、各类运算符

### (a) 标准运算符

$$
+-\\
\times,\cdot,\div\\
\pm,\mp\\
<>\\
\ge,\le\\
\gg,\ll\\
\ne,\approx,\equiv\\
\cap,\cup,\in,\notin,\subseteq,\subsetneqq,\varnothing\\
\forall,\exists,\nexists\\
\because,\therefore\\
\mathbb R,\R,\Q,\Z,\N\\
\mathcal F,\mathscr F
$$

### (b) 省略、极限

$$
\cdots,\vdots,\ddots\\
\infty,\partial,\nabla,\propto,\degree\\
$$

*∂*：opt + D

### (c) 三角函数、求极限

$$
\sin x,\sec x\\
\cosh x\\
\log_2 x,\ln x,\lg x\\
\lim_{x \to 0} \frac {x}{\sin x}\\
\max x,\min y\\
\text {MSE(x)： } 均方误差
$$



---

## 5、大型运算符

### (a) 求和、极限

$$
\sum,\prod\\
\sum_i,\sum_j\\
\sum_{i=0}^N\\
\frac {\sum\limits_{i=1}^n x_i} {\prod\limits_{i+1}^n x^i}
$$

### (b) 积分、间距

$$
\int,\iint,\iiint\\
\int_{-\infty}^0 f(x) \, \text d x\\
\int_{-\infty}^0 f(x) \, \, \text d x\\
\\
\\
a\, a\\
a\ a\\
a\quad a\\
a\qquad a\\
$$



---

## 6、标注符号

$$
\vec x,\overrightarrow {AB}\\
\\
\bar x,\overline {AB}\\
$$

![截屏2022-10-31 16.49.10](https://s2.loli.net/2022/10/31/zGuvcD3qsoaknRW.png)





---

## 7、箭头

$$
\leftarrow,\Rightarrow,\Leftarrow,\longleftarrow
$$



<img src="https://s2.loli.net/2022/10/31/uz4Psk1yWhnBb9Z.png" alt="截屏2022-10-31 16.55.44" style="zoom:20%;" />





---

## 8、括号与定界符


$$
([a,b]),\{A,B\}\\
\lceil,\rceil,\lfloor,\rfloor\\
\left(0,\frac 1 a\right]\\\\
\frac {∂f} {∂x}|_{x=0}\\
\left.\frac {∂f} {∂x}\right|_{x=0}
$$





---

## 9、多行公式

line 环境
$$
\begin{align}
a= b+c+f\\
= r+f\\
\\
a&= b+c+f\\
&= r+f
\end{align}
$$







---

## 10、大括号

$$
f(x)=

\begin{cases}

\sin x,& -π\le x \le π\\
0,& \text{other}
\end{cases}
$$







---

## 11、矩阵

1. matrix 无外包围
2. bmatrix 方括号包围
3. pmatrix 圆括号包围
4. vmatrix 直线包围

$$
\begin{matrix}

a & b  & \cdots & c\\
\vdots & \vdots & \ddots & \vdots\\
e & f  & \cdots & g

\end{matrix}
$$

$$
\begin{bmatrix}

a & b  & \cdots & c\\
\vdots & \vdots & \ddots & \vdots\\
e & f  & \cdots & g

\end{bmatrix}
$$

$$
\begin{pmatrix}

a & b  & \cdots & c\\
\vdots & \vdots & \ddots & \vdots\\
e & f  & \cdots & g

\end{pmatrix}
$$

$$
\begin{vmatrix}

a & b  & \cdots & c\\
\vdots & \vdots & \ddots & \vdots\\
e & f  & \cdots & g

\end{vmatrix}
$$

**直立体表示**：
$$
\bf A, \bf B
$$








---

## **实战演练**

### (1) exp

$$
f(x) = \frac 1 {\sqrt{2\pi} \sigma} {\rm e} ^ {-\frac {(x-\mu)^2}{2\sigma ^ 2}}\\\\
f(x) = \frac 1 {\sqrt{2\pi} \sigma} \exp \left[ {-\frac {(x-\mu)^2}{2\sigma ^ 2}} \right]\\
$$

### (2) 积分

$$
x(n)=\frac{1}{2 \pi} \int_{-\pi}^\pi X\left(\mathrm{e}^{\mathrm{j} \omega}\right) \mathrm{e}^{\mathrm{j} \omega n} \mathrm{~d} \omega
$$

### (3) 多行

$$
\begin{aligned}
\vec{B}(\vec{r}) &=\frac{\mu_0}{4 \pi} \oint_C \frac{I \mathrm{~d} \vec{l} \times \vec{R}}{R^3} \\
&=\frac{\mu_0}{4 \pi} \int_V \frac{\overrightarrow{J_V} \times \vec{R}}{R^3} \mathrm{~d} V^{\prime}
\end{aligned}
$$

## 推荐工具: Mathpix Snipping Tool

<img src="https://s2.loli.net/2022/10/31/2VzcUZOiJwgpCjo.png" alt="截屏2022-10-31 17.07.48" style="zoom: 33%;" />









