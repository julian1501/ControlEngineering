measurement = SPERTE_Measure_And_Collect(p,2,600000,"IntroductionExperiment",1);
measurement = measurement(10000:end,:);
error_motor = measurement(:,2);
error_load = measurement(:,1);

[rms_e_motor, peak_e_motor] = errorCalc(error_motor,Ts);
fprintf("Root mean square error of the motor: %d \n",rms_e_motor);
fprintf("Peak error of the motor: %d \n",peak_e_motor);
[rms_e_load,  peak_e_load ] = errorCalc(error_load, Ts);
fprintf("Root mean square error of the load: %d \n",rms_e_load);
fprintf("Peak error of the load: %d \n",peak_e_load);

function [rms,peak] = errorCalc(error,Ts)
    samples = max(size(error));
    Tsim = Ts*samples;

    rms = (1/Tsim)*trapz(error.^2);
    peak = max(error);
end