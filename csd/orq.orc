sr = 44100
kr = 4410
ksmps = 10
nchnls = 1

;=========================================================================
;Flute Instrument based on Perry Cook's Slide Flute
;=========================================================================
instr 1
	
  aflute1 init 0
  ifqc    = cpspch(p4)
  ipress  = p6
  ibreath = p7
  ifeedbk1= p8
  ifeedbk2= p9	

; Flow setup
  kenv1   linseg 0, .06, 1.1*ipress, .2, ipress, p3-.16, ipress, .02, 0 
  kenv2   linseg 0, .01, 1, p3-.02, 1, .01, 0
  kenvibr linseg 0, .5, 0, .5, 1, p3-1, 1  ; Vibrato envelope

; The values must be approximately -1 to 1 or the cubic will blow up.
  aflow1 rand kenv1
  kvibr oscil .1*kenvibr, 5, 3

; ibreath can be used to adjust the noise level.
  asum1 = ibreath*aflow1 + kenv1 + kvibr
  asum2 = asum1 + aflute1*ifeedbk1

  afqc  = 1/ifqc - asum1/20000 -9/sr + ifqc/12000000

; Embouchure delay should be 1/2 the bore delay
;  ax delay asum2, (1/ifqc-10/sr)/2
  atemp1 delayr 1/ifqc/2
  ax     deltapi afqc/2 ; - asum1/ifqc/10 + 1/1000
         delayw asum2

  apoly = ax - ax*ax*ax
  asum3 = apoly + aflute1*ifeedbk2

  avalue tone asum3, 2000

; Bore, the bore length determines pitch.  Shorter is higher pitch.
   atemp2   delayr 1/ifqc
   aflute1 deltapi afqc
           delayw avalue

  out avalue*p5*kenv2

endin


;=========================================================================

;=========================================================================
; Clarinet Instrument based on Perry Cook's Clarinet
;=========================================================================
instr 2

  areedbell init 0
  ifqc  = cpspch(p4)
  ifco  = p7
  ibore = 1/ifqc-15/sr

; I got the envelope from Perry Cooke's Clarinet.
  kenv1   linseg 0, .005, .55 + .3*p6, p3 - .015, .55 + .3*p6, .01, 0
  kenvibr linseg 0, .1, 0, .9, 1, p3-1, 1  ; Vibrato envelope

; Supposedly has something to do with reed stiffness?
  kemboff = p8

; Breath Pressure
  avibr oscil .1*kenvibr, 5, 3
  apressm = kenv1 + avibr

; Reflection filter from the bell is lowpass.
  arefilt tone areedbell, ifco

; The delay from bell to reed.
  abellreed delay arefilt, ibore

; Back pressure and reed table look up.
  asum2 = - apressm -.95*arefilt - kemboff
  areedtab tablei asum2/4+.34, p9, 1, .5
  amult1 = asum2 * areedtab

; Forward Pressure
  asum1 = apressm + amult1

  areedbell delay asum1, ibore

  aofilt atone areedbell, ifco

  out aofilt*p5

endin

instr 8  ; Drum Stick 1

  gadrum init 0

; Frequency
  ifqc  = cpspch(p5)

; Initialize the delay line with noise
  ashape linseg 0, 1/ifqc/8, -1/2, 1/ifqc/4, 1/2, 1/ifqc/8, 0, p3-1/ifqc, 0
  gadrum tone ashape, p6

endin
;=========================================================================



;=========================================================================
; Perry Cook's Organ
;=========================================================================
instr 3
  ifrq = cpspch(p4)
  
  kenv linseg 0, .01, p5, p3-.02, p5, .01, 0

  a1     oscil 8,   1      * ifrq,  4
  a2     oscil 8,   2      * ifrq,  4
  a3     oscil 8,   2.9966 * ifrq,  4
  a4     oscil 8,   4      * ifrq,  4
  a5     oscil 3,   5.9932 * ifrq,  4
  a6     oscil 2,   8      * ifrq,  4
  a7     oscil 1,  10.0794 * ifrq,  4
  a8     oscil 1,  11.9864 * ifrq,  4
  a9     oscil 4,  16      * ifrq,  4

  aorgan = kenv* (a1+a2+a3+a4+a5+a6+a7+a8+a9)

  outs aorgan, aorgan
endin
;=========================================================================


;=========================================================================
; Organ 2
;=========================================================================
instr 4
  ifrq = cpspch(p4)
  
  kenv linseg 0, .01, p5, p3-.02, p5, .01, 0

  a1     oscil 8,   1      * ifrq,  4
  a2     oscil 8,   2      * ifrq,  4
  a3     oscil 8,   2.9966 * ifrq,  4
  a4     oscil 8,   4      * ifrq,  4

  aorgan = kenv* (a1+a2+a3+a4)

  outs aorgan, aorgan
endin
;=========================================================================


;=========================================================================
; Organ 3
;=========================================================================
instr 5
  ifrq = cpspch(p4)
  
  kenv linseg 0, .01, p5, p3-.02, p5, .01, 0
  kenvibr linseg 0, .01, p5, p3-.02, p5, .01, 1  ; Vibrato envelope
  avibr oscil 8*kenvibr, 5, 3


  a1     oscil 8,   1      * ifrq,  4
  a4     oscil 8,   4      * ifrq,  4
  a5     oscil 3,   5.9932 * ifrq,  4
  a6     oscil 2,   8      * ifrq,  4

;  aorgan = ((kenv + avibr)/2) * (a1+a4+a5+a6) ;Organ oscilador
  aorgan = kenv * (a1+a4+a5+a6)

  outs aorgan, aorgan
endin
;=========================================================================

