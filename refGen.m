function refPos = refGen(t,Tr,Tcv,Tta)
    assert(Tta + Tcv == Tr,'Turn around and constant velocity times do not add up to Tr.')
    t = mod(t,Tr);
    turn_margin = 2.5;

    if t <= 0.25*Tcv
        % const vel down
        refPos = -(240/Tcv)*t;
    elseif 0.25*Tcv < t && t <= (0.25*Tcv + 0.5*Tta)
        % turn around to top
        t_turn = t - 0.25 * Tcv;
        refPos = -60 -turn_margin * sin(pi * t_turn / 0.5*Tta);
    elseif (0.25*Tcv + 0.5*Tta) < t && t <= (0.75*Tcv + 0.5*Tta)
        % const vel up
        refPos = (240/Tcv)*t - 120*(1 + Tta/Tcv);
    elseif (0.75*Tcv + 0.5*Tta) < t && t <= (0.75*Tcv + Tta)
        % turn around to bottom
        t_turn = t - (0.75 * Tcv + 0.5 * Tta);
        refPos = 60 + turn_margin * sin(pi * t_turn / 0.5*Tta);
    elseif (0.75*Tcv + Tta) < t && t <= Tr
        % const vel down
        refPos = -(240/Tcv)*t + 240*(1 + Tta/Tcv);
    end
end