plot "time02.dat" u 1:2 w p
replot "time02.dat" u 1:3 w p
replot "time02.dat" u 1:5 w p
#replot "time02.dat" u 1:9 w p

replot "time02.dat" using 1:3 lw 3 lt 2 smooth sbezier
replot "time02.dat" using 1:5 lw 3 lt 3 smooth sbezier

pause 1000
