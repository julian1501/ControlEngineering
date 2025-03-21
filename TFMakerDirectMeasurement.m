% measurement = SPERTE_Measure_And_Collect(p,2,160000,"IntroductionExperiment",1);
input = simout(:,1);
output = simout(:,2);

windowSize = 5000;
window = hann(windowSize);
noverlap = windowSize/2;


[TF, F] = tfestimate(input,output,window,noverlap,windowSize,Fs);

close all;

tiledlayout(2,1);

nexttile()
loglog(F,abs(TF))
grid on;
ylabel("Magnitude [dB]")
yline(1)

nexttile()
semilogx(F,(180/pi)*angle(TF))
grid on;
ylabel("Phase [deg]")
xlabel("Frequency [Hz]")

