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

i1	0.000	2.000	8.00		1.000	
i1	0.000	2.000	8.04		1.000	
i1	0.000	2.000	8.07		1.000	

; ========================================
; END VOICE 0
; ========================================

</CsScore>
</CsoundSynthesizer>
