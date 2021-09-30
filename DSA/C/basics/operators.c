/*
    ----------------------------------------------
    Arithmetic Operator     = +, -, *, /, %
    ----------------------------------------------
    Increment/ Decrement    = ++, --
    ----------------------------------------------
    Relational Operator     = ==, <, >, !=, <=, >=  (return either true or false)
    ----------------------------------------------
    Logical Operator        = &&. ||, !             (know short circuit logic)
    ----------------------------------------------
    Bitwise Operator        = &, ^, |, ~, >>, <<
    ----------------------------------------------
    Assignment Operator     = =, +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^= 
    ----------------------------------------------
    Other Operator          = ?:, &, *, sizeof(), ( , ), (type)
    ----------------------------------------------

    imp. When PRECEDENCE of operator are same, ASSOCIATIVITY comes in picture.

    Comma (,) is a very tricky operator. (explore it) 

    lvalue
        - simply means an object that has an identifiable location in memory (having an address)
        - must be variable, since needs to have capability to hold the value
    rvalue
        - simply means an object that has no identifiable location in memory
        - can be expression or values

    imp. have a general idea about Lexical Analysis (helps, evaluating the meaning of the expression)

    # Associativity & Precedence
    ----------------------------------------------------------------------------------
    Parenthesis etc.    |L to R|    (), [], ( ->, . ), (Post++, Post--)
    ----------------------------------------------------------------------------------
    Unary               |R to L|    +, -, ++Pre, --Pre, !, ~, *, &, sizeof(), (type)
    ----------------------------------------------------------------------------------
    Multiplicative      |L to R|    *, /, %
    -----------------------------------------------
    Additive            |L to R|    +, -
    -----------------------------------------------
    Bitwise Shift       |L to R|    <<, >>
    -----------------------------------------------
    Relational          |L to R|    <, >, <=, >=
    -----------------------------------------------
    Equality            |L to R|    ==, !=
    -----------------------------------------------
    Bitwise AND         |L to R|    &
    -----------------------------------------------
    Bitwise XOR         |L to R|    ^
    -----------------------------------------------
    Bitwise OR          /L to R/    |
    -----------------------------------------------
    Logical AND         /L to R/    &&
    -----------------------------------------------
    Logical OR          /L to R/    ||
    -----------------------------------------------
    Conditional         /R to L/    ?:
    ------------------------------------------------------------------------------
    Assignment          /R to L/    =, +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=
    ------------------------------------------------------------------------------
    , (comma)           /L to R/    ,
    -----------------------------------------------

*/