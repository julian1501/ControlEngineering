
d = simout(:,1);
u = simout(:,2);

nfft = 5000;
window = hann(nfft);
noverlap = nfft/2;

[S,F] = tfestimate(u,d,window,noverlap,nfft,Fs);

TF = S.^-1 - 1;

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

