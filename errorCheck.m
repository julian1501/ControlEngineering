function [rms,peak] = errorCheck(error,Ts)
    samples = max(size(error));
    Tsim = Ts*samples;

    rms = (1/Tsim)*trapz(error.^2);
    peak = max(error);
end