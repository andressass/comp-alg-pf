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
; VOICE: 0, Instr.: 0
; ========================================

i0	0.000	0.312	8.04		0.500	
i0	0.312	0.312	8.02		0.500	
i0	0.625	0.625	8.04		0.500	
i0	1.250	0.625	8.09		0.500	
i0	1.875	0.625	8.09		0.500	
i0	2.500	0.625	9.00		0.500	
i0	3.125	0.312	9.02		0.500	
i0	3.438	0.312	8.11		0.500	
i0	3.750	1.250	8.09		0.500	
i0	5.000	0.312	8.07		0.500	
i0	5.312	0.312	8.02		0.500	
i0	5.625	0.625	8.04		0.500	
i0	6.250	0.625	8.02		0.500	
i0	6.875	0.625	8.02		0.500	
i0	7.500	0.312	8.00		0.500	
i0	7.812	0.312	8.02		0.500	
i0	8.125	0.312	8.04		0.500	
i0	8.438	0.312	8.07		0.500	
i0	8.750	1.250	8.00		0.500	
i0	10.000	0.625	8.04		0.500	
i0	10.625	0.312	8.00		0.500	
i0	10.938	0.312	8.07		0.500	
i0	11.250	0.625	8.02		0.500	
i0	11.875	0.625	8.09		0.500	
i0	12.500	0.625	9.00		0.500	
i0	13.125	0.312	8.05		0.500	
i0	13.438	0.312	8.07		0.500	
i0	13.750	1.250	8.05		0.500	
i0	15.000	0.625	9.00		0.500	
i0	15.625	0.312	8.05		0.500	
i0	15.938	0.312	8.00		0.500	
i0	16.250	0.312	8.07		0.500	
i0	16.562	0.312	8.04		0.500	
i0	16.875	0.625	8.05		0.500	
i0	17.500	0.312	8.00		0.500	
i0	17.812	0.312	8.05		0.500	
i0	18.125	0.312	8.07		0.500	
i0	18.438	0.312	8.03		0.500	
i0	18.750	1.250	8.04		0.500	

; ========================================
; END VOICE 0
; ========================================

</CsScore>
</CsoundSynthesizer>