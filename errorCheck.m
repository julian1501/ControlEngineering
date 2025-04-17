%% Measure the error
% measurement = SPERTE_Measure_And_Collect(p,2,300000,"Reference_model_Control_Engineering",0);
measurement = simout(:,:);
error_load = measurement(:,2);
acc = measurement(:,3);

error_load_cv = error_load(acc == 0);

ham_size = 50;
error_load_ham  = hampel(error_load_cv,ham_size,2);



%% Analyze the plots
close all;
% tiledlayout(1,2);
% nexttile()
% plot(error_load_cv.*1e3)
% title('Measured error')
% ylabel('Error [mrad]')
% xlabel('Sample [-]')
% grid on;
% nexttile()
% plot(error_load_ham.*1e3);
% title('Hampel filtered error')
% xlabel('Sample [-]')
% grid on;

% [rms_e_motor, peak_e_motor] = errorCalc(error_motor_ham);
% fprintf("Root mean square error of the motor: %d \n",1e3.*rms_e_motor);
% fprintf("Peak error of the motor: %d \n",1e3.*peak_e_motor);
[rms_e_load,  peak_e_load ] = errorCalc(error_load_cv);
fprintf("Root mean square error of the load: %d \n",1e3.*rms_e_load);
fprintf("Peak error of the load: %d \n",1e3.*peak_e_load);

%% Calculate PSD 
nfft = 8000;
window = hann(nfft);
noverlap = nfft/2;
[pxx,f] = pwelch(error_load_cv,window,noverlap,F,Fs);
% Assess the PSD to asses the error 
figure; 
plot(f,10*log10(pxx));
title("Power Spectral Density of Error");
xlabel("Frequency (Hz)");
ylabel("Power (dB)");
xlim([0,50]);
grid on;

function [rms,peak] = errorCalc(error)
    samples = max(size(error));
    rms = sqrt((1/samples)*sum(error.^2)) ;
    peak = max(error);
end