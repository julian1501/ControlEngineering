measurement = SPERTE_Measure_And_Collect(p,2,300000,"Reference_model_Control_Engineering",0);
measurement = measurement(10000:end-10000,:);
error_motor = measurement(:,2);
error_load = measurement(:,1);

ham_size = 500;
error_motor_ham = hampel(error_motor,ham_size,1.5);
error_load_ham  = hampel(error_load,ham_size,1.5);

close all;
tiledlayout(1,2);
nexttile()
plot(error_load.*10e3)
title('Measured error')
ylabel('Error [rad]')
xlabel('Sample [-]')
grid on;
nexttile()
plot(error_load_ham.*10e3);
title('Hampel filtered error')
xlabel('Sample [-]')
grid on;

[rms_e_motor, peak_e_motor] = errorCalc(error_motor_ham);
fprintf("Root mean square error of the motor: %d \n",10e3.*rms_e_motor);
fprintf("Peak error of the motor: %d \n",10e3.*peak_e_motor);
[rms_e_load,  peak_e_load ] = errorCalc(error_load_ham);
fprintf("Root mean square error of the load: %d \n",10e3.*rms_e_load);
fprintf("Peak error of the load: %d \n",10e3.*peak_e_load);

function [rms,peak] = errorCalc(error)
    samples = max(size(error));
    rms = (1/samples)*trapz(error.^2);
    peak = max(error);
end