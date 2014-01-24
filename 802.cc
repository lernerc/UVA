// all with no solution mean no
// all with positive solutions are true
// for case with one basis it has to be a multiple
// for case with two bases it has to be + + on the alphas, it will not work with + - and - - is not possible
// for case with three bases it can be + + +,
// alloys
//  A   B   C
// a11 a12 a13
// a21 a22 a23
// . . .
// am1 am2 am3

// linear program
// g1*a11 + g2*a21 + g3*a31 + . . . + gm*am1 = A
// g1*a12 + g2*a22 + g3*a32 + . . . + gm*am2 = B
// g1*a13 + g2*a23 + g3*a33 + . . . + gm*am3 = A


// scale A B C so that A + B + C = 1
// then g1 + g2 + g3 + . . . + gm = 1

// everything in the convex hull of the alloys can be a positive linear combination
