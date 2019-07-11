set logscale y
plot [80:300] [0.2:100000000] "factoring.dat" w l
replot "factoring.dat" w p

pause 1000
