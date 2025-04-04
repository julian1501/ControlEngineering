% calculate coeffs
Tr = 12;
Tta = 4;

Tcv = Tr - Tta;
Tt = Tta/2;
A = [0 0 0 0 1;
     0 0 2 0 0;
     0 0 0 1 0;
     12*Tt^2 6*Tt 2 0 0;
     4*Tt^3 3*Tt^2 2*Tt 1 0];

B = [-60; 0; -240/Tcv; 0; 240/Tcv];
coefs = linsolve(A,B);