# Lab Assignment 4 - Numerical Methods Lab

**Department:** Computer Science & Engineering  
**Institution:** International Islamic University Chittagong  
**Course:** CSE 4746 Numerical Methods Lab  
**Opening Statement:**  
_Bismillahir Rahmanir Rahim_

---

## Overview

This lab assignment focuses on curve fitting and solving ordinary differential equations (ODEs) using classical numerical techniques. It includes five problems covering least squares methods and numerical approaches for solving differential equations such as Euler’s and Runge-Kutta methods.

---

## Assignment Problems

### Problem 1: Least Squares Line Fit

**Description:**  
Write a program to find the least squares line of the form  
\[
y = a + bx
\]  
for the given dataset:

| x  | -2 | -1 | 0 | 1 | 2 |
|----|----|----|---|---|---|
| y  | 1  | 2  | 3 | 4 | 5 |

---

### Problem 2: Least Squares Parabola Fit

**Description:**  
Write a program to find the least squares parabola of the form  
\[
y = a + bx + cx^2
\]  
for the dataset:

| x  | 2  | 4  | 6  | 8  |
|----|----|----|----|----|
| y  | 1.4 | 2.0 | 2.4 | 2.8 |

---

### Problem 3: Exponential Curve Fit

**Description:**  
Write a program to find the best values of **a** and **b** for the exponential relation  
\[
y = ae^{bx}
\]  
using the data:

| x  | 2 | 10 | 26 | 61 |
|----|----|----|----|----|
| y  | 600 | 500 | 400 | 350 |

---

### Problem 4: Euler’s Method for ODEs

**Description:**  
Solve the differential equation  
\[
\frac{dy}{dx} = x^3 + y, \quad y(0) = 1
\]  
Compute \( y(0.02) \) using Euler’s Method with step size \( h = 0.01 \).

---

### Problem 5: Runge-Kutta Method

**Description:**  
Solve the differential equation  
\[
\frac{dy}{dx} = x + y, \quad y(0) = 1
\]  
Compute \( y(0.1) \) and \( y(0.2) \) using **Runge-Kutta Method** of 4th order with step size \( h = 0.1 \).

---
