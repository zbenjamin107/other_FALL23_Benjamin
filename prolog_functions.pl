%zachary benjamin
%CS-3210-01
%

%1) family relations
%creating facts
parent(ron,zach).
parent(ron,chase).
parent(herb,ron).
parent(herb,stu).
parent(stu,owen).
%creating rules
grandparent(GP, GC) :- parent(GP, P), parent(P, GC).	%if GP is the parent of the GC parent then true
sibling(S1,S2) :- parent(P,S1), parent(P,S2), S1\=S2.			%if both ppl have the same parent then true	
cousin(C1,C2) :- parent(P1, C1), parent(P2,C2), sibling(P2,P1).%

% 2) russina dolls
directlyIn(katerine,olga).% the facts
directlyIn(olga,natasha).
directlyIn(natasha,irina).
% recursive call that will check every layer until it find it or comes to the center
in(OUT, IN) :- directlyIn(OUT ,IN); directlyIn(OUT, N), in(N,IN).

% 3) traveling between towns
directTrain(baltimore,washington).%the facts
directTrain(wilmington,baltimore).
directTrain(philadelphia,wilmington).
directTrain(newark,philadelphia).
directTrain(newyorkcity,newark).
directTrain(newhaven,newyorkcity).
directTrain(providence,newhaven).
directTrain(boston,providence).
%this recursive fucntion is similar to the one in the previos function. I only changed the names realy
travelFromTo(FROM, TO) :- directTrain(FROM, TO); directTrain(FROM, BETWEEN), travelFromTo(BETWEEN, TO).

% 4) traveling between towns with vast variety in transportation
byCar(auckland,hamilton).% the facts you didn't know 
byCar(hamilton,raglan).
byCar(valmont,saarbruecken).
byCar(valmont,metz).

byTrain(metz,frankfurt).
byTrain(saarbruecken,frankfurt).
byTrain(metz,paris).
byTrain(saarbruecken,paris).

byPlane(frankfurt,bangkok).
byPlane(frankfurt,singapore).
byPlane(paris,losAngeles).
byPlane(bangkok,auckland).
byPlane(singapore,auckland).
byPlane(losAngeles,auckland).

%helper functions i made. these recursive calls will see if the town can be traveled to in a straight line in that own means of transportation
travelByCar(FROM,TO) :- byCar(FROM, TO); byCar(FROM, BETWEEN), travelByCar(BETWEEN, TO).
travelByPlane(FROM,TO) :- byPlane(FROM, TO); byPlane(FROM, BETWEEN), travelByPlane(BETWEEN, TO).
travelByTrain(FROM,TO) :- byTrain(FROM, TO); byTrain(FROM, BETWEEN), travelByTrain(BETWEEN, TO).

%this function is very similar to that before it but i had to add a little and create helper functions for neatness
travel(FROM, TO) :- travelByCar(FROM, TO); travelByTrain(FROM, TO); travelByPlane(FROM, TO); 
    				travelByCar(FROM, MID), travel(MID, TO); travelByTrain(FROM, MID), travel(MID, TO); travelByPlane(FROM, MID), travel(MID, TO).

% 5) latin and english
tran(unus,one).
tran(duo,two).
tran(tres,three).
tran(quattuor,four).
tran(quinque,five).
tran(sex,six).
tran(septem,seven).
tran(octo,eight).
tran(novem,nine).

listtran([],[]).

listtran([LH | LT], [EH | ET]) :- tran(LH,EH), listtran(LT , ET).




% 6) lake crossing
% this was done in class(thanks dude!). 
change(e,w).
change(w,e).
move([X,X,Goat,Veggie],wolf,[Y,Y,Goat,Veggie]) :- change(X,Y).
move([X,Wolf,X,Veggie],goat,[Y,Wolf,Y,Veggie]) :- change(X,Y).
move([X,Wolf,Goat,X],veggie,[Y,Wolf,Goat,Y]) :- change(X,Y).
move([X,Wolf,Goat,Veggie],nothing,[Y,Wolf,Goat,Veggie]) :- change(X,Y).

oneEq(X,X,_).
oneEq(X,_,X).

safe([Man,Wolf,Goat,Veggie]) :- oneEq(Man,Wolf,Goat), oneEq(Man,Goat,Veggie). 

solution([e,e,e,e],[]).
solution(Config, [FirstMove|OtherMoves]) :- 
    move(Config,FirstMove,NextConfig), 
    safe(NextConfig), 
    solution(NextConfig, OtherMoves).
