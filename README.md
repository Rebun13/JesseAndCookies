# JesseAndCookies

## Description

Jesse loves cookies and wants the sweetness of some cookies to be greater than value _k_. To do this, two cookies with the least sweetness are repeatedly mixed. This creates a special combined cookie with:

$sweetness = (1 x LeastSweetCookie + 2 x 2^{nd} LeastSweetCookie)$

This occurs until all the cookies have a _sweetness ≥ k_.

Given the sweetness of a number of cookies, determine the minimum number of operations required. If it is not possible, return _-1_.

## Returns

- int: the number of iterations required or 

## Input 

- The first line has two space-separated integers, _n_ and _k_, the size of _A[]_ and the minimum required sweetness respectively.

- The next line contains _n_ space-separated integers, _A[i]_. 
