function [refPos, refVel, refAcc] = refGen(t, Tr, Tta)
    turn_margin = 2.5;

    % Compute turnaround and constant velocity times
    Tcv = Tr - Tta;
    Tt = 0.5*Tta;
    assert(abs(Tta + Tcv - Tr) < 1e-6, 'Turnaround and constant velocity times do not add up to Tr.')

    % polynomial coefficients
    a = -3.75; b = 15; c = 0; d = -30; e = -60;

    t = mod(t, Tr);

    if t <= 0.25 * Tcv
        % Constant velocity down
        refPos = -(240 / Tcv) * t;
        refVel = -(240 / Tcv);
        refAcc = 0;

    elseif t <= (0.25 * Tcv + Tt)
        % Turnaround: bottom to top (quintic polynomial)
        t_turn = t - 0.25 * Tcv;
        refPos = a*t_turn^4 + b*t_turn^3 + c*t_turn^2 + d*t_turn + e; 
        refVel = 4*a*t_turn^3 + 3*b*t_turn^2 + 2*c*t_turn + d;
        refAcc = 12*a*t_turn^2 + 6*b*t_turn + c;

    elseif t <= (0.75 * Tcv + Tt)
        % Constant velocity up
        refPos = (240 / Tcv) * t - 120 * (1 + Tta / Tcv);
        refVel = (240 / Tcv);
        refAcc = 0;

    elseif t <= (0.75 * Tcv + Tta)
        % Turnaround: top to bottom (quintic polynomial)
        t_turn = t - (0.75 * Tcv + Tt);
        refPos = -a*t_turn^4 - b*t_turn^3 - c*t_turn^2 + -d*t_turn - e; 
        refVel = -4*a*t_turn^3 - 3*b*t_turn^2 - 2*c*t_turn + -d;
        refAcc = -12*a*t_turn^2 - 6*b*t_turn - c;

    elseif t <= Tr
        % Constant velocity down
        refPos = -(240 / Tcv) * t + 240 * (1 + Tta / Tcv);
        refVel = -(240 / Tcv);
        refAcc = 0;

    else
        refPos = 0;
        refVel = 0;
        refAcc = 0;
    end
end
