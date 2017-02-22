This is a simple expression evaluator in C during my time at the January Piscine. 

To create the binary output and clean the folder:
```
make all
make fclean
```

To use the evaluator, the expression needs to contained inside quotation marks.

Example: `./eval_expr "5 + (5 / 4)" `

Spacing only matters in the case of negative numbers. If a space exists between the sign and number the evaluator will not take the sign into account
