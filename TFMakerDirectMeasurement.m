% measurement = SPERTE_Measure_And_Collect(p,2,160000,"IntroductionExperiment",1);
input = simout(:,1);
output = simout(:,2);

windowSize = 5000;
window = hann(windowSize);
noverlap = windowSize/2;


[TF, F] = tfestimate(input,output,window,noverlap,windowSize,Fs);
Coherence = mscohere(input,output,window,noverlap,windowSize,Fs);

close all;

tiledlayout(3,1);

nexttile()
loglog(F,abs(TF))
grid on;
ylabel("Magnitude [dB]")
yline(1)

nexttile()
semilogx(F,(180/pi)*angle(TF))
grid on;
ylabel("Phase [deg]")

nexttile()
semilogx(F,Coherence)
ylabel('Coherence [-]')
xlabel("Frequency [Hz]")

