% use kattio.pl
[kattio].
:- use_module(library(clpq)).

calc(A1, A2, A3) :-
    read_int(B1), read_int(B2), read_int(B3),
    read_int(C1), read_int(C2), read_int(C3),
    read_int(D1), read_int(D2), read_int(D3),
    (({
        A1*X1+B1*X2+C1*X3 = D1, 
        A2*X1+B2*X2+C2*X3 = D2, 
        A3*X1+B3*X2+C3*X3 = D3, 
        X1 > 0, X2 > 0, X3 > 0
    },
    minimize(X1+X2+X3)
    ) ->
        writeln("YES");
        writeln("NO")
    ).

main :-
 repeat,
 read_int(A1), read_int(A2), read_int(A3),
 ((A1 = 0, A2 = 0, A3 = 0) ;
     calc(A1, A2, A3),
     fail
 ).

