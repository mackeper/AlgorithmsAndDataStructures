% use kattio.pl
[kattio].
:- use_module(library(clpq)).
:- debug.

calc_lp(A, B, M, O) :-
    ((A =:= 0, B =:= 0) ->
        writeln("0")
        ;
        (
            {
                M >= X1+X2, 
                2*X1+X2 >= O, 
                X1 >= 1, X2 >= 1
            },
            maximize(A*X1+B*X2),
            R is A*X1+B*X2,
            writeln(R)
        )
    ).

main :-
 read_int(A), read_int(B), read_int(M), read_int(O),
     calc_lp(A, B, M, O).

