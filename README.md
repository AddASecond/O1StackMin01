# O1StackMin01

# log 2016/08/29
The function of this small program is to Find the Minuimum value of a Stack with only O(1) time complexity.
Function is totally completed and OK but now the 1st edition has several tiny limitations:
1.Only int--but easy to change to other data types;
2.Some input/output statement is not right, remain to change.

# main idea of algorithm
The normal way to find minimum value in a stack is traversal,where complexity is O(n).
The main idea of O(1) methed is to build another stack b to push/pop simutaneously with stack a,
but only save the minimum value.
For example, [9,16,8,45,5] is already pushed is a, then b is [9,9,8,8,5].
The stack is realized using array, unassigned array value is set to 0xFFFF FFFF CCCC CCCC.
