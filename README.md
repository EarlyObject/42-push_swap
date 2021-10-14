## :four::two: push_swap project  
### Game rules  
***
The game is composed of 2 stacks named a and b.  
To start with:
* a contains a random number of either positive or negative numbers without any duplicates.
* b is empty

The goal is to sort in ascending order numbers into stack a.  
To do this you have the following operations at your disposal:<br/>
:keyboard:  
*sa:* swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.  
*sb:* swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
*ss:* sa and sb at the same time.  
*pa:* push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.  
*pb:* push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.  
*ra:* rotate a - shift up all elements of stack a by 1. The first element becomes the last one.  
*rb:* rotate b - shift up all elements of stack b by 1. The first element becomes the last one.  
*rr:* ra and rb at the same time.  
*rra:* reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.  
*rrb:* reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.  
*rrr:* rra and rrb at the same time.<br/>
<hr style="border:2px red"> </hr>

>This project contains 2 programs:  
*The first*, named [checker](/checkers) which takes integer arguments and reads instructions on the standard output. Once read,checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.  
*The second* one called push_swap which calculates and displays on the standard output the smallest program using push_swap instruction language that sorts integer arguments received.  

:link:[Here](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a/) you can read a nice article explaining push_swap.  
:link:42 push_swap subject is [here](/subject/push_swap.en.subject.pdf).  
