%TF.GenerationSoftware,KiCad,Pcbnew,8.0.5*%
%TF.CreationDate,2024-10-21T15:28:47-03:00*%
%TF.ProjectId,majoras - rotate,6d616a6f-7261-4732-902d-20726f746174,rev?*%
%TF.SameCoordinates,Original*%
%TF.FileFunction,Soldermask,Top*%
%TF.FilePolarity,Negative*%
%FSLAX46Y46*%
G04 Gerber Fmt 4.6, Leading zero omitted, Abs format (unit mm)*
G04 Created by KiCad (PCBNEW 8.0.5) date 2024-10-21 15:28:47*
%MOMM*%
%LPD*%
G01*
G04 APERTURE LIST*
G04 Aperture macros list*
%AMRoundRect*
0 Rectangle with rounded corners*
0 $1 Rounding radius*
0 $2 $3 $4 $5 $6 $7 $8 $9 X,Y pos of 4 corners*
0 Add a 4 corners polygon primitive as box body*
4,1,4,$2,$3,$4,$5,$6,$7,$8,$9,$2,$3,0*
0 Add four circle primitives for the rounded corners*
1,1,$1+$1,$2,$3*
1,1,$1+$1,$4,$5*
1,1,$1+$1,$6,$7*
1,1,$1+$1,$8,$9*
0 Add four rect primitives between the rounded corners*
20,1,$1+$1,$2,$3,$4,$5,0*
20,1,$1+$1,$4,$5,$6,$7,0*
20,1,$1+$1,$6,$7,$8,$9,0*
20,1,$1+$1,$8,$9,$2,$3,0*%
%AMHorizOval*
0 Thick line with rounded ends*
0 $1 width*
0 $2 $3 position (X,Y) of the first rounded end (center of the circle)*
0 $4 $5 position (X,Y) of the second rounded end (center of the circle)*
0 Add line between two ends*
20,1,$1,$2,$3,$4,$5,0*
0 Add two circle primitives to create the rounded ends*
1,1,$1,$2,$3*
1,1,$1,$4,$5*%
%AMRotRect*
0 Rectangle, with rotation*
0 The origin of the aperture is its center*
0 $1 length*
0 $2 width*
0 $3 Rotation angle, in degrees counterclockwise*
0 Add horizontal line*
21,1,$1,$2,0,0,$3*%
G04 Aperture macros list end*
%ADD10RoundRect,0.250000X0.750000X-0.250000X0.750000X0.250000X-0.750000X0.250000X-0.750000X-0.250000X0*%
%ADD11RoundRect,0.250000X-0.250000X-0.750000X0.250000X-0.750000X0.250000X0.750000X-0.250000X0.750000X0*%
%ADD12RotRect,1.070000X1.800000X45.000000*%
%ADD13HorizOval,1.070000X-0.258094X0.258094X0.258094X-0.258094X0*%
G04 APERTURE END LIST*
D10*
%TO.C,REF\u002A\u002A*%
X165750000Y-89250000D03*
%TD*%
D11*
%TO.C,REF\u002A\u002A*%
X160750000Y-86000000D03*
%TD*%
D10*
%TO.C,REF\u002A\u002A*%
X165750000Y-90750000D03*
%TD*%
D12*
%TO.C,D1*%
X159703949Y-91796051D03*
D13*
X160601975Y-90898025D03*
X161500000Y-90000000D03*
X162398026Y-89101974D03*
%TD*%
D10*
%TO.C,REF\u002A\u002A*%
X165750000Y-92250000D03*
%TD*%
D11*
%TO.C,REF\u002A\u002A*%
X162250000Y-86000000D03*
%TD*%
%TO.C,REF\u002A\u002A*%
X159250000Y-86000000D03*
%TD*%
M02*
