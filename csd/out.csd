<CsoundSynthesizer>
<CsOptions>
-odac -d -O null
</CsOptions>
<CsInstruments>
; ====================
sr = 44100
kr = 441
ksmps = 100
nchnls = 2
; ====================

; =======================================
instr 1 ; (short atack, long release)
; =======================================
iamp = p5 * 25000
ifreq = cpspch(p4)
itable = 1

kamp linen 1.0, 0.05, p3, (0.9 * p3)
asig oscil iamp, ifreq, itable
aout = kamp * asig
outs aout, aout
; =======================================
endin
; =======================================
; =======================================
instr 2 ; (medium atack, short release)
; =======================================
iamp = p5 * 25000
ifreq = cpspch(p4)
itable = 2

kamp linen 1.0, 0.1, p3, (0.1 * p3)
asig oscil iamp, ifreq, itable
aout = kamp * asig
outs aout, aout
; =======================================
endin
; =======================================
; =======================================
instr 3 ; (long atack, long release)
; =======================================
iamp = p5 * 25000
ifreq = cpspch(p4)
itable = 3

kamp linen 1.0, (0.4 * p3), p3, (0.3 * p3)
asig oscil iamp, ifreq, itable
aout = kamp * asig
outs aout, aout
; =======================================
endin
; =======================================
; =======================================
instr 4 ; (short atack, medium release)
; =======================================
iamp = p5 * 25000
ifreq = cpspch(p4)
itable = 4

kamp linen 1.0, 0.03, p3, (0.4 * p3)
asig oscil iamp, ifreq, itable
aout = kamp * asig
outs aout, aout
; =======================================
endin
; =======================================
</CsInstruments>
<CsScore>
; ========================================
; Function Tables:
; ========================================
f1 0 4096 10 1 .9 .1 .8 .2 .7 .3 .6 .4 .5
f2 0 4096 10 1 0 1 0 1 0 1 0 1
f3 0 4096 10 .1 .3 .5 .7 .5 .3 .1
f4 0 4096 10 .8 .6 .4 .2 .4 .6 .8

; ========================================

; ========================================
; VOICE: 0, Instr.: 2
; ========================================

i2	0.000	0.391	9.04		1.000	
i2	0.391	0.391	9.02		1.000	
i2	0.781	0.781	9.00		1.000	
i2	1.562	0.781	9.05		1.000	
i2	2.344	0.781	9.05		1.000	
i2	3.125	0.781	9.04		1.000	
i2	3.906	0.391	9.05		1.000	
i2	4.297	0.391	9.07		1.000	
i2	4.688	1.562	9.02		1.000	
i2	6.250	0.391	9.04		1.000	
i2	6.641	0.391	9.02		1.000	
i2	7.031	0.781	9.00		1.000	
i2	7.812	0.781	9.05		1.000	
i2	8.594	0.781	9.05		1.000	
i2	9.375	0.391	9.04		1.000	
i2	9.766	0.391	9.02		1.000	
i2	10.156	0.391	9.00		1.000	
i2	10.547	0.391	8.11		1.000	
i2	10.938	1.562	9.00		1.000	
i2	12.500	0.781	9.07		1.000	
i2	13.281	0.391	9.09		1.000	
i2	13.672	0.391	9.07		1.000	
i2	14.062	0.781	9.05		1.000	
i2	14.844	0.781	9.02		1.000	
i2	15.625	0.781	9.04		1.000	
i2	16.406	0.391	9.05		1.000	
i2	16.797	0.391	9.04		1.000	
i2	17.188	1.562	9.02		1.000	
i2	18.750	0.781	9.07		1.000	
i2	19.531	0.391	9.09		1.000	
i2	19.922	0.391	9.07		1.000	
i2	20.312	0.391	10.00		1.000	
i2	20.703	0.391	9.11		1.000	
i2	21.094	0.781	9.09		1.000	
i2	21.875	0.391	9.07		1.000	
i2	22.266	0.391	9.05		1.000	
i2	22.656	0.391	9.04		1.000	
i2	23.047	0.391	9.02		1.000	
i2	23.438	1.562	9.00		1.000	
i2	25.000	0.391	8.04		0.500	
i2	25.391	0.391	8.11		0.500	
i2	25.781	0.781	8.04		0.500	
i2	26.562	0.781	8.05		0.500	
i2	27.344	0.781	8.09		0.500	
i2	28.125	0.781	8.11		0.500	
i2	28.906	0.391	8.09		0.500	
i2	29.297	0.391	8.04		0.500	
i2	29.688	1.562	8.11		0.500	
i2	31.250	0.391	8.04		0.500	
i2	31.641	0.391	8.05		0.500	
i2	32.031	0.781	8.09		0.500	
i2	32.812	0.781	8.05		0.500	
i2	33.594	0.781	8.02		0.500	
i2	34.375	0.391	8.07		0.500	
i2	34.766	0.391	8.02		0.500	
i2	35.156	0.391	8.09		0.500	
i2	35.547	0.391	8.04		0.500	
i2	35.938	1.562	8.00		0.500	
i2	37.500	0.781	8.04		0.500	
i2	38.281	0.391	8.02		0.500	
i2	38.672	0.391	8.00		0.500	
i2	39.062	0.781	8.02		0.500	
i2	39.844	0.781	8.05		0.500	
i2	40.625	0.781	8.04		0.500	
i2	41.406	0.391	8.05		0.500	
i2	41.797	0.391	8.00		0.500	
i2	42.188	1.562	8.05		0.500	
i2	43.750	0.781	8.07		0.500	
i2	44.531	0.391	8.02		0.500	
i2	44.922	0.391	8.00		0.500	
i2	45.312	0.391	8.07		0.500	
i2	45.703	0.391	8.11		0.500	
i2	46.094	0.781	9.02		0.500	
i2	46.875	0.391	8.11		0.500	
i2	47.266	0.391	8.09		0.500	
i2	47.656	0.391	8.04		0.500	
i2	48.047	0.391	8.03		0.500	
i2	48.438	1.562	8.04		0.500	
i2	50.000	0.391	9.04		1.000	
i2	50.391	0.391	9.02		1.000	
i2	50.781	0.781	9.00		1.000	
i2	51.562	0.781	9.05		1.000	
i2	52.344	0.781	9.05		1.000	
i2	53.125	0.781	9.04		1.000	
i2	53.906	0.391	9.05		1.000	
i2	54.297	0.391	9.07		1.000	
i2	54.688	1.562	9.02		1.000	
i2	56.250	0.391	9.04		1.000	
i2	56.641	0.391	9.02		1.000	
i2	57.031	0.781	9.00		1.000	
i2	57.812	0.781	9.05		1.000	
i2	58.594	0.781	9.05		1.000	
i2	59.375	0.391	9.04		1.000	
i2	59.766	0.391	9.02		1.000	
i2	60.156	0.391	9.00		1.000	
i2	60.547	0.391	8.11		1.000	
i2	60.938	1.562	9.00		1.000	
i2	62.500	0.781	9.07		1.000	
i2	63.281	0.391	9.09		1.000	
i2	63.672	0.391	9.07		1.000	
i2	64.062	0.781	9.05		1.000	
i2	64.844	0.781	9.02		1.000	
i2	65.625	0.781	9.04		1.000	
i2	66.406	0.391	9.05		1.000	
i2	66.797	0.391	9.04		1.000	
i2	67.188	1.562	9.02		1.000	
i2	68.750	0.781	9.07		1.000	
i2	69.531	0.391	9.09		1.000	
i2	69.922	0.391	9.07		1.000	
i2	70.312	0.391	10.00		1.000	
i2	70.703	0.391	9.11		1.000	
i2	71.094	0.781	9.09		1.000	
i2	71.875	0.391	9.07		1.000	
i2	72.266	0.391	9.05		1.000	
i2	72.656	0.391	9.04		1.000	
i2	73.047	0.391	9.02		1.000	
i2	73.438	1.562	9.00		1.000	
i2	75.000	0.781	9.04		1.000	
i2	75.781	0.781	9.02		1.000	
i2	76.562	1.562	9.00		1.000	
i2	78.125	1.562	9.05		1.000	
i2	79.688	1.562	9.05		1.000	
i2	81.250	1.562	9.04		1.000	
i2	82.812	0.781	9.05		1.000	
i2	83.594	0.781	9.07		1.000	
i2	84.375	3.125	9.02		1.000	
i2	87.500	0.781	9.04		1.000	
i2	88.281	0.781	9.02		1.000	
i2	89.062	1.562	9.00		1.000	
i2	90.625	1.562	9.05		1.000	
i2	92.188	1.562	9.05		1.000	
i2	93.750	0.781	9.04		1.000	
i2	94.531	0.781	9.02		1.000	
i2	95.312	0.781	9.00		1.000	
i2	96.094	0.781	8.11		1.000	
i2	96.875	3.125	9.00		1.000	
i2	100.000	1.562	9.07		1.000	
i2	101.562	0.781	9.09		1.000	
i2	102.344	0.781	9.07		1.000	
i2	103.125	1.562	9.05		1.000	
i2	104.688	1.562	9.02		1.000	
i2	106.250	1.562	9.04		1.000	
i2	107.812	0.781	9.05		1.000	
i2	108.594	0.781	9.04		1.000	
i2	109.375	3.125	9.02		1.000	
i2	112.500	1.562	9.07		1.000	
i2	114.062	0.781	9.09		1.000	
i2	114.844	0.781	9.07		1.000	
i2	115.625	0.781	10.00		1.000	
i2	116.406	0.781	9.11		1.000	
i2	117.188	1.562	9.09		1.000	
i2	118.750	0.781	9.07		1.000	
i2	119.531	0.781	9.05		1.000	
i2	120.312	0.781	9.04		1.000	
i2	121.094	0.781	9.02		1.000	
i2	121.875	3.125	9.00		1.000	
i2	125.000	0.391	9.04		1.000	
i2	125.391	0.391	9.02		1.000	
i2	125.781	0.781	9.00		1.000	
i2	126.562	0.781	9.05		1.000	
i2	127.344	0.781	9.05		1.000	
i2	128.125	0.781	9.04		1.000	
i2	128.906	0.391	9.05		1.000	
i2	129.297	0.391	9.07		1.000	
i2	129.688	1.562	9.02		1.000	
i2	131.250	0.391	9.04		1.000	
i2	131.641	0.391	9.02		1.000	
i2	132.031	0.781	9.00		1.000	
i2	132.812	0.781	9.05		1.000	
i2	133.594	0.781	9.05		1.000	
i2	134.375	0.391	9.04		1.000	
i2	134.766	0.391	9.02		1.000	
i2	135.156	0.391	9.00		1.000	
i2	135.547	0.391	8.11		1.000	
i2	135.938	1.562	9.00		1.000	
i2	137.500	0.781	9.07		1.000	
i2	138.281	0.391	9.09		1.000	
i2	138.672	0.391	9.07		1.000	
i2	139.062	0.781	9.05		1.000	
i2	139.844	0.781	9.02		1.000	
i2	140.625	0.781	9.04		1.000	
i2	141.406	0.391	9.05		1.000	
i2	141.797	0.391	9.04		1.000	
i2	142.188	1.562	9.02		1.000	
i2	143.750	0.781	9.07		1.000	
i2	144.531	0.391	9.09		1.000	
i2	144.922	0.391	9.07		1.000	
i2	145.312	0.391	10.00		1.000	
i2	145.703	0.391	9.11		1.000	
i2	146.094	0.781	9.09		1.000	
i2	146.875	0.391	9.07		1.000	
i2	147.266	0.391	9.05		1.000	
i2	147.656	0.391	9.04		1.000	
i2	148.047	0.391	9.02		1.000	
i2	148.438	1.562	9.00		1.000	

; ========================================
; END VOICE 0
; ========================================

; ========================================
; VOICE: 1, Instr.: 1
; ========================================

i1	23.438	0.391	9.11		1.000	
i1	23.828	0.391	9.09		1.000	
i1	24.219	0.781	9.07		1.000	
i1	25.000	0.781	10.00		1.000	
i1	25.781	0.781	10.00		1.000	
i1	26.562	0.781	9.11		1.000	
i1	27.344	0.391	10.00		1.000	
i1	27.734	0.391	10.02		1.000	
i1	28.125	1.562	9.09		1.000	
i1	29.688	0.391	9.11		1.000	
i1	30.078	0.391	9.09		1.000	
i1	30.469	0.781	9.07		1.000	
i1	31.250	0.781	10.00		1.000	
i1	32.031	0.781	10.00		1.000	
i1	32.812	0.391	9.11		1.000	
i1	33.203	0.391	9.09		1.000	
i1	33.594	0.391	9.07		1.000	
i1	33.984	0.391	9.05		1.000	
i1	34.375	1.562	9.07		1.000	
i1	35.938	0.781	10.02		1.000	
i1	36.719	0.391	10.04		1.000	
i1	37.109	0.391	10.02		1.000	
i1	37.500	0.781	10.00		1.000	
i1	38.281	0.781	9.09		1.000	
i1	39.062	0.781	9.11		1.000	
i1	39.844	0.391	10.00		1.000	
i1	40.234	0.391	9.11		1.000	
i1	40.625	1.562	9.09		1.000	
i1	42.188	0.781	10.02		1.000	
i1	42.969	0.391	10.04		1.000	
i1	43.359	0.391	10.02		1.000	
i1	43.750	0.391	10.07		1.000	
i1	44.141	0.391	10.05		1.000	
i1	44.531	0.781	10.04		1.000	
i1	45.312	0.391	10.02		1.000	
i1	45.703	0.391	10.00		1.000	
i1	46.094	0.391	9.11		1.000	
i1	46.484	0.391	9.09		1.000	
i1	46.875	1.562	9.07		1.000	
i1	48.438	0.391	8.11		0.500	
i1	48.828	0.391	9.05		0.500	
i1	49.219	0.781	8.11		0.500	
i1	50.000	0.781	9.00		0.500	
i1	50.781	0.781	9.04		0.500	
i1	51.562	0.781	9.05		0.500	
i1	52.344	0.391	9.04		0.500	
i1	52.734	0.391	8.11		0.500	
i1	53.125	1.562	9.05		0.500	
i1	54.688	0.391	8.11		0.500	
i1	55.078	0.391	9.00		0.500	
i1	55.469	0.781	9.04		0.500	
i1	56.250	0.781	9.00		0.500	
i1	57.031	0.781	8.09		0.500	
i1	57.812	0.391	9.02		0.500	
i1	58.203	0.391	8.09		0.500	
i1	58.594	0.391	9.04		0.500	
i1	58.984	0.391	8.11		0.500	
i1	59.375	1.562	8.07		0.500	
i1	60.938	0.781	8.11		0.500	
i1	61.719	0.391	8.09		0.500	
i1	62.109	0.391	8.07		0.500	
i1	62.500	0.781	8.09		0.500	
i1	63.281	0.781	9.00		0.500	
i1	64.062	0.781	8.11		0.500	
i1	64.844	0.391	9.00		0.500	
i1	65.234	0.391	8.07		0.500	
i1	65.625	1.562	9.00		0.500	
i1	67.188	0.781	9.02		0.500	
i1	67.969	0.391	8.09		0.500	
i1	68.359	0.391	8.07		0.500	
i1	68.750	0.391	9.02		0.500	
i1	69.141	0.391	9.05		0.500	
i1	69.531	0.781	9.09		0.500	
i1	70.312	0.391	9.05		0.500	
i1	70.703	0.391	9.04		0.500	
i1	71.094	0.391	8.11		0.500	
i1	71.484	0.391	8.03		0.500	
i1	71.875	1.562	8.04		0.500	
i1	73.438	0.391	9.04		1.000	
i1	73.828	0.391	9.02		1.000	
i1	74.219	0.781	9.00		1.000	
i1	75.000	0.781	9.05		1.000	
i1	75.781	0.781	9.05		1.000	
i1	76.562	0.781	9.04		1.000	
i1	77.344	0.391	9.05		1.000	
i1	77.734	0.391	9.07		1.000	
i1	78.125	1.562	9.02		1.000	
i1	79.688	0.391	9.04		1.000	
i1	80.078	0.391	9.02		1.000	
i1	80.469	0.781	9.00		1.000	
i1	81.250	0.781	9.05		1.000	
i1	82.031	0.781	9.05		1.000	
i1	82.812	0.391	9.04		1.000	
i1	83.203	0.391	9.02		1.000	
i1	83.594	0.391	9.00		1.000	
i1	83.984	0.391	8.11		1.000	
i1	84.375	1.562	9.00		1.000	
i1	85.938	0.781	9.07		1.000	
i1	86.719	0.391	9.09		1.000	
i1	87.109	0.391	9.07		1.000	
i1	87.500	0.781	9.05		1.000	
i1	88.281	0.781	9.02		1.000	
i1	89.062	0.781	9.04		1.000	
i1	89.844	0.391	9.05		1.000	
i1	90.234	0.391	9.04		1.000	
i1	90.625	1.562	9.02		1.000	
i1	92.188	0.781	9.07		1.000	
i1	92.969	0.391	9.09		1.000	
i1	93.359	0.391	9.07		1.000	
i1	93.750	0.391	10.00		1.000	
i1	94.141	0.391	9.11		1.000	
i1	94.531	0.781	9.09		1.000	
i1	95.312	0.391	9.07		1.000	
i1	95.703	0.391	9.05		1.000	
i1	96.094	0.391	9.04		1.000	
i1	96.484	0.391	9.02		1.000	
i1	96.875	1.562	9.00		1.000	
i1	98.438	0.195	9.00		1.000	
i1	98.633	0.195	8.11		1.000	
i1	98.828	0.391	8.09		1.000	
i1	99.219	0.391	9.02		1.000	
i1	99.609	0.391	9.02		1.000	
i1	100.000	0.391	9.00		1.000	
i1	100.391	0.195	9.02		1.000	
i1	100.586	0.195	9.04		1.000	
i1	100.781	0.781	8.11		1.000	
i1	101.562	0.195	9.00		1.000	
i1	101.758	0.195	8.11		1.000	
i1	101.953	0.391	8.09		1.000	
i1	102.344	0.391	9.02		1.000	
i1	102.734	0.391	9.02		1.000	
i1	103.125	0.195	9.00		1.000	
i1	103.320	0.195	8.11		1.000	
i1	103.516	0.195	8.09		1.000	
i1	103.711	0.195	8.07		1.000	
i1	103.906	0.781	8.09		1.000	
i1	104.688	0.391	9.04		1.000	
i1	105.078	0.195	9.05		1.000	
i1	105.273	0.195	9.04		1.000	
i1	105.469	0.391	9.02		1.000	
i1	105.859	0.391	8.11		1.000	
i1	106.250	0.391	9.00		1.000	
i1	106.641	0.195	9.02		1.000	
i1	106.836	0.195	9.00		1.000	
i1	107.031	0.781	8.11		1.000	
i1	107.812	0.391	9.04		1.000	
i1	108.203	0.195	9.05		1.000	
i1	108.398	0.195	9.04		1.000	
i1	108.594	0.195	9.09		1.000	
i1	108.789	0.195	9.07		1.000	
i1	108.984	0.391	9.05		1.000	
i1	109.375	0.195	9.04		1.000	
i1	109.570	0.195	9.02		1.000	
i1	109.766	0.195	9.00		1.000	
i1	109.961	0.195	8.11		1.000	
i1	110.156	0.781	8.09		1.000	
i1	110.938	0.781	8.09		1.000	
i1	111.719	0.195	8.11		1.000	
i1	111.914	0.195	9.00		1.000	
i1	112.109	0.195	9.02		1.000	
i1	112.305	0.195	9.04		1.000	
i1	112.500	0.391	9.05		1.000	
i1	112.891	0.195	9.07		1.000	
i1	113.086	0.195	9.09		1.000	
i1	113.281	0.195	9.04		1.000	
i1	113.477	0.195	9.05		1.000	
i1	113.672	0.391	9.04		1.000	
i1	114.062	0.781	8.11		1.000	
i1	114.844	0.195	9.00		1.000	
i1	115.039	0.195	9.02		1.000	
i1	115.234	0.391	9.00		1.000	
i1	115.625	0.391	8.11		1.000	
i1	116.016	0.391	9.02		1.000	
i1	116.406	0.195	9.04		1.000	
i1	116.602	0.195	9.05		1.000	
i1	116.797	0.391	9.04		1.000	
i1	117.188	0.781	8.09		1.000	
i1	117.969	0.195	8.07		1.000	
i1	118.164	0.195	8.09		1.000	
i1	118.359	0.195	8.11		1.000	
i1	118.555	0.195	9.00		1.000	
i1	118.750	0.391	9.02		1.000	
i1	119.141	0.391	9.02		1.000	
i1	119.531	0.391	8.09		1.000	
i1	119.922	0.195	8.11		1.000	
i1	120.117	0.195	9.00		1.000	
i1	120.312	0.781	8.11		1.000	
i1	121.094	0.195	9.04		1.000	
i1	121.289	0.195	9.02		1.000	
i1	121.484	0.391	9.00		1.000	
i1	121.875	0.391	9.02		1.000	
i1	122.266	0.391	9.02		1.000	
i1	122.656	0.391	8.09		1.000	
i1	123.047	0.195	8.11		1.000	
i1	123.242	0.195	9.00		1.000	
i1	123.438	0.781	8.09		1.000	
i1	124.219	0.195	8.11		1.000	
i1	124.414	0.195	9.00		1.000	
i1	124.609	0.195	9.02		1.000	
i1	124.805	0.195	9.04		1.000	
i1	125.000	0.391	9.05		1.000	
i1	125.391	0.195	9.07		1.000	
i1	125.586	0.195	9.09		1.000	
i1	125.781	0.195	9.04		1.000	
i1	125.977	0.195	9.05		1.000	
i1	126.172	0.391	9.04		1.000	
i1	126.562	0.781	8.11		1.000	
i1	127.344	0.195	9.00		1.000	
i1	127.539	0.195	9.02		1.000	
i1	127.734	0.391	9.00		1.000	
i1	128.125	0.391	8.11		1.000	
i1	128.516	0.391	9.02		1.000	
i1	128.906	0.195	9.04		1.000	
i1	129.102	0.195	9.05		1.000	
i1	129.297	0.391	9.04		1.000	
i1	129.688	0.781	8.09		1.000	
i1	130.469	0.195	8.07		1.000	
i1	130.664	0.195	8.09		1.000	
i1	130.859	0.195	8.11		1.000	
i1	131.055	0.195	9.00		1.000	
i1	131.250	0.391	9.02		1.000	
i1	131.641	0.391	9.02		1.000	
i1	132.031	0.391	8.09		1.000	
i1	132.422	0.195	8.11		1.000	
i1	132.617	0.195	9.00		1.000	
i1	132.812	0.781	8.11		1.000	
i1	133.594	0.195	9.04		1.000	
i1	133.789	0.195	9.02		1.000	
i1	133.984	0.391	9.00		1.000	
i1	134.375	0.391	9.02		1.000	
i1	134.766	0.391	9.02		1.000	
i1	135.156	0.391	8.09		1.000	
i1	135.547	0.195	8.11		1.000	
i1	135.742	0.195	9.00		1.000	

; ========================================
; END VOICE 1
; ========================================

; ========================================
; VOICE: 2, Instr.: 2
; ========================================

i2	46.875	0.391	8.04		1.000	
i2	47.266	0.391	8.02		1.000	
i2	47.656	0.781	8.00		1.000	
i2	48.438	0.781	8.05		1.000	
i2	49.219	0.781	8.05		1.000	
i2	50.000	0.781	8.04		1.000	
i2	50.781	0.391	8.05		1.000	
i2	51.172	0.391	8.07		1.000	
i2	51.562	1.562	8.02		1.000	
i2	53.125	0.391	8.04		1.000	
i2	53.516	0.391	8.02		1.000	
i2	53.906	0.781	8.00		1.000	
i2	54.688	0.781	8.05		1.000	
i2	55.469	0.781	8.05		1.000	
i2	56.250	0.391	8.04		1.000	
i2	56.641	0.391	8.02		1.000	
i2	57.031	0.391	8.00		1.000	
i2	57.422	0.391	7.11		1.000	
i2	57.812	1.562	8.00		1.000	
i2	59.375	0.781	8.07		1.000	
i2	60.156	0.391	8.09		1.000	
i2	60.547	0.391	8.07		1.000	
i2	60.938	0.781	8.05		1.000	
i2	61.719	0.781	8.02		1.000	
i2	62.500	0.781	8.04		1.000	
i2	63.281	0.391	8.05		1.000	
i2	63.672	0.391	8.04		1.000	
i2	64.062	1.562	8.02		1.000	
i2	65.625	0.781	8.07		1.000	
i2	66.406	0.391	8.09		1.000	
i2	66.797	0.391	8.07		1.000	
i2	67.188	0.391	9.00		1.000	
i2	67.578	0.391	8.11		1.000	
i2	67.969	0.781	8.09		1.000	
i2	68.750	0.391	8.07		1.000	
i2	69.141	0.391	8.05		1.000	
i2	69.531	0.391	8.04		1.000	
i2	69.922	0.391	8.02		1.000	
i2	70.312	1.562	8.00		1.000	
i2	71.875	0.391	7.04		0.500	
i2	72.266	0.391	7.11		0.500	
i2	72.656	0.781	7.04		0.500	
i2	73.438	0.781	7.05		0.500	
i2	74.219	0.781	7.09		0.500	
i2	75.000	0.781	7.11		0.500	
i2	75.781	0.391	7.09		0.500	
i2	76.172	0.391	7.04		0.500	
i2	76.562	1.562	7.11		0.500	
i2	78.125	0.391	7.04		0.500	
i2	78.516	0.391	7.05		0.500	
i2	78.906	0.781	7.09		0.500	
i2	79.688	0.781	7.05		0.500	
i2	80.469	0.781	7.02		0.500	
i2	81.250	0.391	7.07		0.500	
i2	81.641	0.391	7.02		0.500	
i2	82.031	0.391	7.09		0.500	
i2	82.422	0.391	7.04		0.500	
i2	82.812	1.562	7.00		0.500	
i2	84.375	0.781	7.04		0.500	
i2	85.156	0.391	7.02		0.500	
i2	85.547	0.391	7.00		0.500	
i2	85.938	0.781	7.02		0.500	
i2	86.719	0.781	7.05		0.500	
i2	87.500	0.781	7.04		0.500	
i2	88.281	0.391	7.05		0.500	
i2	88.672	0.391	7.00		0.500	
i2	89.062	1.562	7.05		0.500	
i2	90.625	0.781	7.07		0.500	
i2	91.406	0.391	7.02		0.500	
i2	91.797	0.391	7.00		0.500	
i2	92.188	0.391	7.07		0.500	
i2	92.578	0.391	7.11		0.500	
i2	92.969	0.781	8.02		0.500	
i2	93.750	0.391	7.11		0.500	
i2	94.141	0.391	7.09		0.500	
i2	94.531	0.391	7.04		0.500	
i2	94.922	0.391	7.03		0.500	
i2	95.312	1.562	7.04		0.500	
i2	96.875	0.391	8.04		1.000	
i2	97.266	0.391	8.02		1.000	
i2	97.656	0.781	8.00		1.000	
i2	98.438	0.781	8.05		1.000	
i2	99.219	0.781	8.05		1.000	
i2	100.000	0.781	8.04		1.000	
i2	100.781	0.391	8.05		1.000	
i2	101.172	0.391	8.07		1.000	
i2	101.562	1.562	8.02		1.000	
i2	103.125	0.391	8.04		1.000	
i2	103.516	0.391	8.02		1.000	
i2	103.906	0.781	8.00		1.000	
i2	104.688	0.781	8.05		1.000	
i2	105.469	0.781	8.05		1.000	
i2	106.250	0.391	8.04		1.000	
i2	106.641	0.391	8.02		1.000	
i2	107.031	0.391	8.00		1.000	
i2	107.422	0.391	7.11		1.000	
i2	107.812	1.562	8.00		1.000	
i2	109.375	0.781	8.07		1.000	
i2	110.156	0.391	8.09		1.000	
i2	110.547	0.391	8.07		1.000	
i2	110.938	0.781	8.05		1.000	
i2	111.719	0.781	8.02		1.000	
i2	112.500	0.781	8.04		1.000	
i2	113.281	0.391	8.05		1.000	
i2	113.672	0.391	8.04		1.000	
i2	114.062	1.562	8.02		1.000	
i2	115.625	0.781	8.07		1.000	
i2	116.406	0.391	8.09		1.000	
i2	116.797	0.391	8.07		1.000	
i2	117.188	0.391	9.00		1.000	
i2	117.578	0.391	8.11		1.000	
i2	117.969	0.781	8.09		1.000	
i2	118.750	0.391	8.07		1.000	
i2	119.141	0.391	8.05		1.000	
i2	119.531	0.391	8.04		1.000	
i2	119.922	0.391	8.02		1.000	
i2	120.312	1.562	8.00		1.000	
i2	121.875	25.000	9.04		1.000	

; ========================================
; END VOICE 2
; ========================================

</CsScore>
</CsoundSynthesizer>
