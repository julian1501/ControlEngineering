t = simout.time;
d = simout.signals.values(:,1);
u = simout.signals.values(:,2);

nfft = 400;
window = hann(nfft);
noverlap = 0.5*nfft;

[S,F] = tfestimate(d,u,window,noverlap,nfft,Fs);

Kp = 1.2; Kd = 0.1;
C = Kp + Kd.*F;

TF = C.^-1.*(S.^-1 - 1);

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