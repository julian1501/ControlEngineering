%% Make TF data from measurement data
% measurement = SPERTE_Measure_And_Collect(p,2,600000,"IntroductionExperiment",1);
% measurement = measurement(10000:end,:);
input = measurement(:,1);
output = measurement(:,2);

% input = simout(:,1);
% output = simout(:,2);

nfft = 8000;
window = hamming(nfft);
noverlap = nfft/2;

[TF, F] = tfestimate(input,-output,window,noverlap,nfft,Fs);
Coherence = mscohere(input,-output,window,noverlap,nfft,Fs);

TF = TF(3:end,:);
F = F(3:end,:);
Coherence = Coherence(3:end,:);

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
yline(0.9)
ylabel('Coherence [-]')
xlabel("Frequency [Hz]")

