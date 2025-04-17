err = simout(:,2);
pos = simout(:,3);

cycles = pos < 5.593392416e-11;
zeropos = find(cycles == 1);

err_111 = err(zeropos(18):zeropos(22));
plot(err_111)