# plot_psd.gnu — plot PSD from demo.cpp output

set title "Welch PSD Estimate"
set xlabel "Frequency (Hz)"
set ylabel "Power Spectral Density"
set grid
set key left top
set style line 1 lc rgb '#0060ad' lw 2

plot "psd_data.txt" using 1:2 with lines linestyle 1 title "PSD"
pause -1 "Press Enter to exit"
